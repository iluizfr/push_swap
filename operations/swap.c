/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:54:52 by lde-frei          #+#    #+#             */
/*   Updated: 2026/01/20 15:59:34 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_node **stack_a)
{
	if (ft_lstsize(*stack_a) > 1)
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
}

void	sb(t_node **stack_b)
{
	if (ft_lstsize(*stack_b) > 1)
	{
		swap(stack_b);
		write(1, "sb\n", 3);
	}
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		swap(stack_a);
		swap(stack_b);
		write(1, "ss\n", 3);
	}
}
