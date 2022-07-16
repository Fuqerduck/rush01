#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


// Fonction d'affichage
void affichage (int grille[4][4])
{
	for (int i=0; i<4; i++)
	{
		for (int j=0; j<4; j++)
		{
			printf("%d ", grille[i][j]);
		}
		putchar('\n');
	}
	puts("------------------");
	puts("\n\n");
}

void	complete_1234(int grille[4][4], int row, int col, char dir)
{
	int	cur;

	cur = 1;
	if (dir == 'O')
		while (cur <= 4)
			grille[row][col--] = cur++;
	else if (dir == 'E')
		while (cur <= 4)
			grille[row][col++] = cur++;
	else if (dir == 'N')
		while (cur <= 4)
			grille[row--][col] = cur++;
	else if (dir == 'S')
		while (cur <= 4)
			grille[row++][col] = cur++;
}

void	row_col_4(int grille[4][4], int *vues)
{
	int	i;

	i = 0;
	while (vues[i] != '\0')
	{
		if (vues[i] == 4)
		{
			if (i >= 8)
			{
				if (i >= 12)
					complete_1234(grille, i % 4, 3, 'O');
				else
					complete_1234(grille, i % 4, 0, 'E');
			}
			else
			{
				if (i >= 4)
					complete_1234(grille, 3, i % 4, 'N');
				else
					complete_1234(grille, 0, i % 4, 'S');
			}
		}
		i++;
	}
}

int absentSurLigne (int k, int grille[4][4], int i)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		if (grille[i][j] == k)
			return (1);
		i++;
	}
	return (0);
}

int absentSurColonne (int k, int grille[4][4], int j)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grille[i][j] == k)
			return (1);
		i++;
	}
	return (0);
}

int estValide (int grille[4][4], int position)
{
	if (position == 4*4)
		return (0);

	int i = position/4, j = position%4;

	if (grille[i][j] != 0)
		return estValide(grille, ++position);

	for (int k=1; k <= 4; k++)
	{
		if (absentSurLigne(k,grille,i) == 0 && absentSurColonne(k,grille,j) == 0)
		{
			grille[i][j] = k;

			if ( estValide (grille, ++position) == 0)
				return (0);
		}
	}
	grille[i][j] = 0;

	return (1);
}

int main (void)
{
	/*  
		col1up      col2up      col3up      col4up 
		col1down    col2down    col3down    col4down 
		row1left    row2left    row3left    row4left 
		row1right   row2right   row3right   row4right
	*/
	int row_col[16] = {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};
	int grille[4][4] =
	{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	};

	printf("Grille avant\n");
	affichage(grille);

	row_col_4(grille, row_col);

	estValide(grille, 0);

	printf("Grille apres\n");
	affichage(grille);
}
