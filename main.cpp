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
#define Underflow 3     //Overflow��ʾ
#define NotPresent 4    //NotPresent��ʾԪ�ز�����
#define Duplicate 5     //Duplicate��ʾ���ظ�Ԫ��
typedef int Status;
int max_int = (1 << 31) - 1;
//�ڽӾ���
typedef struct mGraph
{
    ElemType** a;       //�ڽӾ���
    int n;              //ͼ�ĵ�ǰ������
    int e;              //ͼ�ĵ�ǰ����
    ElemType noEdge;    //��������ޱ�ʱ��ֵ
} MGraph;

//�ڽӱ�
typedef struct eNode {
    int adjVex;             //�����ⶥ��u���ڽӵĶ���
    ElemType w;             //�ߵ�Ȩֵ
    struct eNode* nextArc;  //ָ����һ���ߵĽڵ�
}ENode;

typedef struct lGraph {
    int n;      //ͼ�ĵ�ǰ������
    int e;      //ͼ�ĵ�ǰ����
    ENode** a;  //ָ��һάָ������
}LGraph;

//���Ķ��нڵ�
typedef struct queue {
    int* v;
    int size;
    int front;
    int rear;
}Queue;

//��������
void Create(Queue* queue, int size) {
    queue->v = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) queue->v[i] = -1;
    queue->front = queue->rear = 0;
    queue->size = size;
}

//�Ƿ�Ϊ��
bool QueueIsEmpty(Queue* queue) {
    if (queue->front == queue->rear) return TRUE;
    return FALSE;
}

//���
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

//������
int DeQueue(Queue* queue) {
    if (QueueIsEmpty(queue)) return -1;
    int place = (queue->rear + 1) % queue->size;
    int v = queue->v[place];
    queue->v[place] = -1;
    queue->rear = place;
    return v;
}

//��������е�һ���ڵ��ֵ
int Front(Queue* queue)
{
    int place = (queue->rear + 1) % queue->size;
    return queue->v[place];
}

//ͼ���ڽӾ���Ĵ洢ʵ�ַ���

//�ڽӾ����ʼ��
Status Init(mGraph* mg, int nSize, ElemType noEdgeValue)
{
    int i, j;
    mg->n = nSize;  //��ʼ��������
    mg->e = 0;  //��ʼʱû�б�
    mg->noEdge = noEdgeValue;   //��ʼ��û�б�ʱ����ֵ
    mg->a = new ElemType * [nSize];  //���ɳ���Ϊn��һλָ������
    if (!mg->a) return ERROR;
    for (i = 0; i < mg->n; i++) {
        mg->a[i] = new ElemType[nSize];
        for (j = 0; j < mg->n; j++) mg->a[i][j] = mg->noEdge;
        mg->a[i][i] = 0;
    }
    return OK;
}

//�ڽӾ���ĳ���
void Destroy(mGraph* mg)
{
    int i;
    for (i = 0; i < mg->n; i++)
        free(mg->a[i]);
    free(mg->a);
}

//�ڽӾ���ߵĲ���
Status Insert(mGraph* mg, int u, int v, ElemType w)
{
    if (u < 0 || u >= mg->n || v < 0 || v >= mg->n || u == v) return ERROR;
    if (mg->a[u][v] != mg->noEdge) return Duplicate;
    mg->a[u][v] = w;
    mg->e++;
    return OK;
}

//�ڽӾ���ɾ����
Status Remove(mGraph* mg, int u, int v)
{
    if (u < 0 || u >= mg->n || v < 0 || v >= mg->n || u == v) return ERROR;
    if (mg->a[u][v] == mg->noEdge) return NotPresent;
    mg->a[u][v] = mg->noEdge;
    mg->e--;
    return OK;
}

//�ڽӾ����Ƿ��б�
Status Exist(mGraph* mg, int u, int v)
{
    if (u < 0 || u >= mg->n || v < 0 || v >= mg->n || u == v) return ERROR;
    if (mg->a[u][v] == mg->noEdge) return NotPresent;
    return OK;
}

//ͼ���ڽӱ�Ĵ洢ʵ�ַ���
//��ʼ��
Status Init2(LGraph* lg, int nSize)
{
    int i;
    lg->n = nSize;  //��ʼ��������
    lg->e = 0;  //��ʼʱû�б�
    lg->a = new ENode * [nSize];  //���ɳ���Ϊn��һλָ������
    if (!lg->a) return ERROR;
    for (i = 0; i < lg->n; i++) {
        lg->a[i] = NULL;    //��ָ������a�ÿ�
    }
    return OK;
}

//�ڽӱ�ĳ���
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

//�ڽӱ�ߵ�����
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

//�ڽӱ�ߵĲ���
Status Insert2(LGraph* lg, int u, int v, int w)
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

//�ڽӱ�ߵ�ɾ��
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

//���
void Output2(LGraph* lg)
{
    ENode* p;
    for (int i = 0; i < lg->n; i++)
    {
        p = lg->a[i];
        printf("%d ", i);
        while (p != NULL) {
            printf("=%d-> %d ", p->w, p->adjVex);
            p = p->nextArc;
        }
        printf("|\n");
    }
}

//������ȱ����ڽӱ�
void DFS(int v, int visited[], LGraph g)
{
    ENode* w;
    printf("%d ", v);   //���ʶ���v
    visited[v] = 1; //Ϊ����v���Ϸ��ʱ��
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

//������ȱ����ڽӱ�
void BFS(int v, int visited[], LGraph g)
{
    ENode* w;
    Queue q;
    Create(&q, g.n);
    visited[v] = 1;
    printf("%d ", v);   //���ʶ���v
    EnQueue(&q, v); //���
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
    int* visited = (int*)malloc(g.n * sizeof(int));   //��̬����visited����
    for (i = 0; i < g.n; i++) {
        visited[i] = 0;
    }
    for (i = 0; i < g.n; i++) {
        if (!visited[i]) BFS(i, visited, g);
    }
    printf("\n");
    free(visited);
}

//Dijkstra�㷨
//�����Դ���㵽��������ĵ�Դ���·��
void shortestpath(LGraph* lg, int visited[], int distance[], int prenode[], int src) {
    int count = 0;//��¼ֱ����Դ�������Ķ������
    visited[src] = 1;//Դ���Ѿ���ӵ����·����
    distance[src] = 0;
    count++;
    //����ж����Դ��ֱ���������������þ���
    if (lg->a[src] != NULL) {
        ENode* p = lg->a[src];
        while (p != NULL) {
            distance[p->adjVex] = p->w;
            prenode[p->adjVex] = src;//��Щ�����ǰ������ΪԴ��
            p = p->nextArc;
        }
    }

    while (count <= lg->n) {
        int min = max_int;
        int target_node = 0;
        //������ʣ��ڵ���Ѱ�Ҿ������¼������·���Ķ��㣬�������һ��
        for (int i = 0; i < lg->n; i++) {
            if (visited[i] == 0 && min > distance[i]) {
                min = distance[i];
                target_node = i;
            }
        }
        visited[target_node] = 1;//����̾��붥��������·����
        count++;
        //���¼���Ķ���Ϊ�н飬����ʣ��δ�������·���Ķ���ľ���
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
        printf("ͼ�в����ڴ� %d �� %d ��·����\n", src, end);
        return NULL;
    }
    else {
        printf("���·������ : %d\n", distance[end]);
        printf("���·�� :(");
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
    //ͼ���ڽӾ������
    printf("�ڽӾ���:");
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
    //ͼ���ڽӱ����
    printf("�ڽӱ�:");
    LGraph lg;
    ElemType noEdgeValue2 = -1;
    int nSize2 = 6;
    Init2(&lg, nSize2);
    Insert2(&lg, 2, 1, 1);
    Insert2(&lg, 1, 3, 2);
    Insert2(&lg, 3, 4, 2);
    Insert2(&lg, 2, 4, 4);
    Insert2(&lg, 3, 1, 4);
    Insert2(&lg, 3, 3, 5);
    Insert2(&lg, 1, 1, 2);
    Insert2(&lg, 4, 4, 7);
    Insert2(&lg, 3, 4, 1);
    Insert2(&lg, 4, 1, 9);
    Insert2(&lg, 5, 1, 10);

    Output2(&lg);
    Remove2(&lg, 0, 1);
    printf("ɾ��0->1��");
    Output2(&lg);
    //������ȱ���
    printf("������ȱ�����");
    DFSGraph(lg);
    //������ȱ���
    printf("������ȱ�����");
    BFSGraph(lg);
    printf("\n");
    GetShortestPath(&lg, 1, 2);
    Destroy2(&lg);
    return 0;
}
