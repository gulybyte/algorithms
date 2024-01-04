# Calc

Currently, it only performs the four basic arithmetic operations. The inputs have a limit, with the maximum being 9999, and it only accepts natural numbers ($\mathbb{N}$), meaning only positive integers including zero. Soon, I will include factorial operations with $\mathbb{N}$, in addition to expanding the basic operations to integers ($\mathbb{Z}$), including both positive and negative integers, and later to rational numbers ($\mathbb{Q}$), which involve positive and negative decimal fractions. Subsequently, I will also introduce the following operations: square root, potentiation and module operations. All of this information is detailed in this issue: [Features for calc nasm](https://github.com/gulybyte/algorithms/issues/1).

To execute this code, it is necessary to run it on a Linux distribution and have NASM installed, as [explained here](/config/NASM.md). Once `nasm` is installed, with the command prompt open in this folder, run the following command, and everything will be taken care of:
```sh
make
```

### Resume

![cover calc nasm](/calc/nasm/static/cover.png)