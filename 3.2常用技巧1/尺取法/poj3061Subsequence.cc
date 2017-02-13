#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int kMaxn = 100000 + 10;

int sum[kMaxn];

int s,n;

int slove() {
    if(sum[n] < s) {
        return 0;
    }
    int ans = 100000000 + 10;
    for(int i = 1; i <= n; i++) {
        if(sum[i] + s > sum[n])
            break;
        int l = 1; int r = n;
        while(l < r) {
            int mid = (l + r) / 2;
            if(sum[mid] >= sum[i] + s)
                r = mid;
            else l = mid + 1;
        }
        ans = min(ans, l - i);
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &n, &s);
        memset(sum, 0, sizeof(sum));
        for(int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            sum[i] = sum[i - 1] + x;
        }
        printf("%d\n", slove());
    }
    return 0;
}
