/*
�⺻���� linkedlist�� ����� ����
*/

#include "Math.h"
#include "CoreFunction.h"
#include "LinkedList.h"

//vertex ����
//link ��ũ
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

//phead : ����Ʈ�� ����������� ������
//p : ������
//new_node : ���Ե� ���
void insertNode(LinkedNode** phead, LinkedNode* p, LinkedNode* new_node) {
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