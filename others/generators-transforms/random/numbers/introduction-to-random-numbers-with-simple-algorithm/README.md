# Introduction com um algoritmo simples

<h6>Sumario:</h6>

- [um algoritmo simples](#um-belo-exemplo-the-linear-congruential-generator)
- [a escolha dos parametros torna o algoritmo eficiente](#escolha-dos-parâmetros)

### The Algorithm. The Linear Congruential Generator.
The generator is defined by the linear relation:

#### $$X_{n+1} \equiv (aX_n + c) \text{ mod } m \quad|\quad n \geq 0$$

#### Para isso, as seguintes condições:

| parametros | description | satisfy this conditions |
| - | - | - |
| $m$ | the modulus | $m>0$ |
| $a$ | the multiplier | $0\leq a<m$ |
| $c$ | the increment | $0\leq c<m$ |
| $X_0$ | the starting value | $0\leq X_0<m$ |


Código em lua, com os paramtros na forma $m=10$ e $a=c=X_0=7$:
```lua
function linearCongruentialGenerator(x0, a, c, m, n)
    local results = {}
    if a > 0 and m > 0 and c >= 0 and x0 >= 0 and a < m and c < m and x0 < m then
        for i = 1, n do
            x0 = (a * x0 + c) % m
            table.insert(results, x0)
        end
    else
        print('Condições não satisfeitas')
    end
    return results
end

local seed = 7
local multiplier = 7
local increment = 7
local modulus = 10simple-algorit

local n = 20

local lcg = linearCongruentialGenerator(seed, multiplier, increment, modulus, n)
local output = table.concat(lcg, " ")
print(output)


-- 6, 9, 0, 7, 6, 9, 0, 7, ...
```

A base é essa, um algoritmo que produz uma sequencia de números pseudo-aleatorios a partir de uma chave, que nasceu da necessidade de uma sequência (de $\mathbb Z$) determinística que, embora não seja verdadeiramente aleatória, tenha propriedades estatísticas que a façam parecer aleatória.

O problema é que a sequencia gerada <small>(6, 9, 0, 7, 6, 9, 0, 7, ...)</small> não está parecendo aleátoria, mas isso não significa que o algoritmo (apresentado por [Lehmer](https://en.wikipedia.org/wiki/D._H._Lehmer)) tenha falhado em sua premissa, o problema da sequencia gerada está nas escolhas dos parametros.

### Escolha dos Parâmetros

Para garantir uma sequência que possua um período longo antes de se repetir, é estabelecido as seguintes condições nas escolhas dos parametros:

 - $m$ deve ser grande e também potencia de 2, ou seja: $m \text{ mod }4\equiv 0$. Assim é facilitado os calculos computacionais em binario e permite um longo período;
 - $c$ deve ser coprimo a $m$, ou seja: $gdc(c,m)=1$. Assim a sequencia não se repete em ciclos curtos;
 - $a−1$ deve ser divisível por todos os fatores primos de $m$ e por $4$, ou seja:
    - $(a−1)\text{ mod }p\equiv 0$ para cada fator primo $p$ de $m$
    - $(a-1)\text{ mod }4\equiv 0$
    - Assim a sequência terá um bom comportamento em termos de aleatoriedade e distribuição.

Dada essas condições, é concluido os seguinte valores para os parametros:

 - $m=2^{32}=4294967296$
    - Justificativa: $2^{32}$ é grande e é potencia de 2
 - $c=1013904223$
    - Justificativa: $1013904223$ é coprimo de $2^{32}$
 - $a=1664525$
    - Justificativa: $1664525-1\text{ mod }p\equiv 0 \text{ }\forall$ fator primo $p$ de $m$, e $1664525-1\text{ mod }4\equiv 0$

Esses valores também satisfazem as [condições da equação](#para-isso-as-seguintes-condições).

Com esses parametros, o algoritmo funciona de forma excelente, mesmo com a `seed = 1` e `n = 40000000`, dos 40 milhões de resultados não houve nenhum número gerado duplicado.