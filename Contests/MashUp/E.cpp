#include <bits/stdc++.h>
using namespace std;
#define N 4000000

bool v[N];

int main () {

	int t;
	cin >> t;
	string a;
	int s[100010];
	while(t--) {
		
		cin >> a;

		for(int i=0;i<a.size();i++) {
			s[i] = a[i] - '0';
		}
		
		for(int i=1;i<=20;i++) {
			int k = (1<<i);
			int j;
			int now = 0;
			for(int j=0;j<(1<<i);j++) {
				v[j] = 0;
			}
			for(j=0;j<i && a.size()-1-j >= 0;j++) {
				now += s[a.size()-1-j] * (1<<j);
			}
			//printf("sz %d: ", i);
			//printf("%d ", now);
			v[now]=1;
			k--;
			for(int pos = a.size()-1-j; pos >= 0; pos--) {
				now /= 2;
				now += (1<<(i-1)) * s[pos];
				//printf("%d ", now);
				if(v[now] == 0) {
					k--;
					v[now] = 1;
				}
				if(k == 0) break;
			}
			//printf("\n");
			
			if(k > 0) {
				printf("%d\n", i);
				break;
			}
		}
	}



}
