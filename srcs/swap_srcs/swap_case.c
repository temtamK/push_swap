/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 23:53:46 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/31 23:53:47 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	switch_c_norm(t_stack **a, t_stack **b, int w, t_data *data)
{
	t_stack	*tmp;

	tmp = NULL;
	if (w == 6 && size_list(*b) > 1)
	{
		ft_putstr_fd("rrb\n", data->fd);
		rr_stack(b, tmp);
		free(tmp);
	}
	else if (w == 7 && size_list(*b) > 1)
	{
		ft_putstr_fd("sb\n", data->fd);
		swap_stack(b);
	}
	else if (w == 8 && size_list(*a) > 1)
	{
		ft_putstr_fd("sa\n", data->fd);
		swap_stack(a);
	}
}

void	switch_case_norm(t_stack **a, t_stack **b, int w, t_data *data)
{
	t_stack	*tmp;

	tmp = NULL;
	if (w == 3 && size_list(*a) > 1)
	{
		ft_putstr_fd("rra\n", data->fd);
		rr_stack(a, tmp);
	}
	else if (w == 4)
	{
		ft_putstr_fd("pa\n", data->fd);
		push_stack(b, a, tmp);
		free(tmp);
	}
	else if (w == 5 && size_list(*b) > 1)
	{
		ft_putstr_fd("rb\n", data->fd);
		r_stack(b);
		free(tmp);
	}
	else
		switch_c_norm(a, b, w, data);
}

void	switch_case(t_stack **a, t_stack **b, int w, t_data *data)
{
	t_stack	*tmp;

	tmp = NULL;
	if (w == 1)
	{
		ft_putstr_fd("pb\n", data->fd);
		push_stack(a, b, tmp);
		free(tmp);
	}
	else if (w == 2)
	{
		ft_putstr_fd("ra\n", data->fd);
		r_stack(a);
		free(tmp);
	}
	else
		switch_case_norm(a, b, w, data);
}
