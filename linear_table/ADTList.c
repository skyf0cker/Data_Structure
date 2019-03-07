#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#define ERROR 0
#define SUCCESS 1
#define SIZE_INT 4 

typedef struct 
{
    int *begin;
    size_t SIZE;
    int length;

}ADTList;

int tail_insert(ADTList *adt, int data) {
    if (!adt->begin) {
        printf("%s", "ADTlist is not initial!");
    } else {
        adt->begin = (int*)realloc(adt->begin, adt->SIZE+SIZE_INT);
        if (!adt->begin) {
            return ERROR;
        }
        *(adt->begin + adt->length) = data;
        adt->SIZE += SIZE_INT;
        adt->length += 1;

        return SUCCESS;
    }
}

ADTList* init() {
    ADTList *adt = (ADTList*)malloc(sizeof(ADTList));
    if (!adt) {
        return NULL;
    } else {
        adt->begin = (int*)malloc(SIZE_INT);
        adt->SIZE = SIZE_INT;
        adt->length = 0;
    }
    return adt;
}

int* getArray(int init_num, int step, int num_size) {
    int *array = (int*)malloc(num_size*SIZE_INT);
    int i = 0;
    for (;i < num_size;i++) {
        *array++ = init_num;
        init_num += step;
    }
    array -= num_size;
    return array;
}

int Midinsert(ADTList* adt, int data, int position) {
    int begin = position;
    int last = adt->length;
    int *temp;
    for (temp=adt->begin + last;temp >= adt->begin+begin;temp--) {
        *(temp+1) = *(temp); 
    }
    *(adt->begin + begin) = data;
    adt->SIZE += SIZE_INT;
    adt->length += 1;
}

int GetIndex(int *array, int data, size_t SIZE) {
    int board_length = SIZE + 1;
    int checkpoint = (int)board_length/2;
    while(!(data > *(array+checkpoint-1) && data < *(array+checkpoint+1))){
        // printf("%d", checkpoint);
        checkpoint = (int)checkpoint/2;
    }
    return checkpoint;
}

int main() {
    int num = 0;
    printf("%s", "输入顺序表的元素个数:");
    scanf("%d", &num);
    int temp = num;
    int temp2 = num;
    printf("%s", "请输入初始值和步长:");    
    int init_num = 0;
    int step = 0;
    scanf("%d,%d", &init_num,&step);
    ADTList *adt = init();  
    int *array = getArray(init_num, step, temp);
    for (;num > 0;num--) {
        printf("%d", *array++);
        if (num == 1) {
            continue;
        } else
        {
            printf("%s", ",");
        }
    }
    array -= temp;
    
    for (;temp > 0;temp--) {
        tail_insert(adt, *array++);
    }
    array -= temp2;

    int data  = 0;

    printf("\n%s", "请输入插入的元素:");
    scanf("%d", &data);

    int checkpoint = GetIndex(array, data, temp2);
    Midinsert(adt, data, checkpoint);
    int num2 = temp2+1;
    for (;num2 > 0;num2--) {
        printf("%d", *(adt->begin)++);
        if (num2 == 1) {
            continue;
        } else
        {
            printf("%s", ",");
        }
        
    }
}