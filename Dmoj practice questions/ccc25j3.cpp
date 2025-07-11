#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string code;
        string newcode;
        getline(cin, code);
        int num = 0;
        for (int j = 0; j < code.length(); j++){
            if (isupper(code[j])){
                newcode += code[j];
            } else if (isdigit(code[j]) && j+1 < code.length() && !isdigit(code[j+1])){
                num += code[j];
            } else if (isdigit(code[j]) && j+1 < code.length() && isdigit(code[j+1])) {
                num += code[j]*10 + code[j+1];
            } else if (isdigit(code[j])) {
                num += code[j];
            }

        }
        cout << newcode << to_string(num) << endl;
    }
}