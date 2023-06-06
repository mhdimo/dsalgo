#include<iostream>

using namespace std;
template<class T>
class Node{
    public:
        T data;
        Node<T>* left;
        Node<T>* right;
        Node() : left(nullptr), right(nullptr) {}
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

        Node<T>* Find(Node<T>* t, int x) {
            while (t != NULL) {
                if (x < t->data) {
                    t = t->left;
                } else if (x > t->data) {
                    t = t->right;
                } else {
                    return t;  // Elemento trovato
                }
            }
            return NULL;  // Elemento non trovato
        }        

        void InOrder(Node<T>* t) {
            if(t == NULL){
                return;
            }
            InOrder(t->left);
            cout<<t->data<<" ";
            InOrder(t->right);
        }

        void PreOrder(Node<T>* t) {
            if(t == NULL){
                return;
            }
            cout<<t->data<<" ";
            PreOrder(t->left);
            PreOrder(t->right);
        }

        void PostOrder(Node<T>* t) {
            if(t == NULL){
                return;
            }
            PostOrder(t->left);
            PostOrder(t->right);
            cout<<t->data<<"";
        }

        void Display(Node<T>* t) {
            if(t == NULL){
                return;
            }
            Display(t->left);
            cout << t->data << " ";
            Display(t->right);
        }

        int Height(Node<T>* t){
            if(t == NULL){
                return 0; //l'altezza di un albero vuoto e' 0
            }

            int LeftHeight = Height(t->left);
            int RightHeight = Height(t->right);
            // L'altezza dell'albero è l'altezza massima tra il sottoalbero sinistro e destro,
            // incrementata di 1 per tener conto del nodo corrente.
            return max(LeftHeight, RightHeight) +1;
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

            int Height(){
                return Height(root);
                cout << endl;
            }      

            void InOrder() {
                InOrder(root);
                cout << endl;
            }

            void PostOrder() {
                PostOrder(root);
                cout << endl;
            }

            void PreOrder() {
                PreOrder(root);
                cout << endl;
            }

            void Display() {
                Display(root);
                cout << endl;
            }

            T Search(T x) {
                Node<T>* foundNode = Find(root, x);
                if (foundNode != nullptr) {
                    return foundNode->data;  // Restituisce il valore del nodo trovato
                }
                return T();  // Restituisce un valore di default se l'elemento non è presente
            }


};


int main() {
    BST<int> t;

    cout<<"BST Example:"<<endl;
    t.Insert(20);
    t.Insert(25);
    t.Insert(15);
    t.Insert(10);
    t.Insert(30);

    cout<<"PreOrder:"<<endl;
    t.PreOrder();
    cout<<"PostOrder:"<<endl;
    t.PostOrder();
    cout<<"Inorder:"<<endl;
    t.InOrder();

    cout<<"\nAdd more data and do Find and deletion:";
    t.Insert(23);
    t.Insert(54);
    t.Insert(22);
    t.Insert(67);
    t.Insert(45);

    cout<<"\nDelete 67:\n";
    t.Remove(67);
    t.Display();
    cout<<"\nDelete 25:\n";
    t.Display();
    int searchval = 100;
    cout<<"\nFind "<<searchval<<", if the number is in the tree it will return the same number:\n";
    cout<<t.Search(searchval);
    cout<<"\nAltezza dell'albero: " << t.Height() << endl;


    return 0;
}