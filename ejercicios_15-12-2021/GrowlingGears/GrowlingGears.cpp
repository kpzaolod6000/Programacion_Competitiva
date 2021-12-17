
#include <bits/stdc++.h>

using namespace std;

double calcMax(int a, int b, int c) {
    double x = (double) (-b) / (-2 * (double) a);
    double result = -a * x * x + b * x + c;
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    
    while(t--) {
        int n;
        cin>>n;
        if(n == 1) {
            int a,b,c;
            cin>>a>>b>>c;
            cout<<1<<endl;
            continue;
        }
        int max = INT_MIN;
        double maxTorque = DBL_MIN;
        for(int i = 1; i <= n; i++) {
            int a,b,c;
            cin>>a>>b>>c;
            double temp = calcMax(a, b, c);
            
            if(temp > maxTorque) {
                maxTorque = temp;
                max = i;
            }
        }
        cout<<max<<endl;
    }
    return 0;
}