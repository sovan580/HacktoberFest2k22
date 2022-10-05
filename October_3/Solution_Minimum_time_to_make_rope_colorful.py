class Solution:
def minCost(self, colors: str, neededTime: List[int]) -> int:

    colors = colors + 'z'
    neededTime.append(0)
    point_1 = 0
    point_2 = 1
        
    tot_time = 0
    
    while point_2 < len(colors):
        if colors[point_1] == colors[point_2]:
            point_2 += 1
            
        else:
            if point_2 > point_1 + 1:
                tot_time += sum(sorted(neededTime[point_1:point_2])[:-1])
                
            point_1, point_2 = point_2, point_2 + 1
            
            
    return tot_time
