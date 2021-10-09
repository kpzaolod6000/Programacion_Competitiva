
#include <bits/stdc++.h>
//algoritmo kadane
using namespace std;



vector<int> sumsPrefix(vector<int> arr){
    vector<int> aux;
    aux.push_back(0);

    for (size_t i = 0; i < arr.size(); i++) aux.push_back(aux.back() + arr[i]);

    return aux;

}

int MinAvgTwoSlice(vector<int> &nums){// Complejidad n^2 for length slide > 2

    vector<int> sum_prfx = sumsPrefix(nums);
    
    double avrg,sum_;
    double min_ = 200001;
    int min_idx = -1;

    multimap<double,int> min_index;

    for(size_t i = 0; i < nums.size()-1; i++){
        min_ = 200001;
        for(size_t j = i+1; j < nums.size(); j++){
            
            avrg = (double)(sum_prfx[j+1] - sum_prfx[i]) / (double)(j+1-i);
            if(avrg < min_){
                min_ = avrg;
            }
        }
        min_index.insert ( pair<float,int>(min_,i) );
            
     
    }
    min_idx = (*min_index.begin()).second;
    // cout<<"\n";
    // for (auto it = min_index.cbegin(); it != min_index.cend(); ++it)
    //     cout << " [" << it->first << ':' << it->second << ']';
    // cout<<"\n";
    return min_idx;
}

int MinAvgTwoSlice2(vector<int> &A){//complejidad n

    int idx_len2 = -1,idx_len3 = -1;
    float min2 = 200001,min3 = 200001;
    float sum_2,sum_3;
    float v_1,v_2,v_3;
    for (size_t i = 0; i < A.size()-1; i++)
    {
        v_1 = A[i];
        v_2 = A[i+1];
        sum_2 = v_1 + v_2;
        if (sum_2 < min2 )
        {
            min2 = sum_2;
            idx_len2 = i;
        }
        if(i < A.size()-2){
            v_3 = A[i+2];
            sum_3 = v_1 + v_2 + v_3;
            if (sum_3 < min3)
            {
                min3 = sum_3;
                idx_len3 = i;
            }      
        }
    }
    if(idx_len3 == -1) return idx_len2;

    double avrg2 = (double)(min2/2);
    double avrg3 = (double)(min3/3);
    if (avrg2 < avrg3) return idx_len2;
    if (avrg3 < avrg2) return idx_len3;

    return min(idx_len2,idx_len3);

    
}

//  int  subarraySum(vector<int>& nums,int k) {
//         int sum = 0;
//         map<int, int> mp;
        
//         mp[0]++;
//         int ans = 0;
//         for(int i = 0; i < nums.size(); i++) {
//             sum += nums[i];
//             if(mp.count(sum-k))
//                 ans += mp[sum-k];
//             mp[sum]++;
//         }
//         for (auto it = mp.cbegin(); it != mp.cend(); ++it)
//             cout << " [" << it->first << ':' << it->second << ']';
//         return ans;
//     }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,value;
    cin>>n;
    vector<int> arr;
    for (size_t i = 0; i < n; i++)
    {          
        cin>>value;
        arr.push_back(value);
    }
 
    cout<<MinAvgTwoSlice(arr)<<"\n";
    
    cout<<MinAvgTwoSlice2(arr)<<"\n";
    // for (size_t i = 0; i < n; i++)cout<<arr[i]<<"\n";
    
    
    

    return 0;
}