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

bool valid(int i, int j){
    return (i>= 0 && j>=0 && i < n && j < m);
}

bool full(int i, int j, int ii, int jj, vector<vector<int>> &acc){
    if(!valid(i, j) || !valid(ii, jj)) return false;
    int sum = acc[i][j];
    if(ii > 0)
        sum -= acc[ii-1][j];
    if(jj > 0)
        sum -= acc[i][jj-1];
    if(ii > 0 && jj > 0)
        sum += acc[ii-1][jj-1];
    //printf("full? %d %d %d %d sum %d mult %d\n", i, j, ii, jj, sum , (i - ii + 1)*(j - jj + 1));
    return (sum == (i - ii + 1)*(j - jj + 1));
}

vector<vector<char>> ans;

bool go(int k, vector<vector<int> > &M, vector<vector<int>> &acc){
    int cnt = 0;
    ans.clear();
    for(int a=0;a<n;a++)
        ans.pb(vector<char>(m, '.'));
    vector<vector<int>> aux(n, vector<int>(m, 0));
    //printf("test k %d\n", k);
    for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            if(full(a+k, b+k, a-k, b-k, acc)){
                //printf("full %d %d %d %d\n", a+k, b+k, a-k, b-k);
                ans[a][b] = 'X';
                aux[a-k][b-k]++;
                if(valid(a-k, b+k+1))
                    aux[a-k][b+k+1]--;
                if(valid(a+k+1, b-k))
                    aux[a+k+1][b-k]--;
                if(valid(a+k+1, b+k+1))
                    aux[a+k+1][b+k+1]++;
            }
        }
    }
    for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            if(a > 0)
                aux[a][b] += aux[a-1][b];
            if(b > 0)
                aux[a][b] += aux[a][b-1];
            if(a > 0 && b > 0)
                aux[a][b] -= aux[a-1][b-1];
            if((aux[a][b] > 0) != M[a][b]){
                //printf("a %d  b %d diff\n", a, b);
                return false;
            }
        }
    }
    return true;
}

int main (){
	scanf("%d%d", &n, &m);
    vector<vector<int>> M(n, vector<int>(m, 0));
    vector<vector<int>> acc(n, vector<int>(m, 0));
	for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            char c;
            scanf(" %c", &c);
            M[a][b] = (c == 'X');
            acc[a][b] = M[a][b];
            if(a > 0 && b > 0)
                acc[a][b] -= acc[a-1][b-1];
            if(a > 0)
                acc[a][b] += acc[a-1][b];
            if(b > 0)
                acc[a][b] += acc[a][b-1];
        }
	}
    int i = 0, j = min(n, m);
    while(i < j){
        int m = (i + j +1)/2;
        if(go(m, M, acc))
            i = m;
        else
            j = m - 1; 
    }
    go(i, M, acc);
    printf("%d\n", i);
    for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            printf("%c", ans[a][b]);
        }
        puts("");
    }
}

