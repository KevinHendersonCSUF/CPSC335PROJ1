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
int minSwapsCouples(std::vector<int>& row) {
  int n = row.size();
  int swaps = 0;

  // Build a mapping from each person's value to their index.
  std::unordered_map<int, int> pos;
  for (int i = 0; i < n; i++) {
    pos[row[i]] = i;
  }

  // Process each pair in the row.
  for (int i = 0; i < n; i += 2) {
    int personA = row[i];
    // Calculate the correct partner for personA using XOR:
    // If personA is even, partner = personA + 1; if odd, partner = personA - 1.
    int correctPartner = personA ^ 1;

    // If the next person is not the correct partner, perform a swap.
    if (row[i + 1] != correctPartner) {
      // Check that the correct partner exists in the mapping.
      if (pos.find(correctPartner) == pos.end()) {
        std::cout << "Error: partner " << correctPartner 
                  << " not found for person " << personA << std::endl;
        return -1;
      }
      
      // Get the index where the correct partner is currently located.
      int partnerIndex = pos[correctPartner];
      
      // Swap the person at i+1 with the correct partner.
      std::swap(row[i + 1], row[partnerIndex]);
      
      // Update the mapping with the new positions.
      pos[row[partnerIndex]] = partnerIndex;
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
