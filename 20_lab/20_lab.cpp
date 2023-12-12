#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Генерація кількості голосів для кожного кандидата в кожному населеному пункті
void generateVotes(int votes[][5]) {
    srand(time(NULL));
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            votes[i][j] = rand() % 500 + 50 * (j + 1);
        }
    }
}

// Виведення результатів голосування у вигляді таблиці
void printResults(int votes[][5]) {
    cout << "Results of the election:\n";
    cout << "---------------------------------\n";
    cout << "City\tПЕТЯ 1\tСАШКО 2\tВітлій 3\tСЕМЕН 4\tВАЛІК 5\n";
    cout << "---------------------------------\n";
    for (int i = 0; i < 6; i++) {
        cout << i + 1 << "\t";
        for (int j = 0; j < 5; j++) {
            cout << votes[i][j] << "\t\t";
        }
        cout << endl;
    }
    cout << "---------------------------------\n";
}

// Знаходження кандидата з меншею кількістю голосів ніж n
void findCandidateWithLessVotes(int votes[][5], int n) {
    for (int j = 0; j < 5; j++) {
        int totalVotes = 0;
        for (int i = 0; i < 6; i++) {
            totalVotes += votes[i][j];
        }
        if (totalVotes < n) {
            cout << "Candidate " << j + 1 << " has less than " << n << " votes.\n";
        }
    }
}

int main() {
    int votes[6][5];
    generateVotes(votes);
    printResults(votes);

    int n;
    cout << "Enter the threshold number of votes (n): ";
    cin >> n;

    findCandidateWithLessVotes(votes, n);

    return 0;
}
