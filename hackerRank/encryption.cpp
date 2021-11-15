#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string encryption(string s) {
    double L = sqrt(s.size());
    int r = floor(L);
    int c = ceil(L);
    if(r*c < s.size()){
        r = c;
    }
    // cout << r<<" "<<c<<"\n";

    vector<vector<char>> table;

    int idx = 0;
    for (size_t i = 0; i < r; i++)
    {
        vector<char> col;
        for (size_t j = 0; j < c; j++)
        {
            col.push_back(s[idx]);
            idx++;
        }
        table.push_back(col);
    }
        
    string result = "";
    for (size_t j = 0; j < c; j++)
    {
        for (size_t i = 0;i < r; i++)
        {
            result += table[i][j];
            // cout<<table[i][j]<<" ";
        }
        result += " ";
        // cout<<"\n";
    }
    string rpta = "";

    for (size_t i = 0; i < result.size()-1; i++)
    {
        rpta += result[i]; 
    }
    
    
    
    return rpta;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    cout << result << "\n";

    fout.close();

    return 0;
}
