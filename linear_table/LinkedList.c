#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;

}Node, *node;

void tail_insert(node head, int _data) {
    node n = head->next;
    if (!n) {
        n = (node)malloc(sizeof(Node));
        head->next = n;        
    }
    while(n->next){
        n = n->next;
    }
    n->next = (node)malloc(sizeof(Node));
    n->data = _data;
}

void head_insert(node head, int _data) {
    node new_node = (node)malloc(sizeof(Node));
    if (new_node) {
        new_node->data = _data;
        new_node->next = head->next;
        head->next = new_node;
    }
}

void solution(node head, int mink, int maxk) {
    node pmink, pmaxk;
    node n = head->next;
    while(n){
        if (n->next && n->next->data == mink) {
            pmink = n;
        }
        if (n->data == maxk) {
            pmaxk = n;
        }
        n = n->next;
    }
    free(pmink->next);
    pmink->next = NULL;
    pmink->next = pmaxk;
}

void reverse(node head) {
    node n = head->next;
    int temp = 0;
    node before = n;
    node after = before->next;
    node ptemp;
    while(ptemp != n){
        head->next = after;
        while(after && after != ptemp) {
            temp = after->data;
            after->data = before->data;
            before->data = temp;
            before = after;
            after = before->next;
        }
        ptemp = before;
        before = n;
        after = before->next;
    }
    
}

int main() {
    int i = 0;
    node head = (node)malloc(sizeof(Node));
    head->next = (node)malloc(sizeof(Node));
    int a=0,b=0,c=0,d=0;
    scanf("%d,%d,%d,%d",&a,&b,&c,&d);
    
    tail_insert(head, a);
    tail_insert(head, b);
    tail_insert(head, c);
    tail_insert(head, d);

    node test2 = head->next;
    reverse(head);
    node test = head->next;
    while(test){
        if (! test->next) {
            printf("%d", test->data);
            test = test->next;        
        } else
        {
            printf("%d,", test->data);
            test = test->next;        
        }
    
    }
    
}







