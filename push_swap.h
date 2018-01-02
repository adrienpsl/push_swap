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

/*
**    struct push
*/

typedef struct		s_pw
{
	t_dlist			*lst_a;
	t_dlist			*lst_b;
	t_list			*instruct;
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
void		ft_pb(t_pw *pw);
void		ft_pa(t_pw *pw);
/*
**  ================ checker  =======================================
*/
t_dlist *ft_checker_reader(int ac, char **av);
/*
**    utils
*/
void	ft_error_pw(void);
void	ft_error_ck(void);
void	pl(t_dlist *l);
void	make_circle(t_dlist *lst);

#endif
