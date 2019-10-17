# MultiThread-ContaPrimosMatriz
Dada uma matriz de números naturais aleatórios verificar quantos números primos existem e contabilizar o tempo necessário para realizar esta computação. Veja na íntegra o [contexto de implementação](./contexto.pdf) do referido programa.

## Compilação
:bowtie: 
Foi usado o compilador de C++ *g++ (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0* (Ubuntu). Pode-se também usar o compilador *g++ (tdm-1) 4.9.2* (Windows) ou similar para gerar o arquivo executável na sua máquina. No seu terminal, compile o programa usando o seguinte comando no diretório onde se encontra o código-fonte:
Windows: ```g++ main.cpp count.cpp util.cpp -o run -lpthread```.
Linux:  ```g++ -o run main.cpp util.cpp count.cpp -lpthread```.
Uma vez compilado, rode o arquivo executável com o nome ```run.exe``` ou equivalente na sua máquina.

## Licença
[GNU General Public License v3.0](/LICENSE)

## TaskList
#### Implementar Execução Serialmente
- [X] Adicionar Bibliotecas do Sistema/ de C/C++ que serão utilizadas
- [X] Macros para parametrização do programa
- [X] Identicar se um número é primo
- [X] Matriz de inteiros positivos com valores aleatórios
 
#### Implementar Execução por Threads
- [X] Particionar Matriz em Blocos
- [X] Parametrizar Threads
- [X] Implementar Rotina
- [X] Definir qnt. de Threads e atuação de cada uma (vide parâmetros)
- [X] Medir tempo de processador serial
- [X] Medir tempo de processador para as threads


## GitHub
:octocat: [MultiThread-ContaPrimosMatriz](https://github.com/Jakiminski/MultiThread-ContaPrimosMatriz/)

## *GNU's Processor Time Analysis*
* [The GNU C Library -Date and Time](https://www.gnu.org/software/libc/manual/html_node/Date-and-Time.html).
