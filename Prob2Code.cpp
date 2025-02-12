// Project 1, Problem 2

// Language used: C++

// Names:
// Kevin Henderson, Bryan Tran, Kenny Ly, Nathan Preheim
//-----------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>

int main() {
  int row_input = 0;
  int row_length = 0;
  int swaps = 0;
  int temp = 0;
  int temp2 = 0;
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
  // create array for row operations
  int row[row_length];
  // create row that doesnt get changed for print later
  int inprow[row_length];
  // prompt user to add numbers to row
  for (int i = 0; i < row_length; i++) {
    std::cout << "enter number at index " << i << ": ";
    std::cin >> row[i];

    inprow[i] = row[i];
    // same integer check from above
    if (!std::cin) {
      std::cout << "Input must be a number!" << '\n';
      return 1;
    }
  }

  // main swap operation block
  for (int j = 1; j < row_length; j++) {
    if (row[j] != row[j - 1] + 1) {
      // assign the elements to be swapped to temp variables to keep track
      temp = row[j - 1] + 1;
      temp2 = row[j];
      // performs the swap and increments the counter
      for (int x = 0; x < row_length; x++) {
        if (row[x] == temp) {
          row[j] = temp;
          row[x] = temp2;
          std::cout << "row[" << j << "]" << " needs to be swapped with row["
                    << x << "]" << '\n';
          swaps++;
          break;
        }
      }
    }
  }

  // prints both input row, and newly swapped row and number of swaps performed
  std::cout << "Input row = [ ";
  for (int k = 0; k < row_length; k++) {
    std::cout << inprow[k] << " ";
  }
  std::cout << "]" << "\n" << "-----------------------------------" << '\n';
  std::cout << "Number of swaps: " << swaps << '\n';
  if (swaps == 0) {
    std::cout << "All couples are already seated side by side" << '\n';
  } else {
    std::cout << "swapped row = [ ";
    for (int k = 0; k < row_length; k++) {
      std::cout << row[k] << " ";
    }
    std::cout << "]" << "\n";
  }

  return 0;
}
