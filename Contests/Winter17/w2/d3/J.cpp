#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppp;
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

#define X first.first
#define Y first.second
#define Z second.first
#define V second.second

const int MAXN = 55;

int n, m;

ppp mk(int x, int y, int z, int val){
	return ppp(pii(x, y), pii(z, val));
}

vector<ppp> v;

void put(int i, int val){
	int x = i/(n*n);
	int y = (i - x*(n*n))/n;
	int z = i%n;
	x++;y++;z++;
	v.pb(mk(x, y, z, val));
}

bool cmp(ppp a, ppp b){
	return a.V > b.V;
}

int M[2][MAXN][MAXN][MAXN], sum[2][MAXN][MAXN][MAXN];

void add(int t, ppp cell){
	M[t][cell.X][cell.Y][cell.Z]++;
}

void acc(){
	for(int t=0;t<2;t++){
		for(int a=1;a<=n;a++){
			for(int b=1;b<=n;b++){
				for(int c=1;c<=n;c++){
					sum[t][a][b][c] = M[t][a][b][c] + sum[t][a-1][b][c] + sum[t][a][b-1][c] + sum[t][a][b][c-1]
						- sum[t][a-1][b-1][c] - sum[t][a-1][b][c-1] - sum[t][a][b-1][c-1]
						+ sum[t][a-1][b-1][c-1];
				}
			}
		}
	}
}

void pass(){
	for(int a=1;a<=n;a++){
		for(int b=1;b<=n;b++){
			for(int c=1;c<=n;c++){
				M[1][a][b][c] += M[0][a][b][c];
				M[0][a][b][c] = 0;
			}
		}
	}
}

vector<int> ans;

int sumk(int t, int a, int b, int c, int k){
	return sum[t][a][b][c] - sum[t][a-k][b][c] - sum[t][a][b-k][c] - sum[t][a][b][c-k]
		+ sum[t][a-k][b-k][c] + sum[t][a-k][b][c-k] + sum[t][a][b-k][c-k]
		- sum[t][a-k][b-k][c-k];
}

void print(){
	for(int t=0;t<2;t++){
		debug("\nt %d\n", t);
		for(int a=1;a<=n;a++){
			for(int b=1;b<=n;b++){
				for(int c=1;c<=n;c++){
					printf("%d ", M[t][a][b][c]);
				}
				printf("\n");
			}
			printf("\n");
		}
		printf("\n");
	}	
	for(int t=0;t<2;t++){
		debug("\nt %d\n", t);
		for(int a=1;a<=n;a++){
			for(int b=1;b<=n;b++){
				for(int c=1;c<=n;c++){
					printf("%d ", sum[t][a][b][c]);
				}
				printf("\n");
			}
			printf("\n");
		}
		printf("\n");
	}	
}

void zera(){
	for(int t=0;t<2;t++){
		for(int a=1;a<=n;a++){
			for(int b=1;b<=n;b++){
				for(int c=1;c<=n;c++){
					M[t][a][b][c] = 0;
				}
			}
		}
	}	
	for(int t=0;t<2;t++){
		for(int a=1;a<=n;a++){
			for(int b=1;b<=n;b++){
				for(int c=1;c<=n;c++){
					sum[t][a][b][c] = 0;
				}
			}
		}
	}	

}

int main (){
	for_tests(t, tt){
		zera();
		scanf("%d", &n);
		v.clear();
		ans.clear();
		for(int a=0;a<n*n*n;a++){
			int x;
			scanf("%d", &x);
			put(a, x);
		}
		sort(v.begin(), v.end(), cmp);
		int i = 0;
		for(int k=n;k>=1;k--){
			while(i < v.size() && v[i].V >= k){
				add((v[i].V > k), v[i]);
				i++;
			}
			acc();
//			print();
			int res =0;
			for(int a=k;a<=n;a++){
				for(int b=k;b<=n;b++){
					for(int c=k;c<=n;c++){
						if(sumk(0, a, b, c, k) >= 1 && sumk(1, a, b, c, k) <= 0)
							res++;
					}
				}
			}
			ans.pb(res);
			res = 0;
			pass();
		}
		for(int a=ans.size()-1;a>=0;a--){
			printf("%d ", ans[a]);
		}
		printf("\n");
	}
}
