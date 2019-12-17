#pragma once

#include <vector>
#include <utility>
#include <stack>
#include <map>
#include <string>

using namespace std;

#define _OK_ 1
#define _NO_ 0

#define VI vector

static map<string, int> id;
static map<int, string> city;
static vector<string> city_list;

class Graph {
public:
	struct edge {
		int v, w, c;
		edge(int v, int w, int c) {
			this->v = v;
			this->w = w;
			this->c = c;
		}
	};

	VI <VI <edge>> G;
	VI <bool> vis;
	stack <int> Available;

	int Ins();

	void Ins_Edge(int u,int v,int w,int c);

	int Del(int u);

	int Del_Edge(int u, int v);
	
	int change(int u, int v, int w,int c);

};