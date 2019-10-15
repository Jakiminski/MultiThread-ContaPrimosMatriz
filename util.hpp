#ifndef _UTIL_HPP_
#define _UTIL_HPP_

	int isPrime(unsigned n); // Checa se um número é primo
    	int randRange(unsigned range, int min); // núm aleatório

	unsigned** newMatrix(void); // Aloca matriz com números aleatórios
    	void showMatrix(unsigned**mat); // Print para matrizes pequenas ou para depuração
    	int delMatrix (unsigned** mat); // Deleta matriz


#endif //_UTIL_HPP_
