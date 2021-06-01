/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:27:39 by taemkim           #+#    #+#             */
/*   Updated: 2021/06/01 00:46:39 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_norm_3(t_stack **a, t_stack **b, t_data *data)
{
	switch_case(a, b, 8, data);
	switch_case(a, b, 3, data);
}

void	sort_a_3(t_stack **a, t_stack **b, int len, t_data *data)
{
	t_stack	*bt_stack;
	int		min;

	bt_stack = bottom(*a);
	min = get_min(*a);
	while (check_sort(a, len) == 0)
	{
		if ((*a)->number < (*a)->next->number && bt_stack->number == min)
			switch_case(a, b, 3, data);
		else if ((*a)->number > (*a)->next->number && bt_stack->number == min)
			sort_norm_3(a, b, data);
		else if ((*a)->next->number == min)
		{
			if ((*a)->number < bt_stack->number)
				switch_case(a, b, 8, data);
			else if ((*a)->number > bt_stack->number)
				switch_case(a, b, 2, data);
		}
		else if ((*a)->number == min && (*a)->next->number > bt_stack->number)
		{
			switch_case(a, b, 8, data);
			switch_case(a, b, 2, data);
		}
	}
}

void	sort_min1(t_stack **a, t_stack **b, int len, t_data *data)
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
			switch_case(a, b, 8, data);
		while (m != (*a)->number)
			norm_part1(a, b, data, m);
		if (m == (*a)->number)
		{
			ss = *a;
			switch_case(a, b, 1, data);
			free(ss);
			size--;
		}
	}
}

void	sort_min(t_stack **a, t_stack **b, int len, t_data *data)
{
	t_stack	*ss;

	ss = NULL;
	if (len == 2 && (*a)->number > (*a)->next->number)
		switch_case(a, b, 8, data);
	if (len <= 3)
		sort_a_3(a, b, len, data);
	else if (len > 3)
	{
		sort_min1(a, b, len, data);
		sort_a_3(a, b, 3, data);
		while ((*b))
		{
			ss = *b;
			switch_case(a, b, 4, data);
			free(ss);
		}
		free_stack(b);
	}
	free_stack(a);
}
