/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ha_and_below.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:49:47 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/05 14:45:37 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static int	get_min(t_list **stack, int val)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && (head->index != val))
			min = head->index;
	}
	return (min);
}

void	sort_sam(t_list **a)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *a;
	min = get_min(a, -1);
	next_min = get_min(a, min);
	if (is_sorted(a))
		return ;
	if (head->index == min && head->next->index != next_min)
		ra_sa_rra(a);
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			sa(a, 1);
		else
			rra(a, 1);
	}
	else
	{
		if (head->next->index == min)
			ra(a, 1);
		else
			sa_rra(a);
	}
}

static void	sort_see(t_list **a, t_list **b)
{
	int	distance;

	if (is_sorted(a))
		return ;
	distance = get_distance(a, get_min(a, -1));
	if (distance == 1)
		ra(a, 1);
	else if (distance == 2)
	{
		ra(a, 1);
		ra(a, 1);
	}
	else if (distance == 3)
		rra(a, 1);
	if (is_sorted(a))
		return ;
	pb(a, b, 1);
	sort_sam(a);
	pa(a, b, 1);
}

void	sort_ha(t_list **a, t_list **b)
{
	int	distance;

	distance = get_distance(a, get_min(a, -1));
	if (distance == 1)
		ra(a, 1);
	else if (distance == 2)
	{
		ra(a, 1);
		ra(a, 1);
	}
	else if (distance == 3)
	{
		rra(a, 1);
		rra(a, 1);
	}
	else if (distance == 4)
		rra(a, 1);
	if (is_sorted(a))
		return ;
	pb(a, b, 1);
	sort_see(a, b);
	pa(a, b, 1);
}

void	sort_ha_and_below(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (is_sorted(a) || size == 0 || size == 1)
		return ;
	if (size == 2)
		sa(a, 1);
	else if (size == 3)
		sort_sam(a);
	else if (size == 4)
		sort_see(a, b);
	else if (size == 5)
		sort_ha(a, b);
}
