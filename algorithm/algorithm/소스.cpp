#include<stdio.h>
#include<math.h>

int main()
{
	long double x0 = 4;
	long double y0 = 4;
	long double f;
	long double g;
	long double h = 1.0/1000.0;
	long double pfx;
	long double pfy;
	long double pgx;
	long double pgy;

	long double x1;
	long double y1;
	int i = 1;
	long double e = 1;
	long double e2 = 1;
	printf("반복수\t\tx0\t\t\ty0\t\t\tx1\t\ty1\t\t\t오차\n");

	for (i = 1; e>0.5*pow(10, -4); i++)
	{
		f = pow(x0, 2)*y0 + x0 - 186;
		g = pow(x0, 2) + x0*y0 + pow(y0, 2) - 91;
		pfx = ((pow(x0 + h, 2)*y0 + (x0 + h) - 186) - (pow(x0, 2)*y0 + x0 - 186)) / h;
		pfy = ((pow(x0, 2)*(y0 + h) + x0 - 186) - (pow(x0, 2)*y0 + x0 - 186)) / h;
		pgx = ((pow(x0 + h, 2) + (x0 + h)*y0 + pow(y0, 2) - 91) - (pow(x0, 2) + x0*y0 + pow(y0, 2) - 91)) / h;
		pgy = ((pow(x0, 2) + x0*(y0 + h) + pow(y0 + h, 2) - 91) - (pow(x0, 2) + x0*y0 + pow(y0, 2) - 91)) / h;
		printf("%lf\n%lf\n%lf\n%lf\n", pfx, pfy, pgx, pgy);
		x1 = x0 + (-f*pgy + pfy*g) / (pfx*pgy - pfy*pgx);
		y1 = y0 + (-pfx*g + pgx*f) / (pfx*pgy - pfy*pgx);
		e = fabs((x1 - x0) / x1);
		e2 = fabs((y1 - y0) / y1);

		printf(" %d \t\t%lf\t\t%lf\t\t%lf\t\t%lf\t\t%lf\t\t%lf\n", i, x0, y0, x1, y1, e, e2);
		x0 = x1;
		y0 = y1;
	}
}