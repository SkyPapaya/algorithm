#include <stdio.h>
#include <stdlib.h>
#include<stddef.h>

typedef struct Node{

int element;
struct Node* link;
}Node;

typedef struct HeaderList{
    //头节点
    Node *head;
    //链表节点数量
    int num;
}HeaderList;

int Init(HeaderList *L){
L->head = (void*) 0;
L->num = 0;
return 1;

}



//index为需要查找的索引位置
int Find(HeaderList *L , int index , int* x){
    Node* p;
    int j;
    //要查询的位置超过列表长度
    if(index >= L->num - 1 || index < 0 ){
        printf("OutOfIndex");
        return 0;
    }
    //链表只能从头开始逐个查询
    p = L->head;
    for(int i = 0 ; i < index - 1 ; i++){
        p = p->link;
    }
    //循环结束，指针指向目标元素
    return p->element;
}



//index是要插入的位置，target为插入元素的值
int Insert(HeaderList* L , int index , int target){
//用来暂存数据
//不动态生成生命周期会出现问题
Node* temp = (Node*)malloc(sizeof(Node));
temp->element = target;
temp->link = (void*)0;
//指向索引位置的node
Node* indexNode;
 for(int i = 0 ; i < index - 1 ; i++){
        indexNode = indexNode->link;
    }
//对索引位置进行判断
   if(index >= L->num - 1 || index < 0 ){
        printf("OutOfIndex");
        return 0;
    }
//如果插入位置在头节点以后
if(index > 0){
    //新节点在索引节点之后
    temp->link = indexNode->link;
    //索引节点重新连接到插入后的后半段链表中
    indexNode->link = temp;
}else{
    //节点插入在头节点之前成为新的头节点
    temp->link = L->head;
    L->head = temp;
}
//插入成功后链表的长度要加一
L->num++;

    return 1;
}



//index是要删除的目标索引
int Delete(HeaderList* L , int index){
    //如果链表没有节点则删除失败
    if(L->num == 0){
        printf("List is empty");
        return 0;
    }
//对索引位置进行判断
   if(index >= L->num - 1 || index < 0 ){
        printf("OutOfIndex");
        return 0;
    }
    Node* before;
    Node* after;
    before = L->head;
    after = L->head;

     //如果删除的是头节点
        if (index == 0)
        {
            L->head = L->head->link;
        }
        

    //最后一个i是目标索引前一个
    //before是目标索引的前一个
    for(int i = 0 ; i < index - 1; i++){
        before = before->link;
    }
    //after是目标索引的后一个
    after = before->link->link;
    //删除目标元素
     free(before->link);
     L->num--;
    //让before的下一个变成after即可
    before->link = after;
   return 1;
}

int OutPut(HeaderList* L ){
    //链表为空则无法进行输出
    if(L->num == 0){
        printf("List is empty");
        return 0;
    }

    Node* tool;
    tool = L->head;
    for(int i = 0 ; i < L->num ; i++){
        printf("%d " , tool->element);
       tool = tool->link;
   return 1;
    }
}

void Destroy (HeaderList* L){
    Node* p;
    while (L->head){
        p=L->head->link;
        free(L->head);
        L->head=p;

    }
}

int Reversed(HeaderList* L){
     if(L->num == 0){
        printf("List is empty");
        return 0;
    }

    Node* temp1;
    Node* temp2;
    Node* tool;
    tool = L->head;
  while( !temp2 ){
       temp1->link->link = tool;
       tool = temp1->link; 
       temp1->link = temp2->link;
       temp2 = temp2->link->link;
    }
    temp1->link->link = tool;
    L->head = temp1->link;
    return 1;

}



// void bubbleSort(Node* n)
// {
//     if((n -> link == NULL) || (n -> link -> link == NULL))
//     {
//         return;
//     }
 
//     Node *head, * pre, * cur, *next, * end, * temp;
//     head = n;
//     end = NULL;
//     //从链表头开始将较大值往后沉
//     while(head -> link != end)
//     {
//         for(pre = head, cur = pre -> link, next = cur -> link; next != end; pre = pre -> link, cur = cur -> link, next = next -> link)
//         {
//             //相邻的节点比较
//             if(cur -> element > next -> element)
//             {
//                 cur -> link = next -> link;
//                 pre -> link = next;
//                 next -> link = cur;
//                 temp = next;
//                 next = cur;
//                 cur = temp;
//             }
//         }
//         end = cur;
//     }
// }

// typedef struct pNode{
//     int coef;
//     int exp;
//     struct pNode* link;
// }PNode;
// typedef struct polynominal{
//     PNode* head;

// }polynominal;


// void Creat(Polynominal *p){
      
// }
int main(){
  
    int i;
    int x;
    HeaderList headerList;
    Init(&headerList);
    for(int i = 0 ; i < 9 ; i++){
        Insert(&headerList , i , i+1);
    }
    OutPut(&headerList);
    printf_s("jj");





    return 0;
    
}

