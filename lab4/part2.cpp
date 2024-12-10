#include <iostream>
#include <chrono>
#include <list>

using namespace std;

template <typename T>
T at(list<T>& ll, size_t idx)
{
	auto it = ll.begin();
	
	for(int i = 0; i < idx; ++i)
		++it; 
	
	return *it; 
}

int main(){
	size_t size = 1000;
	
	for(int x = 0; x < 20; x++)
	{
		list<int> my_list;
		//1. Resize my_list to have size*x items
		my_list.resize(size*x); 
		//2. log the start time (see part 1)
		const auto start = chrono::steady_clock::now();
		//3. Use a for loop to iterate through all indexs of my_list by calling 
		for (int i = 0; i < my_list.size();i++) 
            at<int>(my_list, i); 
		//4. log the end time and calculate the diff
		const auto end = chrono::steady_clock::now();
		const chrono::duration<double> diff = end - start;

		cout << "Iterating linked list for size " << my_list.size() << ": ";
		cout << diff.count() << endl;
	}
	return 0;
}
