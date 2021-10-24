#include "magic_dragon.hpp"

// Define MagicDragon's methods here

void MagicDragon::Eat(FoodListType &foodlist)
{
    for (FoodListType::iterator i=foodlist.begin();
            i!=foodlist.end(); i++)
        {
            if (i->type == Herbs)
            {
                size_++;
                i = foodlist.erase(i);
                std::cout << "Magic dragon ate: " << i->name << std::endl;
            }
        }
}

void MagicDragon::Hoard(TreasureListType &treasurelist)
{
    for (TreasureListType::iterator i = treasurelist.begin();
         i != treasurelist.end(); i++)
    {
        if (i->type == Potions)
        {
            treasure_list.push_back(*i);
            std::cout << "Magic dragon received: " <<\
            i->name << std::endl;
            i = treasurelist.erase(i);
        }
    }
}
