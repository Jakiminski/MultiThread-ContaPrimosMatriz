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
	/*
	*	Exemplos simples:
	*	Matriz 5x5 e blocos 1x1
	*	Matriz 9x4 e blocos 3x2
	*	Matriz 9x9 e blocos 9x3
	*	Matriz 40x10 e blocos 5x2
	*	Matriz 32x32 e blocos 8x8
	*	Matriz 160x16 e blocos 4x4
	*	Matriz 400x400 e blocos 2x4
	*	
	* Sugestão: Usar matrizes com dimensões que sejam múltiplas das escolhas acima.
	*/
	
	// MATRIZ
	#define M_HEIGHT (unsigned) 50 // Altura da Matriz
	#define M_WIDTH (unsigned) 18 // Largura da Matriz
    	#define PRINT FALSE // Printar a matriz? TRUE:FALSE
	
	// BLOCOS DA MATRIZ (Threads)
	// (x e y estão trocados no plano cartesiano)
	//Obs: M_SIZE deve ser divisivel por HEIGHT e WIDTH
	#define HEIGHT (unsigned) 2 // Altura 
	#define WIDTH (unsigned) 3 // Largura

	// NÚMEROS ALEATÓRIOS
	#define RND_RNG (unsigned) 10 // Tamanho do intervalo de valores aleatórios
    #define RND_MIN (int) 1 // Menor valor do intervalo
	
#endif //_MCR_HPP_
