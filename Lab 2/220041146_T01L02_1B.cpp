#include <iostream>
#include <vector>
using namespace std; 

void EnQueue(int Queue[], int &f, int &r, int &c, int n, int val){
    if(c==n){
        cout<<"EnQueue: Overflow"<<endl;
    }
    else{
        Queue[r]=val;
        r=(r+1)%n;
        c++;
        cout<<"EnQueue: ";
        int temp=c,i=f;
        while(temp--){
            cout<<Queue[(i++)%n]<<" ";
        }
        cout<<endl;
    }
}

void DeQueue(int Queue[], int &f, int &r, int &c, int n){
    if(c==0){
        cout<<"DeQueue: Underflow"<<endl;
    }
    else{
        f=(f+1)%n;
        c--;
        cout<<"DeQueue: ";
        int temp=c,i=f;
        while(temp--){
            cout<<Queue[(i++)%n]<<" ";
        }
        cout<<endl;
    }
}

bool isEmpty(int &c){
    if(!c){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(int &c, int n){
    if(c==n){
        return true;
    }
    else{
        return false;
    }
}

void sizeOfQueue(int &c){
    cout<<"Size: "<<c<<endl;
}

void Front(int Queue[], int &f){
    cout<<"Front: "<<Queue[f]<<endl;
}

int main(){
    int count=0, front=0, rear=0;
    int N;
    cin>>N;
    int Queue[N];
    int a=0;
    while(a!=-1){
        cin >> a;
        switch(a){
            case 1:
            int b;
            cin>>b;
            EnQueue(Queue,front,rear,count,N,b);
            break;
            
            case 2:
            DeQueue(Queue,front,rear,count,N);
            break;

            case 3:
            if(isEmpty(count)){
                cout<<"isEmpty: True"<<endl;
            }
            else{
                cout<<"isEmpty: False"<<endl;
            }
            break;

            case 4:
                if(isFull(count,N)){
                    cout<<"isFull: True"<<endl;
                }
                else{
                    cout<<"isFull: False"<<endl;
                }
            break;

            case 5:
            sizeOfQueue(count);
            break;

            case 6:
            Front(Queue,front);
            break;
        }
    }
    cout<<"Exit"<<endl;
}