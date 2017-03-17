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

const int MAXN = 212345, LOGN = 30;

int n, m, k;
char s1[MAXN], s2[MAXN];
int cnt[MAXN], acu[2][200001][200];

bool eq(int i, int j, int ii, int jj){
	for(int a=i;a<=j;a++){
		if(s1[a] != s2[a-i+ii])
			return false;
	}
	return true;
}

bool conta(int i, int j, int ii, int jj){
	int m = (i+j)/2;
	int mm = (ii+jj)/2;
	bool ans = true;
	for(int a='a';a<='z';a++){
		cnt[a] += acu[0][m][a];
		if(i != 0) cnt[a] -= acu[0][i-1][a];
		cnt[a] -= acu[1][mm][a];
		if(ii != 0) cnt[a] += acu[1][ii-1][a];

		if(cnt[a] != 0){
			ans = false;
			cnt[a] = 0;
			return false;
		}
		cnt[a] = 0;
	}

	for(int a='a';a<='z';a++){
		cnt[a] += acu[0][j][a];
		cnt[a] -= acu[0][m][a];
		cnt[a] -= acu[1][jj][a];
		cnt[a] += acu[1][mm][a];
		if(cnt[a] != 0){
			ans = false;
			cnt[a] = 0;
			return false;
		}
		cnt[a] = 0;
	}
	return ans;
}

bool contax(int i, int j, int ii, int jj){
	int m = (i+j)/2;
	int mm = (ii+jj)/2;
	bool ans = true;
	for(int a='a';a<='z';a++){
		cnt[a] += acu[0][m][a];
		if(i != 0) cnt[a] -= acu[0][i-1][a];
		cnt[a] -= acu[1][jj][a];
		cnt[a] += acu[1][m][a];

		if(cnt[a] != 0){
			ans = false;
			cnt[a] = 0;
			return false;
		}
		cnt[a] = 0;
	}

	for(int a='a';a<='z';a++){
		cnt[a] += acu[0][j][a];
		cnt[a] -= acu[0][m][a];
		cnt[a] -= acu[1][mm][a];
		if(ii != 0)cnt[a] += acu[1][ii-1][a];
		if(cnt[a] != 0){
			ans = false;
			cnt[a] = 0;
			return false;
		}
		cnt[a] = 0;
	}
	return ans;
}

bool go(int i, int j, int ii, int jj){
	if(eq(i, j, ii, jj)){
		return true;
	}

	if((j - i + 1)&1) {
		return false;
	}
	int m=(i+j)/2;
	int mm = (ii+jj)/2;
	
	bool ans = false;
	if(conta(i, j, ii, jj)){
		ans |= (go(i, m, ii, mm) & go(m+1, j, mm+1, jj));
	}
	if(ans == true) return ans;
	if(contax(i, j, ii, jj)){
		ans |= (go(i, m, mm+1, jj) & go(m+1, j, ii, mm));
	}
	return ans;
}

int main (){
	scanf(" %s \n %s", s1, s2);
	int tam = strlen(s1);
	for(int a=0;a<tam;a++){
		if(a != 0){
			for(int b='a';b<='z';b++){
				acu[0][a][b] = acu[0][a-1][b];
			}
		}
		acu[0][a][s1[a]]++;
	}
	for(int a=0;a<tam;a++){
		if(a != 0){
			for(int b='a';b<='z';b++){
				acu[1][a][b] = acu[1][a-1][b];
			}
		}
		acu[1][a][s2[a]]++;
	}
	if(go(0, tam-1, 0, tam-1))
		puts("YES");
	else
		puts("NO");
}
