#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
private:
    Node *head = NULL;
    Node *tail = NULL;
    void firstNode(Node *n)
    {
        this->head = n;
        this->tail = n;
    }

public:
    void print()
    {
        if (!this->head)
        {
            return;
        }

        Node *temp = this->head;
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void push(int data)
    {
        Node *n = new Node(data);

        if (!this->head)
        {
            firstNode(n);
            return;
        }

        this->tail->next = n;
        this->tail = n;
    }
    void pop()
    {
        if (!this->head)
        {
            return;
        }

        Node *temp = this->head;

        if (!temp->next)
        {
            this->head = NULL;
            this->tail = NULL;
            return;
        }

        while (temp->next->next)
        {
            temp = temp->next;
        }
        delete temp->next->next;
        temp->next = NULL;
    }
    void unshift(int data)
    {
        Node *n = new Node(data);
        if (!this->head)
        {
            firstNode(n);
            return;
        }

        n->next = this->head;
        this->head = n;
    }
    void shift()
    {
        if (!this->head)
        {
            return;
        }

        Node *deletedNode = this->head;
        if (!this->head->next)
        {
            this->head = NULL;
            this->tail = NULL;
            delete deletedNode;
            return;
        }

        this->head = this->head->next;
        delete deletedNode;
    }
};

int main()
{

    LinkedList arr;

    arr.push(1);
    arr.push(2);
    arr.push(3);
    arr.push(4);
    arr.pop();
    arr.pop();
    arr.pop();
    arr.pop();
    arr.unshift(1);
    arr.unshift(2);
    arr.unshift(3);
    arr.unshift(4);
    arr.shift();
    arr.shift();
    arr.shift();
    arr.shift();
    arr.print();

    cout << "DONE" << endl;
    return 0;
}