/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:37:50 by lde-frei          #+#    #+#             */
/*   Updated: 2026/01/20 15:57:37 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

// ==== * list functions * ==== //
void	creat_stack(t_list **stack, int argc, char **argv);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int num);

// ==== * Libft functions * ==== //
char	*ft_substr(const char *str, int start, int len);
void	free_array(char **array);
char	**ft_split(char *str);
int		word_count(char *str);
int		ft_atoi(char *nptr, int *result);
int		is_digit(char c);
int		is_space(char c);

// ==== * Utils * ==== //
void	clear_stack(t_list **stack);
void	print_stack(t_list *stack);

// ==== * Sorting * ==== //
void	rrr(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);

#endif