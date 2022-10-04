/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:32:27 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/05 01:29:49 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<limits.h>
# include	<stdio.h>

# ifndef SIZE_MAX
/* Limit of `size_t' type.  */
#  if __WORDSIZE == 64
#   define SIZE_MAX                (18446744073709551615UL)
#  else
#   define SIZE_MAX                (4294967295U)
#  endif
# endif

# define STACK_COUNT 3

typedef struct s_list
{
	int				val;
	int				index;
	struct s_list	*next;
}	t_list;

//libft
long	ft_atoi(const char *str);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
int		ft_putstr_fd(char *str, int fd);

// lst_utils.c
void	ft_lstadd_back(t_list **lst, t_list *node);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **stack);
t_list	*ft_lstlast(t_list *lst);

//error.c
void	error_exit(char *str);

//utils.c
void	free_split(char **str);
int		is_sorted(t_list **stack);
int		get_distance(t_list **stack, int index);
int		find_max(t_list *stack);

//check_args.c
void	check_args(int argc, char **argv);

//index.c
void	index_stack(t_list **stack);

//the only dumb methods we are allow to use
//push.c
int		pa(t_list **a, t_list **b);
int		pb(t_list **a, t_list **b);

//rotate.c
int		ra(t_list **a);
int		rb(t_list **b);
int		rr(t_list **a, t_list **b);

//reverse_rotate.c
int		rra(t_list **a);
int		rrb(t_list **b);
int		rrr(t_list **a, t_list **b);

//swap.c
int		sa(t_list **a);
int		sb(t_list **b);
int		ss(t_list **a, t_list **b);

//my_func_too_long.c
void	ra_sa_rra(t_list **stack);
void	sa_rra(t_list **stack);

//sort_ha_and_below.c
void	sort_ha_and_below(t_list **a, t_list **b);
void	sort_sam(t_list **a);

//radix.c
void	the_god_damn_radix_sort(t_list **stack_a, t_list **stack_b);

//quick_sort.c
//void	quick_sort(t_list **a, t_list **b, int n);

//the_sorter.c
//void	sort_it(t_list **a, t_list **b);

//insertion_sort.c
void	move_to_b(t_list **a, t_list **b, int chunk, int limit);
void	insertion_sort(t_list **a, t_list **b, int chunk_count);

void	ft_lstprint(t_list	*lst);
#endif
