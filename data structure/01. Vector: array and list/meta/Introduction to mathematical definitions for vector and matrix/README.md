### Notations
- $\mathbb{N}_0=\mathbb{N} ∪ \{0\} \Leftrightarrow$ os números naturais;
- ***vector*** = `array` or `list` One-Dimensional;
- ***matrix*** = `array` or `list` Two-Dimensional;
- tupla (as vezes chamada de ênupla) é uma sequência finita. A definição usada é a de [Introduction to the Theory of Computation - Michael Sipser](https://duckduckgo.com/?q=ISBN+978-1133187790&ia=web).


# Introduction to <small><small><small>(_my_)</small></small></small> mathematical definitions for ***vector*** and ***matrix***.

## ***Vector*** (array or list one-dimensional)
> definition without memory.

Um ***vector*** $V$ é uma estrutura de dados que consiste num conjunto $C$ de elementos $\alpha$ com cada elemento sendo identificado por um indice $i$ de um conjunto $S_t$, esses elementos $\alpha$ são do mesmo tipo $T$. Ou seja:

$$V = \{(i,\alpha)\text{ | }i\in S_t\text{, }\alpha\in C\}$$
onde:

- $T \Leftrightarrow$ ADT ([abstract data type]((https://en.wikipedia.org/wiki/Abstract_data_type)))

- $C\subset T$

- $t=(0,1,\dots,n-1) \Leftrightarrow$ Tupla $t$ de $n$ termos dos $\mathbb{N}_0$ ($n\in\mathbb{N}_0$)

    - $n =|C| \Leftrightarrow$ O número dos $n$ termos são o número de elementos do conjunto $C$ (ou a cardinalidade de $C$)

- $S_t = \{t\} = \{0,1,\dots,n-1\} \Leftrightarrow S_t$ é a tupla $t$ na forma conjunto

#### Exemplo com $C=\{5,8,6,7\}$:

- $C=\{5,8,6,7\} \Rightarrow S_t=\{0,1,2,3\}$
> portanto:
- $V=\{(0,5)\text{; }(1,8)\text{; }(2,6)\text{; }(3,7)\}$

## ***Matrix*** (array or list two-dimensional)
> definition without memory.

Uma ***matrix*** $M$ é uma estrutura de dados que consiste numa _matriz matematica_ $C_{m\times n}$ de elementos $\alpha$, onde cada elemento é identificado por um par de índices $(i, j)$ pertencentes a conjuntos $S_\gamma$ e $S_\lambda$ respectivamente. Esses elementos $\alpha$ são do mesmo tipo $T$. Ou seja: 
$$M=\{((i,j),\alpha)\text{ | }i \in S_\gamma\text{, }j\in S_\lambda\text{, }\alpha\in C_{m\times n}\}$$

onde:

- $T \Leftrightarrow$ ADT (abstract data type)

- $C_{m\times n} \subset T$

- $\gamma=(0,1,\dots,m-1)\Leftrightarrow$ Tupla $\gamma$ de $m$ termos das $m$ linhas de $C_{m\times n}$

- $\lambda=(0,1,\dots,n-1)\Leftrightarrow$ Tupla $\lambda$ de $n$ termos das $n$ colunas de $C_{m\times n}$

- $S_\gamma = \{\gamma\} = \{0,1,\dots,m-1\} \Leftrightarrow S_\gamma$ é a tupla $\gamma$ na forma conjunto

- $S_\lambda = \{\lambda\} = \{0,1,\dots,n-1\} \Leftrightarrow S_\lambda$ é a tupla $\lambda$ na forma conjunto

#### Exemplo com $C_{2\times 4} = \{5,8,6,7,2,3,4,1\}$

$C_{2\times 4} = \{5,8,6,7,2,3,4,1\} \Rightarrow S_\gamma=\{0,1\}\text{ e }S_\lambda = \{0,1,2,3\}$

$M = \{((0,0),5)\text{; }((0,1),8)\text{; }((0,2),6)\text{; }((0,3),7)\text{; }((1,0),2)\text{; }((1,1),3)\text{; }((1,2),4)\text{; }((1,3),1)\}$


## Definition for ***Vector*** and ***Matrix*** with Memory.

Partindo das definições feitas em ***[vector](#vector-array-or-list-one-dimensional)*** e ***[matrix](#matrix-array-or-list-two-dimensional)***, iremos agora extender essas definições visando formar uma intuição generalizada de como ***vectors*** e ***matrixes*** são estruturados na memória do computador, faremos isso sem entrar a fundo nos conceitos de toria da computação para não ficar extenso demais, até porque as próprias definições dadas para as estruturas de dados foram através de um conjunto.

### ***Vector***

...



### ***Matrix***

...


