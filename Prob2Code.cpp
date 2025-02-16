// Project 1, Problem 2

// Language used: C++

// Names:
// Kevin Henderson, Bryan Tran, Kenny Ly, Nathan Preheim
//-----------------------------------------------------------------------

// BUGLIST:
// * input: [2, 0, 4, 1, 3, 5] is producing wrong output.
#include <iostream>
#include <string>
#include <vector>

int main() {
  int row_input = 0;
  int row_length = 0;
  int swaps = 0;
  int temp = 0;

  // prompt user for length of row
  std::cout << "How long is the row?" << '\n';
  std::cin >> row_length;
  if (row_length > 30 || row_length % 2 != 0) {
    std::cout << "Row must be less than 30 and even!" << '\n';
    return 1;
  }
  // checks if input is a number or not
  if (!std::cin) {
    std::cout << "Input must be a number!" << '\n';
    return 1;
  }

  // create row that doesnt get changed for print later
  std::vector<int> row;
  // prompt user to add numbers to row
  for (int i = 0; i < row_length; i++) {
    std::cout << "enter number at index " << i << ": ";
    std::cin >> temp;
    row.push_back(temp);

    // same integer check from above
    if (!std::cin) {
      std::cout << "Input must be a number!" << '\n';
      return 1;
    }
  }

  // main swap operation block
  for (int j = 0; j < row.size(); j++) {
    // checks to see if individual is sitting next to its partner, if not,
    // assign whoevers next to it to temp value for swap
    if (row[j + 1] != row[j] + 1 && row[j + 1] != row[j] - 1) {
      temp = row[j + 1];

      for (int x = 0; x <= row.size(); x++) {
        if (row[x] == row[j] + 1 || row[x] == row[j] - 1) {
          row[j + 1] = row[x];
          row[x] = temp;
          swaps++;
          break;
        }
      }
    }
    // skips individual that was just swapped
    j++;
  }
  std::cout << "Number of swaps: " << swaps << '\n';

  // for testing
  for (int k : row) {
    std::cout << k << '\n';
  }

  if (swaps == 0) {
    std::cout << "All couples are already seated side by side" << '\n';
  }
  return 0;
}