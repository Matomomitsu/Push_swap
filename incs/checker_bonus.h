/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 01:47:04 by mtomomit          #+#    #+#             */
/*   Updated: 2022/11/03 22:51:07 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

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

// Move_utils_bonus.c
void	ft_pa(t_first_last *first_last, t_stack *aux_sa, t_stack *aux_sb, \
		t_data *data);
void	ft_pb(t_first_last *first_last, t_stack	*aux_sa, t_stack *aux_sb, \
		t_data *data);
void	ft_sa(t_first_last *first_last, t_stack *aux_sa);
void	ft_sb(t_first_last *first_last, t_stack *aux_sb);
void	ft_rra(t_first_last *first_last, t_stack *aux_sa);
void	ft_rrb(t_first_last *first_last, t_stack *aux_sb);
void	ft_ra(t_first_last *first_last, t_stack *aux_sa);
void	ft_rb(t_first_last *first_last, t_stack *aux_sb);
void	ft_ss(t_first_last *first_last);
void	ft_rr(t_first_last *first_last);
void	ft_rrr(t_first_last *first_last);

// Check_order_bonus.c
int		check_order(t_stack *first_sa, t_stack *last_sa);

// Ft_error_bonus.c
int		check_numbers(t_stack *first_sa, t_stack *last_sa);
void	ft_free(t_stack *list, t_first_last *first_last, void *line);
void	ft_error(t_stack *list, t_first_last *first_last, void *line);
int		verify_argv(char **argv);

// Move_bonus.c
int		find_move(char *line, t_first_last *first_last, t_data *data);

#endif
