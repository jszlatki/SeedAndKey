# SeedAndKey - with_Crypto++
Creation of Vector SeedAndKey DLL using VS Code and compiling with g++ in MSYS2.
The branch __with_Crypto++__ has the Crypto++ library from the [Crypto++ Github site](https://github.com/weidai11/cryptopp). And shows a practical example for a security function.

## Licenses
The code is based on the sample Vector Seed and Key dll files (GenerateKeyExImpl.cpp and KeyGenAlgoInterfaceEx.h) They were created at 2003-07-17 by Vector Informatik GmbH.
To get it work the Crypto++ library shall be downloaded an built. Please always ad the Copyright file of the Crypto++ library. It is prepared in the coresponding folders.

## Generic information
The aim of the project to figure out how to create a seed and key DLL using free tools: IDE, compiler, configuration management tool, which contains special security functions.
- Both the source files should have been slightly changed to get the project compiled: warning and error free. 
- The originaly included Visual Studio project files are not included because the VSCode cannot directly use them.
- The source has an example how to use a Crypto++ library, where an ed25519 signing happens with a semi-random ;) private key, which signature serves the a key.

## Settings
### Tasks.json
This contains two tasks and the required precompiler switches are copied and modified from the original project files of Vector. The project is set up to create 64bit dlls: 
  - Build SeedAndKey DLL Debug: build task for the debugging
  - Build SeedAndKey DLL Release: build task for the release
### c_cpp_properties.json
This file contains the settings for the C/C++ VSCode addon 

## Prerequisites
- [MSYS2](https://www.msys2.org/) shall be installed to build the library
  - Check the [C++/GCC on Window](https://code.visualstudio.com/docs/cpp/config-mingw)
- [Crypto++ library](https://github.com/weidai11/cryptopp) shall be downloaded compiled for 64bit architecture

## Crypto++ library
There is a subfolder as a library C++ project. There are defined several tasks in the tasks.json file to get warning-free compiled the Crypto++ library.

### Tasks
This json file defines the compiler settings and tasks to get compile the library:
 - __Debug x64 Build and Move__: calls the tasks in sequence: "Build Debug (x64)", "Move x64 Debug Object Files"
 - __Build Debug (x64)__: build object files for 64 bit architecture for debugging
 - __Move x64 Debug Object Files__: moves all the object files under /build/x64_debug/ folder

 - __Release x64 Build and Move__: calls the tasks in sequence: "Build Release (x64)", "Move x64 Release Object Files"
 - __Build Release (x64)__: build object files for 64 bit architecture for release
 - __Move x64 Relase Object Files__: moves all the object files under /build/x64_release/ folder

 - __Debug x86 Build and Move__: calls the tasks in sequence: "Build Debug (x86)", "Move x86 Debug Object Files"
 - __Build Debug (x86)__: build object files for 32 bit architecture for debugging
 - __Move x86 Debug Object Files__: moves all the object files under /build/x86_debug/ folder

 - __Release x86 Build and Move__: calls the tasks in sequence: "Build Release (x86)", "Move x86 Release Object Files"
 - __Build Release (x86)__: build object files for 32 bit architecture for release
 - __Move x86 Relase Object Files__: moves all the object files under /build/x86_release/ folder
 




