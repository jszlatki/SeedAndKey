//****************************************************************************************
// File name: GenerateKeyExImpl.cpp
// Description: Implementation of the key generation algorithm with a security function from the Crypto++ library
//
//   Copyright: Vector Informatik GmbH - 2003 - many thanks for the great example ;)
// changes:
// 2003-07-17   Vector First implementation
// 2025-02-05   JSz    remove the nKeyGeneration variable
// 2025-02-09   JSz    add ed25519 signature generation for the key
//****************************************************************************************

#include <windows.h>
#include <string>
#include <vector>

#include "KeyGenAlgoInterfaceEx.h"
#include "cryptlib.h"
#include "xed25519.h"
#include "osrng.h"

#ifndef KEYGENALGO_API
  #ifdef KEYGENALGO_EXPORTS
    #define KEYGENALGO_API __declspec(dllexport)
  #else
    #define KEYGENALGO_API __declspec(dllimport)
  #endif
#endif

using namespace CryptoPP;


const byte privateKey[] = {/*	L1											1 3	101	  112		  34			32 byte size */
		/* ASN.1 Header*/	0x30, 0x2E, 0x02, 0x01, 0x00, 0x30, 0x05, 0x06, 0x03, 0x2B, 0x65, 0x70, 0x04, 0x22, 0x04, 0x20, /*End of Header*/
		/*key*/		    	'S', 'e', 'c', 'u', 'r', 'i', 't', 'y', 0xFF, 'L', 'e', 'v', 'e', 'l', '1', 0xFF,
							'P', 'r', 'i', 'v', 'a', 't', 'e', 'K', 'e', 'y', 0x42, 'J', 'o', 'z', 's', 'i' };

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

KEYGENALGO_API VKeyGenResultEx GenerateKeyEx(
      const unsigned char*  iSeedArray,     /* Array for the seed [in] */
      unsigned int          iSeedArraySize, /* Length of the array for the seed [in] */
      const unsigned int    iSecurityLevel, /* Security level [in] */
      const char*           iVariant,       /* Name of the active variant [in] */
      unsigned char*        ioKeyArray,     /* Array for the key [in, out] */
      unsigned int          iKeyArraySize,  /* Maximum length of the array for the key [in] */
      unsigned int&         oSize           /* Length of the key [out] */
      )
{
	std::string signature = "";
	ed25519::Signer signer;
	AutoSeededRandomPool prng;
	std::string seed(reinterpret_cast<const char*>(iSeedArray));

	// Generate the signature based on the seed with the private key
	StringSource ss_pri(privateKey, sizeof(privateKey), true);
	signer.AccessPrivateKey().Load(ss_pri);
	StringSource(seed, true, new SignerFilter(prng, signer, new StringSink(signature)));
	
	// Set the size of the key based on the signature's size
	oSize = signature.size();	
    if (signature.size() > iKeyArraySize)
      return KGRE_BufferToSmall;

	// Copy the signature to the key
	std::copy(signature.begin(), signature.end(), ioKeyArray);
	
	// Return successfully generated key
  	return KGRE_Ok;
}


