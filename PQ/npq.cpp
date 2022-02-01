#include <iostream>
#include <cstring>
#define HEAPSIZE 30

using namespace std;

void heapify(struct Heap heap[], int element, int hsize);
void build_min_heap(struct Heap heap[]);
void heap_sort(struct Heap heap[]);

struct Heap{
    string name;
    float score;
    int size = 0;
};

//function to return heap size
int heap_size(struct Heap heap[]){ 
    return heap->size;
}

//function to swap the heap
void swap(struct Heap *a, struct Heap *b){ 
    struct Heap c = *a;
    *a = *b;
    *b = c;
}

//function to insert name/score to heap, apply minheap while doing
void heap_push(struct Heap heap[], string input_name, float input_score){
    struct Heap nheap; //temp heap
    nheap.name = input_name;
    nheap.score = input_score;

    int idx = heap_size(heap) + 1; //index to start from 1 not 0

    heap[idx].name = nheap.name; //copy value to following index
    heap[idx].score = nheap.score;
    heap->size += 1; //after copying, move to next index

    //do minheap
    while (idx > 0 && heap[(idx - 1) / 2].score > heap[idx].score){ //until parent score is smaller than child
        swap(heap[idx], heap[(idx - 1) / 2]); //swap parent and child
        idx = (idx - 1) / 2; //until index reaches top
    }
}

//to delete the smallest key in queue
void heap_pop(struct Heap heap[], string name, float score){
    string hname = name;
    float hscore = score;
    int hsize = heap_size(heap);
    swap(heap[1], heap[hsize]);

    heap[hsize].name = ""; //make it null
    heap[hsize].score = 0; 

    if (heap->size == 0)
        cout << "Nothing to delete" << endl;
    else if (heap->size > 0){
        heap->size -= 1; //decrease the size by 1
        cout << "[" << hname << ", " << hscore << "] is deleted." << endl;
    }

    heapify(heap, 1, heap_size(heap)); //recall heapify to maintain min heap structure
}

//decrease function
void heap_decrease(struct Heap heap[], int idx_element, float c_value){
    heap[idx_element].score = c_value; //insert the new value according to the scanned element index
    build_min_heap(heap); //recall minheap function to maintain heap-structure
}

//heapify to check which heap is smallest
void heapify(struct Heap heap[], int element, int hsize){
    int smallest;
    int left = element * 2; //left hand
    int right = element * 2 + 1; //right hand
    //if lefthand exist and is less than current score, set left as smallest
    if (left <= hsize && heap[left].score < heap[element].score)
        smallest = left;
    else smallest = element;
    //if righthand exist and is less than current score, set right as smallest
    if (right <= hsize && heap[right].score < heap[element].score)
        smallest = right;
    //if the given element is not the smallest, call swap to swap between parent and child
    if (smallest != element){
        swap(heap[smallest], heap[element]);
        heapify(heap, smallest, hsize); //recall heapify to check the sides
    }
}

//to maintain minheap structure
void build_min_heap(struct Heap heap[]){
    int hsize = heap_size(heap); //copy size of heap to temp
    //call heapify until down to 1
    for (int i = hsize/2; i >= 1; --i){
        heapify(heap, i, hsize);
    }
}

//print all the keys in the heap
void heap_print(struct Heap heap[]){
    for (int i = 1; i <= heap_size(heap); ++i){
        cout << "[" << heap[i].name << ", " << heap[i].score << "] ";
    }
    cout << endl;
}

int main(void){
    float input_score, c_value;
    string input_name, menu_key;
    int idx_element;

    struct Heap heap[HEAPSIZE];

    while(1){
        cout << "\n";
        cout << "*********** MENU ***********\n";
        cout << "I : Insert new element into queue.\n";
        cout << "D : Delete element with smallest key from queue.\n";
        cout << "C : Decrese key of element in queue.\n";
        cout << "P : Print out all elements in queue.\n";
        cout << "Q : Quit.\n" << endl;

        cout << "Choose menu: ";
        cin >> menu_key; //enter key

        //Quit
        if (menu_key == "Q" || menu_key == "q"){
            cout << "Thank you. Bye!" << endl;
            break;
        }
        //Insertion
        else if (menu_key == "I" || menu_key == "i"){
            if (heap_size(heap) < HEAPSIZE){
                cout << "Enter name of element: ";
                cin >> input_name;
            
                while (input_name.length() > 10){
                    input_name = "";
                    cout << "Name is too long." << endl;
                    cout << "Enter name of element: ";
                    cin >> input_name;
                }

                cout << "Enter value of element: ";
                cin >> input_score;
                
                while (input_score > 100.0){
                    input_score = 0;
                    cout << "The value is too big. Make it smaller than 100.0" << endl;
                    cout << "Enter value of element: ";
                    cin >> input_score;
                }
                
                while (input_score < 0.0){
                    input_score = 0;
                    cout << "The value is too small. Make it bigger than 0.0" << endl;
                    cout << "Enter value of element: ";
                    cin >> input_score;
                }
                
                heap_push(heap, input_name, input_score); //send size, name, score
            }
            else{
                cout << "HEAP already full. (MAXIMUM IS 30)" << endl;
            }
        }
        //Deletion
        else if (menu_key == "D" || menu_key == "d"){
            string dname = heap[1].name; //the first index of the heap
            float dscore = heap[1].score; 
            heap_pop(heap, dname, dscore); //call pop funtion
        }
        //Decrease
        else if (menu_key == "C" || menu_key == "c"){
            cout << "Enter index of element: ";
            cin >> idx_element; //get the index number of wanted element
            cout << "Enter new key value: ";
            cin >> c_value; //get new score that need to be replaced

            heap_decrease(heap, idx_element, c_value); //call decrease funtion
        }
        //exception
        else if (menu_key == "P" || menu_key == "p"){
            heap_print(heap);
        }
        else{
        }
    }
    return 0;
}