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

void min_heap_insert(vector<int>& heap, int val){
    heap.push_back(val);
    int idx=heap.size()-1;
    while(idx>=0){
        int parent=((idx-1)/2);
        if(heap[parent]>heap[idx]){
            swap(heap[parent],heap[idx]);
            idx=parent;    
        } 
        else{
            break;
        }    
    }
}

int heap_extract_min(vector<int>& heap){
    if(heap.empty()){
        cout<<"Underflow!"<<endl;
        return 0;
    }
    int min=heap[0];
    int size=heap.size();
    swap(heap[0],heap[size-1]);
    size--;
    heap.pop_back();
    heapify(heap,size,0);
    return min;
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
    int ans=0;
    while(heap.size()>1){
        int first=heap_extract_min(heap);
        int second=heap_extract_min(heap);
        int cost=first+second;
        ans+=cost;
        min_heap_insert(heap,cost);
    }
    cout<<ans<<endl;
}