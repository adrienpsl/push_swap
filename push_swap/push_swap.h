//
// Created by Adrien PUSEL on 12/31/17.
//

#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H

# include "../../libft/includes/libft.h"

/*
**    struct push
*/

typedef struct		s_pw
{
	t_dlist			*lst;
}					t_pw;


/*
**  ==============  push reader  ======================================
*/
t_dlist *ft_main_reader(int ac, char **av);
long	ft_atol(const char *s);
int					*get_tab(t_pw *pw);
void put_good_nb(t_dlist *pw, int nb);

/*
**  ==============  push swap  ======================================
*/

/*
**  ===========  main  ===========
*/

/*
**    utils
*/
void	ft_error_pw(void);

#endif
