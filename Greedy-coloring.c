#define _CRT_SECURE_NO_WARNINGS

//**//
// VS-17
// Maxim_Dostra_205669088
//**//

//Libraries
#include  <stdio.h>
#include  <stdlib.h>

//Stract
typedef struct Intervals
{
	int start;
	int end;
	int Degree;
	int comp_Degree;
	int color;
}Intervals;

//Function
void GreedyColoring()
{
	int k, i, j;
	int edges = 0, Max_color = 0;
	int Max_Degree = 0, Min_Degree = 0;
	int Max_Copm_Degree = 0, Min_Comp_Degree = 0;
	Intervals *Arr, temp;

	printf("Please input k: ");
	scanf("%d", &k);

	Arr = (Intervals *)malloc(k * sizeof(Intervals *)); //Array

	printf("You will now be asked to insert a family of %d intervals: \n", k);

	for (i = 0; i < k; i++) //scanf
	{
		printf("%dth Interval: ", (i + 1));
		scanf("%d %d", &Arr[i].start, &Arr[i].end);
	}

	printf("The itervals family is: \n");
	for (i = 0; i < k; i++) //print intervals family
	{
		printf("[%d,%d]", Arr[i].start, Arr[i].end);
		Arr[i].color = 1;
		if (i != k-1)
			printf(",");
	}

	for (i = 0; i < k - 1; i++) //Sorting
	{
		for (j = 0; j < k - i - 1; j++)
		{
			if (Arr[j].start > Arr[j + 1].start)
			{
				temp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = temp;
			}
		}
	}
	printf("\n");

	for (i = 0; i < k; i++) //edges
	{
		for (j = i + 1; j < k; j++) {
			if (Arr[i].end >= Arr[j].end || (Arr[i].end >= Arr[j].start && Arr[i].end <= Arr[j].end))
			{
				edges++;
			}
		}
	}

	for (i = 0; i < k; i++) //Degree & coloring
	{
		Arr[i].Degree = 0;
		for (j = 0; j < k; j++)
		{
			if (j > i)
			{
				if (Arr[i].end >= Arr[j].end || (Arr[i].end >= Arr[j].start && Arr[i].end <= Arr[j].end))
				{
					Arr[i].Degree++;
					if (Arr[i].color == Arr[j].color)
						Arr[j].color++;
				}
			}
			if (j < i)
			{
				if (Arr[j].end >= Arr[i].end || (Arr[j].end >= Arr[i].start && Arr[j].end <= Arr[i].end))
				{
					Arr[i].Degree++;
					if (Arr[i].color == Arr[j].color)
						Arr[i].color++;
				}
			}
		}
	}

	printf("G Edges = %d \n", edges);

	Min_Degree = Arr[0].Degree;
	for (i = 0; i < k; i++) //Min & Max
	{
		if (Arr[i].Degree > Max_Degree)
			Max_Degree = Arr[i].Degree;

		if (Arr[i].Degree < Min_Degree)
			Min_Degree = Arr[i].Degree;

		if (Arr[i].color > Max_color)
			Max_color = Arr[i].color;
	}

	printf("Maximum Degree of G = %d \n", Max_Degree);
	printf("Minimum Degree of G = %d \n", Min_Degree);
	printf("Chromatic Number of G = %d \n", Max_color);
	printf("G's Complement Edges = %d \n", ((k*(k - 1)) / 2) - (edges));
	printf("Maximum Degree of G Complement = %d \n", (k - Min_Degree - 1));
	printf("Minimum Degree of G Complement = %d \n", (k - Max_Degree - 1));

	printf("Optional Coloring: ");
	for (i = 1; i <= Max_color; i++) //Print optional coloring: 
	{
		printf("{");
		for (j = 0; j < k; j++)
		{
		if (Arr[j].color == i)
		printf("[%d,%d]", Arr[j].start, Arr[j].end);
		}
		printf("} = %d, ", i);
	}
	printf("\n");
	free(Arr);
}

//Main - VS-17
void main()
{
	GreedyColoring();
	system("PAUSE");
}