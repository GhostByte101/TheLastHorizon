// main.cpp
#include <iostream>
#include <string>
#include "wizard.h"
#include "knight.h"
#include "elf.h"
#include "common.h"
using namespace std;

int main()
{
    string name;
    cout << "Player please enter you name :" << endl;
    cin >> name;
    int c;

    cout << endl
         << "You open your eyes startled by the sound of something squeaking....." << endl
         << "Its dark and you can't properly distinguish the figure of something small..." << endl
         << "As your eyes adjust you realize its a small mouse." << endl
         << "You let out a sign of relief but it is short lived as you notice its no ordinary mouse but a demonic one with vicious big claws and red eyes." << endl
         << "You see a stick to your right.Instinctively you know you need to think quickly or you are a goner." << endl;

    waitForEnter();

    cout << "You need to choose between the two choices : " << endl
         << "1) Kill the mouse with the stick." << endl
         << "2)Run away." << endl;
    do
    {
        cin >> c;

        switch (c)
        {
        case 1:
        {
            cout << endl
                 << "Congratulations you have successfully killed the demonic mouse earning a dagger as reward." << endl
                 << "You have chosen the path of the warrior. Your quest begins now." << endl;
            break;
        }

        case 2:
        {
            cout << endl
                 << "You have choosen to run away from a mere demonic mouse. You may not be fit for the path of a warrior." << endl;

            break;
        }
        default:
            cout << "Choose either 1 or 2.";
            break;
        }
    } while (c != 1 && c != 2);

    cout << "HELLOOOO " << name << " !! The demon king has taken over the Kingdom of Avalon. The World has become infested with his minions and demon folk who roam everywhere wreaking havoc and killing everyone."
         << endl
         << "______________________________"
         << endl
         << "You are an ordinary human on a quest to save your kingdom from these evil forces ......Good luck on your journey.\n Sayonara "
         << endl
         << "______________________________";

    waitForEnter();

    cout << "Welcome to Avalon!\n"
         << "Choose your hero:\n"
         << "  1) Wizard\n"
         << "  2) Knight\n"
         << "  3) Elf\n"
         << "Enter 1, 2 or 3: ";
    int choice;

    cin >> choice;
    string p="no";
    do
    {
        switch (choice)
        {
        case 1:
            return wizardMain(); // hands off to your Wizard story
        case 2:
            return knightMain(); // hands off to your Knight story
        case 3:
            return elfMain(); // hands off to your Elf story
        default:
            cout << "Invalid selection, exiting.\n";
            return 1;
        }
        cin>>p;
    } while (p == "yes");
}

// g++ -std=c++17 main.cpp common.cpp wizard.cpp knight.cpp elf.cpp -Iinclude -o AvalonGame.exe