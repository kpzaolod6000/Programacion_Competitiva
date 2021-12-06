#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n'
 
const int mxN = 1e5+5;
int sa[mxN], pos[mxN], tmp[mxN], lcp[mxN];
int gap, N;
string text;
 
bool comp(int x, int y) {
    if (pos[x] != pos[y])
        return pos[x] < pos[y];
    x += gap;
    y += gap;
    return (x < N && y < N) ? pos[x] < pos[y] : x > y;
}
 
void SuffixArray() {
    for (int i = 0; i < N; i++)
        sa[i] = i, pos[i] = text[i];
 
    for (gap = 1;; gap <<= 1) {
        sort(sa, sa+N, comp);
        for (int i = 0; i < N-1; i++)
            tmp[i+1] = tmp[i] + comp(sa[i], sa[i+1]);
        for (int i = 0; i < N; i++)
            pos[sa[i]] = tmp[i];
        if (tmp[N - 1] == N - 1)
            break;
    }
}
 
void b_lcp() {
    for (int i = 0, k = 0; i < N; i++) if (pos[i] != N-1) {
        int j = sa[pos[i] + 1];
        while (text[i + k] == text[j + k])
            k++;
        lcp[pos[i]] = k;
        if (k) k--;
    }
}

int pre[mxN];
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>text; 
    N = text.size();

    SuffixArray();
    b_lcp();
    
    int prev = 0;
    for (int i = 0; i < N; i++) {
        pre[prev + 1]++;
        pre[N - sa[i] + 1]--;
        prev = lcp[i];
    }
    for (int i = 1; i <= N; i++) {
        cout << pre[i] << ' ' ;
        pre[i+1] += pre[i];
    }
}