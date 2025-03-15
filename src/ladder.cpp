#include "ladder.h"
#include <cassert>

void error(string word1, string word2, string msg)
{
    cout << "ERROR with word 1: " << word1 << " and word 2: " << word2 << "\n" << "Messsage: " << msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) // main algorithm
{
    int str1_len = str1.size();
    int str2_len = str2.size();
    int len_diff = str1_len - str2_len;
    if ((len_diff != 0) && (len_diff != 1) && (len_diff != -1)) return false;

    vector<vector<int>> dp(str1_len + 1, vector<int>(str2_len + 1));

    // Initialize the base cases
    for (int i = 0; i <= str1_len; ++i) dp[i][0] = i;
    for (int j = 0; j <= str2_len; ++j) dp[0][j] = j;

    // Compute the edit distance
    for (int i = 1; i <= str1_len; ++i) {
        for (int j = 1; j <= str2_len; ++j) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
        }
    }
    int dist = dp[str1_len][str2_len];
    return dist == d ? true : false;
}

bool is_adjacent(const string& word1, const string& word2)
{
    // call edit_distance_within and set the d argument to 1
    if (edit_distance_within(word1, word2, 1)) return true; // might be wrong 
    return false;
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) // breadth first search
{
    if (begin_word == end_word) return {};
    if (word_list.count(end_word) == 0) return {};
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);
    while (!ladder_queue.empty())
    {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder[ladder.size() - 1];
        for(auto it = word_list.begin(); it != word_list.end(); ++it)
        {
            if (is_adjacent(last_word, *it))
            {
                if (!visited.count(*it))
                {
                    visited.insert(*it);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(*it);
                    if (*it == end_word)
                    {
                        return new_ladder;
                    }
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    return {};
}

void load_words(set<string> & word_list, const string& file_name)
{
    string word;
    ifstream file(file_name);
    while (file >> word) 
    {
        word_list.insert(word);
    }
    file.close();
}

void print_word_ladder(const vector<string>& ladder)
{
    for (string word : ladder)
    {
        cout << word << " ";
    }
}

void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "words.txt");
    assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    assert(generate_word_ladder("code", "data", word_list).size() == 6);
    assert(generate_word_ladder("work", "play", word_list).size() == 6);
    assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}
