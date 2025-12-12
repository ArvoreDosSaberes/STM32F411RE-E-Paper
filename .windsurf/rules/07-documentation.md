---
trigger: model_decision
description: Deve ser sempre observada para criação de documentação e sua manteunção (atualização)
---
## Documentação (princípios)

* **Explique decisões**: registre a motivação de algoritmos, estruturas e blocos de código (trade-offs, complexidade, limites).
* **Tom didático**: escreva de forma clara e instrutiva, acessível a quem é leigo.
* **Idioma**: toda a documentação em **português brasileiro**.
* **Localização**: mantenha a documentação em `./docs/` na raiz do projeto.
* **Atualização:** Existindo os arquivos, leia-os e atualize seu conteúdo, ajustando o texto existente.
* **Copyrigth:** Respeite sempre as licenças originais e o copyrigth para todos os documentos e código fonte. Mantendo o original

---

## README.md principal

O readme principal deve conter o título do projeto com palavras separadas por espaços.

Deve conter uma seção que descreva o projeto e seu propósito.

Deve conter uma seção que informa as bibliotecas usadas, consulte cmakelists.txt para obter as informações. Além disso verifique o arquivo .gitmodules para obter os submódulos do projeto.

Deve conter os badges do git hub, com linguagem usada,  a Licença usada, seguindo o exemplo a seguir:

![Visitors](https://visitor-badge.laobi.icu/badge?page_id=ArvoreDosSaberes.esp-i2c-scanner)[![License: CC BY 4.0](https://img.shields.io/badge/License-CC%20BY%204.0-lightgrey.svg)](https://creativecommons.org/licenses/by/4.0/)
[![ESP-IDF](https://img.shields.io/badge/ESP--IDF-v5.0%2B-blue.svg)](https://docs.espressif.com/projects/esp-idf/en/latest/)
[![C](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![ESP32](https://img.shields.io/badge/ESP32-Supported-green.svg)](https://www.espressif.com/en/products/socs/esp32)
[![ESP32-S2](https://img.shields.io/badge/ESP32--S2-Supported-green.svg)](https://www.espressif.com/en/products/socs/esp32-s2)
[![ESP32-S3](https://img.shields.io/badge/ESP32--S3-Supported-green.svg)](https://www.espressif.com/en/products/socs/esp32-s3)
[![ESP32-C3](https://img.shields.io/badge/ESP32--C3-Supported-green.svg)](https://www.espressif.com/en/products/socs/esp32-c3)
[![ESP32-C6](https://img.shields.io/badge/ESP32--C6-Supported-green.svg)](https://www.espressif.com/en/products/socs/esp32-c6)
[![ESP32-H2](https://img.shields.io/badge/ESP32--H2-Supported-green.svg)](https://www.espressif.com/en/products/socs/esp32-h2)
[![GitHub](https://img.shields.io/github/stars/ArvoreDosSaberes/esp-i2c-scanner?style=social)](https://github.com/ArvoreDosSaberes/esp-i2c-scanner)
[![GitHub Issues](https://img.shields.io/github/issues/ArvoreDosSaberes/esp-i2c-scanner)](https://github.com/ArvoreDosSaberes/esp-i2c-scanner/issues)

Adicione como mantenedor Carlos Delfino site https://carlosdelfino.eti.br e-mail consultoria@carlosdelfino.eti.br, comente sobre o site https://mcu.tec.br que tem artigos relevantes sobre MCUs e FPGAs.

## Licença do projeto

O arquivo deve conter a licença usada, se nenhuma licença for infomrada comece com a CC-BY-4.0. Crie um arquivo chamado `LICENSE.`

Adicione Carlos Delfino Carvalho Pinheiro (https://carlosdelfino.eti.br e consultoria@carlosdelfino.eti.br) como atual desenvolvedor do código ou ajustes realizados.

Adicione https://mcu.tec.br como site de referência com artigos relevantes sobre MCU e FPGA.

## Estrutura recomendada em `docs/`

```
LICENSE
README.md
docs/
  README.md                  # Lista dos documentos, resumo e links para cada um
  REQUIREMENTS.md            # Requisitos funcionais e não funcionais
  PLAN.md                    # Planejamento (roadmap, milestones, riscos)
  CHANGELOG.md               # Histórico de mudanças
  architecture.md            # Arquitetura (DDD, camadas, diagramas)
  decisions/
    ADR-0001-titulo.md       # Architecture Decision Records
  integrations/
    google.md
    linkedin.md
    facebook.md
    apple.md
    microsoft.md
    ...
  how-to/
    setup-dev.md             # Ambiente de dev
    run-tests.md             # Execução de testes
    deploy.md                # Deploy por ambiente
    troubleshooting.md       # Problemas comuns e soluções
  guidelines/
    coding-standards.md
    logging.md
    security.md
```

---

## Passo a Passo de Integrações (Google, LinkedIn, Facebook, Apple, Microsoft, etc.)

Para **cada** provedor, criar um arquivo em `docs/integrations/<provedor>.md` contendo:

1. **Resumo** (o que integra e por quê)
2. **Pré-requisitos** (contas, permissões, billing, SDKs)
3. **Criação do app** no provedor (telas com passos numerados)
4. **Scopes/Permissões** requeridos e justificativa
5. **Callback URLs / Redirects** (por ambiente)
6. **Variáveis de ambiente** (nomes exatos, onde configurar)
7. **Fluxos OAuth/OIDC** (PKCE, Client Credentials, etc.)
8. **Mapeamento de dados** (claims/fields → entidades do sistema)
9. **Testes manuais** (checklist) e **testes automatizados** (se aplicável)
10. **Resolução de problemas** (erros comuns, códigos e correções)

> Observação: incluir prints/tabelas quando facilitar o entendimento. Sempre numerar os passos.

---

## Didática (orientação editorial)

* Escreva para **leigos** conseguirem **reproduzir tarefas** sem suporte.
* Use **passos numerados**, **capturas de tela** quando necessário e **tabelas** para variáveis/URLs.
* Destaque **avisos importantes** (e.g., segurança, limites de API).
* Inclua **tempo estimado** por tarefa quando fizer sentido.

---

## Requisitos e Planejamento

### `REQUIREMENTS.md` (sempre começar por aqui)

* Contexto e objetivos (escopo/fora do escopo)
* Requisitos funcionais e não funcionais
* Restrições (legais, técnicas, desempenho, custo)
* Critérios de aceite e métricas de sucesso

### `PLAN.md` (sequência após requisitos)

* Roadmap (marcos e entregas)
* Estrutura de trabalho (épicos, histórias)
* Riscos e mitigação
* Plano de testes e validação
* Plano de rollout/rollback

### `CHANGELOG.md` (por fim)

* Use o formato cronológico com entradas agrupadas por versão:

  * **Added**, **Changed**, **Fixed**, **Removed**, **Security**
* Referencie issues/PRs e datas.

---

## Versionamento

* **Formato**: `x.y.z`

  * **x (major)**: mudanças **de paradigma ou arquiteturais** (quebras de compatibilidade).
  * **y (minor)**: mudanças **básicas** que **impactam a arquitetura**, mas **mantêm compatibilidade**.
  * **z (patch)**: política especial:

    * **z par** → **novos recursos** sem quebrar compatibilidade;
    * **z ímpar** → **correções de bugs**.
* Exemplos:

  * `2.3.7` → correção de bug (z ímpar).
  * `2.4.8` → novo recurso compatível (z par).
  * `3.0.0` → mudança estrutural com quebra (major).

> Sempre atualizar `CHANGELOG.md` e tags no repositório ao alterar a versão.
