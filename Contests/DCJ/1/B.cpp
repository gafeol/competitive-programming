#include"weird_editor.h"
#include<message.h>
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }


const int MAXN = 212345;

ll base[3][3], M[3][3], aux[3][3];

void expo(ll e){
	if(e == 0){
		for(int a=0;a<2;a++){
			for(int b=0;b<2;b++){
				M[a][b] = (a==b);
			}
		}
		return;
	}

	expo(e/2ll);
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			aux[a][b] = 0;
			for(int c=0;c<2;c++){
				aux[a][b] = mod(aux[a][b] + M[c][b]*M[a][c]);
			}
		}
	}
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			M[a][b] = aux[a][b];
		}
	}

	if(e&1){
		for(int a=0;a<2;a++){
			for(int b=0;b<2;b++){
				aux[a][b] = 0;
				for(int c=0;c<2;c++){
					aux[a][b] = mod(aux[a][b] + M[c][b]*base[a][c]);
				}
			}
		}
		for(int a=0;a<2;a++){
			for(int b=0;b<2;b++){
				M[a][b] = aux[a][b];
			}
		}
	}

}

int main (){
	ll m = NumberOfNodes();
	ll id = MyNodeId();
	ll N = GetNumberLength();
	ll cnt[10];

	for(int a=0;a<10;a++)
		cnt[a] = 0;

	ll l = (N/(m-1))*id, r = (N/(m-1))*(id+1);
	if(!id && r == 0)
		r = N;
	ll atu = -1;
	for(ll i=l;i < min(N, r);i++){
		ll val = GetDigit(i);	
		while(atu >= val){
			cnt[atu] = 0;
			atu--;
		}
		cnt[val]++;
		atu = val-1;
	}
	while(atu >= 0){
		cnt[atu] = 0;
		atu--;
	}
	for(int i=9;i>=0;i--){
		PutLL(0, cnt[i]);
	}
	Send(0);
	if(!id){
		ll ans[10];
		ll len = 0;
		for(int a=0;a<10;a++)
			ans[a] = 0;
		for(int i = 0;i < m;i++){
			Receive(i);
			int ok = 0;
			for(int j=9;j>=0;j--){
				ll qtd = GetLL(i);
				if(!ok){
					if(qtd == 0)
						continue;
					ok = 1;
					ans[j] += qtd;
				}
				else
					ans[j] = qtd;
			}
		}
		ll res = 0;
		for(int d=9;d>0;d--){
			len += ans[d];
		}
		ans[0] = N - len;

		for(ll d = 9;d>=0;d--){
			M[0][0] = 10;
			M[0][1] = M[1][1] = 1;
			M[1][0] = 0;
			for(int a=0;a<2;a++){
				for(int b=0;b<2;b++){
					base[a][b] = M[a][b];
				}
			}
			expo(ans[d]);
			res = mod(mod(res*M[0][0]) + mod(M[0][1]*d));
		}
		printf("%lld\n", res);
	}
}
