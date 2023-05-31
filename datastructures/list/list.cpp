#include<iostream>
#include<cstdlib>

using namespace std;
template <class T>
class Node {
    public:
        T data;
        Node<T>* Next = NULL;

        Node(T value):data(value),Next(NULL){}

        Node(T value, Node<T>* TemporaryNext):data(value),Next(TemporaryNext){}
};

template <class T>
class LinkedList{
    private:
        Node<T>* Head;
        Node<T>* Tail;
    public:
        //default constructor. We initialize the head/Tail with a NULL.
        LinkedList():Head(NULL),Tail(NULL){}

        //function for inserting element at the head of the list.
        void push_back(T value){
            //start with making a new node.
            Node<T>* new_node = new Node<T>(value);

            //If list is empty make the head as a new node
            if (Head == NULL) {
                Head = new_node;
                }else{
                    new_node->Next = Head;
                    Head = new_node;
            }
        }

        //function for inserting element at the end of the list
        void push_front(T value){
            //start with making a new node.
            Node<T>* new_node = new Node<T>(value);

            //If list is empty make the head as a new node
            if(Head == NULL){
                Head = new_node;
            }else{
                new_node->Next = Head;
                Head = new_node;
            }
        }

        //loop over the list to find a element
        //returns true if found
        bool search(T value){
            Node<T>* temp = Head;
            while (temp != NULL){
                if (temp->data == value){
                    return true;
                }
                temp = temp->Next;
            }
            return false;
        }

        void remove(T value){
            Node<T>* temp = Head;

            if(temp != NULL && temp->data == value){
                Head = temp->Next;
                delete temp;
                return;
            }else{//else loop over the list and search for the node to delete.
                Node<T>* current = Head;
                while(temp != NULL && temp->data != value){
                    current = temp;
                    temp = temp->Next;
                }
                // if the value is not found in the linked list
                if(!temp){
                    cout<<"Value not found\n";
                    return;
                }
                current->Next = temp->Next;
                delete temp;
            }
        }

        void display(){
            Node<T>* temp = Head;
            while(temp != NULL){
                cout<<"Node->data: "<<temp->data<<endl;
                temp = temp->Next; 
            } 
            cout<< endl;
        }

        void reverse(){
            Node<T>* Current = Head;
            Node<T>* Previous = NULL;
            Node<T>* Next = NULL;

            while (Current != NULL){
                //store next.
                Next = Current->Next;
                //reverse current's Node pointer.
                Current->Next = Previous;
                // Move pointer one position ahead;
                Previous = Current;
                Current = Next;
            }
            Head = Previous;
        }
};


int main(){

    LinkedList<int> l;
    //Inserting elements
    l.push_back(6);
    l.push_back(9);
    l.push_back(1);
    l.push_back(3);
    l.push_back(7);
    //using void display()
    cout<<"Current Linked List before reverse: \n";
    l.display();
    cout<<"\nAdd element 10 at the front: \n";
    l.push_front(10);
    l.display();
    l.reverse();
    cout<<"\nReversed Linked list: \n";
    l.display();
    cout<<"\nRemoving 10 from linked list: \n";
    l.remove(10);
    l.display();
    
}