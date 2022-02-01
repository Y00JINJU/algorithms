//priority queue by sungjin's assignment
#include <iostream>

#define HEAPSIZE 31

using namespace std;

void heapify(struct Heap heap[], int element, int hsize);
void build_min_heap(struct Heap heap[]);
void heap_sort(struct Heap heap[]);

struct Heap{
    string name;
    float score;
    int size = 0;
    //int& operator[] (float index) { return *(&score + index); }
};

void menu(){
    cout << "\n";
    cout << "************ MENU ************" << endl;
    cout << "I: Insert new element into queue." << endl;
    cout << "D: Delete elelment with smallest key from queue." << endl;
    cout << "C: Decrease key of element in queue." << endl;
    cout << "P: Print cout all elements in queue." << endl;
    cout << "Q: Quit" << endl;
    cout << "\n";
}

int heap_size(struct Heap heap[]){
    return heap->size;
}

void swap(struct Heap *a, struct Heap *b){
    cout << "swap" << endl;
    struct Heap c = *a;
    *a = *b;
    *b = c;
}

void heap_push(struct Heap heap[], string input_name, float input_score){
    struct Heap nheap;
    nheap.name = input_name;
    nheap.score = input_score;

    int idx = heap_size(heap) + 1;

    heap[idx].name = nheap.name;
    heap[idx].score = nheap.score;
    heap->size += 1;

    //min heap
    while (idx > 0 && heap[(idx-1) / 2].score > heap[idx].score){
        swap(heap[idx], heap[(idx-1) / 2]);
        idx = (idx - 1) / 2;
    }
}

void heap_pop(struct Heap heap[]){
    
    int hsize = heap_size(heap);
    swap(heap[1], heap[hsize]);

    heap[hsize].name = "";
    heap[hsize].score = 0;
    heap->size -= 1;

    heapify(heap, 1, heap_size(heap));

}

void heap_decrease(struct Heap heap[], int idx_element, int c_value){
    
    heap[idx_element].score = c_value;

    build_min_heap(heap);

}

void heapify(struct Heap heap[], int element, int hsize){
    int smallest;
    int left = element * 2;
    int right = element * 2 + 1;

    if (left <= hsize && heap[left].score < heap[element].score){
        smallest = left;
    } 
    else smallest = element;

    if (right <= hsize && heap[right].score < heap[element].score){
        smallest = right;
    }

    if (smallest != element){
        swap(heap[smallest], heap[element]);
        heapify(heap, smallest, hsize);
    }
}

void build_min_heap(struct Heap heap[]){

    int hsize = heap_size(heap);

    for (int i = hsize/2; i >= 1; --i){
        heapify(heap, i, hsize);
    }
}

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
        menu();
        
        cout << "Choose menu: ";
        cin >> menu_key;

        if (menu_key == "Q" || menu_key == "q"){
            cout << "Quit the program" << endl;
            break;
        }

        else if (menu_key == "I" || menu_key == "i"){
            cout << "Enter name of element: ";
            cin >> input_name;

            if (input_name.length() > 10){
                input_name = "";
                cout << "too long" << endl;
                cout << "again:: ";
                cin >> input_name;
            }
            
            cout << "Enter value of element: ";
            cin >> input_score;

            

            heap_push(heap, input_name, input_score);

            cout << "New element [" << input_name << ", " << input_score << "] is inserted." << endl;

        }

        else if (menu_key == "D" || menu_key == "d"){
            string dname = heap[1].name;
            float dscore = heap[1].score;

            heap_pop(heap);
            
            cout << "[" << dname << ", " << dscore << "] is deleted." << endl;
        }

        else if (menu_key == "C" || menu_key == "c"){
            cout << "Enter index of element: ";
            cin >> idx_element;
            
            cout << "Enter new key value: ";
            cin >> c_value;

            heap_decrease(heap, idx_element, c_value);
        }

        else if (menu_key == "P" || menu_key == "p"){
            heap_print(heap);
        }

        else{
            cout << "Please check menu" << endl;
            cout << endl;
        }
        
    }
}

// pop다 했을 때 원소가 없습니다. 
// 31이상됐을 때 더이상 넣지 못합니다 하면서 아무런 행동 안하기 
// score 의 범위도 정해주고, name의 사이즈랑 a > z~ A> Z 이런 알파벳만 사용가능한거 