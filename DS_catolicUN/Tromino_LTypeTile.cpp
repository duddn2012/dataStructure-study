/*
* //�����ڵ� ����

int main(void)
{
	int k = 0;		//���簢 ������ ũ��(k<=10)
	pivot pv;
	int pRow, pCol;	//Ÿ�Ϸ� ���� ���� ���� ��, �� ��ȣ

	scanf_s("%d", &k);	//k�� �Է�

	k = pow(2, k);

	//2^k * 2^k ���� ����
	board = (int**)malloc(sizeof(int*) * k);
	for (int i = 0; i < k; i++) {
		board[i] = (int*)malloc(sizeof(int) * k);
	}

	scanf_s("%d %d", &pRow, &pCol);	//Ÿ�Ϸ� ���� ���� ���� ��, �� ��ȣ �Է�
	pv.row = pRow - 1;
	pv.col = pCol - 1;

	board[pv.row][pv.col] = 0;	//���� ���� ���� 0���� ����

	//��ŷ�� �Ұ����� ��� - 1 ���, ���� �� ��� ���簢 ���� ���
	sol(k, 0, 0, pv);

	//���� ��ü ���
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < k; i++) {
		free(board[i]);
	}
	free(board);

	return 0;
}

*/


#include "Math.h"
#include "CoreFunction.h"
#include "Tromino_LTypeTile.h"


pivot sol(int length, int row, int col, pivot pv) {
	num++;
	int s = length / 2;
	int location = check(length, row, col, pv);	//ä�����ִ� ������ ã�´� ���� ��� ���� 1~4
	pivot p1, p2, p3, p4;

	p1.row = row + s - 1;
	p1.col = col + s - 1;
	p2.row = row + s - 1;
	p2.col = col + s;
	p3.row = row + s;
	p3.col = col + s - 1;
	p4.row = row + s;
	p4.col = col + s;

	//Ÿ���� �ִ� ��ġ�� ���� Ÿ�� ��ġ
	if (location == 1) {
		board[p2.row][p2.col] = num;
		board[p3.row][p3.col] = num;
		board[p4.row][p4.col] = num;
		p1 = pv;
	}
	else if (location == 2) {
		board[p1.row][p1.col] = num;
		board[p3.row][p3.col] = num;
		board[p4.row][p4.col] = num;
		p2 = pv;
	}
	else if (location == 3) {
		board[p1.row][p1.col] = num;
		board[p2.row][p2.col] = num;
		board[p4.row][p4.col] = num;
		p3 = pv;
	}
	else if (location == 4) {
		board[p1.row][p1.col] = num;
		board[p2.row][p2.col] = num;
		board[p3.row][p3.col] = num;
		p4 = pv;
	}

	if (length == 2) return pv;
	sol(s, row, col, p1);
	sol(s, row, col + s, p2);
	sol(s, row + s, col, p3);
	sol(s, row + s, col + s, p4);
	return pv;
}

int check(int sz, int row, int col, pivot pv) {
	if (pv.row < (row + sz / 2)) {
		if (pv.col < (col + sz / 2)) {
			return 1;
		}
		else {
			return 2;
		}
	}
	else {
		if (pv.col < (col + sz / 2)) {
			return 3;
		}
		else {
			return 4;
		}
	}

	return 0;
}