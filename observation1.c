#include<stdio.h>
#define MAX_SIZE 100

typedef struct 
{
    int data[MAX_SIZE];
    int SIZE;
}ArrayADT;

void initialise(ArrayADT *arr)
{
    arr->SIZE=0;
}

void Insert(ArrayADT *arr,int value)
{
    if(arr->SIZE >= MAX_SIZE)
    {
        printf("List is full");
        return;
    }
    arr->data[arr->SIZE]=value;
    arr->SIZE++;
}

void InsertPOS(ArrayADT*arr,int pos,int value)
{
    if(pos<0 || pos > arr->SIZE || arr->SIZE >= MAX_SIZE)
    {
        printf("Invalid or list full.");
    }
    for(int i = arr->SIZE; i>pos ;i--) 
    {
        arr->data[i]=arr->data[i-1];
    }
    arr->data[pos]=value;
    arr->SIZE++;
}
void DeletePOS(ArrayADT*arr,int pos)
{
    if(pos<0 || pos >= arr->SIZE || arr->SIZE == 0)
    {
        printf("Invalid as list is empty.");
    }
    for(int i = pos; i<arr->SIZE-1 ;i++)
    {
        arr->data[i]=arr->data[i+1];
    }
    arr->SIZE--;
}

void display(ArrayADT *arr)
{
    for(int i =0; i<arr->SIZE; i++)
    {
        printf("%d\t",arr->data[i]);
    }
}

int main(){
    ArrayADT arr;
    initialise(&arr);
    printf("Array elements : ");
    Insert(&arr,10);
    Insert(&arr,20);
    Insert(&arr,30);
    display(&arr);
    printf("\n");
    printf("Array elements after insertion: ");
    InsertPOS(&arr,1,40);
    display(&arr);
    printf("\n");
    printf("Array elements after deletion: ");
    DeletePOS(&arr,2);
    display(&arr);
    return 0;
}
