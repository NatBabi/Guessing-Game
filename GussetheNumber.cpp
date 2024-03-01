#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

class Player_A {
private:
    struct node {
        int guess;
        string input_A;
        string ans;
        node* nxt;
    };
    node* temp;
    node* top;
    int total_differences = 0;
    int num_guesses;
    const int max_guesses = 5;

public:
    Player_A() {
        top = NULL;
        total_differences = 0;
        num_guesses = 0;
    }

    void add(int x) {
        temp = new node;
        cout << "Question of Player A:(use >=) ";
        getline(cin, temp->input_A);

        int num1 = stoi(temp->input_A.substr(2));
        temp->nxt = NULL;

        if (x >= num1) {
            temp->ans = "Yes";
            cout << "Answer of the computer: " << temp->ans << "\n";
        } else {
            temp->ans = "No";
            cout << "Answer of the computer: " << temp->ans << "\n";
        }

        cout << "Guess of player A: ";
        cin >> temp->guess;
        cin.ignore();

        temp->nxt = NULL;
        if (top == NULL) {
            top = temp;
        } else {
            temp->nxt = top;
            top = temp;
        }
        num_guesses++;
        total_differences += abs(x - temp->guess);
        if (temp->guess == x)
            cout << "Right! Congratulations on your guessing performance, which is " << get_guessing_performance_A(x) << "%\n";
        else
            cout << "Wrong!\n";
    }

    void display() {
        temp = top;
        if (top == NULL) {
            cout << "Previous turn: NO\n";
        } else {
            temp = top;
            cout << "Previous turn: Question of Player A: " << temp->input_A << "\n";
            cout << setiosflags(ios::left) << setw(16) << " " << "Answer of the computer: " << temp->ans << endl;
            cout << setiosflags(ios::left) << setw(16) << " " << "Guess of player A: " << temp->guess << endl;
        }
    }

    double get_guessing_performance_A(int x) {
        double PT = 100 - ((num_guesses / static_cast<double>(max_guesses)) * 100);
        double PA = ((total_differences) / (double)(5050) * (x - 100) * x) + x; // assuming maximum number is 100
        return (PT + PA) / 2;
    }
};

class Player_B {
private:
    struct node {
        int guess;
        string input_B;
        string ans;
        node* nxt;
    };
    node* top;
    node* temp;
    int total_differences = 0;
    int num_guesses;
    const int max_guesses = 5;

public:
    Player_B() {
        top = NULL;
        total_differences = 0;
        num_guesses = 0;
    }

    void add(int x) {
        temp = new node;
        cout << "Question of Player B: ";
        getline(cin, temp->input_B);

        int num2 = stoi(temp->input_B.substr(2));
        temp->nxt = NULL;

        if (x >= num2) {
            temp->ans = "Yes";
            cout << "Answer of the computer: " << temp->ans << " \n";
        } else {
            temp->ans = "No";
            cout << "Answer of the computer: " << temp->ans << " \n";
        }

        cout << "Guess of player B: ";
        cin >> temp->guess;
        cin.ignore();

        temp->nxt = NULL;
        if (top == NULL) {
            top = temp;
        } else {
            temp->nxt = top;
            top = temp;
        }
        num_guesses++;
        total_differences += abs(x - temp->guess);
        if (temp->guess == x)
            cout << "Right! Congratulations on your guessing performance, which is " << get_guessing_performance_B(x) << "%\n";
        else
            cout << "Wrong!\n";
    }

    void display() {
        temp = top;
        if (top == NULL) {
            cout << "Previous turn: NO\n";
        } else {
            temp = top;
            cout << "Previous turn: Question of Player B: " << temp->input_B << "\n";
            cout << setiosflags(ios::left) << setw(16) << " " << "Answer of the computer: " << temp->ans << endl;
            cout << setiosflags(ios::left) << setw(16) << " " << "Guess of player B: " << temp->guess << endl;
        }
    }

    double get_guessing_performance_B(int x) {
        double PT = 100 - ((num_guesses / static_cast<double>(max_guesses)) * 100);
        double PA = ((total_differences) / (double)(9900) * (x - 100) * x) + x; // assuming maximum number is 100
        return (PT + PA) / 2;
    }
};

int main() {
    Player_A PA;
    Player_B PB;

    int trial_A = 0;
    int trial_B = 0;

    srand(time(0)); // seed random number generator with current time
    const int SIZE = 100;
    int secretNum = rand() % SIZE + 1;

    cout << "    ___________________  "<< endl;
    cout << "   |                   | " << endl;
    cout << "   | Guess Number Game | " << endl;
    cout << "   |                   | "<< endl;
    cout << "   |___________________|\n"<< endl;


    do {
        system("cls");
        cout << "      TURN" << trial_A+1  << "\n" << endl;
        PA.display();
        PA.add(secretNum);
        trial_A++;
        cout << endl;
        system("cls");
        cout << "TURN" << trial_A+1 << endl;
        PB.display();
        PB.add(secretNum);
        trial_B++;
        cout << endl;
    } while (trial_B < 3 || trial_A < 3);

    cout << setiosflags(ios::left) << setw(16) << "GAME ENDS" << endl;
    if (PA.get_guessing_performance_A(secretNum) > PB.get_guessing_performance_B(secretNum)) {
        cout << setiosflags(ios::left) << setw(16) << "Player A won with guessing performance of " << PA.get_guessing_performance_A(secretNum) << "%" << endl;
        cout << setiosflags(ios::left) << setw(16) << "Player B losses with guessing performance of " << PB.get_guessing_performance_B(secretNum) << "%" << endl;
    } else if (PA.get_guessing_performance_A(secretNum) < PB.get_guessing_performance_B(secretNum)) {
        cout << setiosflags(ios::left) << setw(16) << "Player B won with guessing performance of " << PB.get_guessing_performance_B(secretNum) << "%" << endl;
        cout << setiosflags(ios::left) << setw(16) << "Player A losses with guessing performance of " << PA.get_guessing_performance_A(secretNum) << "%" << endl;
    } else {
        cout << setiosflags(ios::left) << setw(16) << "Player A losses with guessing performance of " << PA.get_guessing_performance_A(secretNum) << "%" << endl;
        cout << setiosflags(ios::left) << setw(16) << "Player B losses with guessing performance of " << PB.get_guessing_performance_B(secretNum) << "%" << endl;
    }

    return 0;
}
