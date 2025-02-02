# 📌 TAD Lista Linear Simplesmente Encadeada (SLList)

## 📖 Descrição do Projeto
Este projeto implementa um **Tipo Abstrato de Dados (TAD) Lista Linear Simplesmente Encadeada (SLList)** e fornece uma API para manipulação de uma coleção de elementos do tipo escolhido. O programa permite criar, inserir, remover, consultar, listar e destruir a coleção de forma eficiente.

## 🖥️ Ambiente de Execução
- **🖥️ Sistema Operacional:** Windows
- **🛠️ Compilador:** GCC

## 📌 Estrutura de Dados
A estrutura utilizada no projeto contém os seguintes campos:
- **📝 char[30]** - Nome do elemento (ex: Nome do aluno, nome do time, etc.).
- **🔢 int** - Um identificador numérico (ex: ID, número de jogos, etc.).
- **📊 float** - Um valor decimal associado ao elemento (ex: nota, pontuação, etc.).

## ⚙️ Funcionalidades Implementadas
A API do TAD Lista Encadeada contém as seguintes operações:
- ✅ **Criar uma coleção**
- ✅ **Inserir um elemento** na coleção
- ✅ **Remover um elemento** identificado pelo `char`, `int` e `float`
- ✅ **Consultar um elemento** na coleção pelo `char`, `int` e `float`
- ✅ **Listar todos os elementos** da coleção
- ✅ **Esvaziar a coleção**
- ✅ **Destruir a coleção** (se estiver vazia)

### ❗ Regras Importantes
- **⚠️ O arquivo `time.c` não pode conter `printf`, `scanf` ou similares** (todas as operações de entrada e saída devem ser feitas no programa principal).
- **📌 O trabalho é individual.**

## 🔄 Roteiro para Teste
1️⃣ Criar uma coleção.
2️⃣ Inserir três elementos na coleção.
3️⃣ Listar os elementos da coleção.
4️⃣ Consultar um dos elementos na coleção.
5️⃣ Remover o segundo elemento inserido na coleção.
6️⃣ Listar os elementos da coleção.
7️⃣ Esvaziar a coleção.
8️⃣ Listar os elementos da coleção.

## 📂 Estrutura do Projeto
O arquivo comprimido enviado para avaliação deve conter:
- 📄 `README.md` (este arquivo)
- 📌 `time.h` (arquivo de cabeçalho com a definição da API)
- 🖥️ `time.c` (implementação do TAD Lista Encadeada)
- 🎯 `main.c` (programa principal para testes e interação com o usuário)
- 🔧 Pasta do projeto: `TAD-List`
- 🔧 Executável do programa (`.exe` para Windows)

## 🚀 Compilação e Execução
Para compilar e executar o programa manualmente via terminal:

```sh
# Compilar o programa
gcc -o programa main.c time.c -Wall

# Executar
./programa
```

## 👨‍💻 Autor
- **Nome:** Caio Moreira
- **Curso:** Estruturas de Dados I, Ciências da Computação - UFMA


