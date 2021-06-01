/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_use.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:10:44 by taemkim           #+#    #+#             */
/*   Updated: 2021/06/01 00:06:28 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					val_aprox(float m)
{
	int	k;

	k = (int)m;
	if ((m - k) >= 0.5)
		return ((int)m + 1);
	else
		return ((int)m);
}

int					ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if ((!s1 || !s2))
		return (-1);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (((s1[i] == '\0' && s2[i] != '\0') || (s2[i] == '\0' && s1[i] != '\0')))
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

int					size_list(t_stack *a)
{
	int	len;

	len = 0;
	while (a)
	{
		len++;
		a = a->next;
	}
	return (len);
}

static long long	operation(const char *str, long lenght, int sign)
{
	long long	r;

	r = 0;
	while (str[lenght] >= 48 && str[lenght] <= 57)
	{
		r = r * 10 + str[lenght] - '0';
		lenght++;
	}
	return (sign * r);
}

long long			my_atoi(const char *str)
{
	long	lenght;
	int		sign;

	lenght = 0;
	sign = 1;
	while (str[lenght] == ' ' || str[lenght] == '\n' || str[lenght] == '\t'
		|| str[lenght] == '\r' || str[lenght] == '\f' || str[lenght] == '\v')
		lenght++;
	if (str[lenght] == '-' || str[lenght] == '+')
	{
		if (str[lenght] == '-')
			sign *= -1;
		lenght++;
	}
	return (operation(str, lenght, sign));
}
