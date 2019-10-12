#include "header.hpp"
using namespace std;

extern unsigned** matriz;
extern int contaPrimos;
extern int sTempo, pTempo;

void primeNumCountSerial(void){
    contaPrimos = 0; // Reseta Contador
    for (unsigned i=0; i<M_SIZE; i++){
        for (unsigned j=0; j<M_SIZE; j++){
            if (isPrime(matriz[i][j])){
                contaPrimos++;
            }
        }
    }
}

void primeNumCountParallel(void){
    contaPrimos = 0; // Reseta Contador

}
