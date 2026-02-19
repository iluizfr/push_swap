/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:37:50 by lde-frei          #+#    #+#             */
/*   Updated: 2026/02/18 15:47:52 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_node
{
	int				pos;
	int				data;
	int				keep;
	int				index;
	int				cost_a;
	int				cost_b;
	int				target_pos;
	struct s_node	*next;
}					t_node;

// ==== * list functions * ==== //
void	creat_stack(t_node **stack, int argc, char **argv);
void	ft_lstadd_back(t_node **lst, t_node *new);
t_node	*ft_lstlast(t_node *lst);
int		ft_lstsize(t_node *lst);
t_node	*ft_lstnew(int num);

// ==== * Libft functions * ==== //
char	*ft_substr(const char *str, int start, int len);
int		ft_atoi(char *nptr, int *result);
void	sort_int_tab(int *tab, int len);
void	free_array(char **array);
char	**ft_split(char *str);
int		word_count(char *str);
int		is_digit(char c);
int		is_space(char c);
int		absolut(int x);

// ==== * Agorithm * ==== //
void	exec_double_rotate(t_node **stack_a, t_node **stack_b, t_node *node);
void	exec_rotations(t_node **stack_a, t_node **stack_b, t_node *node);
void	sort_stack(t_node **stack_a, t_node **stack_b);
void	set_targets(t_node *stack_a, t_node *stack_b);
void	calc_costs(t_node *stack_a, t_node *stack_b);
t_node	*find_target(t_node *stack_a, int b_index);
void	final_rotate(t_node **stack_a);
t_node	*find_min_node(t_node *stack);
void	clear_stack(t_node **stack);
int		is_ascending(t_node *stack);
void	print_stack(t_node *stack);
void	update_pos(t_node *stack);
void	set_lis(t_node *stack_a);
int		has_to_rm(t_node *stack);
t_node	*get_cheapest(t_node *b);
void	set_index(t_node *head);

// ==== * Operations * ==== //
void	rrr(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_b, t_node **stack_a);
void	ss(t_node **stack_a, t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);

#endif