#include<iostream>
#include<cstdlib>

using namespace std;
template <class T>
class Node {
    public:
        int data;
        Node<T>* Next = nullptr;

        Node(T value):data(value),Next(nullptr){}

        Node(T value, Node* TemporaryNext):data(value),Next(TemporaryNext){}
};

template <class T>
class LinkedList{
    private:
        Node<T>* Head;
    public:
        //default constructor. We initialize the head with a nullptr.
        LinkedList():Head(nullptr){}

        //function for inserting element at the start of the list.
        void insert(T value){
            //start with making a new node.
            Node<T>* new_node = new Node<T>(value);

            //If list is empty make the head as a new node
            if (Head == nullptr) {
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
            while (temp != nullptr){
                if (temp->data == value){
                    return true;
                }
                temp = temp->Next;
            }
            return -1;
        }

        void remove(T value){
            Node<T>* temp = Head;

            if(temp != nullptr && temp->data == value){
                Head = temp->Next;
                delete temp;
                return;
            }else{//else loop over the list and search for the node to delete.
                Node<T>* current = Head;
                while(temp != nullptr && temp->data != value){
                    current = temp;
                    temp = temp->Next;
                }
                // if the value is not found in the linked list
                if(!temp){
                    cout<<"Value not found\n";
                    return;
                }
                current->nexxt = temp->Next;
                delete temp;
            }
        }

        void display(){
            Node<T>* temp = Head;
            while(temp != nullptr){
                cout<<"temp->data: "<<temp->data<<endl;
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
    l.insert(6);
    l.insert(9);
    l.insert(1);
    l.insert(3);
    l.insert(7);
    //using void display()
    cout<<"Current Linked List before reverse: \n";
    l.display();
    cout<<"\nCurrent Linked List after reverse: \n";
    l.reverse();
    l.display();
}