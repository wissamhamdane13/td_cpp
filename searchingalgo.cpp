#include <iostream>
#include <vector>
#include <cmath>

class SearchingAlgorithm {
protected:
    int numberComparisons = 0;
    static int totalComparisons;
    static int totalSearch;
    static float averageComparisons;

public:
    virtual int search(const std::vector<int>& data, int target) = 0;

    void displaySearchResults(std::ostream& os, int result, int target) {
        totalComparisons += numberComparisons;
        totalSearch++;
        averageComparisons = static_cast<float>(totalComparisons) / totalSearch;

        os << "Target " << target << " found at index " << result
           << " with " << numberComparisons << " comparisons." << std::endl;
        os << "Total comparisons: " << totalComparisons << std::endl;
        os << "Average comparisons: " << averageComparisons << std::endl;
    }

    static int getTotalComparisons() { return totalComparisons; }
    static int getTotalSearch() { return totalSearch; }
    static float getAverageComparisons() { return averageComparisons; }
};

int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
float SearchingAlgorithm::averageComparisons = 0.0;

class LinearSearch : public SearchingAlgorithm {
public:
    int search(const std::vector<int>& data, int target) override {
        numberComparisons = 0;
        for (int i = 0; i < data.size(); ++i) {
            numberComparisons++;
            if (data[i] == target) return i;
        }
        return -1;
    }
};

class JumpSearch : public SearchingAlgorithm {
public:
    int search(const std::vector<int>& data, int target) override {
        int n = data.size();
        int step = std::sqrt(n);
        int prev = 0;
        numberComparisons = 0;

        while (data[std::min(step, n) - 1] < target) {
            numberComparisons++;
            prev = step;
            step += std::sqrt(n);
            if (prev >= n) return -1;
        }

        for (int i = prev; i < std::min(step, n); ++i) {
            numberComparisons++;
            if (data[i] == target) return i;
        }

        return -1;
    }
};

class BinarySearch : public SearchingAlgorithm {
public:
    int search(const std::vector<int>& data, int target) override {
        int left = 0, right = data.size() - 1;
        numberComparisons = 0;

        while (left <= right) {
            numberComparisons++;
            int mid = left + (right - left) / 2;

            if (data[mid] == target) return mid;
            if (data[mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return -1;
    }
};

int main() {
    std::vector<int> data = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 9;

    LinearSearch linearSearch;
    JumpSearch jumpSearch;
    BinarySearch binarySearch;

    int result = linearSearch.search(data, target);
    linearSearch.displaySearchResults(std::cout, result, target);

    result = jumpSearch.search(data, target);
    jumpSearch.displaySearchResults(std::cout, result, target);

    result = binarySearch.search(data, target);
    binarySearch.displaySearchResults(std::cout, result, target);

    return 0;
}