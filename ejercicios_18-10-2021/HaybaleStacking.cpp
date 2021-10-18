#include <bits/stdc++.h>

using namespace std;

vector<int> sumsPrefix(vector<int> arr){
    
    vector<int> aux;
    aux.push_back(0);
    for (size_t i = 0; i < arr.size(); i++) aux.push_back(aux.back() + arr[i]);
    return aux;

}

int HaybaleStacking(vector<int> &arr,int k){
    int A,B;
    while (k > 0)
    {
        cin>>A>>B;
        arr[A]++;
        arr[B+1]--;
        k--;
    }
    vector<int> rpt = sumsPrefix(arr);
    sort (rpt.begin(), rpt.end());
    // for (size_t i = 0; i < rpt.size(); i++)
    // {
    //     cout<<rpt[i]<<" ";
    // }
    return arr[arr.size()/2+1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k;
    // long int value;
    cin >> n >>k;

    vector<int> arr(n);
    
    cout<<HaybaleStacking(arr,k);

    cout<<"\n";
    return 0;
}