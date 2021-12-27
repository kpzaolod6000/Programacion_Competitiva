#include <bits/stdc++.h>
using namespace std; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    cin>>q;
    
    int i = 1;
    while (q--) {
        unordered_map<int, int> nro_pairs;
        int person;
        int cnt = 0;
        int nro_person; 
        cin >> nro_person;
        while (cnt < nro_person) {
            cin >> person;
            nro_pairs[person]++;
            cnt++;
        }
        cout << "Case #" << i<< ": ";
        for(auto x : nro_pairs){
            if (x.second == 1) {
                cout << x.first << endl;
            }
        }
        i++;
    }
    return 0;
}