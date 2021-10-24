#include <string>
#include <vector>
#include <iostream>

class Creature {
public:
    Creature(const std::string& name, const std::string& type, int hp)
        : name_(name), type_(type), hitpoints_(hp) { }

    const std::string& GetName() const { return name_; }
    const std::string& GetType() const { return type_; }
    int GetHitPoints() const { return hitpoints_; }
    virtual std::string WarCry() const { return "(nothing)"; }

private:
    std::string name_;
    const std::string type_;
    int hitpoints_;
};


class Troll : public Creature {
public:
    Troll(const std::string& name) : Creature(name, "Troll", 10) { }

    virtual std::string WarCry() const { return "Ugazaga!"; }
};


class Dragon : public Creature {
public:
    Dragon(const std::string& name) : Creature(name, "Dragon", 50) { }

    virtual std::string WarCry() const { return "Whoosh!"; }
};


int main() {
    Troll tr("Diiba");
    Dragon dr("Rhaegal");
    Dragon dr2("Viserion");

    std::vector<Creature*> monsters;
    monsters.push_back(&tr);
    monsters.push_back(&dr);
    monsters.push_back(&dr2);

    for (auto it : monsters) {
        std::cout << it->GetName() << " says: " << it->WarCry()
                << std::endl;
    }
}