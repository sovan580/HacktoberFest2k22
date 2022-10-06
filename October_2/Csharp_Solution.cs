public class Solution {
    int modulo = (int)Math.Pow(10, 9) + 7;
    
    public int NumRollsToTarget(int n, int k, int target) {
        int[][] diceResults = new int[n+1][];
        
        for(int i=0; i<=n; i++){
            diceResults[i] = new int[target+1];
            Array.Fill(diceResults[i], -1);
        }
        
        return NumRollsToTargetHelper(n, k, target, diceResults);
    }
    
    private int NumRollsToTargetHelper(int n, int k, int target, int[][] diceResults){
        if(n == 0 && target == 0)
            return 1;
        
        if(n == 0 || target < 0)
            return 0;
        
        if(diceResults[n][target] != -1){
            return diceResults[n][target];
        }
        
        long count = 0;
        
        for(int i=1; i<=k; i++){
            int temp = NumRollsToTargetHelper(n-1, k, target-i, diceResults);
            count = (count + temp)%modulo;
        }
        
        diceResults[n][target] = (int)count%modulo;
        return diceResults[n][target];
    }
}
