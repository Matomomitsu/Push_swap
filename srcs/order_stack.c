/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:09:41 by mtomomit          #+#    #+#             */
/*   Updated: 2022/11/05 00:09:39 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	check_order(t_stack *first_sa, t_stack *last_sa)
{
	t_stack	*temp;
	t_stack	*aux;

	temp = first_sa;
	while (temp != last_sa)
	{
		aux = temp->next;
		if (temp->number > aux->number)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	order_three_stack(t_first_last *first_last, t_data *data)
{
	t_stack	*temp;

	temp = first_last->first_sa->next;
	while (!check_order(first_last->first_sa, first_last->last_sa))
	{
		if (first_last->first_sa->number > first_last->last_sa->number)
		{
			if (first_last->first_sa->number < temp->number)
				move_and_print(first_last, data, RRA);
			else
				move_and_print(first_last, data, RA);
		}
		if (first_last->first_sa->number > \
			first_last->first_sa->next->number || \
			first_last->last_sa->number < \
			first_last->last_sa->prev->number)
			move_and_print(first_last, data, SA);
		temp = first_last->first_sa->next;
	}
}

static void	change_stack(t_data *data, \
		t_first_last *first_last, long int *numbers)
{
	long int	i;

	i = data->index;
	while (data->num_stack_a > 3 && data->lowest_number \
	!= numbers[data->lowest_index])
	{
		if (first_last->first_sa->number <= numbers[data->lowest_index] && \
			first_last->first_sa->number != data->lowest_number && \
			first_last->first_sa->number != data->biggest_number)
		{
			move_and_print(first_last, data, PB);
			if (numbers[data->lowest_index] != data->biggest_number)
				data->lowest_index++;
		}
		else
		{
			if (first_last->first_sb && first_last->first_sb->number \
				<= numbers[i])
				move_and_print(first_last, data, RR);
			else
				move_and_print(first_last, data, RA);
		}
		if (data->lowest_index >= i + data->index)
			i = i + data->index;
	}
}

static void	execute_best_move(t_moves *best_move, t_first_last *first_last, \
		t_data *data)
{
	while (best_move->count_ra != 0 || best_move->count_rb != 0)
	{
		if (best_move->count_ra > 0 && best_move->count_rb > 0)
			move_and_print(first_last, data, RR);
		if (best_move->count_ra < 0 && best_move->count_rb < 0)
			move_and_print(first_last, data, RRR);
		if (best_move->count_ra > 0 && best_move->count_rb <= 0)
			move_and_print(first_last, data, RA);
		if (best_move->count_ra < 0 && best_move->count_rb >= 0)
			move_and_print(first_last, data, RRA);
		if (best_move->count_ra >= 0 && best_move->count_rb < 0)
			move_and_print(first_last, data, RRB);
		if (best_move->count_ra <= 0 && best_move->count_rb > 0)
			move_and_print(first_last, data, RB);
		if (best_move->count_ra > 0)
			best_move->count_ra--;
		if (best_move->count_ra < 0)
			best_move->count_ra++;
		if (best_move->count_rb > 0)
			best_move->count_rb--;
		if (best_move->count_rb < 0)
			best_move->count_rb++;
	}
}

void	order_stack(t_first_last *first_last, t_data *data, long int *numbers)
{
	t_moves	best_move;

	change_stack(data, first_last, numbers);
	move_remnant(data, first_last);
	order_three_stack(first_last, data);
	while (first_last->first_sb)
	{
		best_move.count_ra = 0;
		best_move.count_rb = 0;
		find_best_move(first_last, data, &best_move);
		execute_best_move(&best_move, first_last, data);
		move_and_print(first_last, data, PA);
	}
}
