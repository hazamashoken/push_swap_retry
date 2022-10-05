/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:30:56 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/05 15:46:54 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include	<string.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<limits.h>

# include	"get_next_line.h"
# include	"push_swap.h"

# ifndef SIZE_MAX
/* Limit of `size_t' type.  */
#  if __WORDSIZE == 64
#   define SIZE_MAX                (18446744073709551615UL)
#  else
#   define SIZE_MAX                (4294967295U)
#  endif
# endif

//utils.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	error_free_exit(char *str, t_list **a, t_list **b);

#endif
