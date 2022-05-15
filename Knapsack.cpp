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
        double K;
        int n, val;
        double wt;
        in >> n >> K;
        vector<item> items;
        for (int i = 0; i < n; i++) {
            in >> val >> wt;
            item a = { val,wt };
            items.push_back(a);
        }
        vector<int> used(n);
        int max_prof = knapsack(items, used, K, n);
        cout << max_prof << endl;
        fill_result(max_prof, out,files[file]);
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
