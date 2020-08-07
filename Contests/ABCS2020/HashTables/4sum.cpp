#include <bits/stdc++.h>
using namespace std;

vector<long long> readLine(){
    vector<long long> line;
    char c;
    long long val = 0;
    int sign = 1;
    while((c = getchar()) != '\n' && c != EOF){
       if(c == '-')
           sign = -1;
       else if(c == ' '){
           line.push_back(sign*val); 
           val = 0;
           sign = 1;
       }
       else{
           val *= 10; 
           val += (c - '0');
       }
    }
    line.push_back(sign*val);

    return line;
}


int main (){
    map<long long, long long> cnt;
    vector<vector<long long>> s(4);
    for(int a=0;a<4;a++)
        s[a] = readLine();

    int ans = 0;
    for(long long x: s[0]){
        for(long long y: s[1]){
            for(long long z: s[2]){
                for(long long a: s[3]){
                    cnt[x+y+z+a]++;        
                }
            }
        }
    }

    printf("%lld\n", cnt[0]);
}

