# SeedAndKey - simple
Creation of Vector SeedAndKey DLL using VS Code and compiling with g++ in MSYS2.
The branch __simple__ does not have any special includes.

## Licenses
The code is based on the sample Vector Seed and Key dll files (GenerateKeyExImpl.cpp and KeyGenAlgoInterfaceEx.h) They were created at 2003-07-17 by Vector Informatik GmbH.

## Generic information
The aim of the my project to figure out how to create this DLL using free tools: IDE, compiler, configuration management tool. There is a very good description on the Microsoft VSCode [C++/GCC on Window](https://code.visualstudio.com/docs/cpp/config-mingw) webpage how to set it up. 

## Changes
- Both the source files should have been slightly changed to get the project compiled: warning and error free. 
- The originaly included Visual Studio project files are not included because the VSCode cannot directly use them.

## tasks.json:
There are two tasks defined here. The required precompiler switches are also copied and modified from the original project files. The project is modified to create 64bit dlls. The are added libgcc and libstdc++ statically not to have to install the [MSYS2](https://www.msys2.org/) on the target PC, where the dll will be used.
  - __Build SeedAndKey DLL Debug__: build task for the debugging
  - __Build SeedAndKey DLL Release__: build task for the release
