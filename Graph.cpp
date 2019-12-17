#include "Graph.h"
#include <queue>
using namespace std;

int Graph::Ins() {
	if (G.size() == 0) {
		VI <edge> tmp;
		G.push_back(tmp);
		vis.push_back(0);
	}
	if (!Available.empty()) {
		int res=Available.top();
		Available.pop();
		vis[res] = 1;
		return res;
	}
	else {
		VI <edge> tmp;
		G.push_back(tmp);
		vis.push_back(1);
		return G.size() - 1;
	}
}

void Graph::Ins_Edge(int u, int v, int w,int c)
{
	Graph::G[u].push_back(edge(v, w, c));
	Graph::G[v].push_back(edge(u, w, c));
}

int Graph::Del(int u)
{
	queue <int> q;
	if (u <= vis.size() - 1 && vis[u] == 1) {
		for (auto v : G[u]) {
			q.push(v.v);
		}
		while (!q.empty()) {
			for (int i = 0; i < G[q.front()].size(); i++){
				if (G[q.front()][i].v == u){
					G[q.front()].erase(G[q.front()].begin() + i);
				}
			}
			q.pop();
		}

		G[u].clear();

		vis[u] = 0;
		
		Available.push(u);

		return _OK_;
	}
	else return _NO_;
}

int Graph::Del_Edge(int u, int v)
{
	bool flag = 0;
	for (int i = 0; i < G[u].size(); i++) {
		if (G[u][i].v == v) {
			G[u].erase(G[u].begin() + i);
			flag = 1;
		}
	}

	if (flag) {
		for (int i = 0; i < G[v].size(); i++) {
			if (G[v][i].v == u) {
				G[v].erase(G[v].begin() + i);
			}
		}
		return _OK_;
	}
	else return _NO_;
}

int Graph::change(int u, int v, int w,int c)
{
	if (Del_Edge(u, v) == _OK_) {
		Ins_Edge(u, v, w, c);
		return _OK_;
	}
	else return _NO_;
}