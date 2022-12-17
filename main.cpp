#include <iostream>
#include <string>


int longest_common_substring(std::string& text, std::string& substring) {
  int lcs_suffixes[text.length() + 1][substring.length() + 1];
  int result = 0;

  for (int i = 0; i <= text.length(); i++) {
    for(int j = 0; j < substring.length(); j++) {

      if (i == 0 || j ==0) {
        lcs_suffixes[i][j] = 0;
      } else if (text[i - 1] == substring[i - 1]) {
        lcs_suffixes[i][j] = lcs_suffixes[i - 1][j - 1] + 1;
        result = std::max(result, lcs_suffixes[i][j]);
      } else {
        lcs_suffixes[i][j] = 0;
      }
    }
  }

  return result;
}

int main() {

  std::string text;
  std::string substring;

  std::cout << "Enter string" << std::endl;
  std::cin >> text;

  std::cout << "Enter substring" << std::endl;
  std::cin >> substring;

  std::cout << "LCS is " << longest_common_substring(text, substring) << std::endl;
}

