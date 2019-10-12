#include "header.hpp"
using namespace std;

/* HOW TO COMPILE THIS PROGRAM
*
* g++ <listar_todos_arquivos_.cpp> -pthread -o <nome_para_executavel>
*
*
*/

unsigned** matriz;
int contaPrimos = 0; // Quantos primos há na matriz?
int sTempo = 0, pTempo = 0; // Tempo de processamento em execução monolítica e em computação paralela 


int main() {
	
    setlocale(LC_ALL,"Portuguese");
    matriz = newMatrix(M_SIZE);
    assert(matriz!=NULL);    
    
    /**Execução Serial
    *Code Here

    */
    cout << "[S]: A matriz possui " << contaPrimos << " números primos. Tempo de Execução: " << sTempo << " segundos." << endl;
    
    /*Execução Paralela
    *Code Here

    */
    cout << "[P]: A matriz possui " << contaPrimos << " números primos. Tempo de Execução: " << pTempo << " segundos." << endl;

    assert(delMatrix(matriz));

    return 0;
}