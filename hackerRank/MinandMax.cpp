#include <bits/stdc++.h>

using namespace std;

void miniMaxSum(vector<int> arr) {
    
    long long int sum = 0;
    set<long long int> numbers;

    for (int k = 0; k < 5; k++)
    {
        numbers.insert(arr[k]);
        sum += arr[k];
    }

    auto it = numbers.end();
    it--;

    std::cout << sum-*it << " ";
    std::cout << sum-*(numbers.begin()) << " ";

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    
    vector<int> arr(5);

    for (int i = 0; i < 5; i++) {
        cin>>arr[i];
    }

    miniMaxSum(arr);

    
    return 0;
}
