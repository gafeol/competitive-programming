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

const int MAXN = 5123;

int n, m, k;
char s[MAXN][15], op[MAXN][5], A[MAXN][MAXN], B[MAXN][MAXN];
int mn[MAXN], mx[MAXN], iA[MAXN], iB[MAXN];
int val[2][MAXN];
map<string, int> ind;

int main (){
	scanf("%d%d", &n, &m);
	ind["?"] = -1;
	for(int a=0;a<n;a++){
		scanf(" %s := %s", s[a], A[a]);
		ind[s[a]] = a;
		if(A[a][0] == '0' || A[a][0] == '1'){
			op[a][0] = 'N';
			continue;
		}
		iA[a] = ind[A[a]];
		scanf(" %s %s", op[a], B[a]);
		iB[a] = ind[B[a]];
	}
	int sum[2];
	for(int i=0;i<m;i++){
		sum[0] = 0;
		sum[1] = 0;
		for(int a=0;a<n;a++){
			val[0][a] = 0;
			val[1][a] = 0;
		}
		for(int a=0;a<n;a++){
			if(op[a][0] == 'N'){
				val[0][a] = A[a][m-i-1] - '0';
				val[1][a]= A[a][m-i-1] - '0';
			}
			else if(op[a][0] == 'A'){
				val[0][a] = 0; 
				if(A[a][0] == '?' && B[a][0] == '?')
					val[1][a] = 1;
				else if(A[a][0] == '?')
					val[1][a] = val[1][iB[a]];
				else if(B[a][0] == '?')
					val[1][a] = val[1][iA[a]];
				else{
					val[1][a] = val[1][iA[a]]&val[1][iB[a]];
					val[0][a] = val[0][iA[a]]&val[0][iB[a]];
				}
				
			}
			else if(op[a][0] == 'X'){
				if(A[a][0] == '?' && B[a][0] == '?'){
					val[0][a] = 0;
					val[1][a] = 0;
				}
				else if(A[a][0] == '?'){
					val[1][a] = 1^val[1][iB[a]];
					val[0][a] = 0^val[0][iB[a]];
				}
				else if(B[a][0] == '?'){
					val[0][a] = 0^val[0][iA[a]];
					val[1][a] = 1^val[1][iA[a]];
				}
				else{
					val[1][a] = val[1][iA[a]]^val[1][iB[a]];
					val[0][a] = val[0][iA[a]]^val[0][iB[a]];
				}
			}
			else {
				if(A[a][0] == '?' && B[a][0] == '?'){
					val[0][a] = 0;
					val[1][a] = 1;
				}
				else if(A[a][0] == '?'){
					val[1][a] = 1;
					val[0][a] = val[0][iB[a]];
				}
				else if(B[a][0] == '?'){
					val[0][a] = val[0][iA[a]];
					val[1][a] = 1;
				}
				else{
					val[1][a] = val[1][iA[a]]|val[1][iB[a]];
					val[0][a] = val[0][iA[a]]|val[0][iB[a]];
				}
			}
			sum[0] += val[0][a];
			sum[1] += val[1][a];
		}
		if(sum[0] >= sum[1])
			mx[i] = 0;
		else
			mx[i] = 1;
		if(sum[0] <= sum[1])
			mn[i] = 0;
		else
			mn[i] = 1;
	}
	for(int a=0;a<m;a++){
		printf("%d", mn[m-a-1]);
	}
	printf("\n");
	for(int a=0;a<m;a++){
		printf("%d", mx[m-a-1]);
	}
	printf("\n");
}
