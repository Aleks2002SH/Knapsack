// Knapsack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "for_file_output.h"


int main()
{
    vector<string> files;
    auto cur_p = fs::current_path();
    fs::path dir{ "data" };
    fs::path pathtodata = cur_p / dir;
    files = filesindir(pathtodata);
    ofstream out("result.txt");
    for (int file = 0; file < files.size(); file++) {
        ifstream in(files[file]);
        int K, n, val, wt;
        //creation of given list of items
        vector<item> items; 
        in >> n >> K;
        for (int i = 0; i < n; i++) {
            in >> val >> wt;
            item a = { val,wt };
            items.push_back(a);
        }
        vector<int> used(n, 0);
        vector<item> sorted_items = sort_vector(items);
        int total_profit = knapsack(sorted_items, used, n, K);
        cout << total_profit << endl;
        /*vector<int> initial_order = initial_element_order(used, n, items, sorted_items);// uncommenting will reveal the used items for filling knapsack
        show1d_matrix<int>(initial_order);*/
        fill_result(total_profit, out, files[file]);
        in.close();
    }
    out.close();
    
    
   
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
