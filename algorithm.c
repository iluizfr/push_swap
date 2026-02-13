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

#include "push_swap.h"

t_node *find_min_node(t_node *stack)
{
	t_node	*tmp;
	t_node	*min_node;

	if (!stack)
		return (NULL);
	tmp = stack;
	min_node = stack;
	while (tmp)
	{
		if (tmp->index < min_node->index)
			min_node = tmp;
		tmp = tmp->next;
	}
	return (min_node);
}

t_node *find_target(t_node *stack_a, int b_index)
{
	t_node	*tmp;
	t_node	*best;
	int		diff;

	best = NULL;
	diff = MAX_INT;
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->index > b_index && tmp->index - b_index < diff)
		{
			diff = tmp->index - b_index;
			best = tmp;
		}
		tmp = tmp->next;
	}
	if (best)
		return (best);
	return (find_min_node(stack_a));
}

int has_to_rm(t_node *stack)
{
	while (stack)
	{
		if (stack->keep == 0)
			return (1);
		stack = stack->next;
	}
	return (0);
}

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

int	sort(t_node **stack_a, t_node**stack_b)
{
	t_node	*cheap;

	idex(*stack_a);
	set_lis(*stack_a);
	while (has_to_rm(*stack_a))
	{
		if ((*stack_a)->keep == 0)
			pb(stack_b, stack_a);
		else
			ra(stack_a);	
	}
	while (ft_lstsize(*stack_b) > 0)
	{
		update_pos(*stack_a);
		update_pos(*stack_b);
		set_targets(*stack_a, *stack_b);
		calc_costs(*stack_a, *stack_b);
		cheap = get_cheapest(*stack_b);
		exec_rotations(stack_a, stack_b, cheap);
		pa(stack_a, stack_b);
	}
	update_pos(*stack_a);
	final_rotate(stack_a);
	return (0);
}

void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		sort_2(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size > 3 && size < 6)
		sort_5(stack_a, stack_b);
	else
	{
		if (!is_ascending(*stack_a))
			sort(stack_a, stack_b);
	}
}
