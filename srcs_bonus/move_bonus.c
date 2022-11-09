/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 03:36:43 by mtomomit          #+#    #+#             */
/*   Updated: 2022/11/03 22:52:08 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/checker_bonus.h"

static int	get_move_number(char *line)
{
	if (!ft_strncmp(line, "pa\n", 4))
		return (PA);
	if (!ft_strncmp(line, "pb\n", 4))
		return (PB);
	if (!ft_strncmp(line, "sa\n", 4))
		return (SA);
	if (!ft_strncmp(line, "sb\n", 4))
		return (SB);
	if (!ft_strncmp(line, "ss\n", 4))
		return (SS);
	if (!ft_strncmp(line, "ra\n", 4))
		return (RA);
	if (!ft_strncmp(line, "rb\n", 4))
		return (RB);
	if (!ft_strncmp(line, "rr\n", 4))
		return (RR);
	if (!ft_strncmp(line, "rra\n", 5))
		return (RRA);
	if (!ft_strncmp(line, "rrb\n", 5))
		return (RRB);
	if (!ft_strncmp(line, "rrr\n", 4))
		return (RRR);
	return (0);
}

static void	execute_move(t_first_last *first_last, t_data *data, \
	int move_number)
{
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

int	find_move(char *line, t_first_last *first_last, t_data *data)
{
	int	move_number;

	move_number = get_move_number(line);
	if (move_number != 0)
	{
		execute_move(first_last, data, move_number);
		return (1);
	}
	else
		return (0);
}
