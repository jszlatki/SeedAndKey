# SeedAndKey
Creation of Vector SeedAndKey DLL using VS Code and compiling with g++ in MSYS2.

## Licenses
The code is based on the sample Vector Seed and Key dll files (GenerateKeyExImpl.cpp and KeyGenAlgoInterfaceEx.h) They were created at 2003-07-17 by Vector Informatik GmbH.

## Generic information
The aim of the my project to figure out how to create a DLL using free tools: IDE, compilers. Why it was needed:
- I was only interesting, if it is possible,
- I wanted to learn more about VSCode,
- I wanted to learn github //pls don't ban me

## Changes
- Both the source files should have been slightly changed to get the project compiled: warning and error free. 
- The originaly included Visual Studio project files are not included because the VSCode cannot directly use them.

## Added files
- tasks.json: it contains two tasks and the required precompiler switches are copied and modified from the original project files. I redifined the project to create 64bit dlls. Additionally I added libgcc and libstdc++ staticly not to have to install the [MSYS2](https://www.msys2.org/) on the target PC.
  - Build SeedAndKey DLL Debug: build task for the debugging
  - Build SeedAndKey DLL Release: build task for the release
