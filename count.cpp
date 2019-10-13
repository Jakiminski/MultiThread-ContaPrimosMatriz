#include "header.hpp"
using namespace std;

/*Matriz*/
extern unsigned** matriz;
extern int contaPrimos;
extern int sTempo, pTempo;

//Conta Numeros Primos em Intervalos
void countPrime(unsigned x0, unsigned x1, unsigned y0, unsigned y1){
    for (unsigned i=x0; i<x1; i++){
        for (unsigned j=y0; j<y1; j++){
            /*if (isPrime(matriz[i][j])){
                contaPrimos++;
            }*/
			contaPrimos += isPrime(matriz[i][j]);
        }
    }	
}

//
// Contagem Serial
//

void primeNumCountSerial(void){
	contaPrimos = 0; // Reseta Contador

	countPrime(0,M_SIZE,0,M_SIZE);
}

//
// Contagem por Threads
//


/*Thread*/
pthread_mutex_t mutexCnt, mutexIdx;
unsigned xPrev, yPrev;

void primeNumCountParallel(void){
    contaPrimos = 0; // Reseta Contador
	unsigned n = M_SIZE*M_SIZE/(HEIGHT*WIDTH); // Numero de Threads
	BlocoArgs* b = new BlocoArgs [n];
	// Threads, respectivas rotinas e o(s) Mutex(es)
	//Inicializa mutexes
	assert(pthread_mutex_init(&mutexCnt,NULL));
	assert(pthread_mutex_init(&mutexIdx,NULL));

	/* TODO
	for(int k = 0;k<n;k++){
		b[i].x;
		
	}
	*/
	pthread_exit(NULL);
}



// Procedimento/Rotina, executado em determinada(s) Thread(s)
void* rotina(void* args){
	BlocoArgs* b = (BlocoArgs*) args;
	unsigned x0 = b->x, x1 = b->x + HEIGHT;
	unsigned y0 = b->y, y1 = b->y + WIDTH;



	while(true){
		countPrime(x0,x1,y0,y1); 
		// Cada Thread executando a rotina irá add diretamente ao contaPrimos

		//pthread_mutex_lock
	}
	
} 

