/*
Ʈ���� ����
���� ����Ʈ�� ���� �׷����� �����غ���

�⺻���� linkedlist�� ����� �����ϰ�,
Ʈ���� Ư���� �߰��غ���.
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

//������ �������� ���� (������ �Լ�)
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

//phead : ����Ʈ�� ����������� ������
//p : ������
//new_node : ���Ե� ���
void insertNode(TreeNode** root, int key) {
	TreeNode* p, * t;	//p�� �θ���. t�� ������
	TreeNode* n;		//n�� ���ο� ���

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
	//key�� ���� ��� t�� Ž��, p�� t�� �θ���
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

	//�ܸ� ����� ���
	if ((t->llink == NULL) && (t->rlink == NULL)) {
		if (p != NULL) {
			if (p->llink == t)
				p->llink = NULL;
			else p->rlink = NULL;
		}
		else
			*root = NULL;
	}
	//�ϳ��� �ڽĸ� ������ ���
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
	else {	//�� ���� �ڽ��� ������ ��� 
		//������ ����Ʈ������ �ļ��ڸ� ã�´�.
		succ_p = t;
		succ = t->rlink;
		//�ļ��ڸ� ã�Ƽ� ��� �������� �̵��Ѵ�.
		while (succ->llink != NULL) {
			succ_p = succ;
			succ = succ->llink;
		}
		//�ļ����� �θ�� �ڽ��� ����
		if (succ_p->llink == succ)
			succ_p->llink = succ->rlink;
		else
			succ_p->rlink = succ->rlink;
		//�ļ��ڸ� ���� ���� �̵��Ѵ�.
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