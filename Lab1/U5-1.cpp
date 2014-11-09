#include <iostream>
#include <string>

// Could get better results by using the <random> library,
// since it probably produces a better distribution of results.

using namespace std;

string translate(int i);
string resolve(int computer, int player);
void usage();

int main(int argc, char* argv[]) {
    int computer, player;
    srand(time(0));

    if(argc == 1) {
        cout << "Let's play rock, paper, scissors!" << endl;
        while(true) {
            computer = (rand() % 3) + 1;
            cout << "1 = rock, 2 = paper, 3 = scissors: ";
            cin >> player;
            if(cin.eof()) break;
            if(player < 1 || player > 3) {
                cout << "Invalid user input. Make sure you enter 1, 2 or 3." << endl;
                return 1;
            } else {    
                resolve(computer, player);
            }
        }
    } else if(argc == 2) {
        string arg = argv[1];
        if(arg == "-d" || arg == "--distribution") {
            long distribution[3] {0, 0, 0};
            for(long i = 0; i < 10000; i++) {
                distribution[rand() % 3]++;
            }
            cout << "Out of 10,000 randomizations;" << endl;
            cout << distribution[0] << " were rocks." << endl;
            cout << distribution[1] << " were papers." << endl;
            cout << distribution[2] << " were scissors" << endl;
        } else {
            usage();
            return 1;
        }
    } else {
        cout << "Unknown argument: " << argv[1] << endl;
        usage();
        return 1;
    }
    
    cout << endl;
    return 0;
}

string translate(int i) {
    switch(i) {
        case 1:
            return "rock";
        case 2:
            return "paper";
        case 3:
            return "scissors";
        default:
            return "undefined";
    }
}

string resolve(int computer, int player) {
    cout << "Computer chose " << translate(computer) << endl;
    cout << "You chose " << translate(player) << endl;
    if(computer == player) cout << "It's a tie." << endl;
    else if(computer == 1) {
        if(player == 2)
            cout << "You win." << endl;
        else cout << "Computer wins." << endl;
    } else if(computer == 2) {
        if(player == 3)
            cout << "You win." << endl;
        else cout << "Computer wins." << endl;
    } else if(computer == 3) {
        if(player == 1)
            cout << "You win." << endl;
        else cout << "Computer wins." << endl;
    }
}

void usage() {
    cout << "Usage: Invocation without arguments starts the game. Ivocation with -d or --distribution demonstrates the randomization." << endl;
}
