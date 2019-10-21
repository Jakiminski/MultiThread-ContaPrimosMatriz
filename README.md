# MultiThread-ContaPrimosMatriz

Dada uma matriz de números naturais aleatórios verificar quantos números primos existem e contabilizar o tempo necessário para realizar esta computação. Veja na íntegra o [contexto de implementação](./contexto.pdf) do referido programa.

## Máquina
- Notebook Acer Aspire V3
- Processador Intel Core i7-3632QM @2.2GHz x 8
- 8GBs RAM
- 500GB HD
- Ubuntu 18.04.3 LTS 64 bits / Windows 10 64 bits

## Compilação
:bowtie: 
Foi usado o compilador de C++ *g++ (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0* (Ubuntu). Pode-se também usar o compilador *g++ (tdm-1) 4.9.2* (Windows) ou similar para gerar o arquivo executável na sua máquina. No seu terminal, compile o programa usando o seguinte comando no diretório onde se encontra o código-fonte:
* Windows: ```g++ main.cpp count.cpp util.cpp -o ContaPrimosMatriz -lpthread```.
* Linux:  ```g++ -o ContaPrimosMatriz main.cpp util.cpp count.cpp -lpthread```.
Uma vez compilado, rode o arquivo executável com o nome ```ContaPrimosMatriz``` ou equivalente na sua máquina.

## Parâmetros
Vá para o arquivo ```macros.hpp```, onde as dimensões da matriz e das submatrizes podem ser alterados, através de pre-compilação de diretivas ```#define```.  Edite **apenas** o seguinte trecho: 
```
// MATRIZ
	#define M_HEIGHT (unsigned) 2000 // Altura da Matriz
	#define M_WIDTH (unsigned) 1500 // Largura da Matriz
    	
	
	// BLOCOS DA MATRIZ (Threads)
	// (x e y estão trocados no plano cartesiano)
	//Obs: M_SIZE deve ser divisivel por HEIGHT e WIDTH
  #define MAX_THREADS 6 // Qnt. Máxima de Threads
	#define HEIGHT (unsigned) 4 // Altura 
	#define WIDTH (unsigned) 3 // Largura
```

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

## Issues
- Parametrização do Número de Threads possui um bug, pois quando uma thread percorre mais de um bloco ocorre um dos dois efeitos colaterais, que não puderam ser solucionados corretamente:
1. A última coluna de blocos não tem todos os elementos contados; OU
2. Todos os elementos são contados, porém ocorre falha de segmentação.  

## GitHub
:octocat: [MultiThread-ContaPrimosMatriz](https://github.com/Jakiminski/MultiThread-ContaPrimosMatriz/)

## Sources

#### Sites
* [CPlusPlus.com](http://www.cplusplus.com/)
* [GNU's Processor Time Analysis](https://www.gnu.org/software/libc/manual/html_node/Date-and-Time.html)

#### Livros
* Sistemas Operacionais Modernos - Tanenbaum - Cap. 2, 4ª Edição.
