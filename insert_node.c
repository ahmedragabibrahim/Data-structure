#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*next;
};


void insert_node(int pos,struct node*nod,struct node**shead)
{
    struct node* temp1;
    struct node* temp2;
    temp1=(*shead);
    int counter=0;
    if (pos==1){
        (*nod).next=(*shead);
        (*shead)=nod;
        }

    while((counter<pos) && (temp1->next!=NULL))
    {
        temp2=temp1;
        temp1=temp1->next;
        counter++;

    }
   temp2->next=nod;
    nod->next=temp1;


}


int main()
{
    struct node a;
    struct node b;
    struct node c;
    struct node d;
    a.data=1;
    b.data=3;
    c.data=2;
    d.data=11;
    a.next=&b;
    b.next=&c;
    c.next=NULL;
    struct node*shead=&a;
    insert_node(3,&d,&shead);
    printf("%d",d.next->data);
    return 0;
}
