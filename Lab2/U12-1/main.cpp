#include <iostream>
#include <string>

using namespace std;

string toMorse(string s);
string capitalize(string& str);

int main()
{
    string s = "TesTar å ä ö";
    cout << capitalize(s) << endl;
    cout << toMorse(capitalize(s)) << endl;
    return 0;
}

string toMorse(string s) {
    string table[29] = {
        ".-",
        "-...",
        "-.-.",
        "-..",
        ".",
        "..-.",
        "--.",
        "....",
        "..",
        ".---",
        "-.-",
        ".-..",
        "--",
        "-.",
        "---",
        ".--.",
        "--.-",
        ".-.",
        "...",
        "-",
        "..-",
        "...-",
        ".--",
        "-..-",
        "-.--",
        "--..",
        ".--.-",
        ".-.-",
        "---."
    };
    string output = "";
    for(unsigned int i = 0; i < s.size(); i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            output.append(table[s[i] - 'A']);
            output.append(" ");
        } else if(s.substr(i, 1).compare(" ") == 0) {
            output.append("  ");
        } else {
            // Needs to read 2 bytes if it's å, ä or ö
            if(s.substr(i, 2).compare("Å") == 0)
                output.append(table[26]);
            else if(s.substr(i, 2).compare("Ä") == 0)
                output.append(table[27]);
            else if(s.substr(i, 2).compare("Ö") == 0)
                output.append(table[28]);
        }
    }
    return output;
}

string capitalize(string& str) {
    string output;
    for(unsigned int i = 0; i < str.length(); i++) {
        if(str[i] >= 'a' && str[i] <= 'z')
            output += str[i] - 32;
        else {
            if(str.substr(i, 2).compare("å") == 0) {
                output.append("Å");
                i++; // read two bytes, so we need to increment i
            } else if(str.substr(i, 2).compare("ä") == 0) {
                output += "Ä";
                i++;
            } else if(str.substr(i, 2).compare("ö") == 0) {
                output += "Ö";
                i++;
            } else
                output += str[i];
        }
    }
    return output;
}
