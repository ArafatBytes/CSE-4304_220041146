#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int>& heap,int heapSize, int idx){
    int left=(2*idx)+1;
    int right=(2*idx)+2;
    int smallest=idx;
    if(left<heapSize && heap[left]<heap[smallest]){
        smallest=left;
    }
    if(right<heapSize && heap[right]<heap[smallest]){
        smallest=right;
    }
    if(smallest!=idx){
        swap(heap[smallest],heap[idx]);
        heapify(heap,heapSize,smallest);
    }
}

void buildMinHeap(vector<int>& heap){
    int size= heap.size();
    for(int i=((size)/2)-1;i>=0;i--){
        heapify(heap,size,i);
    }
}

void heapSort(vector<int>& heap){
    int size=heap.size();
    for(int i=size-1;i>0;i--){
        swap(heap[0],heap[i]);
        size--;
        heapify(heap,size,0);
    }
}

int main(){
    vector<int>heap;
    while(true){
        int n;
        cin>>n;
        if(n==-1){
            break;
        }
        else{
            heap.push_back(n);
        }
    }
    buildMinHeap(heap);
    cout<<"Min Heap: ";
    for(int i=0;i<heap.size();i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    heapSort(heap);
    cout<<"Sorted: ";
    for(int i=heap.size()-1;i>=0;i--){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}