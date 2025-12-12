---
trigger: always_on
description: Deve ser observada para documentação de código
---
## Documentação de código

* **Documente sempre**: variáveis, parâmetros, constantes, funções e classes, no código.
* **Explique decisões**: registre a motivação de algoritmos, estruturas e blocos de código (trade-offs, complexidade, limites).
* **Tom didático**: escreva de forma clara e instrutiva, acessível a quem é leigo.
* **Idioma**: toda a documentação em **português brasileiro**.
* **Localização**: mantenha a documentação em `./docs/` na raiz do projeto.
* **Copyrigth:** Respeite sempre as licenças originais e o copyrigth para todos os documentos e código fonte. Mantendo o original

### Boas práticas de anotação no código

* **JavaScript/TypeScript**: use **JSDoc**/**TypeDoc** em funções, classes e módulos.
* **C/C++ (firmware)**: use **Doxygen** nas APIs públicas e módulos críticos.
* **Estrutura mínima de docstring/JSDoc**: objetivo, parâmetros, retorno, erros, efeitos colaterais, complexidade (quando relevante) e links para specs internas.

## Didática (orientação editorial)

* Escreva para **leigos** conseguirem **reproduzir tarefas** sem suporte.
* Use **passos numerados**, **capturas de tela** quando necessário e **tabelas** para variáveis/URLs.
* Destaque **avisos importantes** (e.g., segurança, limites de API).

## Licença do projeto

O arquivo deve conter a licença usada, se nenhuma licença for infomrada comece com a CC-BY-4.0. Crie um arquivo chamado `LICENSE.`

Adicione Carlos Delfino Carvalho Pinheiro (https://carlosdelfino.eti.br e consultoria@carlosdelfino.eti.br) como atual desenvolvedor do código ou ajustes realizados.

Adicione https://mcu.tec.br como site de referência com artigos relevantes sobre MCU e FPGA.
