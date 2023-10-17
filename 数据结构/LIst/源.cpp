#include <stdio.h>
#include <stdlib.h>
#include<stddef.h>

typedef struct Node {
    int element;
    struct Node* link;
}Node;

typedef struct HeaderList {
    //头节点
    Node* head;
    //链表节点数量
    int num;
}HeaderList;

typedef struct PolynomialNode {
    // 系数
    int coefficient; 
    // 指数
    int exponent;    
    struct PolynomialNode* next;
} PolynomialNode;

typedef struct {
    double coefficient; // 系数
    char variable;      // 字母变量
    int exponent;       // 指数
} Term;

// 定义多项式的结构
typedef struct {
    int num_terms; // 多项式中的项数
    Term* terms;   // 多项式的项数组
} Polynomial;

int Init(HeaderList* L ) {
    L->head = NULL;
    L->num = 0;
    return 1;

}



//index为需要查找的索引位置
int Find(Node* L, int index) {
    Node* p;
    int j;
    //要查询的位置超过列表长度
    
    //链表只能从头开始逐个查询
    p = L;
    for (int i = 0; i < index - 1; i++) {
        p = p->link;
    }
    //循环结束，指针指向目标元素
    return p->element;
}


//index是要插入的位置，target为插入元素的值
int Insert(Node* node, int index, int target) {

   
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return 0;
    }
    temp->element = target;

        Node* prev = NULL;
        Node* current = node;
        for (int i = 0; i < index; i++) {
            prev = current;
            current = current->link;
        temp->link = current;
        prev->link = temp;
    }

    return 1;
}

int Delete(Node* node, int index) {
    Node* before;
    Node* after;
    before = node;
    after = node;

    //如果删除的是头节点
    if (index == 0)
    {
        node = node->link;
    }


    //最后一个i是目标索引前一个
    //before是目标索引的前一个
    for (int i = 0; i < index - 1; i++) {
        before = before->link;
    }
    //after是目标索引的后一个
    after = before->link->link;
    //删除目标元素
    free(before->link);
    //让before的下一个变成after即可
    before->link = after;
    return 1;
}


//index为需要查找的索引位置
int Find(HeaderList* L, int index) {
    Node* p;
    int j;
    //要查询的位置超过列表长度
    if (index >= L->num - 1 || index < 0) {
        printf("OutOfIndex");
        return 0;
    }
    //链表只能从头开始逐个查询
    p = L->head;
    for (int i = 0; i < index - 1; i++) {
        p = p->link;
    }
    //循环结束，指针指向目标元素
    return p->element;
}



//index是要插入的位置，target为插入元素的值
int Insert(HeaderList* L, int index, int target) {
    // Check if the index is out of bounds.
    if (index < 0 || index > L->num) {
        printf("Index out of bounds\n");
        return 0;
    }

    // Create a new node 'temp' and allocate memory for it.
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return 0;
    }
    temp->element = target;

    // If the list is empty or we're inserting at the beginning.
    if (index == 0 || L->num == 0) {
        temp->link = L->head;
        L->head = temp;
    }
    else {
        // Find the node at the specified index.
        Node* prev = NULL;
        Node* current = L->head;
        for (int i = 0; i < index; i++) {
            prev = current;
            current = current->link;
        }

        // Insert the new node after 'prev'.
        temp->link = current;
        prev->link = temp;
    }

    // Increment the number of elements in the list.
    L->num++;

    return 1;
}

int Reversed(Node* node) {

    Node* temp1 = NULL;
    Node* temp2 = NULL;
    Node* tool = NULL;
    temp1 =node;
   node = NULL;
    while (temp1) {
        temp2 = temp1->link;
        temp1->link = tool;
        tool = temp1;
        temp1 = temp2;
    }
   node= tool;
    return 1;

}




//index是要删除的目标索引
int Delete(HeaderList* L, int index) {
    //如果链表没有节点则删除失败
    if (L->num == 0) {
        printf("List is empty");
        return 0;
    }
    //对索引位置进行判断
    if (index >= L->num - 1 || index < 0) {
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
    for (int i = 0; i < index - 1; i++) {
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

int OutPut(HeaderList* L) {
    //链表为空则无法进行输出
    if (L->num == 0) {
        printf("List is empty");
        return 0;
    }

    Node* tool;
    tool = L->head;
    while(tool->link) {
        printf("%d ", tool->element);
        tool = tool->link;
    }
    printf("%d", tool->element);
    return 1;
}

void Destroy(HeaderList* L) {
    Node* p;
    while (L->head) {
        p = L->head->link;
        free(L->head);
        L->head = p;

    }
}

int Reversed(HeaderList* L) {
    if (L->num == 0) {
        printf("List is empty");
        return 0;
    }

    Node* temp1 = NULL;
    Node* temp2 = NULL;
    Node* tool = NULL;
    temp1 = L->head;
    L->head = NULL;
    while (temp1) {
        temp2 = temp1->link;
        temp1->link = tool;
        tool = temp1;
        temp1 = temp2;
    }
    L->head = tool;
    return 1;

}




 void bubbleSort(HeaderList *headerList)
 {
     Node *n = headerList->head;
     if((n -> link == NULL) || (n -> link -> link == NULL))
     {
         return;
     }

     Node *head, * pre, * cur, *next, * end, * temp;
     head = n;
     end = NULL;
     //从链表头开始将较大值往后沉
     while(head -> link != end)
     {
         for(pre = head, cur = pre -> link, next = cur -> link;   next != end;   pre = pre -> link, cur = cur -> link, next = next -> link)
         {
             //相邻的节点比较
             if(cur -> element > next -> element)
             {
                 cur -> link = next -> link;
                 pre -> link = next;
                 next -> link = cur;
                 temp = next;
                 next = cur;
                 cur = temp;
             }
         }
         end = cur;
         
     }
     cur = head;
    
     for (int i = 0; i < headerList->num - 2 ; i++) {
         cur = cur->link;
     }
     Insert(headerList , headerList->num , head->element);
     headerList->head = head  -> link;
 }

 // 创建一个新的多项式项
 PolynomialNode* createNode(int coefficient, int exponent) {
     PolynomialNode* newNode = (PolynomialNode*)malloc(sizeof(PolynomialNode));
     newNode->coefficient = coefficient;
     newNode->exponent = exponent;
     newNode->next = NULL;
     return newNode;
 }

 // 将多项式的项添加到链表的末尾
 void appendTerm(PolynomialNode** poly, int coefficient, int exponent) {
     PolynomialNode* newNode = createNode(coefficient, exponent);
     if (*poly == NULL) {
         *poly = newNode;
         return;
     }
     PolynomialNode* temp = *poly;
     while (temp->next != NULL) {
         temp = temp->next;
     }
     temp->next = newNode;
 }

 // 用于初始化多项式的函数
 void initializePolynomial(Polynomial* poly, int num_terms) {
     poly->num_terms = num_terms;
     poly->terms = (Term*)malloc(num_terms * sizeof(Term));
 }

 // 用于释放多项式内存的函数
 void destroyPolynomial(Polynomial* poly) {
     free(poly->terms);
 }

 // 用于显示多项式的函数
 void displayPolynomial(const Polynomial* poly) {
     for (int i = 0; i < poly->num_terms; i++) {
         if (i > 0) {
             printf(" + ");
         }
         printf("%.2f", poly->terms[i].coefficient);
         if (poly->terms[i].variable != '\0') {
             printf("%c", poly->terms[i].variable);
         }
         if (poly->terms[i].exponent != 0) {
             printf("^%d", poly->terms[i].exponent);
         }
     }
     printf("\n");
 }

 //多项式的加法
 Polynomial addPolynomials(const Polynomial* poly1, const Polynomial* poly2) {
     int total_terms = poly1->num_terms + poly2->num_terms;
     Polynomial result;
     initializePolynomial(&result, total_terms);

     int i = 0, j = 0, k = 0;
     while (i < poly1->num_terms && j < poly2->num_terms) {
         if (poly1->terms[i].exponent > poly2->terms[j].exponent) {
             result.terms[k++] = poly1->terms[i++];
         }
         else if (poly1->terms[i].exponent < poly2->terms[j].exponent) {
             result.terms[k++] = poly2->terms[j++];
         }
         else {
             result.terms[k].exponent = poly1->terms[i].exponent;
             result.terms[k].coefficient = poly1->terms[i].coefficient + poly2->terms[j].coefficient;
             i++;
             j++;
             k++;
         }
     }

     while (i < poly1->num_terms) {
         result.terms[k++] = poly1->terms[i++];
     }

     while (j < poly2->num_terms) {
         result.terms[k++] = poly2->terms[j++];
     }

     result.num_terms = k;
     return result;
 }


 // 用于将多项式相乘的函数
 Polynomial multiplyPolynomials(const Polynomial* poly1, const Polynomial* poly2) {
     Polynomial result;
     initializePolynomial(&result, poly1->num_terms * poly2->num_terms);

     int term_count = 0;
     for (int i = 0; i < poly1->num_terms; i++) {
         for (int j = 0; j < poly2->num_terms; j++) {
             result.terms[term_count].coefficient = poly1->terms[i].coefficient * poly2->terms[j].coefficient;
             result.terms[term_count].variable = poly1->terms[i].variable;
             result.terms[term_count].exponent = poly1->terms[i].exponent + poly2->terms[j].exponent;
             term_count++;
         }
     }

     return result;
 }


int main() {
    HeaderList headerList;
    Init(&headerList );
    for (int i = 0; i < 9; i++) {
        Insert(&headerList, i, i + 1);
    }
    printf("初始化后的链表为：");
    OutPut(&headerList);
    printf("\n");

    Reversed(&headerList);
    printf("逆置后的链表为：");
    OutPut(&headerList);
    printf("\n");

    printf("排序后的链表为：");
    bubbleSort(&headerList);
    OutPut(&headerList);
    printf("\n");
    
    printf("查找第二个元素: ");
    printf("%d", Find(&headerList, 2));
    printf("\n");

    printf("删除第二个节点：");
    Delete(&headerList, 1);
    OutPut(&headerList);
    printf("\n");

    // 初始化两个多项式
    Polynomial poly1, poly2, result;
    initializePolynomial(&poly1, 2);
    poly1.terms[0].coefficient = 2.0;
    poly1.terms[0].variable = 'x';
    poly1.terms[0].exponent = 2;
    poly1.terms[1].coefficient = 3.0;
    poly1.terms[1].variable = 'y';
    poly1.terms[1].exponent = 1;

    initializePolynomial(&poly2, 2);
    poly2.terms[0].coefficient = 4.0;
    poly2.terms[0].variable = 'x';
    poly2.terms[0].exponent = 1;
    poly2.terms[1].coefficient = 5.0;
    poly2.terms[1].variable = 'y';
    poly2.terms[1].exponent = 2;

    // 显示两个多项式
    printf("Poly1: ");
    displayPolynomial(&poly1);

    printf("Poly2: ");
    displayPolynomial(&poly2);

    // 计算多项式相乘
    printf("多项式相乘:\n");
    result = multiplyPolynomials(&poly1, &poly2);

    // 显示结果多项式
    printf("Result: ");
    displayPolynomial(&result);

    //计算多项式相加
    printf("多项式相加:\n");
    printf("Result: ");
    result = addPolynomials(&poly1, &poly2);
    displayPolynomial(&result);

    // 释放多项式内存
    destroyPolynomial(&poly1);
    destroyPolynomial(&poly2);
    destroyPolynomial(&result);
    
    return 0;

}

