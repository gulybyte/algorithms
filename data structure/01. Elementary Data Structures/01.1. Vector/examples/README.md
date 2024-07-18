https://www.youtube.com/watch?v=_KSKH8C9Gf0

<!-- # Examples and Types of Vectors in Different Programming Languages

#### C/C++

In C, the array is dynamic (mutable by inference, it doesn't make sense to be dynamic and immutable), where the array (list) can grow as needed.

```c
#include <stdio.h>
#include <stdlib.h>

void main() {

    int dynamicMutableVector[] = {42, 7, 33, 81};

    printf("\nValue of indice 0: %d", dynamicMutableVector[0]);

    dynamicMutableVector[0] = 35;
    dynamicMutableVector[4] = 27;
    dynamicMutableVector[42] = 402;

    printf("\nValue of indice 0: %d", dynamicMutableVector[0]);
    printf("\nValue of indice 4: %d", dynamicMutableVector[4]);
    printf("\nValue of indice 42: %d", dynamicMutableVector[42]);

}
```
> Out:<br>Value of indice 0: 42<br>Value of indice 0: 35<br>Value of indice 4: 27<br>Value of indice 42: 402

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


#### Java

In Java, the array is dynamic and imutable, we can change elements through their indices, but we cannot change the size of the array.

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
 -->
