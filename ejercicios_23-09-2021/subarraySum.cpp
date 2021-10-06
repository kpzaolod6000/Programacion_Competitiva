
#include <bits/stdc++.h>

using namespace std;

// COMPLEJIDAD n^2
vector<int> sumsPrefix(vector<int> arr){
    vector<int> aux;
    aux.push_back(0);

    for (size_t i = 0; i < arr.size(); i++) aux.push_back(aux.back() + arr[i]);

    return aux;

}

int subarraySum(vector<int> &nums,int k){// Complejidad n^2

    vector<int> sum_prfx = sumsPrefix(nums);
    int cnt = 0;

    for(size_t i = 0; i < nums.size(); i++){
        for(size_t j = i; j < nums.size(); j++){
            if((sum_prfx[j+1] - sum_prfx[i]) == k) cnt++;
        }
    }

    return cnt;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k,value;
    cin>>n>>k;
    vector<int> arr;

    for(int i=0; i<n;i++) {
        cin>>value;
        arr.push_back(value);
    }
    cout<<subarraySum(arr,k)<<"\n";
   
    return 0;
}
