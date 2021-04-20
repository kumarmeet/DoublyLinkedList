#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct Node
{
    int item;
    struct Node *pre;
    struct Node *next;
};

int menu(void);
void printMetaData(struct Node *);
struct Node * searchItem(struct Node*, int);
void deleteParticularNode(struct Node*, int);
void deleteLastItemAtNode(struct Node**);
void deleteFistItemAtNode(struct Node**);
void addItemAfterNode(struct Node*, int);
void addItemAtStart(struct Node**, int);
void viewList(struct Node*);
void addNode(struct Node**, int);
int countItem(struct Node*);

int main()
{
    struct Node *start = NULL, *p=NULL;
    int item;

    while(1)
    {
        system("cls");
        printMetaData(start);
        switch(menu())
        {
        case 1:
            input(&item);
            addNode(&start, item);
            break;
        case 2:
            printf("Check item in the list or not\n");
            scanf("%d",&item);
            if(p = searchItem(start,item))
            {
                printf("Item has in the list\n");
                input(&item);
                addItemAfterNode(p, item);
            }
            else
                printf("Item Not found");
            break;
        case 3:
            addItemAtStart(&start, item);
            printf("Add Item at start");
            break;
        case 4:
            printf("Check item in the list or not\n");
            scanf("%d",&item);
            if(p = searchItem(start,item))
            {
                deleteParticularNode(p,item);
            }
            else
                printf("Item Not found");
            break;
        case 5:
            deleteFistItemAtNode(&start);
            printf("First item deleted");
            break;
        case 6:
            deleteLastItemAtNode(&start);
            printf("Deleted last item");
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Invalid choice");
        }
        getch();
    }
    return 0;
}

void input(int *item)
{
    printf("Enter your item -> ");
    scanf("%d", item);
}

void printMetaData(struct Node *n)
{
    printf("List is empty -> %s\n",n != NULL ? "No": "Yes");
    printf("You have %d items in list\n", countItem(n));
    viewList(n);
}

int menu()
{
    int choice;
    printf("\n\n1. Add item");
    printf("\n2. Add item after item");
    printf("\n3. Add item at first");
    printf("\n4. Delete item");
    printf("\n5. Delete first item");
    printf("\n6. Delete last item");
    printf("\n7. Exit");
    printf("\nEnter your choice -> ");
    scanf("%d",&choice);
    return choice;
}
