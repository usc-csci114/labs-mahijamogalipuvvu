#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    vector<int> input;
    stack<int> stack;
    int num;

    cout << "enter integers! to stop, use the command Ctrl-D." << endl;

    while (cin >> num) {
        input.push_back(num);
    }

    cout << "in order:" << endl;
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << " ";
        stack.push(input[i]); 
    }
    cout << endl;

    cout << "in reverse:" << endl;
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;

    return 0;
}
