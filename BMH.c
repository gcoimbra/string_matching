//Referências: ZIVIANI, Nivio. Projeto de algoritmos com implementação em Pascal e C. 3ª Edição. 2010.
#include "main.h"

void BMH(ARGS)
{
	long i, j, k, displacement[MAX_ALPHABET_SIZE + 1];

	for (j = 0; j <= MAX_ALPHABET_SIZE; j++)
	{
		#ifdef TESTE
			*comparacoes += 1;
			*acessos_memoria += 1;
			*operacoes += 1;
		#endif
		displacement[j] = pattern_size;
	}

	for (j = 1; j < pattern_size; j++)
	{
		#ifdef TESTE
			*comparacoes += 1;
			*operacoes += 3;
			*acessos_memoria += 2;
		#endif
		displacement[pattern[j - 1]] = pattern_size - j;
	}

	i = pattern_size;

	while (i <= text_size)    // Pesquisa
	{
		#ifdef TESTE
			*comparacoes += 1; // while
		#endif

		k = i;
		j = pattern_size;

		while (text[k-1] == pattern[j-1] && j > 0)
		{
			#ifdef TESTE
				*comparacoes += 2;
				*acessos_memoria += 2;
				*operacoes += 4;
			#endif
			k--;
			j--;
		}

		if (j == 0)
		{
		      	#ifdef ANALISE
					printf("Casamento na posicao: %3ld\n", k + 1);
				#endif
		    	break;
		}

		i += displacement[text[i-1]];
		#ifdef TESTE
			*operacoes += 2;
			*acessos_memoria += 2;
		#endif
    }

}
