/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:32:52 by lde-frei          #+#    #+#             */
/*   Updated: 2026/01/15 19:14:50 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verify_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!is_digit(arg[i]) && !is_space(arg[i])
			&& arg[i] != '-' && arg[i] != '+')
			return (-1);
		else if ((arg[i] == '+' || arg[i] == '-') && (!is_digit(arg[i + 1])
				|| is_digit(arg[i - 1])))
			return (-1);
		i++;
	}
	return (0);
}

void	check_stack(t_list *stack)
{
	t_list	*tmp;
	t_list	*next;

	tmp = stack;
	while (tmp->next)
	{
		next = tmp->next;
		while (next)
		{
			if (tmp->data == next->data)
				free_on_error(&stack, NULL);
			next = next->next;
		}
		tmp = tmp->next;
	}
}

void	print_stack(t_list *stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	tmp = stack;
	while (tmp)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

void	clear_stack(t_list **stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		(*stack) = tmp;
	}
}

void	free_on_error(t_list **stack, char **split)
{
	if (stack)
		clear_stack(stack);
	if (split)
		free_array(split);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}
