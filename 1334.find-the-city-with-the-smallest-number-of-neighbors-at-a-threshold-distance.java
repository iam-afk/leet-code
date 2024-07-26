// @leet start
class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        int[][] d = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[i][j] = i == j ? 0 : Integer.MAX_VALUE / 2;
        for (var edge : edges) {
            d[edge[0]][edge[1]] = edge[2];
            d[edge[1]][edge[0]] = edge[2];
        }
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
        var mn = Integer.MAX_VALUE;
        var city = -1;
        for (int i = 0; i < n; i++) {
            var c = 0;
            for (int j = 0; j < n; j++)
                if (i != j && d[i][j] <= distanceThreshold)
                    c++;
            if (c <= mn) {
                mn = c;
                city = i;
            }
        }
        return city;
    }
}
// @leet end