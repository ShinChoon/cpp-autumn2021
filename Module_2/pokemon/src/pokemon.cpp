#include "pokemon.hpp"
#include <algorithm>

bool Shorter_name(const std::pair<std::string, size_t> &a, const std::pair<std::string, size_t> &b)
{
    return (a.first[0] < b.first[0]);
}

bool Shorter_id(const std::pair<std::string, size_t> &a, const std::pair<std::string, size_t> &b)
{
    return (a.second < b.second);
}

bool alph_name(const std::pair<std::string, size_t> &a, const std::pair<std::string, size_t> &b)
{
    return (a.first[0] < b.first[0]);
}

/* constuctor
    * initializes the collection to contain all the pokemons from the two 
    * collections given as parameters and removes all duplicates, takes the following parameters:
    *  - collection: a PokemonCollection
    *  - collection2: a PokemonCollection
    * Hint: sorting at some point would probably help
    * 
    * All the other functions must get full points before this is tested.
    */
PokemonCollection::PokemonCollection(PokemonCollection collection, PokemonCollection collection2){
    std::copy(collection.pokemons_.begin(), collection.pokemons_.end(), std::back_inserter(pokemons_));
    std::copy(collection2.pokemons_.begin(), collection2.pokemons_.end(), std::back_inserter(pokemons_));
    pokemons_.sort(alph_name);
    auto end_unique = std::unique(pokemons_.begin(),pokemons_.end());
    pokemons_.erase(end_unique, pokemons_.end());
}

/* Add:
    * adds a pokemon to the end of the collection, takes the following parameters:
    *  - the pokemon's name, 
    *  - the pokemon's id, 
    */
void PokemonCollection::Add(const std::string &name, size_t id){
    pokemons_.push_back(std::make_pair(name, id));
}

/* Remove:
    * removes a pokemon to the collection, takes the following parameters:
    *  - the pokemon's name, 
    *  - the pokemon's id
    * returns true if the pokemon was found and removed, false otherwise
    */
bool PokemonCollection::Remove(const std::string &name, size_t id){
    auto it = std::find(pokemons_.cbegin(), pokemons_.cend(), std::make_pair(name,id));
    if (it != pokemons_.end())
    {

        pokemons_.erase(it);
        return true;
    }
    else
    {
        return false;
    }
};

/* Print:
    * Prints the collection to the standard output stream. 
    * The format of the print should be as below: 
id: <id>, name: <name>\n
id: <id>, name: <name>\n
    */
void PokemonCollection::Print() const{
    for (auto i = pokemons_.begin(); 
        i != pokemons_.end(); i++)
    {
        std::cout << "id: " << i->second << ", name: " << i->first << std::endl; 
    }
}

/* SortByName:
    * sorts the collection by name.
    * If two names are equal, their order is determined by their ids
    * Hint: A list only has bidirectional iterators, which might narrow your sorting solutions down a bit.
    * However a valid and easy solution does exist!
    */
void PokemonCollection::SortByName(){
    pokemons_.sort(Shorter_name);

    for (std::list<std::pair<std::string, size_t>>::iterator i = pokemons_.begin();
         i != pokemons_.end(); i++){
        if (i->first == std::next(i,1)->first)//compare name
        {
            if (Shorter_id(*(std::next(i, 1)), *i))//compare id
                std::swap(*i, *(std::next(i, 1)));
        }
    }
}

/* SortById:
    * sorts the collection by id
    * If two ids are equal, their order is determined by their names
    * Hint: A list only has bidirectional iterators, which might narrow your sorting solutions down a bit.
    * However a valid and easy solution does exist!
    */
void PokemonCollection::SortById(){
    pokemons_.sort(Shorter_id);
    for (std::list<std::pair<std::string, size_t>>::iterator i = pokemons_.begin();
         i != pokemons_.end(); i++)
    {
        if (i->second == std::next(i, 1)->second)//compare id
        {
            if (Shorter_name(*(std::next(i, 1)), *i))//compare name
                std::swap(*i, *(std::next(i, 1)));
        }
    }
}