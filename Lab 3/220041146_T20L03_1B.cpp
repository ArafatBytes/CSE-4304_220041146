#include<iostream>
#include<vector>
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

int heap_extract_max(vector<int>& heap){
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
    int n;
    cin>>n;
    vector<int>heap,sum;
    int cpy=n;
    while(cpy--){
        int a;
        cin>>a;
        heap.push_back(a);
    }
    int k;
    cin>>k;
    for(int i=0;i<n;i++){
        int summation=0;
        for(int j=i;j<n;j++){
            summation+=heap[j];
            sum.push_back(summation);
        }
    }
    buildMaxHeap(sum);
    int res;
    while(k--){
        res=heap_extract_max(sum);
    }
    cout<<res<<endl;
}