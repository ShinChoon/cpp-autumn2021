#include "dragon.hpp"

/*
 * GetName: the function returns a constant reference to the Dragon's name and takes
 * no parameters. This function does not change the state of the Dragon object, i.e.
 * the function should be const.
 */
const std::string& Dragon::GetName()const{
    return name_;
}


/* 
 * GetAge: the function returns the Dragon's age as a size_t and takes no parameters. 
 * This function does not change the state of the Dragon object, i.e. the function 
 * should be const.
 */
size_t Dragon::GetAge()const{
    return age_;
}
 /* 
 * GetSize: the function returns the Dragon's size as a size_t and takes no parameters.
 * This function does not change the state of the Dragon object, i.e. the function 
 * should be const.
 *
  */
size_t Dragon::GetSize()const
{
    return size_;
}

/*
 * 
 * GetTreasures: the function returns a constant reference to the Dragon's treasures list
 * and takes no parameters. This function does not change the state of the Dragon object, 
 * i.e. the function should be const.
 *
  */

const TreasureListType &Dragon::GetTreasures()const
{
    return treasure_list;
}

std::ostream& operator<<(std::ostream &out, const Dragon &dragon)
{
    out << "Dragon named: " << dragon.GetName() << ", age: " << dragon.GetAge()
        << ", size: " << dragon.GetSize() << std::endl;
    out << "Treasures:" << std::endl;
    for (auto i : dragon.GetTreasures())
    {
        out << i.name << std::endl;
    }
    return out;
}
/* TODO: operator <<
 * Description:
 * An overloaded << stream operator for printing Dragons to an parameter ostream.
 * The dragon should be printed to the parameter ostream in the following format:
Dragon named: <Dragon's name>, age: <Dragon's age>, size: <Dragon's size>\n
Treasures:\n
<First Treasure's name in the Dragon's treasures list>\n
<Second Treasure's name in the Dragon's treasures list>\n
...
<Last Treasure's name in the Dragon's treasures list>\n
 * ------------
 * Parameters:
 * - a reference to the output stream where the information is printed (ostream&).
 * - Dragon whose information should be printed (const Dragon&).
 * ------------
 * Returns:
 * A reference to the output stream given as a parameter.
 */