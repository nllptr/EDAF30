#include <iostream>

using namespace std;

string generate_key();
void capitalize(string &str);
string encrypt(string str, string key);

int main()
{
    cout << "Generating encryption key..." << endl;
    string key = generate_key();
    cout << "Key generated: " << key << endl;
    string cleartext;
    getline(cin, cleartext);
    if(cleartext.length() > 80) {
        cout << "Input too long (max 80 charaters)" << endl;
        return 1;
    }
    capitalize(cleartext);
    cout << encrypt(cleartext, key) << endl;
    return 0;
}

string generate_key() {
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string random;
    srand(time(0));
    for(int i = alpha.length(); i > 0; i--) {
        int next = rand() % i;
        random += alpha[next];
        alpha.erase(alpha.begin() + next);
    }
    return random;
}

void capitalize(string& str) {
    for(int i = 0; i < str.length(); i++)
        if(str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;
}

string encrypt(string str, string key) {
    string output;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') output += key[str[i] - 'A'];
        else output += str[i];
    }
    return output;
}
