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

const int MAXN = 112;

int n, m, k;


void mult(vector<vector<double>> &U, vector<vector<double>> &T){
    vector<vector<double>> aux(n, vector<double>(n));
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            aux[a][b] = 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                aux[i][j] += U[i][k]*T[k][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            U[i][j] = aux[i][j];
        }
    }

}
void expo(vector<vector<double>> &m, vector<vector<double>> &base, int e){
    if(e == 0){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m[i][j] = (i==j);
            }
        }
        return ;
    }
    expo(m, base, e/2);
    mult(m, m);

    if(e&1)
        mult(m, base);
}

int main (){
    int A, B, C;
    while(scanf("%d%d%d%d", &n, &A, &B, &C) != EOF){
        A--;
        B--;
        C--;
        vector<vector<double> > adj(n, vector<double>(n));
        vector<vector<double> > base(n, vector<double>(n));
        for(int a=0;a<n;a++){
            for(int b=0;b<n;b++){
                adj[a][b] = base[a][b] = 0;
            }
        }
        for(int a=1;a<n;a++){
            int i, j;
            scanf("%d%d", &i, &j); 
            i--;
            j--;
            adj[i][j] = 1;
            adj[j][i] = 1;
        }
        for(int i=0;i<n;i++){
            if(i != B && i != C){
                int sum = 0;
                for(int j=0;j<n;j++){
                    sum += adj[i][j];
                }
                if(sum == 0) continue;
                for(int j=0;j<n;j++)
                    adj[i][j] = adj[i][j]/((double)sum);
            }
            else{
                for(int j=0;j<n;j++)
                    adj[i][j] = (i == j);
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                base[i][j] = adj[i][j];
        int exp = 1000000;
        expo(adj, base, exp);
        printf("%.6f\n", adj[A][B]);
    }
}

