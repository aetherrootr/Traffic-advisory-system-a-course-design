#include "Interaction.h"

Graph G;

int darw_menu()
{
	int x = 40, y = 0;
	while (1) {
		system("cls");
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 4; i++) printf(" ");
		printf("交通咨询系统\n");
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 20; i++) printf("*");
		printf("\n");
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j <= 40; j++) {
				if (j == x && i == y) {
					printf(">");
				}
				else printf(" ");
			}
			if (i == 0) printf(" 查询路径 ");
			if (i == 1) printf(" 编辑路径 ");
			if (i == 2) printf(" 退出 ");
			for (int k = 1; k < 5; k++) printf(" ");
			printf("\n");
		}
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 20; i++) printf("*");
		printf("\n");
		char input;
		input = _getch();
		if (input == 80 && y < 2) y++;
		if (input == 72 && y > 0) y--;
		if (input == 13) break;
	}
	return y;
}

void menu()
{
	while (1) {
		int flag = darw_menu();
		if (flag == 0) {
			query_Graph();
		}
		else if (flag == 1) {
			edit_Graph();
		}
		else break;
	}
}

int darw_query_Graph()
{
	int x = 37, y = 0;
	while (1) {
		system("cls");
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 4; i++) printf(" ");
		printf("路径查询\n");
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 20; i++) printf("*");
		printf("\n");
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j <= 37; j++) {
				if (j == x && i == y) {
					printf(">");
				}
				else printf(" ");
			}
			if (i == 0) printf(" 查询距离最短路径 ");
			if (i == 1) printf(" 查询花费最少路径 ");
			if (i == 2) printf(" 退出 ");
			for (int k = 1; k < 5; k++) printf(" ");
			printf("\n");
		}
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 20; i++) printf("*");
		printf("\n");
		char input;
		input = _getch();
		if (input == 80 && y < 2) y++;
		if (input == 72 && y > 0) y--;
		if (input == 13) break;
	}
	return y;
}

void query_Graph()
{
	while (1){
		int flag = darw_query_Graph();
		if (flag == 0) {
			best_dist();
		}
		else if (flag == 1) {
			best_cost();
		}
		else break;
	}
}

void add_vertice()
{
	system("cls");
	printf("请输入要添加的城市:\n");
	string s;
	cin >> s;
	system("cls");
	if (id[s] == 0) {
		int tag = G.Ins();
		id[s] = tag;
		city[tag] = s;
		city_list.push_back(s);
	}
	else {
		cout << "非法添加," << s << "已存在" << endl;
		system("pause");
	}
}

void add_edge()
{
	int s = darw_s();
	if (s >= city_list.size()) {
		return;
	}
	int t = darw_t();
	if (t >= city_list.size()) {
		return;
	}

	s = id[city_list[s]];
	t = id[city_list[t]];

	for (auto v : G.G[s]) {
		if (v.v == t) {
			system("cls");
			printf("该边已经存在，无法加入\n");
			system("pause");
		}
	}

	system("cls");

	cout << city[s] << "-->" << city[t] << endl;

	printf("请输入距离:\n");
	int w, c;
	cin >> w;
	printf("请输入每公里的花费:\n");
	cin >> c;
	G.Ins_Edge(s, t, w, c);
}

int darw_delete_vertice()
{
	int y = 0;
	while (1) {
		system("cls");
		printf("请选择要删除的城市\n");
		for (int i = 0; i <= city_list.size(); i++) {
			if (i == y) {
				printf(">");
			}
			else printf(" ");
			if (i < city_list.size()) {
				cout << " " << city_list[i] << " ";
			}
			else printf(" 退出 ");
			for (int k = 1; k < 5; k++) printf(" ");
			printf("\n");
		}
		char input;
		input = _getch();
		if (input == 80 && y < city_list.size()) y++;
		if (input == 72 && y > 0) y--;
		if (input == 13) break;
	}
	return y;
}

void delete_vertice()
{
	int s = darw_delete_vertice();
	if (s >= city_list.size()) {
		return;
	}

	system("cls");

	int flag = G.Del(id[city_list[s]]);
	if (flag == _OK_) {
		city[id[city_list[s]]] = "";
		id[city_list[s]] = 0;
		city_list.erase(city_list.begin() + s);
		printf("删除成功\n");
	}
	else
	{
		printf("删除失败\n");
	}
	system("pause");
}

void delete_edge()
{
	int s = darw_s();
	if (s >= city_list.size()) {
		return;
	}
	int t = darw_t();
	if (t >= city_list.size()) {
		return;
	}

	s = id[city_list[s]];
	t = id[city_list[t]];

	system("cls");

	int flag=G.Del_Edge(s, t);
	if (flag == _OK_) {
		printf("删除成功\n");
	}
	else {
		printf("删除失败,有可能是边不存在\n");
	}
	system("pause");
}

void chang_edge()
{
	int s = darw_s();
	if (s >= city_list.size()) {
		return;
	}
	int t = darw_t();
	if (t >= city_list.size()) {
		return;
	}

	s = id[city_list[s]];
	t = id[city_list[t]];

	system("cls");

	cout << city[s] << "-->" << city[t] << endl;

	printf("请输入距离:\n");
	int w, c;
	cin >> w;
	printf("请输入每公里的花费:\n");
	cin >> c;
	system("cls");
	int flag = G.change(s, t, w, c);
	if (flag == _OK_) {
		printf("修改成功\n"); 
	}
	else {
		printf("修改失败,有可能是边不存在\n");
	}
	system("pause");
}

int darw_rename()
{
	int y = 0;
	while (1) {
		system("cls");
		printf("请选择要改名的城市\n");
		for (int i = 0; i <= city_list.size(); i++) {
			if (i == y) {
				printf(">");
			}
			else printf(" ");
			if (i < city_list.size()) {
				cout << " " << city_list[i] << " ";
			}
			else printf(" 退出 ");
			for (int k = 1; k < 5; k++) printf(" ");
			printf("\n");
		}
		char input;
		input = _getch();
		if (input == 80 && y < city_list.size()) y++;
		if (input == 72 && y > 0) y--;
		if (input == 13) break;
	}
	return y;
}

void rename()
{
	int s = darw_rename();
	if (s >= city_list.size()) {
		return;
	}

	system("cls");

	int tmp = s;
	s = id[city_list[s]];
	city_list.erase(city_list.begin() + tmp);

	while (1) {
		system("cls");
		printf("请输入城市的新名字:\n");
		string ss;
		cin >> ss;

		if (id[ss] == 0) {
			id[ss] = s;
			id[city[s]] = 0;
			city[s] = ss;
			city_list.push_back(ss);
			system("cls");
			printf("修改成功\n");
			system("pause");
			break;
		}
		else {
			cout << "非法修改," << ss << "已存在" << endl;
			system("pause");
		}
	}
}

void out_file()
{
	ofstream file("out.map");
	if (file.is_open()) {
		for (int i = 0; i < G.G.size(); i++) {
			if (G.vis[i] == 0) continue;
			for (int j = 0; j < G.G[i].size(); j++) {
				if (G.G[i][j].v < i) continue;
				file << city[i] << " " << city[G.G[i][j].v] << " ";
				file << G.G[i][j].w << " " << G.G[i][j].c << endl;
			}
		}
		file.close();
		system("cls");
		printf("导出成功\n");
		system("pause");
	}
	else {
		system("cls");
		printf("out.map文件不存在，导入失败\n");
		system("pause");
	}
	
}

void in_file()
{
	string su, sv;
	int w, c;
	ifstream file("in.map");
	if (file.is_open()) {
		while (file >> su >> sv >> w >> c) {
			//cout << su << " " << sv << " " << w << " " << c << endl;
			//cout << id[su] << " " << id[sv] << endl;
			if (id[su] == 0) {
				id[su]=G.Ins();
				city[id[su]] = su;
				city_list.push_back(su);
			}

			if (id[sv] == 0) {
				id[sv] = G.Ins();
				city[id[sv]] = sv;
				city_list.push_back(sv);
			}

			G.Ins_Edge(id[su], id[sv], w, c);
		}
		file.close();
		system("cls");
		printf("导入成功\n");
		system("pause");
	}
	else {
		system("cls");
		printf("in.map文件不存在，导入失败\n");
		system("pause");
	}
}

int darw_edit_Graph()
{
	int x = 37, y = 0;
	while (1) {
		system("cls");
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 4; i++) printf(" ");
		printf("路径编辑\n");
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 20; i++) printf("*");
		printf("\n");
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j <= 37; j++) {
				if (j == x && i == y) {
					printf(">");
				}
				else printf(" ");
			}
			if (i == 0) printf(" 加入新地点 ");
			if (i == 1) printf(" 加入新路径 ");
			if (i == 2) printf(" 删除一个地点 ");
			if (i == 3) printf(" 删除一条路径 ");
			if (i == 4) printf(" 修改一条路径 ");
			if (i == 5) printf(" 修改城市名称 ");
			if (i == 6) printf(" 从文件中导入地图 ");
			if (i == 7) printf(" 导出地图到文件 ");
			if (i == 8) printf(" 退出 ");
			for (int k = 1; k < 5; k++) printf(" ");
			printf("\n");
		}
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 20; i++) printf("*");
		printf("\n");
		char input;
		input = _getch();
		if (input == 80 && y < 8) y++;
		if (input == 72 && y > 0) y--;
		if (input == 13) break;
	}
	return y;
}

void edit_Graph()
{
	while (1) {
		int flag = darw_edit_Graph();
		if (flag == 0) {
			add_vertice();
		}
		else if (flag == 1) {
			add_edge();
		}
		else if (flag == 2) {
			delete_vertice();
		}
		else if (flag == 3) {
			delete_edge();
		}
		else if (flag == 4) {
			chang_edge();
		}
		else if (flag == 5) {
			rename();
		}
		else if (flag == 6) {
			in_file();
		}
		else if (flag == 7) {
			out_file();
		}
		else break;
	}
}

int darw_s() {
	int y = 0;
	while (1) {
		system("cls");
		printf("请选择起点\n");
		for (int i = 0; i <= city_list.size(); i++) {
			if (i == y) {
				printf(">");
			}
			else printf(" ");
			if (i < city_list.size()) {
				cout << " " << city_list[i] << " ";
			}
			else printf(" 退出 ");
			for (int k = 1; k < 5; k++) printf(" ");
			printf("\n");
		}
		char input;
		input = _getch();
		if (input == 80 && y < city_list.size()) y++;
		if (input == 72 && y > 0) y--;
		if (input == 13) break;
	}
	return y;
}

int darw_t() {
	int y = 0;
	while (1) {
		system("cls");
		printf("请选择终点\n");
		for (int i = 0; i <= city_list.size(); i++) {
			if (i == y) {
				printf(">");
			}
			else printf(" ");
			if (i < city_list.size()) {
				cout << " " << city_list[i] << " ";
			}
			else printf(" 退出 ");
			for (int k = 1; k < 5; k++) printf(" ");
			printf("\n");
		}
		char input;
		input = _getch();
		if (input == 80 && y < city_list.size()) y++;
		if (input == 72 && y > 0) y--;
		if (input == 13) break;
	}
	return y;
}

void best_dist()
{
	DIJ solve;
	int s = darw_s();
	if (s >= city_list.size()) {
		return;
	}
	int t = darw_t();
	if (t >= city_list.size()) {
		return;
	}

	s = id[city_list[s]];
	t = id[city_list[t]];
	
	solve.init(s, t, city_list.size());
	solve.Dijkstra(G);
	solve.getRoad(s, t, city_list.size());

	system("cls");

	printf("最短路径为:%d\n", solve.dis[t]);

	reverse(solve.road.begin(), solve.road.end());
	
	cout<< city[s];
	for (int i = 0; i < solve.road.size(); i++) {
		cout << "-->" << city[solve.road[i]];
	}cout << endl;
	
	system("pause");
}

void best_cost()
{
	DIJ solve;
	int s = darw_s();
	if (s >= city_list.size()) {
		return;
	}
	int t = darw_t();
	if (t >= city_list.size()) {
		return;
	}

	s = id[city_list[s]];
	t = id[city_list[t]];

	solve.init(s, t, city_list.size());
	solve.Dijkstra_cost(G);
	solve.getRoad(s, t, city_list.size());

	system("cls");

	printf("最小花费路径为:%d\n", solve.dis[t]);

	reverse(solve.road.begin(), solve.road.end());

	cout << city[s];
	for (int i = 0; i < solve.road.size(); i++) {
		cout << "-->" << city[solve.road[i]];
	}cout << endl;

	system("pause");
}



