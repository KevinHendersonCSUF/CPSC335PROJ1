// Project 1, Problem 1

// Language used: C++

// Names:
// Kevin Henderson, Bryan Tran, Kenny Ly, Nathan Preheim
//-----------------------------------------------------------------------
// FOR NOW, THIS ONE IS CONFIGURED TO TEST BOTH ALGORITHMS
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// Algorithm 1
// Return the index of the preferred starting city.
int findPreferredStartingCity(const std::vector<int>& city_distances,
                              const std::vector<int>& fuel, int mpg) {
  int start_index = 0;
  int surplus = 0;
  // Iteration
  for (size_t i = 0; i < city_distances.size(); i++) {
    // Calculate
    int net_gain = fuel[i] * mpg - city_distances[i];
    surplus += net_gain;
    // Base case
    if (surplus < 0) {
      start_index = i + 1;
      surplus = 0;
    }
  }
  return start_index;
}
// Algorithm 2
// BUGS: INPUT [8, 1, 4, 3, 0, 7] IS NOT PRODUCING CORRECT OUTPUT
int minSwapsCouples(std::vector<int>& row) {
  int n = row.size();
  int swaps = 0;

  // Create a map
  std::vector<int> pos(n, 0);
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
  int choice = 0;
  std::cout << "Which Algorithm would you like to test(1 or 2): ";
  std::cin >> choice;
  if (choice == 1) {
    std::vector<int> distance;
    distance.push_back(5);
    distance.push_back(25);
    distance.push_back(15);
    distance.push_back(10);
    distance.push_back(15);
    std::vector<int> fuel;
    fuel.push_back(1);
    fuel.push_back(2);
    fuel.push_back(1);
    fuel.push_back(0);
    fuel.push_back(3);
    int mpg = 10;
    std::cout << "preferred starting city is: "
              << findPreferredStartingCity(distance, fuel, mpg) << '\n';
  } else {
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
    std::cout << "Swaps: " << minSwapsCouples(row) << '\n';
    for (int k : row) {
      std::cout << k;
    }
    std::cout << '\n';
  }
  return 0;
}