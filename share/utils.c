/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:01:43 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/05 01:30:39 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (*(str + i) != 0)
		free(*(str + i++));
	free (str);
}

int	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->val > head->next->val)
			return (0);
		head = head->next;
	}
	return (1);
}

int	get_distance(t_list **stack, int index)
{
	t_list	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

int	find_max(t_list *stack)
{
	int		max;
	t_list	*tmp;

	tmp = stack->next;
	max = stack->index;
	while (tmp)
	{
		if (max < tmp->index)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

void	ft_lstprint(t_list	*lst)
{
	t_list	*node;

	node = lst;
	while (node != NULL)
	{
		printf("val: %d index: %d\n", node->val, node->index);
		node = node->next;
	}
}
