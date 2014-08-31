#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include "graph_common.h"

using namespace std;

/*
 * Cormen 22.2-7
 * Check if an undirected graph is bi-partite
 * Using BFS
 */

bool bipartite(int root) {
  queue <int> q;
  q.push(root);
  vis[root] = 1;
  color[root] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if (vis[v]) {
	if (color[v] == color[u]) return false;
	continue;
      }
      q.push(v);
      vis[v] = 1;
      pi[v] = u;
      color[v] = 1 - color[u];
    }
  }
  return true;
}

/*
 * Driver function for checking if an undirected graph is bipartite
 */
void check_bipartite(int n) {
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    if (!bipartite(i)) {
      printf ("[%s] not a bipartite graph\n", __FUNCTION__);
      return;
    }
  }
  printf ("[%s] bipartite graph\n", __FUNCTION__);
}

int main() {
  int n, m, u, v;
  scanf("%d %d", &n, &m);
  while (m--) {
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  graph_init();

  /* Bipartite check */
  check_bipartite(n);
  return 0;
}
