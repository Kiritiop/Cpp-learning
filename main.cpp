#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string instructions;
    cin >> instructions;

    string buffer;

    for (int i = 0; i < instructions.size(); i++)
    {
        char currentChar = instructions[i];

        if (isalpha(currentChar))
        {
            buffer += currentChar;
        }
        else if (currentChar == '+')
        {
            buffer += " tighten ";
        }
        else if (currentChar == '-')
        {
            buffer += " loosen ";
        }
        else if (isdigit(currentChar))
        {
            buffer += currentChar;
            if (i + 1 < instructions.size() && isalpha(instructions[i + 1]))
            {
                cout << buffer << endl;
                buffer = "";
            }
        }
    }
    cout << buffer << endl;

    return 0;
}