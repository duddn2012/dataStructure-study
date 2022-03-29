/*
	최대부분배열 문제 알고리즘 별 함수

	//메인 실행 문
	int main(int argc)
{
	int n = 6000;
	double start, end;

	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 50 - 25; //-100~99
	}

	int Left = 0;
	int Right = n-1;
	int answer = 0;

	start = (double)clock() / (CLOCKS_PER_SEC);	//초단위

	//Algorithm 실행 함수
	answer = MaxSubarray1(arr, n);
	//answer = MaxSubarray2(arr, n);
	//answer = MaxSubarray3(arr, Left, Right);
	//answer = MaxSubarray4(arr, n);

	end = (((double)clock()) / (CLOCKS_PER_SEC));
	printf("알고리즘 1 n = %d개 실행시간 %.10f\n", n, end - start);


	printf("%d", answer);

	free(arr);

	return 0;
}
	
	
	*/

#include "Math.h"
#include "CoreFunction.h"
#include "MaxSubArray.h"

//Algorithm 1 O(n^3)
int MaxSubarray1(int A[], int n) {
	int MaxSum, ThisSum;
	int i, j, k;

	MaxSum = 0;

	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			ThisSum = 0;
			for (k = i; k <= j; k++)
				ThisSum = ThisSum + A[k];
			MaxSum = max(MaxSum, ThisSum);
		}
	}

	return MaxSum;
}

//Algorithm 2 O(n^2)
int MaxSubarray2(int A[], int n) {
	int MaxSum, ThisSum;
	int i, j;

	MaxSum = 0;
	for (i = 0; i < n; i++) {
		ThisSum = 0;
		for (j = i; j < n; j++) {
			ThisSum = ThisSum + A[j];
			MaxSum = max(MaxSum, ThisSum);
		}
	}
	return MaxSum;
}

//Algorithm 3 O(nlogn)
int MaxSubarray3(int A[], int Left, int Right) {
	int MaxSum, MaxLeft, MaxRight, MaxCenter;
	int MaxCenterL, MaxCenterR, ThisSum;
	int Center, i;

	if (Left == Right) {
		if (A[Left] > 0) return A[Left];
		else return 0;
	}

	Center = (Left + Right) / 2;
	MaxLeft = MaxSubarray3(A, Left, Center);
	MaxRight = MaxSubarray3(A, Center + 1, Right);

	MaxCenterL = 0;
	ThisSum = 0;
	for (i = Center; i >= Left; i--) {
		ThisSum = ThisSum + A[i];
		MaxCenterL = max(MaxCenterL, ThisSum);
	}

	MaxCenterR = 0;
	ThisSum = 0;
	for (i = Center; i <= Right; i++) {
		ThisSum = ThisSum + A[i];
		MaxCenterR = max(MaxCenterR, ThisSum);
	}

	MaxCenter = MaxCenterL + MaxCenterR;
	MaxSum = max(max(MaxLeft, MaxRight), MaxCenter);

	return MaxSum;
}

//Algorithm 4(n)
int MaxSubarray4(int A[], int n) {
	int MaxSum, ThisSum;
	int k;
	MaxSum = 0;
	ThisSum = 0;

	for (k = 0; k < n; k++) {
		ThisSum = max(ThisSum + A[k], 0);
		MaxSum = (MaxSum, ThisSum);
	}

	return MaxSum;
}