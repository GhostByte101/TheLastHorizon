
#include "knight.h"
#include "common.h"
#include <iostream>
using namespace std;

// Human implementations
Human::Human(const std::string &name) : name(name)
{
}
std::string Human::getName() const
{
    return name;
}
void Human::identity()
{
    std::cout << "I am a human" << std::endl;
}

// Stats implementations
Stats::Stats(int h, int d) : health(h), damage(d)
{
}
int Stats::getHealth() const
{
    return health;
}
int Stats::getDamage() const
{
    return damage;
}
void Stats::setHealth(int h)
{
    health = h;
}

//Stat implementation
void Stats::setDamage(int d)
{
    damage = d;
}

// Knight implementations
Knight::Knight(const std::string &n, int h, int d)
    : Human(n), Stats(h, d), Excalibur(10), armour(35)
{
}

void Knight::identity()
{
    std::cout << "I am a Knight." << std::endl;
}

int Knight::getExcalibur() const
{
    return Excalibur;
}

int Knight::getArmor() const
{
    return armour;
}

// Elf implementations
Elf::Elf(const string &n, int h, int d)
    : Human(n), Stats(h, d)
{
}

void Elf::identity()
{
    cout << "I am an Elf." << endl;
}

// ElvenKnight implementations
ElvenKnight::ElvenKnight(const std::string &n, int h, int d)

    : Human(n), Stats(h, d), Knight(n, h, d), Elf(n, h, d)
{
}

//ElvenKnight Implementation
void ElvenKnight::identity()
{
    cout << "I am an Elven Knight." << endl;
}
int ElvenKnight::addition(int a)
{
    return a;
}

int ElvenKnight::addition(int a, int b)
{ // function overloading
    return a + b;
}

// Enemy: Goblin
Goblin::Goblin(int h, int d) : Stats(h, d)
{
}
void Goblin::display()
{
    cout << "I am a goblin" << endl;
}

// Jackals
Jackals::Jackals(int h, int d) : Stats(h, d)
{
}
void Jackals::display()
{
    cout << "We are the jackal pack." << endl;
}

// Boss
Boss::Boss(int h, int d) : Stats(h, d), criticalDamage(12)
{
}
void Boss::display()
{
    cout << "I am the boss." << endl;
}

// Troll
Troll::Troll(int h, int d) : Stats(h, d)
{
}
void Troll::display()
{
    cout << "I am a troll." << endl;
}

// Demon
Demon::Demon(int h, int d) : Stats(h, d)
{
}
void Demon::display()
{
    cout << "I am the Demon King." << endl;
}

// Entry point
int knightMain()
{
    Knight k1("Knight", 65, 12);

    Goblin g1(14, 2);

    // Stage 1
    int q, w, e;
    cout << endl
         << "You wake up in a forest, you are dizzy and your head hurts as you try to remember what had happened..." << endl
         << "Slowly the mist over your brain lifts and you remember that you had been ambushed." << endl
         << "You get up and  see a goblin standing guard near you." << endl
         << "You feel around and you find a sword near you...." << endl
         << endl;
    waitForEnter();
    cout << "\033[1;36m";
    cout << "Your stats are: " << endl
         << "Health: " << k1.getHealth() << endl // showing the knight stats up front
         << "Damage: " << k1.getDamage() << endl;
    cout << "\033[0m";
    waitForEnter();
    cout << endl
         << "You have to decide: " << endl
         << "1. Do you fight?" << endl
         << "2. Do you run?" << endl
         << "Select one option: " << endl;
    cin >> q;

    if (q == 1)
    { // if #1
        cout << endl
             << "You get up and face the goblin." << endl
             << "His stats are: " << endl
             <<"\033[1;35m"
             << "Health: " << g1.getHealth() << endl // declaring the health for goblin
             << "Damage: " << g1.getDamage() << endl <<"\033[0m";

        waitForEnter();
        cout << "Do you attack him?" << endl
             << "1. Yes" << endl
             << "2. No" << endl
             << "Choose one" << endl;
        cin >> w;

        if (w == 1)
        { // if #2
            cout << endl
                 << "You attack him, he also retaliates" << endl;
                 cout<<"\033[1;31m"
                 << "Goblin's health: " << g1.getHealth() - k1.getDamage() << endl
                 << "Your health: " << k1.getHealth() - g1.getDamage() << endl;
                 cout<<"\033[0m";
            k1.setHealth(k1.getHealth() - g1.getDamage());

            cout << "You see the goblin is weak and you end him with a finishing blow." << endl;
        }
        else if (w == 2)
        { // if #2

            cout << endl
                 << "As you stare at the goblin, he attacks you twice." << endl;

            cout << "\033[1;31m";
            cout << "Your health now is: " << k1.getHealth() - 2 * (g1.getDamage()) << endl;
            cout << "\033[0m";
            k1.setHealth(k1.getHealth() - 2 * (g1.getDamage()));

            cout << "Adrenaline rushes through you and you stab the goblin straight through the heart and breath a sigh of releif" << endl;
        }
    }
    else if (q == 2)
    { // if #1

        cout << endl
             << "Whoops, you tried to run and the goblin saw you." << endl;

        cout << "The goblin runs behind you and stabs you twice." << endl;

        cout << "\033[1;31m";
        cout << "Your health now is: " << k1.getHealth() - 2 * (g1.getDamage()); // health 61
        cout << "\033[0m";

        k1.setHealth(k1.getHealth() - 2 * (g1.getDamage()));
        waitForEnter();
        cout << endl
             << "You turn around and fight." << endl
             << "After gaining your ground you manage to hit a blow." << endl
             << "Goblin's health: " << g1.getHealth() - k1.getDamage() << endl;

        cout << "You see he's weak so you kick him and run away...." << endl
             << endl;
    }

    waitForEnter();
    cout << "You are going to do a minigame now. GoodLuck!!!" << endl;
    if (MG2())
    {
    }
    else
    {
        cout << "Since you failed the minigame, you lose 2 health points." << endl;
        k1.setHealth(k1.getHealth() - 2);
        cout << "\033[1;31m";
        cout << "Your health now is: " << k1.getHealth() << endl
             << endl;
        cout << "\033[0m";
    }

    Boss b1(30, 7); // declares the boss for stage 1
    waitForEnter();
    cout << endl
         << "After killing the goblin, you breath a sigh of relief." << endl
         << "You try to find a way out of the forest. Suddenly you hear twigs snapping. You turn around to locate the source of the noise." << endl
         << "You finally spot a big shadow. You carefully creep forward and peek throught the bushes. It's a giant orc." << endl
         << "What do you do?" << endl;
    waitForEnter();
    cout << "1. You wait and watch?" << endl
         << "2. You burst out attacking?" << endl;
    cin >> q;

    if (q == 1)
    { // if #1

        cout << "You watch as the orc makes sniffing noises. Suddenly he gets up and walks away. You breath a sigh of relief." << endl
             << "Suddenly you are hurled across the forest as the orc kicks you. You let out a scream as you slam against a tree." << endl;
        cout << "\033[1;31m";
        k1.setHealth(k1.getHealth() - b1.criticalDamage);
        cout << "Your health: " << k1.getHealth() << endl;
        cout << "\033[0m";

        waitForEnter();

        cout << "You stand up to face the orc as he snarls." << endl;
        cout << "\033[1;35m";
        cout << "Orc's health: " << b1.getHealth() << endl // Orcs health
             << "Orc's damage: " << b1.getDamage() << endl // Orcs damage
             << endl;
        cout << "\033[0m";

        waitForEnter();

        cout << "'Come here you human filth', he says." << endl
             << "You stagger to you feet as you slightly hit the orc." << endl;
        b1.setHealth(b1.getHealth() - (k1.getDamage()) / 2);

        cout << "\033[1;35m";
        cout << "Orc's health: " << b1.getHealth() << "The orc seethes as you face a stand off." << endl;
        cout << "\033[0m";

        cout << "You have  a choice: " << endl
             << "1. Go for the killing blow." << endl
             << "2. Strategically fight him." << endl;

        cin >> w;

        if (w == 1)
        { // if else #2

            cout << "You charge towards the orc yelling 'For Gondor'. The orc surprised doesn't jump out in time and you sever his arm." << endl;
            b1.setHealth(b1.getHealth() - 2 * k1.getDamage());
            cout << "The orc yells in pain as he wildly swings his mace. It strikes you across the chest." << endl;
            k1.setHealth(k1.getHealth() - b1.getDamage());
            cout << "\033[1;31m";
            cout << "Your health: " << k1.getHealth() << endl;
            cout << "\033[0m";
            cout << "\033[1;35m";
            cout << "Orcs health: " << b1.getHealth() << endl;
            cout << "\033[0m";

            cout << "The orc staggers a little bit, before falling face down on the ground." << endl;
        }
        else if (w == 2)
        { // if else #2

            cout << "The orc snorts as he stares in your eyes." << endl
                 << "You stare right back, your blue eyes reflecting the moonlight that peeks through the trees." << endl
                 << "You circle each other for a while, sometimes closing in, sometimes creating a gap." << endl
                 << "Suddenly, the orc runs towards you as you step aside, slicing his right hand. He howls as he turns and charges you, throwing you down." << endl;
            k1.setHealth(k1.getHealth() - b1.getDamage());
            b1.setHealth(b1.getHealth() - k1.getDamage());

            cout << "\033[1;31m";

            cout << "Your health: " << k1.getHealth() << endl;

            cout << "\033[0m";

            cout << "\033[1;35m";

            cout << "Orcs health: " << b1.getHealth() << endl;

            cout << "\033[0m";

            waitForEnter();

            cout << "The orc stands over you, showing his yellow teeth as he smirks." << endl
                 << "In a last desperate attempt, you use your dagger to stab the orc in his thigh.You cut his femoral." << endl;
            b1.setHealth(b1.getHealth() - k1.getDamage());
            cout << "\033[1;31m";

            cout << "Your health: " << k1.getHealth() << endl;

            cout << "\033[0m";

            cout << "\033[1;35m";

            cout << "Orcs health: " << b1.getHealth() << endl;

            cout << "\033[0m";
            cout << "The orc hollers as he bleeds to death." << endl;
        }
    }
    else if (q == 2)
    { // else #1
        cout << "\033[1;35m";
        cout << "Orc's health: " << b1.getHealth() << endl // Orcs health
             << "Orc's damage: " << b1.getDamage() << endl // Orcs damage
             << endl;
        cout << "\033[0m";

        cout << "You yell as you burst out the trees, taking the orc by surprise." << endl
             << "You swing your sword, severing the orc's arm." << endl;

        b1.setHealth(b1.getHealth() - 2 * k1.getDamage());

        cout << "\033[1;35m";

        cout << "Orc's health: " << b1.getHealth() << endl;

        cout << "\033[0m";

        cout << endl
             << "In rage, the orc uses his right arm to hurl you across the forest. You slam against a tree and hit your head. You are stunned." << endl
             << "What do you do?" << endl;
        k1.setHealth(k1.getHealth() - 2 * b1.criticalDamage);

        cout << "\033[1;31m";

        cout << "Your health: " << k1.getHealth() << endl;

        cout << "\033[0m";

        waitForEnter();

        cout << "1. Stay down and recover your breath." << endl
             << "2. Get up immediately and attack the orc." << endl;
        cin >> w;

        if (w == 1)
        { // if else #3

            cout << endl
                 << "You pant as the orcs stomps towards you, raises his mace and aims it at your head." << endl
                 << "Scared, you move at the last second, so the mace hits your torso instead." << endl;

            k1.setHealth(k1.getHealth() - 2 * b1.getDamage());
            cout << "\033[1;31m";

            cout << "Your health: " << k1.getHealth() << endl;

            cout << "\033[0m";

            waitForEnter();

            cout << endl
                 << "You let out a scream as you roll and keep dodging the successive mace hits that the orc keeps on hitting." << endl
                 << "Finally you find your footing, and you get up." << endl
                 << "You swing your sword with all your might as you cut his other arm as well." << endl;

            b1.setHealth(b1.getHealth() - 0.5 * k1.getDamage());

            cout << "\033[1;35m";

            cout << "Orc's health: " << b1.getHealth() << endl;

            cout << "\033[1;32m";

            cout << "Congrats, the orc died." << endl;

            cout << "\033[0m";
        }
        else if (w == 2)
        { // if else #3
            cout << endl
                 << "With your head dizzy, you stumble and then duck as the orc swings his mace with the other arm." << endl
                 << "You get behind the orc and stab him in the back." << endl;
            b1.setHealth(b1.getHealth() - 0.5 * k1.getDamage());
            cout << "\033[1;35m";

            cout << "Orc's health: " << b1.getHealth() << endl;

            cout << "\033[1;32m";

            cout << "Congrats, the orc died." << endl;

            cout << "\033[0m";
        }
    }

    cout << "You breath a sigh of relief." << endl
         << "1. Do you want to rest?" << endl
         << "2. Do you want to walk?" << endl;
    cin >> q;

    if (q == 1)
    {

        cout << endl
             << "You have rested. You recovered some health." << endl;
        k1.setHealth(k1.getHealth() + 5);

        cout << "\033[1;32m";
        cout << "Your health: " << k1.getHealth() << endl; // Health is 64
        cout << "\033[0m";
    }
    else if (q == 2)
    {

        cout << endl
             << "You make your way across the uneven forest ground. Stumbling and falling sometimes." << endl; // what do i do with health?
        cout << "Since you are tired, you will have reduced damage." << endl;
        k1.setDamage(k1.getDamage() - 1);

        cout << "\033[1;31m";
        cout << "Your damage: " << k1.getDamage() << endl;
        cout << "\033[0m";

        waitForEnter();
    }

    cout << "After walking for some time, you see sunlight ahead. 'Finally I am gonna be out of this jungle', you think to yourself." << endl // 3 paths via portal
         << "Suddenly you are in a clearing and you see 3 paths. 'A fork in the road', you think to yourself." << endl;
    waitForEnter();
    cout << "Which path do you choose?" << endl
         << "1. The path to the left looks normal, well as normal as it can be comppared to the other two paths." << endl
         << "2. The path looks bright and flowery. 'A little too cheery for my commfort', you think to yourself." << endl
         << "3. The path to the right looks the most gloomy. 'The one which looks the worst usually isn't. Right?', says your internal monologue." << endl;
    cout << endl;
    waitForEnter();
    cout << "What will be your choice?" << endl
         << "There might be a surpise in one of the paths." << endl;

    do
    {
        cin >> e;

        switch (e)
        {
        case 1:
        {
            // stage 2
            cout << endl
                 << "You walk down the path. It seems fine for now. Suddenly you see the road ahead warping slighlty. Curious you approach it." << endl;
            waitForEnter();
            cout << "Suddenly you are pulled through what was apparently a portal.........." << endl;
            waitForEnter();
            cout << "You are transported to what looks like another forest. 'NOT AGAINNNN', you groan as you dust yourself off." << endl
                 << "You look around and you recognize the forest. It is the Giki forest! You heard stories about it in your world." << endl;
            waitForEnter();
            cout << "You explore the forest and you end up at TOGIK. Even more curoius now, you approach it and enter. In the middle you see a sword lodged in stone." << endl
                 << "'Not the Excalibur?' you think to yourself. You approach the sword. 'I dont have what it takes to take the sword out. Or do I?'" << endl
                 << "After contemplating, you walk up to the sword, grab the hilt, put one of your shoe on the rock and pull........" << endl;
            waitForEnter();
            cout << "Suprisingly, the sword gets out with relative ease." << endl;
            cout << "\033[1;32m";
            cout << endl
                 << "Congrats, you unlocked Excaliber! It can grant you extra damage when you use it." << endl
                 << "Damage of Excalibur: " << k1.getExcalibur() << endl;
            cout << "\033[0m"; // Health is 64 (Path )

            waitForEnter();
            cout << "Suddenly a portal opens under your feet and you are transported back to Middle Earth." << endl
                 << "You are back to your home in Edoras." << endl; // health 59
            waitForEnter();

            cout << "You are comfortable in your bed when you hear howling of the jackals. You hear the alarm bells calling soldiers to the defense of the Golden Hall." << endl
                 << "You get off your bed with a sigh. You get surprised when you see a large pack of jackals surrounding the city borders...." << endl;
            waitForEnter();

            Jackals j1(10, 3);
            cout << "You almost hear the feral jackals say: ";
            j1.display();
            cout << endl
                 << "You rotate the hilt of the sword in your hand as you ready a stance for battle." << endl;
            waitForEnter();
            cout << "\033[1;34m";
            cout << "Jackal's health: " << j1.getHealth() << endl
                 << "Jackal's damage: " << j1.getDamage() << endl;
            cout << "\033[0m";
            waitForEnter();
            cout << "5 jackals approach you, with the intent of surrounding you. What do you do?" << endl
                 << "1. Move back slowly towards a wall to prevent them surrounding you." << endl
                 << "2. Charge forward into a sudden attack that will prevent them from surrounding you but may have some jackals flank you." << endl;
            cin >> q;

            if (q == 1)
            { // if #1
                cout << "You look behind. The wall of the city isn't that far behind. You retreat slowly as the jackals growl, their mouths spilling saliva." << endl
                     << "Finally your back touches the wall. The jackals almost grinninng as they think about what fine meat you'll be." << endl;
                waitForEnter();

                cout << "One jackal stays in the middle while the two on each side move a little to the sides. Which way do you attack?" << endl
                     << "1. Straight ahead to the jackal in the middle." << endl
                     << "2. Towards on of the right side." << endl
                     << "3. Towards on of the left side." << endl;
                cin >> e;

                if (e == 1)
                { // if #2
                    cout << "You charge down the jackal in the middle. It barely has anytime to do anything before it gets taken down" << endl
                         << "The rest of the jackals bunch up behind you. As adrenaline rushes through you, you take them down one by one." << endl
                         << "Any jackal that has the misfortune of biting or slashing at you ends up dead." << endl;

                    k1.setHealth(k1.getHealth() - 4 * j1.getDamage());

                    cout << "\033[1;31m";

                    cout << "Your health at the end of the fight: " << k1.getHealth() << endl; // red colorrrr

                    cout << "\033[0m";

                    waitForEnter();

                    k1.setHealth(k1.getHealth() + k1.getArmor());

                    cout << "You go to the infirmary where you are patched up and you receive an armour for your valor. The armor is magical and it instantly heals you." << endl;
                    cout << "\033[1;32m";
                    cout << "You health after the buff: " << k1.getHealth() << endl; // greeen coloorrrrr
                    cout << "\033[0m";
                }
                else if (e == 2)
                { // else if #2
                    cout << "You leap to attack the jackals on the right side. The other 3 flank you and ready themselves to attack you from the behind." << endl;
                    k1.setHealth(k1.getHealth() - 3 * j1.getDamage());
                    cout << "\033[1;31m";
                    cout << "Your health: " << k1.getHealth() // red colorrrr
                         << "\033[0m" << endl;

                    waitForEnter();

                    cout << "Enraged you kill the first jackal by beheading it. The second you stab it in the chest." << endl
                         << "You turn towards the other three who now look a little scared but they try to put up a courageous front." << endl;

                    cout << "As you attack one of the jackal, one of the other two bites your leg while one your arm. You slash the jackal you were attacking and then kill the one biting your arm and kick the one gnawing at your leg" << endl
                         << "The jackal that was slashed whines as he bleeds to death." << endl;

                    k1.setHealth(k1.getHealth() - 2 * j1.getDamage());

                    waitForEnter();

                    cout << "One jackal remains." << endl
                         << "It leaps at you suddenly making you lose your balance. As you try to stand up, it slashes its paws across your chest" << endl
                         << "You take out a dagger and lodge it deep in its chest, putting it to permanent sleep." << endl;
                    waitForEnter();
                    cout << "\033[1;31m";
                    cout << "Your health at the end of the fight: " << k1.getHealth() << endl;
                    cout << "\033[0m";
                    waitForEnter();

                    k1.setHealth(k1.getHealth() + k1.getArmor());

                    cout << "You go to the infirmary where you are patched up and you receive an armour for your valor. The armor is magical and it instantly heals you." << endl;
                    cout << "\033[1;32m";
                    cout << "You health after the buff: " << k1.getHealth() << endl; // greeen coloorrrrr
                    cout << "\033[0m";
                }

                else
                { // else #2
                    cout << "You leap to attack the jackals on the left side. The other 3 flank you and ready themselves to attack you from the behind." << endl;
                    k1.setHealth(k1.getHealth() - 3 * j1.getDamage());
                    cout << "\033[1;31m";
                    cout << "Your health: " << k1.getHealth() << endl; // red colorrrr
                    cout << "\033[0m";

                    waitForEnter();

                    cout << "Enraged you kill the first jackal by beheading it. The second you stab it in the chest." << endl
                         << "You turn towards the other three who now look a little scared but they try to put up a courageous front." << endl;

                    cout << "As you attack one of the jackal, one of the other two bites your leg while one your arm. You slash the jackal you were attacking and then kill the one biting your arm and kick the one gnawing at your leg" << endl
                         << "The jackal that was slashed whines as he bleeds to death." << endl;
                    k1.setHealth(k1.getHealth() - 2 * j1.getDamage());
                    waitForEnter();
                    cout << "One jackal remains." << endl
                         << "It leaps at you suddenly making you lose your balance. As you try to stand up, it slashes its paws across your chest" << endl
                         << "You take out a dagger and lodge it deep in its chest, putting it to permanent sleep." << endl;
                    waitForEnter();

                    cout << "\033[1;34m";

                    cout << "Your health at the end of the fight: " << k1.getHealth() << endl;

                    cout << "\033[0m";

                    waitForEnter();
                    k1.setHealth(k1.getHealth() + k1.getArmor());
                    cout << "You go to the infirmary where you are patched up and you receive an armour for your valor. The armor is magical and it instantly heals you." << endl
                         << "\033[1;32m"
                         << "You health after the buff: " << k1.getHealth() << endl; // greeen coloorrr
                    cout << "\033[0m";
                }
            }
            else
            { // else #1
                cout << "You stand as the jackals form a circle around you." << endl
                     << "You suddenly charge in front as the other 4 leap from behind." << endl
                     << "Any jackal that has the misfortune of biting or slashing at you ends up dead, as every burn of the wound makes you angrier" << endl;

                k1.setHealth(k1.getHealth() - 4 * j1.getDamage());

                cout << "\033[1;31m";

                cout << "Your health at the end of the fight: " << k1.getHealth() << endl; // red colorrrr

                cout << "\033[0m";

                waitForEnter();

                k1.setHealth(k1.getHealth() + k1.getArmor());

                cout << "You go to the infirmary where you are patched up and you receive an armour for your valor. The armor is magical and it instantly heals you." << endl
                     << "\033[1;32m"
                     << "You health after the buff: " << k1.getHealth() << endl; // greeen coloorrr
                cout << "\033[0m";
            }

            // minigame
            if (MG1() == true)
            {

                cout << "You have connected everything correctly!" << endl;
                k1.setHealth(k1.getHealth() + 5);
                cout << "\033[1;32m";
                cout << "Your Health: " << k1.getHealth() << endl; // greeeen

                cout << "\033[0m";
            }
            else
            {

                cout << "You failed the minigame." << endl;

                k1.setHealth(k1.getHealth() - 2);

                cout << "\033[1;31m";

                cout << "Your Health: " << k1.getHealth() << endl;

                cout << "\033[0m";
            }

            Demon d1(50, 20); // Demon king

            // stage 2 boss

            cout << "You are sent the next day to figure out who sent the jackals. You track the jackal prints to a cave. You enter it wary of possible dannger." << endl
                 << "You hear a deep rumble deep in the cave. You carefully approach the source of the sound. You see a sight you hoped you wouldn't have seen." << endl;
            waitForEnter();

            cout << "\033[1;41m";
            cout << "You see a huge fiery demon with a molten crown on his head and enormmous wings that are being flexed." << endl
                 << endl
                 << "\033[1;37m"
                 << "IT IS THE DEMON KING HIMSELF...." << endl // some color
                 << "\033[0m";

            cout << "\033[1;31m";
            cout << "Demon King's Health: " << d1.getHealth() << endl
                 << "Demon King's Damage: " << d1.getDamage() << endl;
            cout << "\033[0m";

            cout << "What do you do?" << endl
                 << "1. Talk" << endl
                 << "2. Run" << endl;

            cin >> q;

            if (q == 1)
            { //  if #1

                cout << "You say 'Who goes there', in a feeble voice." << endl
                     << "The king replies, 'foolish mortal. Who dares tresspass on my land? Begone or prepare to meet your end!!'" << endl;
                waitForEnter();
                cout << "Do you continue talking or do you attack?" << endl
                     << "1. Continue to talk" << endl
                     << "2. Attack" << endl;
                cin >> w;

                if (w == 1)
                { // if #2

                    cout << "'Who are you?', you ask. 'I am the King of the demons, comes the reply. 'But since you are so insolent, prepare to die!'" << endl;
                    cout << "The king  attacks you. You try to dodge but fail. You take damage." << endl;
                    k1.setHealth(k1.getHealth() - 17);
                    cout << "You use Excalibur with full force to deal a counter blow." << endl;
                    d1.setHealth(d1.getHealth() - (k1.getExcalibur() + k1.getDamage()));
                    cout << "\033[1;31m";
                    cout << "Your Health: " << k1.getHealth() << endl
                         << "\033[1;35m"
                         << "Demon's Health: " << d1.getHealth() << endl
                         << "\033[0m";

                    cout << "You see the demon is reeling from the attack. So you attack him again and finish him." << endl; // continue to write a closure
                }
                else if (w == 2)
                { // if #2
                    cout << "Angered by the tone, you rush to attack him." << endl;
                    cout << "The king sees you coming and attacks you. You try to dodge but fail. You take damage." << endl;
                    k1.setHealth(k1.getHealth() - 17);
                    cout << "You use Excalibur with full force to deal a counter blow." << endl;
                    d1.setHealth(d1.getHealth() - (k1.getExcalibur() + k1.getDamage()));
                    cout << "\033[1;31m";
                    cout << "Your Health: " << k1.getHealth() << endl
                         << "\033[1;35m"
                         << "Demon's Health: " << d1.getHealth() << endl
                         << "\033[0m";

                    cout << "You see the demon is reeling from the attack. So you attack him again and finish him." << endl;
                }
            }
            else if (q == 2)
            { // else #1

                cout << "The demon king hears you run away. He chases behind you. You are hit with his giant hand." << endl
                     << "You go 'splat' against a wall." << endl;

                k1.setHealth(k1.getHealth() - 2 * d1.getDamage());

                if (k1.getHealth() != 0)
                {
                    cout << "\033[1;31m";
                    cout << "Your health: " << k1.getHealth();
                    cout << "\033[0m";

                    d1.setHealth(d1.getHealth() - (k1.getExcalibur() + k1.getDamage()));
                    cout << "You use Excalibur with all your might." << endl
                         << "\033[1;35m"
                         << "Demon king's health: " << d1.getHealth() << endl
                         << "\033[0m";

                    cout << "\033[1;41m";
                    cout << "Angry, the demon king smashes foot on your face, crushing it instantly...." << endl
                         << "You are dead. May you rest in peace in the Halls of Mandos...... :(" << endl;
                    cout << "\033[0m";
                }
                else
                {
                    cout << "\033[1;41m";
                    cout << "You died. :(" << endl; // color
                    cout << "\033[0m";
                }
            }

            break;
        }

        case 2:
        { // stage 2 (without Excalibur)

            Troll t1(20, 5); // Troll
            cout << "You walk down the jolly path. Your spirit lifted. You look around and enjoy the view. You look at the canopy of the trees. Suddenly your foot doesn't land om solid ground." << endl
                 << "Before you know it, you are falling down a wormhole. You realize you have stepped in a portal...." << endl; // wait for enter
            waitForEnter();
            cout << "You come out on the other side in the GIKafe. You have read about this place. You look at the trophies and admire them. You had read there was a secret hidden in one of the trophies." << endl
                 << "Before you have time to figure out the secret, a guard enters the cafe. Seeing your weird outfit and mistaking you for a intruder, he headshots you with his gun." << endl
                 << "You suddenly wake up with a jolt and are in the forest again. The jolly path and the experience in the GIKafe seeming like a dream." << endl;
            waitForEnter();

            cout << "You look around. There is a  cliff on your right side. You hear something big moving the trees." << endl
                 << "Suddenly a stone troll comes out of the trees. He almost walks past you but at the last second he looks down and sees you. You get up on your feet immediately." << endl;
            cout << "1. Do you immediately attack it?" << endl
                 << "2. Do you lure it into sunlight to weaken it and then ambush it." << endl;
            cin >> q;

            if (q == 1)
            { // if #1

                cout << "You charge, holding the blade up high. You swing as mightily as you can. You break your sword at impact to your dismay. The troll looks at you smugly." << endl
                     << "Suddenly it starts to break and crumble. You head for shelter as the troll breaks and large pieces of rock and boulders fall down..." << endl;
            }
            else if (q == 2)
            { // else #1

                cout << "To lure the troll, you throw a twig at it, getting its attention and making it roar and chase you." << endl
                     << "You run in a random direction, hoping to find some sunlight. Suddenly you come into a clearing." << endl
                     << "The troll screams as it tries to stop but ends up in the clearing anyway. Enraged it hits you." << endl;
                k1.setHealth(k1.getDamage() - 3);

                cout << "\033[1;31m";
                cout << "Your health: " << k1.getHealth() << endl;
                cout << "\033[0m";

                cout << "You slide across into the trees. You immediately get up and hide in the trees. This confuses the troll." << endl
                     << "You wait you chance to attack. As soon as you find it, you strike the back of the leg of the troll." << endl
                     << "This displaces enough rock for it to start breaking down. But as soon as you had hit the troll, the sword slid out of your hand and fell underneath the breaking troll, making it unaccessible for you." << endl
                     << "Sighing, you dust yourself off and you walk away with a slight limp." << endl;
            }

            if (MG3() == true)
            {
                cout << "You have solved the puzzle correctly!" << endl;
                k1.setHealth(k1.getHealth() + 3);
                cout << "\033[1;32m";
                cout << "You gain some health. Your health: " << k1.getHealth() <<endl;
                cout << "\033[0m";
            }
            else
            {
                cout << "You failed to unscramble the words." << endl
                     << "You lose some health." << endl;
                k1.setHealth(k1.getHealth() - 2);
                cout << "\033[1;31m";
                cout << "Your health: " << k1.getHealth() << endl;
                cout << "\033[0m";
            }

            Demon d2(50, 20);

            cout << "You keep on walking for a while till you come up upon a temple." << endl
                 << "It's bright golden dome, whose sheen has faded with years of erosion feels menacing." << endl
                 << "You being curious as usual, go inside..." << endl;
            waitForEnter();

            cout << "\033[1;41m";
            cout << "You see a giant altar." << endl
                 << "The demon king rises from it. He has a huge sword and a scepter in each of his hands." << "\033[0m"
                 << endl;

            cout << "\033[1;37m";
            cout << "Demon King's Health: " << d2.getHealth() << endl
                 << "Demon King's Damage: " << d2.getDamage() << endl;
            cout << "\033[0m";

            cout << "What do you do?" << endl
                 << "1. Go around?" << endl
                 << "2. Attack." << endl;

            cin >> q;

            if (q == 1)
            { // if #1
                cout << "You try to sneak around the altar, but the demon king spots you and charges at you." << endl
                     << "You are forced to fight him." << endl
                     << "You barely have enough time to react before you are kicked against the wall." << endl;
                waitForEnter();
                cout << "You barely have time to catch your breath befor you feel a foot against your chest." << endl
                     << "The last thing you hear is the cracking of your ribs before you breath your last." << endl;
            }
            else if (q == 2)
            { // else #1
                cout << "You run at the demon king. He barely has any time to raise his scepter and call 3 blood hounds." << endl
                     << "You have a choice: " << endl
                     << "1. Disarm his sword" << endl
                     << "2. Seize his scepter" << endl;

                cin >> w;

                if (w == 1)
                { // if else 2

                    cout << "You deflect the sword that the demon king swings at you. Your vambrace cracks as it withstands the force." << endl

                         << "However you still receive a cut on your arm as the sword goes flying out of the demon king's hand." << endl;
                    k1.setHealth(k1.getHealth() - d2.getDamage());
                    cout << "\033[1;31m";
                    cout << "Your Health: " << k1.getHealth() << endl;
                    cout << "\033[0m";
                    cout << "You pick up the sword that fell from the demon king's hand. You use the sword to kill the 3 blood hounds." << endl;
                    cout << "You then use the sword to cut the sceptre in half and then behead the demon king." << endl;

                    cout << "\033[1;32m";
                    cout << "Congratulations you win!!!" << endl; // color
                    cout << "\033[0m";
                }
                else if (w == 2)
                { // if else 2
                    cout << "You roll on the floor to dodge the sword attack and wrench the sceptre out of his hand." << endl
                         << "You turn the power of the demon king against him." << endl
                         << "There is a shockwave which sends the sword of the demon king flying and getting lodged in his chest." << endl
                         << "As the demon king screams in pain, the blood hounds start eating him alive." << endl;

                    cout << "\033[1;32m";
                    cout << "Congratulations you win!!!" << endl; // color
                    cout << "\033[0m";
                }
            }

            break;
        }

        case 3:
        {
            cout << "You walk down the gloomy path. Regretting your choice." << endl
                 << "Suddenly you fall down a hole and end u falling into a portal that lands you in front of LOGIK." << endl
                 << "You have read about this place in your books, its history and all." << endl;
            waitForEnter();
            cout << "You see the lower door of the LOGIK is open for you to go inside and climb the stairs." << endl
                 << "You climb the precarious and twisty stairs carefully." << endl
                 << "As soon as you reach the top you lose your balance and fall all the way down...." << endl;
            waitForEnter();
            cout << "You suddenly wake up, the fall and everything feeling like a dream..." << endl;
            cout << "You look around. There is a  cliff on your right side. You hear something big moving the trees." << endl
                 << "Suddenly a stone troll comes out of the trees. He almost walks past you but at the last second he looks down and sees you. You get up on your feet immediately." << endl;
            cout << "1. Do you immediately attack it?" << endl
                 << "2. Do you lure it into sunlight to weaken it and then ambush it." << endl;
            cin >> q;

            if (q == 1)
            { // if #1

                cout << "You charge, holding the blade up high. You swing as mightily as you can. You break your sword at impact to your dismay. The troll looks at you smugly." << endl
                     << "Suddenly it starts to break and crumble. You head for shelter as the troll breaks and large pieces of rock and boulders fall down..." << endl;
            }
            else if (q == 2)
            { // else #1

                cout << "To lure the troll, you throw a twig at it, getting its attention and making it roar and chase you." << endl
                     << "You run in a random direction, hoping to find some sunlight. Suddenly you come into a clearing." << endl
                     << "The troll screams as it tries to stop but ends up in the clearing anyway. Enraged it hits you." << endl;
                k1.setHealth(k1.getDamage() - 3);

                cout << "\033[1;31m";
                cout << "Your health: " << k1.getHealth() << endl;
                cout << "\033[0m";

                cout << "You slide across into the trees. You immediately get up and hide in the trees. This confuses the troll." << endl
                     << "You wait you chance to attack. As soon as you find it, you strike the back of the leg of the troll." << endl
                     << "This displaces enough rock for it to start breaking down. But as soon as you had hit the troll, the sword slid out of your hand and fell underneath the breaking troll, making it unaccessible for you." << endl
                     << "Sighing, you dust yourself off and you walk away with a slight limp." << endl;
            }

            if (MG3() == true)
            {
                cout << "You have solved the puzzle correctly!" << endl;
                k1.setHealth(k1.getHealth() + 3);
                cout << "\033[1;32m";
                cout << "You gain some health. Your health: " << k1.getHealth();
                cout << "\033[0m";
            }
            else
            {
                cout << "You failed to unscramble the words." << endl
                     << "You lose some health." << endl;
                k1.setHealth(k1.getHealth() - 2);
                cout << "\033[1;31m";
                cout << "Your health: " << k1.getHealth() << endl;
                cout << "\033[0m";
            }

            Demon d2(50, 20);

            cout << "You keep on walking for a while till you come up upon a temple." << endl
                 << "It's bright golden dome, whose sheen has faded with years of erosion feels menacing." << endl
                 << "You being curious as usual, go inside..." << endl;
            waitForEnter();

            cout << "\033[1;41m";
            cout << "You see a giant altar." << endl
                 << "The demon king rises from it. He has a huge sword and a scepter in each of his hands." << endl;
            cout << "\033[1;37m";
            cout << "Demon King's Health: " << d2.getHealth() << endl
                 << "Demon King's Damage: " << d2.getDamage() << endl;
            cout << "\033[0m";

            cout << "What do you do?" << endl
                 << "1. Go around?" << endl
                 << "2. Attack." << endl;

            cin >> q;

            if (q == 1)
            { // if #1
                cout << "You try to sneak around the altar, but the demon king spots you and charges at you." << endl
                     << "You are forced to fight him." << endl
                     << "You barely have enough time to react before you are kicked against the wall." << endl;
                waitForEnter();
                cout << "You barely have time to catch your breath befor you feel a foot against your chest." << endl
                     << "The last thing you hear is the cracking of your ribs before you breath your last." << endl;
            }
            else if (q == 2)
            { // else #1
                cout << "You run at the demon king. He barely has any time to raise his scepter and call 3 blood hounds." << endl
                     << "You have a choice: " << endl
                     << "1. Disarm his sword" << endl
                     << "2. Seize his scepter" << endl;

                cin >> w;

                if (w == 1)
                { // if else 2

                    cout << "You deflect the sword that the demon king swings at you. Your vambrace cracks as it withstands the force." << endl

                         << "However you still receive a cut on your arm as the sword goes flying out of the demon king's hand." << endl;
                    k1.setHealth(k1.getHealth() - d2.getDamage());
                    cout << "\033[1;31m";
                    cout << "Your Health: " << k1.getHealth() << endl;
                    cout << "\033[0m";
                    cout << "You pick up the sword that fell from the demon king's hand. You use the sword to kill the 3 blood hounds." << endl;
                    cout << "You then use the sword to cut the sceptre in half and then behead the demon king." << endl;

                    cout << "\033[1;32m";
                    cout << "Congratulations you win!!!" << endl; // color
                    cout << "\033[0m";
                }
                else if (w == 2)
                { // if else 2
                    cout << "You roll on the floor to dodge the sword attack and wrench the sceptre out of his hand." << endl
                         << "You turn the power of the demon king against him." << endl
                         << "There is a shockwave which sends the sword of the demon king flying and getting lodged in his chest." << endl
                         << "As the demon king screams in pain, the blood hounds start eating him alive." << endl;

                    cout << "\033[1;32m";
                    cout << "Congratulations you win!!!" << endl; // color
                    cout << "\033[0m";
                }
            }

            break;
        }

        default:
            cout << "Invalid choice, choose again." << endl;
            break;
        }
    } // while (e != 1 && e != 2 && e != 3);
    while (e != 1 && e != 2 && e != 3);

    ElvenKnight ek1("Elven Knight 101", 800, 80);
    waitForEnter();
    cout<<"Testing the diamond problem." <<endl;
    ek1.identity();
    cout << endl
         << "Show casing overloading: " << ek1.addition(5);
    cout << endl
         << "Show casing overloading:" << ek1.addition(5, 10);

    return 0; // Copy your original main() body here
}
