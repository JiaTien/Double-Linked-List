#include <stdio.h>
#include <iostream>

using namespace std;

struct node {

    int data;
    node* perv;
    node* next;
};

void input(node*, int);
void output(node*);
void free_mm(node*);
void delet_node(node**, int);
void revise_node(node**, int, int);
void add_node(node** start, int x, int num);
void reverse_output(node* start);

int main() {

    //創建
    int node_num;
    printf("節點數:");
    scanf("%d", &node_num);
    node* head = new node;
    input(head, node_num);

    //印出
    output(head);
    //反印
    //reverse_output(head);

    //新增
    //add_node(&head, 4, 100);

    //刪除
    //delet_node(&head, 3);

    //修改
    //revise_node(&head, 3, 100);

    //檢查結果
    //output(head);
    //reverse_output(head);
    
    //釋放
    free_mm(head);
    return 0;
}
void input(node* start, int x) {

    node* crt = start, * temp;

    for (int i = 0; i < x; i++) {

        int num;
        printf("\n第%d節點資料:", i + 1);
        scanf("%d", &num);

        if (i == 0) {

            crt->data = num;
            crt->perv = NULL;
        }
        else {
            crt->next = new node;
            temp = crt;
            crt = crt->next;
            crt->perv = temp;
            crt->data = num;
        }

        if (i == x - 1)
            crt->next = NULL;
    }
}
void output(node* start) {

    while (start != NULL) {

        printf("元素:%d\n", start->data);
        start = start->next;
    }
    printf("\n");
}
void reverse_output(node* start) {

    node* last;

    while (start->next != NULL)
        start = start->next;

    last = start;

    while (last != NULL) {

        printf("元素:%d\n", last->data);
        last = last->perv;
    }
    printf("\n");
}
void free_mm(node* start) {

    int c = 1;
    while (start != NULL) {

        node* temp = start;
        start = start->next;
        delete temp;
        printf("Free %d\n", c++);
    }
}
void add_node(node** start, int x, int num) {

    node* new_node = new node, * crt = *start, * temp = NULL, * last;
    new_node->data = num;

    if (x == 1) {

        temp = *start;
        new_node->next = temp;
        new_node->perv = NULL;
        temp->perv = new_node;
        *start = new_node;
    }
    else {

        for (int i = 0; i < x - 1; i++) {

            if (i == x - 2) {

                last = crt;
            }

            if (crt->next != NULL)
                crt = crt->next;
            else
                num = 0;
        }
        temp = last->next;
        last->next = new_node;
        new_node->perv = last;
        new_node->next = temp;
        if (num != 0)
            crt->perv = new_node;
    }
}
void delet_node(node** start, int x) {

    node* temp, * p, * n; int z = 0;

    if (x == 1) {

        temp = *start;
        *start = temp->next;
        delete temp;
        p = *start;
        p->perv = NULL;
    }
    else {
        node* crt = *start;
        for (int i = 0; i < x; i++) {

            if (i == x - 2) {

                n = crt;
            }
            else if (i == x - 1) {

                temp = crt;
            }

            if (crt->next != NULL)
                crt = crt->next;
        }
        n->next = temp->next;
        crt->perv = temp->perv;
        delete temp;
    }
}
void revise_node(node** start, int x, int num) {

    node* crt = *start;

    if (x != 1)
        for (int i = 0; i < x - 1; i++)
            crt = crt->next;

    crt->data = num;
}