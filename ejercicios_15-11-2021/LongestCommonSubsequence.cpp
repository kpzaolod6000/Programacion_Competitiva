#include <bits/stdc++.h>
using namespace std;

int LCS_fib(string P,string Q){
    int result ;

    string strP = P.substr(0,P.size()-1);
    string strQ = Q.substr(0,Q.size()-1);
    if (P.size() == 0 || Q.size() == 0)
    {
        // cout<<P;
        result = 0;
    }
    
    else if(P[P.size()-1] == Q[Q.size()-1]){
        // cout<<str1<<" "<<str2<<"\n";
        result = 1 + LCS_fib(strP,strQ);
    }else{
        int a = LCS_fib(strP,Q);
        int b = LCS_fib(P,strQ);
        result = max(a,b);
    }
    return result;
}


int main(int argc, char const * argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string string1,string2;
    getline(cin,string1);
    getline(cin,string2);
    // cin>>string1>>string2;

    cout<<LCS_fib(string1,string2)<<"\n";
    return 0;
}