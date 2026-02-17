#include "../push_swap.h"

/**
 * @brief Computes the (LIS) at each index.
 * 
 * @param array The array who have all indexes of to be computed.
 * @param n Numbers of elements in the array.
 * @param len Array storing the Lis length at each index.
 * @param prev Array storing the previous index for (LIS) reconstruction.
*/
static void	compute_lis(int *array, int n, int *len, int *prev)
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

static int	find_lis_end(int *len, int n)
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
	free(len);
	return (index);
}

static void	clear_list_flag(t_node *stack_a)
{
	while (stack_a)
	{
		stack_a->keep = 0;
		stack_a = stack_a->next;
	}
}

static void	mark_lis(t_node *stack_a, int *prev, int lis_end)
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
	free(prev);
}

/**
 * @brief Longest increasing subsequence (LIS), indentifies and maks the nodes
 * 		  if they are in the lis. 
 * 
 * @param stack_a Pointer to the head of the linked list.
 * @note  This function converts the linked list into an integer array
 * 		  using each node's index value, finds where the (LIS) ends
 * 		  and mark them with stack_a->keep = 1;
*/
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
		array[i++] = tmp->index;
		tmp = tmp->next;
	}
	compute_lis(array, n, len, prev);
	lis_end = find_lis_end(len, n);
	clear_list_flag(stack_a);
	mark_lis(stack_a, prev, lis_end);
	free(array);
}
