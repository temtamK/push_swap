/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:09:19 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/31 19:30:02 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**fill_ps(t_data *data, int ac, char **av)
{
	if (!ft_strcmp(av[1], "-s"))
	{
		data->fd = open("swap.log", O_CREAT | O_RDWR | O_TRUNC, 0666);
		if (data->fd == -1)
			ft_putstr_fd("Error! opening file", 1);
		if (ac == 3)
			data->split = ft_split(av[2], ' ');
		else
			data->split = &av[2];
	}
	else
	{
		data->fd = 1;
		if (ac == 2)
			data->split = ft_split(av[1], ' ');
		else
			data->split = &av[1];
	}
	return (data->split);
}

void	ft_swap(t_data *data, int ac, char **av)
{
	t_stack	*new;

	new = NULL;
	data->split = fill_ps(data, ac, av);
	check_replicat(data->split);
	check_ascii(data->split);
	data->a = put_in_list(data, data->split, new);
	if (check_sort(&data->a, size_list(data->a)) == 1)
		exit(0);
	data->len = size_list(data->a);
	free_stack(&new);
	if (data->len <= 10)
		sort_min(&(data->a), &(data->b), data->len, data);
	else if (data->len > 10 && data->len < 200)
		algo_1(&(data->a), &(data->b), data->len, data);
	else
		algo(&(data->a), &(data->b), data->len, data);
	if (ac == 2 || (ac == 3 && data->fd != 1))
		ft_free_split(data->split);
	close(data->fd);
}

int		main(int ac, char **av)
{
	t_data	*data;

	data = NULL;
	if (ac < 2)
		exit(1);
	else
	{
		data = initial(data);
		if (!ft_strcmp(av[1], "-c"))
			swap_c(data, ac, av);
		else if (!ft_strcmp(av[1], "-sh"))
			swap_sh(data, ac, av);
		else
			ft_swap(data, ac, av);
		free(data);
		data = NULL;
	}
}
