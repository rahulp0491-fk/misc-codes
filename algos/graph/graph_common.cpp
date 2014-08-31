#include <iostream>
#include <cstdio>
#include <cstring>
#include "graph_common.h"

using namespace std;

vector <int> adj[1000];
int vis[NODES];        // visited array
int pi[NODES];         // parent array
int color[NODES];      // color to nodes for partition - bipartite

void graph_init() {
  memset(vis, 0, sizeof(vis));
  memset(pi, -1, sizeof(pi));
  memset(color, 0, sizeof(color));
}
