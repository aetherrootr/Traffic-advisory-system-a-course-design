#pragma once

#include <queue>
#include <vector>
#include "Graph.h"

using namespace std;

const int INF = 0x3f3f3f3f;

class DIJ {
public:
	struct node {
		int u, d;
		bool operator <(const node& rhs) const {
			return d > rhs.d;
		}
		node(int u, int d) {
			this->u = u;
			this->d = d;
		}
	};

	priority_queue <node> Q;
	vector <int> dis, pre;
	vector <int> road;

	void init(int s, int t, int n);

	void Dijkstra(Graph G);

	void Dijkstra_cost(Graph G);

	void getRoad(int s, int t, int n);
};