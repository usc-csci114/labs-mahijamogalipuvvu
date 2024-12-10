#include <utility>
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <random>
#include "hashtable.h"
#include <chrono>


using namespace std;

int main(int argc, char* argv[]) {
    default_random_engine generator(42); 
    uniform_int_distribution<int> distribution(1, 1000);


    for (int n = 100; n <= 100000; n = n * 1.5) {
        HashTable<int, int> t;

        auto start = chrono::steady_clock::now();

        for (int i = 0; i < n; ++i) {
            int randomValue = distribution(generator);
            t.insert(i, randomValue); 
        }

        auto end = chrono::steady_clock::now();
        chrono::duration<double> difference = end - start;

        cout << n << "\t" << difference.count() << endl;
    }

    return 0;
}