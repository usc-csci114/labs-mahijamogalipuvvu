#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool match(char open, char close) {
    if((open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']') || (open == '<' && close == '>'))
           return true;

    return false;
}

int main() {
    string input;
    stack<char> stack;

    cout << "enter a string with parentheses and brackets ((), {}, [], <>): ";
    getline(cin, input);

    for (int i = 0; i < input.length(); i++) {
        char temp = input[i];

        if (temp == '(' || temp == '{' || temp == '[' || temp == '<') {
            stack.push(temp);
        } else if (temp == ')' || temp == '}' || temp == ']' || temp == '>') {
            char top = stack.top();
            if (!match(top, temp)) {
                cout << "Error. Found " << temp << " at position " << i
                     << ", expecting " << top << "." << endl;
                return 1;
            }
            stack.pop();

            if(stack.empty()) {
                cout << "Error. Found " << temp << " at position " << i
                     << ", expecting any open." << endl;
                return 1;
            }

        } else if (temp == ' ' || temp == '\t') {
            continue;
       } 
    }

    if (!stack.empty()) {
        cout << "Error. Unmatched open parentheses/brackets." << endl;
        return 1;
    }

    cout << "The sequence is correct." << endl;
    return 0;
}
