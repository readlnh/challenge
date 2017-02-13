#include <cstdio>
#include <iostream>
#include <map>
#include <set>
using namespace std;

const int kMaxp = 1000000 + 10;

int p;

int a[kMaxp];

void slove() {
    set<int>se;
    for(int i = 1; i <= p; i++)
        se.insert(a[i]);
    int cnt = se.size();
    int s = 1, t = 1, num = 0;
    map<int, int> count;
    int ans = p + 1;
    for(;;) {
        while(t <= p && num < cnt) {
            if(count[a[t]] == 0) num++;
            count[a[t]]++;
            t++;
        }  
        if(num < cnt) break;
        ans = min(ans, t - s);
        count[a[s]]--;
        if(count[a[s]] == 0) num--;
        s++;
    }
    printf("%d\n", ans);
}

int main() {
    while(~scanf("%d", &p)) {
        for(int i = 1; i <= p; i++)
            scanf("%d", &a[i]);
        slove();
    }
    return 0;
}
