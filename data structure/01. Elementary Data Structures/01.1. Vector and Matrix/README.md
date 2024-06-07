> [_](https://gulybyte.github.io/articles/estrutura-de-dados-java/list/array-list)

### Notations
- $\mathbb{N}_0=\mathbb{N} ∪ \{0\} \Leftrightarrow$ the set of natural numbers with 0;
- ***vector*** = `array` or `list` One-Dimensional;
- ***matrix*** = `array` or `list` Two-Dimensional;
- tuple is a finite sequence. The definition used is from [Introduction to the Theory of Computation - Michael Sipser](https://duckduckgo.com/?q=ISBN+978-1133187790&ia=web).

<details closed>
<summary><h6>Disclaimer</h6></summary>

> Disclaimer: As the author of this repository, I have personally written the mathematical definitions provided here. I am not a PhD or MSc in computer science, nor am I a formally trained mathematician. At the time of writing these definitions, I am in the first semester of a Bachelor's degree in computer science, **so these definitions may contain errors**. The primary goal of these definitions is to provide a mathematical intuition of what a ***vector*** and a ***matrix*** are in computing. These are the most elementary data structures from which all others are built. As such, all programming languages include ***vectors*** and ***matrices*** in a primitive form; they are essentially mappings of indices to memory elements. Given this foundational nature, a mathematical definition is most appropriate for formalizing the concepts of ***vector*** and ***matrix***.

</details>

# ***Vector***

<details closed>

<summary><h4><small><small>(my)</small></small> mathematical definition for <b><i>vector</i></b></h4></summary>

> Definition without considering memory.

A ***vector*** $V$ is a data structure consisting of a set $C$ of elements $\alpha$ with each element identified by an index $i$ from a set $S_t$. These elements $\alpha$ are of the same $T$. That is:

$$V = \{(i,\alpha)\text{ | }i\in S_t\text{, }\alpha\in C\}$$
where:

- $T \Leftrightarrow$ ADT ([abstract data type]((https://en.wikipedia.org/wiki/Abstract_data_type)))

- $C\subset T$

- $t=(0,1,\dots,n-1) \Leftrightarrow$ Tuple $t$ of $n$ terms from $\mathbb{N}_0$ ($n\in\mathbb{N}_0$)

    - $n =|C| \Leftrightarrow$ The number of $n$ terms is the number of elements in set $C$ (or the cardinality of $C$)

- $S_t = \{t\} = \{0,1,\dots,n-1\} \Leftrightarrow S_t$ is the set of indices of tuple $t$

#### Example with $C=\{5,8,6,7\}$:

- $C=\{5,8,6,7\} \Rightarrow S_t=\{0,1,2,3\}$

> therefore:

- $V=\{(0,5)\text{; }(1,8)\text{; }(2,6)\text{; }(3,7)\}$

</details>

### Simple Definition

A vector is a data structure consisting of a collection of elements (values or variables) one-dimensional, all of its elements are of the same data type  (therefore, same memory size), and each element is identified by at one array index.

### Examples and Types of Vectors in Different Programming Languages

#### C/C++

There are two types of vectors: immutable and mutable. The terminology can vary depending on the programming language. For instance, in C/C++, there isn't a specific terminology; we simply refer to them as mutable/variable arrays or immutable/constant arrays. By default, arrays in C/C++ are mutable, but we can make them immutable using the `const` keyword.

```c
#include <stdio.h>
#include <stdlib.h>

void main() {

    const int arrImutable[] = {42, 7, 33, 81};

    printf("\nValue of indice 0: %d", arrImutable[0]);

    /* Impossible operation */
    // arrImutable[0] = 32;

    int arrMutable[] = {42, 7, 33, 81};

    printf("\nValue of indice 0: %d", arrMutable[0]);

    arrMutable[0] = 35;

    printf("\nValue of indice 0: %d", arrMutable[0]);

}
```
> Out:<br>Value of indice 0: 42<br>Value of indice 0: 42<br>Value of indice 0: 35

In this example, `arrImmutable` is declared as a constant array, meaning its elements cannot be modified. `arrMutable` is a regular array that allows modifications.

#### Rust

In Rust, arrays are immutable by default. To make an array mutable, we use the `mut` keyword.
```rs
fn main() {

    println!("\n-- Immutable Vector --");

    let arrImutable: [i32; 7] = [1, 1, 2, 3, 5, 8, 13];

    println!("Value of index 0: {}", arrImutable[0]);

    /* Impossible operation, because it is immutable */
    // arrImutable[0] = 42;

    println!("\n-- Mutable Vector --");

    let mut arrMutable: [i32; 7] = [1, 1, 2, 3, 5, 8, 13];

    println!("Value of index 0: {}", arrMutable[0]);

    /* Possible operation, because it is mutable */
    arrMutable[0] = 42;

    println!("Value of index 0: {}\n", arrMutable[0]);

}
```
> Out:<br>-- Imutable Vector --<br>Value of indice 0: 1<br>-- Mutable Vector --<br>Value of indice 0: 1<br>Value of indice 0: 42

Here, `arrImutable` is immutable, and attempting to modify its elements results in an error. The `arrMutable` is mutable, allowing element modification.

#### Java

In Java, arrays are somewhat immutable. We can change elements through their indices, but we cannot change the size of the array. Using the `final` keyword makes the elements themselves immutable.

![array Java](https://github.com/gulybyte/gulybyte.github.io/blob/master/public/static/images/articles/estrutura-de-dados-java/array.png?raw=trueg)

```java
int[] numbersArray = {2, 3, 5, 7};
System.out.println("third element: " + numbersArray[3]);
System.out.println("length of array: " + numbersArray.length);

numbersArray[3] = 11;
System.out.println("new third element: " + numbersArray[3]);

try {
  numbersArray[4] = 13; // error (exceeded size of the array)
} catch(ArrayIndexOutOfBoundsException e) {
  System.err.println("length max array is: "+ numbersArray.length);
}
```
> Out:<br>third element: 7<br>length of array: 4<br>new third element: 11<br>length max array is: 4

This example demonstrates an attempt to exceed the array's size, resulting in an `ArrayIndexOutOfBoundsException`.

For mutable vectors in Java, we use the `ArrayList` class. An ArrayList can dynamically resize itself, unlike arrays.

![ArrayList Java](https://raw.githubusercontent.com/gulybyte/gulybyte.github.io/master/public/static/images/articles/estrutura-de-dados-java/array-list.png)

```java
final var __ = " ; size: ";
var numbersList = new ArrayList<Integer>();

numbersList.add(2);
numbersList.add(3);
numbersList.add(5);
numbersList.add(7);
System.out.println(numbersList+__+numbersList.size());

numbersList.add(11);// no error (auto resize)
System.out.println(numbersList+__+numbersList.size());

numbersList.set(2, null);
numbersList.remove(4);
System.out.println(numbersList+__+numbersList.size());
```
>Out:<br>[2, 3, 5, 7] ; size: 4<br>[2, 3, 5, 7, 11] ; size: 5<br>[2, 3, null, 7] ; size: 4

The `ArrayList` dynamically resizes itself when elements are added or removed, which is not possible with arrays.

The automatic resizing of the `ArrayList` (or ResizableArray) works by pre-allocating extra space to allow the addition of new elements beyond its current size. When the number of elements exceeds the pre-allocated capacity, the `ArrayList` increases its capacity by creating a new, larger internal array and copying the elements from the old array to the new one. This process ensures dynamic growth without losing data. Typically, the `ArrayList` pre-allocates about 50% more space than its current size, and in some cases, it doubles its capacity.

![ResizableArray ArrayList Java](https://raw.githubusercontent.com/gulybyte/gulybyte.github.io/master/public/static/images/articles/estrutura-de-dados-java/array-list-redimensionamento.png)

```java
final var __ = " ; size: ";
var numbersList = new ArrayList<Integer>(12);

numbersList.addAll(Arrays.asList(
  2,3,5,7,11,13,17,19,23,29
));
System.out.println(numbersList+__+numbersList.size());
numbersList.addAll(Arrays.asList(
  31,37,41,43,47
));
System.out.println(numbersList+__+numbersList.size());
```
> Out:<br>[2, 3, 5, 7, 11, 13, 17, 19, 23, 29] ; size: 10<br>[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47] ; size: 15

##### For more information of arraylist, [see this](https://gulybyte.github.io/articles/estrutura-de-dados-java/list/array-list).

# ***matrix***

<details closed>

<summary><h4><small><small>(my)</small></small> mathematical definition for <b><i>matrix</i></b></h4></summary>

> Definition without considering memory.

A ***matrix*** $M$ is a data structure consisting of a _mathematical matrix_ $C_{m\times n}$ of elements $\alpha$, where each element is identified by a pair of indices $(i, j)$ belonging to sets $S_\gamma$ and $S_\lambda$ respectively. These elements $\alpha$ are of the same type $T$. That is: 
$$M=\{((i,j),\alpha)\text{ | }i \in S_\gamma\text{, }j\in S_\lambda\text{, }\alpha\in C_{m\times n}\}$$

where:

- $T \Leftrightarrow$ ADT (abstract data type)

- $C_{m\times n} \subset T$

- $\gamma=(0,1,\dots,m-1)\Leftrightarrow$ Tuple $\gamma$ of $m$ terms for the number of $m$ rows of $C_{m\times n}$

- $\lambda=(0,1,\dots,n-1)\Leftrightarrow$ Tuple $\lambda$ of $n$ terms for the number of $n$ columns of $C_{m\times n}$

- $S_\gamma = \{\gamma\} = \{0,1,\dots,m-1\} \Leftrightarrow S_\gamma$ is the set of indices of tuple $\gamma$

- $S_\lambda = \{\lambda\} = \{0,1,\dots,n-1\} \Leftrightarrow S_\lambda$ is the set of indices of tuple $\lambda$

#### Example with $C_{2\times 4} = \{5,8,6,7,2,3,4,1\} = \begin{bmatrix} 5 & 2 \\ 8 & 3 \\ 6 & 4 \\ 7 & 1 \end{bmatrix}$

$$C_{2\times 4} = \begin{bmatrix} 5 & 2 \\ 8 & 3 \\ 6 & 4 \\ 7 & 1 \end{bmatrix}\Rightarrow S_\gamma=\{0,1\}\text{ e }S_\lambda = \{0,1,2,3\}$$

> therefore:

$$M = \{((0,0),5)\text{; }((0,1),8)\text{; }((0,2),6)\text{; }((0,3),7)\text{; }((1,0),2)\text{; }((1,1),3)\text{; }((1,2),4)\text{; }((1,3),1)\}$$

</details>


---

...

---
