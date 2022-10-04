/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:32:08 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/05 01:30:52 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	args_to_stack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(*(argv + 1), ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (*(args + i))
	{
		new = ft_lstnew(ft_atoi(*(args + i)));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		free_split(args);
}

void	sort_the_fucking_stack(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size <= 5)
		sort_ha_and_below(a, b);
	else if (size <= 400)
		insertion_sort(a, b, 5);
	else
		the_god_damn_radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	if (argc < 2)
		return (-1);
	check_args(argc, argv);
	a = (t_list **)malloc(sizeof(t_list));
	b = (t_list **)malloc(sizeof(t_list));
	*a = NULL;
	*b = NULL;
	args_to_stack(a, argc, argv);
	if (is_sorted(a))
	{
		ft_lstclear(a);
		ft_lstclear(b);
		return (0);
	}
	sort_the_fucking_stack(a, b);
	ft_lstclear(a);
	ft_lstclear(b);
	return (0);
}
