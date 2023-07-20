#include "main.h"

void shiftAnd(ARGS)
{
	unsigned long resultado, mascara[CHAR_MAX + 1];

	if (pattern_size > 31 || pattern_size == 0)
	{
		fprintf(stderr, "Padrão %s, inválidoz!\n", pattern);
		return;
	}

	resultado = ~1UL;

	for (size_t i = 0; i <= CHAR_MAX; i++)
	{
		#ifdef TESTE
			*comparacoes += 1;
			*acessos_memoria += 1;
			*operacoes += 1;
		#endif
		mascara[i] =  0UL;
	}

	for (size_t i = 0; i < pattern_size; i++)
	{
		#ifdef TESTE
			*comparacoes += 1;
			*acessos_memoria += 2;
			*operacoes += 4;
		#endif
		mascara[pattern[i]] &= ~(1UL << i);
	}

	for (size_t i = 0; text[i] != '\0'; i++)
	{
		resultado |= mascara[text[i]];
		resultado <<= 1;

		#ifdef TESTE
			*acessos_memoria += 3;
			*operacoes += 5;
			*comparacoes += 2;
		#endif

		if (0 == (resultado & (1UL << pattern_size)))
			return;
//			return (text + i - pattern_size) + 1;
	}

}