#include <bits/stdc++.h>

using namespace std;

string highestValuePalindrome(string s, int n, int k) {
    int init = 0,end = 0;
    char max_ = s[0];
    for (size_t i = 1; i < s.size(); i++)
    {
        max_ = max(max_,s[i]); 
    }
    while (init < end && k>=0)
    {
        if(arr[init] == arr[end]){
            init++;
            end--;
        }else if(arr[init] > arr[end]){
            arr[end]
        }
    }
    
    cout<<max_<<endl;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n,k;
    cin>>n>>k;
    

    string s;
    cin>>s;

    string result = highestValuePalindrome(s, n, k);

    fout << result << "\n";

    fout.close();

    return 0;
}