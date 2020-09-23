#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <climits>
using namespace std;
#define pb push_back

const int MAXN = 11234;

int n, m, k;
int nxt[MAXN], bef[MAXN];
vector<int> b[MAXN];
int freq[MAXN];

inline void enqueue(int i, queue<int> &q){
    //printf("enque %d\n", i);
    nxt[bef[i]] = nxt[i];
    bef[nxt[i]] = bef[i];
    q.push(i);
}

int main (){
    int tt = 1;
    while(scanf("%d%d", &n, &m) != EOF && n+m){
        for(int a=1;a<=n;a++){
            nxt[a] = a+1;
            bef[a] = a-1;
            b[a].clear();
            freq[a] = 0;
        }
        bef[1] = nxt[n] = 0;
        nxt[0] = 1;
        bef[0] = n;
        for(int a=0;a<m;a++){
            int i, j;
            scanf("%d%d", &i, &j);
            b[i].pb(j);
            b[j].pb(i);
        }
        queue<int> q;
        enqueue(1, q);
        int ans = -1;
        while(!q.empty()){
            int u = q.front();
            for(int i=0;i<b[u].size();i++)
                freq[b[u][i]]++;
            q.pop();
            ans++;
            int ns = nxt[0];
            int ini = 0;
            while(ns != 0){
                if(!freq[ns])
                    enqueue(ns, q);
                ns = nxt[ns];
            }
            for(int i=0;i<b[u].size();i++)
                freq[b[u][i]]--;
        }
        printf("Case %d: %d\n", tt++, ans);
    }
}

