#include <iostream>
using namespace std;

int main()
{
    string instructions;
    cin >> instructions;
    for (int i = 0; i < instructions.size(); i++)
    {
        string buffer;
        if (isalpha(instructions[i]))
        {
            buffer += instructions[i];
        }
        else if (instructions[i] == '+')
        {
            buffer += " tighten ";
        }
        else if (instructions[i] == '-')
        {
            buffer += " loosen ";
        }
        else if (isdigit(instructions[i]))
        {
            buffer += instructions[i];
            if (isalpha(instructions[i + 1]))
            {
                cout << buffer << endl;
                continue;
            }
        }
    }
    return 0;
}