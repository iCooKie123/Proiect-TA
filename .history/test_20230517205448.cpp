#include <iostream>
#include <cmath>

using namespace std;

const int MAX_N = 100;

int dp[MAX_N + 1][MAX_N + 1];

int longest_common_subsequence(int a[], int n, int b[], int m) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}


int a[]= {1,3,-1,0,2,7};
int b[]={3,-1,1,0,4};
int n=sizeof(a);
int m=sizeof(b);

cout<<longest_common_subsequence(a, n, b, m)<<endl;