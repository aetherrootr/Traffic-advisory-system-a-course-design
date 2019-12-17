#pragma once
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <algorithm>
#include <fstream>
#include "algorithm.h"
#include "Graph.h"

using namespace std;

int darw_s();
int darw_t();
void best_dist();
void best_cost();

int darw_query_Graph();
void query_Graph();

void add_vertice();
void add_edge();
int darw_delete_vertice();
void delete_vertice();
void delete_edge();
void chang_edge();
int darw_rename();
void rename();
void out_file();
void in_file();

int darw_edit_Graph();
void edit_Graph();

int darw_menu();
void menu();