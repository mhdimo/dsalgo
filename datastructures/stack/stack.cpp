#include<iostream>
#include<cstdlib>

using namespace std;

template<class S>
class Node {
    public:
        S data;
        Node<S>* Next = NULL;

        Node(S value):data(value),Next(NULL){}

        Node(S value, Node<S>* TemporaryNext):data(value),Next(TemporaryNext){}
};

template<class S>
class Stack {
    private:
        Node<S>* Head;
        Node<S>* Tail;

    public:
        //default constructor. We initialize the head/Tail with a NULL.
        Stack():Head(NULL),Tail(NULL){}

        //function for inserting element at the head of the list.
        void push_back(S value){
            //start with making a new node.
            Node<S>* new_node = new Node<S>(value);

            //If list is empty make the head as a new node
            if (Head == NULL) {
                Head = new_node;
                }else{
                    new_node->Next = Head;
                    Head = new_node;
            }
        }

        //function for removing the last element inserted at the head
        S Pop(){
            if (this->Head == NULL){ // check if stack is empty
                cerr<<"Pop(): stack is empty.\n";
                return -1;
            }
            //PopValue gets the data of the head so we can return it
            S PopValue = this->Head->data;
            //Deletion of the head and assign it to the next node
            Node<S>* tmp = Head;
            Head = Head->Next;
            delete tmp;

            return PopValue;
        }

        //Function for removing a specific value from the stack.
        void remove(S value){
            Node<S>* temp = Head;

            if(temp != NULL && temp->data == value){
                Head = temp->Next;
                delete temp;
                return;
            }else{//else loop over the list and search for the node to delete.
                Node<S>* current = Head;
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

        bool IsEmpty(){ // verify if the stack is full or not
            if(this->Head){
                cout<<"IsEmpty(): Stack has at least 1 element.\n";
                return false;
            } else{
                cerr<<"IsEmpty(): Stack is empty.\n";
                return true;
            }
        }

        void display(){
            Node<S>* temp = Head;
            while(temp != NULL){
                cout<<"Node->data: "<<temp->data<<endl;
                temp = temp->Next; 
            } 
            cout<< endl;
        }

        void reverse(){
            Node<S>* Current = Head;
            Node<S>* Previous = NULL;
            Node<S>* Next = NULL;

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

        ~Stack(){
            Node<S>* iter = this->Head;

            while (iter){
                Node<S>* tmp = iter;
                iter = iter->Next;
                delete tmp;
            }
        }
};


int main(){

    Stack<int> S;
    //Inserting elements
    S.push_back(6);
    S.push_back(9);
    S.push_back(1);
    S.push_back(3);
    S.push_back(7);
    //using void display()
    cout<<"Current Linked List before reverse: \n";
    S.display();
    cout<<"\nAdd element 10 at the front: \n";
    S.push_back(10);
    S.display();
    S.reverse();
    cout<<"\nReversed Linked list: \n";
    S.display();
    S.remove(10);
    cout<<"\nRemoving 10 from linked list: \n";
    S.display();
    cout<<"\nPop(): ";
    int spop;
    spop = S.Pop();
    cout<<spop<<"\n";
    S.display();
}