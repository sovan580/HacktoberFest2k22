class Solution {
public:
int dp[31][1001] = {0};
int numRollsToTarget(int n, int k, int target) {
dp[0][0] = 1;

    for(int i = 1;i<=target;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            long long res = 0;
            for(int x=1;x<=k;x++){
                if(j>=x){
                    res += dp[i-1][j-x] % 1000000007;
                    res = res % 1000000007;
                }
            }
            dp[i][j] = res ;
        }
    }
    return dp[n][target] ;
}};
