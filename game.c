/*!
 * \file game.c
 * \brief Game Function
 * \author Meyer Cyril
 */

#include <stdlib.h>
#include <stdio.h>

#include "color.h"

// All Function
#include "cdc.h"

/*!
 * \brief play round
 * \return score
 * \param the 3 dice value (sorted)
 */
int play(int d1, int d2, int d3)
{
	dices d;
	d.d1 = d1;
	d.d2 = d2;
	d.d3 = d3;
	
	int r = 0;
	
	if((r = cul_de_chouette(d)) != 0)
		return r;
	
	if((r = chouette_velute(d)) != -10000)
		return r;
	
	if((r = suite(d)) != 0)
		return r;
		
	if((r = velute(d)) != 0)
		return r;
	
	if((r = chouette(d)) != 0)
		return r;
		
	if((r = soufflette(d)) != 0)
		return r;
	
	// NEANT
	return 0;
}

/*!
 * \brief return the score
 * \return score (0 if not a cul de chouette)
 * \param dices
 */
int cul_de_chouette(dices d)
{
	if(d.d1 == d.d2 && d.d2 == d.d3)
	{
		printf(CBOLD CGRN"Cul de Chouette de %d"RESET"\n",d.d1);
		return (40+10*d.d1);
	}
	else
		return 0;
}

/*!
 * \brief return the score
 * \return score (-10000 if not a chouette velute)
 * \param dices
 */
int chouette_velute(dices d)
{
	int c = 0;		// chouette
	
	if(d.d1 == d.d2)
	{
		c = d.d1;
		
		if(c*2 == d.d3)
		{
			return chouette_velute_value(d, d.d3);
		}
	}
	
	return -10000;
}

/*!
 * \brief return the score
 * \return score
 * \param dices (it's a chouette velute)
 */
int chouette_velute_value(dices d, int c)
{
	int g = -1;
	printf(CBOLD CGRN"Chouette Velute de %d"RESET"\n",c);
	printf(CBOLD"- pas mou le caillou -"RESET"\n");
	while(g > 2 || g < 0)
	{
		printf("Premier ? (1 : Oui - 0 : Non - 2 : Egalité)\n");
		scanf("%d", &g);
	}
	if(g == 1)
	{
		return 2*c*c;
	}
	if(g == 0)
	{
		return 0;
	}
	if(g == 2)
	{
		return -2*c*c;
	}
	else	// Error	
		return -1;
}

/*!
 * \brief return the score
 * \return score (0 if not a velute)
 * \param dices
 */
int velute(dices d)
{
	if(d.d1 + d.d2 == d.d3)
	{
		printf(CBOLD CGRN"Velute de %d"RESET"\n",d.d3);
		return 2*d.d3;
	}
	else
		return 0;
}

/*!
 * \brief return the score
 * \return score (0 if not a suite)
 * \param dices
 */
int suite(dices d)
{
	int x = 0;
	int r = 0;
	if(d.d3-2 == d.d1 && d.d3-1 == d.d2)
	{
		if(d.d1 == 1)	// 1-2-3 (velute)
		{
			r += 18;
		}
		printf(CBOLD CGRN"Suite"RESET"\n");
		printf(CBOLD"- Grelotte ça picote -"RESET"\n");
		printf(CBOLD"- Sans fin est la moisissure des bières bretonnes -"RESET"\n");
		printf("Dernier ? (1 : Oui - X : Non)\n");
		scanf("%d", &x);
		
		if(x == 1)
		{
			r -= 10;
		}
	}
	
	return r;
}

/*!
 * \brief return the score
 * \return score (0 if not a soufflette)
 * \param dices
 */
int soufflette(dices d)
{
	int x = 0;
	
	if(d.d1 == 1 && d.d2 == 2 && d.d3 == 4)
	{
		printf(CBOLD CGRN"Soufflette"RESET"\n");
		while((x != -50) && (x != -40) && (x != -30) && (x != 30))
		{
			printf("Résultat : (-50, -40, -30, 30)\n");
			scanf("%d",&x);
		}
		return x;
	}
	return 0;
}

/*!
 * \brief return the score
 * \return score (0 if not a chouette)
 * \param dices
 */
int chouette(dices d)
{
	int c = 0;		// chouette
	int s = -1; 	// sirotage
	
	if(d.d1 == d.d2)
	{
		c = d.d1;
	}
	else if(d.d2 == d.d3)
	{
		c = d.d2;
	}
	
	if(c != 0)
	{
		printf(CBOLD CGRN"Chouette de %d"RESET"\n",c);
		while(s > 1 || s < 0)
		{
			printf(CBOLD CGRN"Siroter ? (0 : Non - 1 : Oui)"RESET"\n");
			scanf("%d", &s);
		}
		if(s == 0)
			return c*c;
		else
		{
			printf("Dé : \n");
			scanf("%d",&s);
			if(s == c)
				return (40+10*c);
			else
			{
				if(c == 6)
					printf(CBOLD CYEL"Civet"RESET"\n");
				return -(c*c);
			}
		}
	}
	return 0;
}

/*!
 * \brief grelottine
 * \return score
 */
int grelottine()
{
	int min_score = 0;
	int choice = 0;
	float mult = 0;
	int mise = 0;
	printf(CBOLD CYEL);
	printf("1. Chouette 33%%\n");
	printf("2. Velute 25%%\n");
	printf("3. Cul de Chouette 16%%\n");
	printf("4. Chouette Velute 8%%\n");
	printf(RESET"\n");
	printf("minimum score :\n");
	scanf("%d", &min_score);
	
	while(choice < 1 || choice > 4)
	{
		printf("combinaison (1-4)\n");
		scanf("%d",&choice);
	}
	if(choice == 1)
		mult = 0.33;
	else if(choice == 2)
		mult = 0.25;
	else if(choice == 3)
		mult = 0.16;
	else if(choice == 4)
		mult = 0.08;
		
	while(mise <= 0 || mise > (min_score*mult))
	{
		printf("Mise maximum : %d\n", (int)(min_score*mult));
		scanf("%d",&mise);
	}
	
	printf("Résultat : (1 gagner - 0 perdu)\n");
	scanf("%d",&choice);
	
	if(choice == 0)
		return -mise;
	else
		return mise;
	
	// useless
	return 0;
}

/*!
 * \brief mise sur un sirotage
 * \return score
 */
int mise_s()
{
	int s = 0;
	
	printf("Mise sur un sirotage : ");
	
	while(s <= 0 || s > 6)
	{
		scanf("%d",&s);
	}
	
	printf(CBOLD CYEL);
	printf("\nInformations Sirotage : ");
	if(s == 1)
		printf("Linotte (1)");
	if(s == 2)
		printf("Alouette (2)");
	if(s == 3)
		printf("Fauvette (3)");
	if(s == 4)
		printf("Mouette (4)");
	if(s == 5)
		printf("Bergeronnette (5)");
	if(s == 6)
		printf("Chouette (6)");
	printf(RESET"\n");
	
	printf("Résultat : (1 gagner - 0 perdu)\n");
	scanf("%d",&s);
	
	if(s == 0)
		return -5;
	else
		return 25;
		
}

/*!
 * \brief mise sur un défi
 * \return score
 */
int mise_d()
{
	int s;
	printf("Résultat : (1 gagner - 0 perdu)\n");
	scanf("%d",&s);
	
	if(s == 0)
		return -5;
	else
		return 25;
}

/*!
 * \brief Civet
 * \return score
 */
int civet()
{
	int v = 0, s = 0;
	while(v <= 0 || v > 102)
	{
		printf("Mise (0 < m < 103) : \n");
		scanf("%d",&v);
	}
	
	printf("Résultat : (1 gagner - 0 perdu)\n");
	scanf("%d",&s);
	
	if(s == 0)
		return -v;
	else
		return v;
}
