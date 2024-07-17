TODO: Obs: se for fazer algo matematico, que seja apenas uma relação matematica simples

# Vector

## Simple Definition

A vector is a data structure consisting of a collection of elements (values or variables) one-dimensional, all of its elements are of the same data type (therefore, same memory size), and each element is identified by at one array index.

## Formal Definition

Um vetor unidimensional $V$ pode ser definido como uma relação, onde o vetor $V$ é a aplicação dos indices $i$ de $S$ para os valores $x$ de um [abstract data type](https://en.wikipedia.org/wiki/Abstract_data_type) $T$ na forma:

#### $$V: S\rightarrow T\Leftrightarrow(i\in S,\exists !x\in T\text{ | }(i,x)\in V)$$

de forma simplicada:

#### $$V=\{(i,x)\text{ | }i\in S, x\in T\text{ and }x=V[i]\}$$

onde $T$ é um [ADT](https://en.wikipedia.org/wiki/Abstract_data_type) para representar os valores $x$ contidos no vetor $V$, que são identificados por um indice $i$ (ou seja, $x=V[i]$). Esse indice $i$ pertence a uma sequência $S$ dos naturais incluindo o 0, $\mathbb{N}_0$. Ou seja:

#### $$V:\{0,1,2,\dots,n-1\}\rightarrow T$$

Esta notação deixa claro que cada índice $i$ tem um único valor associado $x$, e isso é expresso pela unicidade da existência de $x$ para cada $i$.

#### Exemplo:

Vamos dizer que nossos elementos $x$ serão um conjunto $E$ de alguns números inteiros (ou seja, $x\in E | E\subset\mathbb{Z}\subset T$), como exemplo $E=\{-37,-2,0,3,9,94\}$, de acordo com a definição temos:

#### $$V:\{0,1,2,\dots,n-1\}\rightarrow \{-37,-2,0,3,9,94\}$$

Sendo então $(i\in \{0,1,2,\dots,n-1\},\exists !x\in \{-37,-2,0,3,9,94\}\text{ | }(i,x)\in V)$ temos que:

#### $$V=\{(0,-37)\text{; }(1,-2)\text{; }(2,0)\text{; }(3,3)\text{; }(4,9)\text{; }(5,94)\}$$

Então se sabemos que $x=V[i]$ nessa relação, sabemos que:
 - $V[0]=-37$
 - $V[1]=-2$
 - $V[2]=0$
 - $V[3]=3$
 - $V[4]=9$
 - $V[5]=94$

Essa é a definição geral, qualquer tipo de vetor unidimensional se comporta da forma apresentada, a diferença é como cada vetor implementa isso na memória do computador.

Partindo agora dessa mesma definição, veremos como cada tipo de vetor implementa essa definição na memória.


# Tipos de Vector

### Existem dois tipos

 1. **Vetor estático, que chamamos de array**: nele não é possível aumentar o tamanho após a criação;
 2. **Vetor dinâmico, que chamamos de lista**: nele é possível aumentar o tamanho após a criação.

Agora, vamos definir mais formalmente os dois tipos de Vetor.

### Notação de Alocação de Memória: LOC e CONTENT

Para abstrair a locação de memória no computador, será ultilizado a mesma notação de Donald Knuth em The Art of Computer Programming. Com ela podemos representar melhor conteúdos e endereços de memória de forma concisa.

Considere os seguintes valores com seus repectivos endeços de onde se encontram na memória:

![](examples/memory.png)

| Endereço na Memória | Valor/Conteúdo |
| - | - |
| 0x3E8 | 5 |
| 0x3DA | Object |
| 1x4F9 | "hello" |

Com as notações LOC e CONTENT, podemos ...





### Vetor Estatico: ARRAY.

Um vetor estatico é aquele que é alocado de maneira sequencial na memória, ou seja, quando ele respeita a seguinte equação:

#### $$\text{LOC}(V[i+1])=\text{LOC}(V[i])+c$$

Onde $c$ é o tamanho em memória do tipo do array


### Estruturas Associadas
 - **Resizable Array**: Uma estrutura que permite comportamento de um lista (vetor dinâmico), mas que internamente usa um array (vetor estático). Exemplo: [em Java, a classe ArrayList que gerencia o redimensionamento automaticamente](https://gulybyte.github.io/articles/estrutura-de-dados-java). parece que vale a pena para manter O(1)

A forma como são implementados varia entre as linguagens de programação, [veja mais aqui](examples/).
