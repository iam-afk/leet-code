// @leet start

import java.util.ArrayList;
import java.util.PriorityQueue;

class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        record Edge(int to, int weight) {}
        ArrayList<ArrayList<Edge>> graph = new ArrayList<>(n);
        for (int i = 0; i < n; i++)
            graph.add(new ArrayList<>());
        for (var edge : edges) {
            graph.get(edge[0]).add(new Edge(edge[1], edge[2]));
            graph.get(edge[1]).add(new Edge(edge[0], edge[2]));
        }

        var minNeighbours = Integer.MAX_VALUE;
        var city = -1;
        for (int i = 0; i < n; i++) {
            var visited = new boolean[n];
            record Node(int city, int threshold) {}
            var queue = new PriorityQueue<Node>((n1, n2) -> Integer.compare(n2.threshold, n1.threshold));
            var node = new Node(i, distanceThreshold);
            queue.add(node);
            var neighbours = 0;
            while ((node = queue.poll()) != null) {
                if (visited[node.city]) continue;
                visited[node.city] = true;
                neighbours++;
                for (var edge : graph.get(node.city)) {
                    if (edge.to >= 0 && !visited[edge.to] && edge.weight <= node.threshold) {
                        queue.add(new Node(edge.to, node.threshold - edge.weight));
                    }
                }
            }
            if (neighbours <= minNeighbours) {
                minNeighbours = neighbours;
                city = i;
            }
        }
        return city;
    }
}
// @leet end