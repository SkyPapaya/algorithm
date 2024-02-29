#include<iostream>
#include<queue>
#include<stack>
#include<stdlib.h>
#define ElemType int
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define Overflow 2
#define Underflow 3     //Overflow表示
#define NotPresent 4    //NotPresent表示元素不存在
#define Duplicate 5     //Duplicate表示有重复元素
typedef int Status;
int max_int = (1 << 31) - 1;
//邻接矩阵
typedef struct mGraph
{
    ElemType** a;       //邻接矩阵
    int n;              //图的当前顶点数
    int e;              //图的当前边数
    ElemType noEdge;    //两顶点间无边时的值
} MGraph;

//邻接表
typedef struct eNode {
    int adjVex;             //与任意顶点u相邻接的顶点
    ElemType w;             //边的权值
    struct eNode* nextArc;  //指向下一个边的节点
}ENode;

typedef struct lGraph {
    int n;      //图的当前顶点数
    int e;      //图的当前边数
    ENode** a;  //指向一维指针数组
}LGraph;

//树的队列节点
typedef struct queue {
    int* v;
    int size;
    int front;
    int rear;
}Queue;

//创建队列
void Create(Queue* queue, int size) {
    queue->v = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) queue->v[i] = -1;
    queue->front = queue->rear = 0;
    queue->size = size;
}

//是否为空
bool QueueIsEmpty(Queue* queue) {
    if (queue->front == queue->rear) return TRUE;
    return FALSE;
}

//入队
bool EnQueue(Queue* queue, int v) {
    if (v < 0) return ERROR;
    int place = (queue->front + 1) % queue->size;
    if (place == queue->rear) {
        return FALSE;
    }
    queue->v[place] = v;
    queue->front = place;
    return TRUE;
}

//出队列
int DeQueue(Queue* queue) {
    if (QueueIsEmpty(queue)) return -1;
    int place = (queue->rear + 1) % queue->size;
    int v = queue->v[place];
    queue->v[place] = -1;
    queue->rear = place;
    return v;
}

//输出队列中第一个节点的值
int Front(Queue* queue)
{
    int place = (queue->rear + 1) % queue->size;
    return queue->v[place];
}

//图的邻接矩阵的存储实现方法

//邻接矩阵初始化
Status Init(mGraph* mg, int nSize, ElemType noEdgeValue)
{
    int i, j;
    mg->n = nSize;  //初始化顶点数
    mg->e = 0;  //初始时没有边
    mg->noEdge = noEdgeValue;   //初始化没有边时的数值
    mg->a = new ElemType * [nSize];  //生成长度为n的一位指针数组
    if (!mg->a) return ERROR;
    for (i = 0; i < mg->n; i++) {
        mg->a[i] = new ElemType[nSize];
        for (j = 0; j < mg->n; j++) mg->a[i][j] = mg->noEdge;
        mg->a[i][i] = 0;
    }
    return OK;
}

//邻接矩阵的撤销
void Destroy(mGraph* mg)
{
    int i;
    for (i = 0; i < mg->n; i++)
        free(mg->a[i]);
    free(mg->a);
}

//邻接矩阵边的插入
Status Insert(mGraph* mg, int u, int v, ElemType w)
{
    if (u < 0 || u >= mg->n || v < 0 || v >= mg->n || u == v) return ERROR;
    if (mg->a[u][v] != mg->noEdge) return Duplicate;
    mg->a[u][v] = w;
    mg->e++;
    return OK;
}

//邻接矩阵删除边
Status Remove(mGraph* mg, int u, int v)
{
    if (u < 0 || u >= mg->n || v < 0 || v >= mg->n || u == v) return ERROR;
    if (mg->a[u][v] == mg->noEdge) return NotPresent;
    mg->a[u][v] = mg->noEdge;
    mg->e--;
    return OK;
}

//邻接矩阵是否有边
Status Exist(mGraph* mg, int u, int v)
{
    if (u < 0 || u >= mg->n || v < 0 || v >= mg->n || u == v) return ERROR;
    if (mg->a[u][v] == mg->noEdge) return NotPresent;
    return OK;
}

//图的邻接表的存储实现方法

//初始化
Status Init2(LGraph* lg, int nSize)
{
    int i;
    lg->n = nSize;  //初始化顶点数
    lg->e = 0;  //初始时没有边
    lg->a = new ENode * [nSize];  //生成长度为n的一位指针数组
    if (!lg->a) return ERROR;
    for (i = 0; i < lg->n; i++) {
        lg->a[i] = NULL;    //将指针数组a置空
    }
    return OK;
}

//邻接表的撤销
void Destroy2(LGraph* lg)
{
    int i;
    ENode* p, * q;
    for (i = 0; i < lg->n; i++) {
        p = lg->a[i];
        q = p;
        while (p) {
            q = p->nextArc;
            free(p);
            p = q;
        }
    }
    free(lg->a);
}

//邻接表边的搜索
Status Exist2(LGraph* lg, int u, int v)
{
    ENode* p;
    if (u < 0 || u >= lg->n || v < 0 || v >= lg->n || u == v) return ERROR;
    p = lg->a[u];
    while (p) {
        if (p->adjVex == v) return OK;
        p = p->nextArc;
    }
    return NotPresent;
}

//邻接表边的插入
Status Insert2(LGraph* lg, int u, int v, ElemType w)
{
    ENode* p;
    if (u < 0 || u >= lg->n || v < 0 || v >= lg->n || u == v) return ERROR;
    if (Exist2(lg, u, v) == 1) return Duplicate;
    p = (ENode*)malloc(sizeof(ENode));
    p->adjVex = v;
    p->w = w;
    p->nextArc = lg->a[u];
    lg->a[u] = p;
    lg->e++;
    return OK;
}

//邻接表边的删除
Status Remove2(LGraph* lg, int u, int v)
{
    ENode* p, * q;
    if (u < 0 || u >= lg->n || v < 0 || v >= lg->n || u == v) return ERROR;
    p = lg->a[u];
    q = NULL;
    while (p) {
        if (p->adjVex == v) {
            if (q) q->nextArc = p->nextArc;
            else lg->a[u] = p->nextArc;
            free(p);
            lg->e--;
            return OK;
        }
        q = p;
        p = p->nextArc;
    }
    return NotPresent;
}

//输出
void Output2(LGraph* lg)
{
    ENode* p;
    for (int i = 0; i < lg->n; i++)
    {
        p = lg->a[i];
        printf("%d ", i);
        while (p != NULL) {
            printf("-%d-> %d ", p->w, p->adjVex);
            p = p->nextArc;
        }
        printf("^\n");
    }
}

//深度优先遍历邻接表
void DFS(int v, int visited[], LGraph g)
{
    ENode* w;
    printf("%d ", v);   //访问定点v
    visited[v] = 1; //为顶点v打上访问标记
    for (w = g.a[v]; w; w = w->nextArc)
        if (!visited[w->adjVex])
            DFS(w->adjVex, visited, g);
}

void DFSGraph(LGraph g)
{
    int i;
    int* visited = (int*)malloc(g.n * sizeof(int));
    for (i = 0; i < g.n; i++) {
        visited[i] = 0;
    }
    for (i = 0; i < g.n; i++)
        if (!visited[i]) DFS(i, visited, g);
    printf("\n");
    free(visited);
}

//宽度优先遍历邻接表
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

int main() {
    //图的邻接矩阵测试
    printf("**********邻接矩阵**********\n\n");
    MGraph mg;
    ElemType noEdgeValue = -1;
    int nSize = 5;
    int i, j;
    Init(&mg, nSize, noEdgeValue);
    for (i = 0; i < nSize; i++) {
        for (j = 0; j < nSize; j++) {
            Insert(&mg, i, j, 10);
        }
    }
    for (i = 0; i < nSize; i++) {
        for (j = 0; j < nSize; j++) {
            printf("%d ", mg.a[i][j]);
        }
        printf("\n");
    }
    //图的邻接表测试
    printf("\n\n**********邻接表**********\n\n");
    LGraph lg;
    ElemType noEdgeValue2 = -1;
    int nSize2 = 6;
    Init2(&lg, nSize2);
    Insert2(&lg, 0, 1, 1);
    Insert2(&lg, 1, 3, 1);
    Insert2(&lg, 1, 0, 2);
    Insert2(&lg, 2, 4, 3);
    Insert2(&lg, 2, 1, 4);
    Insert2(&lg, 3, 4, 5);
    Insert2(&lg, 3, 2, 6);
    Insert2(&lg, 4, 5, 7);
    Insert2(&lg, 4, 1, 8);
    Insert2(&lg, 4, 0, 9);
    Insert2(&lg, 5, 1, 10);

    Output2(&lg);
    Remove2(&lg, 0, 1);
    printf("\n删除0->1后：\n");
    Output2(&lg);
    //深度优先遍历
    printf("\n深度优先遍历：\n");
    DFSGraph(lg);
    //宽度优先遍历
    printf("\n宽度优先遍历：\n");
    BFSGraph(lg);
    printf("\n");
    GetShortestPath(&lg, 1, 2);
    Destroy2(&lg);
    return 0;
}
