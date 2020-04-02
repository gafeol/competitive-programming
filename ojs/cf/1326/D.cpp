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
const ll P = 27;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1123456;

int n, m, k;
char os[MAXN];


// Z Algorithm
//////////////
const int MAXS = MAXN*2;

int L, R, Z[MAXS];

char s[MAXS];

inline void ZAlgorithm(){
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


int main (){
    for_tests(t, tt){
        scanf(" %s", os);
        n = strlen(os);
        int i = 0, j = n-1;
        while(i < j){
            if(os[i] != os[j]) break;
            i++;
            j--;
        }
        int cnt = 0;
        for(int a=i;a<=j;a++){
            s[cnt++] = os[a];
        }
        int aux = cnt-1;
        while(aux >= 0) // mirror
            s[cnt++] = s[aux--];
        s[cnt] = '\0';
        ZAlgorithm();
        int pre = 0;
        for(int a=cnt/2;a<cnt;a++){
            if(Z[a] + a == cnt){
                pre = Z[a];
                break;
            }
        }


        cnt = 0;
        for(int a=j;a>=i;a--)
            s[cnt++] = os[a];
        s[cnt] = '\0';
        aux = cnt-1;
        while(aux >= 0) // mirror
            s[cnt++] = s[aux--];
        ZAlgorithm();
        int suf = 0;
        for(int a=cnt/2;a<cnt;a++){
            if(Z[a] + a == cnt){
                suf = Z[a];
                break;
            }
        }

        for(int a=0;a<i;a++){
            printf("%c", os[a]);
        }
        if(pre > suf){
            for(int a=i;a<i+pre;a++){
                printf("%c", os[a]);
            }
        }
        else{
            for(int a=j-suf+1;a<=j;a++){
                printf("%c", os[a]);
            }
        }
        for(int a=j+1;a<n;a++){
            printf("%c", os[a]);
        }
        puts("");
    }
}

