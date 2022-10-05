class Solution {
    public int minCost(String colors, int[] neededTime) {
        //looks like greedy will work
        int ans = 0;
        
        for(int i=0;i<colors.length();i++){
            //same character in next index ?
            if(i+1 < colors.length() && colors.charAt(i) == colors.charAt(i+1)) {
                int j = i;
                int max = neededTime[j];
                int total = neededTime[j];
                while(j+1 < colors.length() && colors.charAt(j) == colors.charAt(j+1)){
                    max = Math.max(max, neededTime[j+1]);
                    total += neededTime[j+1];
                    j++;
                }
                i = j;
                ans += (total-max);
            }
        }
        return ans;
    }
}
