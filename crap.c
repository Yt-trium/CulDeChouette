/*!
 * \file crap.c
 * \brief Crap Function
 * \author Meyer Cyril
 */

#include <stdlib.h>
#include <stdio.h>
#include "color.h"
#include "cdc.h"

/*!
 * \brief print the rules to play
 */
void printHelp()
{
	printf(CBOLD CRED"Standart :   xxx (x <= 6 && x > 0\n"RESET);
	printf(CBOLD CRED"Bévue :      ---\n"RESET);
	printf(CBOLD CRED"Grelottine : +++\n"RESET);
	printf(CBOLD CRED"Mise Sirot : ***\n"RESET);
	printf(CBOLD CRED"Mise Défi :  *+*\n"RESET);
	printf(CBOLD CRED"Set score :  ...\n"RESET);
	printf(CBOLD CRED"Civet  :     *-*\n"RESET);
}

/*!
 * \brief sort 3 pointer to int
 * \return void
 * \param the 3 pointer to int value
 * switch value without temporary value
 */
void sort(int * d1, int * d2, int * d3)
{
	if(*d1 > *d2)
	{
		*d1 = *d1 ^ *d2;
		*d2 = *d1 ^ *d2;
		*d1 = *d1 ^ *d2;
	}
	if(*d2 > *d3)
	{
		*d2 = *d2 ^ *d3;
		*d3 = *d2 ^ *d3;
		*d2 = *d2 ^ *d3;
	}
	if(*d1 > *d2)
	{
		*d1 = *d1 ^ *d2;
		*d2 = *d1 ^ *d2;
		*d1 = *d1 ^ *d2;
	}
}

/*!
 * \brief return 0 if d is not a dice value ( d < 1 OR d > 6 )
 * \return 0 : not a dice value / 1 : dice valid value
 * \param (d : dice value) keybord code
 */
int dice(int d)
{
	d -= 48;
	if(d<1 || d>6)
		return 0;
	else
		return 1;
}
