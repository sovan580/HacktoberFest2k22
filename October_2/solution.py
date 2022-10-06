class Solution:             # Here's the plan:
                            #   We apply dp by recursion, in which we define the simpler problem as determining the
                            #   result for each possible roll of the ith die. The state tree is complete n-nary k levels,
                            #   which has n^k-1 nodes, but the recursive call has only n*k possible inputs, so caching
                            #   the recursive function call reduces the number of computations significantly.
    @lru_cache(maxsize=None)
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:

        if target <= 0 or n*k < target :
            return 0

        if n==1:
            return int(target <= k)

        for i in range(1, k+1):
            ans = sum(self.numRollsToTarget(n-1,k,target-i)
                     for i in range(1, k+1))
        
        return ans % (10**9+7)
