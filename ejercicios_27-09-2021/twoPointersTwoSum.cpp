#include <bits/stdc++.h>

using namespace std;


// void twoPointer(int* arr,int n,int target){
    
//     int mdio = (n-1)/2;
//     int izq = mdio, der = mdio+1;
//     int sum;

//     sum = arr[izq] + arr[der];
//     while(sum != target){

//         sum = arr[izq] + arr[der];
//         if (sum > target)
//         {
//             izq--;
//             if(izq < 0) izq = n-1;
            
//             if (izq == mdio) break;

//         }else if(sum < target){
            
//             der++;
//             if(der > n-1) der = 0;
            
//             if( der == mdio+1) break;
//         }
//     }

//     if (izq == der) {
//         cout << "IMPOSSIBLE\n";
//     }else{
//         cout << izq+1 <<" " <<der+1<<"\n";
//     }
// }


//void twoPointer(vector<int> vector_,int n,int target){ // complejidad n (para entredas de vector ordenados ascendentes)
    
//    int in = 0,en = n-1;
    //vector<int> vector_ (arr, arr+n);

//    while(in < en){
//        if (vector_[in] + vector_[en] < target ) in++;
//        else if (vector_[in] + vector_[en] > target ) en--;
//        else break;
//    }
//    if (in == en) {
//        cout << "IMPOSSIBLE\n";
//    }else{
//        cout << in+1 <<" " <<en+1<<"\n";
//    }
//}

vector<int> twoPointerArrayAsc(vector<int> arr,int target){//complejidad nlogn

    vector<int> idx;
    int n = arr.size();
    multimap<int,int> aux;

    int in = 0, en = n-1;

    for(size_t i = 0; i < n ; i++){
        aux.insert ( pair<int,int>(arr[i],i));
    }

    //for (multimap<int,int>::iterator it=aux.begin(); it!=aux.end(); ++it)
    //    cout << it->first << " :=> " << it->second << '\n';
    
    // copy ( arr.begin(), arr.begin()+n, aux.begin() );
    
    sort(arr.begin(),arr.begin()+n);

    bool isTrue = true;
    while(in < en){
        if (arr[in] + arr[en] < target ) in++;
        else if (arr[in] + arr[en] > target ) en--;
        else break;
    }
    
    if (in == en) {
        isTrue = false;
    }else{
        //cout << in <<" "<<en<<"\n";
        multimap<int,int>::iterator in_idx = aux.find(arr[in]);
        multimap<int,int>::iterator en_idx = aux.find(arr[en]);
        
        if(in_idx == en_idx){

            pair <std::multimap<int,int>::iterator, std::multimap<int,int>::iterator> ret;
            
            ret = aux.equal_range(arr[in]);
            
            //multimap<int,int>::iterator idx_it=ret.second;
            
            int last_;
            for (multimap<int,int>::iterator it_=ret.first; it_!=ret.second; ++it_)
                last_ = it_->second;
            
            idx.push_back( ret.first->second+ 1 );
            idx.push_back( last_+1 );
            return idx;
 
        }

        idx.push_back( in_idx->second+1 );
        idx.push_back( en_idx->second+1 );
        return idx;
    }

    if(!isTrue) cout<<"IMPOSSIBLE";
    cout<<"\n";
    
    return idx;
}

// void twoPointer(int* arr,int n,int target){ // complejidad n^2
    
//     int twoP = 0;
//     int in,en;
//     bool t = false;
        
//     for (size_t i = 0; i < n-1; i++)
//     {
//         for (size_t j = i+1; j < n; j++)
//         {
//             if(target == arr[i] + arr[j]) {
//                 t = true;
//                 in = i;
//                 en = j;
//             }
//         }
//     }
//     if (t) {
//         cout << in+1 <<" " <<en+1<<"\n";
//     }else{
//         cout << "IMPOSSIBLE\n";
//     }
// }
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n,value;
    cin>>n;
    int target;
    cin>>target;

    vector<int> array;

    for (size_t i = 0; i < n; i++)
    {
        cin>>value;
        array.push_back(value);
    }

    //twoPointer(array,n,target);
    vector<int> idx = twoPointerArrayAsc(array,target);

    for(auto x:idx) cout<<x<<" ";
    cout<<"\n";
    // int n = 6;
    // int array[n] = {1,2,7,9,11,15};
    // // int array2[n] = {1,2,7,9,11,15};
    
    // int n_ = 5;
    // int array2[n_] = {-1,1,2,3,5};



    // twoPointer(array,n,11);
    // twoPointer(array2,n_,5);

    return 0;
}
