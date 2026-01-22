/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:27:40 by lde-frei          #+#    #+#             */
/*   Updated: 2026/01/22 13:39:28 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		creat_stack(&stack_a, argc, argv);
		print_stack(stack_a);
		printf("*--------*\n");
		sort_stack(&stack_a, &stack_b);
		print_stack(stack_a);
		clear_stack(&stack_a);
	}
	return (0);
}
