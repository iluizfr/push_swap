/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:32:52 by lde-frei          #+#    #+#             */
/*   Updated: 2026/01/13 17:34:23 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     verify_arg(char *arg)
{
    int i;

    i = 0;
    while (arg[i])
    {
        if(!is_digit(arg[i]) && !is_space(arg[i]) && arg[i] != '-' && arg[i] != '+')
            return (-1);
        else if((arg[i] == '+' || arg[i] == '-') && (!is_digit(arg[i + 1]) 
                 || is_digit(arg[i - 1])))
            return (-1);
        i++;
    }
    return (0);
}

void    check_stack(t_list *stack)
{
    t_list  *tmp;
    t_list  *next;

    tmp = stack;
    while (tmp->next)
    {
        next = tmp->next;
        while (next)
        {
            if (tmp->num == next->num)
            {
                clear_stack(&stack);
                write(2, "Error\n", 6);
                exit(EXIT_FAILURE);
            }
            next = next->next;
        }
        tmp = tmp->next;
    }
}

void    creat_stack(t_list **a, int argc, char **argv)
{
    char    **array;
    int     i;
    int     j;
    
    i = 1;
    while (i < argc)
    {
        if (verify_arg(argv[i]) < 0)
        {
            clear_stack(a);
            write(2, "Error\n", 6);
            exit(EXIT_FAILURE);
        }
        if (word_count(argv[i]) != 1)
        {
            j = 0;
            array = ft_split(argv[i++]);
            while (array[j])
                ft_lstadd_back(a, ft_lstnew(ft_atoi(array[j++])));
            free_array(array);
        }
        else
            ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i++])));
    }
    check_stack(*a);
}

void    print_stack(t_list *stack)
{
    t_list *tmp;

    tmp = stack;
    while (tmp)
    {
        printf("%d\n", tmp->num);
        tmp = tmp->next;
    }
}

void    clear_stack(t_list **stack)
{
    t_list *tmp;
    
    if (!stack)
        return ;
    while(*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        (*stack) = tmp;
    }
}
