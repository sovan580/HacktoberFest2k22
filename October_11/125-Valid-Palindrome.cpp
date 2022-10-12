class Solution {
public:
    bool isPalindrome(string s) {
        
        int n = s.length();
        string a;
        for(int i=0;i<n;i++){
            if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>='0'&& s[i]<='9')) {
             a.push_back(s[i]);   
            }
        }
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        cout<<a;
        n=a.length();
        if(n==0) return true;
        int l=0,r=n-1;
        while(l<r){
            if(a[l]!=a[r])return false;
            l++,r--;
        }
        return true;
    }
};
