#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node*next;
    struct node*prev;
}Node;

Node* CreateNode(int value)
{
    Node*newnode = (Node*)malloc(sizeof(Node));
    if(!newnode)
    {
        printf("Memory allocation fails.");
        return NULL;
    }
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

void InsertAtBeg(Node**head,int value)
{
    Node* newnode = CreateNode(value);
    if(!newnode)
    {
        printf("Memory allocation failed.");
        return;
    }
    newnode->next=*head;
    (*head)->prev=newnode;
    *head = newnode;
}
 
void InsertAtPos(Node**head,int value,int pos)
{
    if(pos<1){
        printf("Invalid position.");
        return;
    }
    Node *newnode = CreateNode(value);
    if(pos==1)
    {
       InsertAtBeg(head,value);
    }
    Node*temp=*head;
    for(int i=1;i<pos-1;i++)
    {
        if(temp->next==NULL)
        {
            printf("Invalid position.");
        }
        temp=temp->next;
    }
     newnode->prev = temp;
     newnode->next=temp->next;
     temp->next=newnode;
     newnode->next->prev=newnode;
}
void InsertAtEnd(Node ** head,int value) 
{
    Node* newnode = CreateNode(40);
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }
    Node*temp = *head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}

void DeletionAtBeg(Node**head)
{
    if(*head==NULL)
    {
        printf("Deletion not possible.");
        return;
    }
    Node*temp=*head;
    // if dll has only single node. 
    if(temp->next==NULL)
    {
        *head=NULL;
        free(temp);
        return;
    }
    (*head)=(*head)->next;
    (*head)->prev=NULL;
    free(temp);
}

void DeletionAtEnd(Node* *head)
{
    if(*head==NULL)
    {
        printf("deletion not possible.");
    }
     Node*temp=*head;
    // if dll has only single node. 
    if(temp->next==NULL)
    {
        *head=NULL;
        free(temp);
        return;
    }
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
}

void DeletionAtpos(Node** head, int pos) {
    if (*head == NULL) {
        printf("Deletion not possible. List is empty.\n");
        return;
    }

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    Node* temp = *head;

    if (pos == 1) {
        DeletionAtBeg(head);
        return;
    }

    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position. Node doesn't exist.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void Displaylist(Node* head)
{
    Node* temp = head;
    if (head == NULL) {
        printf("Linked List is empty.\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(){
    Node* head = NULL;
    head = CreateNode(20);
    if(head!=NULL){
        printf("Node created with data: %d\n",head->data);
    }
    printf("Insertion at beginning: ");
    InsertAtBeg(&head,30);
    Displaylist(head);
    printf("Insertion at end: ");
    InsertAtEnd(&head,40);
    Displaylist(head);
    printf("Insertion at position: ");
    InsertAtPos(&head,50,2);
    Displaylist(head);
    printf("Deletion at beginning: ");
    DeletionAtBeg(&head);
    Displaylist(head);
    printf("Deletion at end: ");
    DeletionAtEnd(&head);
    Displaylist(head);
    printf("Deletion at position: ");
    DeletionAtpos(&head,2);
    Displaylist(head);
    return 0;
}

