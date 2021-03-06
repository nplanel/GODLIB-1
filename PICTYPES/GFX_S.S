**************************************************************************************
*	GFX_S.S
*
*	GFX rendering functions
*
*
*	[c] 2001 Reservoir Gods
**************************************************************************************

**************************************************************************************
;	EXPORTS / IMPORTS
**************************************************************************************


	export	PinkNote_Player

	export	PinkNote_NotePlayChannelA
	export	PinkNote_NotePlayChannelB
	export	PinkNote_NotePlayChannelC

	import	gPinkNoteChannel


**************************************************************************************
;	STRUCTS
**************************************************************************************

	OFFSET

oGfx_ID:			ds.l	1
oGfx_Version:		ds.w	1
oGfx_Width:			ds.w	1
oGfx_Height:		ds.w	1
oGfx_PlaneCount:	ds.b	1
oGfx_HasMaskFlag:	ds.b	1
oGfx_Pixels:		ds.w	1

	EVEN


**************************************************************************************
	TEXT
**************************************************************************************

*------------------------------------------------------------------------------------*
* FUNCTION : Gfx_Render( sGfx * apGfx, U16 * apScreen, 
* ACTION   : processes note data and plays YM sounds.
* CREATION : 04.02.01 PNK
*------------------------------------------------------------------------------------*

Gfx_Render:

	

	rts
