/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:32:52 by lde-frei          #+#    #+#             */
/*   Updated: 2026/01/07 16:44:50 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_digit(char c)
{
    return (c >= '0' || c <= '9');
}

int ft_atoi(const char *nptr)
{
    int i;
    int sin;
    int resul;

    i = 0;
    sin = 1;
    resul = 0;
    while(is_digit(nptr[i]))
        i++;
    if (nptr[i] == '+' || nptr[i] == '-')
    {
        if (nptr[i] == '-')
            sin = -1;
        i++;
    }
    while(is_digit(nptr[i]))
    {
        resul *= 10;
        resul += nptr[i] - '0';
        i++;
    }
    return (resul * sin);
}
