#include <iostream>
#include <vector>
#include <queue>
#include<iterator>
#include<algorithm>

using namespace std;

struct item {
	int price;
	double wt;
	bool operator==(const item& other) {
		return (other.price == price) && (other.wt == wt);
	}
};
struct Node {
	int lvl, upper_bound;
	double wt,cost;
	Node() {
		this->lvl = 0;
		this->upper_bound = 0;
		this->wt = 0;
		this->cost = 0;
	}
	Node(int lvl, int upper_bound, double cost,double wt)
	{
		this->lvl = lvl;
		this->upper_bound = upper_bound;
		this->wt = wt;
		this->cost = cost;
	}
};
bool comparison(item i1, item i2) {
	return ((double)i1.price / i1.wt) < ((double)i2.price / i2.wt);
}
double calc_upper_bound(vector<item> &items,Node &v,double &K,int &n) {
	try {
		int lvl = v.lvl;
		double cur_wt = v.wt;
		double cur_cost = v.cost;
		int cur_up_bound = v.upper_bound;
		while (lvl < n) {
			if (cur_wt + items[lvl].wt < K) {
				cur_cost += items[lvl].price;
				cur_wt += items[lvl].wt;
				lvl++;
			}
			else {
				break;
			}
		}
		if (lvl < n) cur_cost += (K - cur_wt) * items[lvl].price / items[lvl].wt;
		return cur_cost;
	}
	catch(out_of_range& e) {
		cout << "upper_bound func" << endl;
	}
}
void sorted_vector(vector<item>& vec) {
	sort(vec.begin(), vec.end(), comparison);
}

int knapsack(vector<item> &items,vector<int> &used, double& K,int &n) {
	sorted_vector(items);
	queue<Node> Q;
	Node parent(-1, 0, 0, 0);
	Q.push(parent);
	int max_val = 0;
	while (!Q.empty()) {
		parent = Q.front();
		Q.pop();
		if (parent.lvl >= n - 1) continue;
		try {
			Node son(parent.lvl + 1, parent.upper_bound + items[parent.lvl + 1].price, parent.cost, parent.wt + items[parent.lvl + 1].wt);
			son.cost = calc_upper_bound(items, son, K, n);
			if (son.upper_bound > max_val && son.wt <= K) max_val = son.upper_bound;
			if (son.cost > max_val) {
				Q.push(son);
			}
			son.upper_bound = parent.upper_bound;
			son.wt = parent.wt;
			son.cost = calc_upper_bound(items, son, K, n);
			if (son.cost > max_val) {
				Q.push(son);
			}
		}
		catch (out_of_range& e) {
			cout << "knapsack_func" << endl;
		}
	}
	return max_val;
}


template<class T>
void show_1dmatrix(vector<T> &V) {
	int N = V.size();
	for (int i = 0; i < N; i++) {
		cout << V[i] << " ";
	}
	cout << endl;
}

vector<int> initial_elemets_order(vector<int> used, int n, vector<item>& items) {
	vector<int> used_correct_order(n);
	try {
		for (int i = 0; i < n; i++) {
			if (used[i] == 1) {
				item elem = items[i];
				vector<item>::iterator it = find(items.begin(), items.end(), elem);
				int dist = distance(items.begin(), it);
				used_correct_order[dist] = 1;
			}
		}
	}
	catch (out_of_range& e) {
		cout<<"constructing elems order"<<endl;
	}
	return used_correct_order;
}