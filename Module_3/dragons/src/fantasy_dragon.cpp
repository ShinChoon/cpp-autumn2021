#include "fantasy_dragon.hpp"

// Define FantasyDragon's methods here


void FantasyDragon::Eat(FoodListType& foodlist)
{

    for (FoodListType::iterator i=foodlist.begin();
            i!=foodlist.end(); i++)
        {
        if ((i->type == People)
            || (i->type == PeopleFood))
            {
                this->size_++;
                i=foodlist.erase(i);
                std::cout << "Fantasy dragon ate: " << i->name << std::endl;
            }
    }

}

void FantasyDragon::Hoard(TreasureListType &treasurelist)
{
    for (TreasureListType::iterator i = treasurelist.begin();
         i != treasurelist.end(); i++)
    {
        if (i->type == Jewellery){
            treasure_list.push_back(*i);
            std::cout << "Fantasy dragon received: " <<\
            i->name << std::endl;
            i = treasurelist.erase(i);
        }

    }
}