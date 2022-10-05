class Solution {
    public int numDecodings(String s) {
      
        
        int n=s.length();
        
        int count=1;
        
        if(s.charAt(0)=='0') return 0;
        if(n==1) return 1;
        
        
        int r=1,l=1,temp=0;
        for(int i=1;i<n;i++)
        {
            temp=r;
            r+=l;
            if(s.charAt(i)=='0')
                r=l;
            String str=s.substring(i-1,i+1);
            if(Integer.valueOf(str)>26 || str.charAt(0)=='0')
                r-=l;
            
            if(r==0) return 0;
            l=temp;
        }
        return r;
    }
}
