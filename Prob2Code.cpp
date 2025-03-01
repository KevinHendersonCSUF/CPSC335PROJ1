// Project 1, Problem 2

// Language used: C++

// Names:
// Kevin Henderson, Bryan Tran, Kenny Ly, Nathan Preheim
//-----------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

// Algorithm 2
// BUGS: INPUTs [8, 1, 4, 3, 0, 7], [43, 45, 0, 44, 1, 46] IS NOT PRODUCING
// CORRECT OUTPUT
int minSwapsCouples(std::vector<int>& row) {
  int n = row.size();
  int swaps = 0;

  // Create a map
  std::unordered_map<int, int> pos;
  for (int i = 0; i < n; i++) {
    pos[row[i]] = i;
  }

  // Process seating in pairs
  for (int i = 0; i < n; i += 2) {
    int first_person = row[i];
    // XOR
    // If first_person is even, partner = first_person + 1; if odd, partner =
    // first_person - 1.
    int partner = first_person ^ 1;

    // Base case
    if (row[i + 1] != partner) {
      int partner_index = pos[partner];
      std::swap(row[i + 1], row[partner_index]);
      // Update the positions in the mapping.
      pos[row[partner_index]] = partner_index;
      pos[row[i + 1]] = i + 1;
      swaps++;
    }
  }

  return swaps;
}

int main() {
  int row_length = 0;
  int temp = 0;
  std::vector<int> row;
  // prompt user for length of row
  std::cout << "Enter row length: ";
  std::cin >> row_length;
  if (row_length >= 2 * 30 || row_length % 2 != 0) {
    std::cout << "Row must be less than or equal to 30 and even!" << '\n';
    return 1;
  }
  // checks if input is a number or not
  if (!std::cin) {
    std::cout << "Input must be a number!" << '\n';
    return 1;
  }
  // prompt user to add numbers to row
  for (int i = 0; i < row_length; i++) {
    std::cout << "Enter number at index " << i << ": ";
    std::cin >> temp;
    row.push_back(temp);

    // same integer check from above
    if (!std::cin) {
      std::cout << "Input must be a number!" << '\n';
      return 1;
    }
  }
  std::cout << "-----------------------------------" << '\n';
  // perform the swap and print how many swaps
  std::cout << "Number of swaps: " << minSwapsCouples(row) << '\n';

  // print the row after swap
  std::cout << "[";
  int pair = 0;
  for (int k = 0; k < row.size(); k++) {
    if (pair == 0) {
      std::cout << "(";
    }
    std::cout << row[k];
    pair++;
    if (pair == 1) {
      std::cout << ", ";
    }
    if (pair == 2) {
      // check if couples follow the (2n-2, 2n-1) format stated in project
      // instructions, if not, stop printing and print error message
      if (row[k - 1] != row[k] + 1 && row[k - 1] != row[k] - 1) {
        std::cout << '\n' << "Couples must follow (2n-2, 2n-1)!" << '\n';
        return 1;
      }
      std::cout << ")";
      pair = 0;
    }
  }
  std::cout << "]" << '\n';

  return 0;
}
