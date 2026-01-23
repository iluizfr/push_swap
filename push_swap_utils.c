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

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int		is_ascendig(t_list *stack)
{
	t_list *tmp;

	tmp = stack;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		is_descendig(t_list *stack)
{
	t_list *tmp;

	tmp = stack;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->data < tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	first_step(t_list **stack_a, t_list **stack_b)
{
	t_list	*bigger;

	bigger = ft_lstlast(*stack_a);
	while (!is_ascendig(*stack_a))
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
	}
}

void	second_step(t_list **stack_a, t_list **stack_b)
{
	t_list	*smaller;
	smaller = ft_lstlast(*stack_b);
	while (!is_descendig(*stack_b) && ft_lstsize(*stack_b) > 0)
	{
		if ((*stack_b)->data < smaller->data)
		{
			rb(stack_b);
			smaller = ft_lstlast(*stack_b);
		}
		else if ((*stack_b)->data > smaller->data && (*stack_b)->data < (*stack_b)->next->data)
			sb(stack_b);
		else if ((*stack_b)->data > smaller->data && (*stack_b)->data > (*stack_b)->next->data)
			pa(stack_a, stack_b);
		else if ((*stack_a)->data < smaller->data && (*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a);
	}
}

void	third_step(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_b) > 0)
	{
		pa(stack_a, stack_b);
	}	
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	while (!is_ascendig(*stack_a))
	{
		first_step(stack_a, stack_b);
		second_step(stack_a, stack_b);
		third_step(stack_a, stack_b);
	}
}
