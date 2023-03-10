#include <conio.h>
#include <stdio.h>

int n, R[9];
// n- dimensiunea tablei de sah, R[9] - pozitiile reginei pe tabla

int check(int x, int y)
{
	int i;
	for (i = 1; i < x; i++)
	{
		if ((R[i] == y) || (i - R[i] == x - y) || (i - x == y - R[i]))
		{
			y = y + 1;
			i = 0;
		}
	}
	if (y > n)
		return 0;
	else
		return y;
}

int main() {
	int i, conflict, solution_count = 0;
	n = 8;

	for (i = 1; i <= n; i++)
		R[i] = 1;
	i = 1;
	while (solution_count < 92)
	{
		for (; i <= n; i++)
		{
			conflict = check(i, R[i]);
			if (conflict != 0)
				R[i] = conflict;
			else
			{
				R[i] = 1;  // Seteaza pozitia curenta a reginei pe 1
				R[i - 1] = R[i - 1] + 1; // Incrementeaza pozitia reginei din pozitia anterioara
				i = i - 2; // Decrementeaza valoarea lui i cu 2
			}
		}

		//print the solution

		solution_count++;

		printf("Solution %d:\n", solution_count);
		for (i = 1; i <= n; i++)
		{
			for (conflict = 1; conflict <= n; conflict++)
			{
				if (conflict == R[i])
					printf("Q ");
				else
					printf("- ");
			}
			printf("\n");
		}
		printf("\n[");
		for (i = 1; i < n; i++)
			printf("%d, ", R[i]);
		printf("%d]", R[n]);
		getch();

		system("CLS");

		R[n] = R[n] + 1; // Incrementeaza pozitia ultimei regine
		i = n; // Seteaza i la ultima pozitie a tablei de sah


	}

}