/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderby.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 00:04:19 by taemkim           #+#    #+#             */
/*   Updated: 2021/06/01 00:14:10 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack **a, t_stack **b)
{
	r_stack(a);
	r_stack(b);
}

void	ss(t_stack **a, t_stack **b)
{
	swap_stack(a);
	swap_stack(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = NULL;
	rr_stack(a, tmp);
	rr_stack(b, tmp);
}

int		avreage(t_stack *a)
{
	int		k;
	int		i;
	int		avg;
	t_stack	*tmp;

	i = 0;
	k = 0;
	avg = 0;
	tmp = a;
	while (a != NULL)
	{
		k += a->number;
		i++;
		a = a->next;
	}
	a = tmp;
	avg = (int)(k / i);
	return (avg);
}

char	**normal(t_data *data, int ac, char **av)
{
	if (ac == 2)
		data->split = ft_split(av[1], ' ');
	else
		data->split = &av[1];
	return (data->split);
}
