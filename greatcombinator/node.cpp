#include "node.h"
#include <iostream>

using namespace std;

void createStartNode(Node *head)
{
    int digit1 = 1;
    int digit2 = 1;
    int digit3 = 1;
    int digit4 = 1;

    while (digit1 != 7)
    {
        add_node(head, digit1, digit2, digit3, digit4);
        digit4++;
        if (digit4 == 7)
        {
            digit4 = 1;
            digit3++;
            if (digit3 == 7)
            {
                digit3 = 1;
                digit2++;
                if (digit2 == 7)
                {
                    digit2 = 1;
                    digit1++;
                }
            }
        }
    }
}


void add_node(Node *head, int digit1, int digit2, int digit3, int digit4) {
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node;
    temp->next->next = NULL;
    temp->next->array[0] = digit1;
    temp->next->array[1] = digit2;
    temp->next->array[2] = digit3;
    temp->next->array[3] = digit4;
}

void removeValue(Node *head, int digit1, int digit2, int digit3, int digit4)
{
    Node* temp = head;
    bool isRemoved = false;
    while (temp->next && !isRemoved)
    {
        if (temp->next->array[0] == digit1 && temp->next->array[1] == digit2
                && temp->next->array[2] == digit3 && temp->next->array[3] == digit4)
        {
            Node* tmp = temp->next->next;
            delete temp->next;
            temp->next = tmp;
            isRemoved = true;
        }
        else
        {
            temp = temp->next;
        }
    }
}

void print_node(Node* current, int numberOfProbe) {


    cout << "My probe" << numberOfProbe << ": "
            << current->array[0]
            << current->array[1]
            << current->array[2]
            << current->array[3] << endl;
}

int numberOfValues(Node* head)
{
    int result = 0;
    Node* temp = head->next;
    while(temp)
    {
        result++;
        temp = temp->next;
    }
    return result;
}
