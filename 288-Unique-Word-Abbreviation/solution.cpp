class ValidWordAbbr {
public:
    unordered_map<string, string> m;
    ValidWordAbbr(vector<string>& dictionary) {
        for(int i = 0; i < dictionary.size(); i++)
        {
            string tmp = word2Abbr(dictionary[i]);
            if(tmp == "")continue;
            m[tmp] += dictionary[i];
        }
    }

    bool isUnique(string word) {
        string tmp = word2Abbr(word);
        if(tmp == "")return true;
        //not find:true
        if(m.find(tmp) == m.end())return true;
        //find once and it is the original word
        return m[tmp] == word;
    }

    string word2Abbr(string input)
    {
        string output;
        int len = input.size();
        if(len < 3)return "";
        else{
           output = input[0] + to_string(len-2) + input[len-1];
        }
        return output;
    }

};



// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");