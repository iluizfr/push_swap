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
    int     i;
    int     j;
    t_list  *a;
    t_list  *tmp;
    int     flag;
    char    **array;

    i = 1;
    a = NULL;
    while(i < argc)
    {
        flag = verify_arg(argv[i]);
            if (flag < 0)
            {
                write(2, "Error\n", 6);
                return (1);
            }
        if (word_count(argv[i]) != 1)
        {
            j = 0;
            array = ft_split(argv[i]);
            while (array[j])
                ft_lstadd_back(&a, ft_lstnew(ft_atoi(array[j++])));
            i++;
            free_array(array);
        }
        ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i++])));
    }
    printl(a);
    while(a)
    {
        tmp = a->next;
        free(a);
        a = tmp;
    }
    return(0);
}