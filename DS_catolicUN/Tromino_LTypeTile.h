//채워져있는 타일의 인덱스 값을 담을 구조체
typedef struct pivot {
	int row;
	int col;
}pivot;

int check(int sz, int row, int col, pivot pv);
pivot sol(int length, int row, int col, pivot pv);

int num = 0;
int** board = NULL;	//정사각 보드 2차원 배열