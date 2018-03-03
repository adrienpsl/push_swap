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

#ifndef LIBFT_HEADER_ARGV_H
# define LIBFT_HEADER_ARGV_H

# define SIZE_OPTION BUFFER_OPTION_ARGV

/*
**    ==== define the type of my object ======================================
*/
typedef struct s_argv *t_argv;

/*
**    ==== methods ===========================================================
*/
typedef struct s_m_argv
{
	void (*destroy)(t_argv *);
	int (*is_one)(t_argv);
} t_m_argv;

/*
**    ==== define my object ==================================================
*/

struct s_argv
{
	t_m_argv mm;
	char str_options[SIZE_OPTION];
	int count;
	int ac;
	char **av;
};

/*
**    ==== prototype constructor =============================================
*/
t_argv new_argv(int ac, char **av);

/*
**    functions
*/
void no_argv(char *string, int ac);


#endif