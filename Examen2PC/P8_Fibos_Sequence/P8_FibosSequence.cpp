#include <bits/stdc++.h>
using namespace std;

long int fib_bottomup(long int A,long int B,long int n){
    
    long int max_;
    max_= max(A,B);
    
    try
    { 
        // long int* F = new long int[(max_+n)+ 1]; 
        vector<long int> F(max_+n+1);
        F[0] = 0;
        F[1] = 1;
        
        for (long int i = 2; i <= max_; i++)
        {
            F[i] = F[i-2] + F[i-1];
        }
    
        
        long int sum_ = F[A] * F[B];
        // cout<<max_<<endl;
        // cout<<F[max_]<<endl;
        // cout<<sum_<<endl;
        long int j = A;

        for (long int i = max_+1; i <= (max_-1)+n; i++)
        {
            j++;
            F[i] = F[i-2] + F[i-1];
            sum_ += (F[i] * F[j]);
        }

        return sum_;
    } 
    catch (bad_alloc & exception) 
    { 
        cerr << "bad_alloc detected: " << exception.what(); 
    } 
    return 0;
    // vector<unsigned long long int> F((max_*n)+1);
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long int A,B,n;
    while (true)
    {
        // scanf("%d %d %d", &A, &B,&n);
        cin>>A>>B>>n;
        if (A == 0 && B == 0 && n == 0 ) break;    
        cout<<fib_bottomup(A,B,n) % 1000000007<<endl;
    }
    
    return 0;
}