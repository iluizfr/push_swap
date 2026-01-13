/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:21:22 by lde-frei          #+#    #+#             */
/*   Updated: 2026/01/13 18:48:46 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int     is_space(char c)
{
    return(c == 32 || (c >= 9 && c <= 13));
}

int     ft_atoi(char *nptr)
{
    int i;
    int sin;
    long resul;

    i = 0;
    sin = 1;
    resul = 0;
    while(is_space(nptr[i]))
        i++;
    if (nptr[i] == '+' || nptr[i] == '-')
    {
        if (nptr[i] == '-')
            sin = -1;
        i++;
    }
    while(nptr[i] && is_digit(nptr[i]))
    {
        resul *= 10;
        resul += nptr[i] - '0';
        i++;
        if ((resul * sin) > MAX_INT || (resul * sin) < MIN_INT)
        {
            write(2, "Error\n", 6);
            exit(EXIT_FAILURE);
        }
    }
    return (resul * sin);
}

char    *ft_substr(const char *str, int start, int len)
{
	char	*sub;
	char	*ptr;
	int     slen;

	if (!str)
		return (NULL);
	slen = 0;
    while(str[slen])
    {
        slen++;
    }
	if (start >= slen)
		return (malloc(0));
	if (len > slen - start)
		len = slen - start;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	ptr = sub;
	str += start;
	while (len--)
		*sub++ = *str++;
	*sub = '\0';
	return (ptr);    
}
