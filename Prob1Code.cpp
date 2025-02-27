// Project 1, Problem 1

// Language used: C++

// Names:
// Kevin Henderson, Bryan Tran, Kenny Ly, Nathan Preheim
//-----------------------------------------------------------------------
// FOR NOW, THIS ONE IS CONFIGURED TO TEST BOTH ALGORITHMS
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

int main() {
    std::vector<int> distance;
    distance.push_back(15);
    distance.push_back(5);
    distance.push_back(15);
    distance.push_back(25);
    distance.push_back(10);
    std::vector<int> fuel;
    fuel.push_back(3);
    fuel.push_back(0);
    fuel.push_back(1);
    fuel.push_back(2);
    fuel.push_back(1);
    int mpg = 10;
    std::cout << "preferred starting city is: "
              << findPreferredStartingCity(distance, fuel, mpg) << '\n';

  return 0;
}
