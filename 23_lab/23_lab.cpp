#include <iostream>
#include <algorithm>

class ModifiedString {
public:
    ModifiedString() {}
    ModifiedString(const std::string& s) : str(s) {}

    void PerformModification() {
        std::reverse(str.begin(), str.end());
    }

    std::string GetResult() const {
        return str;
    }

private:
    std::string str;
};

int main() {
    ModifiedString myString("salamchik, bratva!");
    myString.PerformModification();

    std::cout << "Modified String: " << myString.GetResult() << std::endl;

    myString.PerformModification();
    const ModifiedString& stringRef = myString;
    std::string reversed = stringRef.GetResult();
    std::cout << "Reversed String: " << reversed << std::endl;

    ModifiedString empty;
    std::cout << "Empty String: \"" << empty.GetResult() << "\"" << std::endl;

    return 0;
}
