#ifndef NODE_H
#define NODE_H

struct Node {
    int array[4];
    Node *next;
};

void createStartNode(Node* head);
void add_node(Node *head, int digit1, int digit2, int digit3, int digit4);
void removeValue(Node* head, int digit1, int digit2, int digit3, int digit4);
void print_node(Node* current, int numberOfProbe);
int numberOfValues(Node* head);

#endif // NODE_H
