#include "header.hpp"
using namespace std;

//Matriz
extern unsigned** matriz;
extern int contaPrimos;
extern int sTempo, pTempo;

//Conta Numeros Primos em Intervalos
int countPrime(unsigned x0, unsigned x1, unsigned y0, unsigned y1){
	int sum = 0;
    for (unsigned i=x0; i<x1; i++){
        for (unsigned j=y0; j<y1; j++){
            sum += isPrime(matriz[i][j]);
        }
    }	
	return sum;
	cout << "\nCount!\n";
}


//
//
// Contagem Serial
//

void primeNumCountSerial(void){
	
        sTempo = time(NULL);	
	contaPrimos = countPrime(0,M_HEIGHT,0,M_WIDTH);
	sTempo = time(NULL) - sTempo;

	cout << "[S]: A matriz possui " << contaPrimos << " números primos." << endl;

}


//
//
// Contagem por Threads
//

//Thread
pthread_mutex_t mutex;
unsigned xPrev, yPrev;
int numThreads = (int) (M_HEIGHT*M_WIDTH)/(HEIGHT*WIDTH);


void primeNumCountParallel(void){

    	contaPrimos = 0; // Reseta Contador

	pthread_t* threads = new pthread_t [numThreads];
	BlocoArgs* b = new BlocoArgs [numThreads];
	numThreads = 0; 
	int k = 0;// Conta Threads; k <= numThreads
	int status;
	// Threads, respectivas rotinas e o(s) Mutex(es)
	
	//Inicializa mutex
	pthread_mutex_init(&mutex,NULL);

	
	// Cria Threads
	pTempo = time(NULL);	
	for (int i=0; i<M_HEIGHT; i+=HEIGHT){
		for (int j=0; j<M_WIDTH; j+=WIDTH){
			// BlocoArgs; submatriz por thread
			
			k = numThreads;
			b[k].x = i;
			b[k].y = j;
			b[k].threadId = k;
			xPrev = b[k].x, yPrev = b[k].y;
			status = pthread_create(&threads[k],NULL,rotina,&b[k]);
			if (status){
				exit(-1);			
			}
			numThreads++;
			//cout << numThreads << " threads criadas ." << endl; 
		}
	}
	//cout << "Total de Threads: " << numThreads << endl;

	

	for (k=0; k<numThreads; k++){
		pthread_join(threads[k],NULL);
	}
	pTempo = time(NULL) - pTempo;
	cout << "[P]: A matriz possui " << contaPrimos << " números primos." << endl;

}



// Procedimento/Rotina, executado em cada Thread
void* rotina(void* args){
	
	BlocoArgs* b = (BlocoArgs*) args;
	unsigned sum = 0;
	unsigned x1 = (b->x) + HEIGHT;
	unsigned y1 = (b->y) + WIDTH;
	int status;
	//cout << "* " << b->threadId << " thread works" << endl;
	
	// Entrando na Área Crítica
	pthread_mutex_lock(&mutex); 
	// Acesso à memória compartilhada: matriz e contador
	sum += countPrime(b->x, x1, b->y, y1);
	contaPrimos += sum;
	// Saindo da Área Crítica
	pthread_mutex_unlock(&mutex);

	pthread_exit(NULL); // Encerra Thread
} 

