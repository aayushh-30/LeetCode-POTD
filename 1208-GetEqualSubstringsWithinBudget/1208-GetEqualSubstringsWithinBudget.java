// Last updated: 10/8/2025, 2:09:12 AM
class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int n = s.length();
        ArrayList<Integer> cost = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            cost.add(Math.abs(s.charAt(i) - t.charAt(i)));
        }

        int i = 0;
        int j = 0;
        int ans = 0;
        int sum = 0;

        while (j < n) {
            sum += cost.get(j);

            while (i <= j && sum > maxCost) {
                sum -= cost.get(i);
                i++;
            }

            ans = Math.max(ans, j - i + 1); 
            j++;
        }

        return ans;
    }
}
