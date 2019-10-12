#ifndef _MCR_HPP_
#define _MCR_HPP_

	// PARAMETRIZAÇÃO
	#define M_SIZE (unsigned)9 // Tamanho da Matriz
    #define RND_RNG (unsigned)10 // Tamanho do intervalo de valores aleatórios
    #define RND_MIN (int)1 // Menor valor do intervalo
    

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

	
    

#endif //_MCR_HPP_