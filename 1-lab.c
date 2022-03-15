#include <stdio.h>
#include <malloc.h>

typedef struct Line {
	int n; 
	int* a; 
} Line;

typedef struct Matrix {
	int lines;
	Line* matr; 
} Matrix;

int getInt(int* a)
{
	int n;
	do {
		n = scanf_s("%d", a, sizeof(int));
		if (n < 0)
			return 0;
		if (n == 0)
		{
			printf("%s\n", "Error! Repeat input");
			scanf_s("%*c", 0);
		}
	} while (n == 0);
	return 1;
}

void erase(Matrix* a)
{
	int i;
	for (i = 0; i < a->lines; ++i)
		free(a->matr[i].a);
	free(a->matr);
	a->lines = 0;
	a->matr = NULL;
}

int input(Matrix* rm)
{
	const char* pr = "";
	int m;
	int i, j;
	int* p;

	do {
		printf("%s\n", pr);
		printf("Enter number of lines: --> ");

		pr = "You are wrong; repeat, please!";
		if (getInt(&m) == 0)
			return 0;

	} while (m < 1);
	rm->lines = m;
	
	rm->matr = (Line*)calloc(m, sizeof(Line));
	for (i = 0; i < rm->lines; ++i) {
		
		pr = "";
		do {
			printf("%s\n", pr);
			printf("Enter number of items in line %d: --> ", i + 1);
			pr = "You are wrong; repeat, please!";
			if (getInt(&m) == 0) {
				
				rm->lines = i;
				erase(rm);
				return 0;
			}
		} while (m < 1);
		rm->matr[i].n = m;
		
		p = (int*)malloc(sizeof(int) * m);
		rm->matr[i].a = p;
		
		printf("Enter items for matrix line #%d:\n", i + 1);
		for (j = 0; j < m; ++j, ++p)
			if (getInt(p) == 0) {
				
				rm->lines = i + 1;
				erase(rm);
				return 0;
			}
	}
	return 1;
}

void output(const char* msg, Matrix a)
{
	int i, j;
	int* p;
	printf("%s:\n\n", msg);
	for (i = 0; i < a.lines; ++i) {
		p = a.matr[i].a;
		for (j = 0; j < a.matr[i].n; ++j, ++p)
			printf("%d ", *p);
		printf("\n");
	}

}

void change(int a[], int m)
{
	int* first = NULL;
	int* last = NULL;
	int prev = *a, i = 0;

	for (; m-- > 0; ++a)
	{
		if ((*a > prev) && (i == 0))
		{
			first = a;
			i++;
		}
		if (*a < prev)
		{
			last = a;
		}
		prev = *a;
	}
	if ((first != NULL) && (last != NULL))
	{
		int change = *first;
		*first = *last;
		*last = change;
	}
}

void edit(Matrix pm)
{
	int i;
	for (i = 0; i < pm.lines; ++i)
		change(pm.matr[i].a, pm.matr[i].n);
}

int main()
{
	Matrix matr = { 0, NULL };
	if (input(&matr) == 0)
	{
		printf("%s\n", "End of file occured");
		return 1;
	}
	output("\nSource matrix", matr);
	edit(matr);
	output("\nNew matrix", matr);
	erase(&matr);
	return 0;

}