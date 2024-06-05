### Notations
- $\mathbb{N}_0=\mathbb{N} ∪ \{0\} \Leftrightarrow$ the set of natural numbers with 0;
- ***vector*** = `array` or `list` One-Dimensional;
- ***matrix*** = `array` or `list` Two-Dimensional;
- tuple is a finite sequence. The definition used is from [Introduction to the Theory of Computation - Michael Sipser](https://duckduckgo.com/?q=ISBN+978-1133187790&ia=web).

<details closed>
<summary><h6>Disclaimer</h6></summary>

> Disclaimer:  this definition was made by me, the author of the repository. I am not a PhD or MSc in computer science, nor a mathematician by training. At the time of writing these definitions, I am in the first semester of a Bachelor's degree in computer science, so the definitions are subject to errors. The general goal of these mathematical definitions is to provide a mathematical intuition of what a ***vector*** and a ***matrix*** are in computing.

</details>


# Introduction to <small><small><small>(_my_)</small></small></small> mathematical definitions for ***vector*** and ***matrix***.

## ***Vector*** (array or list one-dimensional)
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

## ***Matrix*** (array or list two-dimensional)
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

#### Example with $C_{2\times 4} = \{5,8,6,7,2,3,4,1\}$

$C_{2\times 4} = \{5,8,6,7,2,3,4,1\} \Rightarrow S_\gamma=\{0,1\}\text{ e }S_\lambda = \{0,1,2,3\}$

> therefore:

$M = \{((0,0),5)\text{; }((0,1),8)\text{; }((0,2),6)\text{; }((0,3),7)\text{; }((1,0),2)\text{; }((1,1),3)\text{; }((1,2),4)\text{; }((1,3),1)\}$

