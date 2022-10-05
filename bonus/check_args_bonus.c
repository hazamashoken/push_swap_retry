/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:39:48 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/05 14:58:09 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

static int	is_dupe(int needle, char **haystack, int i)
{
	i++;
	while (*(haystack + i))
	{
		if (ft_atoi(*(haystack + i)) == needle)
			return (1);
		i++;
	}
	return (0);
}

static int	is_num(char *num)
{
	int	i;

	i = 0;
	if (*num == '-' && ft_strlen(num) > 1)
		i++;
	while (*(num + i))
	{
		if (!ft_isdigit(*(num + i)))
			return (0);
		i++;
	}
	return (1);
}

void	check_args_bonus(int argc, char **argv)
{
	int		i;
	long	num;
	char	**args;

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
		num = ft_atoi(*(args + i));
		if (!is_num(*(args + i)))
			error_exit("Error\n");
		if (is_dupe(num, args, i))
			error_exit("Error\n");
		if (num < INT_MIN || num > INT_MAX)
			error_exit("Error\n");
		i++;
	}
	if (argc == 2)
		free_split(args);
}
