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
pthread_mutex_t mutex, idx;
unsigned xPrev, yPrev;


void primeNumCountParallel(void){

    	contaPrimos = 0; // Reseta Contador

	pthread_t* threads = new pthread_t [MAX_THREADS];
	BlocoArgs* b = new BlocoArgs [MAX_THREADS];
	int numThreads = 0; // Conta Threads [0,MAX_THREADS]
	int status;
	// Threads, respectivas rotinas e o(s) Mutex(es)
	
	//Inicializa mutexes
	pthread_mutex_init(&mutex,NULL);
	pthread_mutex_init(&idx,NULL);
	
	// Cria Threads
	pTempo = time(NULL);
		
	for (int i=0; i<M_HEIGHT; i+=HEIGHT){
		for (int j=0; j<M_WIDTH; j+=WIDTH){
			// BlocoArgs; submatriz por thread
			
			b[numThreads].x = i;
			b[numThreads].y = j;
			b[numThreads].threadId = numThreads;
			
			xPrev = b[numThreads].x;
 			yPrev = b[numThreads].y;

			status = pthread_create(&threads[numThreads],NULL,rotina,&b[numThreads]);
			
			assert(!status);			
			
			numThreads++;
			cout << numThreads << " threads criadas ." << endl; 
		}
	}
	/**/
	//cout << "Total de Threads: " << numThreads << endl;

	

	for (int k=0; k<numThreads; k++){
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
	cout << "* " << b->threadId << " thread works" << endl;

	/**/
	while(TRUE){
		cout << "* " << b->threadId << " changed block" << endl;
		sum += countPrime(b->x, x1, b->y, y1);
		/**/
		// Situação crítica: Definir próximo bloco da matriz
		pthread_mutex_lock(&idx);
 		// Definir próximo bloco da matriz
		if (yPrev + WIDTH < M_WIDTH){
			b->y = yPrev + WIDTH;
			yPrev += WIDTH;
			pthread_mutex_unlock(&idx); // Desbloquear mutex idx

		}else if (xPrev + HEIGHT < M_HEIGHT){
			b->x = xPrev + HEIGHT;
			xPrev += HEIGHT; 
			b->y = 0;
			yPrev = 0;
			pthread_mutex_unlock(&idx); // Desbloquear mutex idx
				
		}else{
			pthread_mutex_unlock(&idx); // Desbloquear mutex idx
			break;

		}
		/**/
	}	
	/**/

	// Entrando na Área Crítica
	pthread_mutex_lock(&mutex); 
	// Acesso à memória compartilhada: matriz e contador
	
	contaPrimos += sum;
	// Saindo da Área Crítica
	pthread_mutex_unlock(&mutex);



	pthread_exit(NULL); // Encerra Thread
} 

