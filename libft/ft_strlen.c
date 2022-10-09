/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:55:24 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/09 21:21:56 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (*(unsigned char *)(s + len) != '\0')
		len++;
	return (len);
}

size_t	ft_strplen(char **s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (*(unsigned char **)(s + len) != 0)
		len++;
	return (len);
}
