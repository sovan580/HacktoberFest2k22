class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        MOD = 1e9 + 7
        dp = {}
        for i in range(1, min(k+1, target+1)):
            dp[(1, i)]= 1
            
        def get_num_ways(n, k, target):
            if target <= 0 or n <= 0 or target < n or target > n*k:
                return 0
            if (n, target) not in dp:
                ways = 0
                for i in range(1, min(k+1, target+1)):
                    ways += get_num_ways(n-1, k, target-i) 
                dp[(n, target)] = int(ways % MOD)
                
            return dp[(n, target)]
        
        return int(get_num_ways(n, k, target) % MOD)
