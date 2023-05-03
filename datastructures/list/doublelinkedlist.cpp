#include<iostream>
#include<cstdlib>

using namespace std;
template <class T>
class Node{
    public:
        int data;
        Node<T>* Next = NULL;
        Node<T>* Previous = NULL;

        Node(T value):data(value),Next(NULL), Previous(NULL){}

        Node(T value, Node<T>* TemporaryNext, Node<T>* TemporaryPrevious):data(value),Next(TemporaryNext),Previous(TemporaryPrevious){}
};

template <class T>
class LinkedList{
    private:
        Node<T>* Head;
        Node<T>* Tail;
    public:
        //default constructor. We initialize the head with a NULL.
        LinkedList():Head(NULL){}

        //function for inserting element at the start of the list.
        void push_back(T value){
            //start with making a new node.
            Node<T>* new_node = new Node<T>(value);

            //If list is empty make the head as a new node
            if (Head == NULL) {
                Head = new_node;
                Tail = new_node;
                }else{
                    
                    new_node->Next = NULL;
                    new_node->Previous = Tail;
                    //Set the Next pointer of the current last node to the new node 
                    Tail->Next = new_node;

                    //Set the new node as the new Tail of the list
                    Tail = new_node;
            }
        }

        //function for inserting element at the end of the list
        void push_front(T value){
            //start with making a new node.
            Node<T>* new_node = new Node<T>(value);

            //If list is empty make the head as a new node
            if(Head == NULL){
                Head = new_node;
                Tail = new_node;
            }else{
                //Set the Next and Previous pointers of the new node.
                new_node->Next = Head;
                new_node->Previous = NULL;

                //Set the Previous pointer of the current first node to the new node.
                Head->Previous = new_node;

                //Set the new node as the new Head of the List
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
                if(Head != NULL){
                    Head->Previous = NULL;
                }
                delete temp;
                return;
            }else{//else loop over the list and search for the node to delete.
                while(temp != NULL && temp->data != value){
                    temp= temp->Next;
                }
                // if the value is not found in the linked list
                if(!temp){
                    cout<<"Value not found\n";
                    return;
                }
                temp->Previous->Next = temp->Next;
                if(temp->Next){
                    temp->Next->Previous = temp->Previous;
                }
                
                delete temp;
                return;
            }
        }

        void display(){
            Node<T>* temp = Head;

            while(temp != NULL){
                cout<<"Node->data: "<<temp->data<<", ";
                if(temp->Previous == NULL){
                    cout<< "left: NULL ";
                }else{
                    cout<<"left: "<< temp->Previous->data <<", ";
                }
                if(temp->Next == NULL){
                    cout<<"right: NULL ";
                }else{
                    cout<<"right: "<<temp->Next->data;
                }
                cout<<endl;
                temp = temp->Next; 
            }
            cout<< endl;
        }

        void reverse(){
            Node<T>* Current = Head;
            Node<T>* temp = NULL;

            while (Current != NULL){
                //store next & Previous node.
                //reverse current's Node pointer.
                temp = Current->Previous;
                Current->Previous = Current->Next;
                Current->Next = temp;
                // Move pointer one to the next Node;
                Current = Current->Previous;
            }
            // Set the head to last node (which is the original tail).
            Head = temp->Previous;
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
    l.remove(10);
    cout<<"\nRemoving 10 from linked list: \n";
    l.display();
    
}