#include <iostream>
#include <vector>

std::vector<int> longestCommonSubsequence(const std::vector<int>& a, const std::vector<int>& b) {
    int m = a.size();
    int n = b.size();
    
    // Inițializăm o matrice pentru stocarea subsirurilor comune
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    
    // Construim matricea dp folosind programarea dinamică
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    // Reconstruim cel mai lung subsir comun
    std::vector<int> lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs.insert(lcs.begin(), a[i - 1]);
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    
    return lcs;
}

int main() {
    std::vector<int> a = {1, 3, -1, 0, 2, 7};
    std::vector<int> b = {3, -1, 1, 0, 4};
    
    std::vector<int> lcs = longestCommonSubsequence(a, b);
    
    std::cout << "Cel mai lung subsir comun: ";
    for (int i = 0; i < lcs.size(); ++i) {
        std::cout << lcs[i] << " ";
    }
    
    return 0;
}
