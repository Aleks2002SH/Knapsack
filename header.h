#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct item {
	int val;
	double wt;
};
struct Node {
	int lvl, bord,sum_val;
	double wt;
	Node(int lvl, int bord,int sum_val,double wt)
	{
		this->lvl = lvl;
		this->bord = bord;
		this->sum_val = sum_val;
		this->wt = wt;
	}
	Node() {
		this->lvl = 0;
		this->bord = 0;
		this->sum_val = 0;
		this->wt = 0;
	}
};
int bord(vector<item> &items,int& K,int& n,Node &v) {
	int bord;
	if (v.wt >= K) return 0;
	int son = v.lvl + 1;
	double current_weight = v.wt;
	int current_sum_val = v.sum_val;
	while ((current_weight+ items[son].wt <= K) && (son < n-1)) {
		current_weight += items[son].wt;
		current_sum_val += items[son].val;
		son += 1;
	}
	if (son < n) {
		bord = (K-current_weight)*items[son].val/items[son].wt;
	}
	return bord;
}
bool comparison(item i1, item i2) {
	return ((double)i1.val / i1.wt) < ((double)i2.val / i2.wt);
}
double knapsack(vector<item> items,int &K,int &n,vector<int> &used) {
	sort(items.begin(), items.end(), comparison);
	int sum_value = 0;
	queue <Node> Q;
	Node parent(-1,0,0,0);
	Q.push(parent);
	while (!Q.empty()) {
		parent = Q.front();
		Q.pop();
		if (parent.lvl == n - 1) continue;
		Node son;
		son.lvl = parent.lvl + 1;
		son.wt = parent.wt + items[son.lvl].wt;
		son.sum_val = parent.sum_val + items[son.lvl].val;
		if (son.sum_val > sum_value && son.wt <= K) {
			sum_value = son.sum_val;
			used[son.lvl] = 1;
		}
		son.bord = bord(items, K, n, son);
		if (son.bord > sum_value) {
			Q.push(son);
		}
		son.lvl = parent.lvl + 1;
		son.wt = parent.wt;
		son.bord = bord(items, K, n, son);
		if (son.bord > sum_value) {
			Q.push(son);
		}
	}
	return sum_value;
}

