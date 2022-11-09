/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 02:02:06 by mtomomit          #+#    #+#             */
/*   Updated: 2022/11/03 22:51:57 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/checker_bonus.h"

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
