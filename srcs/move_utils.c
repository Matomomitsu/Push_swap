/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 06:02:45 by mtomomit          #+#    #+#             */
/*   Updated: 2022/10/26 06:05:36 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_ss(t_first_last *first_last)
{
	ft_sa(first_last, first_last->first_sa);
	ft_sb(first_last, first_last->first_sb);
}

void	ft_rr(t_first_last *first_last)
{
	ft_ra(first_last, first_last->first_sa);
	ft_rb(first_last, first_last->first_sb);
}

void	ft_rrr(t_first_last *first_last)
{
	ft_rra(first_last, first_last->first_sa);
	ft_rrb(first_last, first_last->first_sb);
}

void	ft_pb(t_first_last *first_last, t_stack	*aux_sa, t_stack *aux_sb, \
		t_data *data)
{
	if (first_last->first_sa == NULL)
		return ;
	first_last->first_sb = first_last->first_sa;
	if (first_last->last_sb == NULL)
		first_last->last_sb = first_last->first_sb;
	else
		first_last->last_sb->next = first_last->first_sb;
	if (first_last->first_sa == first_last->last_sa)
		first_last->first_sa = NULL;
	if (first_last->first_sa == NULL)
		first_last->last_sa = NULL;
	else
	{
		first_last->first_sa = aux_sa->next;
		first_last->first_sa->prev = first_last->last_sa;
		first_last->last_sa->next = first_last->first_sa;
	}
	first_last->first_sb->next = aux_sb;
	if (aux_sb != NULL)
		aux_sb->prev = first_last->first_sb;
	data->num_stack_b++;
	data->num_stack_a--;
	first_last->first_sb->prev = first_last->last_sb;
	if (first_last->first_sa != NULL)
		first_last->last_sa->next = first_last->first_sa;
}

void	ft_sa(t_first_last *first_last, t_stack *aux_sa)
{
	if (first_last->first_sa == NULL)
		return ;
	if (first_last->first_sa == first_last->last_sa)
		return ;
	else
		first_last->first_sa = aux_sa->next;
	if (first_last->first_sa == first_last->last_sa)
	{
		first_last->last_sa = aux_sa;
		first_last->last_sa->next = first_last->first_sa;
		first_last->first_sa->prev = first_last->last_sa;
	}
	else
	{
		if (aux_sa->next == first_last->last_sa->prev)
			first_last->last_sa->prev = aux_sa;
		aux_sa->next = first_last->first_sa->next;
		first_last->first_sa->next = aux_sa;
		aux_sa->prev = first_last->first_sa;
		first_last->first_sa->prev = first_last->last_sa;
		first_last->last_sa->next = first_last->first_sa;
	}
}
