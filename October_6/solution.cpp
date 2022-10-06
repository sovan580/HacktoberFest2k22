class TimeMap {
public:
    map<string, vector<pair<int,string>>> mp;
//     TimeMap() {
        
//     }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        string ans="";
        // for(auto &it : mp[key] )
        // {
        //     if(it.first>timestamp) break;
        //     ans=it.second;
        // }
        int left=0,right=mp[key].size()-1,mid;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(mp[key][mid].first<timestamp) left=mid+1;
            else if(mp[key][mid].first==timestamp) return mp[key][mid].second;
            else right=mid-1;
            
        }
        if(right>=0) ans=mp[key][right].second;
        return ans;
    }
};
