// #include "push_swap.h"
#include "libft/libft.h"

#include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>

int main(int argc, char const *argv[])
{
	int i;

	i = 1;
	while (argc > i)
	{
		if (ft_atoi(argv[i]) == -1)
			printf("El argumento %d, contiene el dato = %s\n", i, argv[i]);
		else
			printf("El argumento %d, contiene el numero = %s\n", i, argv[i]);
		i++;
	}
	return 0;
}
