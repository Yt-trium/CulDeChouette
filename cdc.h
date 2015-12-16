/*!
 * \file cdc.h
 * \brief Function & Struct
 * \author Meyer Cyril
 */

/*!
 * \struct dices
 * \brief dices structure
 *
 * The dices must be sorted
 */

typedef struct
{
	int d1;
	int d2;
	int d3;
} dices;

void printHelp();

int dice(int d);

void sort(int * d1, int * d2, int * d3);

int play(int d1, int d2, int d3);

int chouette(dices d);

int cul_de_chouette(dices d);

int chouette_velute(dices d);
int chouette_velute_value(dices d, int c);

int velute(dices d);

int suite(dices d);

int soufflette(dices d);

int grelottine();

int mise_s();

int mise_d();

int civet();
