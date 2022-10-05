/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:41:18 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/05 14:43:15 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static int	push(t_list **to, t_list **from)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (ft_lstsize(*from) == 0)
		return (-1);
	head_to = *to;
	head_from = *from;
	tmp = head_from;
	head_from = head_from->next;
	*from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*to = tmp;
	}
	return (0);
}

int	pa(t_list **a, t_list **b, int i)
{
	if (push(a, b) == -1)
		return (-1);
	if (i == 1)
		ft_putstr_fd("pa\n", 1);
	return (0);
}

int	pb(t_list **a, t_list **b, int i)
{
	if (push(b, a) == -1)
		return (-1);
	if (i == 1)
		ft_putstr_fd("pb\n", 1);
	return (0);
}
