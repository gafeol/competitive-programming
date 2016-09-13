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

const int MAXN = 312345;

int n, m, k;

int deg, s[MAXN], mrk[MAXN], res;

queue <int> fil[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	int j = 0;
	for(int a=0;a<m;a++){
		int t, x;
		scanf("%d%d", &t, &x);
		if(t == 1){
			s[deg++] = x;
			res++;
			fil[x].push(deg-1);
		}
		else if(t == 2){
			while(!fil[x].empty()){
				int top = fil[x].front();
				fil[x].pop();
				if(!mrk[top]){
					mrk[top] = 1;
					res--;
				}
			}
		}
		else{
			while(j < x){
				if(!mrk[j]){
					mrk[j] = 1;
					res--;
				}
				j++;
			}
		}
		printf("%d\n", res);
	}
}


