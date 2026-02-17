/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:32:52 by lde-frei          #+#    #+#             */
/*   Updated: 2026/01/23 18:14:20 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	mark_index(t_node *head, int *vetor, int len)
{
	int i;

	while (head)
	{
		i = 0;
		while (i < len)
		{
			if (head->data == vetor[i])
			{
				head->index = i;
				break;
			}
			i++;
		}
		head = head->next;
	}
}

void	set_index(t_node *head)	
{
	int		i;
	int		len;
	int		*vetor;
	t_node	*tmp;

	len = ft_lstsize(head);
	vetor = malloc(sizeof(int) * len);
	tmp = head;
	i = 0;
	while (tmp)
	{
		vetor[i++] = tmp->data;
		tmp = tmp->next;
	}
	sort_int_tab(vetor, len);
	mark_index(head, vetor, len);
	free(vetor);
}

int		is_ascending(t_node *stack)
{
	t_node *tmp;

	tmp = stack;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("%d\n", stack->data);
		stack = stack->next;
	}
}

void	clear_stack(t_node **stack)
{
	t_node	*tmp;

	if (!*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		(*stack) = tmp;
	}
}
