#ifndef GRAPH_COMMON_H
#define GRAPH_COMMON_H

#include <vector>

using namespace std;

#define NODES 1000
#define DFS 0
#define BFS 1

vector <int> adj[1000];
int vis[NODES], pi[NODES];

void traverse(int, int);
void bfs(int);
void print_path(int, int);

#endif
