#include<iostream>
#include<vector>
#include<queue>
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

int main(){
    queue<int>input;
    vector<int>pq;
    int n;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        input.push(a);
    }
    while(!input.empty()){
        vector<int>cpy;
        vector<int>sorted;
        int top=input.front();
        input.pop();
        min_heap_insert(pq,top);
        cpy=pq;
        while(!cpy.empty()){
            int min=heap_extract_min(cpy);
            sorted.push_back(min);
        }
        int lastidx=sorted.size();
        if(lastidx>2){
            int multiple=sorted[lastidx-1]*sorted[lastidx-2]*sorted[lastidx-3];
            cout<<multiple<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}