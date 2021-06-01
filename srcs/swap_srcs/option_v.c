/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_v.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 00:03:50 by taemkim           #+#    #+#             */
/*   Updated: 2021/06/01 00:13:31 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	option_v(t_data *data, int ac, char **av)
{
	if (ac == 3)
		data->split = ft_split(av[2], ' ');
	else
		data->split = &av[2];
	data = fill_in(data);
	while (1)
	{
		data->line = ft_calloc(BUFFER_SIZE, sizeof(char));
		read(0, data->line, BUFFER_SIZE);
		if (data->line[0] == '\0' || data->line[0] == '\n')
		{
			checker_sort(data);
			exit(1);
		}
		else
			checker_pars_v(&data->a, &data->b, data->line);
		system("clear");
		print_data(data->a, data->b);
		free_arg(&(data->line));
	}
	if (data->line[0] == '\0' || data->line[0] == '\n')
	{
		checker_sort(data);
		exit(1);
	}
}

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dup = (char *)malloc(sizeof(char) * i + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (void *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	i = (size * count) - 1;
	while (i >= 0)
	{
		ptr[i] = '\0';
		i--;
	}
	return (ptr);
}

int		ft_strlen(char *s1)
{
	int	k;

	k = 0;
	while (s1[k])
		k++;
	return (k);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*s3;
	char			*str1;
	char			*str2;
	unsigned int	len;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	str1 = (char *)s1;
	str2 = (char *)s2;
	len = 0;
	s3 = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (s3 == NULL)
		return (NULL);
	while (*str1)
		s3[len++] = *(str1++);
	while (*str2)
		s3[len++] = *(str2++);
	s3[len] = '\0';
	return (s3);
}
