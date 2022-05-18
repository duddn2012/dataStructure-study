/*
그래프의 구현
1. 인접 행렬
2. 인접 리스트 V
위의 두 가지 방법 중 인접 리스트를 통해 그래프를 구현해보자

기본적인 linkedlist의 기능을 구현하고,
그래프의 특성을 추가해보자.
*/
#define MAX_VERTICES 50

typedef int vertex;	//정점은 int형으로 정의
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