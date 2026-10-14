#include<iostream>
using namespace std;
int main(){
    string questions[] = {"1. What is your name?: ",
                          "2. How old are you?: ",
                          "3. What are your hobbies?: "
                         };

    string options[][4] = {{"A. Kabeer Danish", "B. Sameer Danish"},
                           {"A. 10", "B. 20", "C. 21"},
                           {"A. Dancing", "B. Listening Songs", "C. Muthi"}} ;

    char answerKey[] = {'A', 'C', 'B'};

    int size = sizeof(questions)/sizeof(questions[0]);
    char guess;
    int score = 0;

    for(int i=0; i<size; i++){
        cout << "******************************\n";
        cout << questions[i] << endl;
        cout << "******************************\n";

        for(int j=0; j<sizeof(options[i])/sizeof(options[i][0]); j++){
            cout << options[i][j] << endl;
        }

        cin >> guess;
        guess = toupper(guess);

        if(guess == answerKey[i]){
            cout << "CORRECT\n";
            score++;
        }
        else{
            cout << "WRONG\n";
            cout << "Answer: " << answerKey[i] << endl;
        }

    }

    cout << "******************************\n";
    cout << "*          RESULTS           *\n";    
    cout << "******************************\n";
    cout << "CORRECT GUESSES: " << score << endl;
    cout << "# of Questions: " << size << endl;
    cout << "Score: " << (score/(double)size)*100 << "%";
} 