#include "../push_swap.h"

void	sort_2(t_node **stack)
{
	if (!is_ascending(*stack))
			sa(stack);
}

void	sort_3(t_node **stack)
{
	t_node	*bigger;

	bigger = ft_lstlast(*stack);
	while (!is_ascending(*stack))
	{
		if ((*stack)->data > bigger->data)
		{
			ra(stack);
			bigger = ft_lstlast(*stack);
		}
		else if ((*stack)->data > (*stack)->next->data)
			sa(stack);
		else
		{
			ra(stack);
			bigger = ft_lstlast(*stack);
		}

	}
}

void	sort_5(t_node **stack_a, t_node **stack_b)
{
	t_node	*bigger;

	bigger = ft_lstlast(*stack_a);
	while (!is_ascending(*stack_a))
	{
		while (!is_ascending(*stack_a))
		{
			if ((*stack_a)->data > bigger->data)
			{
				ra(stack_a);
				bigger = ft_lstlast(*stack_a);
			}
			else if ((*stack_a)->data < bigger->data && (*stack_a)->data > (*stack_a)->next->data)
				sa(stack_a);
			else if ((*stack_a)->data < bigger->data && (*stack_a)->data < (*stack_a)->next->data)
				pb(stack_b, stack_a);
			else if ((*stack_a)->data > (*stack_a)->next->data)
				sa(stack_a);
		}
		while (ft_lstsize(*stack_b) > 0)
			pa(stack_a, stack_b);
	}
}

void	sort(t_node **stack_a, t_node**stack_b)
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
