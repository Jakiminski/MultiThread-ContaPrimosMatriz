#ifndef _CNT_HPP_
#define _CNT_HPP_

	// Estrutura dos blocos/submatrizes
	typedef struct _BLOCO_ARGS_{
		int threadId; //ID da Thread
		unsigned x,y; // Índices linha e coluna iniciais do bloco
	}BlocoArgs;

	// Algoritmos para contagem de números primos
	void countPrime(unsigned x0, unsigned x1, unsigned y0, unsigned y1);
    void primeNumCountSerial(void);
    void primeNumCountParallel(void);

	// Rotina a ser executada em Thread(s)
	void* rotina(void* args);

#endif //_CNT_HPP_

