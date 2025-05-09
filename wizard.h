
#pragma once

#include <string>
using namespace std;




// Abstract enemy interface
class Enemy2 {
public:
    virtual void display() = 0;
    virtual ~Enemy2() = default;
};

// Boss enemy implementation
class Boss2 : public Enemy2 {
private:
    int e_hp;
    int e_damage;
public:
    Boss2(int a, int b);
    void set_Bhp(int a);
    void set_Bdamage(int a);
    int get_bhp() const;
    int get_bdamage() const;
    void i_Bhp(int a);
    void d_Bhp(int a);
    void i_Bd(int a);
    void d_Bd(int a);
    void display() override;
};

// Base human class
class Human2 {
private:
    std::string name;
public:
    explicit Human2(const std::string &name);
    std::string getName() const;
    virtual void identity();
    virtual ~Human2() = default;
};

// Stats component
class stats2 {
private:
    int current_hp;
    int damage;
    int mana;
public:
    stats2(int chp, int d);
    void set_hp(int chp);
    int get_chp() const;
    void increase_hp(int i_hp);
    void decrease_hp(int d_hp);
    void set_damage(int d);
    int get_damage() const;
    void increase_damage(int inc_d);
    void decrease_damage(int dec_d);
    void set_Mana(int mana);
    int get_mana() const;
    void increase_mana(int m);
    void decrease_mana(int m);
};

// Wizard character
class Wizard2 : public Human2, public stats2 {
private:
    int blackhole;
public:
    Wizard2(const std::string &n, int h, int d);
    std::string get_name() const;
    int play();
};

// main entrypoint
int wizardMain();
