class Solution {
  fun minCost(colors: String, neededTime: IntArray): Int {
    var prev = '0'
    var prevPoint = 0
    var count = 0
    for (i in colors.indices) {
      if (prev == colors[i]) {
        count += Math.min(neededTime[i], prevPoint)
        prevPoint = Math.max(neededTime[i], prevPoint)
      } else {
        prevPoint = neededTime[i]
        prev = colors[i]
      }
    }
    return count
  }
}
