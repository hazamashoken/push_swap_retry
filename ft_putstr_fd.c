/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:35:18 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/04 12:36:31 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	ft_putstr_fd(char *str, int fd)
{
	if (fd < 0 || !str)
		return (0);
	return (write(fd, str, ft_strlen(str)));
}
