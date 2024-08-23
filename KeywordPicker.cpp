//
// Created by Aaron on 8/2/2024
//
#include <random>
#include<cstdlib>
#include<ctime>
#include <iostream>
#include <fstream>
#include "KeywordPicker.h"
using namespace std;


vector<KeywordPicker::Keyword> KeywordPicker::selectKeywords(int totalValue)
{
    srand(std::time(nullptr));  // use current time as seed for random number generator
    vector<Keyword> keywords = Get_Keywords();
    shuffle(std::begin(keywords), std::end(keywords), mt19937(std::random_device()()));
    std::vector<Keyword> selectedKeywords;
    int totalSelectedValue = 0;
    for(int i = 0; i < 12 && selectedKeywords.size() < 3; ++i) {
        if(totalSelectedValue + keywords[i].value <= totalValue) {
            selectedKeywords.push_back(keywords[i]);
            totalSelectedValue += keywords[i].value;
        }
    }
    return selectedKeywords;
}

void KeywordPicker::pickRandomKeywords()
{
    int totalKeywordValue;  // Get this value from user input
    cout << "Please enter a Keyword Value Total (1 -24):\n";
    cin >> totalKeywordValue;
    vector<Keyword> selectedKeywords = selectKeywords(totalKeywordValue);

    for(const Keyword& k : selectedKeywords)
    {
        cout << "Selected word: " << k.word << "\n";
        cout << "Def: " << k.definition << "\n";
        cout << "Value: " << k.value << "\n";
        cout << "-----------" << endl;
    }
}

void KeywordPicker::saveToFile(const KeywordPicker::Keyword keyWords[], size_t size) const
{
    ofstream myFile("keywords_.txt");
    if(myFile.is_open())
    {
        for(size_t i = 0; i < size; ++i)
        {
            myFile << keyWords[i].word << "\n";
            myFile << keyWords[i].definition << "\n";
            myFile << keyWords[i].value << "\n";
            myFile << "------\n";
        }
        myFile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}

void KeywordPicker::find_combinations(int target, int start, vector<int> &current, int &count)
{
    if(target == 0) {
        ++count;
        return;
    }
    if(target < start || current.size() == 3) {
        return;
    }

    for(int i = start; i <= 24; ++i) {
        current.push_back(i);
        find_combinations(target - i, i, current, count);
        current.pop_back();
    }
}

int KeywordPicker::total_combinations(int upper_limit)
{
    int count = 0;
    for (int target = 1; target <= upper_limit; ++target) {
        std::vector<int> current;
        find_combinations(target, 1, current, count);
    }
    return count;
}
