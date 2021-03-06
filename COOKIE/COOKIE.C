/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
::
:: COOKIE.C
::
:: CookieJar routines
::
:: [c] 2000 Reservoir Gods
::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/


/* ###################################################################################
#  INCLUDES
################################################################################### */

#include	"COOKIE.H"


/* ###################################################################################
#  CODE
################################################################################### */


/*-----------------------------------------------------------------------------------*
* FUNCTION : CookieJar_Exists()
* ACTION   : checks to see if cookie jar exits
* RETURNS  : 0 if cookie jar doesn't exist
*            1 if cookie jar exists
* CREATION : 06.00.99 PNK
*-----------------------------------------------------------------------------------*/

U8			CookieJar_Exists()
{
#ifndef	dGODLIB_PLATFORM_ATARI
	return( 0 );
#else
	U32	*	lpCookie;

	lpCookie = (U32*)dCOOKIEJAR_BASE;

	if( *lpCookie )
	{
		return(1);
	}
	else
	{
		return(0);
	}
#endif
}


/*-----------------------------------------------------------------------------------*
* FUNCTION : CookieJar_CookieExists( const U32 aCookie )
* ACTION   : checks to see if specified cookie is in the jar
* RETURNS  : 0 if cookie not found
*            1 if cookie found
* CREATION : 06.00.99 PNK
*-----------------------------------------------------------------------------------*/

U8			CookieJar_CookieExists( const U32 aCookie )
{
	if( CookieJar_GetpCookie(aCookie) )
	{
		return( 1 );
	}
	else
	{
		return( 0 );
	}
}


/*-----------------------------------------------------------------------------------*
* FUNCTION : CookieJar_GetpCookie( const U32 aCookie )
* ACTION   : returns a pointer to specified cookie or NULL if cookie not found
* CREATION : 06.00.99 PNK
*-----------------------------------------------------------------------------------*/

sCookie *	CookieJar_GetpCookie( const U32 aCookie )
{
	sCookie * lpCookie;

#ifndef	dGODLIB_PLATFORM_ATARI
	lpCookie = 0;
#else
	lpCookie = *(sCookie **)dCOOKIEJAR_BASE;
#endif

	if( lpCookie )
	{
		while( (lpCookie->mCookie) && (lpCookie->mCookie != aCookie) )
		{
			lpCookie++;
		}
		if( lpCookie->mCookie != aCookie )
		{
			lpCookie = 0L;
		}
	}

	return( lpCookie );
}


/*-----------------------------------------------------------------------------------*
* FUNCTION : CookieJar_GetCookie( const U32 aCookie )
* ACTION   : returns value of cookie aCookie ( or 0 if cookie not found )
* CREATION : 06.00.99 PNK
*-----------------------------------------------------------------------------------*/

U32			CookieJar_GetCookieValue( const U32 aCookie )
{
	sCookie *	lpCookie;
	U32			lValue;

	lpCookie = CookieJar_GetpCookie( aCookie );
	if( lpCookie )
	{
		lValue = lpCookie->mValue;
	}
	else
	{
		lValue = 0;
	}

	return( lValue );
}


/*-----------------------------------------------------------------------------------*
* FUNCTION : CookieJar_SetCookie( const U32 aCookie, const U32 aValue )
* ACTION   : sets value of cookie aCookie to aValue
*            if cookie not in jar, adds new cookie to end of jar
* CREATION : 06.00.99 PNK
*-----------------------------------------------------------------------------------*/

void		CookieJar_SetCookieValue( const U32 aCookie, const U32 aValue )
{
#ifdef	dGODLIB_PLATFORM_ATARI
	sCookie *	lpCookie;

	lpCookie = CookieJar_GetpCookie( aCookie );
	if( lpCookie )
	{
		lpCookie->mValue = aValue;
	}
	else
	{
		lpCookie = *(sCookie **)dCOOKIEJAR_BASE;
		if( lpCookie )
		{
			while( lpCookie->mCookie )
			{
				lpCookie++;
			}
			lpCookie->mCookie = aCookie;
			lpCookie->mValue  = aValue;
		}
	}
#else
	(void)aCookie;
	(void)aValue;
#endif
}


/* ################################################################################ */
