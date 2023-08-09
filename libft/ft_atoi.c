/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:10:11 by jakgonza          #+#    #+#             */
/*   Updated: 2023/08/09 13:52:45 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + *nptr - '0';
		nptr++;
	}
	if (*nptr != (*nptr <= '9' && *nptr >= '0') || (*nptr != '\0'))
		return (num * sign);
	return (num * sign);
}
