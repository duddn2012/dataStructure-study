/*
트리의 구현
연결 리스트를 통해 이진탐색트리를 구현해보자

기본적인 linkedlist의 기능을 구현하고,
트리의 특성을 추가해보자.
*/

#define MAX_VERTICES 50

typedef int element;	//data는 int형으로 정의
typedef struct TreeNode {
	element key;
	struct TreeNode* rlink, *llink;
}TreeNode;

//TreeNode* createNode(element data, TreeNode* llink);


int compare(element e1, element e2);

void display(TreeNode* p);

TreeNode* search(TreeNode* root, element key);

void insertNode(TreeNode** phead, TreeNode* p, TreeNode* new_node);

void deleteNode(TreeNode** phead, TreeNode* p, TreeNode* removed);

/*
void printNode();
*/