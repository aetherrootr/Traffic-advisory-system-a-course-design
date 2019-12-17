#include "algorithm.h"
#include <iostream>

void DIJ::init(int s, int t, int n)
{
	while (!Q.empty()) {
		Q.pop();
	}
	dis.resize(n + 1);
	pre.resize(n + 1);
	for (int i = 0; i < dis.size(); i++) {
		dis[i] = INF;
		pre[i] = i;
	}
	dis[s] = 0;
	Q.push(node(s, 0));
}

void DIJ::Dijkstra(Graph G)
{
	while (!Q.empty()) {
		node fr = Q.top();
		Q.pop();
		int u = fr.u, d = fr.d, v, w;
		if (d != dis[u]) continue;
		for (auto vv : G.G[u]) {
			if (dis[u] + (w = vv.w) < dis[v = vv.v]) {
				dis[v] = dis[u] + w;
				pre[v] = u;
				Q.push(node(v, dis[v]));
			}
		}
	}
}

void DIJ::Dijkstra_cost(Graph G)
{
	while (!Q.empty()) {
		node fr = Q.top();
		Q.pop();
		int u = fr.u, d = fr.d, v, w;
		if (d != dis[u]) continue;
		for (auto vv : G.G[u]) {
			if (dis[u] + (w = vv.w * vv.c) < dis[v = vv.v]) {
				dis[v] = dis[u] + w;
				pre[v] = u;
				Q.push(node(v, dis[v]));
			}
		}
	}
}

void DIJ::getRoad(int s, int t, int n)
{
	road.clear();
	int now = t;
	while (now != s) {
		road.push_back(now);
		now = pre[now];
	}
}

