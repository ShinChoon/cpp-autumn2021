#pragma once

#include <string>
#include <list>
#include <iostream>

/* Enumeration types for the different treasures */
enum TreasureType {
  Jewellery,
  Wisdom,
  Potions
};

/* Implementation of Treasure */
struct Treasure {
  TreasureType type;
  std::string name;
};

/* Enumeration types for the different foods */
enum FoodType {
  PeopleFood,
  People,
  Herbs
};

/* Implementation of Food */
struct Food {
  FoodType type;
  std::string name;
};


/* TODO: class Dragon
 * ------------
 * Description:
 * An abstract class that describes a dragon. Each Dragon object has a name (string), 
 * age (size_t), size (size_t) and a list of Treasure objects that the Dragon has
 * hoarded.
 * ------------
 */
typedef std::list<Treasure> TreasureListType;
typedef std::list<Food> FoodListType; 

class Dragon{
/*  Functions:
* 
* The constructor takes the Dragon's name (const std::string&), age (size_t) and 
* size (size_t) as a parameter and intializes them to the parameter values.
*/
  public:
    Dragon(const std::string &name, \
          size_t age, size_t size) : name_(name), \
          age_(age), size_(size) {}
/* 
* Destructor: Think about how it should be implemented!
*/
    Dragon(const Dragon&) = delete;
    Dragon& operator=(const Dragon&)= delete;
    virtual ~Dragon()=default;
    const std::string &GetName()const;
    size_t GetAge()const;
    size_t GetSize()const;
    const TreasureListType& GetTreasures()const;

/*
* 
* Eat: a pure virtual function, which returns nothing and takes a reference to a list of
* Food objects as a parameter.
*
* 
* Hoard: a pure virtual function, which returns nothing and takes a reference to a list of
* Treasure objects as a parameter.
* ------------
*/
    virtual void Eat(FoodListType& food_list) = 0;
    virtual void Hoard(TreasureListType& treasure_list) = 0;

/*
* Other:
* The class has the following protected members, which means they are accessible to classes
* which inherit this class: name (std::string), age (size_t), size (size_t), treasures 
* (std::list<Treasure>).
*/

  protected:
    TreasureListType treasure_list;
    std::string name_;
    size_t age_;
    size_t size_;
};

std::ostream& operator<<(std::ostream& out, const Dragon& dragon);
