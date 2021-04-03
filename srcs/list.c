/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:07:59 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/03 11:26:50 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *add_back(t_stack **head,t_stack *new,char *av)
{
    t_stack *tmp;
    
    new=(t_stack *)malloc(sizeof(t_stack));
    new->number = ft_atoi(av);
    new->next = NULL;
    new->previous = NULL;
    if(*head == NULL)
       *head = new;
    else
    {
        tmp = *head;
        while (tmp->next)
                tmp = tmp->next;
        tmp->next = new;
        new->previous = tmp;
            return(*head);
    }
    return(*head);
}


t_stack *put_in_list(char **av)
{
    t_stack *A;
    t_stack *tmp;
    char *str;
    int i;

    i = 1;
     A =(t_stack *)malloc(sizeof(t_stack));
    A = NULL;
    tmp = NULL;
    str = NULL;
    while (av[i])
    {
        str = ft_strdup(av[i]);
        // puts(str);
        add_back(&A,tmp,str);
        free_stack(tmp);
        free_arg(&str);
        i++;
    }
    return (A);
}
