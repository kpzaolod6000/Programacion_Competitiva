#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


class FenwickTree {
private:
	vector<ll> tree;
	int n;
public:
	FenwickTree(int n) : n(n) { tree.assign(n + 1, 0); }
	ll query(int l, int r) { return query(r) - query(l - 1); }
	ll query(int r) {
		ll s = 0;
		for (; r > 0; r -= (r & (-r))) s += tree[r];
		return s;
	}
	void update(int i, ll v) {
        while (i<=n)
        {
            tree[i] += v;
            i += (i & (-i));
        }
		// for (; i <= n; i += (i & (-i))) tree[i] += v;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	FenwickTree arr(n), inv_arr(n);
	ll max_inv_arr = 0LL;

	for (size_t i = 0; i < n; ++i) {
		ll val;
		cin >> val;
		val = n - val + 1;
		
		if (val > 1)
			max_inv_arr += inv_arr.query(val - 1);
		inv_arr.update(val, (val > 1 ? arr.query(val - 1) : 0));
		arr.update(val, 1);
	}

	cout << max_inv_arr << endl;
	
	return 0;
}