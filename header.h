#include <iostream>
#include <vector>
#include <queue>
#include<iterator>
#include<algorithm>
#include<string>

using namespace std;

struct item
{
    int val, wt;
    bool operator==(const item& other) {
        return(other.val == val) && (other.wt == wt);
    }
};
bool comparison(item i1, item i2) {
    return ((double)i1.val / i1.wt) < ((double)i2.val / i2.wt);
}

vector<item> sort_vector(vector<item> vec) {
    sort(vec.begin(), vec.end(), comparison);
    return vec;
}
vector<int> initial_element_order(vector<int>& used, int& n, vector<item>& items, vector<item>& sorted_items) {
    vector<int> used_correct_order(n);
    for (int i = 0; i < n; i++) {
        if (used[i] == 1) {
            item elem = sorted_items[i];
            vector<item>::iterator it = find(items.begin(), items.end(), elem);
            int dist = distance(items.begin(), it);
            used_correct_order[dist] = 1;
        }
    }
    return used_correct_order;
}
//dynamic programming approach
int knapsack(vector<item>& items, vector<int>& used, int& n, int& K) {
    vector<vector<int>> solution(n+1);
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < K + 1; j++) {
            solution[i].push_back(0);
        }
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < K + 1; j++) {
            if (j - items[i - 1].wt >= 0) {
                solution[i][j] = max(solution[i - 1][j], solution[i - 1][j - items[i - 1].wt] + items[i - 1].val);
            }
            else {
                solution[i][j] = solution[i - 1][j];
            }
        }
    }
    //getting array of used items
    /*used[n - 1] = 1; 
    int remain_prof = solution[n][K] - items[n - 1].val;
    for (int i = n - 2; i >= 0; i--) {
        if (find(solution[i].begin(), solution[i].end(), remain_prof) == solution[i].end()) {
            used[i] = 1;
            remain_prof -= items[i].val;
            if (remain_prof == 0) break;
        }
    }*/
    return solution[n][K];
}
template<class T>
void show1d_matrix(vector<T>& V) {
    int N = V.size();
    for (int i = 0; i < N; i++) {
        cout << V[i] << " ";
    }
    cout << endl;
}
// taking items until knapsack
int knapsack_for_bad_alloc_tests(vector<item>& items, vector<int>& used, int& n, int& K) {
    int max_prof = 0;
    int sum_wt = 0; 
    int iter = 0;
    while (sum_wt <= K && iter < n) {
        sum_wt += items[iter].wt;
        max_prof += items[iter].val;
        used[iter] = 1;
        iter++;
    }
    return max_prof;
}