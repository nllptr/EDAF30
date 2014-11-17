#include <iostream>
#include <string>

using namespace std;

string toUpperCase(string);
string toMorse(string);

int main() {
    string s = "Hello";
    //cout << toUpperCase(s) << endl;
    cout << toMorse(toUpperCase(s)) << endl;
}

string toMorse(string s) {
    string morse[29] = {
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
    string done = "";
    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            done = done + morse[(char)s[i]-'A'] + " ";
        } else if(s[i] == ' ') {
            done += "  ";
        } else {
            if(s.substr(i, 2).compare("Å") == 0) { //åäö is rep. by 2 bytes
                done = done + morse[26] + " ";
            } else if(s.substr(i, 2).compare("Ä") == 0) {
                done = done + morse[27] + " ";
            } else if(s.substr(i, 2).compare("Ö") == 0) {
                done = done + morse[28] + " ";
            }
        }
    }

    return done;
}

string toUpperCase(string lower) {
    string upper = "";
    for(int i = 0; i < lower.length(); i++) {
        if(lower[i] >= 'a' && lower[i] <= 'z') {
            upper += lower[i] - 32;
        } else {
            if(lower.substr(i, 2).compare("Å") == 0 || lower.substr(i, 2).compare("å") == 0) {  //åäö is rep. by 2 bytes
                upper += "Å";
                i++;                                                                            //adds one as åäö is rep. by 2 bytes
            } else if(lower.substr(i, 2).compare("Ä") == 0 || lower.substr(i, 2).compare("ä") == 0) {
                upper += "Ä";
                i++;
            } else if(lower.substr(i, 2).compare("Ö") == 0 || lower.substr(i, 2).compare("ö") == 0) {
                upper += "Ö";
                i++;
            } else {
                upper += lower[i];
            }
        }
    }
    return upper;
}
