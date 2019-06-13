#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2123456;

int n, m, k;
int main (){
	scanf("%d %d", &n, &m);
    vector<int> s(m);
	for(int a=0;a<m;a++){
        int x, c;
        scanf("%d%d", &x, &c);
        s[a] = c;
	}
     
    sort(s.begin(), s.end(), greater<int>());
    long long ans = 0;
    for(int a=0;a<m;a++){
        int sz = 1 + ((a+1)*a)/2 + (a&1)*((a+1)/2 - 1);
        if(sz > n) break;
        ans += s[a];
    }
    printf("%lld\n", ans);
}
