/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:40:59 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/05 15:20:38 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	ra(t_list **a, int i)
{
	if (!*a)
		return (1);
	if (ft_lstsize(*a) < 2)
		return (1);
	if (rotate(a) == -1)
		return (-1);
	if (i == 1)
		ft_putstr_fd("ra\n", 1);
	return (0);
}

int	rb(t_list **b, int i)
{
	if (rotate(b) == -1)
		return (-1);
	if (i == 1)
		ft_putstr_fd("rb\n", 1);
	return (0);
}

int	rr(t_list **a, t_list **b, int i)
{
	if ((ft_lstsize(*a) < 2) || (ft_lstsize(*b) < 2))
		return (-1);
	rotate(a);
	rotate(b);
	if (i == 1)
		ft_putstr_fd("rr\n", 1);
	return (0);
}
