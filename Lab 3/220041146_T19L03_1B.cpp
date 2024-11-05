#include<iostream>
#include<vector>
#include <cmath>
using namespace std;

void heapify(vector<int>& heap,int heapSize, int idx){
    int left=(2*idx)+1;
    int right=(2*idx)+2;
    int largest=idx;
    if(left<heapSize && heap[left]>heap[largest]){
        largest=left;
    }
    if(right<heapSize && heap[right]>heap[largest]){
        largest=right;
    }
    if(largest!=idx){
        swap(heap[largest],heap[idx]);
        heapify(heap,heapSize,largest);
    }
}

void buildMaxHeap(vector<int>& heap){
    int size= heap.size();
    for(int i=((size)/2)-1;i>=0;i--){
        heapify(heap,size,i);
    }
}

int heap_Maximum(vector<int>& heap){
    return heap[0];
}

int heap_extract_max(vector<int>& heap){
    if(heap.empty()){
        cout<<"Underflow!"<<endl;
        return 0;
    }
    int min=heap[0];
    int size=heap.size();
    swap(heap[0],heap[size-1]);
    size--;
    heapify(heap,size,0);
    return min;
}

void max_heap_insert(vector<int>& heap, int val){
    heap.push_back(val);
    int idx=heap.size()-1;
    while(idx>=0){
        int parent=floor((idx-1)/2);
        if(heap[parent]<heap[idx]){
            swap(heap[parent],heap[idx]);
            idx=parent;    
        } 
        else{
            break;
        }    
    }
}

void heap_decrease_key(vector<int>& heap, int val,int id){
    heap[id]-=val;
    heapify(heap,heap.size(),id);
}

void heap_increase_key(vector<int>& heap, int val,int id){
    heap[id]+=val;
    while(id>=0){
        int parent=((id-1)/2);
        if(heap[parent]<heap[id]){
            swap(heap[parent],heap[id]);
            id=parent;    
        } 
        else{
            break;
        }    
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
    buildMaxHeap(heap);
    cout<<"Max Heap: ";
    for(int i=0;i<heap.size();i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    while(true){
        int a;
        cin>>a;
        switch(a){
            case 1:
                cout<<heap_Maximum(heap)<<endl;
                for(int i=0;i<heap.size();i++){
                    cout<<heap[i]<<" ";
                }
                cout<<endl;
                break;
            case 2:
                cout<<heap_extract_max(heap)<<endl;
                heap.pop_back();
                for(int i=0;i<heap.size();i++){
                    cout<<heap[i]<<" ";
                }
                cout<<endl;
                break;
            case 3:
                int b;
                cin>>b;
                max_heap_insert(heap,b);
                for(int i=0;i<heap.size();i++){
                    cout<<heap[i]<<" ";
                }
                cout<<endl;
                break;
            case 4:
                int p,k;
                cin>>p>>k;
                heap_decrease_key(heap,k,p);
                for(int i=0;i<heap.size();i++){
                    cout<<heap[i]<<" ";
                }
                cout<<endl;
                break;
            case 5:
                int x,y;
                cin>>x>>y;
                heap_increase_key(heap,y,x);
                for(int i=0;i<heap.size();i++){
                    cout<<heap[i]<<" ";
                }
                cout<<endl;
                break;
            default:
                return 0;
        }
    }
}