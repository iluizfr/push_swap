/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:31:18 by lde-frei          #+#    #+#             */
/*   Updated: 2026/01/20 17:14:53 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*penult;
	t_list	*last;

	first = *stack;
	penult = *stack;
	while (penult->next->next != NULL)
		penult = penult->next;
	last = penult->next;
	last->next = first;
	penult->next = NULL;
	*stack = last;
}

void	rra(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) > 1)
	{
		reverse_rotate(stack_a);
		write(1, "rra\n", 4);
	}
}

void	rrb(t_list **stack_b)
{
	if (ft_lstsize(*stack_b) > 1)
	{
		reverse_rotate(stack_b);
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		write(1, "rrr\n", 4);
	}
}
