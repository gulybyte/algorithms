# NASM Assembly
Netwide Assembler (NASM) is an assembly language assembler.

> Assembly (ASM) or assembly language is a human-readable notation for the machine code that a specific computer architecture uses. This low-level programming language requires writing different code depending on the architecture/OS/processor. The assembler is responsible for compiling this language into object binary code, which can then be linked (using `ld` or even `g++`) like other binaries to become an executable. NASM is an assembly language designed for the x86 CPU architecture and is specifically used in Linux distributions.

All NASM code in this repository is written in such a way that it can be executed on any Linux distribution, provided that `nasm` is installed. Therefore, please ensure you have `nasm` installed on your distribution. As for compilation and linking, I have automated the process with a makefile. Each algorithm found here will have a corresponding makefile that handles all the necessary steps to run the code, requiring only the installation of NASM on your distribution.
