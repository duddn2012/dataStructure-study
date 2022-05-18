/*
그래프의 구현
1. 인접 행렬
2. 인접 리스트 V
위의 두 가지 방법 중 인접 리스트를 통해 그래프를 구현해보자

기본적인 linkedlist의 기능을 구현하고,
그래프의 특성을 추가해보자.
*/

#include "Math.h"
#include "CoreFunction.h"
#include "Graph.h"

//vertex 정점
//link 링크
GraphNode* createNode(vertex vertex, GraphNode* link) {
	GraphNode* new_node;
	new_node = (GraphNode*)malloc(sizeof(GraphNode));
	if (new_node == NULL) {
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}
	new_node->vertex = vertex;
	new_node->link = link;
	return(new_node);
}

//phead : 리스트의 헤드포인터의 포인터
//p : 선행노드
//new_node : 삽입될 노드
void insertNode(GraphNode **phead, GraphNode* p, GraphNode* new_node) {	
	if (*phead == NULL) {	//공백 리스트인 경우
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) {	//첫 노드에 삽입하는 경우
		new_node->link = *phead;
		*phead = new_node;
	}
	else {	//p다음에 삽입
		new_node->link = p->link;
		p->link = new_node;
	}
	
}
void deleteNode(GraphNode** phead, GraphNode* p, GraphNode* removed) {
	if (p == NULL)
		*phead = (*phead)->link;
	else
		p->link = removed->link;
	free(removed);
}


void display_recur(GraphNode* head) {
	GraphNode* p = head;
	if (p != NULL) {
		printf("%d->", p->vertex);
		display_recur(p->link);
	}
}