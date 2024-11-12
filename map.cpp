#include <iostream>
#include <vector>
#include <map>
using namespace std;

void countFrequencyBruteForce(const vector<int>& numbers) {
    for (size_t i = 0; i < numbers.size(); ++i) {
        bool alreadyCounted = false;
        for (size_t j = 0; j < i; ++j) {
            if (numbers[j] == numbers[i]) {
                alreadyCounted = true;
                break;
            }
        }
        if (!alreadyCounted) {
            int count = 1;
            for (size_t k = i + 1; k < numbers.size(); ++k) {
                if (numbers[k] == numbers[i]) ++count;
            }
            cout << numbers[i] << " appears " << count << " times" << endl;
        }
    }
}

map<int, int> countFrequencyOptimal(const vector<int>& numbers) {
    map<int, int> frequencyMap;
    for (int num : numbers) ++frequencyMap[num];
    return frequencyMap;
}

int main() {
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};

    cout << "Frequency (Brute Force):" << endl;
    countFrequencyBruteForce(numbers);

    cout << "\nFrequency (Optimal):" << endl;
    for (auto& entry : countFrequencyOptimal(numbers)) {
        cout << entry.first << " appears " << entry.second << " times" << endl;
    }

    return 0;
}
