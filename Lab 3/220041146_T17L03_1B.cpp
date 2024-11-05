#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Data {
    string firstName;
    string lastName;
    int age;
    string house;
};

void heapify(vector<Data>& heap,int heapSize, int idx){
    int left=(2*idx)+1;
    int right=(2*idx)+2;
    int largest=idx;
    if(left<heapSize && heap[left].age>heap[largest].age){
        largest=left;
    }
    if(right<heapSize && heap[right].age>heap[largest].age){
        largest=right;
    }
    if(largest!=idx){
        swap(heap[largest],heap[idx]);
        heapify(heap,heapSize,largest);
    }
}

void buildMaxHeap(vector<Data>& heap){
    int size= heap.size();
    for(int i=((size)/2)-1;i>=0;i--){
        heapify(heap,size,i);
    }
}

Data heap_extract_max(vector<Data>& heap){
    if(heap.empty()){
        cout<<"Underflow!"<<endl;
        return Data();
    }
    Data max=heap[0];
    int size=heap.size();
    swap(heap[0],heap[size-1]);
    size--;
    heap.pop_back();
    heapify(heap,size,0);
    return max;
}

void max_heap_insert(vector<Data>& heap, Data val){
    heap.push_back(val);
    int idx=heap.size()-1;
    while(idx>=0){
        int parent=((idx-1)/2);
        if(heap[parent].age<heap[idx].age){
            swap(heap[parent],heap[idx]);
            idx=parent;    
        } 
        else{
            break;
        }    
    }
}

void takeInfo(vector<Data>& heap){
    string fr,sd;
    cin>>fr>>sd;
    int a;
    cin>>a;
    string ad;
    cin>>ad;
    max_heap_insert(heap,{fr,sd,a,ad});
}

void serve(vector<Data>& heap){
    Data output=heap_extract_max(heap);
    cout<<"Name: "<<output.firstName<<" "<<output.lastName<<", Age: "<<output.age<<", House: "<<output.house<<endl;
}

int main(){
    vector<Data>heap;
    char op;
    while(true){
        cin>>op;
        if(op=='X'){
            return 0;
        }
        else{
            switch(op){
                case 'I':
                    takeInfo(heap);
                    break;
                case 'S':
                    serve(heap);
                    break;
                default:
                    cout<<"Invalid operation!"<<endl;
            }
        }
    }
}