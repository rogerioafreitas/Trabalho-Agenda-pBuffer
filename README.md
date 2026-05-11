# 🧠 Zero-Variable CRUD in C

Este projeto é um sistema de gerenciamento de contatos (CRUD) desenvolvido inteiramente em C com um desafio técnico extremo: **nenhuma variável local foi declarada em todo o programa.**

Todo o controle de fluxo, armazenamento de dados e passagem de parâmetros é feito manipulando um único ponteiro genérico (`void *pBuffer`) alocado dinamicamente no *Heap*, utilizando aritmética de ponteiros avançada, `realloc` e `memmove`.

## 🚀 Funcionalidades

O sistema permite gerenciar cadastros contendo **Nome**, **Idade** e **Email**.
- **[1] Adicionar Pessoa:** Aloca espaço dinamicamente e anexa o novo registro ao final do buffer.
- **[2] Remover Pessoa:** Busca o registro pelo nome, utiliza `memmove` para deslocar os dados adjacentes (fechando o "buraco" na memória) e usa `realloc` para devolver a memória não utilizada ao Sistema Operacional.
- **[3] Buscar Pessoa:** Varredura linear pelo buffer utilizando saltos de *offset* calculados dinamicamente via `strlen` e `sizeof(int)`.
- **[4] Listar Todos:** Percorre e exibe todos os dados estruturados na memória.

## 🛠️ Arquitetura de Memória

Para contornar a ausência de variáveis de escopo, o bloco contíguo de memória apontado por `pBuffer` foi estruturado com o seguinte layout base (Header):

| Posição / Offset | Tamanho | Propósito (Papel na Máquina de Estados) |
| :--- | :--- | :--- |
| Base + 0 | 4 bytes (int) | Registrador volátil (Opções do Menu, scanf temporário). |
| Base + 4 | 4 bytes (int) | Acumulador Total de Bytes dos dados salvos (Tamanho da payload). |
| Base + 8 | 4 bytes (int) | Offset de leitura/navegação (usado nos laços while). |
| Base + 12 | 100 bytes | Área de Scratchpad temporária (buffer para fgets e buscas). |
| Base + 112... | Dinâmico | Início da área de dados (Nome \0 + Idade int + Email \0). |

## 💻 Como Executar

Certifique-se de ter um compilador C (como o GCC) instalado em sua máquina.

1. Clone o repositório:
   git clone https://github.com/rogerioafreitas/Trabalho-Agenda-pBuffer.git

2. Navegue até o diretório e compile o código:
   gcc main.c -o crud

3. Execute o programa:
   ./crud

## 🧠 Aprendizados e Desafios

Este projeto foi um exercício intenso de **Gerenciamento Manual de Memória**. Os principais conceitos aplicados incluem:

- **Aritmética de Ponteiros:** Conversões (casts) constantes para (char*) e (int*) para manipulação de bytes e leitura de valores escalares.
- **Compactação de Heap:** Uso preciso do memmove para lidar com sobreposição de blocos de memória (overlapping) durante a deleção de registros.
- **Prevenção de Segfaults e Memory Leaks:** Cálculo rigoroso de fronteiras de memória (bounds checking) e redimensionamento físico pós-deleção.

---
*Desenvolvido como um desafio focado em domínio de baixo nível e arquitetura de computadores.*


Link Vídeo para Informática UFPEL: https://drive.google.com/file/d/10IM7D-JTUALDNMlrv6vBEtcwWBguLEqb/view?usp=sharing