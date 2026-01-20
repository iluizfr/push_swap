/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:14:06 by lde-frei          #+#    #+#             */
/*   Updated: 2026/01/20 17:15:57 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int num)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = num;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		size;

	size = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;
	t_list	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	ptr = tmp;
	ptr->next = new;
}

void	print_stack(t_list *stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	tmp = stack;
	while (tmp)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

void	clear_stack(t_list **stack)
{
	t_list	*tmp;

	if (!*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		(*stack) = tmp;
	}
}
