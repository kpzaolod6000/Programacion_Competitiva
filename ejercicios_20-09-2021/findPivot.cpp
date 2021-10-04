#include <bits/stdc++.h>

using namespace std;

// int findPivot(vector<int> &nums){
//     int pivot = -1;
//     for(int i=0; i<nums.size();i++){
//         int sumleft = 0,sumright = 0;
//         for(int k=i+1; k<nums.size();k++) sumleft += nums[k];
//         for(int l=0;l<i;l++) sumright += nums[l];
//         // cout << sumleft << " " << sumright << endl;
//         if(sumleft == sumright){
//             pivot = i;
//             break;
//         }
//         if(sumleft == 0 && sumright == 0){
//             pivot = i;
//             break;
//         }

//     }
//     return pivot;
// }

int findPivot(vector<int> &nums){// complejidad O(n)
    
    int izq = 0, der = 0;
    for(size_t i=0;i<nums.size();i++){
        if(i == 0){
            for(size_t j=i+1;j<nums.size();j++) der += nums[j];
        }else der -= nums[i];
        
        if(izq == der) return i;
        else izq += nums[i];
        // cout << izq<<" "<<der<<"\n";
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,value;
    cin>>n;
    vector<int> arr;

    for(int i=0; i<n;i++) {
        cin>>value;
        arr.push_back(value);
    }
    cout<< findPivot(arr);
    
    // for(int i=0; i<n;i++) cout<< array[i]<< " ";



    return 0;
}