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


void twoPointer(int* arr,int n,int target){ // complejidad n
    
    int in = 0,en = n-1;
    // int endP = *(arr+(n-1));
    // cout << endP << "\n";
    
    vector<int> vector_ (arr, arr+n);
    sort (vector_.begin(), vector_.begin()+n); // ver el ordenamiento de los indices

    while(in < en){
        if (vector_[in] + vector_[en] < target ) in++;
        else if (vector_[in] + vector_[en] > target ) en--;
        else break;
    }
    if (in == en) {
        cout << "IMPOSSIBLE\n";
    }else{
        cout << in+1 <<" " <<en+1<<"\n";
    }
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


    int n;
    cin>>n;
    int target;
    cin>>target;

    int array[n];

    for (size_t i = 0; i < n; i++)
    {
        cin>>array[i];        
    }

    twoPointer(array,n,target);
    // int n = 6;
    // int array[n] = {1,2,7,9,11,15};
    // // int array2[n] = {1,2,7,9,11,15};
    
    // int n_ = 5;
    // int array2[n_] = {-1,1,2,3,5};



    // twoPointer(array,n,11);
    // twoPointer(array2,n_,5);

    return 0;
}