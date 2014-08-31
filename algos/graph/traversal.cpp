#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include "graph_common.h"

using namespace std;

void bfs(int root) {
  queue <int> q;
  q.push(root);
  vis[root] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if (vis[v]) continue;
      q.push(v);
      vis[v] = 1;
    }
    printf ("[%s] visited %d\n", __FUNCTION__, u);
  }
}

void traverse(int n, int macro) {
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n; i++) {
    if (macro == BFS) {
      if (!vis[i]) bfs(i);
    }
  }
}

int main() {
  int n, m, u, v;
  scanf("%d %d", &n, &m);
  while (m--) {
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  /* Breadth First Search */
  traverse(n, BFS);
  return 0;
}
