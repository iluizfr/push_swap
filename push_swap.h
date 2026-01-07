/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:37:50 by lde-frei          #+#    #+#             */
/*   Updated: 2026/01/07 16:45:07 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_h
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
    int             num;
    struct s_list   *next;    
}                   t_list;


#endif