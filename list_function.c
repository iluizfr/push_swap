/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:14:06 by lde-frei          #+#    #+#             */
/*   Updated: 2026/01/15 19:13:31 by lde-frei         ###   ########.fr       */
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
	int		len;

	len = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr = ft_lstlast(*lst);
	ptr->next = new;
}

void	creat_stack(t_list **stack, int argc, char **argv)
{
	int		i;
	int		j;
	int		res;
	char	**array;

	i = 1;
	while (i < argc)
	{
		if (verify_arg(argv[i]) < 0)
			free_on_error(stack, NULL);
		if (word_count(argv[i]) != 1)
		{
			j = 0;
			array = ft_split(argv[i++]);
			while (array[j])
			{
				if (!ft_atoi(array[j++], &res))
					free_on_error(NULL, array);
				ft_lstadd_back(stack, ft_lstnew(res));
			}
			free_array(array);
		}
		else if (!ft_atoi(argv[i++], &res))
			free_on_error(stack, NULL);
		else
			ft_lstadd_back(stack, ft_lstnew(res));
	}
	check_stack(*stack);
}
