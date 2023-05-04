#include<iostream>

using namespace std;
template<class T>
class Node{
    public:
        T data;
        Node<T>* left;
        Node<T>* right;
};

template<class T>
class BST {
    private:
        Node<T>*  root;

        Node<T>* MakeEmpty(Node<T>* t){
            if (t == NULL){
                return NULL;
            } else {
                MakeEmpty(t->left);
                MakeEmpty(t->right);
                delete t;
            }
            return NULL;
        }

        Node<T>* Insert(T x, Node<T>* t){
            if (t == NULL){
                t = new Node<T>;
                t->data = x;
                t->left = t->right = NULL;
            }
            else if(x < t->data){
                t->left = Insert(x,t->left);
            } else if(x > t->data) {
                t->right = Insert(x,t->right);
            }
            
            return t;
        }

        Node<T>* FindMin(Node<T>* t){
            if(t == NULL){
                return NULL;
            } else if( t->left == NULL){
                return t;
            }else{
                return FindMin(t->left);
            }
        }

        Node<T>* FindMax(Node<T>* t){
            if(t == NULL){
                return NULL;
            } else if(t->right ==NULL){
                return t;
            } else {
                return FindMax(t->right);
            }
        }

        Node<T>* Remove(T x, Node<T>* t){
            Node<T>* temp;
            if (t == NULL){
                return NULL;
            }else if(x < t->data){
                t->left = Remove(x, t->left);
            }else if(x > t->data){
                t->right = Remove(x, t->right);
            }else if(t->left && t->right){
                temp = FindMin(t->right);
                t->data = temp->data;
                t->right = Remove(t->data, t->right);
            }else{
                temp = t;
                if(t->left == NULL){
                    t = t->right;
                }else if(t-> right == NULL){
                    t = t->left;
                }
                delete temp;
            }

            return t;
        }

        void InOrder(Node<T>* t){
            if(t == NULL){
                return;
            }
            InOrder(t->left);
            cout<<t->data<<" ";
            InOrder(t->right);
        }

        Node<T>* Find(Node<T>* t, int x) {
            if(t == NULL){
                return NULL;
            }else if(x < t->data){
                return find(t->left, x);
            }else if(x > t->data){
                return find(t->right, x);
            }else{
                return t;
            }
        }

        public:

            BST(){ root = NULL; }
            ~BST(){ root = MakeEmpty(root); }

            void Insert(int x) {
                root = Insert(x, root);
            }

            void Remove(int x) {
                root = Remove(x, root);
            }

            void Display() {
                InOrder(root);
                cout << endl;
            }

            void Search(int x) {
                root = Find(root, x);
            }


};


int main() {
    BST<int> t;
    t.Insert(20);
    t.Insert(25);
    t.Insert(15);
    t.Insert(10);
    t.Insert(30);
    t.Display();
    t.Remove(20);
    t.Display();
    t.Remove(25);
    t.Display();
    t.Remove(30);
    t.Display();
    return 0; 
}