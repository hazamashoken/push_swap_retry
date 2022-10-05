/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:39:14 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/05 16:13:42 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static int	find_biggest_front(t_list **b)
{
	int		i;
	t_list	*tmp;
	int		max;

	i = 0;
	tmp = *b;
	max = find_max(*b);
	while (tmp->index < max)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static int	find_biggest_back(t_list **b)
{
	int		i;
	int		j;
	t_list	*tmp;
	int		max;

	i = 0;
	j = 0;
	tmp = *b;
	max = find_max(*b);
	while (i <= (ft_lstsize(*b) - 1))
	{
		if (tmp->index >= max)
			j = i;
		tmp = tmp->next;
		i++;
	}
	return (i - j);
}

static void	move_to_a(t_list **a, t_list **b)
{
	int	hold_first;
	int	hold_second;

	while (ft_lstsize(*b) > 0)
	{
		hold_first = find_biggest_front(b);
		hold_second = find_biggest_back(b);
		if (hold_first <= hold_second)
		{
			while (hold_first-- > 0)
				rb(b, 1);
			pa(a, b, 1);
		}
		else
		{
			while (hold_second-- > 0)
				rrb(b, 1);
			pa(a, b, 1);
		}
	}
}

void	insertion_sort(t_list **a, t_list **b, int chunk_count)
{
	int	chunk;
	int	last_chunk;
	int	i;

	i = 1;
	last_chunk = 0;
	chunk = ft_lstsize(*a) / chunk_count;
	last_chunk = chunk + ft_lstsize(*a) - (chunk * chunk_count);
	while (i <= chunk_count - 1)
	{
		move_to_b(a, b, chunk, chunk * i);
		i++;
	}
	move_to_b(a, b, last_chunk, chunk * (i - 1) + last_chunk);
	move_to_a(a, b);
}
