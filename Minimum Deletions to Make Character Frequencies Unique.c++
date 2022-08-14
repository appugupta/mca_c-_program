class Solution {
public:
    int minDeletions(string s) {
        // Store the frequency of each character
        vector<int> frequency(26, 0);
        for (char c : s) {
            frequency[c - 'a']++;
        }
        
        int deleteCount = 0;
        // Use a set to store the frequencies we have already seen
        unordered_set<int> seenFrequencies;
        for (int i = 0; i < 26; i++) {
            // Keep decrementing the frequency until it is unique
            while (frequency[i] && seenFrequencies.find(frequency[i]) != seenFrequencies.end()) {
                frequency[i]--;
                deleteCount++;
            }
            // Add the newly occupied frequency to the set
            seenFrequencies.insert(frequency[i]);
        }
        
        return deleteCount;
    }
};