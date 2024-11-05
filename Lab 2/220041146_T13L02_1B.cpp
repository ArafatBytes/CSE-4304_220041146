#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int n=1;
    while(n!=0){
        cin>>n;
        if(n==0){
            break;
        }
        queue<int>cards;
        vector<int>output;
        for(int i=1;i<=n;i++){
            cards.push(i);
        }
        while(cards.size()>1){
            int temp1=cards.front();
            cards.pop();
            int temp2=cards.front();
            cards.pop();
            cards.push(temp2);
            output.push_back(temp1);
        }
        cout<<"Discarded cards: ";
        for(int i=0;i<output.size();i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        cout<<"Remaining card: "<<cards.front()<<endl;
    }
}