#include <iostream>
#include <string>
#include <sstream>

// Function to swap the first two letters of words with the same first two letters
void swapWordsWithSameFirstLetter(std::string& input) {
    std::istringstream iss(input);
    std::string word;
    std::string result;

    while (iss >> word) {
        if (word.length() > 1) {
            // Check if the first two letters are the same and swap them
            if (word[0] == word[1]) {
                std::swap(word[0], word[1]);
            }
        }
        result += word + " ";
    }

    // Remove the trailing space
    result.pop_back();

    // Update the original input string
    input = result;
}

int main() {
    setlocale(LC_ALL, "UKR");

    std::string input;

    // Get the input string
    std::cout << "Введіть рядок слів: ";
    std::getline(std::cin, input);

    // Swap the first two letters of words with the same first two letters
    swapWordsWithSameFirstLetter(input);

    // Display the modified string
    std::cout << "Змінений рядок: " << input << std::endl;

    return 0;
}
