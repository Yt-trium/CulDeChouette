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
	printf(CRED"TODO\n"RESET);
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
