#include "bits/stdc++.h"
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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 31234;

int n, m, k;
int s[MAXN];

string code = ">,<>>,>,<[->->+<><<]+->>[-<<+>>]<+-><><<<[-+->-<+-<+>]<[->+<]><>>>>>><>++->>+->>>>>+[>><>>>[-]<[-<>-+]<<>[-+-]-++-+-<[-]<><<>[+---+]<><<<<+-<<<<>-+<><<<><+-<<[->>>>>>>+>>>>>-+>+<<<><<<><<<<<<<<<]>[->>>>><><>><>>+>>>>>>+<<<<<><<<<<+-<<<<]>[->>>>>>><>+>>>>-+><>>+<<<<<<+-<<<<><<<<-+><]>>-++-+>+-+[<-]<[->><>++-<<<]>>>>[-<<<+--+<<<<+>><>>>>>>]>[-<<-+<<<<<+<>>+->>>>>>]>[-<<<<><<<><<+>>>>>>>]>>>>>><>>+[-<<<<+--+<><+-<<<<<<[->>+>>+<<<<]+->[->>+>>+-+<<<<]>[-<<+>>]>[-<<+>>]+[[<>-]-++>[<-]<+-[+--><>><>-<<<]>>-+->>>+>[<-]<+-[->+>[-<-]<[>>[-<<-+->]-<<[->><->+->-+-<<<<]]<]>>-<<<<<+>[><<-]<[>+->[-+<<->]<<[<]]>-+-]>>>>><>>>><>+]-<<<>+-<<<>+>-++[<-]<[-+>>+[<<<>->-+]<<[>>>+[<-+<<->>]<<<[<]]]>-]>>>>[-]<<<<<<<-+<><<<<<<<[-]>>+>+[<-]<[->>+<><<<]>+>[<-]<[>>[<<->]<<[<]]>-[+>>>>>>><++-+++++++++<<<<<<+>+-[<<>-]<[>>[<<->]<<[<]]>-[++>[<-]<[->>-<<<]>>->>+>>+>-[<-]<[<<[->>>+<<><<]+->>>>>+>+[<><-]<><[->>+<<<]<<-<]<<<<+>[<-]<[>>[<<->]<<[<]]>-]>>++++++++[->++++++<]>[-<<<<+>>>>]>>>>>+><>-+[<-]<[>>[<<->]<<[<]]>-[++>[<-]<[->>-<<<]>>-<<<<<<<<+>+[<-]<[->>+<<<]>>>>>>>>+>[<-]<[>>[<<->]<<[<]]>-]<<[-]<<<<<+>[<-]<[>>[<<->]<<[<]]>-]<<[.<]!";

int ot[MAXN];

void init(){
    stack<int> st;
    while(!st.empty())
        st.pop();
    for(int i=0;i<code.size();i++){
        if(code[i] == '['){
            st.push(i);
            //printf("code[%d] %c push %d\n", i, code[i], i);
        }
        else if(code[i] == ']'){
            assert(!st.empty());
            //printf("st top %d\n", st.top());
            ot[st.top()] = i;
            ot[i] = st.top();
            //printf("fecha tag  em %d code[%d] %c\n", i, ot[i], code[ot[i]]);
            assert(ot[i] < i);
            assert(code[ot[i]] == '[');
            st.pop();
        }
    }
    assert(st.empty());
}

char inp[5];
int deg;
int read(){
    assert(deg <= 2);
    return inp[deg++];
}

void run(){
    vector<int> data(MAXN, 0);
    int pos = 0;
    for(int i=0;i<code.size();i++){
        if(pos < 0 || pos >= data.size()){
            printf("pos %d\n", pos);
        }
        //assert(pos >= 0 && pos < data.size());
        //assert(data[pos] >= 0 && data[pos] < 256);
        printf("roda i %d\n", i);
        if(code[i] == '<'){
            pos--;
            printf(" < pos %d\n", pos);
            assert(pos >= 0);
        }
        else if(code[i] == '>'){
            pos++;
            printf(" > pos %d\n", pos);
            assert(pos < MAXN);
        }
        else if(code[i] == '+'){
            data[pos]++;
            if(data[pos] == 256)
                data[pos] = 0;
            //printf("plus data[%d] %d\n", pos, data[pos]);
        }
        else if(code[i] == '-'){
            data[pos]--;
            if(data[pos] == -1)
                data[pos] = 255;
            //printf("sub data[%d] %d\n", pos, data[pos]);
        }
        else if(code[i] == '.'){
            printf("%d", data[pos]);
        }
        else if(code[i] == ','){
            //printf("leu em i %d\n", i);
            data[pos] = read(); 
        }
        else if(code[i] == '['){
            if(data[pos] != 0)
                continue;
            printf("pode pular aqui i %d pra %d\n", i, ot[i]+1);
            i = ot[i];
        }
        else if(code[i] == ']'){
            if(data[pos] != 0)
                continue;
            printf("to em i %d volta ai pra %d\n", i, ot[i]-1);
            i = ot[i];
        }
        else if(code[i] == '!'){
            return ;
        }
        else
            assert(false);

    }
}

int main (){
    init();
    for(char a='!';a<='~';a++){
        inp[0] = a;
        for(char b='!';b<='~';b++){
            inp[1] = b;
            for(char c='!';c<='~';c++){
                inp[2] = c;
                deg = 0;
                printf("ans[\"%c%c%c\"] = ", a, b, c);
                fflush(stdout);
                run();
                puts("");
            }
        }
    }
    return 0;
}

