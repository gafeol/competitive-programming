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

int n, m, k;
int s[MAXN];

// Z Algorithm
//////////////
const int MAXS = MAXN;

int L, R, Z[MAXS];

char seq[MAXS];

inline void ZAlgorithm(char s[]){
	int tam = strlen(s);
	L = R = 0;
	for(int i=1;i<tam;i++){
		if(i > R){
			L = R = i;
			while(R < tam && s[R] == s[R-L])
				R++;
			Z[i] = R-L; 
			R--;
		}
		else{
			if(Z[i-L] >= R-i+1){
				L = i;
				while(R < tam && s[R] == s[R-L])
					R++;
				Z[i] = R-L;
				R--;
			}
			else
				Z[i] = Z[i-L];
		}
	}
}

bool mat[MAXN];
bool imat[MAXN];

int main (){
    for_tests(t, tt){
        for(int a=0;a<MAXN;a++){
            mat[a] = imat[a] = 0;
        }
        scanf(" %s", seq);
        ZAlgorithm(seq);
        int n = strlen(seq);
        for(int a=1;a<n;a++){
            if(a - Z[a] <= 0){
                int len = min(Z[a], a);
                mat[a+len-1] = 1;
                //printf("match %d\n", a+len-1);
            }
        }
        reverse(seq, seq+n);
        ZAlgorithm(seq);
        for(int a=1;a<n;a++){
            if(a - Z[a] <= 0){
                int len = min(Z[a], a);
                imat[n-1 - (a+len-1)] = 1;
                //printf("imatch %d\n", n-1-(a+len-1));
            }
        }
        int ans = 0;
        for(int a=0;a+1<n;a++){
            if(mat[a] && imat[a+1])
                ans++;
        }
        printf("%d\n", ans);
    }
}

