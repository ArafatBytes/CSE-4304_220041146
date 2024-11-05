#include<iostream>
#include<string>
#include<deque>
using namespace std;

int main(){
    string S,T;
    cin>>S>>T;
    deque<char>Deque;
    int count=0;
    while(S!=T){
        count++;
        if(count>S.length()){
            break;
        }
        else{
            for(int i=0;i<S.length()-1;i++){
                Deque.push_back(S[i]);
            }
            Deque.push_front(S[S.length()-1]);
        }
        for(int i=0;i<S.length();i++){
            S[i]=Deque.front();
            Deque.pop_front();
        }
        Deque.clear();
    }
    if(count>=S.length()){
        cout<<"No"<<endl;
    }
    else if(count==0){
        cout<<"Yes. Rotation not needed"<<endl;
    }
    else{
        cout<<"Yes. After "<<count<<" clockwise rotations"<<endl;
    }
}