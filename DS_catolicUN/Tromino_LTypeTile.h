//ä�����ִ� Ÿ���� �ε��� ���� ���� ����ü
typedef struct pivot {
	int row;
	int col;
}pivot;

int check(int sz, int row, int col, pivot pv);
pivot sol(int length, int row, int col, pivot pv);

int num = 0;
int** board = NULL;	//���簢 ���� 2���� �迭