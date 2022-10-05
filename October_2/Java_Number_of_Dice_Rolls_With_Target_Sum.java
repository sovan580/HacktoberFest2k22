class Solution {
    private int mod = 1_000_000_007;
    public int numRollsToTarget(int n, int k, int target) {
        Integer[][] memo = new Integer[n+1][target+1] ;
        func(n,k,target, memo);
        return memo[n][target];
    }
    
    private int func(int n, int k, int t, Integer[][] memo)
    {
        if(t<0 || n< 0)
        {
            return 0;
        }
        
        if(t<=k && n == 1)
        { 
            memo[n][t] = 1;
            return 1;
        }
        //  Check null instaed of 0, as there could be a combination where we have 0 result.
        if(memo[n][t]!=null)
        {
            // if(memo[n][t]>0)
            // System.out.println("cache "+memo[n][t] +" n "+n +" t "+t);
            return  memo[n][t];
        }else{
            int sum = 0;
        for(int i=1; n>1 && i<t && i<=k ; i++)
        {
            int temp = func(n-1,k,t-i,memo)%mod; 
            sum = (sum + temp)%mod;
               
        }
        memo[n][t] = sum;
        return  memo[n][t];
        }
        
    }
}
