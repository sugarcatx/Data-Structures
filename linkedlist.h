#include <iostream>

using namespace std;

class node
{
public:
    int info;
    node *link;
};

class LinkedList
{
    node *Head = NULL;
    node *temp;

public:

    void creation(int);
    void traverse();


    /* Insert Operation */
    void first_insert(int); // Insert at the beginning of the list
    void last_insert(int); // Insert at the end of the list
    void before_insert(int, int);
    void after_insert(int, int);
};



void LinkedList :: creation(int data)
{
    node *ptr = new node();
    ptr->info = data;
    ptr->link = NULL;

    if(Head == NULL)
    {
        Head = ptr;
        temp = ptr;
    }
    else
    {
        temp->link = ptr;
        temp = ptr;
    }
}



void LinkedList :: traverse()
{
    node *srt;

    for(srt = Head; ; srt = srt->link)
    {
        cout << srt->info << " ";
        if (srt->link == NULL) break;
    }

}

void LinkedList :: first_insert(int item)
{
    node *ptr = new node();
    ptr->info = item;
    ptr->link = Head; //Pointing to the currently first node;
    Head = ptr;
}

void LinkedList :: last_insert(int item)
{
    node *ptr = new node();
    ptr->info = item;
    ptr->link = NULL ; //As it is the last node, the link will be null;

    /* Traverse to rich to the end node */
    node *srt = Head;
    for(;;)
    {
        if(srt->link==NULL)
        {
            srt->link = ptr;
            break;
        }
        else
        {
            srt = srt->link;
        }
    }
}


void LinkedList :: before_insert(int sItem, int data)
{
    node *srt, *tmp;
    for(srt=Head; ;)
    {
        if(srt->info == sItem)
        {
            if(srt==Head) //Item found at the head node.
            {
                first_insert(data);
            }
            else //The searching item has been found but it is not in the head node.
            {
                node *ptr = new node();
                ptr->info = data;
                ptr->link = srt;
                tmp->link = ptr;

                break;
            }
        }
        else
        {
            tmp = srt;
            srt = srt->link;
        }
    }
    if (srt == NULL)
    {
        cout << "Item not found" << endl;
    }
}

void LinkedList :: after_insert(int sItem, int item)
{
    node *srt;
    for(srt = Head; ;)
    {
        if (srt->info == sItem)
        {
            if(srt->link == NULL)
            {
                last_insert(item);
                break;
            }
            else
            {
                node *ptr = new node();
                ptr->info = item;
                ptr->link = (srt->link);
                //cout << "SRT->link " << srt->info << endl;
                srt->link = ptr;
                break;
            }
        }
        else
        {
            srt = srt->link;
        }
    }
}
