#ifndef LIBFT_BUFFER_OBJ_STR_H
#define LIBFT_BUFFER_OBJ_STR_H

# include "../../../../includes/libft.h"

/*
**	type of object
*/
struct buffer;
typedef struct buffer *t_buffer;

/*
**	methods of object
*/
typedef void (*destroy_buffer)(t_buffer);
typedef void (*add_str_buffer)(t_buffer, const char *str);
typedef void (*add_char)(t_buffer, const char *str);
typedef void (*print_str_buffer)(t_buffer);


#endif
