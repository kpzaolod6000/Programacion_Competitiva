#include <bits/stdc++.h>
using namespace std;

vector<int> sums(vector<int> arr){
    
    vector<int> aux;
    aux.push_back(arr[0]);
    for (size_t i = 1; i < arr.size(); i++) aux.push_back(aux.back() + arr[i]);
    return aux;

}

int DisastrousDowntime(vector<int> &arr,int k){
    
    int n = arr[arr.size()-1];
    int miliscnd = 1000;
    vector<int> times(n+miliscnd+1);
    
    int time;
    for (size_t i = 0; i < arr.size(); i++)
    {
        time = arr[i];
        times[time]++;
        time += miliscnd;
        times[time]--;
    }
    vector<int> sumTime = sums(times);
    sort (sumTime.begin(), sumTime.end());
    
    int prev;
    for(auto elem : sumTime){
        if(elem > k) break;
        prev = elem;
    }
    return prev;

    // for(auto elem : times){
    //     cout<<elem<<" ";
    // }
    // cout<<"\n";
    // vector<int> sumTime = sums(times);
    // for(auto elem : sumTime){
    //     cout<<elem<<" ";
    // }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k;
    cin >> n >>k;

    vector<int> arr(n);
    for (size_t i= 0;i < n; i++) cin>>arr[i];
    // vector<long int> cost = slidingCost(arr,k);
    cout<<DisastrousDowntime(arr,k);

    // for(auto elem : arr){
    //     cout<<elem<<" ";
    // }
    cout<<"\n";
    return 0;
}