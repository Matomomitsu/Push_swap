/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:09:06 by mtomomit          #+#    #+#             */
/*   Updated: 2022/11/05 00:57:12 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

long int	ft_abs(long int num)
{
	if (num >= 0)
		return (num);
	else
		return (-num);
}

void	get_biggest_and_lowest(t_data *data, long int *numbers, int n)
{
	long int	i;

	if (data->num_stack_a >= 200)
		i = (15 * n) / 100;
	else
		i = (25 * n) / 100;
	data->index = i - 1;
	data->lowest_index = i - 1;
	data->biggest_number = numbers[n - 1];
	data->lowest_number = numbers[0];
}

void	init_data(t_data *data, int argc)
{
	data->num_stack_a = argc - 1;
	data->num_stack_b = 0;
}
