/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:46:55 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/12 11:10:52 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PARAMETERS
//     s1: The prefix string.
//     s2: The suffix string.

// DESCRIPTION
//    Allocates (with malloc(3)) and returns a new
//    string, which is the result of the concatenation
//    of ’s1’ and ’s2’.

// RETURN VALUE
//    The new string.
//    NULL if the allocation fails.

#include	"push_swap.h"

static void	sfree_split(char **str)
{
	int	i;

	i = 0;
	while (*(str + i) != 0)
		free(*(str + i++));
	free (str);
}

char	**ft_strpjoin(char **s1, char **s2)
{
	size_t	i;
	size_t	k;
	char	**str;

	k = 0;
	if (s1 == (void *)0 || s2 == (void *)0)
		return (NULL);
	str = (char **)malloc((ft_strplen(s1)
				+ ft_strplen(s2) + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*(s1 + i) != 0)
		*(str + k++) = ft_strdup(*(s1 + i++));
	i = 0;
	while (*(s2 + i) != 0)
		*(str + k++) =  ft_strdup(*(s2 + i++));
	*(str + k) = 0;
	return (str);
}

char	**ft_strpjoin_free(char **s1, char **s2)
{
	char	**str;

	str = ft_strpjoin(s1, s2);
	if (s1)
		sfree_split(s1);
	if (s2)
		sfree_split(s2);
	return (str);
}
