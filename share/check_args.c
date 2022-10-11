/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:39:48 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/12 02:10:00 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	is_dupe(int needle, char **haystack, int i)
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

int	is_num(char *num)
{
	int	i;

	i = 0;
	if (*num == '\0')
		return (0);
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

char	**split_argv(char **argv)
{
	char	**res;
	char	**tmp;
	int		i;

	tmp = NULL;
	res = NULL;
	i = 0;
	while (*(argv + i))
	{
		*(argv + i) = ft_strtrim(*(argv + i), " ");
		tmp = ft_split(*(argv + i), ' ');
		if (res == NULL)
			res = tmp;
		else
			res = ft_strpjoin(res, tmp);
		i++;
	}
	return (res);
}

int	check_blank(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(*(argv + i)) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	check_args(int argc, char **argv)
{
	int		i;
	long	num;
	char	**args;

	i = 0;
	if (argc == 2)
		args = ft_split(*(argv + 1), ' ');
	else
	{
		if (check_blank(argv, argc))
			error_exit("Error here\n");
		i = 1;
		args = split_argv(argv);
	}
	while (*(args + i))
	{
		num = ft_atoi(*(args + i));
		if (!is_num(*(args + i)) || is_dupe(num, args, i))
			error_exit("Error\n");
		if (num < INT_MIN || num > INT_MAX)
			error_exit("Error\n");
		i++;
	}
	if (argc == 2)
		free_split(args);
}
