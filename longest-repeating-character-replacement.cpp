#include <iostream>

using namespace std;

int characterReplacement(string s, int k) {
  int longestLength;

  if (s.length() <= 1)
    return s.length();
  if (k == 0) {
    // find the longest substring repeating characters
    int longest = 1;
    longestLength = 1;
    for (int i = 0; i < s.length(); i++) {
      longest = 1;
      for (int j = i + 1; j < s.length(); j++) {
        if (s[j] != s[i]) {
          if (longestLength < longest)
            longestLength = longest;
          j = s.length();
        } else {
          i++;
          longest++;
        }
      }
      if (longestLength < longest)
        longestLength = longest;
    }

    return longestLength;
  }
  for (int i = 0; i < s.length() - k - 1; i++) {
    cout << s[i] << ": ";
    int p = i + k + 1;
    if (p >= s.length()) {
      break;
    }

    for (int j = i + 1; j < p; j++) {
      if (s[j] == s[i])
        p++;
    }
    longestLength = k + 1;
    for (int j = i + k + 1; j < s.length(); j++) {
      cout << s[j] << " ";
      if (s[j] == s[i])
        longestLength++;
      else
        break;
    }
    cout << " longestLength: " << longestLength;
    cout << "\n";
  }

  return longestLength;
}

int main(int argc, char const *argv[]) {
  // cout << "s = ABAB, k = 2 Output: \n"
  //      << characterReplacement("ABAB", 2) << "\n";
  // cout << "s = AABABBA, k = 1 Output: " << characterReplacement("AABABBA", 1) << "\n";
  // cout << "s = ABCDEDB, k = 1 Output: " << characterReplacement("ABCDEDB", 1) << "\n";
  // cout << "s = CABCDEAG, k = 4 Output: " << characterReplacement("CABCDEAG", 4) << "\n";
  cout << "s = CAAGGGEEEEE, k = 0 Output: \n"
       << characterReplacement("CAAGGGEEEEE", 0) << "\n";
  return 0;
}
