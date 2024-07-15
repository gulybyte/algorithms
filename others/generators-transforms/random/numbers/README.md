# RANDOM NUMBERS.

> _"Any one who considers arithmetical methods of producing random digits is, of course, in a state of sin."_ — John Von Neumann

<h6>Sumario:</h6>

- [como gerar números aleatorios?](#como-gerar-números-aleátorios-no-computador-qual-algoritmo-é-capaz-de-fazer-isso)
- [garantindo aleatoriedade](#distribuição-estatística--processos-estocasticos--todo-renomear-no-sumario) TODO:
- [undefined temporariamente](#geração-de-prngs-aleatoria-partindo-duma-condição) TODO:

### Como gerar números aleátorios no computador? Qual algoritmo é capaz de fazer isso?

A verdade é que não é póssivel gerar números verdadeiramente aleatorios, o que temos é apenas geradores pseudo-aleatorios. Isso ocorre pois um número/resultado é considerado verdadeiramente aleatório quando é imprevisível e não segue um padrão determinístico claro, ou seja, **quando não depende estatisticamente de nenhum outro número**, como os algoritmos que usamos dependem de alguma variavel para serem gerados (known as the seed value or key), logo implica que não sejam verdadeiramente aleatorios, pois eles sempre estão relacionados a algo, ou seja, são deterministicos, por isso os chamamos de pseudo-aleatorios.

Vale dizer que no computador até é possível TRNGs, não através de um algoritmo, mas de outras formas. Uma das formas seria chamar uma função do hardware (seria um hardware especializado) que coletaria uma fonte de aleatoriedade de algum fenômeno físico que seja aleatório, isso é o que [random.org](https://www.random.org/) faz, onde o fenômeno físico da aleatoriedade vem do ruído atmosférico, que é um processo intrinsecamente aleatório e imprevisível. O problema é que, na prática, esses métodos são lentos e menos escaláveis, implicando que a PRNGs seja mais vantajoso nos quesitos velocidade e eficiência. Mas isso não significa que PRNGs seja ruim; na verdade, muitos algoritmos PRNGs são suficientemente robustos para atender praticamente todas as necessidades de geração de números aleatorios.

> Dictionary:
 - ***TRNGs***: true random number generators;
 - ***PRNGs***: pseudorandom number generators.

Ainda assim, como um algoritmo que é algo deterministico consegue gerar resultado mesmo que seja pseudo-aleatorio? A resposta está na matemática! Especificamente na aritmetica modular.

Segundo esse [artigo](https://www.freecodecamp.org/news/random-number-generator/), for PRNGs in general, those rules revolve around the following:

 1. **Accept** some initial input number, that is a seed or key.
 2. **Apply** that seed in a sequence of mathematical operations to generate the result. That result is the random number.
 3. **Use** that resulting random number as the seed for the next iteration.
 4. **Repeat** the process to emulate randomness.

<!-- TODO: imagem com entrada de uma seed que da output de uma sequencia de números aleatorios -->

Como exemplo técnico, veja a explicação do [linear congruential generator, um algoritmo simples de geração númerica pseudo-aleatoria](introduction-to-random-numbers-with-simple-algorithm/).

Mas o exemplo acima ainda é rudimentar se a ideia fosse gerar números aleatorios partindo do nada, muitas vezes (a maioria) queremos apenas gerar números resultados aleatorios sem fornecer uma seed, porém se a seed estiver hardcoded no código (ou seja, sempre a mesma seed) a os resultados PRNGs gerados serão sempre o mesmo. Para mitigar esse problema a forma mais simples seria definir a seed como a data e horario atuais, assim a seed sempre será diferente portanto o resultados gerados também.

### distribuição estatística ... processos estocasticos ... TODO: renomear no sumario

O algoritmo citado ([the linear congruential generator](introduction-to-random-numbers-with-simple-algorithm/)) é bom exemplo pois ele tem uma distruibuição uniforme, o que significa que os números gerados levarão muito tempo para se repetirem, nesse mesmo algoritmo dada `seed = 1` e uma sequencia com o tamanho de 40 milhões `n = 40000000`, dos 40 milhões de números gerados, não existe nenhum número gerado duplicado.

<!-- TODO: falar disso: https://youtu.be/j50_3TCguls, brevemente sobre os parametros do LCG e sobre o assunto do titulo -->
...


### geração de PRNGs aleatoria partindo duma condição

<!-- TODO: falar e estudar sobre o assunto do titulo -->

# Referencias

- Knuth, D. E. (1997). _The Art of Computer Programming, Volume 2: Seminumerical Algorithms_ (3rd ed.). Addison-Wesley.
- https://www.freecodecamp.org/news/random-number-generator/
- https://youtu.be/LqXnpIn2Uxs
- https://youtu.be/j50_3TCguls