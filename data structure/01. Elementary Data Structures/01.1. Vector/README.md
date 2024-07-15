TODO: Obs: se for fazer algo matematico, que seja apenas uma relação matematica simples

# Vector

## Vetores
 1. **Array ou Vetor Estático** (não é possível aumentar o tamanho após a criação):
    - **Imutável**: Onde você não pode altarar nada do array. Por exemplo, em Rust, ou em Java usando `final`. 
    - **Mutável**: Onde você pode alterar os elementos, mas não o tamanho do array. Por exemplo, em Java, ou em Rust usando `mut`.
 2. **Lista ou Vetor Dinâmico** (é possível aumentar o tamanho após a criação):
    - **Mutável por inferência**: Como em C, onde as listas podem crescer conforme necessário.

<h6>(note que não faz sentido ser dinâmico e imutável)</h6>

### Estruturas Associadas
 - **Resizable Array**: Uma estrutura que permite comportamento de um lista (vetor dinâmico), mas que internamente usa um array (vetor estático). Exemplo: [em Java, a classe ArrayList que gerencia o redimensionamento automaticamente](https://gulybyte.github.io/articles/estrutura-de-dados-java).

