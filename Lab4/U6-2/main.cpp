#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout << "Ange filnamn för input: ";
    char input[80];
    cin >> input;
    ifstream infile(input, ifstream::in);
    if(!infile.is_open()) {
        cout << "Filen " << input << " kunde inte öppnas." << endl;
        infile.close();
        return 1;
    }

    cout << "Ange filnamn för output: ";
    char output[80];
    cin >> output;
    ofstream outfile(output, ios::trunc);
    if(!outfile.is_open()) {
        cout << "Filen " << output << " kunde inte öppnas." << endl;
        infile.close();
        outfile.close();
        return 1;
    }

    char line[80];
    while(infile.getline(line, 80)) {
        string str(line);
        for(unsigned int i = 0; i < str.length(); i++) {
            if(str.at(i) == ' ') str.at(i) = '.';
        }
        str.append("@gronkoping.se");
        outfile << str << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
