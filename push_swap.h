/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:37:50 by lde-frei          #+#    #+#             */
/*   Updated: 2026/01/07 16:45:07 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
    int             num;
    struct s_list   *next;    
}                   t_list;

// list functions
void    ft_lstadd_back(t_list **lst, t_list *new);
int     ft_strcmp(char *s1, char *s2);
int     ft_lstsize(t_list *lst);
t_list  *ft_lstlast(t_list *lst);
t_list  *ft_lstnew(int num);

// Libft functions
int     ft_atoi(char *nptr);
void    free_array(char **array);
char    **ft_split(char *str);
int     word_count(char *str);
int     is_digit(char c);
int     is_space(char c);

// Personal functions
int     add_arg(t_list *stack, char *argv);
int     check_args(int argc, char **args);
int     verify_arg(char *arg);
void    printl(t_list *stack);

#endif