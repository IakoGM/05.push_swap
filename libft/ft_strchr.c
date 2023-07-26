/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:31:32 by jakgonza          #+#    #+#             */
/*   Updated: 2022/12/04 17:17:26 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
    char	a;

    a = c;
    while (*s)
    {
        if (*s == a)
            return ((char *)s);
        s++;
    }
    if (a == '\0')
        return ((char *)s);
    return (NULL);
}
