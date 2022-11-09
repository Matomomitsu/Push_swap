/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 01:26:49 by mtomomit          #+#    #+#             */
/*   Updated: 2022/11/03 22:52:01 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/checker_bonus.h"

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

static void	init_data(t_data *data, int argc)
{
	data->num_stack_a = argc - 1;
	data->num_stack_b = 0;
}

static void	print_result(t_first_last *first_last, t_stack *list, char *line)
{
	if (check_order(first_last->first_sa, first_last->last_sa) && \
		!first_last->last_sb)
		ft_printf(STDOUT, "OK\n");
	else
		ft_printf(STDOUT, "KO\n");
	ft_free(list, first_last, line);
}

int	main(int argc, char **argv)
{
	t_first_last	*first_last;
	t_data			data;
	t_stack			*list;
	char			*line;

	if (argc == 1)
		exit (1);
	first_last = (t_first_last *)ft_calloc(sizeof(t_first_last), 1);
	list = get_list(argc, argv, first_last);
	init_data(&data, argc);
	if (!check_numbers(first_last->first_sa, first_last->last_sa) || \
		!verify_argv(argv))
		ft_error(list, first_last, NULL);
	init_sb(first_last);
	line = get_next_line(STDIN);
	while (line)
	{
		if (!find_move(line, first_last, &data))
			ft_error(list, first_last, line);
		free(line);
		line = get_next_line(STDIN);
	}
	print_result(first_last, list, line);
	return (0);
}
