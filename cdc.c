// ------------------------------
//       Cul De Chouette
//           V 1.0
// 
//       Meyer Cyril 2015
//
// ------------------------------
/*!
 * \file cdc.c
 * \brief Main Program.
 * \author Meyer Cyril
 * \version 1.0
 * Cul De Chouette
 */

#include <stdlib.h>
#include <stdio.h>

#include "color.h"

// All Function
#include "cdc.h"

int main(int argc, char ** argv)
{
	// Create and init vars
	
	int score = 0;			// Score player
	int d1, d2, d3;			// Dice 1,2,3
	int round = 0;
	
	if(argc > 1)
	{
		printHelp();
	}
	
	while(score < 343 && score > -343)
	{
		// Asking state
		d1 = getchar();	// Dice 1
		d2 = getchar();	// Dice 2
		d3 = getchar();	// Dice 3
		getchar();	    // ENTER
		
		// Printing
		printf("Dice 1 : %d\nDice 2 : %d\nDice 3 : %d\n",d1,d2,d3);
		
		
		
		if(dice(d1) && dice(d2) && dice(d3))
		{
			d1 -= 48;
			d2 -= 48;
			d3 -= 48;
			
			sort(&d1,&d2,&d3);
			
			printf("Dice 1 : %d\nDice 2 : %d\nDice 3 : %d\n",d1,d2,d3);
			
			round = play(d1,d2,d3);
		}
		
		score += round;
	}
	
	printf(CBOLD CRED"----- FIN -----\n"RESET);
	
	return 0;
}

/*!
 * \brief return 0 if d is not a dice value ( d < 1 OR d > 6 )
 * \return 0 : not a dice value / 1 : dice valid value
 * \param (d : dice value)
 */
int dice(int d)
{
	d -= 48;
	if(d<1 || d>6)
		return 0;
	else
		return 1;
}
