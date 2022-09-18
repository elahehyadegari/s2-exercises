#include <algorithm>
#include <iostream>
#include <vector>


int main(int argc, char *argv[]) {

  if (argc < 2) {
    std::cout << "invalid_argument" << std::endl;
    return -1;
  }
  auto numColumn{argc - 1};
  std::vector<int> column;
  for (size_t i = 0; i < numColumn; i++) {

    try {

      column.push_back(std::stoi(argv[i + 1]));
    } catch (std::invalid_argument const &ex) {
      std::cout << "invalid_argument" << std::endl;
      return -1;
    }
  }

  auto max{*std::max_element(std::begin(column), std::end(column))};
  auto min{*std::min_element(std::begin(column), std::end(column))};
  auto maxAbs{std::max(std::abs(max), std::abs(min))};
  std::cout << "^"
            << "\n";
  for (auto i = maxAbs; - maxAbs - 1 < i; i--) {
    if (i == 0) {
      std::cout << "+ " << std::string(numColumn, '#') << '\n';
      continue;
    }

    std::cout << "| ";
    std::for_each(column.begin(), column.end(), [i](int &c) {
      std::cout << ((c >= i && i > 0 || (i >= c && i < 0)) ? "#" : " ");
    });
    std::cout << "\n";
  }
  std::cout << "v";
  return 0;
}