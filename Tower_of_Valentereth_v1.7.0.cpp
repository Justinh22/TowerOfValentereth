#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
#include <Windows.h>
#include <bits/stdc++.h>
#include <sstream>
#include <fstream>
#include <conio.h>
using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::vector;
using std::setw;
#include "AchievementHandler.h"
Achievements ach;
int score = 0;
bool godMode = 0;
int karma = 5;
int end = 0;
int pass = 1;
int shortWait = 1000;
int midWait = 2000;
int longWait = 3000;
#include "ItemClasses.h"
#include "ItemList.h"
#include "CreatureList.h"
#include "SpellList.h"
#include "FeatureList.h"
#include "RoomList.h"
//#include "MapList.h"
#include "RoomGen.h"
#include "MenuIllustrations.h"
#include "InteractionHandler.h"
#include "EncounterHandler.h"
#include "RoomLogic.h"
#include "CombatHandler.h"
#include "GoldPicker.h"
#include "SaveFunctions.h"

int actionHandler(string act,bool debug_opt, int gankTracker);  //Done!
int menuHandler(Player &hero,Directory dir); //Done!
int storeMenuHandler(Player &hero,Directory dir,Room &currentRoom);
Room advance(int &depth, bool &itemDrop, int &adv, int &diff, int &rew, int &karma, Player &hero, int &pass, bool &win, Directory dir, int &boss, vector<bool> &mStatus, vector<bool> &rStatus, vector<bool> &reStatus, vector<bool> &iStatus, bool &dev);
int throneDefense(Player &hero, Directory dir, bool debug_opt, bool &gankTracker);

void clear()
{
    std::system("cls");
}

int main()
{
    vector<Weapon> weaponDirectory;
    vector<Armor> armorDirectory;
    vector<Consumable> consumableDirectory;
    vector<Item> maskDirectory;
    vector<AttackSpell> attackSpellDirectory;
    vector<HealingSpell> healingSpellDirectory;
    vector<BuffSpell> buffSpellDirectory;
    vector<Creature> creatureDirectory;
    vector<Feature> featureDirectory;
    vector<Room> roomDirectory;
    vector<Ring> ringDirectory;
    //vector<vector<vector<char>>> mapDirectory;

    weaponDirectory = initWDir(weaponDirectory);
    armorDirectory = initADir(armorDirectory);
    consumableDirectory = initCDir(consumableDirectory);
    maskDirectory = initMDir(maskDirectory);
    attackSpellDirectory = initASDir(attackSpellDirectory);
    healingSpellDirectory = initHSDir(healingSpellDirectory);
    buffSpellDirectory = initBSDir(buffSpellDirectory);
    creatureDirectory = initCDir(creatureDirectory);
    featureDirectory = initFDir(featureDirectory);
    roomDirectory = initRDir(roomDirectory,featureDirectory);
    ringDirectory = initRGDir(ringDirectory);
    //mapDirectory = initMapDir(mapDirectory);
    Directory dir(weaponDirectory,armorDirectory,consumableDirectory,maskDirectory,attackSpellDirectory,healingSpellDirectory,buffSpellDirectory,creatureDirectory,featureDirectory,roomDirectory,ringDirectory);

    string strChoice;
    char chChoice;
    int intChoice;
    int mask=-1;
    bool debug_opt=0;
    bool good=0;
    bool men;
    vector<int> startingItems;
    int startingItem = -1;
    int meleeProficiency = -1;
    int magicProficiency = -1;
    bool alreadyLearned = 0;
    //int mapx=171;
    //int mapy=39;
    bool floorFlag=0;
    while(good==0)
    {
        clear();
        titleScreen();
        strChoice = getch();
        std::stringstream stoi(strChoice);
        stoi >> intChoice;
        if(intChoice==1||intChoice==2)
        {
            good = 1;
        }
        if(intChoice==3)
        {
            men = 0;
            while(men==0)
            {
                valeTrade(ach);
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice==1)
                {
                    while(men==0)
                    {
                        ach.writeAchievements();
                        valeUnlockables(ach);
                        strChoice = getch();
                        std::stringstream stoi(strChoice);
                        stoi >> intChoice;
                        if(intChoice==1)
                        {
                            if(ach.UnlockSword==0)
                            {
                                cout << "Would you like to spend 50 Vale to unlock this? (y/n)" << endl;
                                strChoice = getch();
                                if(strChoice=="y")
                                {
                                    if(ach.Vale<50)
                                    {
                                        cout << "You cannot afford this." << endl;
                                        Sleep(midWait);
                                    }
                                    else
                                    {
                                        ach.Vale -= 50;
                                        cout << "You can now choose to start an ascent with a Crooked Saber!" << endl;
                                        Sleep(midWait);
                                        ach.UnlockSword = 1;
                                    }
                                }
                            }
                            if(ach.UnlockSword==1)
                            {
                                cout << "Start this ascent with a Crooked Saber? You can only start an ascent with one of these items at a time. (y/n)" << endl;
                                strChoice = getch();
                                if(strChoice=="y")
                                {
                                    cout << "You will start your next ascent with a Crooked Saber!" << endl;
                                    startingItem = 5;
                                    Sleep(midWait);
                                }
                            }
                        }
                        else if(intChoice==2)
                        {
                            if(ach.UnlockArmor==0)
                            {
                                cout << "Would you like to spend 50 Vale to unlock this? (y/n)" << endl;
                                strChoice = getch();
                                if(strChoice=="y")
                                {
                                    if(ach.Vale<50)
                                    {
                                        cout << "You cannot afford this." << endl;
                                        Sleep(midWait);
                                    }
                                    else
                                    {
                                        ach.Vale -= 50;
                                        cout << "You can now choose to start an ascent with Leather Armor!" << endl;
                                        Sleep(midWait);
                                        ach.UnlockArmor = 1;
                                    }
                                }
                            }
                            if(ach.UnlockArmor==1)
                            {
                                cout << "Start this ascent with Leather Armor? You can only start an ascent with one of these items at a time. (y/n)" << endl;
                                strChoice = getch();
                                if(strChoice=="y")
                                {
                                    cout << "You will start your next ascent with Leather Armor!" << endl;
                                    startingItem = 103;
                                    Sleep(midWait);
                                }
                            }
                        }
                        else if(intChoice==3)
                        {
                            if(ach.UnlockJolt==0)
                            {
                                cout << "Would you like to spend 80 Vale to unlock this? (y/n)" << endl;
                                strChoice = getch();
                                if(strChoice=="y")
                                {
                                    if(ach.Vale<80)
                                    {
                                        cout << "You cannot afford this." << endl;
                                        Sleep(midWait);
                                    }
                                    else
                                    {
                                        ach.Vale -= 80;
                                        cout << "You can now choose to start an ascent with Jolt!" << endl;
                                        Sleep(midWait);
                                        ach.UnlockJolt = 1;
                                    }
                                }
                            }
                            if(ach.UnlockJolt==1)
                            {
                                cout << "Start this ascent with Jolt? You can only start an ascent with one of these items at a time. (y/n)" << endl;
                                strChoice = getch();
                                if(strChoice=="y")
                                {
                                    cout << "You will start your next ascent with Jolt!" << endl;
                                    startingItem = 300;
                                    Sleep(midWait);
                                }
                            }
                        }
                        else if(intChoice==4)
                        {
                            if(ach.UnlockHeal==0)
                            {
                                cout << "Would you like to spend 80 Vale to unlock this? (y/n)" << endl;
                                strChoice = getch();
                                if(strChoice=="y")
                                {
                                    if(ach.Vale<80)
                                    {
                                        cout << "You cannot afford this." << endl;
                                        Sleep(midWait);
                                    }
                                    else
                                    {
                                        ach.Vale -= 80;
                                        cout << "You can now choose to start an ascent with Minor Heal!" << endl;
                                        Sleep(midWait);
                                        ach.UnlockHeal = 1;
                                    }
                                }
                            }
                            if(ach.UnlockHeal==1)
                            {
                                cout << "Start this ascent with Minor Heal? You can only start an ascent with one of these items at a time. (y/n)" << endl;
                                strChoice = getch();
                                if(strChoice=="y")
                                {
                                    cout << "You will start your next ascent with Minor Heal!" << endl;
                                    startingItem = 315;
                                    Sleep(midWait);
                                }
                            }
                        }
                        else if(intChoice==5)
                        {
                            if(ach.UnlockHealingPot==0)
                            {
                                cout << "Would you like to spend 80 Vale to unlock this? (y/n)" << endl;
                                strChoice = getch();
                                if(strChoice=="y")
                                {
                                    if(ach.Vale<80)
                                    {
                                        cout << "You cannot afford this." << endl;
                                        Sleep(midWait);
                                    }
                                    else
                                    {
                                        ach.Vale -= 80;
                                        cout << "You can now choose to start an ascent with a Potion of Healing!" << endl;
                                        Sleep(midWait);
                                        ach.UnlockHealingPot = 1;
                                    }
                                }
                            }
                            if(ach.UnlockHealingPot==1)
                            {
                                cout << "Start this ascent with a Potion of Healing? You can only start an ascent with one of these items at a time. (y/n)" << endl;
                                strChoice = getch();
                                if(strChoice=="y")
                                {
                                    cout << "You will start your next ascent with a Potion of Healing!" << endl;
                                    startingItem = 204;
                                    Sleep(midWait);
                                }
                            }
                        }
                        else if(intChoice==6)
                        {
                            if(ach.UnlockCalmingPot==0)
                            {
                                cout << "Would you like to spend 80 Vale to unlock this? (y/n)" << endl;
                                strChoice = getch();
                                if(strChoice=="y")
                                {
                                    if(ach.Vale<80)
                                    {
                                        cout << "You cannot afford this." << endl;
                                        Sleep(midWait);
                                    }
                                    else
                                    {
                                        ach.Vale -= 80;
                                        cout << "You can now choose to start an ascent with a Potion of Calming!" << endl;
                                        Sleep(midWait);
                                        ach.UnlockCalmingPot = 1;
                                    }
                                }
                            }
                            if(ach.UnlockCalmingPot==1)
                            {
                                cout << "Start this ascent with a Potion of Calming? You can only start an ascent with one of these items at a time. (y/n)" << endl;
                                strChoice = getch();
                                if(strChoice=="y")
                                {
                                    cout << "You will start your next ascent with a Potion of Calming!" << endl;
                                    startingItem = 205;
                                    Sleep(midWait);
                                }
                            }
                        }
                        else if(intChoice==7)
                        {
                            if(ach.UnlockMelee==0)
                            {
                                cout << "Would you like to spend 150 Vale to unlock this? (y/n)" << endl;
                                strChoice = getch();
                                if(strChoice=="y")
                                {
                                    if(ach.Vale<150)
                                    {
                                        cout << "You cannot afford this." << endl;
                                        Sleep(midWait);
                                    }
                                    else
                                    {
                                        ach.Vale -= 150;
                                        cout << "You can now choose to start an ascent with a Weapon Proficiency!" << endl;
                                        Sleep(midWait);
                                        ach.UnlockMelee = 1;
                                    }
                                }
                            }
                            if(ach.UnlockMelee==1)
                            {
                                cout << "Which weapon would you like to be proficient in?" << endl;
                                cout << "1) Daggers" << endl;
                                cout << "2) Spears" << endl;
                                cout << "3) Swords" << endl;
                                cout << "4) Axes" << endl << endl;
                                strChoice = getch();
                                if(strChoice=="1")
                                {
                                    cout << "You will start your next ascent with dagger proficiency!" << endl;
                                    meleeProficiency = 0;
                                    Sleep(midWait);
                                }
                                if(strChoice=="2")
                                {
                                    cout << "You will start your next ascent with spear proficiency!" << endl;
                                    meleeProficiency = 1;
                                    Sleep(midWait);
                                }
                                if(strChoice=="3")
                                {
                                    cout << "You will start your next ascent with sword proficiency!" << endl;
                                    meleeProficiency = 2;
                                    Sleep(midWait);
                                }
                                if(strChoice=="4")
                                {
                                    cout << "You will start your next ascent with axe proficiency!" << endl;
                                    meleeProficiency = 3;
                                    Sleep(midWait);
                                }
                            }
                        }
                        else if(intChoice==8)
                        {
                            if(ach.UnlockMagic==0)
                            {
                                cout << "Would you like to spend 150 Vale to unlock this? (y/n)" << endl;
                                strChoice = getch();
                                if(strChoice=="y")
                                {
                                    if(ach.Vale<150)
                                    {
                                        cout << "You cannot afford this." << endl;
                                        Sleep(midWait);
                                    }
                                    else
                                    {
                                        ach.Vale -= 150;
                                        cout << "You can now choose to start an ascent with an Elemental Proficiency!" << endl;
                                        Sleep(midWait);
                                        ach.UnlockMagic = 1;
                                    }
                                }
                            }
                            if(ach.UnlockMagic==1)
                            {
                                cout << "Which element would you like to be proficient in?" << endl;
                                cout << "1) Frost" << endl;
                                cout << "2) Fire" << endl;
                                cout << "3) Lightning" << endl << endl;
                                strChoice = getch();
                                if(strChoice=="1")
                                {
                                    cout << "You will start your next ascent with frost proficiency!" << endl;
                                    magicProficiency = 0;
                                    Sleep(midWait);
                                }
                                if(strChoice=="2")
                                {
                                    cout << "You will start your next ascent with fire proficiency!" << endl;
                                    magicProficiency = 1;
                                    Sleep(midWait);
                                }
                                if(strChoice=="3")
                                {
                                    cout << "You will start your next ascent with lightning proficiency!" << endl;
                                    magicProficiency = 2;
                                    Sleep(midWait);
                                }
                            }
                        }
                        else if(intChoice==9)
                        {
                            if(ach.UnlockRing==0)
                            {
                                cout << "Would you like to spend 150 Vale to unlock this? (y/n)" << endl;
                                strChoice = getch();
                                if(strChoice=="y")
                                {
                                    if(ach.Vale<150)
                                    {
                                        cout << "You cannot afford this." << endl;
                                        Sleep(midWait);
                                    }
                                    else
                                    {
                                        ach.Vale -= 150;
                                        cout << "You can now choose to start an ascent with a Minor-Level Ring!" << endl;
                                        Sleep(midWait);
                                        ach.UnlockRing = 1;
                                    }
                                }
                            }
                            if(ach.UnlockRing==1)
                            {
                                cout << "Which ring would you like to start with?" << endl;
                                cout << "1) Minor Regeneration" << endl;
                                cout << "2) Minor Conservation" << endl;
                                cout << "3) Minor Bravery" << endl;
                                cout << "4) Minor Leeching" << endl;
                                cout << "5) Minor Vengeance" << endl;
                                cout << "6) Minor Sight" << endl;
                                cout << "7) Minor Piercing" << endl;
                                cout << "8) Minor Overcharging" << endl;
                                cout << "9) Minor Reflection" << endl;
                                cout << "0) Minor Fury" << endl;
                                strChoice = getch();
                                if(strChoice=="1")
                                {
                                    cout << "You will start your next ascent with a Ring of Minor Regeneration!" << endl;
                                    startingItem = 400;
                                }
                                if(strChoice=="2")
                                {
                                    cout << "You will start your next ascent with a Ring of Minor Conservation!" << endl;
                                    startingItem = 401;
                                }
                                if(strChoice=="3")
                                {
                                    cout << "You will start your next ascent with a Ring of Minor Bravery!" << endl;
                                    startingItem = 402;
                                }
                                if(strChoice=="4")
                                {
                                    cout << "You will start your next ascent with a Ring of Minor Leeching!" << endl;
                                    startingItem = 403;
                                }
                                if(strChoice=="5")
                                {
                                    cout << "You will start your next ascent with a Ring of Minor Vengeance!" << endl;
                                    startingItem = 404;
                                }
                                if(strChoice=="6")
                                {
                                    cout << "You will start your next ascent with a Ring of Minor Sight!" << endl;
                                    startingItem = 405;
                                }
                                if(strChoice=="7")
                                {
                                    cout << "You will start your next ascent with a Ring of Minor Piercing!" << endl;
                                    startingItem = 406;
                                }
                                if(strChoice=="8")
                                {
                                    cout << "You will start your next ascent with a Ring of Minor Overcharging!" << endl;
                                    startingItem = 407;
                                }
                                if(strChoice=="9")
                                {
                                    cout << "You will start your next ascent with a Ring of Minor Reflection!" << endl;
                                    startingItem = 408;
                                }
                                if(strChoice=="0")
                                {
                                    cout << "You will start your next ascent with a Ring of Minor Fury!" << endl;
                                    startingItem = 409;
                                }
                                Sleep(midWait);
                            }
                        }
                        else if(intChoice==0)
                        {
                            men = 1;
                        }
                        else
                        {
                            cout << "Invalid command." << endl;
                            Sleep(midWait);
                        }
                    }
                    men = 0;
                }
                else if(intChoice==2)
                {
                    while(men==0)
                    {
                        ach.writeAchievements();
                        valeOneTime(ach);
                        strChoice = getch();
                        std::stringstream stoi(strChoice);
                        stoi >> intChoice;
                        if(intChoice==1)
                        {
                            cout << "Would you like to spend 30 Vale to start this run with an Iron Sword? (y/n)" << endl;
                            strChoice = getch();
                            if(strChoice=="y")
                            {
                                if(ach.Vale<30)
                                {
                                    cout << "You cannot afford this." << endl;
                                    Sleep(midWait);
                                }
                                else
                                {
                                    ach.Vale -= 30;
                                    cout << "You will start the next ascent with an Iron Sword!" << endl;
                                    Sleep(midWait);
                                    startingItems.push_back(10);
                                }
                            }
                        }
                        else if(intChoice==2)
                        {
                            cout << "Would you like to spend 30 Vale to start this run with Hide Armor? (y/n)" << endl;
                            strChoice = getch();
                            if(strChoice=="y")
                            {
                                if(ach.Vale<30)
                                {
                                    cout << "You cannot afford this." << endl;
                                    Sleep(midWait);
                                }
                                else
                                {
                                    ach.Vale -= 30;
                                    cout << "You will start the next ascent with Hide Armor!" << endl;
                                    Sleep(midWait);
                                    startingItems.push_back(106);
                                }
                            }
                        }
                        else if(intChoice==3)
                        {
                            cout << "Would you like to spend 20 Vale to start this run with Thunderbolt? (y/n)" << endl;
                            strChoice = getch();
                            if(strChoice=="y")
                            {
                                alreadyLearned = 0;
                                for(int i=0;i<startingItems.size();i++)
                                    if(startingItems[i]==303)
                                        alreadyLearned = 1;
                                if(ach.Vale<20)
                                {
                                    cout << "You cannot afford this." << endl;
                                    Sleep(midWait);
                                }
                                else if(!alreadyLearned)
                                {
                                    ach.Vale -= 20;
                                    cout << "You will start the next ascent with Thunderbolt!" << endl;
                                    Sleep(midWait);
                                    startingItems.push_back(303);
                                }
                                else
                                {
                                    cout << "You can't bring duplicates of the same spell." << endl;
                                    Sleep(midWait);
                                }
                            }
                        }
                        else if(intChoice==4)
                        {
                            cout << "Would you like to spend 40 Vale to start this run with Lightning Strike? (y/n)" << endl;
                            strChoice = getch();
                            if(strChoice=="y")
                            {
                                alreadyLearned = 0;
                                for(int i=0;i<startingItems.size();i++)
                                    if(startingItems[i]==306)
                                        alreadyLearned = 1;
                                if(ach.Vale<40)
                                {
                                    cout << "You cannot afford this." << endl;
                                    Sleep(midWait);
                                }
                                else if(!alreadyLearned)
                                {
                                    ach.Vale -= 40;
                                    cout << "You will start the next ascent with Lightning Strike!" << endl;
                                    Sleep(midWait);
                                    startingItems.push_back(306);
                                }
                                else
                                {
                                    cout << "You can't bring duplicates of the same spell." << endl;
                                    Sleep(midWait);
                                }
                            }
                        }
                        else if(intChoice==5)
                        {
                            cout << "Would you like to spend 40 Vale to start this run with Minor Regenerate? (y/n)" << endl;
                            strChoice = getch();
                            if(strChoice=="y")
                            {
                                alreadyLearned = 0;
                                for(int i=0;i<startingItems.size();i++)
                                    if(startingItems[i]==317)
                                        alreadyLearned = 1;
                                if(ach.Vale<40)
                                {
                                    cout << "You cannot afford this." << endl;
                                    Sleep(midWait);
                                }
                                else if(!alreadyLearned)
                                {
                                    ach.Vale -= 40;
                                    cout << "You will start the next ascent with Minor Regenerate!" << endl;
                                    Sleep(midWait);
                                    startingItems.push_back(317);
                                }
                                else
                                {
                                    cout << "You can't bring duplicates of the same spell." << endl;
                                    Sleep(midWait);
                                }
                            }
                        }
                        else if(intChoice==6)
                        {
                            cout << "Would you like to spend 30 Vale to start this run with a Potion of Healing? (y/n)" << endl;
                            strChoice = getch();
                            if(strChoice=="y")
                            {
                                if(ach.Vale<30)
                                {
                                    cout << "You cannot afford this." << endl;
                                    Sleep(midWait);
                                }
                                else
                                {
                                    ach.Vale -= 30;
                                    cout << "You will start the next ascent with a Potion of Healing!" << endl;
                                    Sleep(midWait);
                                    startingItems.push_back(204);
                                }
                            }
                        }
                        else if(intChoice==7)
                        {
                            cout << "Would you like to spend 30 Vale to start this run with a Potion of Calming? (y/n)" << endl;
                            strChoice = getch();
                            if(strChoice=="y")
                            {
                                if(ach.Vale<30)
                                {
                                    cout << "You cannot afford this." << endl;
                                    Sleep(midWait);
                                }
                                else
                                {
                                    ach.Vale -= 30;
                                    cout << "You will start the next ascent with a Potion of Calming!" << endl;
                                    Sleep(midWait);
                                    startingItems.push_back(205);
                                }
                            }
                        }
                        else if(intChoice==8)
                        {
                            cout << "Would you like to spend 30 Vale to start this run with a Blast Bomb? (y/n)" << endl;
                            strChoice = getch();
                            if(strChoice=="y")
                            {
                                if(ach.Vale<30)
                                {
                                    cout << "You cannot afford this." << endl;
                                    Sleep(midWait);
                                }
                                else
                                {
                                    ach.Vale -= 30;
                                    cout << "You will start the next ascent with a Blast Bomb!" << endl;
                                    Sleep(midWait);
                                    startingItems.push_back(216);
                                }
                            }
                        }
                        else if(intChoice==9)
                        {
                            cout << "Would you like to spend 80 Vale to start this run with a Second Soul? (y/n)" << endl;
                            strChoice = getch();
                            if(strChoice=="y")
                            {
                                if(ach.Vale<80)
                                {
                                    cout << "You cannot afford this." << endl;
                                    Sleep(midWait);
                                }
                                else
                                {
                                    ach.Vale -= 80;
                                    cout << "You will start the next ascent with a Second Soul!" << endl;
                                    Sleep(midWait);
                                    startingItems.push_back(216);
                                }
                            }
                        }
                        else if(intChoice==0)
                        {
                            men = 1;
                        }
                        else
                        {
                            cout << "Invalid command." << endl;
                            Sleep(midWait);
                        }
                    }
                    men = 0;
                }
                else if(intChoice==0)
                {
                    men = 1;
                }
                else
                {
                    cout << "Invalid command." << endl;
                    Sleep(midWait);
                }
            }
        }
        if(intChoice==4)
        {
            men = 0;
            while(men==0)
            {
                scores();
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice==0)
                    men = 1;
            }
        }
        if(intChoice==5)
        {
            men = 0;
            while(men==0)
            {
                achievementMenu();
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice==0)
                    men = 1;
            }
        }
        if(intChoice==6)
        {
            men = 0;
            while(men==0)
            {
                maskSelect();
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice>0&&intChoice<9)
                {
                    cout << dir.maskDirectory[intChoice-1].getName() << " | " << dir.maskDirectory[intChoice-1].getDesc() << endl;
                    cout << "Take the mask? (y/n)" << endl;
                    strChoice = getch();
                    if(strChoice=="y")
                    {
                        mask = dir.maskDirectory[intChoice-1].getID();
                        cout << "You put on the " << dir.maskDirectory[intChoice-1].getName() << "." << endl;
                        Sleep(midWait);
                    }
                }
                else if(intChoice==9)
                {
                    if(mask>=0)
                    {
                        mask = -1;
                        cout << "You removed your mask." << endl;
                        Sleep(midWait);
                    }
                    else
                    {
                        cout << "You aren't wearing a mask." << endl;
                        Sleep(midWait);
                    }
                }
                else if(intChoice==0)
                {
                    men = 1;
                }
                else
                {
                    cout << "Invalid command." << endl;
                    Sleep(midWait);
                }
            }
        }
        if(intChoice==8)
        {
            cout << "Debug mode activated.";
            Sleep(midWait);
            debug_opt = 1;
        }
        /*if(intChoice==9)
        { //Test sim
            /*for(int i=0;i<mapDirectory[2].size();i++)
            {
                for(int j=0;j<mapDirectory[2][i].size();j++)
                    cout << mapDirectory[2][i][j];
                cout << endl;
            }
            getch();
            while(1==1)
            {
                clear();
                mapDirectory[0][mapy][mapx] = '@';
                cout << "X----------------X" << endl;
                for(int i=mapy-4;i<mapy+4;i++)
                {
                    cout << "|";
                    for(int j=mapx-8;j<mapx+8;j++)
                        cout << mapDirectory[0][i][j];
                    cout << "|" << endl;
                }
                cout << "X----------------X" << endl << endl;
                cout << "Navigate with arrow keys." << endl;
                cout << "Press any key to type commands." << endl << endl;
                chChoice = getch();
                if(!isalpha(chChoice))
                {
                    switch(getch())
                    {
                        case 'H':    // key up
                            if(!floorFlag)
                                mapDirectory[0][mapy][mapx] = ' ';
                            else
                            {
                                mapDirectory[0][mapy][mapx] = '_';
                                floorFlag = 0;
                            }
                            if(mapDirectory[0][mapy-1][mapx] == ' ')
                                mapy--;
                            break;
                        case 'P':    // key down
                            if(!floorFlag)
                                mapDirectory[0][mapy][mapx] = ' ';
                            else
                            {
                                mapDirectory[0][mapy][mapx] = '_';
                                floorFlag = 0;
                            }
                            if(mapDirectory[0][mapy+1][mapx] == ' '||mapDirectory[0][mapy+1][mapx] == '_')
                            {
                                if(mapDirectory[0][mapy+1][mapx] == '_')
                                    floorFlag = 1;
                                mapy++;
                            }
                            else if(mapDirectory[0][mapy][mapx] == '_')
                                floorFlag = 1;
                            break;
                        case 'M':    // key right
                            if(!floorFlag)
                                mapDirectory[0][mapy][mapx] = ' ';
                            else
                            {
                                mapDirectory[0][mapy][mapx] = '_';
                                floorFlag = 0;
                            }
                            if(mapDirectory[0][mapy][mapx+1] == ' '||mapDirectory[0][mapy][mapx+1] == '_')
                            {
                                if(mapDirectory[0][mapy][mapx+1] == '_')
                                    floorFlag = 1;
                                mapx++;
                            }
                            break;
                        case 'K':    // key left
                            if(!floorFlag)
                                mapDirectory[0][mapy][mapx] = ' ';
                            else
                            {
                                mapDirectory[0][mapy][mapx] = '_';
                                floorFlag = 0;
                            }
                            if(mapDirectory[0][mapy][mapx-1] == ' '||mapDirectory[0][mapy][mapx-1] == '_')
                            {
                                if(mapDirectory[0][mapy][mapx-1] == '_')
                                    floorFlag = 1;
                                mapx--;
                            }
                            break;
                    }
                }
                else
                    cin >> strChoice;
            }
        }*/
    }

    string name;
    string filename;
    int saveStats[30];
    int roomData[15];
    int randEncCount = 15;
    vector<bool> randEncStatus(randEncCount,0);
    vector<int> saveFList;
    vector<int> saveIList;
    vector<int> saveBList;
    vector<bool> itemStatus{0,0,0,0,0,0};
    int depth = 1;
    string save;
    string saveName;
    string load="a";
    int saveCheck;
    int foo;
    bool saveFound=0;
    vector<int> equipSave;
    vector<int> itemSave;
    vector<int> spellSave;

    if(intChoice==1)
    {
        cout << "Name your character: ";
        cin >> name;
        filename = "Saves/" + name + ".txt";
        saveStats[0] = 1;
        saveStats[1] = 0;
        saveStats[2] = 0;
        saveStats[3] = 20;
        saveStats[4] = 20;
        saveStats[5] = 20;
        saveStats[6] = 20;
        saveStats[7] = 5;
        saveStats[8] = 0;
        saveStats[9] = 70;
        saveStats[10] = 0;
        saveStats[11] = 0;
        saveStats[12] = 0;
        saveStats[13] = 1;
        saveStats[14] = 0;
        saveStats[15] = 0;
        saveStats[16] = meleeProficiency;
        saveStats[17] = magicProficiency;
        saveStats[18] = -1;
        saveStats[19] = -1;
        saveStats[20] = -1;
        saveStats[21] = -1;
        saveStats[22] = 0;
        saveStats[23] = 0;
        saveStats[24] = 0;
        saveStats[25] = 0;
        saveStats[26] = 0;
        saveStats[27] = 0;
        saveStats[28] = 0;
        saveStats[29] = 0;
    }
    else if(intChoice==2)
    {
        good = 0;
        while(good==0)
        {
            clear();
            cout << "Your name was: ";
            cin >> name;
            saveFound = 0;
            filename = "Saves/" + name + ".txt";
            std::ifstream savedata(filename);
            if(savedata)
            {
                cout << "Save data found!" << endl;
                int line=0;
                while(std::getline(savedata,save))
                {
                    std::stringstream data(save);
                    saveFound = 1;
                    if(line==0)
                    {
                        for(int i=0;i<30;i++)
                            data >> saveStats[i];
                        for(int i=0;i<6;i++)
                        {
                            data >> saveCheck;
                            if(saveCheck==-1)
                                break;
                            equipSave.push_back(saveCheck);
                        }
                        for(int i=0;i<6;i++)
                        {
                            data >> saveCheck;
                            if(saveCheck==-1)
                                break;
                            itemSave.push_back(saveCheck);
                        }
                        while(1==1)
                        {
                            data >> saveCheck;
                            if(saveCheck==-1)
                                break;
                            spellSave.push_back(saveCheck);
                        }
                    }
                    else if(line==1)
                    {
                        data >> roomData[0];
                        if(roomData[0]==-1)
                            break;
                        while(1==1)
                        {
                            data >> saveCheck;
                            if(saveCheck==-1)
                                break;
                            saveFList.push_back(saveCheck);
                        }
                        while(1==1)
                        {
                            data >> saveCheck;
                            if(saveCheck==-1)
                                break;
                            saveIList.push_back(saveCheck);
                        }
                        while(1==1)
                        {
                            data >> saveCheck;
                            if(saveCheck==-1)
                                break;
                            saveBList.push_back(saveCheck);
                        }
                        for(int i=0;i<6;i++)
                        {
                            data >> saveCheck;
                            itemStatus[i] = saveCheck>0;
                        }
                        for(int i=1;i<15;i++)
                            data >> roomData[i];
                    }
                    else if(line==2)
                    {
                        for(int i=0;i<randEncCount;i++)
                        {
                            data >> saveCheck;
                            randEncStatus[i] = saveCheck;
                        }
                    }
                    line++;
                }
                cout << "Name: " << name << endl;
                cout << "Level: " << saveStats[0] << endl;
                cout << "EXP: " << saveStats[1] << endl;
                cout << "Gold: " << saveStats[2] << endl;
                cout << "HP: " << saveStats[3] << "/" << saveStats[4] << endl;
                cout << "MP: " << saveStats[5] << "/" << saveStats[6] << endl;
                cout << "ATK: " << saveStats[7] << endl;
                cout << "CRT: " << saveStats[8] << endl;
                cout << "ACC: " << saveStats[9] << endl;
                cout << "DEF: " << saveStats[10] << endl;
                cout << "DDG: " << saveStats[11] << endl;
                cout << "LCK: " << saveStats[12] << endl;
                cout << "ROOM: " << saveStats[13] << endl;
                cout << "KEYS: " << saveStats[14] << endl;
                cout << "SCORE: " << saveStats[29] << endl;
                if(saveStats[18]>=0)
                {
                    cout << "MASK: " << dir.maskDirectory[saveStats[18]].getName() << endl << endl;
                }
                cout << "Continue with this character? (y/n)" << endl;
                load = getch();
                if(load=="y")
                    good = 1;
                else
                {
                    equipSave.clear();
                    itemSave.clear();
                    spellSave.clear();
                }
            }
            else
            {
                cout << "Could not locate save data. Create new character with this name? (y/n)" << endl;
                load = getch();
                if(load=="y")
                {
                    saveStats[0] = 1;
                    saveStats[1] = 0;
                    saveStats[2] = 0;
                    saveStats[3] = 20;
                    saveStats[4] = 20;
                    saveStats[5] = 20;
                    saveStats[6] = 20;
                    saveStats[7] = 5;
                    saveStats[8] = 0;
                    saveStats[9] = 70;
                    saveStats[10] = 0;
                    saveStats[11] = 0;
                    saveStats[12] = 0;
                    saveStats[13] = 1;
                    saveStats[14] = 0;
                    saveStats[15] = 0;
                    saveStats[16] = meleeProficiency;
                    saveStats[17] = magicProficiency;
                    saveStats[18] = -1;
                    saveStats[19] = -1;
                    saveStats[20] = -1;
                    saveStats[21] = -1;
                    saveStats[22] = 0;
                    saveStats[23] = 0;
                    saveStats[24] = 0;
                    saveStats[25] = 0;
                    saveStats[26] = 0;
                    saveStats[27] = 0;
                    saveStats[28] = 0;
                    saveStats[29] = 0;
                    good = 1;
                }
                else
                {
                    clear();
                    good = 0;
                }
            }
        }
    }
    clear();

    Player hero(name,saveStats[0],100,saveStats[4],saveStats[6],saveStats[7],saveStats[9],saveStats[8],saveStats[10],saveStats[11],saveStats[12],saveStats[2],saveStats[14],saveStats[1]);
    hero.setEXPGoal(20*hero.level);
    hero.setHP(saveStats[3]);
    hero.setMP(saveStats[5]);
    if(saveStats[15]==1)
        hero.growth = 1;
    if(saveStats[18]>=0)
        mask = saveStats[18];
    if(intChoice==2)
    {
        hero.equipment = equipSave;
        hero.inventory = itemSave;
        hero.spellbook = spellSave;
    }
    depth = saveStats[13];
    hero.meleeTraining = saveStats[16];
    hero.magicTraining = saveStats[17];
    score = saveStats[29];
    if(depth>55)
        hero.empowered = 1;
    if(saveStats[19]!=-1)
        hero.equipWpn(dir.weaponDirectory[saveStats[19]]);
    if(saveStats[20]!=-1)
        hero.equipAmr(dir.armorDirectory[saveStats[20]-100]);
    if(saveStats[21]!=-1)
        hero.equipRng(dir.ringDirectory[saveStats[21]-400]);

    if(mask>=0)
    {
        hero.mask = dir.maskDirectory[mask];
    }

    if(hero.getNDDG()==0&&hero.mask.getID()==5) //Whispers
        hero.setNDDG(10);
    if(hero.mask.getID()==7) //Souls
        hero.setACC(hero.getNACC());
    srand(time(NULL));
    string action;
    string target;

    int err = 0;
    int diff = 0;
    int rew = 5;
    int adv = (depth / 5) + 1;
    if(adv>10)
        adv = 10;
    int menuval;
    int gd;
    int ex;
    int dmg;
    string text;

    Room currentRoom;
    vector<bool> minibossStatus{saveStats[22]>=1,saveStats[23]>=1,saveStats[24]>=1,saveStats[25]>=1,saveStats[26]>=1,saveStats[27]>=1,saveStats[28]>=1};
    vector<bool> roomStatus(100,0);
    int boss = 0;
    bool win = 0;
    bool lvup = 0;
    char yn;
    bool manSave = 0;
    bool dev=0;
    bool itemDrop=0;
    bool gankTracker=1;
    int boxType=-1;
    bool saveLog=0;
    int itemIndex = 0;
    int throneDefensePoints = 0;

    if(!saveFound)
    {
        if(startingItem!=-1)
            startingItems.push_back(startingItem);
        for(int i=0;i<startingItems.size();i++)
        {
            if((startingItems[i]<200||(startingItems[i]<500&&startingItems[i]>=400))&&hero.equipment.size()<=6)
                hero.equipment.push_back(startingItems[i]);
            else if((startingItems[i]>=200&&startingItems[i]<300)&&hero.inventory.size()<=6)
                hero.inventory.push_back(startingItems[i]);
            else if(startingItems[i]>=300&&startingItems[i]<400)
                hero.spellbook.push_back(startingItems[i]);
        }
    }

    if(!saveFound)
    {
        std::system("cls");
        cout << "Word has been passed for centuries of a tower at the far edge of the land, filled with monsters, riches, and power unimaginable." << endl;
        Sleep(shortWait);
        cout << "At the heart of the tower waits a tyrant with god-like power, who calls themself Valentereth." << endl;
        Sleep(shortWait);
        cout << "Several people from your village have left for the tower, seeking the treasures within, but none have returned." << endl << endl;
        Sleep(shortWait);
        cout << "Now, you have gone to the tower, ";
        switch(hero.mask.getID())
        {
            case 0:
                cout << "brimming with dangerous power, ";
                break;
            case 1:
                cout << "filled with uncontrollable rage, ";
                break;
            case 2:
                cout << "blind to the trials that await you, ";
                break;
            case 3:
                cout << "magic coursing through your veins, ";
                break;
            case 4:
                cout << "with immovable and unbreakable will, ";
                break;
            case 5:
                cout << "silent like the night, ";
                break;
            case 6:
                cout << "hungry for battle, ";
                break;
            case 7:
                cout << "compelled by the voices within, ";
                break;
        }
        cout << "hoping to brave the horrors within to find the treasure and power foretold." << endl << endl;
        Sleep(shortWait);
        cout << "Press any key to begin your ascent of the tower." << endl;
        action = getch();
        std::system("cls");
        cout << "Room " << depth << endl << endl;
        currentRoom = roomGenerator(diff,rew,adv,dir,hero,minibossStatus,roomStatus);
    }
    else
    {
        if(roomData[0]==-1)
        {
            std::system("cls");
            cout << "Room " << depth << endl << endl;
            currentRoom = roomGenerator(diff,rew,adv,dir,hero,minibossStatus,roomStatus);
        }
        else //LOAD ROOM
        {
            //cout << "Loading room..." << endl;
            currentRoom.setID(roomData[0]);
            currentRoom.setDesc(dir.roomDirectory[roomData[0]].getDesc());
            for(int i=0;i<saveFList.size();i++)
                currentRoom.flist.push_back(dir.featureDirectory[saveFList[i]]);
            for(int i=0;i<saveIList.size();i++)
                currentRoom.ilist.push_back(saveIList[i]);
            for(int i=0;i<saveBList.size();i++)
            {
                if(saveBList[i]<-1)
                {
                    boxType = -(saveBList[i]+2);
                    switch(boxType)
                    {
                        case 0:
                            currentRoom.blist.push_back("crates");
                            break;
                        case 1:
                            currentRoom.blist.push_back("barrels");
                            break;
                        case 2:
                            currentRoom.blist.push_back("chest");
                            break;
                    }
                }
                else
                    currentRoom.blist.push_back(dir.featureDirectory[saveBList[i]].getName());
            }
            //itemStatus parsed directly into
            currentRoom.monster = dir.creatureDirectory[roomData[1]];
            currentRoom.doorDesc = doorDesc(0,roomData[2]);
            vector<string> lDescSave = {lootDesc(boxType,roomData[3])};
            currentRoom.lootDesc = lDescSave;
            if(roomData[4]==-1)
                currentRoom.creatDesc = "";
            else
                currentRoom.creatDesc = creatureDesc(roomData[1],dir.creatureDirectory,hero,roomData[4]);
            if(roomData[5]==-1)
                currentRoom.ascDesc = "";
            else
                currentRoom.ascDesc = ascensionDesc(roomData[5]);
            currentRoom.contents = roomData[6];
            pass = roomData[7];
            if(roomData[8]>0) //SHOP
            {
                currentRoom.store.setLevel(roomData[8]);
                currentRoom.store.setUnlocked(roomData[9]);
                int itemCost;
                for(int i=10;i<15;i++)
                {
                    if(roomData[i]==-1)
                        break;
                    currentRoom.store.storeInventory.push_back(roomData[i]);
                    switch(dir.getItemRarity(roomData[i]))
                    {
                        case 1:
                            itemCost = 8;
                            break;
                        case 2:
                            itemCost = 15;
                            break;
                        case 3:
                            itemCost = 25;
                            break;
                        case 4:
                            itemCost = 40;
                            break;
                        case 5:
                            itemCost = 60;
                            break;
                        case 6:
                            itemCost = 85;
                            break;
                        case 7:
                            itemCost = 115;
                            break;
                        case 8:
                            itemCost = 150;
                            break;
                        case 9:
                            itemCost = 190;
                            break;
                        case 10:
                            itemCost = 250;
                            break;
                    }
                    currentRoom.store.storeCost.push_back(itemCost);
                }
            }
            else if(roomData[8]==0) //DIVINING
            {
                currentRoom.store.setLevel(roomData[8]);
                currentRoom.store.setUnlocked(roomData[9]);
                currentRoom.store.statUp.push_back(roomData[10]);
                currentRoom.store.statUp.push_back(roomData[11]);
                currentRoom.store.statDown.push_back(roomData[12]);
                currentRoom.store.statDown.push_back(roomData[13]);
                currentRoom.store.setStatCount(roomData[14]);
            }
            //cout << "Done!" << endl;
            cout << "Room " << depth << endl;
            cout << currentRoom.getDesc() << endl;
            for(int i=0;i<currentRoom.getLDescList().size();i++)
                cout << currentRoom.getLDescList()[i] << endl;
            if(hero.empowered==1)
                cout << currentRoom.ascDesc << endl;
            cout << currentRoom.getDrDesc() << endl;
            if(currentRoom.store.getLevel()!=-1)
                if(currentRoom.store.isUnlocked()==0)
                    cout << "There is a locked door at the side of the room. The sign above it says it is a shop." << endl;
                else
                    cout << "There is a shop on the side wall of the room." << endl;
            cout << currentRoom.creatDesc << endl;
        }
    }

    while(end==0)
    {
        //for(int i=0;i<15;i++)
        //    cout << "ROOMDATA[" << i << "]: " << roomData[i] << endl;
        if(hero.getHP()<=0)
        {
            end = 1;
            pass = 2;
            break;
        }
        if(manSave==0)
            saveFunc(hero,filename,depth,minibossStatus,itemStatus,currentRoom,pass,dir,randEncStatus);
        if(debug_opt&&depth%5==0&&depth>0)
        {
            string debugFile = "Saves/" + hero.getName() + "_Flr" + std::to_string(depth) + ".txt";
            saveFunc(hero,debugFile,depth,minibossStatus,itemStatus,currentRoom,pass,dir,randEncStatus);
        }
        if(hero.getHP()>hero.getMHP())
            hero.setHP(hero.getMHP());
        if(hero.getMP()>hero.getMMP())
            hero.setMP(hero.getMMP());
        if(hero.exp>=hero.getEXPGoal())
            hero.levelUp();
        if(itemDrop)
        {
            itemDrop = 0;
            for(int i=0;i<currentRoom.getIList().size();i++)
                if(currentRoom.getIList()[i]==57||currentRoom.getIList()[i]==58||currentRoom.getIList()[i]==142)
                    itemDrop = 1;
            if(!itemDrop)
                currentRoom.creatDesc = "";
        }
        cout << endl << "What do you do?" << endl;
        cin >> action;
        err = actionHandler(action,debug_opt,gankTracker);
        if(err!=-1)
        {
            if(err<4)
            {
                std::getline(cin,target);
                while(target=="")
                {
                    cout << endl << "Select a target: ";
                    std::getline(cin,target);
                }
                if(target.front()==' ')
                    target.erase(target.begin());
                //cout << target << "." << endl;
                text = interactionHandler(err,target,hero,dir,currentRoom,pass,itemStatus,debug_opt,itemIndex);
                if(text=="next")
                {
                    currentRoom = advance(depth,itemDrop,adv,diff,rew,karma,hero,pass,win,dir,boss,minibossStatus,roomStatus,randEncStatus,itemStatus,dev);
                    /*cout << "Reward Stat is " << rew << endl;
                    cout << "Difficulty Stat is " << diff << endl;*/
                    //THIS CODE WORKS FOR IDENTIFYING WHERE ITEMS ARE LOCATED
                    //
                    /*cout << "The room contains the following items in the following places: " << endl;
                    for(int i=0;i<currentRoom.getIList().size();i++)
                        cout << dir.getItemName(currentRoom.getIList()[i]) << "." << endl;
                    cout << "Inside of: " << endl;
                    for(int i=0;i<currentRoom.getBList().size();i++)
                        cout << currentRoom.getBList()[i] << "." << endl;*/
                }
                else if(text=="fight")
                {
                    gd = goldPicker(currentRoom.monster.getLEV());
                    ex = expPicker(currentRoom.monster.getLEV());
                    if(currentRoom.monster.getID()>=57) //Miniboss
                    {
                        gd = goldPicker(adv+3)*2;
                        ex = expPicker(adv+3)*2;
                    }
                    if(hero.mask.getID()==7) //Souls
                        ex = ex*3;
                    pass = combatHandler(hero,currentRoom.monster,dir,gd,ex,debug_opt);
                    if(pass==2)
                    {
                        end = 1;
                        break;
                    }
                    if(pass==3)
                    {
                        pass = 1;
                        currentRoom = advance(depth,itemDrop,adv,diff,rew,karma,hero,pass,win,dir,boss,minibossStatus,roomStatus,randEncStatus,itemStatus,dev);
                        continue;
                    }
                    if(boss==1)
                    {
                        win = 1;
                        std::system("cls");
                        score += 500;
                        ach.Tyrant = 1;
                        if(hero.mask.getID()==0)
                            ach.GlassTriumph = 1;
                        if(hero.mask.getID()==1)
                            ach.FateTriumph = 1;
                        if(hero.mask.getID()==2)
                            ach.DarknessTriumph = 1;
                        if(hero.mask.getID()==3)
                            ach.ArcanaTriumph = 1;
                        if(hero.mask.getID()==4)
                            ach.SteelTriumph = 1;
                        if(hero.mask.getID()==5)
                            ach.WhispersTriumph = 1;
                        if(hero.mask.getID()==6)
                            ach.BeastsTriumph = 1;
                        if(hero.mask.getID()==7)
                            ach.SoulsTriumph = 1;
                        if(ach.GlassTriumph==1&&ach.FateTriumph==1&&ach.DarknessTriumph==1&&ach.ArcanaTriumph==1&&ach.SteelTriumph==1&&ach.WhispersTriumph==1&&ach.BeastsTriumph==1&&ach.SoulsTriumph==1)
                            ach.SpectrumTriumph = 1;
                        if(gankTracker==1)
                            ach.Gank = 1;
                        cout << "Valentereth falls to the ground, motionless. She is defeated." << endl;
                        Sleep(midWait);
                        cout << "As she lay there, the same energy that had hold of her rushes from her body, and into yours." << endl;
                        Sleep(midWait);
                        cout << "You are flooded with incredible power." << endl;
                        Sleep(midWait);
                        cout << "A voice from above calls down to you... 'POWER HUNGRY ONE... YOU HAVE FOUND WHAT YOU DESIRED. NOW YOU MUST DEFEND YOUR TITLE AS TYRANT OF THE TOWER...'" << endl << endl;
                        Sleep(longWait);
                        cout << "You have defeated Valentereth, and inherited the throne! What do you do now?" << endl;
                        cout << "1) Defend the throne." << endl;
                        cout << "2) Venture to the top of the tower." << endl;
                        strChoice = getch();
                        std::stringstream stoi(strChoice);
                        stoi >> intChoice;
                        boss = 0;
                        if(intChoice==1)
                        {
                            end = 2;
                            clear();
                            cout << "You sit upon the throne, Valentereth's axe in hand, brimming with ancient power." << endl;
                            Sleep(shortWait);
                            cout << "At long last, after all the trials you endured, you are the ruler of the tower." << endl;
                            Sleep(shortWait);
                            cout << "Your head aches and your vision blurs, but the feeling of power within is all that matters now." << endl;
                            Sleep(shortWait);
                            cout << "You know there will be many who come forth and challenge your throne. The idea of it fills you with rage..." << endl << endl;
                            Sleep(shortWait);
                            cout << "But you will never, ever, let that happen." << endl << endl;
                            Sleep(midWait);
                            cout << "Numb from the searing pain in your head, you grab your axe, and await your next challenger." << endl << endl;
                            Sleep(midWait);
                            cout << "Press any key to defend your throne.";
                            yn = getch();
                            if(hero.equipment.size()<6)
                            {
                                cout << "You now wield " << dir.getItemName(59) << "!" << endl;
                                hero.equipment.push_back(59);
                                hero.equipWpn(dir.weaponDirectory[59]);
                            }
                            else
                            {
                                good = 0;
                                while(!good)
                                {
                                    std::system("cls");
                                    replaceMenu(hero,dir,0,59);
                                    strChoice = getch();
                                    std::stringstream stoi(strChoice);
                                    stoi >> intChoice;
                                    if(intChoice>=1&&intChoice<=hero.equipment.size())
                                    {
                                        cout << "Replaced " << dir.getItemName(hero.equipment[intChoice-1]) << " with " << dir.getItemName(59) << "." << endl;
                                        hero.equipment[intChoice-1] = 59;
                                        hero.equipWpn(dir.weaponDirectory[59]);
                                        good = 1;
                                    }
                                    else if(intChoice==0)
                                    {
                                        good = 1;
                                    }
                                    else
                                    {
                                        cout << "Invalid input." << endl;
                                        Sleep(shortWait);
                                    }
                                }
                            }
                            Sleep(longWait);
                            throneDefensePoints = throneDefense(hero,dir,debug_opt,gankTracker);
                            break;
                        }
                        else
                        {
                            std::system("cls");
                            cout << "You stare at Valentereth's axe in your hand, its power desperately calling you to wield it..." << endl;
                            Sleep(shortWait);
                            cout << "But is this truly the power you sought? To stay in this tower upon your throne, a prison of your own making?" << endl;
                            Sleep(shortWait);
                            cout << "You cast the axe aside. True power must lie further beyond..." << endl << endl;
                            Sleep(midWait);
                            cout << "Press any key to continue ascending the tower.";
                            yn = getch();
                            hero.Empower();
                        }
                        std::system("cls");
                    }
                    if(boss==2)
                    {
                        ach.Watcher = 1;
                        score += 1000;
                        end = 1;
                        win = 1;
                        break;
                    }

                    if(pass==4)
                    {
                        if(currentRoom.monster.getID()==57)
                        {
                            currentRoom.creatDesc = "One of Ozkoroth's fangs lie in a pool of ooze on the floor...";
                            currentRoom.addItem(57);
                        }
                        else if(currentRoom.monster.getID()==59)
                        {
                            currentRoom.creatDesc = "Emeritus' sceptre lies on the floor, pulsing with energy.";
                            currentRoom.addItem(58);
                        }
                        else if(currentRoom.monster.getID()==60)
                        {
                            currentRoom.creatDesc = "Stiran's shield lies on the floor next to you.";
                            currentRoom.addItem(142);
                        }
                        else if(currentRoom.monster.getID()==63)
                        {
                            currentRoom.creatDesc = "A ring lies on the floor, shimmering with the same light as Halliot.";
                            currentRoom.addItem(434);
                        }
                        itemDrop = 1;
                    }
                    else
                        currentRoom.creatDesc = "";

                    pass = 1;
                    cout << "Floor " << depth << endl;
                    cout << currentRoom.getDesc() << endl;
                    for(int i=0;i<currentRoom.getLDescList().size();i++)
                        cout << currentRoom.getLDescList()[i] << endl;
                    if(hero.empowered==1)
                        cout << currentRoom.ascDesc << endl;
                    cout << currentRoom.getDrDesc() << endl;
                    if(currentRoom.store.getLevel()!=-1)
                        if(currentRoom.store.isUnlocked()==0)
                            cout << "There is a locked door at the side of the room. The sign above it says it is a shop." << endl;
                        else
                            cout << "There is a shop on the side wall of the room." << endl;
                    cout << currentRoom.creatDesc << endl;
                }
                else if(text=="room")
                {
                    cout << endl << "Floor " << depth << endl << endl;
                    cout << currentRoom.getDesc() << endl;
                    for(int i=0;i<currentRoom.getLDescList().size();i++)
                        cout << currentRoom.getLDescList()[i] << endl;
                    if(hero.empowered==1)
                        cout << currentRoom.ascDesc << endl;
                    cout << currentRoom.getDrDesc() << endl;
                    if(currentRoom.store.getLevel()!=-1)
                        if(currentRoom.store.isUnlocked()==0)
                            cout << "There is a locked door at the side of the room. The sign above it says it is a shop." << endl;
                        else
                            cout << "There is a shop on the side wall of the room." << endl;
                    cout << currentRoom.creatDesc << endl;
                }
                else if(text=="store")
                {
                    if(currentRoom.store.isUnlocked()==0)
                    {
                        if(hero.keys == 0)
                            cout << "You do not have any keys." << endl;
                        else
                        {
                            cout << "Would you like to use a key to open the lock? You have " << hero.keys << " key(s) remaining. (y/n)" << endl;
                            yn = getch();
                            if(yn=='y')
                            {
                                hero.keys -= 1;
                                cout << "You unlock the door." << endl;
                                currentRoom.store.setUnlocked(1);
                                Sleep(midWait);
                                storeMenuHandler(hero,dir,currentRoom);
                                clear();
                                cout << "Floor " << depth << endl;
                                cout << currentRoom.getDesc() << endl;
                                for(int i=0;i<currentRoom.getLDescList().size();i++)
                                    cout << currentRoom.getLDescList()[i] << endl;
                                if(hero.empowered==1)
                                    cout << currentRoom.ascDesc << endl;
                                cout << currentRoom.getDrDesc() << endl;
                                if(currentRoom.store.getLevel()!=-1)
                                    if(currentRoom.store.isUnlocked()==0)
                                        cout << "There is a locked door at the side of the room. The sign above it says it is a shop." << endl;
                                    else
                                        cout << "There is a shop on the side wall of the room." << endl;
                                cout << currentRoom.creatDesc << endl;
                            }
                        }
                    }
                    else
                    {
                        storeMenuHandler(hero,dir,currentRoom);
                        clear();
                        cout << "Floor " << depth << endl;
                        cout << currentRoom.getDesc() << endl;
                        for(int i=0;i<currentRoom.getLDescList().size();i++)
                            cout << currentRoom.getLDescList()[i] << endl;
                        if(hero.empowered==1)
                            cout << currentRoom.ascDesc << endl;
                        cout << currentRoom.getDrDesc() << endl;
                        if(currentRoom.store.getLevel()!=-1)
                            if(currentRoom.store.isUnlocked()==0)
                                cout << "There is a locked door at the side of the room. The sign above it says it is a shop." << endl;
                            else
                                cout << "There is a shop on the side wall of the room." << endl;
                        cout << currentRoom.creatDesc << endl;
                    }
                }
                else if(text=="check")
                {
                    //Empty
                }
                else if(text=="escape")
                {
                    if(currentRoom.monster.getName()=="Valentereth, the Tyrant"||currentRoom.monster.getName()=="Termineth, the Watcher")
                    {
                        cout << "You cannot run from this enemy." << endl;
                        Sleep(midWait);
                        continue;
                    }
                    cout << "Enemy has not yet been defeated. Try to run past? (y/n)" << endl;
                    yn = getch();
                    if(yn=='y')
                    {
                        foo = rand() % 100 + 1;
                        if(hero.getDDG()>=currentRoom.monster.getLEV()*3)
                        {
                            if(foo>25) //pass
                            {
                                cout << "You escape successfully!" << endl;
                                Sleep(midWait);
                                good = 1;
                            }
                            else if(foo>10) //pass, but damage
                            {
                                cout << "The enemy attacks as you escape!" << endl;
                                Sleep(midWait);
                                dmg = currentRoom.monster.getSTR() - hero.getDEF();
                                if(hero.mask.getID()==0) //Glass
                                    dmg = dmg*2;
                                if(hero.mask.getID()==5) //Whispers
                                    dmg = static_cast<float>(dmg)*1.5;
                                if(hero.mask.getID()==4) //Steel
                                    dmg = static_cast<float>(dmg)*.7;
                                if(dmg<0)
                                    dmg = 0;
                                hero.changeHP(-dmg);
                                cout << "Dealt " << dmg << " damage!" << endl;
                                Sleep(midWait);
                                good = 1;
                            }
                            else //no pass, damage
                            {
                                cout << "The enemy knocks you back into the room, blocking your way!" << endl;
                                Sleep(midWait);
                                dmg = currentRoom.monster.getSTR() - hero.getDEF();
                                if(hero.mask.getID()==0) //Glass
                                    dmg = dmg*2;
                                if(hero.mask.getID()==5) //Whispers
                                    dmg = static_cast<float>(dmg)*1.5;
                                if(hero.mask.getID()==4) //Steel
                                    dmg = static_cast<float>(dmg)*.7;
                                if(dmg<0)
                                    dmg = 0;
                                hero.changeHP(-dmg);
                                cout << "Dealt " << dmg << " damage!" << endl;
                                Sleep(midWait);
                                good = 0;
                            }
                        }
                        else
                        {
                            if(foo>40) //pass
                            {
                                cout << "You escape successfully!" << endl;
                                Sleep(midWait);
                                good = 1;
                            }
                            else if(foo>20) //pass, but damage
                            {
                                cout << "The enemy attacks as you escape!" << endl;
                                Sleep(midWait);
                                dmg = currentRoom.monster.getSTR() - hero.getDEF();
                                if(hero.mask.getID()==0) //Glass
                                    dmg = dmg*2;
                                if(hero.mask.getID()==5) //Whispers
                                    dmg = static_cast<float>(dmg)*1.5;
                                if(hero.mask.getID()==4) //Steel
                                    dmg = static_cast<float>(dmg)*.7;
                                if(dmg<0)
                                    dmg = 0;
                                hero.changeHP(-dmg);
                                cout << "Dealt " << dmg << " damage!" << endl;
                                Sleep(midWait);
                                good = 1;
                            }
                            else //no pass, damage
                            {
                                cout << "The enemy knocks you back into the room, blocking your way!" << endl;
                                Sleep(midWait);
                                dmg = currentRoom.monster.getSTR() - hero.getDEF();
                                if(hero.mask.getID()==0) //Glass
                                    dmg = dmg*2;
                                if(hero.mask.getID()==5) //Whispers
                                    dmg = static_cast<float>(dmg)*1.5;
                                if(hero.mask.getID()==4) //Steel
                                    dmg = static_cast<float>(dmg)*.7;
                                if(dmg<0)
                                    dmg = 0;
                                hero.changeHP(-dmg);
                                cout << "Dealt " << dmg << " damage!" << endl;
                                Sleep(midWait);
                                good = 0;
                            }
                        }
                        if(hero.getHP()<=0)
                        {
                            cout << "You have fallen..." << endl;
                            Sleep(longWait);
                            pass = 2;
                            end = 1;
                            break;
                        }
                        if(good==1)
                        {
                            score += 10;
                            currentRoom = advance(depth,itemDrop,adv,diff,rew,karma,hero,pass,win,dir,boss,minibossStatus,roomStatus,randEncStatus,itemStatus,dev);
                        }
                    }
                }
                else if(text=="replace")
                {
                    bool inventoryType = 0;
                    if(currentRoom.getIList()[itemIndex]<200||currentRoom.getIList()[itemIndex]>=400)
                        inventoryType = 0;
                    else
                        inventoryType = 1;
                    bool stop = 0;
                    clear();
                    while(!stop)
                    {
                        replaceMenu(hero,dir,inventoryType,currentRoom.getIList()[itemIndex]);
                        strChoice = getch();
                        std::stringstream stoi(strChoice);
                        stoi >> intChoice;
                        if(!inventoryType)
                        {
                            if(intChoice>=1&&intChoice<=hero.equipment.size())
                            {
                                if(hero.equipment[intChoice-1]<100)
                                {
                                    cout << dir.getItemName(hero.equipment[intChoice-1]) << " | " << dir.getItemDesc(hero.equipment[intChoice-1]) << endl;
                                    cout << "RARITY: " << dir.weaponDirectory[hero.equipment[intChoice-1]].getRarity() << endl;
                                    if((hero.meleeTraining==0&&(dir.getItemName(hero.equipment[intChoice-1]).find("Dagger")!=string::npos||dir.getItemName(hero.equipment[intChoice-1]).find("Knife")!=string::npos||dir.getItemName(hero.equipment[intChoice-1]).find("Aerolinde")!=string::npos))||
                                       (hero.meleeTraining==1&&(dir.getItemName(hero.equipment[intChoice-1]).find("Spear")!=string::npos||dir.getItemName(hero.equipment[intChoice-1]).find("Pike")!=string::npos||dir.getItemName(hero.equipment[intChoice-1]).find("Hyliat")!=string::npos))||
                                       (hero.meleeTraining==2&&(dir.getItemName(hero.equipment[intChoice-1]).find("Sword")!=string::npos||dir.getItemName(hero.equipment[intChoice-1]).find("Saber")!=string::npos||dir.getItemName(hero.equipment[intChoice-1]).find("Pyrithia")!=string::npos))||
                                       (hero.meleeTraining==3&&(dir.getItemName(hero.equipment[intChoice-1]).find("Axe")!=string::npos||dir.getItemName(hero.equipment[intChoice-1]).find("Club")!=string::npos||dir.getItemName(hero.equipment[intChoice-1]).find("Teratra")!=string::npos)))
                                    {
                                        cout << "STR: " << dir.weaponDirectory[hero.equipment[intChoice-1]].getStr()+2 << endl;
                                        cout << "ACC: " << dir.weaponDirectory[hero.equipment[intChoice-1]].getAcc()+5 << endl;
                                        cout << "CRIT: " << dir.weaponDirectory[hero.equipment[intChoice-1]].getCrt()+5 << endl;
                                    }
                                    else
                                    {
                                        cout << "STR: " << dir.weaponDirectory[hero.equipment[intChoice-1]].getStr() << endl;
                                        cout << "ACC: " << dir.weaponDirectory[hero.equipment[intChoice-1]].getAcc() << endl;
                                        cout << "CRIT: " << dir.weaponDirectory[hero.equipment[intChoice-1]].getCrt() << endl;
                                    }
                                    if(dir.weaponDirectory[hero.equipment[intChoice-1]].getMA()!=0)
                                        cout << "MAGIC AMP: +" << dir.weaponDirectory[hero.equipment[intChoice-1]].getMA() << "%" << endl;
                                }
                                else if(hero.equipment[intChoice-1]<200)
                                {
                                    cout << dir.getItemName(hero.equipment[intChoice-1]) << " | " << dir.getItemDesc(hero.equipment[intChoice-1]) << endl;
                                    cout << "RARITY: " << dir.armorDirectory[hero.equipment[intChoice-1]-100].getRarity() << endl;
                                    cout << "DEF: " << dir.armorDirectory[hero.equipment[intChoice-1]-100].getDef() << endl;
                                    cout << "DDG: " << dir.armorDirectory[hero.equipment[intChoice-1]-100].getDdg() << endl;
                                    if(dir.armorDirectory[hero.equipment[intChoice-1]-100].getMG()!=0)
                                        cout << "MANA REGEN: " << dir.armorDirectory[hero.equipment[intChoice-1]-100].getMG()  << endl;
                                }
                                else
                                {
                                    cout << dir.getItemName(hero.equipment[intChoice-1]) << " | " << dir.getItemDesc(hero.equipment[intChoice-1]) << endl;
                                    cout << "RARITY: " << dir.ringDirectory[hero.equipment[intChoice-1]-400].getRarity() << endl;
                                    if(dir.ringDirectory[hero.equipment[intChoice-1]-400].getAct()>0)
                                        cout << "ACTIVATION RATE: " << dir.ringDirectory[hero.equipment[intChoice-1]-400].getAct() << "%" << endl;
                                    if(dir.ringDirectory[hero.equipment[intChoice-1]-400].getHPR()>0)
                                        cout << "HP REGEN: " << dir.ringDirectory[hero.equipment[intChoice-1]-400].getHPR() << endl;
                                    if(dir.ringDirectory[hero.equipment[intChoice-1]-400].getMPR()>0)
                                        cout << "MANA REGEN: " << dir.ringDirectory[hero.equipment[intChoice-1]-400].getMPR() << endl;
                                }
                                cout << "Are you sure you want to replace " << dir.getItemName(hero.equipment[intChoice-1]) << " with " << dir.getItemName(currentRoom.getIList()[itemIndex]) << "? (y/n)" << endl;
                                strChoice = getch();
                                if(strChoice=="y")
                                {
                                    cout << "Replaced " << dir.getItemName(hero.equipment[intChoice-1]) << " with " << dir.getItemName(currentRoom.getIList()[itemIndex]) << "." << endl;
                                    Sleep(midWait);
                                    hero.equipment[intChoice-1] = currentRoom.getIList()[itemIndex];
                                    itemStatus[itemIndex] = 1;
                                    stop = 1;
                                }
                            }
                            else if(intChoice==0)
                            {
                                stop = 1;
                            }
                            else
                            {
                                cout << "Invalid input." << endl;
                                Sleep(shortWait);
                            }
                        }
                        else
                        {
                            if(intChoice>=1&&intChoice<=hero.inventory.size())
                            {
                                if(dir.consumableDirectory[hero.inventory[intChoice-1]-200].getID()<212) //Potion/Food
                                {
                                    cout << dir.consumableDirectory[hero.inventory[intChoice-1]-200].getName() << " | " << dir.consumableDirectory[hero.inventory[intChoice-1]-200].getDesc() << endl;
                                    cout << "RARITY: " << dir.consumableDirectory[hero.inventory[intChoice-1]-200].getRarity() << endl;
                                    cout << "HP: " << dir.consumableDirectory[hero.inventory[intChoice-1]-200].getHP() << endl;
                                    cout << "MP: " << dir.consumableDirectory[hero.inventory[intChoice-1]-200].getMP() << endl << endl;
                                }
                                else
                                {
                                    cout << dir.consumableDirectory[hero.inventory[intChoice-1]-200].getName() << " | " << dir.consumableDirectory[hero.inventory[intChoice-1]-200].getDesc() << endl;
                                    cout << "RARITY: " << dir.consumableDirectory[hero.inventory[intChoice-1]-200].getRarity() << endl << endl;
                                }
                                cout << "Are you sure you want to replace " << dir.getItemName(hero.inventory[intChoice-1]) << " with " << dir.getItemName(currentRoom.getIList()[itemIndex]) << "? (y/n)" << endl;
                                strChoice = getch();
                                if(strChoice=="y")
                                {
                                    cout << "Replaced " << dir.getItemName(hero.inventory[intChoice-1]) << " with " << dir.getItemName(currentRoom.getIList()[itemIndex]) << "." << endl;
                                    Sleep(midWait);
                                    hero.inventory[intChoice-1] = currentRoom.getIList()[itemIndex];
                                    itemStatus[itemIndex] = 1;
                                    stop = 1;
                                }
                            }
                            else if(intChoice==0)
                            {
                                stop = 1;
                            }
                            else
                            {
                                cout << "Invalid input." << endl;
                                Sleep(shortWait);
                            }
                        }
                        clear();
                    }
                    cout << "Floor " << depth << endl << endl;
                    cout << currentRoom.getDesc() << endl;
                    for(int i=0;i<currentRoom.getLDescList().size();i++)
                        cout << currentRoom.getLDescList()[i] << endl;
                    if(hero.empowered==1)
                        cout << currentRoom.ascDesc << endl;
                    cout << currentRoom.getDrDesc() << endl;
                    if(currentRoom.store.getLevel()!=-1)
                        if(currentRoom.store.isUnlocked()==0)
                            cout << "There is a locked door at the side of the room. The sign above it says it is a shop." << endl;
                        else
                            cout << "There is a shop on the side wall of the room." << endl;
                    cout << currentRoom.creatDesc << endl;
                }
                else
                {
                    cout << text << endl;
                }
            }
            else if(err==4)
            {
                menuval = menuHandler(hero,dir);
                clear();
                if(menuval==-1) //Writing Save File
                {
                    cout << "Quitting..." << endl;
                    saveFunc(hero,filename,depth,minibossStatus,itemStatus,currentRoom,pass,dir,randEncStatus);
                    end = 1;
                }
                else
                {
                    cout << "Floor " << depth << endl;
                    cout << currentRoom.getDesc() << endl;
                    for(int i=0;i<currentRoom.getLDescList().size();i++)
                        cout << currentRoom.getLDescList()[i] << endl;
                    if(hero.empowered==1)
                        cout << currentRoom.ascDesc << endl;
                    cout << currentRoom.getDrDesc() << endl;
                    if(currentRoom.store.getLevel()!=-1)
                        if(currentRoom.store.isUnlocked()==0)
                            cout << "There is a locked door at the side of the room. The sign above it says it is a shop." << endl;
                        else
                            cout << "There is a shop on the side wall of the room." << endl;
                    cout << currentRoom.creatDesc << endl;
                }
            }
            else if(err==7)
            {
                if(manSave==0)
                {
                    cout << "ToV uses autosave. Would you like to disable autosave? You can re-enable" << endl;
                    cout << "autosave by typing save again or restarting the game. (y/n)" << endl;
                    yn = getch();
                    if(yn=='y')
                    {
                        cout << "Autosave disabled. Saving..." << endl;
                        saveFunc(hero,filename,depth,minibossStatus,itemStatus,currentRoom,pass,dir,randEncStatus);
                        manSave = 1;
                    }
                }
                else
                {
                    cout << "Autosave is disabled. Re-enable? Your game will be saved either way. (y/n)" << endl;
                    yn = getch();
                    if(yn=='y')
                    {
                        cout << "Autosave re-enabled." << endl;
                        manSave = 0;
                    }
                    saveFunc(hero,filename,depth,minibossStatus,itemStatus,currentRoom,pass,dir,randEncStatus);
                }
            }
            else if(err==8)
            {
                cout << endl;
                cout << "Actions:" << endl;
                cout << "    MOVE: move <target>" << endl;
                cout << "        -Synonyms: Go, Enter, Leave, Walk, Next" << endl;
                cout << "        -Meaning: Used to enter a new area." << endl;
                cout << "        -EG: enter door" << endl;
                cout << "    LOOK: look <target>" << endl;
                cout << "        -Synonyms: Check, Examine, See" << endl;
                cout << "        -Meaning: Used to examine a feature in the room." << endl;
                cout << "        -EG: check crates" << endl;
                cout << "    GET: get <target>" << endl;
                cout << "        -Synonyms: Take, Grab, Add" << endl;
                cout << "        -Meaning: Used to acquire a new item." << endl;
                cout << "        -EG: get wooden sword" << endl;
                cout << "    ATTACK: attack <target>" << endl;
                cout << "        -Synonyms: Fight, Strike, Kill, Gank" << endl;
                cout << "        -Meaning: Used to engage in combat with a creature." << endl;
                cout << "        -EG: attack ogre" << endl;
                cout << "    MENU: menu" << endl;
                cout << "        -Synonyms: Inventory, Pause, M, Items" << endl;
                cout << "        -Meaning: Opens up your menu." << endl;
                cout << "        -EG: menu" << endl;
                cout << "    SAVE: save" << endl;
                cout << "        -Synonyms: (None)" << endl;
                cout << "        -Meaning: Enables/Disables manual saving (Autosave enabled by default)." << endl;
                cout << "        -EG: save" << endl;
                cout << "    SPEED: speed <speed>" << endl;
                cout << "        -Synonyms: Delay, Textspeed, Gamespeed" << endl;
                cout << "        -Meaning: Sets the speed of the gameplay to either slow, normal, or fast." << endl;
                cout << "        -EG: speed fast" << endl;
                cout << "    HELP: help" << endl;
                cout << "        -Synonyms: Manual, H, Guide, Instructions" << endl;
                cout << "        -Meaning: Opens a guide to actions." << endl;
                cout << "        -EG: help" << endl;
                cout << endl;
                cout << "For further help, consult the REAMDE file in the game files." << endl << endl;
            }
            /*else if(err==5)
            {
                cin >> diff >> rew >> adv;
                cout << "Generating room with diff = " << diff << ", rew = " << rew << ", and adv = " << adv << "." << endl;
                roomGenerator(diff,rew,adv,dir);
            }*/
            else if(err==6) //DEBUG_GO
            {
                currentRoom = advance(depth,itemDrop,adv,diff,rew,karma,hero,pass,win,dir,boss,minibossStatus,roomStatus,randEncStatus,itemStatus,dev);
            }
            else if(err==10) //SEE
            {
                //THIS CODE WORKS FOR IDENTIFYING WHERE ITEMS ARE LOCATED
                cout << "The room contains the following items in the following places: " << endl;
                for(int i=0;i<currentRoom.getIList().size();i++)
                {
                    cout << dir.getItemName(currentRoom.getIList()[i]) << ".";
                    if(itemStatus[i]==1)
                        cout << " (Taken)" << endl;
                    else
                        cout << endl;
                }
                cout << "Inside of: " << endl;
                for(int i=0;i<currentRoom.getBList().size();i++)
                    cout << currentRoom.getBList()[i] << "." << endl;
            }
            else if(err==11) //MINIBOSS
            {
                cout << "You hear noises coming from the next room..." << endl;
                dev = 1;
            }
            else if(err==12) //GODMODE
            {
                if(!godMode)
                {
                    cout << "God mode enabled. ATK and DEF have been maxed out in combat for this room." << endl;
                    godMode = 1;
                }
                else
                {
                    cout << "God mode disabld." << endl;
                    godMode = 0;
                }
            }
            else if(err==13) //SAVELOG
            {
                if(!saveLog)
                {
                    cout << "Save log enabled. Copies of this save file will be made every 5 floors for review purposes." << endl;
                    saveLog = 1;
                }
                else
                {
                    cout << "Save log disabld." << endl;
                    saveLog = 0;
                }
            }
            else if(err==14)
            {
                cout << "Karma: " << karma << endl;
            }
            else if(err==15)
            {
                std::getline(cin,target);
                while(target=="")
                {
                    cout << endl << "Select a speed: ";
                    std::getline(cin,target);
                }
                if(target.front()==' ')
                    target.erase(target.begin());
                if(target=="slow"||target=="long")
                {
                    shortWait = 1500;
                    midWait = 3000;
                    longWait = 4500;
                    cout << "Game speed set to slow." << endl;
                }
                else if(target=="normal"||target=="regular"||target=="medium")
                {
                    shortWait = 1000;
                    midWait = 2000;
                    longWait = 3000;
                    cout << "Game speed set to normal." << endl;
                }
                else if(target=="fast"||target=="short")
                {
                    shortWait = 500;
                    midWait = 1000;
                    longWait = 1500;
                    cout << "Game speed set to fast." << endl;
                }
                else
                {
                    cout << "Invalid speed. Try: slow, normal, fast" << endl;
                }
            }
        }
        else
            end = 1;
    }
    if(win==1)
    {
        clear();
        if(pass==2)
        {
            cout << "GAME OVER!" << endl;
            cout << "You inherited the throne of the Tower of Valentereth, and defended it for " << throneDefensePoints << " rounds!" << endl;
            remove(filename.c_str());
            if(end!=2)
            {
                ach.DejaVu++;
                ach.RiseAndShine++;
            }
            Sleep(midWait);
            if(hiscores(hero,depth+throneDefensePoints))
            {
                cout << "On the leaderboard!" << endl;
                Sleep(midWait);
            }
        }
        else if(boss==2)
        {
            cout << "CONGRATULATIONS!" << endl;
            cout << "You have broken the curse and ascended to the top of the Tower of Valentereth!" << endl;
            remove(filename.c_str());
            Sleep(midWait);
            if(hiscores(hero,100))
            {
                cout << "On the leaderboard!" << endl;
                Sleep(midWait);
            }
        }
    }
    else if(pass==2)
    {
        clear();
        remove(filename.c_str());
        ach.DejaVu++;
        ach.RiseAndShine++;
        cout << "GAME OVER!" << endl;
        cout << "You made it to room " << depth << "!" << endl;
        Sleep(midWait);
        if(hiscores(hero,depth))
        {
            cout << "On the leaderboard!" << endl;
            Sleep(midWait);
        }
    }
    else
        Sleep(midWait);
    ach.writeAchievements();
    return 0;
}

int actionHandler(string act, bool debug_opt, int gankTracker)
{
    if(act=="go"||act=="move"||act=="enter"||act=="leave"||act=="walk"||act=="next")
    {
        //cout << "You go to the ";
        return 0;
    }
    else if(act=="look"||act=="check"||act=="examine"||act=="see")
    {
        //cout << "You look at the ";
        return 1;
    }
    else if(act=="take"||act=="get"||act=="grab"||act=="add"||act=="yoink"||act=="pickup")
    {
        //cout << "You take the ";
        return 2;
    }
    else if(act=="attack"||act=="fight"||act=="gank"||act=="strike"||act=="kill"||act=="murder")
    {
        if(act!="gank")
            gankTracker = 0;
        //cout << "You attack the ";
        return 3;
    }
    else if(act=="menu"||act=="inventory"||act=="pause"||act=="m"||act=="items")
    {
        //cout << "You open your menu." << endl;
        return 4;
    }
    else if(act=="save")
    {
        return 7;
    }
    else if(act=="help"||act=="manual"||act=="instructions"||act=="guide"||act=="h")
    {
        return 8;
    }
    else if((act=="debug_go"||act=="dgo")&&debug_opt)
    {
        return 6;
    }
    else if((act=="dsee"||act=="dlook"||act=="look_all")&&debug_opt)
    {
        return 10;
    }
    else if((act=="miniboss"||act=="summon")&&debug_opt)
    {
        return 11;
    }
    else if(act=="godmode"&&debug_opt)
    {
        return 12;
    }
    else if(act=="savelog"&&debug_opt)
    {
        return 13;
    }
    else if(act=="karma"&&debug_opt)
    {
        return 14;
    }
    else if(act=="speed"||act=="delay"||act=="textspeed"||act=="gamespeed")
    {
        return 15;
    }
    else
    {
        cout << "Unknown command." << endl;
        return 9;
    }
}

int menuHandler(Player &hero, Directory dir)
{
    string strChoice;
    int intChoice;
    int nav;
    int gCost;
    int mCost;
    do{
        nav = 0;
        mainMenu();
        strChoice = getch();
        std::stringstream stoi(strChoice);
        stoi >> intChoice;

        if(intChoice==1)
        {
            nav = 1;
        }
        else if(intChoice==2)
        {
            while(true)
            {
                statMenu(hero,dir);
                cout << "STATS: ";
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice==0)
                {
                    break;
                }
            }
        }
        else if(intChoice==3)
        {
            do{
                nav = 0;
                equipmentMenu(hero.equipment,dir);
                cout << "EQUIPMENT: ";
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                /*if(intChoice<=0&&intChoice>=9)
                {
                    cout << "Please input an integer." << endl;
                    Sleep(1000);
                    continue;
                }*/
                if(intChoice<=hero.equipment.size())
                {
                    if(intChoice==0)
                        break;
                    if(hero.equipment[intChoice-1]<100)
                    {
                        cout << dir.getItemName(hero.equipment[intChoice-1]) << " | " << dir.getItemDesc(hero.equipment[intChoice-1]) << endl;
                        cout << "RARITY: " << dir.weaponDirectory[hero.equipment[intChoice-1]].getRarity() << endl;
                        if((hero.meleeTraining==0&&(dir.getItemName(hero.equipment[intChoice-1]).find("Dagger")!=string::npos||dir.getItemName(hero.equipment[intChoice-1]).find("Knife")!=string::npos||dir.getItemName(hero.equipment[intChoice-1]).find("Aerolinde")!=string::npos))||
                           (hero.meleeTraining==1&&(dir.getItemName(hero.equipment[intChoice-1]).find("Spear")!=string::npos||dir.getItemName(hero.equipment[intChoice-1]).find("Pike")!=string::npos||dir.getItemName(hero.equipment[intChoice-1]).find("Hyliat")!=string::npos))||
                           (hero.meleeTraining==2&&(dir.getItemName(hero.equipment[intChoice-1]).find("Sword")!=string::npos||dir.getItemName(hero.equipment[intChoice-1]).find("Saber")!=string::npos||dir.getItemName(hero.equipment[intChoice-1]).find("Pyrithia")!=string::npos))||
                           (hero.meleeTraining==3&&(dir.getItemName(hero.equipment[intChoice-1]).find("Axe")!=string::npos||dir.getItemName(hero.equipment[intChoice-1]).find("Club")!=string::npos||dir.getItemName(hero.equipment[intChoice-1]).find("Teratra")!=string::npos)))
                        {
                            cout << "STR: " << dir.weaponDirectory[hero.equipment[intChoice-1]].getStr()+2 << endl;
                            cout << "ACC: " << dir.weaponDirectory[hero.equipment[intChoice-1]].getAcc()+5 << endl;
                            cout << "CRIT: " << dir.weaponDirectory[hero.equipment[intChoice-1]].getCrt()+5 << endl;
                        }
                        else
                        {
                            cout << "STR: " << dir.weaponDirectory[hero.equipment[intChoice-1]].getStr() << endl;
                            cout << "ACC: " << dir.weaponDirectory[hero.equipment[intChoice-1]].getAcc() << endl;
                            cout << "CRIT: " << dir.weaponDirectory[hero.equipment[intChoice-1]].getCrt() << endl;
                        }
                        if(dir.weaponDirectory[hero.equipment[intChoice-1]].getMA()!=0)
                            cout << "MAGIC AMP: +" << dir.weaponDirectory[hero.equipment[intChoice-1]].getMA() << "%" << endl;
                    }
                    else if(hero.equipment[intChoice-1]<200)
                    {
                        cout << dir.getItemName(hero.equipment[intChoice-1]) << " | " << dir.getItemDesc(hero.equipment[intChoice-1]) << endl;
                        cout << "RARITY: " << dir.armorDirectory[hero.equipment[intChoice-1]-100].getRarity() << endl;
                        cout << "DEF: " << dir.armorDirectory[hero.equipment[intChoice-1]-100].getDef() << endl;
                        cout << "DDG: " << dir.armorDirectory[hero.equipment[intChoice-1]-100].getDdg() << endl;
                        if(dir.armorDirectory[hero.equipment[intChoice-1]-100].getMG()!=0)
                            cout << "MANA REGEN: " << dir.armorDirectory[hero.equipment[intChoice-1]-100].getMG()  << endl;
                    }
                    else
                    {
                        cout << dir.getItemName(hero.equipment[intChoice-1]) << " | " << dir.getItemDesc(hero.equipment[intChoice-1]) << endl;
                        cout << "RARITY: " << dir.ringDirectory[hero.equipment[intChoice-1]-400].getRarity() << endl;
                        if(dir.ringDirectory[hero.equipment[intChoice-1]-400].getAct()>0)
                            cout << "ACTIVATION RATE: " << dir.ringDirectory[hero.equipment[intChoice-1]-400].getAct() << "%" << endl;
                        if(dir.ringDirectory[hero.equipment[intChoice-1]-400].getHPR()>0)
                            cout << "HP REGEN: " << dir.ringDirectory[hero.equipment[intChoice-1]-400].getHPR() << endl;
                        if(dir.ringDirectory[hero.equipment[intChoice-1]-400].getMPR()>0)
                            cout << "MANA REGEN: " << dir.ringDirectory[hero.equipment[intChoice-1]-400].getMPR() << endl;
                    }
                    cout << endl << "What do you want to do to " << dir.getItemName(hero.equipment[intChoice-1]) << "?" << endl;
                    cout << "1) EQUIP" << endl;
                    cout << "2) DROP" << endl;
                    if(hero.equipment[intChoice-1]>=400)
                        cout << "3) ENHANCE" << endl;
                    cout << "0) RETURN" << endl;
                    strChoice = getch();
                    if(strChoice=="1")
                    {
                        if(hero.equipment[intChoice-1]<100)
                        {
                            if(hero.mask.getID()==7) //Souls
                            {
                                cout << "The weapon falls through your hand to the ground...";
                                Sleep(midWait);
                            }
                            else
                            {
                                hero.equipWpn(dir.weaponDirectory[hero.equipment[intChoice-1]]);
                                cout << "Equipped " << dir.getItemName(hero.equipment[intChoice-1]);
                                Sleep(midWait);
                            }
                        }
                        else if(hero.equipment[intChoice-1]<200)
                        {
                            if(hero.mask.getID()==7) //Souls
                            {
                                cout << "The armor phases right through you...";
                                Sleep(midWait);
                            }
                            else
                            {
                                hero.equipAmr(dir.armorDirectory[hero.equipment[intChoice-1]-100]);
                                cout << "Equipped " << dir.getItemName(hero.equipment[intChoice-1]);
                                Sleep(midWait);
                            }
                        }
                        else
                        {
                            hero.equipRng(dir.ringDirectory[hero.equipment[intChoice-1]-400]);
                            cout << "Equipped " << dir.getItemName(hero.equipment[intChoice-1]);
                            Sleep(midWait);
                        }
                    }
                    else if(strChoice=="2")
                    {
                        cout << "Are you sure you want to drop " << dir.getItemName(hero.equipment[intChoice-1]) << "? (y/n)" << endl;
                        strChoice = getch();
                        if(strChoice=="y")
                            hero.equipment.erase(hero.equipment.begin()+intChoice-1);
                    }
                    else if(strChoice=="3"&&hero.equipment[intChoice-1]>=400)
                    {
                        if(hero.equipment[intChoice-1]<=409)
                        {
                            gCost = 100;
                            mCost = 50;
                            cout << endl << dir.getItemName(hero.equipment[intChoice-1]) << " ---> " << dir.getItemName(hero.equipment[intChoice-1]+10) << endl;
                            cout << dir.getItemName(hero.equipment[intChoice-1]+10) << " | " << dir.getItemDesc(hero.equipment[intChoice-1]+10) << endl;
                            cout << "RARITY: " << dir.ringDirectory[hero.equipment[intChoice-1]+10-400].getRarity() << endl;
                            if(dir.ringDirectory[hero.equipment[intChoice-1]+10-400].getAct()>0)
                                cout << "ACTIVATION RATE: " << dir.ringDirectory[hero.equipment[intChoice-1]+10-400].getAct() << "%" << endl;
                            if(dir.ringDirectory[hero.equipment[intChoice-1]+10-400].getHPR()>0)
                                cout << "HP REGEN: " << dir.ringDirectory[hero.equipment[intChoice-1]+10-400].getHPR() << endl;
                            if(dir.ringDirectory[hero.equipment[intChoice-1]+10-400].getMPR()>0)
                                cout << "MANA REGEN: " << dir.ringDirectory[hero.equipment[intChoice-1]+10-400].getMPR() << endl;
                        }
                        else if(hero.equipment[intChoice-1]<=421)
                        {
                            gCost = 250;
                            mCost = 75;
                            cout << endl <<  dir.getItemName(hero.equipment[intChoice-1]) << " ---> " << dir.getItemName(hero.equipment[intChoice-1]+12) << endl;
                            cout << dir.getItemName(hero.equipment[intChoice-1]+12) << " | " << dir.getItemDesc(hero.equipment[intChoice-1]+12) << endl;
                            cout << "RARITY: " << dir.ringDirectory[hero.equipment[intChoice-1]+12-400].getRarity() << endl;
                            if(dir.ringDirectory[hero.equipment[intChoice-1]+12-400].getAct()>0)
                                cout << "ACTIVATION RATE: " << dir.ringDirectory[hero.equipment[intChoice-1]+12-400].getAct() << "%" << endl;
                            if(dir.ringDirectory[hero.equipment[intChoice-1]+12-400].getHPR()>0)
                                cout << "HP REGEN: " << dir.ringDirectory[hero.equipment[intChoice-1]+12-400].getHPR() << endl;
                            if(dir.ringDirectory[hero.equipment[intChoice-1]+12-400].getMPR()>0)
                                cout << "MANA REGEN: " << dir.ringDirectory[hero.equipment[intChoice-1]+12-400].getMPR() << endl;
                        }
                        else
                        {
                            cout << "This ring cannot be enhanced any further." << endl;
                            Sleep(midWait);
                            continue;
                        }
                        cout << endl << "GOLD COST: " << gCost << endl;
                        cout << "MANA COST: " << mCost << endl;
                        cout << "Make an offering to enhance this ring? (y/n)" << endl;
                        strChoice = getch();
                        if(strChoice=="y")
                        {
                            if(hero.gold<gCost)
                            {
                                cout << "You cannot afford to enhance this ring." << endl;
                                Sleep(midWait);
                                continue;
                            }
                            if(hero.getMP()<mCost)
                            {
                                cout << "You do not have enough MP to enhance this ring." << endl;
                                Sleep(midWait);
                                continue;
                            }
                            hero.gold -= gCost;
                            hero.changeMP(-mCost);
                            if(hero.equipment[intChoice-1]<=409)
                            {
                                cout << dir.getItemName(hero.equipment[intChoice-1]) << " has been enhanced to " << dir.getItemName(hero.equipment[intChoice-1]+10) << "!" << endl;
                                hero.equipment[intChoice-1] += 10;
                                if(hero.eqpRng.getID()==hero.equipment[intChoice-1]-10)
                                    hero.eqpRng = dir.ringDirectory[hero.equipment[intChoice-1]-400];
                            }
                            else
                            {
                                cout << dir.getItemName(hero.equipment[intChoice-1]) << " has been enhanced to " << dir.getItemName(hero.equipment[intChoice-1]+12) << "!" << endl;
                                hero.equipment[intChoice-1] += 12;
                                if(hero.eqpRng.getID()==hero.equipment[intChoice-1]-12)
                                    hero.eqpRng = dir.ringDirectory[hero.equipment[intChoice-1]-400];
                            }
                            Sleep(midWait);
                        }
                    }
                    else if(strChoice!="0")
                    {
                        cout << "Invalid action." << endl;
                        Sleep(midWait);
                    }
                }
                else
                {
                    cout << "Invalid item." << endl;
                    Sleep(midWait);
                }
            }while(nav==0);
            nav = 0;
        }
        else if(intChoice==4)
        {
            do{
                nav = 0;
                itemMenu(hero,hero.inventory,dir);
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                /*if(intChoice<=0&&intChoice>=9)
                {
                    cout << "Please input an integer." << endl;
                    Sleep(1000);
                    continue;
                }*/
                if(intChoice<=hero.inventory.size())
                {
                    if(intChoice==0)
                        break;
                    if(dir.consumableDirectory[hero.inventory[intChoice-1]-200].getID()<212) //Potion/Food
                    {
                        cout << dir.consumableDirectory[hero.inventory[intChoice-1]-200].getName() << " | " << dir.consumableDirectory[hero.inventory[intChoice-1]-200].getDesc() << endl;
                        cout << "RARITY: " << dir.consumableDirectory[hero.inventory[intChoice-1]-200].getRarity() << endl;
                        cout << "HP: " << dir.consumableDirectory[hero.inventory[intChoice-1]-200].getHP() << endl;
                        cout << "MP: " << dir.consumableDirectory[hero.inventory[intChoice-1]-200].getMP() << endl << endl;
                        cout << "What do you want to do to " << dir.getItemName(hero.inventory[intChoice-1]) << "?" << endl;
                        cout << "1) USE" << endl;
                        cout << "2) DROP" << endl;
                        cout << "0) RETURN" << endl;
                        strChoice = getch();
                        if(strChoice=="1")
                        {
                            if(dir.consumableDirectory[hero.inventory[intChoice-1]-200].getHP()>0)
                            {
                                hero.changeHP(dir.consumableDirectory[hero.inventory[intChoice-1]-200].getHP());
                                if(hero.getHP()>hero.getMHP())
                                    hero.setHP(hero.getMHP());
                                cout << "You regained " << dir.consumableDirectory[hero.inventory[intChoice-1]-200].getHP() << " HP!" << endl;
                                Sleep(midWait);
                            }
                            if(dir.consumableDirectory[hero.inventory[intChoice-1]-200].getMP()>0)
                            {
                                hero.changeMP(dir.consumableDirectory[hero.inventory[intChoice-1]-200].getMP());
                                if(hero.getMP()>hero.getMMP())
                                    hero.setMP(hero.getMMP());
                                cout << "You regained " << dir.consumableDirectory[hero.inventory[intChoice-1]-200].getMP() << " MP!" << endl;
                                Sleep(midWait);
                            }
                            hero.inventory.erase(hero.inventory.begin()+intChoice-1);
                            if(dir.consumableDirectory[hero.inventory[intChoice-1]-200].getName()=="Bread")
                                ach.Connoisseur++;
                            if(dir.consumableDirectory[hero.inventory[intChoice-1]-200].getID()>=204&&dir.consumableDirectory[hero.inventory[intChoice-1]-200].getID()<=211)
                                ach.Alchemist++;
                        }
                        else if(strChoice=="2")
                        {
                            hero.inventory.erase(hero.inventory.begin()+intChoice-1);
                        }
                        else if(strChoice!="0")
                        {
                            cout << "Invalid action." << endl;
                            Sleep(midWait);
                        }
                    }
                    else
                    {
                        cout << dir.consumableDirectory[hero.inventory[intChoice-1]-200].getName() << " | " << dir.consumableDirectory[hero.inventory[intChoice-1]-200].getDesc() << endl;
                        cout << "RARITY: " << dir.consumableDirectory[hero.inventory[intChoice-1]-200].getRarity() << endl << endl;
                        cout << "What do you want to do to " << dir.getItemName(hero.inventory[intChoice-1]) << "?" << endl;
                        cout << "1) DROP" << endl;
                        cout << "0) RETURN" << endl;
                        strChoice = getch();
                        if(strChoice=="1")
                        {
                            hero.inventory.erase(hero.inventory.begin()+intChoice-1);
                        }
                        else if(strChoice!="0")
                        {
                            cout << "Invalid action." << endl;
                            Sleep(midWait);
                        }
                    }
                }
                else
                {
                    cout << "Invalid item." << endl;
                    Sleep(midWait);
                }
            }while(nav==0);
            nav = 0;
        }
        else if(intChoice==5)
        {
            do{
                nav = 0;
                spellbookMenu(hero.spellbook,dir);
                cout << "SELECT: ";
                if(hero.spellbook.size()>9)
                    cin >> strChoice;
                else
                    strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                /*if(intChoice<=0&&intChoice>=29)
                {
                    cout << "Please input an integer." << endl;
                    Sleep(1000);
                    continue;
                }*/
                if(intChoice<=hero.spellbook.size())
                {
                    if(intChoice==0)
                        break;
                    cout << dir.getItemName(hero.spellbook[intChoice-1]) << " | " << dir.getItemDesc(hero.spellbook[intChoice-1]) << endl;
                    cout << "RARITY: " << dir.getItemRarity(hero.spellbook[intChoice-1]) << endl;
                    if(hero.spellbook[intChoice-1]<=314)
                    {
                        if((hero.magicTraining==0&&(hero.spellbook[intChoice-1]%3==2))||
                           (hero.magicTraining==1&&(hero.spellbook[intChoice-1]%3==1))||
                           (hero.magicTraining==2&&(hero.spellbook[intChoice-1]%3==0)))
                        {
                            cout << "MANA COST: " << dir.attackSpellDirectory[hero.spellbook[intChoice-1]-300].getManaCost()-1 << endl;
                            cout << "DAMAGE: " << dir.attackSpellDirectory[hero.spellbook[intChoice-1]-300].getDMG()+2 << endl;
                        }
                        else
                        {
                            cout << "MANA COST: " << dir.attackSpellDirectory[hero.spellbook[intChoice-1]-300].getManaCost() << endl;
                            cout << "DAMAGE: " << dir.attackSpellDirectory[hero.spellbook[intChoice-1]-300].getDMG() << endl;
                        }
                    }
                    else if(hero.spellbook[intChoice-1]<=320)
                    {
                        cout << "MANA COST: " << dir.healingSpellDirectory[hero.spellbook[intChoice-1]-315].getManaCost() << endl;
                        cout << "HEALING: " << dir.healingSpellDirectory[hero.spellbook[intChoice-1]-315].getHPR() << endl;
                    }
                    else
                    {
                        cout << "MANA COST: " << dir.buffSpellDirectory[hero.spellbook[intChoice-1]-321].getManaCost() << endl;
                        if(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-321].getATKU()>0)
                            cout << "ATK BUFF: " << dir.buffSpellDirectory[hero.spellbook[intChoice-1]-321].getATKU() << endl;
                        if(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-321].getDEFU()>0)
                            cout << "DEF BUFF: " << dir.buffSpellDirectory[hero.spellbook[intChoice-1]-321].getDEFU() << endl;
                        if(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-321].getCRTU()>0)
                            cout << "CRT BUFF: " << dir.buffSpellDirectory[hero.spellbook[intChoice-1]-321].getCRTU() << endl;
                        if(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-321].getACCU()>0)
                            cout << "ACC BUFF: " << dir.buffSpellDirectory[hero.spellbook[intChoice-1]-321].getACCU() << endl;
                        if(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-321].getDDGU()>0)
                            cout << "DDG BUFF: " << dir.buffSpellDirectory[hero.spellbook[intChoice-1]-321].getDDGU() << endl;
                    }

                    cout << endl << "What do you want to do to " << dir.getItemName(hero.spellbook[intChoice-1]) << "?" << endl;
                    if(hero.spellbook[intChoice-1]==315||hero.spellbook[intChoice-1]==316||hero.spellbook[intChoice-1]==319)
                        cout << "1) USE" << endl;
                    cout << "0) RETURN" << endl;
                    strChoice = getch();
                    if(strChoice=="1"&&(hero.spellbook[intChoice-1]==315||hero.spellbook[intChoice-1]==316||hero.spellbook[intChoice-1]==319))
                    {
                        if(hero.getMP()>=dir.healingSpellDirectory[hero.spellbook[intChoice-1]-315].getManaCost())
                        {
                            hero.changeHP(dir.healingSpellDirectory[hero.spellbook[intChoice-1]-315].getHPR());
                            hero.changeMP(-(dir.healingSpellDirectory[hero.spellbook[intChoice-1]-315].getManaCost()));
                            if(hero.getHP()>hero.getMHP())
                                hero.setHP(hero.getMHP());
                            cout << "You regained " << dir.healingSpellDirectory[hero.spellbook[intChoice-1]-315].getHPR() << " HP!" << endl;
                            Sleep(midWait);
                        }
                        else
                            cout << "You don't have enough mana." << endl;
                    }
                    else if(strChoice!="0")
                    {
                        cout << "Invalid action." << endl;
                        Sleep(midWait);
                    }
                }
                else
                {
                    cout << "Invalid spell." << endl;
                    Sleep(midWait);
                }
            }while(nav==0);
            nav = 0;
        }
        else if(intChoice==6)
        {
            if(end!=2)
                cout << "Are you sure you want to quit? Your progress will be saved under your name. (y/n)";
            else
                cout << "Give up? (y/n)";
            strChoice = getch();
            if(strChoice=="y")
                nav = -1;
        }
        else
        {
            cout << "Unknown command. Try one of the options on screen!" << endl;
            Sleep(midWait);
        }
    }while(nav==0);
    return nav;
}

int storeMenuHandler(Player &hero,Directory dir,Room &currentRoom)
{
    if(currentRoom.store.getLevel()==-1)
    {
        cout << "No store in this room." << endl;
        Sleep(longWait);
        return -1;
    }
    int instore = 1;
    int intChoice;
    int chck;
    string strChoice;
    vector<string> statDown;
    vector<string> statUp;
    vector<int> curStatDown;
    vector<int> curStatUp;
    while(instore==1)
    {
        if(currentRoom.store.getType()==0)
        {
            storeMenu(hero,currentRoom.store,dir);
            chck = 0;
            cout << "MENU: ";
            strChoice = getch();
            std::stringstream stoi(strChoice);
            stoi >> intChoice;
            if(intChoice==0)
                instore = 0;
            else if(intChoice>0&&intChoice<=currentRoom.store.storeInventory.size())
            {
                if(currentRoom.store.storeInventory[intChoice-1]<100)
                {
                    cout << dir.getItemName(currentRoom.store.storeInventory[intChoice-1]) << " | " << dir.getItemDesc(currentRoom.store.storeInventory[intChoice-1]) << endl;
                    cout << "RARITY: " << dir.weaponDirectory[currentRoom.store.storeInventory[intChoice-1]].getRarity() << endl;
                    if((hero.meleeTraining==0&&(dir.getItemName(currentRoom.store.storeInventory[intChoice-1]).find("Dagger")!=string::npos||dir.getItemName(currentRoom.store.storeInventory[intChoice-1]).find("Knife")!=string::npos||dir.getItemName(currentRoom.store.storeInventory[intChoice-1]).find("Aerolinde")!=string::npos))||
                       (hero.meleeTraining==1&&(dir.getItemName(currentRoom.store.storeInventory[intChoice-1]).find("Spear")!=string::npos||dir.getItemName(currentRoom.store.storeInventory[intChoice-1]).find("Pike")!=string::npos||dir.getItemName(currentRoom.store.storeInventory[intChoice-1]).find("Hyliat")!=string::npos))||
                       (hero.meleeTraining==2&&(dir.getItemName(currentRoom.store.storeInventory[intChoice-1]).find("Sword")!=string::npos||dir.getItemName(currentRoom.store.storeInventory[intChoice-1]).find("Saber")!=string::npos||dir.getItemName(currentRoom.store.storeInventory[intChoice-1]).find("Pyrithia")!=string::npos))||
                       (hero.meleeTraining==3&&(dir.getItemName(currentRoom.store.storeInventory[intChoice-1]).find("Axe")!=string::npos||dir.getItemName(currentRoom.store.storeInventory[intChoice-1]).find("Club")!=string::npos||dir.getItemName(currentRoom.store.storeInventory[intChoice-1]).find("Teratra")!=string::npos)))
                    {
                        cout << "STR: " << dir.weaponDirectory[currentRoom.store.storeInventory[intChoice-1]].getStr()+2 << endl;
                        cout << "ACC: " << dir.weaponDirectory[currentRoom.store.storeInventory[intChoice-1]].getAcc()+5 << endl;
                        cout << "CRIT: " << dir.weaponDirectory[currentRoom.store.storeInventory[intChoice-1]].getCrt()+5 << endl;
                    }
                    else
                    {
                        cout << "STR: " << dir.weaponDirectory[currentRoom.store.storeInventory[intChoice-1]].getStr() << endl;
                        cout << "ACC: " << dir.weaponDirectory[currentRoom.store.storeInventory[intChoice-1]].getAcc() << endl;
                        cout << "CRIT: " << dir.weaponDirectory[currentRoom.store.storeInventory[intChoice-1]].getCrt() << endl;
                    }
                    if(dir.weaponDirectory[currentRoom.store.storeInventory[intChoice-1]].getMA()!=0)
                        cout << "MAGIC AMP: +" << dir.weaponDirectory[currentRoom.store.storeInventory[intChoice-1]].getMA() << "%" << endl;

                }
                else if(currentRoom.store.storeInventory[intChoice-1]<200)
                {
                    cout << dir.getItemName(currentRoom.store.storeInventory[intChoice-1]) << " | " << dir.getItemDesc(currentRoom.store.storeInventory[intChoice-1]) << endl;
                    cout << "RARITY: " << dir.armorDirectory[currentRoom.store.storeInventory[intChoice-1]-100].getRarity() << endl;
                    cout << "DEF: " << dir.armorDirectory[currentRoom.store.storeInventory[intChoice-1]-100].getDef() << endl;
                    cout << "DDG: " << dir.armorDirectory[currentRoom.store.storeInventory[intChoice-1]-100].getDdg() << endl;
                    if(dir.armorDirectory[currentRoom.store.storeInventory[intChoice-1]-100].getMG()!=0)
                        cout << "MANA REGEN: " << dir.armorDirectory[currentRoom.store.storeInventory[intChoice-1]-100].getMG()  << endl;
                }
                else if(currentRoom.store.storeInventory[intChoice-1]<300)
                {
                    cout << dir.consumableDirectory[currentRoom.store.storeInventory[intChoice-1]-200].getName() << " | " << dir.consumableDirectory[currentRoom.store.storeInventory[intChoice-1]-200].getDesc() << endl;
                    cout << "RARITY: " << dir.consumableDirectory[currentRoom.store.storeInventory[intChoice-1]-200].getRarity() << endl;
                    cout << "HP: " << dir.consumableDirectory[currentRoom.store.storeInventory[intChoice-1]-200].getHP() << endl;
                    cout << "MP: " << dir.consumableDirectory[currentRoom.store.storeInventory[intChoice-1]-200].getMP() << endl;
                }
                else if(currentRoom.store.storeInventory[intChoice-1]<400)
                {
                    cout << dir.getItemName(currentRoom.store.storeInventory[intChoice-1]) << " | " << dir.getItemDesc(currentRoom.store.storeInventory[intChoice-1]) << endl;
                    cout << "RARITY: " << dir.getItemRarity(currentRoom.store.storeInventory[intChoice-1]) << endl;
                    if(currentRoom.store.storeInventory[intChoice-1]<315)
                    {
                        if((hero.magicTraining==0&&(currentRoom.store.storeInventory[intChoice-1]%3==2))||
                           (hero.magicTraining==1&&(currentRoom.store.storeInventory[intChoice-1]%3==1))||
                           (hero.magicTraining==2&&(currentRoom.store.storeInventory[intChoice-1]%3==0)))
                        {
                            cout << "MANA COST: " << dir.attackSpellDirectory[currentRoom.store.storeInventory[intChoice-1]-300].getManaCost()-1 << endl;
                            cout << "DAMAGE: " << dir.attackSpellDirectory[currentRoom.store.storeInventory[intChoice-1]-300].getDMG()+2 << endl;
                        }
                        else
                        {
                            cout << "MANA COST: " << dir.attackSpellDirectory[currentRoom.store.storeInventory[intChoice-1]-300].getManaCost() << endl;
                            cout << "DAMAGE: " << dir.attackSpellDirectory[currentRoom.store.storeInventory[intChoice-1]-300].getDMG() << endl;
                        }
                    }
                    else if(currentRoom.store.storeInventory[intChoice-1]<321)
                    {
                        cout << "MANA COST: " << dir.healingSpellDirectory[currentRoom.store.storeInventory[intChoice-1]-315].getManaCost() << endl;
                        cout << "HEALING: " << dir.healingSpellDirectory[currentRoom.store.storeInventory[intChoice-1]-315].getHPR() << endl;
                    }
                    else
                    {
                        cout << "MANA COST: " << dir.buffSpellDirectory[currentRoom.store.storeInventory[intChoice-1]-321].getManaCost() << endl;
                        if(dir.buffSpellDirectory[currentRoom.store.storeInventory[intChoice-1]-321].getATKU()>0)
                            cout << "ATK BUFF: " << dir.buffSpellDirectory[currentRoom.store.storeInventory[intChoice-1]-321].getATKU() << endl;
                        if(dir.buffSpellDirectory[currentRoom.store.storeInventory[intChoice-1]-321].getDEFU()>0)
                            cout << "DEF BUFF: " << dir.buffSpellDirectory[currentRoom.store.storeInventory[intChoice-1]-321].getDEFU() << endl;
                        if(dir.buffSpellDirectory[currentRoom.store.storeInventory[intChoice-1]-321].getCRTU()>0)
                            cout << "CRT BUFF: " << dir.buffSpellDirectory[currentRoom.store.storeInventory[intChoice-1]-321].getCRTU() << endl;
                        if(dir.buffSpellDirectory[currentRoom.store.storeInventory[intChoice-1]-321].getACCU()>0)
                            cout << "ACC BUFF: " << dir.buffSpellDirectory[currentRoom.store.storeInventory[intChoice-1]-321].getACCU() << endl;
                        if(dir.buffSpellDirectory[currentRoom.store.storeInventory[intChoice-1]-321].getDDGU()>0)
                            cout << "DDG BUFF: " << dir.buffSpellDirectory[currentRoom.store.storeInventory[intChoice-1]-321].getDDGU() << endl;
                    }
                }
                else
                {
                    cout << dir.ringDirectory[currentRoom.store.storeInventory[intChoice-1]-400].getName() << " | " << dir.ringDirectory[currentRoom.store.storeInventory[intChoice-1]-400].getDesc() << endl;
                    cout << "RARITY: " << dir.ringDirectory[currentRoom.store.storeInventory[intChoice-1]-400].getRarity() << endl;
                    if(dir.ringDirectory[currentRoom.store.storeInventory[intChoice-1]-400].getAct()>0)
                        cout << "ACTIVATION RATE: " << dir.ringDirectory[currentRoom.store.storeInventory[intChoice-1]-400].getAct() << "%" << endl;
                    if(dir.ringDirectory[currentRoom.store.storeInventory[intChoice-1]-400].getHPR()>0)
                        cout << "HP REGEN: " << dir.ringDirectory[currentRoom.store.storeInventory[intChoice-1]-400].getHPR() << endl;
                    if(dir.ringDirectory[currentRoom.store.storeInventory[intChoice-1]-400].getMPR()>0)
                        cout << "MP REGEN: " << dir.ringDirectory[currentRoom.store.storeInventory[intChoice-1]-400].getMPR() << endl;
                }
                cout << "PRICE: " << currentRoom.store.storeCost[intChoice-1] << endl << endl;
                cout << "Would you like to purchase this item? (y/n)" << endl;
                strChoice = getch();
                if(strChoice=="y"||strChoice=="Y")
                {
                    if(hero.gold<currentRoom.store.storeCost[intChoice-1])
                    {
                        cout << "You cannot afford this item." << endl;
                        Sleep(midWait);
                    }
                    else if(currentRoom.store.storeInventory[intChoice-1]<200||currentRoom.store.storeInventory[intChoice-1]>=400)
                    {
                        if(hero.equipment.size()>=6)
                        {
                            cout << "Your inventory is full." << endl;
                            Sleep(midWait);
                        }
                        else
                        {
                            hero.equipment.push_back(currentRoom.store.storeInventory[intChoice-1]);
                            cout << "You got the " << dir.getItemName(currentRoom.store.storeInventory[intChoice-1]) << "!" << endl;
                            hero.gold -= currentRoom.store.storeCost[intChoice-1];
                            currentRoom.store.storeInventory.erase(currentRoom.store.storeInventory.begin()+intChoice-1);
                            currentRoom.store.storeCost.erase(currentRoom.store.storeCost.begin()+intChoice-1);
                            Sleep(midWait);
                        }
                    }
                    else if(currentRoom.store.storeInventory[intChoice-1]<300)
                    {
                        if(hero.inventory.size()>=6)
                        {
                            cout << "Your inventory is full." << endl;
                            Sleep(midWait);
                        }
                        else
                        {
                            hero.inventory.push_back(currentRoom.store.storeInventory[intChoice-1]);
                            cout << "You got the " << dir.getItemName(currentRoom.store.storeInventory[intChoice-1]) << "!" << endl;
                            hero.gold -= currentRoom.store.storeCost[intChoice-1];
                            currentRoom.store.storeInventory.erase(currentRoom.store.storeInventory.begin()+intChoice-1);
                            currentRoom.store.storeCost.erase(currentRoom.store.storeCost.begin()+intChoice-1);
                            Sleep(midWait);
                        }
                    }
                    else
                    {
                        for(int i=0;i<hero.spellbook.size();i++)
                        {
                            if(hero.spellbook[i]==currentRoom.store.storeInventory[intChoice-1])
                            {
                                cout << "You already know this spell." << endl;
                                Sleep(midWait);
                                chck = 1;
                            }
                        }
                        if(chck==0)
                        {
                            hero.spellbook.push_back(currentRoom.store.storeInventory[intChoice-1]);
                            cout << "You got the " << dir.getItemName(currentRoom.store.storeInventory[intChoice-1]) << "!" << endl;
                            hero.gold -= currentRoom.store.storeCost[intChoice-1];
                            currentRoom.store.storeInventory.erase(currentRoom.store.storeInventory.begin()+intChoice-1);
                            currentRoom.store.storeCost.erase(currentRoom.store.storeCost.begin()+intChoice-1);
                            Sleep(midWait);
                        }
                    }
                }
            }
            else
            {
                cout << "Invalid choice." << endl;
                Sleep(midWait);
            }
        }
        else if(currentRoom.store.getType()==1)
        {
            diviningMenu(hero,currentRoom.store,dir);
            for(int i=0;i<2;i++)
            {
                statDown.push_back("");
                statUp.push_back("");
                curStatUp.push_back(0);
                curStatDown.push_back(0);
                switch(currentRoom.store.getStatDown()[i])
                {
                    case 0:
                        statDown[i] = "ATK";
                        curStatDown[i] = hero.getNSTR();
                    break;
                    case 1:
                        statDown[i] = "DEF";
                        curStatDown[i] = hero.getNDEF();
                    break;
                    case 2:
                        statDown[i] = "CRT";
                        curStatDown[i] = hero.getNCRT();
                    break;
                    case 3:
                        statDown[i] = "DDG";
                        curStatDown[i] = hero.getNDDG();
                    break;
                    case 4:
                        statDown[i] = "MHP";
                        curStatDown[i] = hero.getMHP();
                    break;
                    case 5:
                        statDown[i] = "MMP";
                        curStatDown[i] = hero.getMMP();
                    break;
                }
                switch(currentRoom.store.getStatUp()[i])
                {
                    case 0:
                        statUp[i] = "ATK";
                        curStatUp[i] = hero.getNSTR();
                    break;
                    case 1:
                        statUp[i] = "DEF";
                        curStatUp[i] = hero.getNDEF();
                    break;
                    case 2:
                        statUp[i] = "CRT";
                        curStatUp[i] = hero.getNCRT();
                    break;
                    case 3:
                        statUp[i] = "DDG";
                        curStatUp[i] = hero.getNDDG();
                    break;
                    case 4:
                        statUp[i] = "MHP";
                        curStatUp[i] = hero.getMHP();
                    break;
                    case 5:
                        statUp[i] = "MMP";
                        curStatUp[i] = hero.getMMP();
                    break;
                }
            }
            chck = 0;
            cout << "MENU: ";
            strChoice = getch();
            std::stringstream stoi(strChoice);
            stoi >> intChoice;
            if(intChoice==0)
                instore = 0;
            if(intChoice==1)
            {
                if(hero.gold<currentRoom.store.getSwapCost())
                {
                    cout << "You cannot afford to divine." << endl;
                    Sleep(midWait);
                }
                else if(curStatDown[0]<2)
                {
                    cout << "You don't have enough " << statDown[0] << "." << endl;
                    Sleep(midWait);
                }
                else
                {
                    switch(currentRoom.store.getStatDown()[0])
                    {
                        case 0:
                            hero.setNSTR(curStatDown[0]-2);
                        break;
                        case 1:
                            hero.setNDEF(curStatDown[0]-2);
                        break;
                        case 2:
                            hero.setNCRT(curStatDown[0]-2);
                        break;
                        case 3:
                            hero.setNDDG(curStatDown[0]-2);
                        break;
                        case 4:
                            hero.setMHP(curStatDown[0]-2);
                        break;
                        case 5:
                            hero.setMMP(curStatDown[0]-2);
                        break;
                    }
                    switch(currentRoom.store.getStatUp()[0])
                    {
                        case 0:
                            hero.setNSTR(curStatUp[0]+1);
                        break;
                        case 1:
                            hero.setNDEF(curStatUp[0]+1);
                        break;
                        case 2:
                            hero.setNCRT(curStatUp[0]+1);
                        break;
                        case 3:
                            hero.setNDDG(curStatUp[0]+1);
                        break;
                        case 4:
                            hero.setMHP(curStatUp[0]+1);
                        break;
                        case 5:
                            hero.setMMP(curStatUp[0]+1);
                        break;
                    }
                    hero.gold -= currentRoom.store.getSwapCost();
                    currentRoom.store.incStatCount();
                    cout << "Reduced " << statDown[0] << " by 2, and raised " << statUp[0] << " by 1!" << endl;
                }
                Sleep(midWait);
            }
            if(intChoice==2)
            {
                if(hero.gold<currentRoom.store.getSwapCost())
                {
                    cout << "You cannot afford to divine." << endl;
                    Sleep(midWait);
                }
                else if(curStatDown[1]<2)
                {
                    cout << "You don't have enough " << statDown[1] << "." << endl;
                    Sleep(midWait);
                }
                else
                {
                    switch(currentRoom.store.getStatDown()[1])
                    {
                        case 0:
                            hero.setNSTR(curStatDown[1]-2);
                        break;
                        case 1:
                            hero.setNDEF(curStatDown[1]-2);
                        break;
                        case 2:
                            hero.setNCRT(curStatDown[1]-2);
                        break;
                        case 3:
                            hero.setNDDG(curStatDown[1]-2);
                        break;
                        case 4:
                            hero.setMHP(curStatDown[1]-2);
                        break;
                        case 5:
                            hero.setMMP(curStatDown[1]-2);
                        break;
                    }
                    switch(currentRoom.store.getStatUp()[1])
                    {
                        case 0:
                            hero.setNSTR(curStatUp[1]+1);
                        break;
                        case 1:
                            hero.setNDEF(curStatUp[1]+1);
                        break;
                        case 2:
                            hero.setNCRT(curStatUp[1]+1);
                        break;
                        case 3:
                            hero.setNDDG(curStatUp[1]+1);
                        break;
                        case 4:
                            hero.setMHP(curStatUp[1]+1);
                        break;
                        case 5:
                            hero.setMMP(curStatUp[1]+1);
                        break;
                    }
                    hero.gold -= currentRoom.store.getSwapCost();
                    currentRoom.store.incStatCount();
                    cout << "Reduced " << statDown[1] << " by 2, and raised " << statUp[1] << " by 1!" << endl;
                }
                Sleep(midWait);
            }
        }
    }
    return 0;
}

int throneDefense(Player &hero, Directory dir, bool debug_opt, bool &gankTracker)
{
    int kills = 0;
    string action;
    string target;
    string holder;
    int gd;
    int ex;
    int err;
    Creature enemy = dir.creatureDirectory[54];
    std::system("cls");
    cout << "After some time waiting, your first challenger approaches. A hero stands before you." << endl << endl;
    godMode = 0;
    while(1==1)
    {
        if(hero.getHP()>hero.getMHP())
            hero.setHP(hero.getMHP());
        if(hero.getMP()>hero.getMMP())
            hero.setMP(hero.getMMP());
        if(hero.exp>=hero.getEXPGoal())
            hero.levelUp();
        cout << endl << "What do you do?" << endl;
        cin >> action;
        err = actionHandler(action,debug_opt,gankTracker);
        if(err==1) //Look
        {
            std::getline(cin,target);
            while(target=="")
            {
                cout << endl << "Select a target: ";
                std::getline(cin,target);
            }
            if(target.front()==' ')
                target.erase(target.begin());
            if(target!="hero"&&target!="challenger"&&target!="traveler"&&target!="enemy"&&target!="monster")
                continue;

            if(hero.mask.getID()==2) //Darkness
            {
                holder = "Silhouette | Level ??\n";
                holder += "HP: ??\n";
                holder += "Strength: ??\n";
                holder += "Accuracy: ??\n";
                holder += "Defense: ??\n";
                holder += "Dodge: ??";
            }
            else
            {
                holder = "Hero | Level ";

                int monDmg = enemy.getSTR() - hero.getDEF();
                int monHit = enemy.getACC() - hero.getDDG();
                int heroDmg = hero.getSTR() - enemy.getDEF();
                int heroHit = hero.getACC() -enemy.getDDG();

                if(hero.eqpWpn.getID()==57)
                    heroDmg = ceil(static_cast<float>(enemy.getHP())*.35);
                if(hero.eqpAmr.getID()==142)
                    monDmg -= monDmg/4;

                if(hero.mask.getID()==6)
                    heroDmg = heroDmg + (heroDmg/2);
                if(hero.mask.getID()==5) //Whispers
                    monDmg = static_cast<float>(monDmg)*1.5;
                if((hero.meleeTraining==0&&(hero.eqpWpn.getName().find("Dagger")!=string::npos||hero.eqpWpn.getName().find("Knife")!=string::npos||hero.eqpWpn.getName().find("Aerolinde")!=string::npos))||
                   (hero.meleeTraining==1&&(hero.eqpWpn.getName().find("Spear")!=string::npos||hero.eqpWpn.getName().find("Pike")!=string::npos||hero.eqpWpn.getName().find("Hyliat")!=string::npos))||
                   (hero.meleeTraining==2&&(hero.eqpWpn.getName().find("Sword")!=string::npos||hero.eqpWpn.getName().find("Saber")!=string::npos||hero.eqpWpn.getName().find("Pyrithia")!=string::npos))||
                   (hero.meleeTraining==3&&(hero.eqpWpn.getName().find("Axe")!=string::npos||hero.eqpWpn.getName().find("Club")!=string::npos||hero.eqpWpn.getName().find("Teratra")!=string::npos)))
                {
                    heroDmg += 2;
                    heroHit += 5;
                }

                holder += "HP: " + std::to_string(enemy.getHP()) + "\n";
                holder += "Strength: " + std::to_string(enemy.getSTR()) + " (Enemy DMG: " + std::to_string(monDmg) + ")\n";
                holder += "Accuracy: " + std::to_string(enemy.getACC()) + " (Enemy Hit Rate: " + std::to_string(monHit) + ")\n";
                holder += "Defense: " + std::to_string(enemy.getDEF()) + " (Your DMG: " + std::to_string(heroDmg) + ")\n";
                holder += "Dodge: " + std::to_string(enemy.getDDG()) + " (Your Hit Rate: " + std::to_string(heroHit) + ")\n";

                cout << holder << endl;
            }
        }
        else if(err==3) //Fight
        {
            std::getline(cin,target);
            while(target=="")
            {
                cout << endl << "Select a target: ";
                std::getline(cin,target);
            }
            if(target.front()==' ')
                target.erase(target.begin());
            if(target!="hero"&&target!="challenger"&&target!="traveler"&&target!="enemy"&&target!="monster")
                continue;
            gd = goldPicker(enemy.getLEV());
            ex = expPicker(enemy.getLEV());
            if(hero.mask.getID()==7) //Souls
                ex = ex*3;
            pass = combatHandler(hero,enemy,dir,gd,ex,debug_opt);
            switch(pass)
            {
                case 1:
                    kills++;
                    if(kills>=10)
                    {
                        cout << "Next." << endl;
                        ach.CurseBearer = 1;
                        Sleep(longWait);
                    }
                    else
                    {
                        cout << "Another defeated." << endl;
                        Sleep(shortWait);
                        cout << "You wait for the next challenger... time passes." << endl;
                        Sleep(shortWait);
                        cout << "You are not sure how many days, months, or years have passed, but you finally see another challenger enter the room." << endl;
                        Sleep(shortWait);
                        switch(kills)
                        {
                            case 0:case 1:case 2:
                                cout << "You stand up from your throne, axe in hand, eager to show the foolish one what true power really is." << endl;
                                break;
                            case 3:case 4:
                                cout << "You stand up slowly, axe in hand. You let out a sigh, and ready for battle." << endl;
                                break;
                            case 5:case 6:
                                cout << "You arise slowly from the throne. Hoping this one will finally be strong enough to end you, you raise your axe and ready for combat." << endl;
                                break;
                            default:
                                cout << "You stand up from the throne, feeling numb. You pray that this will be the one to end your suffering." << endl;
                                break;
                        }
                        enemy = dir.creatureDirectory[54];

                        enemy.setHP(enemy.getHP()+(kills*3));
                        enemy.setSTR(enemy.getSTR()+(kills*2));
                        enemy.setACC(enemy.getACC()+(kills*2));
                        enemy.setDEF(enemy.getDEF()+(kills*2));
                        enemy.setDDG(enemy.getDDG()+(kills*2));
                        Sleep(longWait);
                    }
                    break;
                case 2:
                    return kills;
            }
            godMode = 0;
        }
        else if(err==12) //GODMODE
        {
            if(!godMode)
            {
                cout << "God mode enabled. ATK and DEF have been maxed out in combat for this room." << endl;
                godMode = 1;
            }
            else
            {
                cout << "God mode disabled." << endl;
                godMode = 0;
            }
        }
        else if(err==15)
        {
            std::getline(cin,target);
            while(target=="")
            {
                cout << endl << "Select a speed: ";
                std::getline(cin,target);
            }
            if(target.front()==' ')
                target.erase(target.begin());
            if(target=="slow"||target=="long")
            {
                shortWait = 1500;
                midWait = 3000;
                longWait = 4500;
                cout << "Game speed set to slow." << endl;
            }
            else if(target=="normal"||target=="regular"||target=="medium")
            {
                shortWait = 1000;
                midWait = 2000;
                longWait = 3000;
                cout << "Game speed set to normal." << endl;
            }
            else if(target=="fast"||target=="short")
            {
                shortWait = 500;
                midWait = 1000;
                longWait = 1500;
                cout << "Game speed set to fast." << endl;
            }
            else
            {
                cout << "Invalid speed. Try: slow, normal, fast" << endl;
            }
        }
        else if(err==4)
        {
            err = menuHandler(hero,dir);
            clear();
            if(err==-1) //Writing Save File
            {
                return kills;
            }
            else
            {
                cout << "The hero stands ready for battle." << endl;
            }
        }
        else if(err==8)
        {
            cout << endl;
            cout << "Actions:" << endl;
            cout << "    MOVE: move <target>" << endl;
            cout << "        -Synonyms: Go, Enter, Leave, Walk, Next" << endl;
            cout << "        -Meaning: Used to enter a new area." << endl;
            cout << "        -EG: enter door" << endl;
            cout << "    LOOK: look <target>" << endl;
            cout << "        -Synonyms: Check, Examine, See" << endl;
            cout << "        -Meaning: Used to examine a feature in the room." << endl;
            cout << "        -EG: check crates" << endl;
            cout << "    GET: get <target>" << endl;
            cout << "        -Synonyms: Take, Grab, Add" << endl;
            cout << "        -Meaning: Used to acquire a new item." << endl;
            cout << "        -EG: get wooden sword" << endl;
            cout << "    ATTACK: attack <target>" << endl;
            cout << "        -Synonyms: Fight, Strike, Kill, Gank" << endl;
            cout << "        -Meaning: Used to engage in combat with a creature." << endl;
            cout << "        -EG: attack ogre" << endl;
            cout << "    MENU: menu" << endl;
            cout << "        -Synonyms: Inventory, Pause, M, Items" << endl;
            cout << "        -Meaning: Opens up your menu." << endl;
            cout << "        -EG: menu" << endl;
            cout << "    SAVE: save" << endl;
            cout << "        -Synonyms: (None)" << endl;
            cout << "        -Meaning: Enables/Disables manual saving (Autosave enabled by default)." << endl;
            cout << "        -EG: save" << endl;
            cout << "    SPEED: speed <speed>" << endl;
            cout << "        -Synonyms: Delay, Textspeed, Gamespeed" << endl;
            cout << "        -Meaning: Sets the speed of the gameplay to either slow, normal, or fast." << endl;
            cout << "        -EG: speed fast" << endl;
            cout << "    HELP: help" << endl;
            cout << "        -Synonyms: Manual, H, Guide, Instructions" << endl;
            cout << "        -Meaning: Opens a guide to actions." << endl;
            cout << "        -EG: help" << endl;
            cout << endl;
            cout << "For further help, consult the REAMDE file in the game files." << endl << endl;
        }
    }

}

Room advance(int &depth, bool &itemDrop, int &adv, int &diff, int &rew, int &karma, Player &hero, int &pass, bool &win, Directory dir, int &boss, vector<bool> &mStatus, vector<bool> &rStatus, vector<bool> &reStatus, vector<bool> &iStatus, bool &dev)
{
    double percDmgDone;
    double percDmgTook;
    score += 100;
    depth++;
    ach.Vale++;
    itemDrop = 0;
    godMode = 0;
    if(depth%5==0)
    {
        if(adv<10)
            adv++;
    }
    if(hero.mask.getID()==1)
        karma -= 2;
    if(rand()%5==0)
        encounterHandler(hero,dir,adv,depth,reStatus);
    roomLogic(diff,rew,karma,adv,hero);
    std::system("cls");
    cout << "Room " << depth << endl;
    if(depth==55&&win==0)
        diff = 5;
    else if(depth>55&&depth<80)
        diff = 6;
    else if(depth>=80)
        diff = 7;

    if(diff==0)
        pass = 1;
    else
        pass = 0;

    if(dev==1)
    {
        dev = 0;
        diff = 8;
    }
    Room currentRoom;
    currentRoom = roomGenerator(diff,rew,adv,dir,hero,mStatus,rStatus);
    //cout << "Karma: " << karma << endl;
    if(((depth/5)+1)>11&&currentRoom.monster.getName()!="Valentereth, the Tyrant"&&currentRoom.monster.getName()!="Termineth, the Watcher")
    {
        int egHPBuff = ((depth/5)-11)*6;
        int egStrBuff = ((depth/5)-11)*4;
        int egAccBuff = ((depth/5)-11)*3;
        int egDefBuff = ((depth/5)-11)*4;
        int egDdgBuff = ((depth/5)-11)*2;

        currentRoom.monster.setHP(currentRoom.monster.getHP()+egHPBuff);
        currentRoom.monster.setSTR(currentRoom.monster.getSTR()+egStrBuff);
        currentRoom.monster.setACC(currentRoom.monster.getACC()+egAccBuff);
        currentRoom.monster.setDEF(currentRoom.monster.getDEF()+egDefBuff);
        currentRoom.monster.setDDG(currentRoom.monster.getDDG()+egDdgBuff);
    }
    if(currentRoom.monster.getName()=="Valentereth, the Tyrant"&&win==0)
        boss = 1;
    if(currentRoom.monster.getName()=="Termineth, the Watcher")
        boss = 2;
    for(int i=0;i<iStatus.size();i++)
        iStatus[i] = 0;

    percDmgDone = (hero.getSTR()-currentRoom.monster.getDEF())/currentRoom.monster.getHP();
    percDmgTook = (currentRoom.monster.getSTR()-hero.getDEF())/hero.getMHP();
    if(adv>=5)
    {
        if(percDmgTook>percDmgDone*3)
            karma += 2;
        if(percDmgTook>percDmgDone*4)
            karma += 2;
        if(percDmgDone>percDmgTook*3)
            karma -= 2;
        if(percDmgDone>percDmgTook*4)
            karma -= 2;
    }

    //cout << "Diff: " << diff << endl;
    //cout << "Adv: " << adv << endl;
    //cout << "Karma: " << karma << endl;
    return currentRoom;
}
