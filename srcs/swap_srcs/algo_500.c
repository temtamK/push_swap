/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:21:32 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/31 19:21:42 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	part_1(t_stack **a, t_stack **b, int len, t_data *data)
{
	int		size;
	int		m;
	t_stack	*tmp;
	t_stack	*tmps;

	size = len;
	while (size >= val_aprox(len / 8))
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

void	part_2(t_stack **a, t_stack **b, t_data *data, int size)
{
	t_stack	*tmp;
	t_stack	*tmps;
	int		min;

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
				tmps = *a;
				switch_case(a, b, 1, data);
				free(tmps);
				size--;
			}
			else
				norm_part1(a, b, data, min);
		}
	}
}

void	part_3(t_stack **a, t_stack **b, t_data *data, int max)
{
	t_stack	*tmp;
	t_stack	*tmps;

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
				tmps = *b;
				switch_case(a, b, 4, data);
				max = get_max(*b);
				free(tmps);
			}
		}
	}
}

void	algo(t_stack **a, t_stack **b, int len, t_data *data)
{
	int	m;

	m = 0;
	part_1(a, b, len, data);
	part_2(a, b, data, len);
	part_3(a, b, data, m);
	free_stack(a);
	free_stack(b);
}
