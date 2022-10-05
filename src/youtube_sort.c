/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   youtube_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:27:34 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/05 15:09:32 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static int	try_push_next(t_list **a, t_list **b, int swap)
{
	if ((*b)->index == ft_lstsize(*b) - 2 && !swap)
	{
		pa(a, b, 1);
		return (1);
	}
	return (0);
}

static int	smart_rotate_b(t_list **a, t_list **b)
{
	int		cnt;
	int		swap;
	int		sz;
	t_list	*tmpb;

	cnt = 0;
	swap = 0;
	sz = ft_lstsize(*b);
	tmpb = *b;
	while (tmpb->index != sz - 1 && ++cnt)
		tmpb = tmpb->next;
	while ((*b)->index != sz - 1)
	{
		if (!try_push_next(a, b, swap))
		{
			if (cnt > sz / 2)
				rrb(b, 1);
			else
				rb(b, 1);
		}
		else
			swap = 1;
	}
	return (swap);
}

static void	push_in_chunks(t_list **a, t_list **b, int chunk_sz)
{
	int	chunk_n;
	int	cnt;

	chunk_n = 1;
	cnt = 0;
	while (ft_lstsize(*a))
	{
		if ((*a)->index < (chunk_sz * chunk_n))
		{
			pb(a, b, 1);
			if ((*b)->index
				< chunk_sz * chunk_n - (chunk_sz / 2))
				rb(b, 1);
			cnt++;
		}
		else
			ra(a, 1);
		if (cnt == chunk_sz * chunk_n)
			chunk_n++;
	}
}

static void	push_back_in_order(t_list **a, t_list **b)
{
	while (ft_lstsize(*b))
	{
		if (smart_rotate_b(a, b))
		{
			pa(a, b, 1);
			if (ft_lstsize(*b) > 1
				&& (*b)->index < (*b)->next->index)
				ss(a, b, 1);
			else
				sa(a, 1);
		}
		else
			pa(a, b, 1);
	}
}

void	sort_big(t_list **a, t_list **b)
{
	int	chunk_sz;

	chunk_sz = ft_lstsize(*a) / STACK_COUNT + 22;
	push_in_chunks(a, b, chunk_sz);
	push_back_in_order(a, b);
}
