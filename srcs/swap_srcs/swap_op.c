/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:48:03 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/31 17:48:04 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_c(t_data *data, int ac, char **av)
{
	if (ac == 3)
		data->split = ft_split(av[2], ' ');
	else
		data->split = &av[2];
	data = fill_in(data);
	if (data->len <= 10)
		sort_min_c(&(data->a), &(data->b), data->len);
	else if (data->len > 10 && data->len < 200)
		algo_1_c(&(data->a), &(data->b), data->len);
	else
		algo_c(&(data->a), &(data->b), data->len);
	free_stack(&data->a);
	free_arg(&data->line);
	if (ac == 3)
		ft_free_split(data->split);
}

void	swap_sh(t_data *data, int ac, char **av)
{
	t_stack	*new;

	new = NULL;
	if (ac == 3)
		data->split = ft_split(av[2], ' ');
	else
		data->split = &av[2];
	data = fill_in(data);
	print_data(data->a, data->b);
	if (data->len <= 10)
		sort_min_d(&(data->a), &(data->b), data->len);
	else if (data->len > 10 && data->len < 200)
		algo_1_d(&(data->a), &(data->b), data->len);
	else
		algo_d(&(data->a), &(data->b), data->len);
	free_stack(&new);
	free_stack(&data->a);
	free_arg(&data->line);
	if (ac == 3)
		ft_free_split(data->split);
}
