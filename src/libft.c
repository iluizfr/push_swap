/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:21:22 by lde-frei          #+#    #+#             */
/*   Updated: 2026/02/18 15:00:21 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	ft_atoi(char *nptr, int *result)
{
	int		sin;
	long	res;

	sin = 1;
	res = 0;
	while (is_space(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sin = -1;
		nptr++;
	}
	while (*nptr && is_digit(*nptr))
	{
		res *= 10;
		res += *nptr - '0';
		nptr++;
		if ((res * sin) > MAX_INT || (res * sin) < MIN_INT)
			return (0);
	}
	return (*result = res * sin, 1);
}

char	*ft_substr(const char *str, int start, int len)
{
	char	*sub;
	char	*ptr;
	int		slen;

	if (!str)
		return (NULL);
	slen = 0;
	while (str[slen])
		slen++;
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

void	sort_int_tab(int *tab, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = i;
		while (j < len)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
