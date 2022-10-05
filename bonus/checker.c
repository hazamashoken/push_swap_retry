/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:18:12 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/05 15:01:45 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"
#include	"push_swap_bonus.h"

static void	args_to_stack(t_list **stack, int argc, char **argv)
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

static void	exec_cmd(t_list **a, t_list **b, char *cmd)
{
	if (!ft_strncmp(cmd, "sa\n", 4))
		sa(a, 0);
	else if (!ft_strncmp(cmd, "sb\n", 4))
		sb(b, 0);
	else if (!ft_strncmp(cmd, "ss\n", 4))
		ss(a, b, 0);
	else if (!ft_strncmp(cmd, "pa\n", 4))
		pa(a, b, 0);
	else if (!ft_strncmp(cmd, "pb\n", 4))
		pb(a, b, 0);
	else if (!ft_strncmp(cmd, "ra\n", 4))
		ra(a, 0);
	else if (!ft_strncmp(cmd, "rb\n", 4))
		rb(b, 0);
	else if (!ft_strncmp(cmd, "rr\n", 4))
		rr(a, b, 0);
	else if (!ft_strncmp(cmd, "rra\n", 5))
		rra(a, 0);
	else if (!ft_strncmp(cmd, "rrb\n", 5))
		rrb(b, 0);
	else if (!ft_strncmp(cmd, "rrr\n", 5))
		rrr(a, b, 0);
	else
		error_free_exit("Error\n", a, b);
}

void	push_swap(t_list **a, t_list **b)
{
	char	*cmd;

	cmd = get_next_line(STDIN_FILENO);
	while (cmd)
	{
		exec_cmd(a, b, cmd);
		free(cmd);
		cmd = get_next_line(STDIN_FILENO);
	}
	free(cmd);
	if (is_sorted(a) && ft_lstsize(*b) == 0)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	if (argc == 1)
		return (0);
	check_args_bonus(argc, argv);
	a = (t_list **)malloc(sizeof(t_list));
	b = (t_list **)malloc(sizeof(t_list));
	*a = NULL;
	*b = NULL;
	args_to_stack(a, argc, argv);
	push_swap(a, b);
	ft_lstclear(a);
	ft_lstclear(b);
	return (0);
}
