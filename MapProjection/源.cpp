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

//树的队列节点
typedef struct queue {
	int* v;
	int maxSize;
	int front;
	int rear;
}Queue;

void Create(Queue * queue, int size) {
	queue->v = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) queue->v[i] = -1;
	queue->front = queue->rear = 0;
	queue->maxSize = size;
}

//是否为空
bool QueueIsEmpty(Queue* queue) {
	if (queue->front == queue->rear) return true;
	return false;
}

//入队
bool EnQueue(Queue* queue, int v) {
	if (v < 0) return false;
	int place = (queue->front + 1) % queue->maxSize;
	if (place == queue->rear) {
		return false;
	}
	queue->v[place] = v;
	queue->front = place;
	return true;
}

//出队列
int DeQueue(Queue* queue) {
	if (QueueIsEmpty(queue)) return -1;
	int place = (queue->rear + 1) % queue->maxSize;
	int v = queue->v[place];
	queue->v[place] = -1;
	queue->rear = place;
	return v;
}

//输出队列中第一个节点的值
int Front(Queue* queue)
{
	int place = (queue->rear + 1) % queue->maxSize;
	return queue->v[place];
}

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

//邻接表的边的删除
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


//图的深度优先遍历
void DFS(int v, int visited[], LGraph g) {
	ENode* w;
	//访问节点
	printf("%d", v); 
	//为节点打上标记
	visited[v] = 1; 
	for (w = g.a[v]; w; w = w->nextArc) {
		//如果v没有被访问就递归调用DFS
		if (!visited[w->adjVex]) {
			DFS(w->adjVex, visited, g);

		}
	}
}
void DFSGraph(LGraph g) {
	int i;
	int* visited = (int*)malloc(g.n * sizeof(int));
	//初始化访问数组
	for (i = 0; i < g.n; i++) {
		visited[i] = 0;
	}
	for (i = 0; i < g.n; i++) {
		if (!visited[i]) {
			DFS(i, visited, g);
		}
		free(visited);
	}

}

void BFS(int v, int visited[], LGraph g)
{
	ENode* w;
	Queue q;
	Create(&q, g.n);
	visited[v] = 1;
	printf("%d ", v);   //访问定点v
	EnQueue(&q, v); //入队
	while (!QueueIsEmpty(&q)) {
		v = DeQueue(&q);
		for (w = g.a[v]; w; w = w->nextArc) {
			if (!visited[w->adjVex]) {
				visited[w->adjVex] = 1;
				printf("%d ", w->adjVex);
				EnQueue(&q, w->adjVex);
			}
		}
	}
}

void BFSGraph(LGraph g) {
	int i;
	int* visited = (int*)malloc(g.n * sizeof(int));   //动态生成visited数组
	for (i = 0; i < g.n; i++) {
		visited[i] = 0;
	}
	for (i = 0; i < g.n; i++) {
		if (!visited[i]) BFS(i, visited, g);
	}
	printf("\n");
	free(visited);
}

//Dijkstra算法
//计算从源顶点到其他顶点的单源最短路径
void shortestpath(LGraph* lg, int visited[], int distance[], int prenode[], int src) {
	int count = 0;//记录直接与源点相连的顶点个数
	visited[src] = 1;//源点已经添加到最短路径中
	distance[src] = 0;
	count++;
	//如果有顶点和源点直接相连，另外设置距离
	if (lg->a[src] != NULL) {
		ENode* p = lg->a[src];
		while (p != NULL) {
			distance[p->adjVex] = p->w;
			prenode[p->adjVex] = src;//这些顶点的前驱顶点为源点
			p = p->nextArc;
		}
	}

	while (count <= lg->n) {
		int min = max_int;
		int target_node = 0;
		//首先在剩余节点中寻找距离最新加入最短路径的顶点，最近的那一个
		for (int i = 0; i < lg->n; i++) {
			if (visited[i] == 0 && min > distance[i]) {
				min = distance[i];
				target_node = i;
			}
		}
		visited[target_node] = 1;//将最短距离顶点加入最短路径中
		count++;
		//已新加入的顶点为中介，更新剩余未加入最短路径的顶点的距离
		if (lg->a[target_node] != NULL) {
			ENode* p = lg->a[target_node];
			while (p) {
				if (visited[p->adjVex] == 0 && distance[target_node] + p->w < distance[p->adjVex]) {
					distance[p->adjVex] = distance[target_node] + p->w;
					prenode[p->adjVex] = target_node;
				}
				p = p->nextArc;
			}
		}
	}
}
int max_int = 9999999;
int* GetShortestPath(LGraph* g, int src, int end) {
	int visited[g->n];
	int distance[g->n];
	int prenode[g->n];
	int path[g->n];
	for (int i = 0; i < g->n; i++) {
		visited[i] = 0;
		distance[i] = max_int;
		prenode[i] = -1;
		path[i] = -1;
	}
	shortestpath(g, visited, distance, prenode, src);
	int target = end;
	int i = 1;
	path[0] = end;
	while (prenode[target] != -1) {
		path[i] = prenode[target];
		target = prenode[target];
		i++;
	}
	if (distance[end] >= max_int) {
		printf("图中不存在从 %d 到 %d 的路径！\n", src, end);
		return NULL;
	}
	else {
		printf("最短路径长度 : %d\n", distance[end]);
		printf("最短路径 :(");
		for (int i = g->n - 1; i >= 0; i--) {
			if (path[i] != -1) {
				printf("%d", path[i]);
				if (i != 0) printf(", ");
				else printf(")");
			}
		}
		printf("\n");
		return path;
	}
}
/*
int main() {


	return 0;
}