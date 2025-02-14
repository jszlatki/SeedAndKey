//****************************************************************************************
//   File name: KeyGenAlgo.h
// Description: Abstract base class defines the interface for the key generation algorithm
//        Date: 2003-07-17
//   Copyright: Vector Informatik GmbH - 2003
// changes:
// 2003-07-17   Vector  First implementation
// 2025-02-05   JSz     use the same declaration for the function VKeyGenResultEx as in the cpp file  
//****************************************************************************************

#ifndef KEY_GEN_ALGO_INTERFACE_H
#define KEY_GEN_ALGO_INTERFACE_H

#if _MSC_VER > 1000
#pragma once
#endif


#ifdef KEYGENALGO_EXPORTS
#define KEYGENALGO_API extern "C" __declspec(dllexport)
#else
#define KEYGENALGO_API __declspec(dllimport)
#endif


enum VKeyGenResultEx
{
  KGRE_Ok = 0,
  KGRE_BufferToSmall = 1,
  KGRE_SecurityLevelInvalid = 2,
  KGRE_VariantInvalid = 3,
  KGRE_UnspecifiedError = 4
};

// The client has to provide a keyArray buffer and has to transfer this buffer - 
// including its size - to the GenerateKey method. The method checks, if the size is
// sufficient. The client can discover the required size by examinig the service used
// transfer the key to the ECU.
// Returns false if the key could not be generated:
//  -> keyArraySize to small
//  -> generation for specified security level not possible
//  -> variant unknown
KEYGENALGO_API VKeyGenResultEx GenerateKeyEx(
  const unsigned char*  iSeedArray,     /* Array for the seed [in] */
  unsigned int          iSeedArraySize, /* Length of the array for the seed [in] */
  const unsigned int    iSecurityLevel, /* Security level [in] */
  const char*           iVariant,       /* Name of the active variant [in] */
  unsigned char*        ioKeyArray,     /* Array for the key [in, out] */
  unsigned int          iKeyArraySize,  /* Maximum length of the array for the key [in] */
  unsigned int&         oSize           /* Length of the key [out] */
  );

#endif // KEY_GEN_ALGO_INTERFACE_H