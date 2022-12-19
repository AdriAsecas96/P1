#include <iostream>

using namespace std;

unsigned int n, p_pos;
unsigned int score = 0;
unsigned char input = NULL;
bool game = true;

unsigned char oned[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

void printg()
{
	printf("===================================================================================================\n");
	printf("%s\n", oned);
	printf("===================================================================================================\n");
	printf("Choose action (a-d movement, s shoot):");
}

void update()
{
	if (oned[n - 1] != 'E' && oned[n - 2] != 'E')
	{
		oned[n - 1] = 'E';
	}

	for (int i = p_pos + 1; i < n; i++)
	{
		if (oned[i] == ' ' && oned[i + 1] == 'E')
		{
			oned[i] = 'E', oned[i + 1] = ' ';
		}
		if (oned[i] == 'o' && oned[i + 1] == 'E')
		{
			score++;
			oned[i] = ' ', oned[i + 1] = ' ';
		}
		if (oned[i] == 'o' && oned[i + 1] == ' ')
		{
			oned[i] = ' ', oned[i + 1] = 'o';
			i = i + 1;
		}
		if (oned[i] == 'A' && oned[i + 1] == 'E')
		{
			printf(" Game Over, your score is: %i\n", score);
			game = false;
		}
	}
}

void pinput()
{
	if (input == 'd')
	{
		if (oned[p_pos + 1] == 'E')
		{
			printf(" Game Over, your score is: %i\n", score);
			game = false;
		}
		if (oned[p_pos + 1] == 'o') {}
		else
		{
			oned[p_pos] = ' ';
			oned[++p_pos] = 'A';
		}
	}

	if (input == 'a')
	{
		if (p_pos == 0) {}
		else
		{
			oned[p_pos] = ' ';
			oned[--p_pos] = 'A';
		}
	}

	if (input == 's')
	{
		oned[p_pos + 1] = 'o';
	}
}

int main()
{
	n = sizeof(oned) / sizeof(oned[0]);

	oned[p_pos = 10] = 'A';
	oned[n - 1] = 'E';
	unsigned int irand = 0;	

	while (game)
	{
		pinput();		

		update();

		if (game == false) { break; }

		printg();
		
		std::cin >> input;
		printf("\n");
	}
}
/*
	Aún estoy aprendiendo las bases de c++
	por lo que me disculpo de ante mano si hay algo que haga daño a la vista
*/