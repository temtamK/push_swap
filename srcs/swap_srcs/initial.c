/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 00:02:39 by taemkim           #+#    #+#             */
/*   Updated: 2021/06/01 00:14:00 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*initial(t_data *data)
{
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		exit(1);
	data->a = NULL;
	data->b = NULL;
	data->len = 0;
	data->line = NULL;
	data->split = NULL;
	data->print = 0;
	data->color = 0;
	return (data);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

int		condition(char *line)
{
	if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "ra"))
		return (1);
	if (!ft_strcmp(line, "rra") || !ft_strcmp(line, "sb"))
		return (1);
	if (!ft_strcmp(line, "rb") || !ft_strcmp(line, "rrb"))
		return (1);
	if (!ft_strcmp(line, "pb") || !ft_strcmp(line, "pa"))
		return (1);
	if (!ft_strcmp(line, "ss"))
		return (1);
	if (!ft_strcmp(line, "rrr") || !ft_strcmp(line, "rr"))
		return (1);
	else
		return (0);
}
