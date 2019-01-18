#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	if (argc != 3)
	{
		cerr << "Error: Number of Inputs is Incorrect. Exiting" << endl;
		exit(1);
	}
	char const * in_filename = argv[1];
	char const * out_filename = argv[2];
	string line;
	cout << in_filename << "\n" << out_filename << endl;
	ifstream in_file;
	in_file.open(in_filename);
	ofstream out_file;
	out_file.open(out_filename);
	int num = 0;
	int count = 0;
	int max_digit = 0;
	in_file >>max_digit;
	int add_line = 0;
	in_file >> add_line;
	int current_line_len = 1;
	cout << max_digit;
	cout << add_line;
	out_file << "| ";
	while (in_file >> num) {
		int add_space_num = 0;
		int digit = 0;
		int num_copy = num;
		if (num_copy == 0) {
			digit = 1;
		}
		else {
			while (num_copy) {
				digit++;
				num_copy /= 10;
			}
		}
		add_space_num = max_digit - digit;
		cout << digit << " ";
		if (count == current_line_len - 1) {
			out_file << num;
			while (add_space_num--) {
				out_file << " ";
			}
			out_file << " |" << endl;
			count = 0;
			current_line_len += add_line;
		}
		else if (count == 0) {
			out_file << "| ";
			out_file << num;
			while (add_space_num--) {
				out_file << " ";
			}
			out_file << " | ";
			count += 1;
		}
		else {
			count += 1;
			out_file << num;
			while (add_space_num--) {
				out_file << " ";
			}
			out_file << " | ";
		}
	}
	in_file.close();
	out_file.close();
	return 0;
}