/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:27:23 by lde-frei          #+#    #+#             */
/*   Updated: 2026/01/22 15:20:45 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_list **stack_dst, t_list **stack_src)
{
	t_list	*first;

	first = *stack_src;
	*stack_src = first->next;
	first->next = *stack_dst;
	*stack_dst = first;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_b) > 0)
	{
		push(stack_a, stack_b);
		write(1, "pa\n", 3);
	}
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	if (ft_lstsize(*stack_a) > 0)
	{
		push(stack_b, stack_a);
		write(1, "pb\n", 3);
	}
}
