/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:27:40 by lde-frei          #+#    #+#             */
/*   Updated: 2026/01/15 18:55:50 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	stack_a = NULL;
	if (argc > 1)
	{
		creat_stack(&stack_a, argc, argv);
		print_stack(stack_a);
		printf("--------\n");
		//sa(&stack_a);
		//print_stack(stack_a);
		//clear_stack(&stack_a);
	}
	return (0);
}
