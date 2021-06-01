/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:47:25 by taemkim           #+#    #+#             */
/*   Updated: 2021/06/01 00:02:59 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*put_in_list(t_data *data, char **split, t_stack *new)
{
	int	i;

	i = 0;
	while (split[i])
	{
		new = malloc(sizeof(t_stack));
		if (new == NULL)
			return (NULL);
		new->number = my_atoi(split[i]);
		if (new->number > 2147483647 || new->number < -2147483647)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		new->next = NULL;
		new->previous = NULL;
		add_back(&data->a, new);
		new = NULL;
		i++;
	}
	return (data->a);
}

int		get_pivot(t_stack *c)
{
	t_stack	*result;
	int		len;
	int		m;
	int		k;

	m = 0;
	k = 0;
	len = 0;
	result = NULL;
	len = size_list(c);
	result = sort(c);
	if (len <= 12)
		m = val_aprox(len / 2);
	else if (len > 12 && len < 200)
		m = val_aprox(len / 4);
	else if (len >= 200)
		m = val_aprox(len / 8);
	k = node_nbr(&result, m);
	return (k);
}

int		get_index(t_stack *a, int pivot)
{
	int	i;

	i = 1;
	while (a)
	{
		if (a->number <= pivot)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}

int		get_index_max(t_stack *a, int pivot)
{
	int	i;

	i = 1;
	while (a)
	{
		if (a->number >= pivot)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}

int		get_max(t_stack *b)
{
	int		max;
	t_stack	*tmp;

	max = 0;
	tmp = NULL;
	if (b)
	{
		max = b->number;
		tmp = b;
		while (b)
		{
			if (b->number >= max)
				max = b->number;
			b = b->next;
		}
		b = tmp;
	}
	return (max);
}
