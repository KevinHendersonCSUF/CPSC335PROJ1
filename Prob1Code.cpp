// Project 1, Problem 1

// Language used: C++

// Names:
// Kevin Henderson, Bryan Tran, Kenny Ly, Nathan Preheim
//-----------------------------------------------------------------------

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
  int city = 0;
  int mpg = 0;
  std::cout << "how many cities: ";
  std::cin >> city;
  std::vector<int> distance;
  // push distance from city i to city i+1
  for (int i = 0; i < city; i++) {
    int dist = 0;
    if (i == city - 1) {
      std::cout << "Enter distance from city " << i << " back to city "
                << city - i - 1 << ": ";
      std::cin >> dist;
    } else {
      std::cout << "Enter distance from city " << i << " to city " << i + 1
                << ": ";
      std::cin >> dist;
    }
    distance.push_back(dist);
  }
  std::cout << "-------------------------------------------------" << '\n';
  // push the amount of fuel available in each city
  std::vector<int> fuel;
  for (int j = 0; j < distance.size(); j++) {
    int gas = 0;
    std::cout << "Enter amoount of fuel available in city " << j << ": ";
    std::cin >> gas;
    fuel.push_back(gas);
  }
  std::cout << "-------------------------------------------------" << '\n';
  // set the mpg for the car
  std::cout << "Enter the mpg: ";
  std::cin >> mpg;
  std::cout << "-------------------------------------------------" << '\n';

  std::cout << "preferred starting city is: "
            << findPreferredStartingCity(distance, fuel, mpg) << '\n';

  return 0;
}
