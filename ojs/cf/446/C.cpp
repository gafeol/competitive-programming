#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)

template <typename T> void write(ostream& out, T t) {
	out << t << "\n";
}
template <typename T, typename... Args>
void write(ostream& out, T t, Args... args) {
	out << t << ' ';
	write(out, args...);
}

template <typename... Args>
void debug(Args... args) {
	#ifdef LOCAL
		write(cerr, args...);
	#endif
}


template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const int modn = 1000000009;
inline int mod(int x) { return x % modn; }

const int MAXN = 312345;
const int SQ = 9+sqrt(300000);

int n, m, k;
int s[MAXN];
int bck[MAXN];
int sq;

int sum[SQ], A[SQ], B[SQ];

int fib[MAXN], sfib[MAXN];
int fib2[MAXN], sfib2[MAXN];

inline void upd(int b){
	int fs = A[b];
	int sd = B[b];
	A[b] = 0;
	B[b] = 0;
	int l = b*sq;
	int r = (b+1)*sq-1;
	//printf("upd blc %d de %d - %d A %lld B %lld\n", b, l, r, fs, sd);
	for(int a=l;a<=r;a++){
		s[a] = mod(s[a] + fs);
		swap(fs, sd);
		sd = mod(sd + fs);
	}

}

int main (){
	sq = sqrt(300000);
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		bck[a] = a/sq;
		sum[bck[a]] = mod(sum[bck[a]] + s[a]);
	}
	
	fib[0] = sfib[0] = 0;
	fib[1] = sfib[1] = 1;
	fib[2] = 1; sfib[2] = 2;
	fib2[1] = 1; sfib2[1] = 1;
	fib2[2] = 0; sfib2[2] = 1;


	for(int a=3;a<=sq+10;a++){
		fib[a] = mod(fib[a-1] + fib[a-2]);	
		sfib[a] = mod(sfib[a-1] + fib[a]);
		fib2[a] = mod(fib2[a-1] + fib2[a-2]);	
		sfib2[a] = mod(sfib2[a-1] + fib2[a]);
	}

	for(int a=0;a<m;a++){
		int t, i, j;
		scanf("%d%d%d", &t, &i, &j);	
		i--;j--;
		int bi = bck[i], bj = bck[j];
		if(t == 2){
			upd(bi);
			upd(bj);
			int ans = 0;
			if(bi != bj){
				int b = i;
				while(bck[b] == bi){
					ans = mod(ans + s[b]);
					b++;
				}
				b = bj*sq;
				while(b <= j){
					ans = mod(ans + s[b]);
					b++;
				}
				for(b = bi+1;b < bj;b++)
					ans = mod(sum[b] + ans);
			}
			else{
				for(int b=i;b<=j;b++)
					ans = mod(ans + s[b]);
			}
			printf("%d\n", ans);
		}
		else{
			int fs = 1, sd = 1;		
			if(bi != bj){
				int b = i;
				while(bck[b] == bi){
					sum[bi] = sum[bi] - s[b];
					s[b] = mod(s[b] + fs);
					sum[bi] = mod(sum[bi] + s[b]);
					b++;

					swap(fs, sd);
					sd = mod(sd + fs);
				}
				sum[bi] = mod(modn + mod(sum[bi]));
				while(bck[b] != bj){
					int bb = bck[b];
					A[bck[b]] = mod(A[bck[b]] + fs);
					B[bck[b]] = mod(B[bck[b]] + sd);
					sum[bb] = mod(sum[bb] +  (fs*((ll)sfib2[sq]))%modn);
					sum[bb] = mod(sum[bb] +  (sd*((ll)sfib[sq-1]))%modn);
					ll ofs = fs, osd = sd;
					fs = mod((fib2[sq+1]*ofs)%modn + (fib[sq]*osd)%modn);
					sd = mod((fib2[sq+2]*ofs)%modn + (fib[sq+1]*osd)%modn);
					b += sq;
				}
				while(b <= j){
					sum[bj] = sum[bj] - s[b];
					s[b] = mod(s[b] + fs);
					sum[bj] = mod(sum[bj] + s[b]);
					b++;

					swap(fs, sd);
					sd = mod(sd + fs);
				}
				sum[bj] = mod(sum[bj] + modn);
			}
			else{
				for(int b=i;b<=j;b++){
					sum[bi] = sum[bi] - s[b];
					s[b] = mod(s[b] + fs);
					sum[bi] = mod(sum[bi] + s[b]);

					swap(fs, sd);
					sd = mod(sd + fs);
				}
				sum[bi] = mod(sum[bi] + modn);
			}
		}
		if(false){
			for(int a=0;a<n;a++){
				printf("%d%c", s[a], " \n"[a==n-1]);
			}
			for(int a=0;a<n;a++){
				if(a == 0 || bck[a] != bck[(a-1)]){
					printf("bckt %d\n A %d B %lld sum %d\n", a/sq, A[a/sq], B[a/sq], sum[a/sq]);
				}
			}
		}
	}
}
