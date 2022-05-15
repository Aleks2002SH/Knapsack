#include "Knapsackheader.h"
#include<filesystem>
#include<fstream>
namespace  fs = std::filesystem;
using namespace std;

vector<string> filesindir(const fs::path& dir) {
	vector<string> files;
	for (auto& p : fs::recursive_directory_iterator(dir)) {
		if (fs::is_regular_file(p)) {
			files.push_back(p.path().string());
		}
	}
	return files;
}
void fill_result(int& wt, ofstream& out,string& file_name) {
	out << file_name << " ";
	out << wt << '\n';
}