#include<stdio.h>
#include<stdlib.h>
//�����ڽӾ���

typedef struct mGraph{
	int** a;  //�ڽӾ���
	int n;  //ͼ�ĵ�ǰ������
	int e; //ͼ�ĵ�ǰ����
	int noEdge;  //��������ޱ�ʱ��ֵ
}mGraph;

typedef struct eNode {
	int adjVex;//�붥��u���ڽӵĶ���
	int w; //�ߵ�Ȩֵ
	struct eNode* nextArc;  //ָ����һ���߽ڵ�
}ENode;

typedef struct lGraph {
	int n;  //ͼ�ĵ�ǰ������
	int e;  //ͼ�ĵ�ǰ����
	ENode** a;  //ָ��һάָ������
}LGraph;

int Init(mGraph *mg , int nSize , int noEdgeValue) {
	mg->n = nSize;       //��ʼ��������
	mg->e = 0;    //��ʼ��ʱû�б�
	mg->noEdge = noEdgeValue; //��ʼ��û�б�ʱ��ȡֵ
	mg->a = (int**)malloc(nSize * sizeof(int*));   //���ɳ���Ϊn��һά����
	//�ڽӾ���Ϊ���򷵻�error
	if (!mg->a) {
		return 0;
	}
	//��̬���ɶ�ά����
	for (int i = 0; i < mg->n; i++) {
		mg->a[i] = (int*)malloc(nSize * sizeof(int));
		for (int j = 0; j < mg->n; j++) {
			mg->a[i][j] = mg->noEdge;
		}
		mg->a[i][i] = 0;
	}
	return 1;
}

//����ͼ
void Destroy(mGraph *mg) {
	for (int i = 0; i, mg->n; i++) {
		free(mg->a);
	}
	free(mg->a);
}

//�ߵ�����,���ñߵ�����������������
int Search(mGraph* mg, int u, int v) {
	if (u< 0 || v < 0 || u>mg->n - 1 || v>mg->n - 1 || u == v || mg->a[u][v] == mg->noEdge) {
		return 0;
	}
	return 1;
}

int Insert(mGraph *mg , int u , int v , int w) {
	if (u < 0|| v < 0||u>mg->n -1||v>mg->n -1 || u==v) {
		return 0;
	}
	if (mg->a[u][v] != mg->noEdge) {
		//����5��ʾ���ظ�Ԫ��
		return 5;
	} 
	mg->a[u][v] = mg->noEdge;
	mg->e--;
	return 1;
	}
	

//�ڽӱ��ʼ��

int Init(LGraph* lg, int nSize) {
	lg->n = nSize;
	lg->e = 0;
	lg->a = (ENode**)malloc(nSize * sizeof(ENode*));     //���ɳ���Ϊn��һάָ������
	if (!lg->a) {
		return 0;
	}
	else {
		for (int i = 0; i < lg->n; i++) {
			lg->a[i] = NULL;        //�ÿ�ָ������
			return 1;
		}
	}
	return 1;
}

//�ڽӱ�ĳ���

void Destroy(LGraph* lg) {
	int i;
	ENode* p, * q;
	for (i = 0; i < lg->n; i++) {
		p = lg->a[i];
		q = p;
		while (p) {
			p = p->nextArc;
			free(q);
			q = p;
		}
	}
	free(lg->a);
}

//�ڽӱ��бߵ�����

int Exist(LGraph* lg, int u, int v) {
	ENode* p;
	if (u < 0 || u > lg->n - 1 || v > lg->n - 1 || u == v) {
		return 0;
	}
	p = lg->a[u];
	while (p && p->adjVex != v ) {
		p = p -> nextArc;
	}
	if (!p) {
		return 0;
	}
	else {
		return 1;
	}
}

//�ߵĲ���

int Insert(LGraph *lg , int u , int v , int w) {
	ENode* p;
	if (u<0 || v < 0 || u > lg->n - 1 || v > lg->n - 1 || u == v) {
		return 0;
	}
	if (Exist(lg, u, v)) {
		return 5; //����5��ʾ���ظ�Ԫ��
	}
	p = (ENode*)malloc(sizeof(ENode));
	p->adjVex = v;
	p->w = w;
	p->nextArc = lg->a[u];
	lg->a[u] = p;
	lg->e++;
	return 1;
}

//�ڽӱ�ı��ɾ��
int Remove(LGraph* lg, int u, int v) {
	ENode* p, * q;
	if (u < 0 || v>0 || u > lg->n - 1 || v > lg->n - 1 || u == v) {
		return 0;

	}
	p = lg->a[u];
		q = NULL;
		while (p && p->adjVex != v) {
			q = p;
			p = p->nextArc;
		}
		if (!p) {
			return 4;  //����4��ʾԪ�ز�����
		}
		if (q) {
			q->nextArc = p->nextArc;
		}
		else {
			lg->a[u] = p->nextArc;      
		}
		free(p);
		lg->e--;
		return 1;
}

int main() {


	return 0;
}