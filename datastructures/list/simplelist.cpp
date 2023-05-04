#include<iostream>

struct node {
    int data;
    node* next = NULL;
};

int main(){
    node* n;
    node* temp;
    node* head;

    n = new node;
    n->data = 10;
    temp = n;
    head = n;

    std::cout<<temp->data<<std::endl;

    n = new node;
    n->data = 20;
    temp->next = n;
    temp = temp->next;

    std::cout<<temp->data<<std::endl;

    n = new node;
    n->data = 30;
    temp->next = n;
    temp = temp->next;

    std::cout<<temp->data<<std::endl;

    n = new node;
    n->data = 40;
    temp->next = n;
    temp = temp->next;
    n->next = NULL;
    std::cout<<temp->data<<std::endl;
    std::cout<<head->data<<std::endl;

    return 0;
}

