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

int LCS_memo(string& P,string& Q,int m, int n, vector<vector<int>>& memo){
    
    int result ;
    if (m == 0 || n == 0)
    {
        result = 0;
    }
    else if (memo[m][n])
    {
        result = memo[m][n];
    }
    
    else if(P[m-1] == Q[n-1]){
        // cout<<str1<<" "<<str2<<"\n";
        result = 1 + LCS_memo(P,Q,m-1,n-1, memo);
    }else{
        int a = LCS_memo(P,Q,m-1,n, memo);
        int b = LCS_memo(P,Q,m,n-1, memo);
        result = max(a,b);
    }
    return result;
}

int LCS_memorization(string& P,string& Q){
    int m = P.size();
    int n = Q.size();
    vector<vector<int>> memo(m+1,vector<int>(n+1,0));

    return LCS_memo(P,Q,m,n,memo);

}

int LCS_bottomup(string& P,string& Q){
    

    int m = P.size();
    int n = Q.size();
    vector<vector<int>> memo(m+1,vector<int>(n+1,0));
    
    
    for (size_t i = 0; i <= m; i++)
    {
        for (size_t j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                memo[i][j] = 0;
            }
            else if(P[i-1] == Q[j-1]){
                // cout<<str1<<" "<<str2<<"\n";
                memo[i][j] = 1 + memo[i-1][j-1];
            }else{
                int a = memo[i-1][j];
                int b = memo[i][j-1];
                memo[i][j] = max(a,b);
            }
        }
        
    }
    return memo[m][n];
}



int main(int argc, char const * argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string string1,string2;
    getline(cin,string1);
    getline(cin,string2);
    // cin>>string1>>string2;

    cout<<LCS_fib(string1,string2)<<"\n";
    cout<<LCS_memorization(string1,string2)<<"\n";
    cout<<LCS_bottomup(string1,string2)<<"\n";
    return 0;
}