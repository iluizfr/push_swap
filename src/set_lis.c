#include "../push_swap.h"

void	compute_lis(int *array, int n, int *len, int *prev)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		len[i] = 1;
		prev[i] = -1;
		i++;
	}
	i = 1;
	while (i < n)
	{
		j = 0;
		while (j < i)
		{
			if (array[j] < array[i] && len[j] + 1 > len[i])
			{
				len[i] = len[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

int	find_lis_end(int *len, int n)
{
	int	i;
	int	max;
	int	index;

	i = 0;
	max = 0;
	index = 0;
	while (i < n)
	{
		if (len[i] > max)
		{
			max = len[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	clear_list_flag(t_node *stack_a)
{
	while (stack_a)
	{
		stack_a->keep = 0;
		stack_a = stack_a->next;
	}
}

void	mark_lis(t_node *stack_a, int *prev, int lis_end)
{
	int		i;
	t_node	*tmp;

	while (lis_end != -1)
	{
		tmp = stack_a;
		i = 0;
		while (i < lis_end)
		{
			tmp = tmp->next;
			i++;
		}
		tmp->keep = 1;
		lis_end = prev[lis_end];
	}
}

void	set_lis(t_node *stack_a)
{
	int		i;
	int		n;
	int		*len;
	int		*prev;
	int		*array;
	int		lis_end;
	t_node	*tmp;

	i = 0;
	tmp = stack_a;
	n = ft_lstsize(stack_a);
	array = malloc(sizeof(int) * n);
	len = malloc(sizeof(int) * n);
	prev = malloc(sizeof(int) * n);
	while (tmp)
	{
		array[i] = tmp->index;
		tmp = tmp->next;
		i++;
	}
	compute_lis(array, n, len, prev);
	lis_end = find_lis_end(len, n);
	clear_list_flag(stack_a);
	mark_lis(stack_a, prev, lis_end);
	free(array);
	free(len);
	free(prev);
}
