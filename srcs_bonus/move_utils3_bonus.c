/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 03:48:59 by mtomomit          #+#    #+#             */
/*   Updated: 2022/11/03 22:52:21 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/checker_bonus.h"

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
