/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:29:55 by mtomomit          #+#    #+#             */
/*   Updated: 2022/11/07 18:33:04 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static t_stack	*get_list(int argc, char **argv, t_first_last *first_last)
{
	t_stack	*numbers;
	int		i;

	i = 1;
	numbers = (t_stack *)ft_calloc(sizeof(t_stack), argc);
	while (argv[i])
	{
		numbers[i - 1].number = ft_atoi(argv[i]);
		if (argv[i + 1])
			numbers[i - 1].next = &numbers[i];
		else
			numbers[i - 1].next = &numbers[0];
		if (i != 1)
			numbers[i - 1].prev = &numbers[i - 2];
		i++;
	}
	first_last->first_sa = &numbers[0];
	if (i > 1)
		first_last->last_sa = &numbers[i - 2];
	if (i > 1)
		first_last->first_sa->prev = first_last->last_sa;
	return (numbers);
}

static void	init_sb(t_first_last *first_last)
{
	first_last->first_sb = NULL;
	first_last->last_sb = NULL;
}

void	adjust_stack(t_first_last *first_last, t_data *data)
{
	long int	i;
	long int	moves;
	t_stack		*temp;

	i = 0;
	temp = first_last->first_sa;
	while (temp->number != data->lowest_number)
	{
		i++;
		temp = temp->next;
	}
	if (i > data->num_stack_a / 2)
		moves = i - data->num_stack_a;
	else
		moves = i;
	if (moves >= 0)
		while (moves-- > 0)
			move_and_print(first_last, data, RA);
	else
		while (moves++ < 0)
			move_and_print(first_last, data, RRA);
}

int	main(int argc, char **argv)
{
	t_first_last	*first_last;
	t_data			*data;
	t_stack			*list;
	long int		*numbers;

	if (argc == 1)
		exit (1);
	first_last = (t_first_last *)ft_calloc(sizeof(t_first_last), 1);
	data = (t_data *)ft_calloc(sizeof(t_data), 1);
	list = get_list(argc, argv, first_last);
	init_data(data, argc);
	if (!check_numbers(first_last->first_sa, first_last->last_sa) || \
		!verify_argv(argv))
		ft_error(list, first_last, data);
	if (check_order(first_last->first_sa, first_last->last_sa))
		ft_free(list, first_last, NULL, data);
	numbers = get_numbers(first_last, argc - 1);
	heap_sort(numbers, argc - 1);
	get_biggest_and_lowest(data, numbers, argc - 1);
	init_sb(first_last);
	order_stack(first_last, data, numbers);
	adjust_stack(first_last, data);
	ft_free(list, first_last, numbers, data);
	return (0);
}
