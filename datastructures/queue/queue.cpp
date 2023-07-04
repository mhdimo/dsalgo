#include<iostream>
#include<cstdlib>

using namespace std;

template<class Q>
class Node {
    public:
        Q data;
        Node<Q>* Next = NULL;

        Node(Q value):data(value),Next(NULL){}

        Node(Q value, Node<Q>* TemporaryNext):data(value),Next(TemporaryNext){}
};

template<class Q>
class Stack {
    private:
        Node<Q>* Head;
        Node<Q>* Tail;

    public:
        //default constructor. We initialize the head/Tail with a NULL.
        Stack():Head(NULL),Tail(NULL){}

        //function for inserting element at the head of the list.
        void Enqueue(Q value){
            //start with making a new node.
            Node<Q>* new_node = new Node<Q>(value);

            //If list is empty make the head as a new node
            if (Head == NULL) {
                Head = new_node;
                }else{
                    new_node->Next = Head;
                    Head = new_node;
            }
        }

        //function for removing the last element inserted at the head
        void Dequeue(){
            if (this->Head == NULL && this->Tail == NULL){ // check if stack is empty
                cerr<<"Dequeue(): stack is empty.\n";
                return;
            }
            //PopValue gets the data of the head so we can return it
            Q DequeueValue= this->Head->data;
            //Deletion of the head and assign it to the next node
            Node<Q>* tmp = Head;
            Head = Head->Next;
            if (Head == NULL) {
                Tail = NULL; // if the queue becomes empty after dequeueing, set tail to null
            }
            delete tmp;

            return;
        }

        //Function for removing a specific value from the stack.
        void remove(Q value){
            Node<Q>* temp = Head;

            if(temp != NULL && temp->data == value){
                Head = temp->Next;
                delete temp;
                return;
            }else{//else loop over the list and search for the node to delete.
                Node<Q>* current = Head;
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
            Node<Q>* temp = Head;
            while(temp != NULL){
                cout<<"Node->data: "<<temp->data<<endl;
                temp = temp->Next; 
            } 
            cout<< endl;
        }

        void reverse(){
            Node<Q>* Current = Head;
            Node<Q>* Previous = NULL;
            Node<Q>* Next = NULL;

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
            Node<Q>* iter = this->Head;

            while (iter){
                Node<Q>* tmp = iter;
                iter = iter->Next;
                delete tmp;
            }
        }
};


int main(){

    Stack<int> S;
    //Inserting elements
    S.Enqueue(6);
    S.Enqueue(9);
    S.Enqueue(1);
    S.Enqueue(3);
    S.Enqueue(7);
    //using void display()
    cout<<"Current Queue before reverse: \n";
    S.display();
    cout<<"\nAdd element 10 at the front: \n";
    S.Enqueue(10);
    S.display();
    S.reverse();
    cout<<"\nReversed Linked Queue: \n";
    S.display();
    S.remove(10);
    cout<<"\nRemoving 10 from Queue: \n";
    S.display();
    S.IsEmpty();
}