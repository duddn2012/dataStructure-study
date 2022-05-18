/*
트리의 구현
연결 리스트를 통해 그래프를 구현해보자

기본적인 linkedlist의 기능을 구현하고,
트리의 특성을 추가해보자.
*/

#include "Math.h"
#include "CoreFunction.h"
#include "Tree.h"
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int compare(element e1, element e2) {
	if (e1 == e2)return 0;
	else if (e1 > e2)return 1;
	else return -1;
}

void display(TreeNode* p) {
	if (p != NULL) {
		printf("(");
		display(p->llink);
		printf("%d", p->key);
		display(p->rlink);
		printf(")");
	}
}

TreeNode* search(TreeNode* root, element key) {
	TreeNode* p = root;
	while (p != NULL) {
		switch (compare(key, p->key)) {
		case -1:
			p = p->llink;
			break;
		case 0:
			return p;
		case 1:
			p = p->rlink;
			break;
		}
	}
	return p;
}

//실제로 사용되지는 않음 (연습용 함수)
TreeNode* createNode(element data, TreeNode* llink, TreeNode* rlink) {
	TreeNode* new_node;
	new_node = (TreeNode*)malloc(sizeof(TreeNode));
	if (new_node == NULL) {
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}
	new_node->key = data;
	new_node->llink = llink;
	new_node->rlink = rlink;
	return(new_node);
}

//phead : 리스트의 헤드포인터의 포인터
//p : 선행노드
//new_node : 삽입될 노드
void insertNode(TreeNode** root, int key) {
	TreeNode* p, * t;	//p는 부모노드. t는 현재노드
	TreeNode* n;		//n은 새로운 노드

	t = *root;
	p = NULL;

	while (t != NULL) {
		if (compare(key, t->key)==0) return;
		p = t;
		if (compare(key, t->key) <0 ) t = t->llink;
		else t = t->rlink;
	}

	n = (TreeNode*)malloc(sizeof(TreeNode));
	if (n == NULL) return;

	n->key = key;
	n->llink = n->rlink = NULL;

	if (p != NULL)
		if (compare(key, t->key) < 0)
			p->llink = n;
		else p->rlink = n;
	else *root = n;
}

void deleteNode(TreeNode** root, element key) {
	TreeNode* p, * child, * succ, * succ_p, * t;
	//key를 갖는 노드 t를 탐색, p는 t의 부모노드
	p = NULL;
	t = *root;
	while (t != NULL && compare(t->key, key) != 0) {
		p = t;
		t = (compare(key, t->key) < 0) ? t->llink : t->rlink;
	}

	if (t == NULL) {
		printf("key is not in the tree");
		return;
	}

	//단말 노드인 경우
	if ((t->llink == NULL) && (t->rlink == NULL)) {
		if (p != NULL) {
			if (p->llink == t)
				p->llink = NULL;
			else p->rlink = NULL;
		}
		else
			*root = NULL;
	}
	//하나의 자식만 가지는 경우
	else if ((t->llink == NULL) || (t->rlink == NULL)) {
		child = (t->llink != NULL) ? t->llink : t->rlink;
		if (p != NULL) {
			if (p->llink == t)
				p->llink = child;
			else p->rlink = child;
		}
		else
			*root = child;
	}
	else {	//두 개의 자식을 가지는 경우 
		//오른쪽 서브트리에서 후속자를 찾는다.
		succ_p = t;
		succ = t->rlink;
		//후속자를 찾아서 계속 왼쪽으로 이동한다.
		while (succ->llink != NULL) {
			succ_p = succ;
			succ = succ->llink;
		}
		//후속자의 부모와 자식을 연결
		if (succ_p->llink == succ)
			succ_p->llink = succ->rlink;
		else
			succ_p->rlink = succ->rlink;
		//후속자를 현재 노드로 이동한다.
		t->key = succ->key;
		t = succ;
	}
	free(t);
}

void display_recur(TreeNode* head) {
	TreeNode* p = head;
	if (p != NULL) {
		printf("%d->", p->key);
		display_recur(p->llink);
	}
}