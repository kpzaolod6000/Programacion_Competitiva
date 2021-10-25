#include <bits/stdc++.h>
using namespace std;



int evalRPN(vector<string>& tokens){
    stack<int> result;
    int x_val,y_val;

    for (size_t i = 0; i < tokens.size(); i++)
    {
        string ch = tokens[i];
        if( ch=="+" || ch=="-" || ch=="*" || ch=="/"){
            y_val = result.top();
            result.pop();
            x_val = result.top();
            result.pop();
            if (ch == "+") result.push(x_val + y_val);
            else if (ch == "-") result.push(x_val - y_val);
            else if (ch == "*") result.push(x_val * y_val);
            else if (ch == "/") result.push(x_val / y_val);
        }else{
            result.push(stoi(ch));
        }
    }
    return result.top();
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    
    vector<string> arr ={"2","1","+","3","*"};
    cout<<evalRPN(arr)<<"\n";
    
    vector<string> arr2 ={"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout<<evalRPN(arr2)<<"\n";
    
    return 0;
}