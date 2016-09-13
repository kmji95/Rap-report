#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

double getRandomNumber(const double min, const double max)
{
	double temp = (double)rand() / (double)RAND_MAX;
	temp = min + (max - min)*temp;
	return temp;
}

bool isInsideCircle(const double x, const double y)
{
	const double x_c = 5.0;
	const double y_c = 3.0;


	const double f = (x - x_c)*(x - x_c) / 25 + (y - y_c)*(y - y_c) / 9;
	if (f > 1.0) return false;
	else return true;
}

void main()
{
	FILE *of = fopen("circle.txt", "w");
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10000; i++)
	{
		double x = getRandomNumber(0.0, 10.0);
		double y = getRandomNumber(0.0, 6.0);

		if (isInsideCircle(x, y) == true)
			fprintf(of, "%f,%f\n", x, y);
	}
}
