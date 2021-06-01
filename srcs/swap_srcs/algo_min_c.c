/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_min_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:06:31 by taemkim           #+#    #+#             */
/*   Updated: 2021/06/01 00:24:58 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_norm_c(t_stack **a, t_stack **b)
{
	switch_case_color(a, b, 8);
	switch_case_color(a, b, 3);
}

void	sort_c_3(t_stack **a, t_stack **b, int len)
{
	t_stack	*bottom_stack;
	int		min;

	bt_stack = bottom(*a);
	min = get_min(*a);
	while (check_sort(a, len) == 0)
	{
		if ((*a)->number < (*a)->next->number && bt_stack->number == min)
			switch_case_color(a, b, 3);
		else if ((*a)->number > (*a)->next->number && bt_stack->number == min)
			sort_norm_c(a, b);
		else if ((*a)->next->number == min)
		{
			if ((*a)->number < bt_stack->number)
				switch_case_color(a, b, 8);
			else if ((*a)->number > bt_stack->number)
				switch_case_color(a, b, 2);
		}
		else if ((*a)->number == min && (*a)->next->number > bt_stack->number)
		{
			switch_case_color(a, b, 8);
			switch_case_color(a, b, 2);
		}
	}
}

void	sort_min1_c(t_stack **a, t_stack **b, int len)
{
	int		size;
	int		m;
	t_stack	*ss;
	t_stack	*tmp;

	size = len;
	while (size > 3)
	{
		m = get_min(*a);
		tmp = (*a)->next;
		if ((*a)->number != m && tmp && tmp->number == m)
			switch_case_color(a, b, 8);
		while (m != (*a)->number)
			norm_part1_c(a, b, m, 1);
		if (m == (*a)->number)
		{
			ss = *a;
			switch_case_color(a, b, 1);
			free(ss);
			size--;
		}
	}
}

void	sort_min_c(t_stack **a, t_stack **b, int len)
{
	t_stack	*ss;

	ss = NULL;
	if (len == 3)
		sort_c_3(a, b, len);
	else if (len > 3)
	{
		sort_min1_c(a, b, len);
		sort_c_3(a, b, 3);
		while ((*b))
		{
			ss = *b;
			switch_case_color(a, b, 4);
			free(ss);
		}
		free_stack(b);
	}
	free_stack(a);
}
