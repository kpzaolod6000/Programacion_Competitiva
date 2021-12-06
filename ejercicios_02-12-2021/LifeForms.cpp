#include <bits/stdc++.h>

using namespace std;

#define MAX 100107

int chars[MAX];
int r[MAX], SA[MAX];
int pos[MAX];
int tmp[MAX];
int LCP[MAX];
int w[MAX];
int N, S, gap;
bool hasLCP = false;


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
        for(int i=0; i <S-1; ++i){
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
                hasLCP = true;
            }
        }
    }
}
 
bool LCS(int x, int SAsize, bool print) {
    
    bool counted[N];
    int count;
    for (int i = 1; i < SAsize; ++i) {
        if (LCP[i] >= x) {
            for(int i=0; i < N; ++i) counted[i] = false;
            count = 1;
            counted[w[SA[i-1]]] = true;
            int j = i;
            while (j < SAsize && LCP[j] >= x) {
                if (w[SA[j]] != w[SA[j]+x-1]) {
                    break;
                }
                if (!counted[w[SA[j]]]) {
                    counted[w[SA[j]]] = true;
                    ++count;
                }
                ++j;
            }
            if (count > N/2) {
                if (print) {
                    printf("%c", 'a' + chars[SA[i]]); 
                    for (int k = 1; k < x; ++k) {
                        printf("%c", 'a' + chars[SA[i]+k]);
                    }
                    // cout<<"\n";
                    printf("\n");
                }
                else {
                    return true;
                }
            }
            i = j-1;
        }
    }
    return false;
}

int main() {
    
    int T, SAsize, longestWord = -1;
    string line;
    while (scanf("%d", &N) == 1 && N != 0) {
        SAsize = 0;
        getline(cin, line);
        for(int i=0; i < N; ++i) {
            getline(cin, line);
            if (line.length() - longestWord > 0)
                longestWord = line.length();
            for (int j = 0; j < line.length(); ++j) {
                
                w[SAsize] = i;
                chars[SAsize++] = line[j] - 'a';
            }
            chars[SAsize++] = 27+i;
            chars[SAsize] = 0;
        }
        chars[SAsize-1] = 0;

        --SAsize;
        S = SAsize;
        SuffixArray();
        b_LCP(SAsize);

        int low = 1, best = -1;
        int high = longestWord;
        if (hasLCP) {
            while (high >= low) {
                int mid = low + (high-low)/2;
                if (LCS(mid, SAsize, false)) {
                    low = mid + 1;
                    best = max(mid,best);
                }
                else
                    high = mid - 1;
            }
        }
        if (best != -1) {
            LCS(best, SAsize, true);
        }
        else
            printf ("?\n");
        printf ("\n");
     }
    return 0;
}