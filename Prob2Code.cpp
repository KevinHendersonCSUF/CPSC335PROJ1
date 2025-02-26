// Project 1, Problem 2

// Language used: C++

// Names:
// Kevin Henderson, Bryan Tran, Kenny Ly, Nathan Preheim
//-----------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>

std::vector<int> Swapper(std::vector<int>& row) {
  int temp = 0;
  int swaps = 0;
  for (int j = 0; j < row.size(); j++) {
    // checks to see if individual is sitting next to its partner, if not,
    // assign whoevers next to it to temp value for swap
    if (row[j + 1] != row[j] + 1 && row[j + 1] != row[j] - 1) {
      temp = row[j + 1];
      // iterate through the individuals to find which ones to swap
      for (int x = 0; x <= row.size(); x++) {
        if (row[x] == row[j] + 1 || row[x] == row[j] - 1) {
          row[j + 1] = row[x];
          row[x] = temp;
          swaps++;
          // prints what individuals are swapped
          std::cout << "row[" << j + 1 << "] must be swapped with row[" << x
                    << "]" << '\n';
          break;
        }
      }
    }
    // skips individual that was just swapped
    j++;
  }
  std::cout << "Number of swaps: " << swaps << '\n';
  if (swaps == 0) {
    std::cout << "All couples are already seated side by side" << '\n';
  }
  return row;
}

int main() {
  int row_length = 0;
  int temp = 0;

  // prompt user for length of row
  std::cout << "How long is the row: ";
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
  std::cout << "-----------------------------------" << '\n';
  // perform the swap
  Swapper(row);

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
      //check if couples follow the (2n-2, 2n-1) format stated in project instructions, if not, stop printing and print error message
      if(row[k-1] != row[k] + 1 && row[k-1] != row[k] - 1){
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