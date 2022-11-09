/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:30:40 by mtomomit          #+#    #+#             */
/*   Updated: 2022/11/05 00:03:30 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define STDOUT	STDOUT_FILENO
# define STDIN	STDIN_FILENO
# define STDERR	STDERR_FILENO

# define PA		1
# define PB		2
# define SA		3
# define SB		4
# define SS		5
# define RA		6
# define RB		7
# define RR		8
# define RRA	9
# define RRB	10
# define RRR	11

typedef struct s_data
{
	long int		num_stack_b;
	long int		num_stack_a;
	long int		biggest_number;
	long int		lowest_number;
	long int		lowest_index;
	long int		index;
}	t_data;

typedef struct s_stack
{
	long int			number;
	struct s_stack		*prev;
	struct s_stack		*next;
}	t_stack;

typedef struct s_moves
{
	long int	count_ra;
	long int	count_rb;
	long int	move_count;
}t_moves;

typedef struct s_first_last
{
	t_stack		*first_sa;
	t_stack		*first_sb;
	t_stack		*last_sa;
	t_stack		*last_sb;
}	t_first_last;

// Utils.c
long int	ft_abs(long int num);
void		get_biggest_and_lowest(t_data *data, long int *numbers, int n);
void		init_data(t_data *data, int argc);

// Move_utils.c
void		ft_pa(t_first_last *first_last, t_stack *aux_sa, t_stack *aux_sb, \
			t_data *data);
void		ft_pb(t_first_last *first_last, t_stack	*aux_sa, t_stack *aux_sb, \
			t_data *data);
void		ft_sa(t_first_last *first_last, t_stack *aux_sa);
void		ft_sb(t_first_last *first_last, t_stack *aux_sb);
void		ft_rra(t_first_last *first_last, t_stack *aux_sa);
void		ft_rrb(t_first_last *first_last, t_stack *aux_sb);
void		ft_ra(t_first_last *first_last, t_stack *aux_sa);
void		ft_rb(t_first_last *first_last, t_stack *aux_sb);
void		ft_ss(t_first_last *first_last);
void		ft_rr(t_first_last *first_last);
void		ft_rrr(t_first_last *first_last);
void		print_move(int move_number);
void		move_and_print(t_first_last *first_last, t_data *data, \
			int move_number);
void		move_remnant(t_data *data, t_first_last *first_last);

// Order_stack.c
int			check_order(t_stack *first_sa, t_stack *last_sa);
void		order_three_stack(t_first_last *first_last, t_data *data);
void		order_stack(t_first_last *first_last, t_data *data, \
			long int *numbers);

// Find_best_move.c
void		calculate_move(t_moves *move, t_data *data);
void		count_moves(t_first_last *first_last, \
			t_moves *move, t_stack *temp);
void		find_best_move_fw(t_first_last *first_last, \
			t_data *data, t_moves *best_move);
void		find_best_move_bk(t_first_last *first_last, \
			t_data *data, t_moves *best_move);
void		find_best_move(t_first_last *first_last, \
			t_data *data, t_moves *best_move);

// Push_swap.c
void		adjust_stack(t_first_last *first_last, t_data *data);

// Heap_sort.c
long int	*get_numbers(t_first_last *first_last, int n);
void		heap_sort(long int *vet, int num_vet);

// Ft_error.c
int			check_numbers(t_stack *first_sa, t_stack *last_sa);
void		ft_free(t_stack *list, t_first_last *first_last, \
			long int *numbers, t_data *data);
void		ft_error(t_stack *list, t_first_last *first_last, t_data *data);
int			verify_argv(char **argv);

#endif
