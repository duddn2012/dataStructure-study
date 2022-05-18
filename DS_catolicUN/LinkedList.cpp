/*
기본적인 linkedlist의 기능을 구현
*/

#include "Math.h"
#include "CoreFunction.h"
#include "LinkedList.h"

//vertex 정점
//link 링크
LinkedNode* createNode(element vertex, LinkedNode* link) {
	LinkedNode* new_node;
	new_node = (LinkedNode*)malloc(sizeof(LinkedNode));
	if (new_node == NULL) {
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}
	new_node->data = vertex;
	new_node->link = link;
	return(new_node);
}

//phead : 리스트의 헤드포인터의 포인터
//p : 선행노드
//new_node : 삽입될 노드
void insertNode(LinkedNode** phead, LinkedNode* p, LinkedNode* new_node) {
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
void deleteNode(LinkedNode** phead, LinkedNode* p, LinkedNode* removed) {
	if (p == NULL)
		*phead = (*phead)->link;
	else
		p->link = removed->link;
	free(removed);
}


void display_recur(LinkedNode* head) {
	LinkedNode* p = head;
	if (p != NULL) {
		printf("%d->", p->data);
		display_recur(p->link);
	}
}