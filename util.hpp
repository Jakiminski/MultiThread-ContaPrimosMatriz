#ifndef _UTIL_HPP_
#define _UTIL_HPP_
    
	int isPrimo(unsigned n); // Checa se um número é primo
    int rand_Range(unsigned range, int min); // núm aleatório
	
    unsigned** newMatrix(unsigned tam); // Aloca matriz com números aleatórios
    void showMatrix(unsigned**mat); //Imprime a matriz
    int delMatrix (unsigned** mat); // Deleta matriz


#endif //_UTIL_HPP_