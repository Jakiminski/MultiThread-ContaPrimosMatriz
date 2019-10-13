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

	cout << "[S]: A matriz possui " << contaPrimos << " números primos." << endl;
	cout << " Tempo de Execução: " << sTempo << " segundos." << endl << endl;

}

//
// Contagem por Threads
//


/*Thread*/
pthread_mutex_t mutexCnt, mutexIdx;
unsigned xPrev, yPrev;

void primeNumCountParallel(void){
    contaPrimos = 0; // Reseta Contador
	int numThreads = (int)(M_SIZE*M_SIZE) / (HEIGHT*WIDTH);
	pthread_t* threads = new pthread_t [numThreads];
	BlocoArgs* b = new BlocoArgs [numThreads];
	int status = FALSE;
	int k = 0; // Conta Threads; k <= numThreads
	
	// Threads, respectivas rotinas e o(s) Mutex(es)
	
	//Inicializa mutexes
	status = pthread_mutex_init(&mutexCnt,NULL) || pthread_mutex_init(&mutexIdx,NULL);
	assert(!status);

	// Cria Threads
	for (int i=0; i<M_SIZE; i+=HEIGHT){
		for (int j=0; j<M_SIZE; j+=WIDTH, k++){
			// BlocoArgs; submatriz por thread
			b[k].x = i;
			b[k].y = j;
			b[k].threadId = k;

			//status = pthread_create(&threads[k],NULL,rotina,&matriz[k]);
			assert(!status);
		}
	}

	cout << k << " threads criadas ." << endl; 
	/*
	for (k=0; k<numThreads; k++){
		status = pthread_join(threads[k],NULL);
		assert(!status);
	}
*/
	cout << "[P]: A matriz possui " << contaPrimos << " números primos." << endl;
	cout << " Tempo de Execução: " << pTempo << " segundos." << endl;
}



// Procedimento/Rotina, executado em determinada(s) Thread(s)
void* rotina(void* args){
	BlocoArgs* b = (BlocoArgs*) args;
	unsigned x0 = b->x, x1 = (b->x) + HEIGHT-1;
	unsigned y0 = b->y, y1 = (b->y) + WIDTH-1;


	while (true){
		
		// Cada Thread executando a rotina irá add diretamente ao contaPrimos
		countPrime(x0,x1,y0,y1); 
		pthread_mutex_lock(&mutexIdx);

	}
	
} 

