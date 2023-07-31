// #include "push_swap.h"
#include "libft/libft.h"

#include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>

int ft_atoi(const char *nptr)
{
	int num;

	num = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + *nptr - '0';
		nptr++;
	}
	if (!(*nptr >= '0' && *nptr <= '9') && *nptr != '\0')
		return (-1);
	return (num);
}

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
