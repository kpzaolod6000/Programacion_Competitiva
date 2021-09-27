#include <bits/stdc++.h>

using namespace std;

void sortedOrder(int arr[],int n){
    
    int in = 0, en = n-1,temp;
    int a,b;
    int aux[n];
    for (size_t i = 0; i < n; i++)
    {
        aux[i] = abs(arr[i] * arr[i]); 
    }
    

    while (arr[in] < 0)
    {
        en = n-1;
        while(arr[en] > 0){
            if(aux[in] > aux[en]){
                temp = aux[in];
                aux[in] = aux[en];
                aux[en] = temp;
            }
            en--;
        }
        // break;
        in++;
    }

    for (size_t i = 0; i < n; i++)
    {
        cout << aux[i] <<" ";
    }
    
    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=5;
    
    int array[n] = {-4,-3,1,2,3};
    sortedOrder(array,n);

    return 0;
}