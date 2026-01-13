/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:37:50 by lde-frei          #+#    #+#             */
/*   Updated: 2026/01/13 18:46:05 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_INT 2147483647
#define MIN_INT -2147483648

typedef struct s_list
{
    int             num;
    struct s_list   *next;
}                   t_list;

// list functions
void    creat_stack(t_list **a, int argc, char **argv);
void    ft_lstadd_back(t_list **lst, t_list *new);
t_list  *ft_lstlast(t_list *lst);
int     ft_lstsize(t_list *lst);
t_list  *ft_lstnew(int num);

// Libft functions
char    *ft_substr(const char *str, int start, int len);
int     ft_strcmp(char *s1, char *s2);
void    free_array(char **array);
char    **ft_split(char *str);
int     word_count(char *str);
int     ft_atoi(char *nptr);
int     is_digit(char c);
int     is_space(char c);

// Personal functions
int     add_arg(t_list *stack, char *argv);
int     check_args(int argc, char **args);
void    clear_stack(t_list **stack);
void    check_stack(t_list *stack);
void    print_stack(t_list *stack);
int     verify_arg(char *arg);

#endif