#include<bits/stdc++.h>
using namespace std;

#define MAX 200001

int chars[MAX];
int r[MAX], SA[MAX];
int pos[MAX], tmp[MAX];
int LCP[MAX]; 
int N, S, gap;


bool cmp(int i, int j) {
    if (pos[i] == pos[j]) {
        i += gap;
        j += gap;
        if (i < S && j < S)
            return pos[i] < pos[j];
        else
            return i > j;
    }
    return pos[i] < pos[j];
}


void SuffixArray() {
    for (int i = 0; i < S; ++i) {
        pos[i] = chars[i];
        SA[i] = i;
        tmp[i] = 0;
    }
    gap = 1;
    while (true) {
        sort(begin(SA), begin(SA) + S, cmp);
        for(int i=0; i < S-1; ++i){
            int higher = cmp(SA[i], SA[i+1]);
            tmp[i+1] = tmp[i] + (higher ? 1 : 0);
        }
        for(int i=0; i < S; ++i) pos[SA[i]] = tmp[i]; 
        if (tmp[S-1] >= S-1)
            break;
        gap = gap << 1;
    }
}


void b_LCP(int SAsize) {
    for(int i=0; i < SAsize; ++i) r[SA[i]] = i;
    LCP[0] = 0;
    int h = 0;
    for (int i = 0; i < SAsize; ++i) {
        if (r[i] == 0) {
            LCP[i] = 0;
            continue;
        }
        if (r[i] > 0) {
            int j = SA[r[i]-1];
            while (i+h < SAsize && j+h < SAsize && chars[i+h] == chars[j+h]) ++h;
            LCP[r[i]] = h;
            if (h > 0) {
                --h;
            }
        }
    }
}

int getLRS() {
    int maxi = -1;
    for (int i = 0; i < S; ++i) {
        maxi = max(maxi,LCP[i]);
    }
    return maxi;
}



int main() {
    int SAsize;
    string line;
    scanf("%d", &N);
    SAsize = 0;
    getline(cin, line);
    getline(cin, line);
    for (int j = 0; j < N; ++j) {
        chars[SAsize++] = line[j] - 'a';
    }
    chars[SAsize] = 0;
    --SAsize;
    S = SAsize;
    SuffixArray();
    b_LCP(SAsize);

    printf ("%d\n", getLRS());
    return 0;
}