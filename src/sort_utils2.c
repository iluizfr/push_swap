#include "../push_swap.h"

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

/**
 * @brief Looks in stack_a the smaller index bigger than b_index.
 * 
*/
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

void	update_pos(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i++;
		stack = stack->next;
	}
}

void	exec_double_rotate(t_node **stack_a, t_node **stack_b, t_node *node)
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
}
