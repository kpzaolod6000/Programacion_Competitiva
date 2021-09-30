#include <bits/stdc++.h>

using namespace std;

int windowsR(vector<int> vector_, int n, int k){
    
    int max = 0;
    int sum_;
    for (size_t i = 0; i < n-2; i++)
    {
        sum_ = 0;
        for (size_t j = i; j < i+k; j++)
        {
            sum_ += vector_[j];
        }
        // cout<<sum_<<endl;
        if (sum_ > max) max = sum_;
        
    }
    return max;

}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 3;
    int n = 5;
    int arr[] = {2,3,4,1,5};
    vector<int> vector_ (arr, arr+n);
    // for (size_t i = 0; i < n; i++)
    // {
    //     cout << vector_[i] <<" ";
    // }
    

    cout << windowsR(vector_,n,k)<<"\n";
    // int n = 6;
    // int array[n] = {1,2,7,9,11,15};
    // // int array2[n] = {1,2,7,9,11,15};
    
    // int n_ = 5;
    // int array2[n_] = {-1,1,2,3,5};



    // twoPointer(array,n,11);
    // twoPointer(array2,n_,5);

    return 0;
}