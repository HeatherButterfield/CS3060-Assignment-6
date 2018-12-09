#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

void clook(int blockList[], int count)
{

};

int main(int argc, char* argv[])
{
	ifstream fn(argv[1]); //open the file
	//ifstream fn("C:/Users/Me/Documents/CS 3060/Assignment6/Debug/block-list.txt"); //open the file
	string line;
	int block_list[100];
	int count = 0;
	if (fn.is_open() && fn.good())
	{
		while (getline(fn, line))
		{
			string b_list;
			stringstream ss(line);
			while (ss >> b_list)
			{
				block_list[count] = stoi(b_list);
				count++;
			}
		}
	}
	vector<int> b_list_sort(block_list, block_list + count);
	sort(b_list_sort.begin(), b_list_sort.end());
	int i = 0;
	int disk_count = 0;
	int k = 0;
	int block_list_sorted[100];
	for (std::vector<int>::iterator it = b_list_sort.begin(); it != b_list_sort.end(); ++it)
	{
		block_list_sorted[k] = *it;
		k++;
	}
	while (block_list_sorted[i] < 50)
	{
		i++;
	}
	for (int j = i; j > 0; j--)
	{
		if(block_list_sorted[j - 1] != NULL)
		{
			disk_count += block_list_sorted[j] - block_list_sorted[j - 1];
			cout << disk_count << endl;
		}
	}
	for (int j = count-1; j > i; j--)
	{
		if(block_list_sorted[j - 1] != NULL)
		{
			disk_count += block_list_sorted[j] - block_list_sorted[j - 1];
			cout << disk_count << endl;
		}
	}
	cout << "C-LOOK Total Seek: " << disk_count << "\n";
	//cout << endl << "press the [Enter] key to exit" << endl;
	return 0;
}
