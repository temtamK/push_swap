/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:49:59 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/03 13:29:16 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER
#define CHECKER

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

typedef struct s_stack{

    int number;
    struct s_stack *next;
    struct s_stack *previous;
} t_stack;

/**********************LIST*******************/
t_stack *put_in_list(char **av);
t_stack *creat_stack(char *av, t_stack *A);
t_stack *add_back(t_stack **head,t_stack *new,char *av);
t_stack *add_back1(t_stack **head,t_stack *new);
t_stack *add_back1(t_stack **head, t_stack *new);
/**********************TOOlS*******************/
int ft_strcmp(const char *s1, const char *s2);
int size_list(t_stack *A);
/**********************ERRORS*********************/
int first_errors(int ac, char **av);
int check_ascii(char **av);
/**********************FREE*********************/
void free_arg(char **arg);
void free_stack(t_stack *stack);

/********************** MOVES*******************/
t_stack *swap_stack(t_stack *head);
t_stack *rotate_stack(t_stack *head);

#endif