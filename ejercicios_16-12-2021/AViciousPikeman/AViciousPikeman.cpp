
#include <bits/stdc++.h>
using namespace std;

int comp(const void *p, const void *q) {
  int *a = (int *) p;
  int *b = (int *) q;
  return *a - *b;
}

int main() {

  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long n,t,a,b,c;
  long ti[10000];

  cin>>n>>t>>a>>b>>c>>ti[0];

  for (size_t i = 1; i < n; i++)
    ti[i] = (a * ti[i-1] + b) % c + 1;

  qsort(ti, n, sizeof(long), comp);

  int penalty = 0;
  int max_number = 0;
  int store_ = 0;
  for (size_t i = 0; i < n; i++) {
    if (store_ + ti[i] <= t) {
      penalty = (penalty + ti[i] + store_) % 1000000007;
      store_ += ti[i];
      max_number++;
    } else {
      break;
    }
  }

  cout<<max_number<<" "<<penalty<<endl;
  return 0;
}