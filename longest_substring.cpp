#include <iostream>
#include <string>
#include <cstring>


using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	if (s.length() == 1) {
		return 1;
	}

	int char_map[200] = {0};
	// for reset map use => memset(map, 0, sizeof(char_map));
	int max_count = 0;
	int temp_count = 0;
	int index = 1;
	for ( string::iterator it=s.begin(); it!=s.end(); ++it, ++index ) {
		if (char_map[(int) *it]) {
			//temp_count = index - char_map[(int) *it];
			if ( ! (temp_count < char_map[(int) *it]) ) {
				temp_count = index;
			}
		} else {
			temp_count++;
		}
		char_map[(int) *it] = index;
		if (max_count < index - temp_count) {
			max_count = index - temp_count;
		}
	}
        return max_count;
    }
};

int main(void) {
	Solution solution = Solution();
	std::string s = "abba";


	int answer = solution.lengthOfLongestSubstring(s);
	std::cout << " answer: " << answer << std::endl;
	std::cout << " ******a: " << (int) 'a' << std::endl;
	std::cout << " ******z: " << (int) 'z' << std::endl;

	return 0;
}

