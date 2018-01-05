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

# define RIGHT 30
# define RIGHT_UP 31
# define RIGHT_DOWN 32

# define ONE -1
# define UP 1
# define DOWN 2

# define HEAD 1
# define TAIL 2


# define KEEP_RIGHT 4


# define KEEP_LEFT 5

/*
**    struct push
*/

typedef struct		s_solver
{
	int			nb;
	int			op;
	size_t		i;
	size_t		index;
	int more;
}					t_solver;

typedef struct		s_lim
{
	int			fst;
	int			med;
	int			lst;
}					t_lim;

typedef struct		s_pw
{
	t_dlist			*lst_a;
	t_dlist			*lst_b;
	t_list			*instruct;
	t_lim			lim;
}					t_pw;


/*
**  ==============  push reader  ======================================
*/
t_dlist *ft_pw_reader(int ac, char **av);
long	ft_atol(const char *s);
int					*get_tab(t_pw *pw);

/*
**  ==============  push swap  ======================================
*/
void		ft_sa(t_pw *pw);
void		ft_sb(t_pw *pw);
void 		ft_ss(t_pw *pw);

void		ft_pb(t_pw *pw);
void		ft_pa(t_pw *pw);

void		ft_ra(t_pw *pw);
void		ft_rb(t_pw *pw);
void		ft_rr(t_pw *pw);

void		ft_rra(t_pw *pw);
void		ft_rrb(t_pw *pw);
void		ft_rrr(t_pw *pw);

/*
**  ==============  push solver  ======================================
*/

void ft_solver(t_pw *pw);

void get_lim(t_pw *pw);
void g_nb(int *nb, t_dlist *l);

/*
**    set the good index number to put the nb in the good way
*/
void check_lim(t_solver *s, t_pw *pw);

int under_limit(size_t count, t_dlist *lst);
int nb_bigger_head(t_solver *s, t_dlist *lst);
int prev_smaller(t_dlist *lst);
int next_smaller(t_dlist *lst);

size_t loop_taller_head(t_solver *s, t_dlist *l);
size_t loop_smaller_head(t_solver *s, t_dlist *l);

size_t loop_taller_tail(t_solver *s, t_dlist *l);
size_t loop_smaller_tail(t_solver *s, t_dlist *l);

 void put_index_lst(t_dlist *lst, int tab[]);
int gn(t_dlink *link);


/*
**  ================ checker  =======================================
*/
int ft_checker_reader(t_pw *pw, int ac, char **av, int *i);
/*
**    utils
*/
void	ft_error_pw(void);
void	ft_error_ck(void);
void	pl(t_dlist *l);
void	make_circle(t_dlist *lst);

void pll(t_pw *pw);

/*
**    debug
*/
void phead(t_dlist *l);

#endif
