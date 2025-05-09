#include "Common.h"
#include <iostream>
using namespace std;

void waitForEnter()
{
    cout << "\033[1;33m" << "\n[Press Enter to continue...]\n"

         << "\033[0m";

    cin.ignore();
    cin.get();
}
bool MG1()
{
    string b1 = "Banana", m1 = "Moneky", r1 = "Rabbit", c1 = "Carrot", p1 = "Pony", a1 = "Apple";
    cout << endl;

    cout << p1 << "   --------------- " << c1 << endl;
    cout << r1 << " --------------- " << b1 << endl;
    cout << m1 << " --------------- " << a1 << endl;
    cout << endl;

    cout << "Match the following pairs" << endl;
    cout << endl;

    cout << "Monkey is going to match with??" << endl;
    cin >> m1;
    cout << endl;

    cout << "Pony is going to match with??" << endl;
    cin >> p1;
    cout << endl;

    cout << "Rabbit is going to match with??" << endl;
    cin >> r1;
    cout << endl;

    if ((m1 == "Banana" || m1 == "banana") && (r1 == "Carrot" || r1 == "carrot") && (p1 == "Apple" || p1 == "apple"))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool MG2()
{
    int x, y, z, i1, i2, i3;
    x = 87;
    y = 52;
    z = 102;
    cout << endl;

    cout << "Please find the sum of " << x << " and " << y << endl;
    cin >> i1;
    cout << endl;

    if ((i1 == 139))
    {
        cout << "Please find the sum of " << z << " and " << y << endl;
        cin >> i2;
        cout << endl;

        if ((i2 == 154))
        {
            cout << "Please find the difference of " << z << " and " << x << endl;
            cin >> i3;
            cout << endl;

            if ((i3 == 15))
            {
                cout << "You pass the test!" << endl
                     << "You know your maths!" << endl
                     << endl;

                return true;
            }
            else
            {
                cout << "Should have paid attention in the first grade!" << endl
                     << endl;
                return false;
            }
        }
        else
        {
            cout << "Should have paid attention in the first grade!" << endl
                 << endl;
            return false;
        }
    }
    else
    {
        cout << "Should have paid attention in the first grade!" << endl
             << endl;
        return false;
    }
}
bool MG3()
{
    string s4, s5, s6, s7;
    string s1 = "mporgnimrag"; // programming
    string s2 = "mage";        // game
    string s3 = "gocnid";      // coding
    string s8 = "abl";         // lab

    cout <<"Welcome to the minigame where you unscramble the words." <<endl <<"Unscramble this word: " << s1 << endl
         << endl;
    cin >> s4;

    if (s4 == "programming")
    {

        cout << "Unscramble this word: " << s2 << endl
             << endl;
        cin >> s5;
        if (s5 == "game")
        {
            cout << "Unscramble this word: " << s3 << endl
                 << endl;
            cin >> s6;
            if (s6 == "coding")
            {
                cout << "Unscramble this word: " << s8 << endl
                     << endl;
                cin >> s7;
                if (s7 == "lab")
                {
                    cout << "You are CORRECT!!!" << endl
                         << endl;
                    return true;
                }
                else
                {
                    cout << "You are wrong, please try again." << endl
                         << endl;
                    return false;
                }
            }
            else
            {
                cout << "You are wrong, please try again." << endl
                     << endl;
                return false;
            }
        }
        else
        {
            cout << "You are wrong, please try again." << endl
                 << endl;
            return false;
        }
    }
    else
    {
        cout << "You are wrong, please try again." << endl
             << endl;
        return false;
    }
    return true;
}
