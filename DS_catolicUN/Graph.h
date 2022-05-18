/*
�׷����� ����
1. ���� ���
2. ���� ����Ʈ V
���� �� ���� ��� �� ���� ����Ʈ�� ���� �׷����� �����غ���

�⺻���� linkedlist�� ����� �����ϰ�,
�׷����� Ư���� �߰��غ���.
*/
#define MAX_VERTICES 50

typedef int vertex;	//������ int������ ����
typedef struct GraphNode {
	vertex vertex;
	GraphNode* link;
}GraphNode;

typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

GraphNode* createNode(vertex vertex, GraphNode* link);

void insertNode(GraphNode** phead, GraphNode* p, GraphNode* new_node);

void deleteNode(GraphNode** phead, GraphNode* p, GraphNode* removed);

/*
void printNode();
*/