
#include <bits/stdc++.h>

using namespace std;
using is = tuple<int, string>;

// int f[20001];
vector<int> f(20001);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    unordered_map<string, int> m;
    vector<string> mi;
    queue<pair<int, int>> q;

    int i = 0, d = 0;
    string s;
    while (cin>>s) {
        
        if (s.size() < 4 || s == "</text>") continue;
        if (s == "<text>") {
            d++;
            while (!q.empty()) {
                int k, t;
                // tie(k, t) 
                auto current = q.front();
                k = current.first;
                t = current.second;
                
                if (k > d - 7) break;
                f[t]--;
                q.pop();
            }
        } else if (s == "<top") {
            int n;
            cin >> n >> s;
            cout << "<top " << n << ">\n";
            if (n > i) n = i;
            
            vector<is> a(i);
            for (int k = 0; k < i; k++)
                a[k] = {f[k], mi[k]};
            sort(a.begin(), a.end(), [](is &a, is&b) { return get<0>(a) > get<0>(b) || (get<0>(a) == get<0>(b) && get<1>(a) < get<1>(b)); });
            
            int l = get<0>(a[n - 1]);
            for (is &x : a) {
                int k; string s;
                tie(k, s) = x;
                if (k < l) break;
                cout << s << " " << k << "\n";
        }
        cout << "</top>\n";
        } else {
        if (!m.count(s)) m[s] = i++, mi.push_back(s);
            int k = m[s];
            f[k]++;
            q.push({d, k});
        }
    }
}