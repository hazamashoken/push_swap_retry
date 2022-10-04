/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:10:40 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/05 01:30:33 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->val = content;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_list **lst, t_list *node)
{
	t_list	*tmp;

	tmp = *lst;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node;
	}
	else
		*lst = node;
}

int	ft_lstsize(t_list *lst)
{
	size_t	size;
	t_list	*node;

	node = lst;
	size = 0;
	while (node != NULL)
	{
		node = node->next;
		size++;
	}
	return (size);
}

void	ft_lstclear(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	if (stack == NULL)
		return ;
	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	node = lst;
	while (node != NULL && node->next != NULL)
		node = node->next;
	return (node);
}
