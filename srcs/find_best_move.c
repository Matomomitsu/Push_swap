/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:07:28 by mtomomit          #+#    #+#             */
/*   Updated: 2022/11/07 21:49:23 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	calculate_move(t_moves *move, t_data *data)
{
	if (move->count_ra > data->num_stack_a / 2)
		move->count_ra = move->count_ra - data->num_stack_a;
	if (move->count_rb > data->num_stack_b / 2)
		move->count_rb = move->count_rb - data->num_stack_b;
	if ((move->count_ra >= 0 && move->count_rb >= 0) || \
		(move->count_ra <= 0 && move->count_rb <= 0))
	{
		if (ft_abs(move->count_ra) >= ft_abs(move->count_rb))
			move->move_count = ft_abs(move->count_ra);
		else
			move->move_count = ft_abs(move->count_rb);
	}
	else
		move->move_count = ft_abs(move->count_ra) + ft_abs(move->count_rb);
}

void	count_moves(t_first_last *first_last, \
			t_moves *move, t_stack *temp)
{
	t_stack	*temp_2;

	move->count_ra = 0;
	temp_2 = first_last->first_sa;
	while (1)
	{
		if (temp->number > temp_2->prev->number && \
		temp->number < temp_2->number)
			break ;
		move->count_ra++;
		temp_2 = temp_2->next;
	}
}

void	find_best_move_fw(t_first_last *first_last, \
		t_data *data, t_moves *best_move)
{
	t_moves	move;
	t_stack	*temp;

	move.count_rb = 0;
	temp = first_last->first_sb;
	best_move->move_count = 9223372036854775807;
	while (move.count_rb <= data->num_stack_b / 2 && \
		best_move->move_count > move.count_rb)
	{
		count_moves(first_last, &move, temp);
		calculate_move(&move, data);
		if (best_move->move_count > move.move_count)
		{
			best_move->count_ra = move.count_ra;
			best_move->count_rb = move.count_rb;
			best_move->move_count = move.move_count;
		}
		temp = temp->next;
		move.count_rb++;
	}
}

void	find_best_move_bk(t_first_last *first_last, \
		t_data *data, t_moves *best_move)
{
	t_moves		move;
	t_stack		*temp;
	long int	temp_count_rb;

	temp = first_last->first_sb;
	move.count_rb = data->num_stack_b;
	while (move.count_rb >= data->num_stack_b / 2 && \
		best_move->move_count > ft_abs(move.count_rb - data->num_stack_b))
	{
		count_moves(first_last, &move, temp);
		temp_count_rb = move.count_rb;
		calculate_move(&move, data);
		if (best_move->move_count > move.move_count)
		{
			best_move->count_ra = move.count_ra;
			best_move->count_rb = move.count_rb;
			best_move->move_count = move.move_count;
		}
		temp = temp->prev;
		move.count_rb = temp_count_rb - 1;
	}
}

void	find_best_move(t_first_last *first_last, \
	t_data *data, t_moves *best_move)
{
	find_best_move_fw(first_last, data, best_move);
	find_best_move_bk(first_last, data, best_move);
}
