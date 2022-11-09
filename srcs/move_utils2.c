/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 06:03:55 by mtomomit          #+#    #+#             */
/*   Updated: 2022/10/26 06:05:07 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_rra(t_first_last *first_last, t_stack *aux_sa)
{
	if (first_last->first_sa == NULL)
		return ;
	if (first_last->first_sa == first_last->last_sa)
		return ;
	else
			first_last->first_sa = aux_sa->prev;
	first_last->last_sa = aux_sa->prev->prev;
}

void	ft_rrb(t_first_last *first_last, t_stack *aux_sb)
{
	if (first_last->first_sb == NULL)
		return ;
	if (first_last->first_sb == first_last->last_sb)
		return ;
	else
			first_last->first_sb = aux_sb->prev;
	first_last->last_sb = aux_sb->prev->prev;
}

void	ft_ra(t_first_last *first_last, t_stack *aux_sa)
{
	if (first_last->first_sa == NULL)
		return ;
	if (first_last->first_sa == first_last->last_sa)
		return ;
	else
			first_last->last_sa = aux_sa;
	first_last->first_sa = aux_sa->next;
}

void	ft_rb(t_first_last *first_last, t_stack *aux_sb)
{
	if (first_last->first_sb == NULL)
		return ;
	if (first_last->first_sb == first_last->last_sb)
		return ;
	else
			first_last->last_sb = aux_sb;
	first_last->first_sb = aux_sb->next;
}

void	ft_sb(t_first_last *first_last, t_stack *aux_sb)
{
	if (first_last->first_sb == NULL)
		return ;
	if (first_last->first_sb == first_last->last_sb)
		return ;
	else
		first_last->first_sb = aux_sb->next;
	if (first_last->first_sb == first_last->last_sb)
	{
		first_last->last_sb = aux_sb;
		first_last->last_sb->next = first_last->first_sb;
		first_last->first_sb->prev = first_last->last_sb;
	}
	else
	{
		if (aux_sb->next == first_last->last_sb->prev)
			first_last->last_sb->prev = aux_sb;
		aux_sb->next = first_last->first_sb->next;
		first_last->first_sb->next = aux_sb;
		aux_sb->prev = first_last->first_sb;
		first_last->first_sb->prev = first_last->last_sb;
		first_last->last_sb->next = first_last->first_sb;
	}
}
