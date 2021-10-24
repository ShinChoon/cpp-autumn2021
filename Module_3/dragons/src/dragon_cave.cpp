#include "dragon_cave.hpp"

// Define DragonCave's methods here


DragonCave::~DragonCave(){
    for(auto i : dragonlist){
        delete i;
    }
    // dragonlist.clear();
}

const DragonListType &DragonCave::GetDragons() const
{
    return dragonlist;
}
void DragonCave::Accommodate(Dragon *dragon)
{
    dragonlist.push_back(dragon);
}
void DragonCave::Evict(const std::string &draname)
{
    for (DragonListType::iterator i = dragonlist.begin(); 
            i!= dragonlist.end(); i++)
        {
            if ((*i)->GetName() == draname)
            {
                i = dragonlist.erase(i);
                break;

            }
        
        }
}

std::ostream& operator<<(std::ostream& out, const DragonCave& drac){
    out << "DragonCave dwellers:" << std::endl;
    for (auto i : drac.GetDragons())
    {
        
        out << std::endl;
        out << *i;
    }
    return out;
}

