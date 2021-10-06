#include <bits/stdc++.h>

using namespace std;

int maxPrefixSums(vector<int> arr,int init,int end){
    
    int max_ = 0, sum_ = 0;

    for (size_t i = init; i <= end; i++){
        sum_ += arr[i];
        if(sum_ > max_) max_ = sum_;         
    }
    if (max_ < 0) return 0;    
    return max_;

}
void prefxSumQueries(vector<int> &arr, vector<int> &output,vector<int> qline){

    if(qline[0] == 1){
        arr[qline[1] - 1] = qline[2];
    }else if(qline[0] == 2){    
        output.push_back(maxPrefixSums(arr,qline[1]-1,qline[2]-1));
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,q,value;
    cin >> n >>q;

    vector<int> arr;
    for (size_t i= 0;i < n; i++){
        cin>>value;
        arr.push_back(value);
    }
    
    vector<int> output;
    vector<int> qline;
    int thr = 0;
    while (q--)
    {
        thr = 0;
        while (thr < 3)
        {
            cin>>value;
            qline.push_back(value);
            thr++;
        }
        
        prefxSumQueries(arr,output,qline);
        qline.clear();
    }
    
    // cout<<"\n";
    // for(auto x : arr ) {
    //     cout<<x <<" ";
    // }
    // cout<<"\n";

    for(auto y : output) {
        cout<<y <<"\n";
    }

    return 0;
}