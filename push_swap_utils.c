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
    int resul;

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
    }
    return (resul * sin);
}

int     verify_arg(char *arg)
{
    int i;

    i = 0;
    while (arg[i])
    {
        if(!is_digit(arg[i]) && !is_space(arg[i]) && arg[i] != '-' && arg[i] != '+')
            return (-1);
        else if((arg[i] == '+' || arg[i] == '-') && !is_digit(arg[i + 1]))
            return (-1);
        i++;
    }
    return (0);
}

void    printl(t_list *stack)
{
    t_list *tmp;

    tmp = stack;
    while (tmp)
    {
        printf(" %d\n", tmp->num);
        tmp = tmp->next;
    }
}