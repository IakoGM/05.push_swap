/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:40:16 by jakgonza          #+#    #+#             */
/*   Updated: 2022/09/13 22:50:49 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	countdigits(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*intmin(void)
{
	char	*str;

	str = (char *) malloc(12 * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, "-2147483648", 12);
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*num;

	if (n == -2147483648)
		return (intmin());
	i = countdigits(n);
	num = (char *) malloc((i + 1) * sizeof(char));
	if (!num)
		return (NULL);
	if (n == 0)
		num[0] = 48;
	num[i] = '\0';
	i -= 1;
	if (n < 0)
	{
		num[0] = 45;
		n *= -1;
	}
	while (n > 0)
	{
		num[i] = '0' + n % 10;
		n = n / 10;
		i--;
	}
	return (num);
}
