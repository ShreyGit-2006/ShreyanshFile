#include<stdio.h> 
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node*next;  
}Node;

Node* CreateNode(int value)
{
    Node*newnode = (Node*)malloc(sizeof(Node));
    if(!newnode){
        printf("Memory allocation fails.");
        return NULL;
    }
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}
void InsertAtBegin(Node* *head, int value)
{
    Node *newnode = CreateNode(value);
    if (!newnode) {
        printf("Memory allocation failed.\n");
        return;
    }

    newnode->data = value;
    newnode->next = *head;
    *head = newnode;
}

void InsertAtEnd(Node* *head,int value)
{
    Node *newnode = CreateNode(value);
    if(*head==NULL){
        *head=newnode; // since   list is empty
        return;
    }

    Node*temp = *head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
void InsertAtPos(Node* *head,int value,int pos)
{
   
    if(pos<1){
        printf("Invalid position.");
        return;
    }
    Node *newnode = CreateNode(value);
    if(pos==1){
       InsertAtBegin(head,value);
    }
    else{
        Node*temp=*head;
        for(int i=1;i<pos-1;i++)
        {
            if(temp->next==NULL)
            {
                printf("Invalid position.");
            }
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

void DeleteAtBeg(Node* *head)
{
    if(*head==NULL){
        printf("List is empty");
        return;
    }
    Node*temp=*head;
    (*head)=(*head)->next;
    free(temp);
}

void DeletionAtEnd(Node* *head)
{
    if(*head==NULL){
        printf("List is empty.\n");
        return;
    }
    Node* temp = *head;
    Node* prevnode;
    while(temp->next!=NULL){
        prevnode=temp;
        temp=temp->next;
    }
    prevnode->next=NULL;
    free(temp);
    // while(temp->next->next!=NULL)
    // {
    //     temp=temp->next;
    // }
    // free(temp->next);
    // temp->next=NULL;
   
}
void DeletionAtpos(Node* *head, int pos)
{
    Node* delnode;
    if(*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if(pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }
    if(pos == 1)
    {
        DeleteAtBeg(head);
        return;
    }
    Node* temp = *head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    delnode=temp->next;
    if(delnode==NULL){
        printf("Out of range.");
    }
    temp->next = delnode->next;
    free(delnode);
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
int main() {
    // initiallly head is null.
    Node* head=NULL;
    head = CreateNode(20); // here value is 
    // Check if node is created successfully.
    if(head != NULL) {
        printf("Node created with data: %d\n", head->data);
    }
    // Insert nodes at beginning
    printf("Inserting at beginning: ");
    printf("\n");
    InsertAtBegin(&head,25);
    InsertAtBegin(&head,35);
    InsertAtBegin(&head,87);
    Displaylist(head);
    printf("Inserting at end: ");
    printf("\n");
    InsertAtEnd(&head,45);
    Displaylist(head);
    printf("Inserting at position: ");
    printf("\n");
    InsertAtPos(&head,300,2);
    Displaylist(head);
    printf("Deletion at beginning: ");
    DeleteAtBeg(&head);
    printf("\n");
    Displaylist(head);
    printf("Deltion at end: ");
    printf("\n");
    DeletionAtEnd(&head);
    Displaylist(head);
    printf("Deletion at position: ");
    printf("\n");
    DeletionAtpos(&head,1 );
    Displaylist(head);
    return 0;
}


