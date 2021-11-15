#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'staircase' function below.
 *
 * The function accepts INTEGER n as parameter.
 */


void staircase(int n) {
    int cnt = 0;
    for(size_t i = 0; i < n; i++){
        
        for(size_t m = i ; m < n-1 ; m++){
            cout<<" ";
        }
        for (size_t l = 0; l <= cnt; l++)
        {
            cout<<"#";
        }
        
        cnt++;
        cout<<"\n";
        
    }
    
}

int main()
{
    // string n_temp;
    // getline(cin, n_temp);

    int n;
    cin>>n;

    staircase(n);

    return 0;
}