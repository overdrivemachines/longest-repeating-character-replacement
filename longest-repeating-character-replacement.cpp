#include <iostream>
#include <unordered_map>

using namespace std;

int characterReplacement(string s, int k) {
  int longestLength;

  // cout << "\n";

  if ((s.length() <= 1) || (k >= s.length() - 1))
    return s.length();
  if (k == 0) {
    // find the longest substring of repeating characters
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
      if (longestLength == s.length())
        return longestLength;
    }

    return longestLength;
  }

  longestLength = 1;
  unordered_map<char, int> umap;
  int i = 0;
  char leftchar = s[i];
  char rightchar;
  umap[leftchar] = 1;
  int windowLength = 0;

  char mostFrequentChar;
  int mostFrequentCharCount = 0;

  // s = CABBBB, k = 2
  // cout << leftchar << ": ";
  for (int j = 1; j < s.length(); j++) {
    rightchar = s[j];
    windowLength = j - i + 1;

    // cout << rightchar << " ";
    // add rightchar to umap
    if (umap.count(rightchar)) {
      // if rightchar exists in umap, increment its number of occurrences
      umap[rightchar]++;
    } else {
      // cout << "newc ";
      umap[rightchar] = 1;
    }

    // find most frequent character in umap
    for (auto x : umap) {
      if (x.second > mostFrequentCharCount) {
        mostFrequentCharCount = x.second;
        mostFrequentChar = x.first;
      }
    }

    if (windowLength - mostFrequentCharCount <= k) {
      // cout << "valid ";
      if (windowLength > longestLength) {
        longestLength = windowLength;
      }
    } else {
      // cout << "invalid ";
      umap[leftchar]--;
      leftchar = s[++i];
      // cout << "\n";
      // cout << leftchar << ".." << rightchar << ": ";
    }
  }

  return longestLength;
}

int main(int argc, char const *argv[]) {
  // cout << "s = ABAB, k = 2 Output: \n"
  //      << characterReplacement("ABAB", 2) << "\n";
  // cout << "s = AABAACA, k = 1 Output: " << characterReplacement("AABAACA", 1) << "\n";
  // cout << "s = ABCDEDB, k = 1 Output: " << characterReplacement("ABCDEDB", 1) << "\n";
  // cout << "s = CABCDEAG, k = 4 Output: " << characterReplacement("CABCDEAG", 4) << "\n";
  // cout << "s = CAAGGGEEEEE, k = 0 Output:" << characterReplacement("CAAGGGEEEEE", 0) << "\n";
  cout << "s = BAAAB, k = 2 Output:" << characterReplacement("BAAAB", 2) << "\n";
  return 0;
}
