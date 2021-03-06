#include <bits/stdc++.h>

using namespace std;

// int subarraysDivByK(vector<int> &nums,int k){// complejidad O(n^3)
    
//     int cnt = 0;
//     int sums;

//     for(size_t i = 0; i < nums.size() ; i++){
//         for(size_t j = i; j < nums.size() ; j++){
//             sums = 0;
//             for(size_t k = i;k < j+1 ; k++){
//                 sums += nums[k];
//             }
//             if(sums % k == 0) cnt++;
//         }
//     }
//     return cnt;
// }


// COMPLEJIDAD n^2
// vector<int> sumsPrefix(vector<int> arr){
    
//     vector<int> aux;
//     aux.push_back(0);

//     for (size_t i = 0; i < arr.size(); i++) aux.push_back(aux.back() + arr[i]);

//     return aux;

// }

// int subarraysDivByK(vector<int> &nums,int k){// Complejidad n^2
    
//     vector<int> sum_prfx = sumsPrefix(nums);
//     int cnt = 0;
    
//     for(size_t i = 0; i < nums.size(); i++){
//         for(size_t j = i; j < nums.size(); j++){
//             if((sum_prfx[j+1] - sum_prfx[i]) % k == 0) cnt++;
//         }
//     }
    
//     return cnt;
//     // for(auto x : sum_prfx){
//     //     cout <<x<<" ";
//     // }
// }

int subarraysDivByK(vector<int> nums,int k){
    map<int,int> indxT;
    map<int,int>::iterator ind;
    int prefix_sum = 0,cnt = 0;
    
    indxT[0] = 1;
    // for (map<int,int>::iterator it=indxT.begin(); it!=indxT.end(); ++it){
    //     cout << it->first << " => " << it->second << '\n';
    // }
    int v_=0;
    int mod_k;
    for(size_t i = 0; i < nums.size(); i++){
        
        prefix_sum = (prefix_sum + nums[i]);
        //mod_k = abs(prefix_sum % k);
        mod_k = ((prefix_sum % k) + k) % k;
        
        if(indxT.count(mod_k)){
            ind = indxT.find(mod_k);
            v_ = ind->second;
        }else v_ = 0;
        
        cnt += v_;

        indxT[mod_k] = indxT.find(mod_k)->second+ 1;
    }
    // cout<<"\n";
    for (map<int,int>::iterator it=indxT.begin(); it!=indxT.end(); ++it){
        cout << it->first << " => " << it->second << '\n';
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
    cout<<subarraysDivByK(arr,k);

    cout<<"\n"<<-2%6<<"\n";

    return 0;
}
