#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <cstdlib>  
#include <ctime>
#include <chrono> 

using namespace std;

void fillrand(vector<int>& v);

void fillrand(vector<int>& v) {
    for (int num : v) 
        num = rand() % 10000;  
}


int main() {
    srand(time(0)); 

    int originalSize = 100;  


    for (int i = 1; i <= 20; ++i) {                 //MODIFICATION
        int currentSize = originalSize * pow(2, i); //MODIFICATION

        vector<int> v(currentSize);
        fillrand(v);
            
        priority_queue<int> pq(v.begin(), v.end());
        //list<int> l;                              //MODIFICATION

        auto start = chrono::steady_clock::now();   //MODIFICATION


        while (!pq.empty()) {
            //l.push_front(pq.top());               //MODIFICATION
            pq.pop();
        }

        auto end = chrono::steady_clock::now();
        const chrono::duration<double> diff = end - start;
        
        cout << "sorting vector of size " << v.size() << ": " << diff.count() << endl;

        // for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        //     cout << *it << " ";
        // }

        // cout << endl;



    }
 

}


