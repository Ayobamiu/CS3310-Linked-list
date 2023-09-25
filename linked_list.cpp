#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    node *next, *prev;
    int ID;
    node(int ID)
    {
        next = NULL;
        prev = NULL;
        this->ID = ID;
    }
};

class linked_list
{
public:
    node *head, *tail;
    int nodes, max_nodes;

    linked_list(int maxNodes)
    {
        this->head = NULL;
        this->tail = NULL;
        this->nodes = 0;
        this->max_nodes = maxNodes;
    }

    int size()
    {
        return nodes;
    }
    bool empty()
    {
        return size() <= 0;
    }
    bool full()
    {
        return size() >= max_nodes;
    }
    void insert_tail(node *new_node)
    {
        if (empty())
        {
            head = new_node;
            tail = new_node;
            nodes = nodes + 1;
        }
        else if (full())
        {
            cout << "An attempt to insert was made while Linked List is full";
        }
        else
        {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
            nodes = nodes + 1;
        }
    };
    void delete_tail()
    {
        if (empty())
        {
            cout << "An attempt to delete was made while Linked List is empty";
        }
        if (size() == 1)
        {
            free(head);
            head = NULL;
            tail = NULL;
            nodes = nodes - 1;
        }
        else
        {
            tail = tail->prev;
            tail->next->prev = NULL;
            // free(tail->next);
            delete (tail->next); // delete operator instead of free to deallocate memory for the deleted nodes
            tail->next = NULL;
            nodes = nodes - 1;
        }
    }
    void insert_head(node *new_node)
    {
        if (empty())
        {
            head = new_node;
            tail = new_node;
            nodes = nodes + 1;
        }
        else if (full())
        {
            cout << "An attempt to insert was made while Linked List is full";
        }
        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
            nodes = nodes + 1;
        }
    };

    void delete_head()
    {
        if (empty())
        {
            cout << "An attempt to delete was made while Linked List is empty";
        }
        if (size() == 1)
        {
            free(head);
            head = NULL;
            tail = NULL;
            nodes = nodes - 1;
        }
        else
        {
            head = head->next;
            head->prev->next = NULL;
            // free(head->prev);
            delete (head->prev); // delete operator instead of free to deallocate memory for the deleted nodes
            head->prev = NULL;
            nodes = nodes - 1;
        }
    }
};

class myqueue
{
public:
    linked_list *LL;
    myqueue(int max_nodes)
    {
        if (max_nodes > 0)
            LL = new linked_list(max_nodes);
        else
            LL = nullptr;
    };
    void enqueue(node *new_node)
    {
        LL->insert_tail(new_node);
    };
    int dequeue()
    {
        int newID = LL->head->ID;
        LL->delete_head();
        return newID;
    };
};
class mystack
{
public:
    linked_list *LL;
    mystack(int max_nodes)
    {
        if (max_nodes > 0)
            LL = new linked_list(max_nodes);
        else
            LL = nullptr;
    };
    void push(node *new_node)
    {
        LL->insert_tail(new_node);
    };
    int pop()
    {
        int newID = LL->tail->ID;
        LL->delete_tail();
        return newID;
    };
};

void input(myqueue *q, mystack *s)
{
    for (int i = 0; i < 10; i++)
    {
        q->enqueue(new node(i));
        s->push(new node(i));
    };
};
void output(myqueue *q, mystack *s)
{
    for (int i = 0; i < 10; i++)
    {
        cout << "outputting queue" << endl;
        int newID = q->dequeue();
        cout << newID << endl;
    };
    for (int i = 0; i < 10; i++)
    {
        cout << "outputting stack" << endl;
        int newID = s->pop();
        cout << newID << endl;
    };
};

int main()
{
    myqueue *q = new myqueue(10);
    mystack *s = new mystack(10);

    input(q, s);
    output(q, s);

    return 0;
};
