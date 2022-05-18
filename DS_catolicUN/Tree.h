/*
Ʈ���� ����
���� ����Ʈ�� ���� ����Ž��Ʈ���� �����غ���

�⺻���� linkedlist�� ����� �����ϰ�,
Ʈ���� Ư���� �߰��غ���.
*/

#define MAX_VERTICES 50

typedef int element;	//data�� int������ ����
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