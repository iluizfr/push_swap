/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:27:40 by lde-frei          #+#    #+#             */
/*   Updated: 2026/01/07 16:55:08 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *a;
    t_list *b;
    
    argc = 1;
    while(argc)
    {
        a = ft_atoi(argv[argc]);
        argv++;
    }
    return(0);
}