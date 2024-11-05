#include <iostream>
#include <stack>
using namespace std;

int performingoperation(char oper, int op1, int op2) {
    switch (oper) {
        case '+': 
        return op1 + op2;
        case '-': 
        return op1 - op2;
        case '*': 
        return op1 * op2;
        case '/': 
        return op1 / op2;
        default: 
        return 0; 
    }
}
int postfix(string st) {
    stack<int> mathOp;
    for (int i = 0; i < st.length(); i++) {
        char x = st[i];
        if (isdigit(x)) {
            mathOp.push(x - '0');
        }
        else {
            int op2 = mathOp.top();
            mathOp.pop();
            int op1 = mathOp.top();
            mathOp.pop();

            int result = performingoperation(x, op1, op2);
            mathOp.push(result);
        }
    }
    return mathOp.top();
}

int main(){
    int n;
    string math;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>math;
        int soln=postfix(math);
        cout<<soln<<endl;
    }
}