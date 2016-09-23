#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m,  k, t;
int s[MAXN];

int main (){
	scanf("%d%d", &n, &t);
	int p = -1;
	for(int a=0;a<n;a++){
		char c;
		scanf(" %c", &c);
		s[a] = c-'0';
		if(p == -1)
			s[a] = c-'0';
		else
			s[a-1] = c-'0';
		if(c == '.')
			p = a;
	}
	int nxt = 0;
	int ult = 0;
	int fin = n-2;
	for(int a=p-1;a<n-2;a++){
		if(s[a+1] >= 5){
			t--;
			s[a]++;
			fin = a;
			if(a == p-1){
				nxt = 1;
			}
			else if(s[a] >= 5){
				int i = a;
				while(t > 0 && i > p && s[i] >= 5){
					s[i] = 0;
					s[i-1]++;
					fin = i-1;
					t--;
					i--;
				}
				if(i==p && s[i] >=5 && t > 0){
					nxt = 1;
					fin = i-1;
					s[i-1]++;
					t--;
				}
			}
			break;

		}
	}
	/*printf("nxt %d fin %d\n", nxt, fin);
	for(int a=0;a<n-1;a++){
		printf("%d ", s[a]);
	}
	printf("\n");*/
	if(nxt){
		int a = p-1;
		while(a != 0 && s[a] == 10){
			s[a] = 0;
			s[a-1]++;
			a--;
		}
	}
	while(fin >= p && s[fin] == 0)
		fin--;
	for(int a=0;a<=fin;a++){
		if(a == p)
			printf(".");
		printf("%d", s[a]); 
	}
	printf("\n");
}
