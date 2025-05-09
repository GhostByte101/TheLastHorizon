
#pragma once

#include <string>
using namespace std;



// Base Human class for Elf module
class Human1 {
protected:
    std::string name;
public:
    explicit Human1(const std::string &name);
    std::string getName() const;
    virtual void identity();
    virtual ~Human1() = default;
};

// Stats component for Elf module
class Stats1 {
protected:
    int health;
    int damage;
public:
    Stats1(int h, int d);
    int getHealth() const;
    int getDamage() const;
    void setHealth(int h);
    void setDamage(int d);
    void scaleDamage(int multiplier);
    virtual ~Stats1() = default;
};

// Elf character
class Elf1 : virtual public Human1, virtual public Stats1 {
public:
    Elf1(const std::string &n, int h, int d);
    void identity() override;
    int tripleArrows();
    const int total_health;
};

// Knight1 needed for ElvenKnight1
class Knight1 : virtual public Human1, virtual public Stats1 {
public:
    Knight1(const string &n, int h, int d);
    void identity() override;
};

// ElvenKnight1 combines Knight1 and Elf1
class ElvenKnight1 : public Knight1, public Elf1 {
public:
    ElvenKnight1(const std::string &n, int h, int d);
    void identity() override;
    int addition(int a);
    int addition(int a, int b);
};

// Enemy interface
class Enemy1 {
public:
    virtual void display() = 0;
    virtual ~Enemy1() = default;
};

// Goblin1 and Boss1
class Goblin1 : public Stats1, public Enemy1 {
public:
    Goblin1(int h, int d);
    void display() override;
};

class Boss1 : public Stats1, public Enemy1 {
public:
    Boss1(int h, int d);
    void display() override;
    int criticalDamage;
};

// Stage2 function
void Stage2(int choice, Elf1 &e1);

// Entry point for Elf module
int elfMain();