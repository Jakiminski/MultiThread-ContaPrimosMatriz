#include "header.hpp"
using namespace std;

/** HOW TO COMPILE THIS PROGRAM
*
* g++ <lista_arquivos_.cpp> -pthread -o <nome_para_executavel>
* lista_arquivos = count.cpp util.cpp main.cpp
*
* TODO list:
* Implementar Execução por Threads
* Parametrizar Threads
* Medir tempo de processador serial
* Medir tempo de processador para as threads
*
*/

unsigned** matriz;
int contaPrimos = 0;
int sTempo = 0, pTempo = 0;


int main() {
	
	/**Gerar matriz com números aleatórios*/
    setlocale(LC_ALL,"Portuguese");
    matriz = newMatrix(M_SIZE);
    assert(matriz!=NULL);
#if PRINT
    showMatrix(matriz); 
#endif
    /**Execução Serial*/
    primeNumCountSerial();
   
    /**Execução Paralela*/
    primeNumCountParallel();
	
	/**desalocar matriz e encerrar todas as threads*/
    assert(delMatrix(matriz));
	pthread_exit(NULL);
}
