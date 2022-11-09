/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 01:49:05 by mtomomit          #+#    #+#             */
/*   Updated: 2022/11/03 22:52:05 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/checker_bonus.h"

int	check_numbers(t_stack *first_sa, t_stack *last_sa)
{
	t_stack	*temp;
	t_stack	*aux;

	temp = first_sa;
	while (temp != last_sa)
	{
		aux = temp->next;
		while (aux != last_sa)
		{
			if (temp->number == aux->number)
				return (0);
			aux = aux->next;
		}
		if (temp->number == aux->number)
			return (0);
		if (temp->number > 2147483647 || temp->number < -2147483648)
			return (0);
		temp = temp->next;
	}
	if (temp->number > 2147483647 || temp->number < -2147483648)
		return (0);
	return (1);
}

int	verify_argv(char **argv)
{
	int	i;
	int	o;

	i = 1;
	o = 0;
	while (argv[i] != NULL)
	{
		if (argv[i][o] == '-' || argv[i][o] == '+')
			o = 1;
		while (argv[i][o])
			if (argv[i][o] < '0' || argv[i][o++] > '9')
				return (0);
		i++;
		o = 0;
	}
	return (1);
}

void	ft_free(t_stack *list, t_first_last *first_last, void *line)
{
	free(list);
	free(first_last);
	free(line);
}

void	ft_error(t_stack *list, t_first_last *first_last, void *line)
{
	free(list);
	free(first_last);
	free(line);
	ft_printf(STDOUT, "Error\n");
	exit (1);
}
