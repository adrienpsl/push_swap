#ifndef LIBFT_DOUBLE_LINKED_LIST_H
# define LIBFT_DOUBLE_LINKED_LIST_H

# include "../../../includes/libft.h"
# include "./double_linked_list_link/header/double_linked_list_link_header.h"
# include "./double_linked_list_object/header/double_linked_list_header.h"

typedef struct		s_dll_l
{
	size_t			content_size;
	void			*content;
	t_dll_l			next;
	t_dll_l			prev;
}					*t_dll_l;
#endif

