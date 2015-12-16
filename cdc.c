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
#include <string.h>

#include "color.h"

// All Function
#include "cdc.h"

int main(int argc, char ** argv)
{
	// Create and init vars
	
	int score = 0;			// Score player
	int d1, d2, d3;			// Dice 1,2,3
	int round = 0;
	int defi = 0;
	
	if(argc > 1)
	{
		if(strcmp(argv[1], "-h") == 0)
			printHelp();
		else
			score = atoi(argv[1]);
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
			
			printf(CBOLD CBLU"%d - %d - %d"RESET"\n",d1,d2,d3);
			
			round = play(d1,d2,d3);
		}
		else if(d1 == '-')	// Bévue
		{
			if(score >= 0)
				round = -10;
			else
				round = 10;
		}
		else if(d1 == '+')	// Grelottine
		{
			defi = 1;
			round = grelottine();
		}
		else if(d1 == '*')	// Mise
		{
			defi = 1;
			if(d2 == '*')
				round = mise_s();
			else if(d2 == '-')
				round = civet();
			else 
				round = mise_d();
		}
		else if(d1 == '.')
		{
			printf("Set score : ");
			scanf("%d",&score);
		}
		else
		{
			round = 0;
			printf(CBOLD CRED"Erreur : Dés incorrecte"RESET"\n");
		}
		
		if(score+round > 332 && defi == 1)
		{
			if(score < 332)
				score = 332;
		}
		else
			score += round;
			
		printf(CBOLD CYEL"Score : %d"RESET"\n",score);
	}
	
	printf(CBOLD CRED"----- FIN -----"RESET"\n");
	
	return 0;
}
