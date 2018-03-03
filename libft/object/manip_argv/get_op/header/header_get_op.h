#ifndef LIBFT_GET_OP_H
# define LIBFT_GET_OP_H

#define OPTIONS D_options

/*
**    ==== define the type of my object ======================================
*/
typedef struct s_get_op *t_get_op;

/*
**    ==== methods ===========================================================
*/
typedef struct s_m_get_op
{
	void (*destroy)(t_get_op *);
	/*
	**    return argv objet with option
	*/
	t_argv (*get_option)(t_get_op);
} t_m_get_op;


/*
**    ==== method debug ======================================================
*/
typedef struct s_d_get_op
{
} t_d_get_op;

/*
**    ==== utils =============================================================
*/
typedef struct s_u_get_op
{

} t_u_get_op;

/*
**    ==== define my object ==================================================
*/

struct s_get_op
{
	t_m_get_op mm;
	t_d_get_op dd;
	t_u_get_op uu;
	t_argv argv;
	char **options;

};

/*
**    ==== prototype method ==================================================
*/


/*
**    ==== prototype debug ===================================================
*/

/*
**    ==== utils =============================================================
*/


/*
**    ==== prototype constructor =============================================
*/
t_get_op new_get_op(int ac, char** av);
t_argv get_option_proto(t_get_op argv);

#endif
