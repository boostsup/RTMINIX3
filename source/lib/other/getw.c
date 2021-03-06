/*
 * getw - read a word from a stream
 */
/* $Header: /cvsup/minix/src/lib/other/getw.c,v 1.1.1.1 2005/04/21 14:56:27 beng Exp $ */

#include	<stdio.h>

_PROTOTYPE(int getw, (FILE *stream ));

int getw(stream)
register FILE *stream;
{
	register int cnt = sizeof(int);
	int w;
	register char *p = (char *) &w;

	while (cnt--) {
		*p++ = getc(stream);
	}
	if (feof(stream) || ferror(stream)) return EOF;
	return w;
}
