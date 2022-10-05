/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 01:28:32 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/05 14:42:20 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static int	find_pos_front(t_list **a, int limit)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *a;
	while (tmp->index >= limit)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static int	find_pos_back(t_list **a, int limit)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = 0;
	j = 0;
	tmp = *a;
	while (i <= (ft_lstsize(*a) - 1))
	{
		if (tmp->index >= limit)
			j = i;
		tmp = tmp->next;
		i++;
	}
	return (j);
}

void	move_to_b(t_list **a, t_list **b, int chunk, int limit)
{
	int	hold_first;
	int	hold_second;
	int	i;

	i = 1;
	while (i <= chunk)
	{
		hold_first = find_pos_front(a, limit);
		hold_second = find_pos_back(a, limit);
		if (hold_first <= hold_second)
		{
			while (hold_first-- > 0)
				ra(a, 1);
			pb(a, b, 1);
		}
		else
		{
			while (hold_second-- >= 0)
				rra(a, 1);
			pb(a, b, 1);
		}
		i++;
	}
}
