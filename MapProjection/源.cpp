#include<stdio.h>
#include<stdlib.h>
//定义邻接矩阵

typedef struct mGraph{
	int** a;  //邻接矩阵
	int n;  //图的当前顶点数
	int e; //图的当前边数
	int noEdge;  //两顶点间无边时的值
}mGraph;

typedef struct eNode {
	int adjVex;//与顶点u像邻接的顶点
	int w; //边的权值
	struct eNode* nextArc;  //指向下一个边节点
}ENode;

typedef struct lGraph {
	int n;  //图的当前顶点数
	int e;  //图的当前边数
	ENode** a;  //指向一维指针数组
}LGraph;

int Init(mGraph *mg , int nSize , int noEdgeValue) {
	mg->n = nSize;       //初始化顶点数
	mg->e = 0;    //初始化时没有边
	mg->noEdge = noEdgeValue; //初始化没有边时的取值
	mg->a = (int**)malloc(nSize * sizeof(int*));   //生成长度为n的一维数组
	//邻接矩阵为空则返回error
	if (!mg->a) {
		return 0;
	}
	//动态生成二维数组
	for (int i = 0; i < mg->n; i++) {
		mg->a[i] = (int*)malloc(nSize * sizeof(int));
		for (int j = 0; j < mg->n; j++) {
			mg->a[i][j] = mg->noEdge;
		}
		mg->a[i][i] = 0;
	}
	return 1;
}

//撤销图
void Destroy(mGraph *mg) {
	for (int i = 0; i, mg->n; i++) {
		free(mg->a);
	}
	free(mg->a);
}

//边的搜索,利用边的两个顶点来搜索边
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
		//返回5表示有重复元素
		return 5;
	} 
	mg->a[u][v] = mg->noEdge;
	mg->e--;
	return 1;
	}
	

//邻接表初始化

int Init(LGraph* lg, int nSize) {
	lg->n = nSize;
	lg->e = 0;
	lg->a = (ENode**)malloc(nSize * sizeof(ENode*));     //生成长度为n的一维指针数组
	if (!lg->a) {
		return 0;
	}
	else {
		for (int i = 0; i < lg->n; i++) {
			lg->a[i] = NULL;        //置空指针数组
			return 1;
		}
	}
	return 1;
}

//邻接表的撤销

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

//邻接表中边的搜索

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

//边的插入

int Insert(LGraph *lg , int u , int v , int w) {
	ENode* p;
	if (u<0 || v < 0 || u > lg->n - 1 || v > lg->n - 1 || u == v) {
		return 0;
	}
	if (Exist(lg, u, v)) {
		return 5; //返回5表示有重复元素
	}
	p = (ENode*)malloc(sizeof(ENode));
	p->adjVex = v;
	p->w = w;
	p->nextArc = lg->a[u];
	lg->a[u] = p;
	lg->e++;
	return 1;
}

//邻接表的变的删除
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
			return 4;  //返回4表示元素不存在
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