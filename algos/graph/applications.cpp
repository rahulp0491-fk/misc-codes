#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <utility>
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

/*
 * Cormen 22.2-8
 * Find diameter of a tree
 * Using BFS
 */

pair<int, int> bfs_get_depth(int root) {
  queue <int> q;
  int mx, mxv;
  q.push(root);
  vis[root] = 1;
  mx = depth[root] = 0;
  mxv = root;
  pair<int, int> p;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if (vis[v]) continue;
      q.push(v);
      vis[v] = 1;
      depth[v] = depth[u] + 1;
      if (depth[v] > mx) mx = depth[v], mxv = v;
    }
  }
  p = make_pair(mx, mxv);
  return p;
}

/*
 * Driver function for diameter of a tree
 */
void diameter(int n) {
  if (!n) return;
  pair<int, int> deep = bfs_get_depth(0), res;
  graph_init();
  res = bfs_get_depth(deep.second);
  printf ("[%s] diameter = %d\n", __FUNCTION__, res.first);
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

#if 0
  /* Bipartite check */
  check_bipartite(n);
#endif  

  /* Diameter of a tree */
  diameter(n);
  return 0;
}
