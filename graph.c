#include <stdio.h>
#include <stdlib.h>
//Breadth First Search (BFS) of a Graph
#define BOOL char
#define FALSE 0
#define TRUE 1
struct node{
    char name;
    struct node*linkes[3];
    int counter;
    BOOL read;
};
struct node*lest[3];
void addedg(struct node*first,struct node*second)
{
    (*first).linkes[(*first).counter]=second;
    (*second).linkes[(*second).counter]=first;
    (*first).counter++;
    (*second).counter++;
}
void print(int num_n)
{
    int i;
    for(i=0;i<=num_n;i++)
    {
        int j;
        struct node temp;
        temp=*lest[i];
        printf("\n%c",temp.name);
        for(j=0;j<temp.counter;j++)
        {
            printf("-->%c",temp.linkes[j]->name);
        }
    }

}
void BFS(int num_n)
{
    int c=0;
    char bfs[num_n];
    int i;
    int j;
    struct node temp;
    for( i=0;i<num_n;++i)
    {

        if((*lest[i]).read==FALSE)
        {

            bfs[c++]=(*lest[i]).name;

            (*lest[i]).read=TRUE;
        }

        for(j=0;j<(*lest[i]).counter;j++)
        {
            if((*lest[i]).linkes[j]->read==FALSE){

                    bfs[c++]=(*lest[i]).linkes[j]->name;

                    (*lest[i]).linkes[j]->read=TRUE;
            }

        }
    }
    int g;
    for(g=0;g<num_n;++g)
    {
        printf("%c\n",bfs[g]);
    }

}

int main()
{

    struct node a;
    a.name='a';
    a.counter=0;
    a.read=FALSE;
    lest[0]=&a;


    struct node b;
    b.name='b';
    b.counter=0;
    b.read=FALSE;
    lest[1]=&b;

    struct node c;
    c.name='c';
    c.counter=0;
    c.read=FALSE;
    lest[2]=&c;

     struct node d;
    d.name='d';
    d.counter=0;
    d.read=FALSE;
    lest[3]=&d;

    addedg(&c,&b);
    addedg(&b,&a);
    addedg(&b,&d);
    //printf("num of rel:%d",a.counter);


   //print(3);
   BFS(4);
    return 0;
}
