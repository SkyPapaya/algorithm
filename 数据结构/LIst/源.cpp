#include <stdio.h>
#include <stdlib.h>
#include<stddef.h>

typedef struct Node {
    int element;
    struct Node* link;
}Node;

typedef struct HeaderList {
    //ͷ�ڵ�
    Node* head;
    //����ڵ�����
    int num;
}HeaderList;

typedef struct PolynomialNode {
    // ϵ��
    int coefficient; 
    // ָ��
    int exponent;    
    struct PolynomialNode* next;
} PolynomialNode;

typedef struct {
    double coefficient; // ϵ��
    char variable;      // ��ĸ����
    int exponent;       // ָ��
} Term;

// �������ʽ�Ľṹ
typedef struct {
    int num_terms; // ����ʽ�е�����
    Term* terms;   // ����ʽ��������
} Polynomial;

int Init(HeaderList* L ) {
    L->head = NULL;
    L->num = 0;
    return 1;

}



//indexΪ��Ҫ���ҵ�����λ��
int Find(Node* L, int index) {
    Node* p;
    int j;
    //Ҫ��ѯ��λ�ó����б���
    
    //����ֻ�ܴ�ͷ��ʼ�����ѯ
    p = L;
    for (int i = 0; i < index - 1; i++) {
        p = p->link;
    }
    //ѭ��������ָ��ָ��Ŀ��Ԫ��
    return p->element;
}


//index��Ҫ�����λ�ã�targetΪ����Ԫ�ص�ֵ
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

    //���ɾ������ͷ�ڵ�
    if (index == 0)
    {
        node = node->link;
    }


    //���һ��i��Ŀ������ǰһ��
    //before��Ŀ��������ǰһ��
    for (int i = 0; i < index - 1; i++) {
        before = before->link;
    }
    //after��Ŀ�������ĺ�һ��
    after = before->link->link;
    //ɾ��Ŀ��Ԫ��
    free(before->link);
    //��before����һ�����after����
    before->link = after;
    return 1;
}


//indexΪ��Ҫ���ҵ�����λ��
int Find(HeaderList* L, int index) {
    Node* p;
    int j;
    //Ҫ��ѯ��λ�ó����б���
    if (index >= L->num - 1 || index < 0) {
        printf("OutOfIndex");
        return 0;
    }
    //����ֻ�ܴ�ͷ��ʼ�����ѯ
    p = L->head;
    for (int i = 0; i < index - 1; i++) {
        p = p->link;
    }
    //ѭ��������ָ��ָ��Ŀ��Ԫ��
    return p->element;
}



//index��Ҫ�����λ�ã�targetΪ����Ԫ�ص�ֵ
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




//index��Ҫɾ����Ŀ������
int Delete(HeaderList* L, int index) {
    //�������û�нڵ���ɾ��ʧ��
    if (L->num == 0) {
        printf("List is empty");
        return 0;
    }
    //������λ�ý����ж�
    if (index >= L->num - 1 || index < 0) {
        printf("OutOfIndex");
        return 0;
    }
    Node* before;
    Node* after;
    before = L->head;
    after = L->head;

    //���ɾ������ͷ�ڵ�
    if (index == 0)
    {
        L->head = L->head->link;
    }


    //���һ��i��Ŀ������ǰһ��
    //before��Ŀ��������ǰһ��
    for (int i = 0; i < index - 1; i++) {
        before = before->link;
    }
    //after��Ŀ�������ĺ�һ��
    after = before->link->link;
    //ɾ��Ŀ��Ԫ��
    free(before->link);
    L->num--;
    //��before����һ�����after����
    before->link = after;
    return 1;
}

int OutPut(HeaderList* L) {
    //����Ϊ�����޷��������
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
     //������ͷ��ʼ���ϴ�ֵ�����
     while(head -> link != end)
     {
         for(pre = head, cur = pre -> link, next = cur -> link;   next != end;   pre = pre -> link, cur = cur -> link, next = next -> link)
         {
             //���ڵĽڵ�Ƚ�
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

 // ����һ���µĶ���ʽ��
 PolynomialNode* createNode(int coefficient, int exponent) {
     PolynomialNode* newNode = (PolynomialNode*)malloc(sizeof(PolynomialNode));
     newNode->coefficient = coefficient;
     newNode->exponent = exponent;
     newNode->next = NULL;
     return newNode;
 }

 // ������ʽ������ӵ������ĩβ
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

 // ���ڳ�ʼ������ʽ�ĺ���
 void initializePolynomial(Polynomial* poly, int num_terms) {
     poly->num_terms = num_terms;
     poly->terms = (Term*)malloc(num_terms * sizeof(Term));
 }

 // �����ͷŶ���ʽ�ڴ�ĺ���
 void destroyPolynomial(Polynomial* poly) {
     free(poly->terms);
 }

 // ������ʾ����ʽ�ĺ���
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

 //����ʽ�ļӷ�
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


 // ���ڽ�����ʽ��˵ĺ���
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
    printf("��ʼ���������Ϊ��");
    OutPut(&headerList);
    printf("\n");

    Reversed(&headerList);
    printf("���ú������Ϊ��");
    OutPut(&headerList);
    printf("\n");

    printf("����������Ϊ��");
    bubbleSort(&headerList);
    OutPut(&headerList);
    printf("\n");
    
    printf("���ҵڶ���Ԫ��: ");
    printf("%d", Find(&headerList, 2));
    printf("\n");

    printf("ɾ���ڶ����ڵ㣺");
    Delete(&headerList, 1);
    OutPut(&headerList);
    printf("\n");

    // ��ʼ����������ʽ
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

    // ��ʾ��������ʽ
    printf("Poly1: ");
    displayPolynomial(&poly1);

    printf("Poly2: ");
    displayPolynomial(&poly2);

    // �������ʽ���
    printf("����ʽ���:\n");
    result = multiplyPolynomials(&poly1, &poly2);

    // ��ʾ�������ʽ
    printf("Result: ");
    displayPolynomial(&result);

    //�������ʽ���
    printf("����ʽ���:\n");
    printf("Result: ");
    result = addPolynomials(&poly1, &poly2);
    displayPolynomial(&result);

    // �ͷŶ���ʽ�ڴ�
    destroyPolynomial(&poly1);
    destroyPolynomial(&poly2);
    destroyPolynomial(&result);
    
    return 0;

}

