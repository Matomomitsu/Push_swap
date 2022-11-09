/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 06:06:27 by mtomomit          #+#    #+#             */
/*   Updated: 2022/11/05 00:10:25 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_pa(t_first_last *first_last, t_stack *aux_sa, t_stack *aux_sb, \
		t_data *data)
{
	if (first_last->first_sb == NULL)
		return ;
	first_last->first_sa = first_last->first_sb;
	if (first_last->last_sa == NULL)
		first_last->last_sa = first_last->first_sa;
	else
		first_last->last_sa->next = first_last->first_sa;
	if (first_last->first_sb == first_last->last_sb)
		first_last->first_sb = NULL;
	if (first_last->first_sb == NULL)
		first_last->last_sb = NULL;
	else
	{
		first_last->first_sb = aux_sb->next;
		first_last->first_sb->prev = first_last->last_sb;
		first_last->last_sb->next = first_last->first_sb;
	}
	first_last->first_sa->next = aux_sa;
	if (aux_sa != NULL)
		aux_sa->prev = first_last->first_sa;
	first_last->first_sa->prev = first_last->last_sa;
	data->num_stack_a++;
	data->num_stack_b--;
	if (first_last->first_sb != NULL)
		first_last->last_sb->next = first_last->first_sb;
}

void	print_move(int move_number)
{
	if (move_number == PA)
		ft_printf(STDOUT, "pa\n");
	if (move_number == PB)
		ft_printf(STDOUT, "pb\n");
	if (move_number == SA)
		ft_printf(STDOUT, "sa\n");
	if (move_number == SB)
		ft_printf(STDOUT, "sb\n");
	if (move_number == SS)
		ft_printf(STDOUT, "ss\n");
	if (move_number == RA)
		ft_printf(STDOUT, "ra\n");
	if (move_number == RB)
		ft_printf(STDOUT, "rb\n");
	if (move_number == RR)
		ft_printf(STDOUT, "rr\n");
	if (move_number == RRA)
		ft_printf(STDOUT, "rra\n");
	if (move_number == RRB)
		ft_printf(STDOUT, "rrb\n");
	if (move_number == RRR)
		ft_printf(STDOUT, "rrr\n");
}

void	move_and_print(t_first_last *first_last, t_data *data, int move_number)
{
	print_move(move_number);
	if (move_number == PA)
		ft_pa(first_last, first_last->first_sa, first_last->first_sb, data);
	if (move_number == PB)
		ft_pb(first_last, first_last->first_sa, first_last->first_sb, data);
	if (move_number == SA)
		ft_sa(first_last, first_last->first_sa);
	if (move_number == SB)
		ft_sb(first_last, first_last->first_sb);
	if (move_number == SS)
		ft_ss(first_last);
	if (move_number == RA)
		ft_ra(first_last, first_last->first_sa);
	if (move_number == RB)
		ft_rb(first_last, first_last->first_sb);
	if (move_number == RR)
		ft_rr(first_last);
	if (move_number == RRA)
		ft_rra(first_last, first_last->first_sa);
	if (move_number == RRB)
		ft_rrb(first_last, first_last->first_sb);
	if (move_number == RRR)
		ft_rrr(first_last);
}

void	move_remnant(t_data *data, t_first_last *first_last)
{
	while (data->num_stack_a > 3)
	{
		if (first_last->first_sa->number == data->biggest_number || \
			first_last->first_sa->number == data->lowest_number)
			move_and_print(first_last, data, RA);
		else
			move_and_print(first_last, data, PB);
	}
}
