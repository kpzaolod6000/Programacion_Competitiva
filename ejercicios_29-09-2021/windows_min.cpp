#include <bits/stdc++.h>

using namespace std;

int windowsR_min(vector<int> vector_, int n, int sum_target){
    
    int k;
    int sum_;
    int num_v;
    bool t = false;
    for (size_t i = 0; i < n; i++)
    {
        
        for (size_t j = i; j < n; j++)
        {
            sum_ = 0;
            num_v = 0;
            for (size_t l = i; l < j; l++)
            {
                sum_ += vector_[j];
                num_v++;
            }
            if (sum_ == sum_target) {
                k = num_v;
                t = true;
            };
        }
        // cout<<sum_<<endl;
        

    }
    return k;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int sum_ = 7;
    int n = 5;
    int arr[] = {2,4,2,5,1};
    vector<int> vector_ (arr, arr+n);
    // for (size_t i = 0; i < n; i++)
    // {
    //     cout << vector_[i] <<" ";
    // }
    

    cout << windowsR_min(vector_,n,sum_)<<"\n";
    // int n = 6;
    // int array[n] = {1,2,7,9,11,15};
    // // int array2[n] = {1,2,7,9,11,15};
    
    // int n_ = 5;
    // int array2[n_] = {-1,1,2,3,5};



    // twoPointer(array,n,11);
    // twoPointer(array2,n_,5);

    return 0;
}