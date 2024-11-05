#include<iostream>
#include<deque>
using namespace std;

deque<int>Deque;

void move1(){
    int temp=Deque.front();
    Deque.pop_front();
    Deque.push_back(temp);
}

void move2(){
    Deque.pop_front();
}

int main(){
    int N,a;
    cin>>N;
    while(N--){
        cin>>a;
        Deque.push_back(a);
    }
    int count=0;
    while(Deque.size()>1){
        count++;
        if(count%2!=0){
            move1();
            move2();
        }
        else{
            move1();
            move1();
            move2();
        }
    }
    if(count%2==0){
        cout<<"Ishraq "<<Deque.front()<<endl;
    }
    else{
        cout<<"Daiyan "<<Deque.front()<<endl;
    }
}