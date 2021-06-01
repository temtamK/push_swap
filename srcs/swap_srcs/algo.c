/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:20:54 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/31 19:27:12 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	part1_1(t_stack **a, t_stack **b, int len, t_data *data)
{
	int		size;
	int		m;
	t_stack	*tmp;
	t_stack	*tmps;

	size = len;
	while (size >= val_aprox(len / 4))
	{
		tmps = dup_list(*a);
		m = get_pivot(tmps);
		while (check_under_pivot((*a), m) && (*a))
		{
			if ((*a)->number <= m)
			{
				tmp = *a;
				switch_case(a, b, 1, data);
				size--;
				free(tmp);
			}
			else
				norm_part1(a, b, data, m);
		}
		free_stack(&tmps);
	}
}

void	part1_2(t_stack **a, t_stack **b, t_data *data, int size)
{
	int		min;
	t_stack	*tmp;

	tmp = NULL;
	while (*a && !check_sort(a, size))
	{
		min = get_min(*a);
		tmp = (*a)->next;
		while ((*a)->number != min && tmp && tmp->number == min)
			switch_case(a, b, 8, data);
		while (size_list(*a) && check_under_pivot((*a), min))
		{
			if ((*a)->number == min)
			{
				tmp = *a;
				switch_case(a, b, 1, data);
				free(tmp);
				size--;
			}
			else
				norm_part1(a, b, data, min);
		}
	}
}

void	part1_3(t_stack **a, t_stack **b, t_data *data, int max)
{
	t_stack	*tmp;

	tmp = NULL;
	while (*b)
	{
		max = get_max(*b);
		while (check_upper_pivot((*b), max))
		{
			max = get_max(*b);
			tmp = (*b)->next;
			while ((*b)->number != max && tmp && tmp->number == max)
				switch_case(a, b, 7, data);
			while (((*b)->number != max) && *b)
				norm_part3(a, b, data, max);
			while (*b && (*b)->number == max)
			{
				tmp = *b;
				switch_case(a, b, 4, data);
				max = get_max(*b);
				free(tmp);
			}
		}
	}
}

void	algo_1(t_stack **a, t_stack **b, int len, t_data *data)
{
	int	m;

	m = 0;
	part1_1(a, b, len, data);
	part1_2(a, b, data, len);
	part1_3(a, b, data, m);
	free_stack(a);
	free_stack(b);
}
