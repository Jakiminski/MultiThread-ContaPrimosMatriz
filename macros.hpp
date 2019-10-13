#ifndef _MCR_HPP_
#define _MCR_HPP_


    // Boolean
    #ifdef TRUE
	#undef TRUE
	#endif// TRUE undef
	#ifndef TRUE
	#define TRUE 1
	#endif // TRUE def
	#ifdef FALSE
	#undef FALSE
	#endif// FALSE undef
	#ifndef FALSE
	#define FALSE 0
	#endif // FALSE def

	// PARAMETRIZAÇÃO
	
	// MATRIZ
	#define M_SIZE (unsigned) 10 // Tamanho da Matriz
    #define PRINT FALSE // Printar a matriz? TRUE:FALSE
	
	// NÚMEROS ALEATÓRIOS
	#define RND_RNG (unsigned) 10 // Tamanho do intervalo de valores aleatórios
    #define RND_MIN (int) 1 // Menor valor do intervalo
	
	// BLOCOS DA MATRIZ (Threads)
	//Obs: M_SIZE deve ser divisivel por HEIGHT e WIDTH
	#define HEIGHT (unsigned) 2 // Altura
	#define WIDTH (unsigned) 2 // Largura


#endif //_MCR_HPP_
