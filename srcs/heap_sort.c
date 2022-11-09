/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:03:37 by mtomomit          #+#    #+#             */
/*   Updated: 2022/11/03 06:38:49 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

long int	*get_numbers(t_first_last *first_last, int n)
{
	long int	*numbers;
	t_stack		*temp;
	size_t		i;

	i = 0;
	numbers = ft_calloc(sizeof(long int), n + 1);
	temp = first_last->first_sa;
	while (temp != first_last->last_sa)
	{
		numbers[i] = temp->number;
		i++;
		temp = temp->next;
	}
	numbers[i] = temp->number;
	return (numbers);
}

static void	create_heap(long int *vet, long int i, long int f)
{
	long int	aux;
	long int	j;

	j = i * 2 + 1;
	aux = vet[i];
	while (j <= f)
	{
		if (j < f)
		{
			if (vet[j] < vet[j + 1])
				j = j + 1;
		}
		if (aux < vet[j])
		{
			vet[i] = vet[j];
			i = j;
			j = 2 * i + 1;
		}
		else
			j = f + 1;
	}
	vet[i] = aux;
}

void	heap_sort(long int *vet, int num_vet)
{
	long int	i;
	long int	aux;

	i = (num_vet - 1) / 2;
	while (i >= 0)
	{
		create_heap(vet, i, num_vet - 1);
		i--;
	}
	i = num_vet - 1;
	while (i >= 1)
	{
		aux = vet[0];
		vet[0] = vet[i];
		vet[i] = aux;
		create_heap(vet, 0, i - 1);
		i--;
	}
}
