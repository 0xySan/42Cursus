/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:59:43 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/26 22:48:42 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define MAX_INT 2147483647

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_value
{
	int		argc;
	int		n;
	char	**numbers;
}	t_value;

typedef struct s_bcost
{
	int	a_cost;
	int	b_cost;
	int	best_a_rot;
	int	best_b_rot;
	int	best_cost;
	int	pos;
	int	current_cost;
}	t_bcost;

void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
int		is_sorted(t_stack *stack);
void	free_stack(t_stack *stack);
void	error_exit(t_stack *a, t_stack *b, int argc, char **argv);
int		ft_atoi(const char *str);
void	init_stack(t_stack *a, t_stack *b, t_value val);
void	sort_three(t_stack *a);
void	sort_small(t_stack *a, t_stack *b);
void	sort_stack(t_stack *a, t_stack *b);
void	sort_two(t_stack *a);
char	**ft_split(char const *s, char c);
void	free_numbers(char **numbers);
void	put_pos(t_stack *a, t_stack *b, int pos);
int		find_lowest(t_stack *b, int number);
void	sort_three_reverse(t_stack *b);
int		is_reverse_sorted(t_stack *stack);
int		search_min(t_stack *b);
int		check_if_highest(t_stack *b, int number);
int		check_if_lowest(t_stack *b, int number);
void	calculate_costs(t_stack *a, t_stack *b, int i, t_bcost *cost);
void	update_best_move(t_bcost *cost, int i, t_stack *a, t_stack *b);
void	find_best_move(t_stack *a, t_stack *b, t_bcost *cost);
int		search_pos(t_stack *b, int number);
void	sort_five(t_stack *a, t_stack *b);
int		ft_strlen(const char *str);

#endif