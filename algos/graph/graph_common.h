#ifndef GRAPH_COMMON_H
#define GRAPH_COMMON_H

#include <vector>

using namespace std;

#define DEBUG 0
#define NODES 1000
#define DFS 0
#define BFS 1

extern vector <int> adj[1000]; // adj list
extern int vis[NODES];         // visited array
extern int pi[NODES];          // parent array
extern int color[NODES];       // color to nodes for partition - bipartite
extern int depth[NODES];

void traverse(int, int);
void bfs(int);
void print_path(int, int);
void check_bipartite(int);
bool bipartite(int);
void graph_init();
void diameter(int);
pair<int, int> bfs_get_depth(int);

#endif
