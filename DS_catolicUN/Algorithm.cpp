//#include "CoreFunction.h"
//#include "Algorithm.h"
//#include "MaxSubArray.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Algorithm.h"
#include "Graph.h"

int main(void)
{
	int a, b;
	float result = 0;

	scanf_s("%d %d", &a, &b);

	result = a / b;
	printf("%.9f", result);
	return 0;
}