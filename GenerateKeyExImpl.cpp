// KeyGeneration.cpp : Defines the entry point for the DLL application.

//****************************************************************************************
//   File name: GenerateKeyExImpl.cpp
// Description: Implementation of the key generation algorithm
//        Date: 2003-07-17
//   Copyright: Vector Informatik GmbH - 2003
// changes:
// 2003-07-17   Vector  First implementation
// 2025-02-25   JSz    comment out the nKeyGeneration variable
//****************************************************************************************

#include <windows.h>
#include "KeyGenAlgoInterfaceEx.h"


#ifndef KEYGENALGO_API
  #ifdef KEYGENALGO_EXPORTS
    #define KEYGENALGO_API __declspec(dllexport)
  #else
    #define KEYGENALGO_API __declspec(dllimport)
  #endif
#endif

// This is an example of an exported function.

// This is the constructor of a class that has been exported.
// see KeyGeneration.h for the class definition
// KEYGENALGO_API int nKeyGeneration=0;


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
    if (iSeedArraySize>iKeyArraySize)
      return KGRE_BufferToSmall;
    for (unsigned int i=0;i<iSeedArraySize;i++)
      ioKeyArray[i]=~iSeedArray[i];
    oSize=iSeedArraySize;
    
  return KGRE_Ok;
}


