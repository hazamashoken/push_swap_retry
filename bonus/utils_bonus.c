/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:39:29 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/05 14:24:20 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

void	error_free_exit(char *str, t_list **a, t_list **b)
{
	write(2, str, ft_strlen(str));
	ft_lstclear(a);
	ft_lstclear(b);
	exit(1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((*(s1 + i) || *(s2 + i)) && i < n)
	{
		if (*(s1 + i) != *(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}
