#define min(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = a;                                                                          \
    __typeof__(b) _b = b;                                                                          \
    _a < _b ? _a : _b;                                                                             \
  })

typedef struct
{
  int size;
  int i[100][100];
} Graph;

static int const INF = 1e9;

Graph*
graphCreate(int n, int** edges, int edges_size, int* edges_col_size)
{
  Graph* graph = malloc(sizeof *graph);
  graph->size = n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      graph->i[i][j] = i == j ? 0 : INF;
  for (int i = 0; i < edges_size; ++i) {
    int v = edges[i][0], u = edges[i][1], w = edges[i][2];
    graph->i[v][u] = w;
  }
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        graph->i[i][j] = min(graph->i[i][j], graph->i[i][k] + graph->i[k][j]);
  return graph;
}

void
graphAddEdge(Graph* graph, int* edge, int edge_size)
{
  int v = edge[0], u = edge[1], w = edge[2];
  for (int i = 0; i < graph->size; ++i)
    for (int j = 0; j < graph->size; ++j)
      graph->i[i][j] = min(graph->i[i][j], graph->i[i][v] + w + graph->i[u][j]);
}

int
graphShortestPath(Graph* graph, int node1, int node2)
{
  return graph->i[node1][node2] < INF ? graph->i[node1][node2] : -1;
}

void
graphFree(Graph* graph)
{
  free(graph);
}

/**
 * Your Graph struct will be instantiated and called as such:
 * Graph* obj = graphCreate(n, edges, edgesSize, edgesColSize);
 * graphAddEdge(obj, edge, edgeSize);

 * int param_2 = graphShortestPath(obj, node1, node2);

 * graphFree(obj);
*/