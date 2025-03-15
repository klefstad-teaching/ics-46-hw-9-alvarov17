#include "ladder.h"

void error(string word1, string word2, string msg)
{
    cout << "ERROR with word 1: " << word1 << " and word 2: " << word2 << "\n" << "Messsage: " << msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) // main algorithm
{

}

bool is_adjacent(const string& word1, const string& word2)
{
    // call edit_distance_within and set the d argument to 1
    if (edit_distance_within(word1, word2, 1)) return true; // might be wrong 



}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) // breadth first search
{
    if (being_word == end_word) return {};
    queue<vector<string>> ladder_queue;
    ladder_queue.push([begin_word]);
    set<string> visited;
    visited.insert(begin_word);
    while (!ladder_queue.empty())
    {
        vector<string> ladder = ladder_queue.top();
        ladder_queue.pop();
        string last_word = ladder[ladder.size() - 1];
        for(auto it = word_list.begin(); it != word_list.end(); ++it)
        {
            if (is_adjacent(last_word, *it))
            {
                if (!visited.find(*it))
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
    return vector<string>;
}

void load_words(set<string> & word_list, const string& file_name)
{
    string word;
    ifstream file(file_name);
    while (file >> word_list) 
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
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}
