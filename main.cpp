#include <iostream>
#include <string>
#include <vector>
#include <tuple>

class Card {
    private:
    std :: string cardName;
    public:
    Card(const std::string &name ) : cardName(name) {}
    virtual void displayInfo () const=0;

    
};

class PokemonCard : public Card {
    private:
    std::string pokemonType;
    std::string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    std::vector<std::tuple<int,int,std::string,int>> attacks;
    int cout_energie;
    int cout_energie_actuel;
    std::string description;
    int degats;
    public:
    PokemonCard(const std::string& name ,const std::string &type, const std::string &name,
    int level, int hp, const std ::vector <std::tuple<int,int,std::string,int>>& attack,
    int energy,int energyact,const std::string& decrire, int degat):
    Card(name),pokemonType(type),familyName(name),evolutionLevel(level),maxHP(hp),attacks(attack),
    cout_energie(energy),cout_energie_actuel(energyact),description(decrire),degats(degat);


};

class EnergyCard :public Card{
    private:
    std::string energyType;
    public:
    EnergyCard(const std::string&name,const std::string & type)
        : Card("Energy"), energyType(type) {}
};

class TrainerCard : public Card{
    private:
    std::string trainerEffect;
    public:
    TrainerCard(std::string& name, std::string       ): 

};