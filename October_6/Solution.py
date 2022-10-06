class TimeMap:

    def _init_(self):
        self.main=defaultdict(list)
        

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.main[key].append((value,timestamp))
        

    def get(self, key: str, timestamp: int) -> str:
        # print (self.main)
        if key in self.main:
            l,r=0,len(self.main[key])-1
            while l<r:
                mid=(l+r)//2
                if self.main[key][mid][1]>timestamp:
                    r=mid-1
                elif self.main[key][mid][1]<timestamp:
                    l=mid+1
                else:
                    return self.main[key][mid][0]
            if  self.main[key][l][1]<=timestamp:
                return self.main[key][l][0]
            elif self.main[key][l-1][1]<=timestamp:
                return self.main[key][l-1][0]
        return ""
