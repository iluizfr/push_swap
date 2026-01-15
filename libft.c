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
    int sin;
    long resul;

    sin = 1;
    resul = 0;
    while(is_space(*nptr))
        nptr++;
    if (*nptr == '+' || *nptr == '-')
    {
        if (*nptr == '-')
            sin = -1;
        nptr++;
    }
    while(*nptr && is_digit(*nptr))
    {
        resul *= 10;
        resul += *nptr - '0';
        nptr++;
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
