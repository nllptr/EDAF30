#include <iostream>

using namespace std;

int main()
{
    cout << "Enter roman number: " << endl;
    string input;
    getline(cin, input);
    int numbers[input.length()];
    for(int i = 0; i < input.length(); i++) {
        switch(input[i]) {
        case 'I':
            numbers[i] = 1;
            break;
        case 'V':
            numbers[i] = 5;
            break;
        case 'X':
            numbers[i] = 10;
            break;
        case 'L':
            numbers[i] = 50;
            break;
        case 'C':
            numbers[i] = 100;
            break;
        case 'D':
            numbers[i] = 500;
            break;
        case 'M':
            numbers[i] = 1000;
            break;
        default:
            cout << "Invalid input." << endl;
            return 1;
            break;
        }
    }

    int output = 0;
    for(int i = 0; i < input.length(); i++) {
        // If the same letter occurs more than 3 times in a row
        if(i < input.length() - 3 && numbers[i] == numbers[i + 1] && numbers[i] == numbers[i + 2] && numbers[i] == numbers[i + 3]) {
            cout << "Invalid number." << endl;
            return 1;
        // If a comes before b and a is greater than b: add
        } else if(numbers[i] >= numbers[i + 1] || i == (input.length() - 1)) {
            output += numbers[i];
        // If a comes before b and a is less than b
        } else if(numbers[i] < numbers[i + 1]) {
            // If a comes before b which comes before c, and a is less than equal to c
            if(i < input.length() - 2 && numbers[i] <= numbers[i + 2]) {
                cout << "Invalid number." << endl;
                return 1;
            // otherwise: subtract
            } else {
                output -= numbers[i];
            }
        }
    }

    cout << output << endl;
    return 0;
}

