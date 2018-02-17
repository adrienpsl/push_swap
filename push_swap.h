/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H

# include "../libft/includes/libft.h"

# define KEEP_LEFT 5

/*
**    struct push
*/

typedef struct s_loop
{
	t_dlist *lst;
	int sens;
	int end;
	int nb;
	int nb_operation;
} t_loop;

typedef struct s_pw
{
	t_dlist *lst_a;
	t_dlist *lst_b;
	int mediane;
	int *tab;
	int tab_max;
	int tab_min;
	t_dlink *lim_head;
	t_dlink *lim_tail;
	t_loop loop;
} t_pw;

/*
**  ==============  push reader  ======================================
*/
t_dlist *ft_pw_reader(int ac, char **av);
long ft_atol(const char *s);
int *get_tab(t_pw *pw);

/*
**  ==============  push swap  ======================================
*/
void ft_sa(t_pw *pw);
void ft_sb(t_pw *pw);
void ft_ss(t_pw *pw);

void ft_pb(t_pw *pw);
void ft_pa(t_pw *pw);

void ft_ra(t_pw *pw);
void ft_rb(t_pw *pw);
void ft_rr(t_pw *pw);

void ft_rra(t_pw *pw);
void ft_rrb(t_pw *pw);
void ft_rrr(t_pw *pw);

/*
**  ==============  push solver  ======================================
*/

void ft_solver(t_pw *pw);

/*
**    the fatest way
*/
long way_by_head(t_loop *loop);
long way_by_tail(t_loop *loop);

void get_nbtop_stack_lst(int *nb, t_dlist *l);



/*
**    set the good number of operation to put the nb by the end or start of the stack
*/
int find_best_way(t_pw *pw);

/*
**    comparaison int
*/
int next_bigger(t_loop *l, t_dlink *link);
int next_smaller(t_loop *l, t_dlink *link);
int end_lst(t_loop *l, size_t count);
int nb_bigger(t_loop *l, t_dlink *link);
int nb_lower(t_loop *l, t_dlink *link);
int prev_smaller(t_loop *l, t_dlink *link);
int nb_is_bigest(t_dlink *tmp, t_loop *loop);
int nb_is_lowest(t_dlink *tmp, t_loop *loop);

void set_bigger_taller(t_loop *loop);

long nb_taller_head(t_loop *loop);
size_t nb_smaller_head(t_loop *loop);
//
//size_t loop_taller_tail(t_solver *s, t_dlist *l);
//size_t loop_smaller_tail(t_solver *s, t_dlist *l);

void put_index_lst(t_dlist *lst, int tab[]);
int gn(t_dlink *link);

/*
**  ================ checker  =======================================
*/
int ft_checker_reader(t_pw *pw, int ac, char **av, int *i);
/*
**    utils
*/
void ft_error_pw(void);
void ft_error_ck(void);
void pl(t_dlist *l);
void make_circle(t_dlist *lst);

void pll(t_pw *pw, char *str);

/*
**    debug
*/
void phead(t_dlist *l);
void plt(t_dlink *tmp, t_dlist *l);

#endif
