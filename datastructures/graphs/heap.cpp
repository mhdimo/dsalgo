#include <iostream>
using namespace std;

template<class H>
class Heap {
    private:
        H Size; //defined size for the array "heap_array"
        H Heap_size;
        H* Heap_array;

        inline H Left(H i){return (i << 1)+1;}
        inline H Right(H i){return (i << 1)+2;}
        inline H Parent(H i){return i >> 1;}
    public:
		Heap(H hs = 100):Size(hs){
            Heap_size = 0;
            Heap_array = new H[hs];
        }

        ~Heap(){
            delete [] Heap_array;
        }

        void exchange(H& n, H& m){
            H Temp;
            Temp = n;
            n = m;
            m = Temp;
            return;
        }

        void Insert(H e){
            H i;
            H parent_i;

            if(Heap_size < Size){
                i = Heap_size++;
                Heap_array[i] = e;
                parent_i = Parent(i);
                while ((i > 0) && (Heap_array[parent_i] < Heap_array[i])) {
			        exchange(Heap_array[i], Heap_array[parent_i]);
			        i = parent_i;
			        parent_i = Parent(i);
			        // ShowHeap (this);
		        }
                Heap_array[i] = e;
            } else {
                cout<< "Insert(): Heap is full";
            }
            return;
        }

        H Maximum(){
            if(Heap_size > 0) {
                return Heap_array[0];
            } else {
                cout<<"Maximum(): Heap is empty!";  
            }
        }

        void Heapify(H i){
            H Largest;
            H Left_i; 
            H Right_i;

            if ((Left_i = Left(i)) > Heap_size-1){
                Left_i = i; //Left(i) is out of range
            }
            if ((Right_i = Right(i)) > Heap_size-1){
                Right_i = i; //Right(i) is out of range
            }

            Largest = i;
            if(Heap_array[Largest] < Heap_array[Left_i]){
                Largest = Left_i;
            }
            if(Heap_array[Largest] < Heap_array[Right_i]){
                Largest = Right_i;
            }
            //Largest is the maximum index between Heap_array[i], Heap_array[Left_i],
	        // Heap_array[Right_i]

            if (i != Largest) {
	    	    exchange(Heap_array[i], Heap_array[Largest]);
	    	    Heapify(Largest);
	        }
        }

        void ExtractMaximum(){
        	if (Heap_size > 0) {
        		Heap_array[0] = Heap_array[Heap_size-1];
        		Heap_size--;
        		// ShowHeap(this);
        		Heapify(0);
        	} else {
                cout << "ExtractMaximum: heap is empty\n";
            }
        }

        void ShowHeap (Heap<H>* h){
        	for (int i = 0; i < h->Heap_size; i++){
        		cout << h->Heap_array[i] << " Left(i)="<<h->Heap_array[Left(i)]<<", Right(i)="<<h->Heap_array[Right(i)]<<endl;
            }
            cout<<endl;
        }
};


int main (void)
{
	cout << "Heap in C++" << endl;
	Heap<int> hp;
	
	hp.Insert(16); // ShowHeap(&hp);
	hp.Insert(7);  // ShowHeap(&hp);
	hp.Insert(14); // ShowHeap(&hp);
	hp.Insert(9);  // ShowHeap(&hp);
	hp.Insert(1);  // ShowHeap(&hp);
	hp.Insert(8);  // ShowHeap(&hp);
	hp.Insert(10);
	hp.Insert(3);
	hp.Insert(2);
	hp.Insert(4); 

    hp.ShowHeap(&hp);

	hp.Insert(15);
	hp.ShowHeap(&hp);

	hp.ExtractMaximum(); 
    hp.ShowHeap(&hp);

	return 0;
}
