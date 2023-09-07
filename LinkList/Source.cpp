#include<stdio.h>


typedef struct node {
	//data field
	int data;
	//pointer field
	struct node* link;

}Node;

typedef struct singeList {
	Node* first;
		int num;
}SingleList;


int init(SingleList* L) {
	L->first = NULL;
	L->num = 0;
	return 1;
}

int Find(SingleList L, int i, Node* node) {
	Node* p;
	int ele;
	if (i <= -1 || i > L.num - 1) {
		return 0;
	}
	p = L.first;
	if (i != 1) {
		for (int j = 0; j < i; j++) {
			//迭代到目标位置，暂存node已经被替换成链表里面的node，在调用时，函数中应该有一个node用来存储需要查询的数据
			p = p->link;
		}
	}
	*node = *p;

}
int main() {
	SingleList singleList;
	init(&singleList);
	Node node1, node2;
	node1.data = 1;
	
	node2.data = 2;
	node1.link = &node2;
	singleList.first = &node1;
	singleList.num = 2;

	Node temp;
	Find(singleList, 1, &temp);
	printf_s("%d", temp.data);






	return 0;

}