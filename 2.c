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
	const double x_c = 0.5;
	const double y_c = 0.5;
	const double r = 0.5;

	const double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;
	if (f > 0.0) return false;
	else return true;
}

bool isInsideCircle1(const double x, const double y)
{
	const double x_c = 2.5;
	const double y_c = 0.5;
	const double r = 0.5;

	const double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;
	if (f > 0.0) return false;
	else return true;
}

void main()
{
	FILE *of = fopen("circle.txt", "w");
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10000; i++)
	{
		double x = getRandomNumber(0.0, 1.0);
		double y = getRandomNumber(0.0, 1.0);

		if (isInsideCircle(x, y) == true)
			fprintf(of, "%f,%f\n", x, y);
	}


	for (int j = 0; j < 10000; j++)
	{
		double x1 = getRandomNumber(2.0, 3.0);
		double y1 = getRandomNumber(0.0, 1.0);

		if (isInsideCircle1(x1, y1) == true)
			fprintf(of, "%f,%f\n", x1, y1);
	}


	for (int k = 0; k < 10000; k++)
	{
		double x2 = getRandomNumber(1.0, 2.0);
		double y2 = getRandomNumber(0.3, 0.7);


		fprintf(of, "%f,%f\n", x2, y2);
	}

}
