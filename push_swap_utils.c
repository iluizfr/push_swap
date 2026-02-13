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

#include "push_swap.h"

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
	t_node	*tmp;

	if (!stack)
		return ;
	tmp = stack;
	while (tmp)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
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

void	idex(t_node *head)
{
	int		i;
	int		j;
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
	tmp = head;
	while (tmp)
	{
		j = 0;
		while (j < len)
		{
			if (tmp->data == vetor[j])
			{
				tmp->index = j;
				break;
			}
			j++;
		}
		tmp = tmp->next;
	}
	free(vetor);
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
