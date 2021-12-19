#include <bits/stdc++.h>

#define INF 0xFFFFFFFFFFFFFFFFUL
using namespace std;
int n, m;

int v[2001][2001];
int k[2001][2001];

int main(){
	
	int val;
	cin>>n>>m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin>>val;
			k[i][j] = val;
			v[i][j] = val;
		}
	}

	
	unsigned long long minimun = INF;

	if(n>1&&m>1){
		for (int p = 0; p < 4 ; ++p)
		{	
			int ok = 1;
			unsigned long long sum = 0;

			for (int i = 1; i <= n && ok; ++i)
			{
				for (int j = 1; j <= m && ok; ++j)
				{
					int x = ((p==0)&(~j)) | ((p==1)&(~i)) | ((p==2)&(j)) | ((p==3)&(i));
					int y = max(v[i-1][j], v[i][j-1]);

					if(!k[i][j]) v[i][j] = y + 1 + ((x+y)&1);
					else if( !((x+v[i][j])&1) || !(v[i][j-1]<v[i][j]) || !(v[i-1][j]<v[i][j]) ){
						ok = 0;
					}
					sum += v[i][j];
				}
			}
			if(ok){
				minimun = min(minimun, sum);
			}
		}
	}
	else{
		for (int p = 1; p <= 2; ++p)
		{
			if (!k[1][1]) v[1][1] = p;

			int ok = 1;
			unsigned long long sum = v[1][1];

			for (int j = 2; j <= m && ok; ++j)
			{
				if (!k[1][j]) v[1][j] = v[1][j-1] + 1;
				else if( !(v[1][j-1] < v[1][j]) ) ok = 0;
				sum += v[1][j];
			}
			for (int i = 2; i <= n && ok; ++i)
			{
				if (!k[i][1]) v[i][1] = v[i-1][1] + 1;
				else if( !(v[i-1][1] < v[i][1]) ) ok = 0;
				sum += v[i][1];
			}
			if(ok) minimun = min(minimun, sum);
		}
	}

	if(minimun != INF)	cout << minimun << "\n";
	else cout << "-1\n";

	return 0;
}