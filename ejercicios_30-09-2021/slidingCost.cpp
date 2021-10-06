#include <bits/stdc++.h>

using namespace std;

void swap(int &a,int &b){
    int tmp;
    tmp = b;
    b = a;
    a = tmp; 
}
vector<long int> slidingCost(vector<long int> &arr, int k){
    vector<long int> cost;
    int n = arr.size();

    int mdd;
    long int v_cost;
    for (size_t i = 0; i <= n-k; i++)
    {
        vector<long int> k_elem;
        for (size_t j = i; j < i+k; j++)
        {
            k_elem.push_back(arr[j]);
        }
        sort(k_elem.begin(), k_elem.end());

        mdd = k_elem.size()/2;
        // cout<<mdd<<"\n";
        v_cost = 0;
        int l;
        for (l = 0; l < mdd; l++)
        {
            v_cost += ( k_elem[mdd] - k_elem[l] );
        }
        for (l = mdd+1; l < k; l++)
        {
            v_cost += ( k_elem[l] - k_elem[mdd] );
        }
        cost.push_back(v_cost);
    }

    return cost;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k;
    long int value;
    cin >> n >>k;

    vector<long int> arr;
    for (size_t i= 0;i < n; i++){
        cin>>value;
        arr.push_back(value);
    }    
    vector<long int> cost = slidingCost(arr,k);
    for(auto elem : cost){
        cout<<elem<<" ";
    }
    cout<<"\n";
    return 0;
}