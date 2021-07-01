#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *pre;
    int item;
    struct Node *next;
};
struct Node * searchItem(struct Node*, int);
void deleteParticularNode(struct Node**, int);
void deleteLastItemAtNode(struct Node**);
void deleteFistItemAtNode(struct Node**);
void addItemAfterNode(struct Node*, int);
void addItemAtStart(struct Node**, int);
void viewList(struct Node*);
void addNode(struct Node**, int);
int countItem(struct Node*);

struct Node * searchItem(struct Node *s, int data)
{
    while(s)
    {
        if(s->item == data)
            return s;
        else
            s=s->next;
    }
        return NULL;
};

void deleteParticularNode(struct Node **s, int data)
{
    struct Node *t, *r;
    t = r = *s;

    if(r->item == data)
    {
        *s = r->next;
    }
    while(r->item != data)
    {
        t = r;
        r = r->next;
    }
    t->next = r->next;
    t->next->pre = t->next;
    free(r);
}

void deleteLastItemAtNode(struct Node **s)
{
    struct Node *t, *r;
    t = *s;

    if((*s)->next == NULL)
        *s= NULL;
    else
    {
        while(t->next != NULL)
            t = t->next;

        t->pre->next = NULL;
        free(t);
    }
}

void deleteFistItemAtNode(struct Node **s)
{
    struct Node *t;
    t = *s;
    if(t->next == NULL)
        *s = NULL;
    *s = t->next;
    free(t);
}

void addItemAfterNode(struct Node *t, int data)
{
    struct Node *r;
    r = (struct Node*)malloc(sizeof(struct Node));
    r->item = data;
    r->next = t->next;
    r->pre = t;

    if(t->next != NULL)
        t->next->pre = r;
    t->next = r;
}

void addItemAtStart(struct Node **s, int data)
{
    struct Node *t, *r;
    r = (struct Node*)malloc(sizeof(struct Node));
    r->item = data;
    r->pre = NULL;
    r->next = *s;

    if(*s != NULL)
        (*s)->pre = r;
    *s=r;
}

void addNode(struct Node **s, int data)
{
    struct Node *t, *r;
    r = (struct Node*)malloc(sizeof(struct Node));
    r->item = data;
    r->next = NULL;

    if(*s == NULL)
    {
        r->pre = NULL;
        *s = r;
    }
    else
    {
        t = *s;
        while(t->next != NULL)
            t = t->next;

        r->pre = t;
        t->next = r;
    }
}

void viewList(struct Node *s)
{
    while(s)
    {
        printf("%d ",s->item);
        s = s->next;
    }
}

int countItem(struct Node *s)
{
  int countItem = 0;

  while(s)
    {
      countItem++;
      s = s->next;
    }
  return countItem;
}
