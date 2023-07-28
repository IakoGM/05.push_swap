#include "push_swap.h"
#include "libft/libft.h"

#include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>

int ft_iako(const char *nptr)
{
	int num;
	int sign;

	num = 0;
	sign = 1;
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + *nptr - '0';
		nptr++;
	}
	if (*nptr > '9')
		return (-1);
	return (num);
}

int main(int argc, char const *argv[])
{
	int i;
	// int	cast;

	i = 1;
	while (argc > i)
	{
		if (ft_iako(argv[i]) == -1)
			printf("El argumento %d, contiene el dato = %s\n", i, argv[i]);
		else
			printf("El argumento %d, contiene el numero = %s\n", i, argv[i]);
		i++;
	}
	return 0;
}
