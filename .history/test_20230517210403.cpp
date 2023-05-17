#include <iostream>

void longestCommonSubsequence(int a[], int m, int b[], int n) {
    // Inițializăm o matrice pentru stocarea subsirurilor comune
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    // Reconstruim cel mai lung subsir comun
    int lcsLength = dp[m][n];
    int lcs[lcsLength];
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs[lcsLength - 1] = a[i - 1];
            --lcsLength;
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    
    // Afișăm cel mai lung subsir comun
    std::cout << "Cel mai lung subsir comun: ";
    for (int i = 0; i < sizeof(lcs) / sizeof(lcs[0]); ++i) {
        std::cout << lcs[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int a[] = {1, 3, -1, 0, 2, 7};
    int b[] = {3, -1, 1, 0, 4};
    
    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);
    
    longestCommonSubsequence(a, m, b, n);
    
    return 0;
}
