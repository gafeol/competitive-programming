#include <bits/stdc++.h>
using namespace std;
const int MAXN = 212345;
#define fst first
#define snd second
typedef pair<int, int> pii;

int n, m, k;
pii s[MAXN];

bool go(int t){
    multiset<int> beg, fim;
    for(int a=0;a<t;a++){
        beg.insert(s[a].fst);
        fim.insert(s[a].snd);
    }
    int i = 0;
    if(*fim.begin() - *beg.rbegin() + 1 >= t)
        return true;
    while(i + t < n){
        beg.erase(beg.find(s[i].fst));
        fim.erase(fim.find(s[i].snd));
        beg.insert(s[i+t].fst);
        fim.insert(s[i+t].snd);
        if(*fim.begin() - *beg.rbegin() + 1 >= t)
            return true;
        i++;
    }
    return false;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        int i,j;
        scanf("%d%d", &i, &j);
        s[a] = {i, j};
	}

    int i = 1, j = n;
    while(i < j){
        int m = (i + j+1)/2;
        if(go(m))
            i = m;
        else
            j = m-1;
    }
    printf("%d\n", i);
}

