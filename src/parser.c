/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:50:53 by lde-frei          #+#    #+#             */
/*   Updated: 2026/01/20 17:13:56 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	verify_arg(char *arg)
{
	int	i;

	if (arg[0] == '\0')
		return (-1);
	i = 0;
	while (arg[i])
	{
		if (!is_digit(arg[i]) && !is_space(arg[i])
			&& arg[i] != '-' && arg[i] != '+')
			return (-1);
		else if ((arg[i] == '+' || arg[i] == '-') && (!is_digit(arg[i + 1])
				|| is_digit(arg[i - 1])))
			return (-1);
		i++;
	}
	return (0);
}

static void	free_on_error(t_node **stack, char **split)
{
	if (stack)
		clear_stack(stack);
	if (split)
		free_array(split);
	write(1, "Error\n", 6);
	exit(EXIT_SUCCESS);
}

static void	divide_args(t_node **stack, int i, char **argv)
{
	int		j;
	int		res;
	char	**array;

	j = 0;
	array = ft_split(argv[i]);
	while (array[j])
	{
		if (!ft_atoi(array[j], &res))
			free_on_error(NULL, array);
		ft_lstadd_back(stack, ft_lstnew(res));
		j++;
	}
	free_array(array);
}

static void	check_stack(t_node *stack)
{
	t_node	*tmp;
	t_node	*next;

	if (!stack)
		return ;
	tmp = stack;
	while (tmp->next)
	{
		next = tmp->next;
		while (next)
		{
			if (tmp->data == next->data)
				free_on_error(&stack, NULL);
			next = next->next;
		}
		tmp = tmp->next;
	}
}

void	creat_stack(t_node **stack, int argc, char **argv)
{
	int		i;
	int		res;

	i = 1;
	while (i < argc)
	{
		if (verify_arg(argv[i]) < 0)
			free_on_error(stack, NULL);
		else if (word_count(argv[i]) != 1)
			divide_args(stack, i, argv);
		else if (!ft_atoi(argv[i], &res))
			free_on_error(stack, NULL);
		else
			ft_lstadd_back(stack, ft_lstnew(res));
		i++;
	}
	check_stack(*stack);
}
