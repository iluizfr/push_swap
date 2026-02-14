/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:13:51 by lde-frei          #+#    #+#             */
/*   Updated: 2026/01/22 16:22:14 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_targets(t_node *stack_a, t_node *stack_b)
{
	t_node	*tmp_b;
	t_node	*target;

	tmp_b = stack_b;
	while (tmp_b)
	{
		target = find_target(stack_a, tmp_b->index);
		tmp_b->target_pos = target->pos;
		tmp_b = tmp_b->next;
	}
}

void	calc_costs(t_node *stack_a, t_node *stack_b)
{
	int		size_a;
	int		size_b;
	t_node	*tmp;

	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	tmp = stack_b;
	while (tmp)
	{
		if (tmp->pos <= size_b / 2)
			tmp->cost_b = tmp->pos;
		else
			tmp->cost_b = tmp->pos - size_b;
		if (tmp->target_pos <= size_a / 2)
			tmp->cost_a = tmp->target_pos;
		else
			tmp->cost_a = tmp->target_pos	 - size_a;
		tmp = tmp->next;
	}
}

t_node	*get_cheapest(t_node *b)
{
	int		min;
	int		cost;
	t_node	*cheap;

	cheap = b;
	min = ABS(b->cost_a) + ABS(b->cost_b);
	while (b)
	{
		cost = ABS(b->cost_a) + ABS(b->cost_b);
		if (cost < min)
		{
			min = cost;
			cheap = b;
		}
		b = b->next;
	}
	return (cheap);
}

void	exec_rotations(t_node **stack_a, t_node **stack_b, t_node *node)
{
	while (node->cost_a > 0 && node->cost_b > 0)
	{
		rr(stack_a, stack_b);
		node->cost_a--;
		node->cost_b--;
	}
	while (node->cost_a < 0 && node->cost_b < 0)
	{
		rrr(stack_a, stack_b);
		node->cost_a++;
		node->cost_b++;
	}
	while (node->cost_a > 0)
	{
		ra(stack_a);
		node->cost_a--;
	}
	while (node->cost_a < 0)
	{
		rra(stack_a);
		node->cost_a++;
	}
	while (node->cost_b > 0)
	{
		rb(stack_b);
		node->cost_b--;
	}
	while (node->cost_b < 0)
	{
		rrb(stack_b);
		node->cost_b++;
	}
}

void	final_rotate(t_node **stack_a)
{
	int		min_pos;
	t_node	*min_node;
	int		size;

	min_node = find_min_node(*stack_a);
	min_pos = min_node->pos;
	size = ft_lstsize(*stack_a);
	if (min_pos <= size / 2)
	{
		while (min_pos--)
			ra(stack_a);
	}
	else
	{
		min_pos = size - min_pos;
		while (min_pos--)
			rra(stack_a);
	}
}
