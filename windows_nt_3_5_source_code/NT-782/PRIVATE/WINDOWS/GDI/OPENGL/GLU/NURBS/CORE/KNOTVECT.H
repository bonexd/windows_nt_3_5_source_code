/**************************************************************************
 *									  *
 * 		 Copyright (C) 1992, Silicon Graphics, Inc.		  *
 *									  *
 *  These coded instructions, statements, and computer programs  contain  *
 *  unpublished  proprietary  information of Silicon Graphics, Inc., and  *
 *  are protected by Federal copyright law.  They  may  not be disclosed  *
 *  to  third  parties  or copied or duplicated in any form, in whole or  *
 *  in part, without the prior written consent of Silicon Graphics, Inc.  *
 *									  *
 **************************************************************************/

/*
 * knotvector.h - $Revision: 1.1 $
 */

#ifndef __KNOTVECTOR_H__
#define __KNOTVECTOR_H__

#include "types.h"

struct Knotvector { /* a knot vector */
			Knotvector( void );
			~Knotvector( void );
    void		init( long, long, long, INREAL * );
    int			validate( void );
    void 		show( char * );

    long		order;		/* order of spline  */
    long		knotcount;	/* number of knots  */
    long		stride;		/* bytes between points */
    Knot *		knotlist;	/* global knot vector */
};

/* tolerance to test knot coincidence */
#define TOLERANCE 		(REAL)10.0e-5

inline int 
identical( Knot x, Knot y )
{
    return ((x-y) < TOLERANCE) ? 1 : 0;
}
#endif /* __KNOTVECTOR_H__ */
