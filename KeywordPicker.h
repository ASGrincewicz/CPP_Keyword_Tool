//
// Created by Aaron on 8/2/2024.
//
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#ifndef KEYWORDPICKER_KEYWORDPICKER_H
#define KEYWORDPICKER_KEYWORDPICKER_H

class KeywordPicker
{
public:
    struct Keyword {
        string word;
        string definition;
        int value;
    };

    [[nodiscard]] inline std::vector<Keyword> Get_Keywords() const
    {
        return keywords_;
    }

    vector<Keyword> selectKeywords(int totalValue);

    void pickRandomKeywords();

    void saveToFile(const Keyword keyWords[], size_t size) const;

    void find_combinations(int target, int start, std::vector<int>& current, int& count);

    int total_combinations(int upper_limit);

    inline static bool compareByValue(const Keyword &a, const Keyword &b)
    {
        return a.value < b.value;
    }

    inline static void sortKeywords(vector<Keyword> &keyWords)
    {
        std::sort(keyWords.begin(), keyWords.end(), compareByValue);
    }

    inline void sortAndSaveToFile(vector<Keyword> &keyWords) const
    {
        // Sort the array by 'value'
        sortKeywords(keyWords);

        // Save to file
        saveToFile(keyWords.data(), keyWords.size());
    }
private:
   std::vector<Keyword> keywords_ = {
            {"Barrage","Attack X Targets this turn. You must roll X or higher for each attack to succeed.",1},
            {"Mend","Heal any ally by 5 HP", 1},
            {"Blink","Move this card from the melee zone to the ranged zone or vice versa.", 2},
            {"Fortify","Take -5 Damage from the next successful attack.", 3},
            {"Charge","This cards next attack does 2x Damage.", 3},
            {"Deflect","When this card is attacked, roll a die, the attacker must roll higher to succeed or they take the damage.", 4},
            {"Empower","Pick an adjacent ally to enter Focus mode, gain their generated Quantix immediately.", 5},
            {"Strafe","Negate an opponent's 'Deflect'.", 6},
            {"Unveil", "Deactivate an enemy's 'Cloak'",6},
            {"Dodge","Roll a 5 or 6 to take no damage from a successful attack.\n"
                     "If this card is in the melee zone, any ally in the ranged position behind this card takes the damage.", 7},
            {"Cloak","This card cannot be targeted this turn.",7},
            {"Kinetic","Activate this ability to redirect all successful ally attacks towards this card.\n"
                       "This card has +5 Attack for each redirected attack.  If this card's attack fails, each redirecting ally takes 5 damage. ", 8},
            {"Vanguard","Activate this ability to redirect a successful enemy attack on an ally towards this card.", 9},
            {"Overcharge","Shuffle X cards from your hand into your deck. This card has +5X Attack.", 10},
            {"Rally", "All allies get +5 Attack this turn.", 10},
            {"Pulse","Deal 5 Damage to every card at this card's location.", 11},
            {"Nullify","Cancel an enemy's ability and all effects.", 12}

    };
};


#endif //KEYWORDPICKER_KEYWORDPICKER_H
