/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_func_too_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:03:59 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/04 13:05:14 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ra_sa_rra(t_list **stack)
{
	ra(stack);
	sa(stack);
	rra(stack);
}

void	sa_rra(t_list **stack)
{
	sa(stack);
	rra(stack);
}
