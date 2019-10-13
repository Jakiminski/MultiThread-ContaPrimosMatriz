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
    cout << "[S]: A matriz possui " << contaPrimos << " números primos." << endl;
	cout << " Tempo de Execução: " << sTempo << " segundos." << endl;

    /**Execução Paralela*/
    primeNumCountParallel();
    cout << "[P]: A matriz possui " << contaPrimos << " números primos." << endl;
	cout << " Tempo de Execução: " << pTempo << " segundos." << endl;
	/**desalocar matriz*/
    assert(delMatrix(matriz));

    return 0;
}
