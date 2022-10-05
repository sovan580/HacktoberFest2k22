def numDecodings(self, s: str) -> int:
    memo = [-1 for i in range(len(s))]
    
    def convert(n: int) -> chr:
        n = n + 64
        return chr(n)
    
    def decode(s: str, memo: List[int], ind: int) -> int:
        if ind >= len(s):
            return 1
        
        if int(s[ind]) == 0:
            return 0
        
        if memo[ind] != -1:
            return memo[ind]
        
        count = decode(s, memo, ind + 1)
        
        if ind < len(s) - 1:
            num = (int(s[ind]) * 10) + int(s[ind+1])
            if num <= 26:
                count += decode(s, memo, ind + 2)
                
        memo[ind] = count
            
        return memo[ind]
    
    return decode(s, memo, 0)
