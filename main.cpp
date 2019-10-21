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
   	cout << "Criando matriz...\n";
    	matriz = newMatrix();
    	cout << "Matriz criada!\n";
    	assert(matriz!=NULL);
#if PRINT
    	showMatrix(matriz); 
#endif

#if SERIAL_COUNT
    	/**Execução Serial*/
    	cout << "\nContagem Serial...\n";
    	primeNumCountSerial();
    	cout << "Tempo de execução " << sTempo << " segundos." << endl;
#endif

#if PARALLEL_COUNT 
	/**Execução Paralela*/
	cout << "\nContagem com threads...\n";
	primeNumCountParallel();
	cout << "Tempo de execução " << pTempo << " segundos." << endl;
#endif
 
    	/**desalocar matriz e encerrar todas as threads*/
	assert(delMatrix(matriz));
	pthread_exit(NULL);

}
