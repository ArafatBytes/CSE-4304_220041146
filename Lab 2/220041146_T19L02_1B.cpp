#include<iostream>
#include<queue>
using namespace std;

queue<int>students,sandwiches;

int unable(queue<int>& st, queue<int>& sd){
    int count=0;
    while(!st.empty() && !sd.empty()){
        if(st.front()==sd.front()){
            st.pop();
            sd.pop();
            count=0;
            if(st.empty() && sd.empty()){
                break;
            }
        }
        else{
            int temp=st.front();
            st.pop();
            st.push(temp);
            count++;
            if(count==st.size()){
                break;
            }
        }
    }
    return count;
}

int main(){
    int n,a;
    cin>>n;
    cout<<"students=[";
    for(int i=0;i<n;i++){
        cin>>a;
        cout<<a<<",";
        students.push(a);
    }
    cout<<endl;
    cout<<"dishes=[";
    for(int i=0;i<n;i++){
        cin>>a;
        cout<<a<<",";
        sandwiches.push(a);
    }
    cout<<endl;
    int x=unable(students,sandwiches);
    cout<<x<<endl;
}