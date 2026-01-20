/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:24:49 by lde-frei          #+#    #+#             */
/*   Updated: 2026/01/20 17:14:34 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*first;

	first = *stack;
	*stack = first->next;
	ft_lstadd_back(stack, first);
	first->next = NULL;
}

void	ra(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) > 1)
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
}

void	rb(t_list **stack_b)
{
	if (ft_lstsize(*stack_b) > 1)
	{
		rotate(stack_b);
		write(1, "rb\n", 3);
	}
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		rotate(stack_a);
		rotate(stack_a);
		write(1, "rr\n", 3);
	}
}
