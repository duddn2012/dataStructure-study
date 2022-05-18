/*
�⺻���� linkedlist�� ����� ����
*/
#define MAX_VERTICES 50

typedef int element;	//������ int������ ����
typedef struct LinkedNode {
	element data;
	LinkedNode* link;
}LinkedNode;

typedef struct GraphType {
	int n;
	LinkedNode* adj_list[MAX_VERTICES];
}GraphType;

LinkedNode* createNode(element data, LinkedNode* link);

void insertNode(LinkedNode** phead, LinkedNode* p, LinkedNode* new_node);

void deleteNode(LinkedNode** phead, LinkedNode* p, LinkedNode* removed);

/*
void printNode();
*/