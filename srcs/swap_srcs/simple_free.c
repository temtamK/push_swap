/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 00:04:50 by taemkim           #+#    #+#             */
/*   Updated: 2021/06/01 00:04:50 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arg(char **arg)
{
	if (*arg)
		free(*arg);
	*arg = NULL;
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_single_stack(t_stack **stack)
{
	free(*stack);
	*stack = NULL;
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack)
	{
		while (*stack)
		{
			tmp = (*stack)->next;
			free(*stack);
			*stack = NULL;
			(*stack) = tmp;
		}
		free(*stack);
		*stack = NULL;
	}
}
