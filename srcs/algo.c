/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:06:00 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/08 18:19:50 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_pivot(t_stack *c)
{
    // t_stack *result;
    int len;
    int m;
    int k;

    // result = a;
    sort(c);
    len = size_list(c);
    // print_list(c);
    m = (int)(len / 2);
    k = node_nbr(&c, m);
    return (k);
}

int check_under_pivot(t_stack *a, int pivot)
{
    while (a)
    {
        if (a->number <= pivot)
            return (a->number);
        a = a->next;
    }
    return (0);
}

int get_index(t_stack *a, int pivot)
{
    int i;
    i = 1;

    while (a)
    {
        if (a->number <= pivot)
            return (i);
        a = a->next;
        i++;
    }
    return (-1);
}

void algo(t_stack **a, t_stack **b, int m)
{
    t_stack *now;
    int index;
    int proximity;
    
    now = (*a);
   
    // while (now)
    {
        int sum = get_pivot(*a);
        // puts(sum);
        print_list(*a);
        // exit(1);
        while (now && check_under_pivot(now, m))
        {
            if (now->number <= m)
            {
                puts("pb");
                push_stack(a, b);
                now = *a;
            }
            else
            {
                index = get_index(now, m);
                proximity = (size_list(now) / 2);
                if (proximity > index)
                {
                    puts("ra");
                    r_stack(a);
                }
                else
                {
                    puts("rra");
                    rr_stack(a);
                }
                now = *a;
            }
            print_list(*a);
            sleep(1);
            // now = now->next;
        }
    }
}
