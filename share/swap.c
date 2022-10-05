/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:41:34 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/05 14:44:25 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static int	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		error_exit("Error occured while swapping!");
	tmp_val = head->val;
	tmp_index = head->index;
	head->val = next->val;
	head->index = next->index;
	next->val = tmp_val;
	next->index = tmp_index;
	return (0);
}

int	sa(t_list **a, int i)
{
	if (swap(a) == -1)
		return (-1);
	if (i == 1)
		ft_putstr_fd("sa\n", 1);
	return (0);
}

int	sb(t_list **b, int i)
{
	if (swap(b) == -1)
		return (-1);
	if (i == 1)
		ft_putstr_fd("sb\n", 1);
	return (0);
}

int	ss(t_list **a, t_list **b, int i)
{
	if ((ft_lstsize(*a) < 2) || (ft_lstsize(*b) < 2))
		return (-1);
	swap(a);
	swap(b);
	if (i == 1)
		ft_putstr_fd("ss\n", 1);
	return (0);
}
