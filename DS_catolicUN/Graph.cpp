/*
�׷����� ����
1. ���� ���
2. ���� ����Ʈ V
���� �� ���� ��� �� ���� ����Ʈ�� ���� �׷����� �����غ���

�⺻���� linkedlist�� ����� �����ϰ�,
�׷����� Ư���� �߰��غ���.
*/

#include "Math.h"
#include "CoreFunction.h"
#include "Graph.h"

//vertex ����
//link ��ũ
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

//phead : ����Ʈ�� ����������� ������
//p : ������
//new_node : ���Ե� ���
void insertNode(GraphNode **phead, GraphNode* p, GraphNode* new_node) {	
	if (*phead == NULL) {	//���� ����Ʈ�� ���
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) {	//ù ��忡 �����ϴ� ���
		new_node->link = *phead;
		*phead = new_node;
	}
	else {	//p������ ����
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