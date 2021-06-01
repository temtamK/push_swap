/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_use.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 23:49:00 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/31 23:50:06 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_under_pivot(t_stack *stack, int pivot)
{
	while (stack)
	{
		if (stack->number <= pivot)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	check_upper_pivot(t_stack *stack, int pivot)
{
	while (stack)
	{
		if (stack->number == pivot)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	get_min(t_stack *a)
{
	int	min;

	min = a->number;
	while (a)
	{
		if (a->number < min)
			min = a->number;
		a = a->next;
	}
	return (min);
}
