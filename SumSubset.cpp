#include <iostream>#include <vector>// Function to find and print subset with the given sumbool isSubsetSum(std::vector<int>& set, int n, int sum, std::vector<int>& subset) {    // Base Cases    if (sum == 0)        return true;    if (n == 0)        return false;    // If last element is greater than sum, then ignore it    if (set[n - 1] > sum)        return isSubsetSum(set, n - 1, sum, subset);    // Check if sum can be obtained by either including or excluding the last element    if (isSubsetSum(set, n - 1, sum, subset)) {        return true;    } else if (isSubsetSum(set, n - 1, sum - set[n - 1], subset)) {        subset.push_back(set[n - 1]); // Include current element in the subset        return true;    }    return false;}// Driver codeint main() {    // Input set of numbers    std::vector<int> set;    int num;    std::cout << "Enter the number of elements in the set: ";    std::cin >> num;    std::cout << "Enter the elements of the set: ";    for (int i = 0; i < num; ++i) {        int element;        std::cin >> element;        set.push_back(element);    }    // Input the target sum    int sum;    std::cout << "Enter the target sum: ";    std::cin >> sum;    // Find and print subset with the given sum    std::vector<int> subset;    if (isSubsetSum(set, num, sum, subset)) {        std::cout << "Found a subset with the given sum: ";        for (int i = 0; i < subset.size(); ++i) {            std::cout << subset[i];            if (i != subset.size() - 1) {                std::cout << ", ";            }        }        std::cout << std::endl;    } else {        std::cout << "No subset with the given sum" << std::endl;    }    return 0;}