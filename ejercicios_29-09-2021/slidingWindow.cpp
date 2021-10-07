#include <bits/stdc++.h>

using namespace std;

int slidingWindow(vector<int> vector_, int n, int k){//complejidad n^2
    
    int max = 0;
    int sum_;
    for (size_t i = 0; i < n-k+1; i++)
    {
        sum_ = 0;
        for (size_t j = i; j < i+k; j++)
        {
            sum_ += vector_[j];
        }
        
        if (sum_ > max) max = sum_;
        
    }
    return max;

}



int slidingWindow2(vector<int> &arr, int n, int k){//complejidad n

    int sum_ = 0, max_ = 0;
    for (size_t i = 0; i < k ; i++) sum_ += arr[i];
    
    max_ = sum_;
    
    int izq = 0;

    for(size_t der = k; der < n ; der++){
        sum_ += arr[der];
        sum_ -= arr[izq];
        izq++;
        max_ = max(sum_,max_);
    }

    return max_;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 3;
    int n = 5;
    int arr[] = {2,3,4,1,5};
    vector<int> vector_ (arr, arr+n);
   

    cout << slidingWindow(vector_,n,k)<<"\n";
    cout << slidingWindow2(vector_,n,k)<<"\n";

    return 0;
}
