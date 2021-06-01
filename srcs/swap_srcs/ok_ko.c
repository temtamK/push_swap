/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok_ko.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:48:08 by taemkim           #+#    #+#             */
/*   Updated: 2021/06/01 00:15:12 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*fill_in(t_data *data)
{
	t_stack	*new;

	new = NULL;
	check_replicat(data->split);
	check_ascii(data->split);
	data->a = put_in_list(data, data->split, new);
	data->len = size_list(data->a);
	return (data);
}

void	checker_sort(t_data *data)
{
	if (check_sort(&data->a, data->len) == 1)
	{
		free_stack(&data->a);
		free_stack(&data->b);
		ft_putstr_fd("OK\n", 1);
		exit(1);
	}
	else
	{
		free_stack(&data->a);
		free_stack(&data->b);
		ft_putstr_fd("KO\n", 1);
		exit(1);
	}
}

int		check_sort(t_stack **a, int len)
{
	t_stack	*tmp;

	if (size_list(*a) != len)
		return (0);
	(void)len;
	tmp = (*a);
	while (tmp && tmp->next)
	{
		if ((tmp)->next != NULL && ((tmp)->number < (tmp)->next->number))
			(tmp) = (tmp)->next;
		else
			return (0);
	}
	return (1);
}
