/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:54:52 by lde-frei          #+#    #+#             */
/*   Updated: 2026/01/15 18:41:42 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **stack)
{
	t_list	*tmp;
	int		swap;

	tmp = *stack;
	if (!*stack || !tmp->next)
		return ;
	swap = tmp->data;
	tmp->data = tmp->next->data;
	tmp->next->data = swap;
}

void	sb(t_list **stack)
{
	t_list	*tmp;
	int		swap;

	tmp = *stack;
	if (!*stack || !tmp->next)
		return ;
	swap = tmp->data;
	tmp->data = tmp->next->data;
	tmp->next->data = swap;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *stack_a;
	tmp2 = *stack_b;
	if ((!*stack_a || !*stack_a) && (!tmp1->next || !tmp2->next))
		return ;
	sa(stack_a);
	sb(stack_b);
}
