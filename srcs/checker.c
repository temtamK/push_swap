/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:04:35 by taemkim           #+#    #+#             */
/*   Updated: 2021/06/01 14:39:45 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*string(t_data *data, char *tmp)
{
	char	*str;

	str = NULL;
	data->line = ft_calloc(BUFFER_SIZE, sizeof(char));
	while (read(0, data->line, BUFFER_SIZE))
	{
		tmp = str;
		if (str == NULL)
			str = ft_strdup(data->line);
		else
			str = ft_strjoin(str, data->line);
		if (data->ac >= 2 && !ft_strchr(data->av[1], ' '))
			condition_(data->line);
		if (tmp)
		{
			free(tmp);
			tmp = NULL;
		}
		if (data->line[0] == '\0' || data->line[0] == '\n')
			break ;
		free_arg(&data->line);
		data->line = malloc(sizeof(char) * BUFFER_SIZE);
		ft_bzero(data->line, BUFFER_SIZE);
	}
	return (str);
}

char	**checker_norm(t_data *data, char **line, char *tmp)
{
	char	*l;

	l = string(data, tmp);
	if (l)
	{
		line = ft_split(l, '\n');
		free_arg(&l);
	}
	else
		checker_sort(data);
	return (line);
}

void	the_end(t_data *data, char **line, int i)
{
	while (line[i])
	{
		if (data->ac <= 2)
		{
			checker_pars(&data->a, &data->b, line[i]);
			i++;
		}
		else
		{
			if (condition(line[i]) == 1)
			{
				checker_pars(&data->a, &data->b, line[i]);
				i++;
			}
			else
			{
				ft_free_split(line);
				free_stack(&data->a);
				free_stack(&data->b);
				free(data);
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
		}
	}
}

void	checker(t_data *data, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	line = checker_norm(data, line, tmp);
	the_end(data, line, i);
	ft_free_split(line);
	checker_sort(data);
}

int		main(int ac, char **av)
{
	t_data	*data;
	char	**line;

	line = NULL;
	data = NULL;
	if (ac < 2)
		exit(1);
	else
	{
		data = initial(data);
		data->ac = ac;
		data->av = av;
		if (!ft_strcmp(av[1], "-v"))
			option_v(data, ac, av);
		else
		{
			data->split = normal(data, ac, av);
			data = fill_in(data);
			checker(data, line);
		}
	}
}
