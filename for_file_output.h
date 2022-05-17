#include "header.h"
#include<filesystem>
#include<fstream>
namespace  fs = std::filesystem;


vector<string> filesindir(const fs::path& dir) {
	vector<string> files;
	for (auto& p : fs::recursive_directory_iterator(dir)) {
		if (fs::is_regular_file(p)) {
			files.push_back(p.path().string());
		}
	}
	return files;
}
void fill_result(int &knapsack_value, ofstream& out, string& file_name) {
	out << file_name << " ";
	out << knapsack_value << '\n';
	/*for (int i = 0; i < used_items.size(); i++) {
		out << used_items[i] << " ";
	}
	out << '\n';*/
}