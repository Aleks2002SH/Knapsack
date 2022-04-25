#include"header.h"

int main()
{
   int K, n,val;
    double wt;
    cin >> n >> K;
    vector<item> items;
    for (int i = 0; i < n; i++) {
        cin >> val >> wt;
        item a = { val,wt };
        items.push_back(a);
    }
    vector<int> used(n);
    cout << knapsack(items,K, n,used) << endl;
    vector<int> used_initial_order = initial_elemets_order(used, n,items);
    show_1dmatrix(used_initial_order);
}
