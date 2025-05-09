
#pragma once

#include <string>
using namespace std;



// Base Human class
class Human {
protected:
    string name;
public:
    explicit Human(const std::string &name);
    string getName() const;
    virtual void identity();
    virtual ~Human() = default;
};

// Stats component
class Stats {
protected:
    int health;
    int damage;
public:
    Stats(int h, int d);
    int getHealth() const;
    int getDamage() const;
    void setHealth(int h);
    void setDamage(int d);
    virtual ~Stats() = default;
};

// Knight character
class Knight : virtual public Human, virtual public Stats {
private:
    int Excalibur;
    int armour;
public:
    Knight(const std::string &n, int h, int d);
    void identity() override;
    int getExcalibur() const;
    int getArmor() const;
};

// Elf character
class Elf : virtual public Human, virtual public Stats {
public:
    Elf(const std::string &n, int h, int d);
    void identity() override;
};

// ElvenKnight combines Knight and Elf
class ElvenKnight : public Knight, public Elf {
public:
    ElvenKnight(const std::string &n, int h, int d);
    void identity() override;
    int addition(int a);
    int addition(int a, int b);
};

// Enemy interface
class Enemy {
public:
    virtual void display() = 0;
    virtual ~Enemy() = default;
};

// Various enemy types
class Goblin : public Stats, public Enemy {
public:
    Goblin(int h, int d);
    void display() override;
};
class Jackals : public Stats, public Enemy {
public:
    Jackals(int h, int d);
    void display() override;
};
class Boss : public Stats, public Enemy {
public:
    Boss(int h, int d);
    void display() override;
    int criticalDamage;
};
class Troll : public Stats, public Enemy {
public:
    Troll(int h, int d);
    void display() override;
};
class Demon : public Stats, public Enemy {
public:
    Demon(int h, int d);
    void display() override;
};

// Entry point for Knight module
int knightMain();