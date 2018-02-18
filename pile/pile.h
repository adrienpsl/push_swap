#ifndef PUSH_SWAP_PILE_H
#define PUSH_SWAP_PILE_H

/*
**    ==== define the type of my object ======================================
*/
typedef struct s_pile *t_pile;

/*
**    ==== methods ===========================================================
*/
typedef struct s_m_pile
{
	void (*destroy)(t_pile *);
} t_m_pile;


/*
**    ==== method debug ======================================================
*/
typedef struct s_d_pile
{
} t_d_pile;

/*
**    ==== utils =============================================================
*/
typedef struct s_u_pile
{

} t_u_pile;

/*
**    ==== define my object ==================================================
*/

struct s_pile
{
	t_m_pile mm;
	t_d_pile dd;
	t_u_pile uu;
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
t_pile new_pile();

#endif
