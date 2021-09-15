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
#include "ItemClasses.h"
#include "ItemList.h"
#include "CreatureList.h"
#include "SpellList.h"
#include "FeatureList.h"
#include "RoomList.h"
#include "RoomGen.h"
#include "MenuIllustrations.h"
#include "InteractionHandler.h"
#include "RoomLogic.h"
#include "CombatHandler.h"
#include "GoldPicker.h"

int actionHandler(string act);  //Done!
int combatHandler(); //Done!
int menuHandler(Player &hero,Directory dir); //Done!
int storeMenuHandler(Player &hero,Directory dir,Room &currentRoom);
void saveFunc(Player &hero, string filename, int depth);
bool hiscores(Player &hero, int depth);

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
    Directory dir(weaponDirectory,armorDirectory,consumableDirectory,maskDirectory,attackSpellDirectory,healingSpellDirectory,buffSpellDirectory,creatureDirectory,featureDirectory,roomDirectory);

    string strChoice;
    int intChoice;
    int mask=-1;
    bool good=0;
    bool men;
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
                scores();
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice==0)
                    men = 1;
            }
        }
        if(intChoice==4)
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
                        Sleep(2000);
                    }
                }
                else if(intChoice==9)
                {
                    if(mask>=0)
                    {
                        mask = -1;
                        cout << "You removed your mask." << endl;
                        Sleep(2000);
                    }
                    else
                    {
                        cout << "You aren't wearing a mask." << endl;
                        Sleep(2000);
                    }
                }
                else if(intChoice==0)
                {
                    men = 1;
                }
                else
                {
                    cout << "Invalid command." << endl;
                    Sleep(2000);
                }
            }
        }
    }

    string name;
    string filename;
    int saveStats[16];
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
        saveStats[9] = 0;
        saveStats[10] = 0;
        saveStats[11] = 1;
        saveStats[12] = 0;
        saveStats[13] = -1;
        saveStats[14] = -1;
        saveStats[15] = -1;
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
                while(std::getline(savedata,save))
                {
                    std::stringstream data(save);
                    saveFound = 1;
                    for(int i=0;i<16;i++)
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
                cout << "Name: " << name << endl;
                cout << "Level: " << saveStats[0] << endl;
                cout << "EXP: " << saveStats[1] << endl;
                cout << "Gold: " << saveStats[2] << endl;
                cout << "HP: " << saveStats[3] << "/" << saveStats[4] << endl;
                cout << "MP: " << saveStats[5] << "/" << saveStats[6] << endl;
                cout << "ATK: " << saveStats[7] << endl;
                cout << "CRT: " << saveStats[8] << endl;
                cout << "ACC: 70" << endl;
                cout << "DEF: " << saveStats[9] << endl;
                cout << "DDG: " << saveStats[10] << endl;
                cout << "DEPTH: " << saveStats[11] << endl;
                cout << "KEYS: " << saveStats[12] << endl;
                if(saveStats[13]>=0)
                    cout << "MASK: " << dir.maskDirectory[saveStats[13]].getName() << endl << endl;
                cout << "Continue with this character? (y/n)" << endl;
                load = getch();
                if(load=="y")
                    good = 1;
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
                    saveStats[9] = 0;
                    saveStats[10] = 0;
                    saveStats[11] = 1;
                    saveStats[12] = 0;
                    saveStats[13] = -1;
                    saveStats[14] = -1;
                    saveStats[15] = -1;
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

    Player hero(name,saveStats[0],100,saveStats[4],saveStats[6],saveStats[7],70,saveStats[8],saveStats[9],saveStats[10],saveStats[2],saveStats[12],saveStats[1]);
    hero.setEXPGoal(20*hero.level);
    hero.setHP(saveStats[3]);
    hero.setMP(saveStats[5]);
    if(saveStats[13]>=0)
        mask = saveStats[13];
    if(intChoice==2)
    {
        hero.equipment = equipSave;
        hero.inventory = itemSave;
        hero.spellbook = spellSave;
    }
    depth = saveStats[11];
    if((depth/5)+2>11)
        hero.empowered = 1;
    if(saveStats[14]!=-1)
        hero.equipWpn(dir.weaponDirectory[saveStats[14]]);
    if(saveStats[15]!=-1)
        hero.equipAmr(dir.armorDirectory[saveStats[15]-57]);

    if(mask>=0)
    {
        hero.mask = dir.maskDirectory[mask];
    }

    if(hero.getNDDG()==0&&hero.mask.getID()==5) //Whispers
        hero.setNDDG(25);

    srand(time(NULL));
    string action;
    string target;

    int err = 0;
    int end = 0;

    int diff = 0;
    int rew = 5;
    int karma = 5;
    int adv = (depth / 5) + 1;
    if(adv>10)
        adv = 10;
    int pass = 1;
    int menuval;
    int gd;
    int ex;
    int dmg;
    string text;

    Room currentRoom;
    bool itemStatus[6] = {0,0,0,0,0,0};
    int boss = 0;
    bool win = 0;
    bool lvup = 0;
    char yn;
    bool manSave = 0;

    int egStrBuff;
    int egAccBuff;
    int egDefBuff;
    int egDdgBuff;

    cout << "Floor " << depth << endl;
    currentRoom = roomGenerator(diff,rew,adv,dir,hero);

    while(end==0)
    {
        if(manSave==0)
            saveFunc(hero,filename,depth);
        if(hero.getHP()>hero.getMHP())
            hero.setHP(hero.getMHP());
        if(hero.getMP()>hero.getMMP())
            hero.setMP(hero.getMMP());
        if(hero.exp>=hero.getEXPGoal())
            hero.levelUp();
        cout << endl << "What do you do?" << endl;
        cin >> action;
        err = actionHandler(action);
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
                text = interactionHandler(err,target,hero,dir,currentRoom,pass,itemStatus);
                if(text=="next")
                {
                    depth++;
                    if(depth%5==0)
                    {
                        if(adv<10)
                            adv++;
                    }
                    roomLogic(diff,rew,karma,adv,hero);
                    if(diff==0)
                        pass = 1;
                    else
                        pass = 0;
                    std::system("cls");
                    cout << "Floor " << depth << endl;
                    if(depth==55&&win==0)
                        diff = 5;
                    else if(depth>55&&depth<80)
                        diff = 6;
                    else if(depth>=80)
                        diff = 7;
                    currentRoom = roomGenerator(diff,rew,adv,dir,hero);
                    //cout << "Karma: " << karma << endl;
                    if(((depth/5)+1)>11&&currentRoom.monster.getName()!="Valentereth, the Tyrant"&&currentRoom.monster.getName()!="Termineth")
                    {
                        egStrBuff = ((depth/5)+1)*4;
                        egAccBuff = ((depth/5)+1)*3;
                        egDefBuff = ((depth/5)+1)*4;
                        egDdgBuff = ((depth/5)+1)*2;

                        currentRoom.monster.setSTR(currentRoom.monster.getSTR()+egStrBuff);
                        currentRoom.monster.setACC(currentRoom.monster.getACC()+egAccBuff);
                        currentRoom.monster.setDEF(currentRoom.monster.getDEF()+egDefBuff);
                        currentRoom.monster.setDDG(currentRoom.monster.getDDG()+egDdgBuff);
                    }
                    if(diff==5&&adv==10&&win==0)
                        boss = 1;
                    if(diff==7)
                        boss = 2;
                    for(int i=0;i<3;i++)
                        itemStatus[i] = 0;

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
                    if(hero.mask.getID()==7) //Souls
                        ex = ex*3;
                    pass = combatHandler(hero,currentRoom.monster,dir,gd,ex);
                    if(pass==2)
                    {
                        end = 1;
                        break;
                    }
                    if(pass==3)
                    {
                        pass = 1;
                        depth++;
                        if(depth%5==0)
                        {
                            if(adv<10)
                                adv++;
                        }
                        roomLogic(diff,rew,karma,adv,hero);
                        if(diff==0)
                            pass = 1;
                        else
                            pass = 0;
                        std::system("cls");
                        cout << "Floor " << depth << endl;
                        if(depth==55&&win==0)
                            diff = 5;
                        else if(depth>55&&depth<80)
                            diff = 6;
                        else if(depth>=80)
                            diff = 7;
                        currentRoom = roomGenerator(diff,rew,adv,dir,hero);
                        //cout << "Karma: " << karma << endl;
                        if(((depth/5)+1)>11&&currentRoom.monster.getName()!="Valentereth, the Tyrant"&&currentRoom.monster.getName()!="Termineth")
                        {
                            egStrBuff = (adv-11)*4;
                            egAccBuff = (adv-11)*3;
                            egDefBuff = (adv-11)*4;
                            egDdgBuff = (adv-11)*2;

                            currentRoom.monster.setSTR(currentRoom.monster.getSTR()+egStrBuff);
                            currentRoom.monster.setACC(currentRoom.monster.getACC()+egAccBuff);
                            currentRoom.monster.setDEF(currentRoom.monster.getDEF()+egDefBuff);
                            currentRoom.monster.setDDG(currentRoom.monster.getDDG()+egDdgBuff);
                        }
                        if(diff==5&&adv==10&&win==0)
                            boss = 1;
                        if(diff==7)
                            boss = 2;
                        for(int i=0;i<3;i++)
                            itemStatus[i] = 0;
                        continue;
                    }
                    pass = 1;
                    if(boss==1)
                    {
                        win = 1;
                        std::system("cls");
                        cout << "Valentereth falls to the ground, motionless. She is defeated." << endl;
                        Sleep(2000);
                        cout << "As she lay there, the same energy that had hold of her rushes from her body, and into yours." << endl;
                        Sleep(2000);
                        cout << "You are flooded with incredible power. The power of a God." << endl;
                        Sleep(2000);
                        cout << "A voice calls to you from above... 'NOW YOU HAVE INHERITED THE MANTLE. YOU SHALL REMAIN HERE, AND DEFEND THE THRONE...'" << endl << endl;
                        Sleep(3000);
                        cout << "You have defeated Valentereth, and inherited the throne! Would you like to continue upward? (y/n): " << endl;
                        yn = getch();
                        boss = 0;
                        if(yn=='n')
                        {
                            end = 1;
                            break;
                        }
                        std::system("cls");
                        cout << "This cycle... of those who defeat the conquerer becoming one themselves... It cannot go on." << endl;
                        Sleep(1000);
                        cout << "The voices from above command you to defend the title of the Tyrant of the Tower." << endl;
                        Sleep(1000);
                        cout << "So you must ascend even further to truly break this cycle..." << endl;
                        Sleep(2000);
                        cout << "Press any key to continue ascending the tower.";
                        yn = getch();
                        hero.Empower();
                        std::system("cls");
                    }
                    if(boss==2)
                    {
                        end = 1;
                        win = 1;
                        break;
                    }
                    currentRoom.creatDesc = "";
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
                                Sleep(2000);
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
                    }
                }
                else if(text=="check")
                {
                    //Empty
                }
                else if(text=="escape")
                {
                    cout << "Enemy has not yet been defeated. Try to run past? (y/n)" << endl;
                    yn = getch();
                    if(yn=='y')
                    {
                        foo = rand() % 100 + 1;
                        if(hero.getDDG()>=15)
                        {
                            if(foo>50) //pass
                            {
                                cout << "You escape successfully!" << endl;
                                Sleep(2000);
                                good = 1;
                            }
                            else if(foo>25) //pass, but damage
                            {
                                cout << "The enemy attacks as you escape!" << endl;
                                Sleep(2000);
                                dmg = currentRoom.monster.getSTR() - hero.getDEF();
                                if(hero.mask.getID()==0||hero.mask.getID()==5) //Glass, Whisper
                                    dmg = dmg*2;
                                if(hero.mask.getID()==4) //Steel
                                    dmg = dmg/2;
                                if(dmg<0)
                                    dmg = 0;
                                hero.changeHP(-dmg);
                                cout << "Dealt " << dmg << " damage!" << endl;
                                Sleep(2000);
                                good = 1;
                            }
                            else //no pass, damage
                            {
                                cout << "The enemy knocks you back into the room, blocking your way!" << endl;
                                Sleep(2000);
                                dmg = currentRoom.monster.getSTR() - hero.getDEF();
                                if(hero.mask.getID()==0||hero.mask.getID()==5) //Glass, Whisper
                                    dmg = dmg*2;
                                if(hero.mask.getID()==4) //Steel
                                    dmg = dmg/2;
                                if(dmg<0)
                                    dmg = 0;
                                hero.changeHP(-dmg);
                                cout << "Dealt " << dmg << " damage!" << endl;
                                Sleep(2000);
                                good = 0;
                            }
                        }
                        else
                        {
                            if(foo>66) //pass
                            {
                                cout << "You escape successfully!" << endl;
                                Sleep(2000);
                                good = 1;
                            }
                            else if(foo>33) //pass, but damage
                            {
                                cout << "The enemy attacks as you escape!" << endl;
                                Sleep(2000);
                                dmg = currentRoom.monster.getSTR() - hero.getDEF();
                                if(hero.mask.getID()==0||hero.mask.getID()==5) //Glass, Whisper
                                    dmg = dmg*2;
                                if(hero.mask.getID()==4) //Steel
                                    dmg = dmg/2;
                                if(dmg<0)
                                    dmg = 0;
                                hero.changeHP(-dmg);
                                cout << "Dealt " << dmg << " damage!" << endl;
                                Sleep(2000);
                                good = 1;
                            }
                            else //no pass, damage
                            {
                                cout << "The enemy knocks you back into the room, blocking your way!" << endl;
                                Sleep(2000);
                                dmg = currentRoom.monster.getSTR() - hero.getDEF();
                                if(hero.mask.getID()==0||hero.mask.getID()==5) //Glass, Whisper
                                    dmg = dmg*2;
                                if(hero.mask.getID()==4) //Steel
                                    dmg = dmg/2;
                                if(dmg<0)
                                    dmg = 0;
                                hero.changeHP(-dmg);
                                cout << "Dealt " << dmg << " damage!" << endl;
                                Sleep(2000);
                                good = 0;
                            }
                        }
                        if(hero.getHP()<=0)
                        {
                            cout << "You have fallen..." << endl;
                            Sleep(3000);
                            pass = 2;
                            end = 1;
                            break;
                        }
                        if(good==1)
                        {
                            depth++;
                            if(depth%5==0)
                            {
                                if(adv<10)
                                    adv++;
                            }
                            roomLogic(diff,rew,karma,adv,hero);
                            if(diff==0)
                                pass = 1;
                            else
                                pass = 0;
                            std::system("cls");
                            cout << "Floor " << depth << endl;
                            if(depth==55&&win==0)
                                diff = 5;
                            else if(depth>55&&depth<80)
                                diff = 6;
                            else if(depth>=80)
                                diff = 7;
                            currentRoom = roomGenerator(diff,rew,adv,dir,hero);
                            //cout << "Karma: " << karma << endl;
                            if(((depth/5)+1)>11&&currentRoom.monster.getName()!="Valentereth, the Tyrant"&&currentRoom.monster.getName()!="Termineth")
                            {
                                egStrBuff = (hero.getLEV()-11)*4;
                                egAccBuff = (hero.getLEV()-11)*3;
                                egDefBuff = (hero.getLEV()-11)*4;
                                egDdgBuff = (hero.getLEV()-11)*2;

                                currentRoom.monster.setSTR(currentRoom.monster.getSTR()+egStrBuff);
                                currentRoom.monster.setACC(currentRoom.monster.getACC()+egAccBuff);
                                currentRoom.monster.setDEF(currentRoom.monster.getDEF()+egDefBuff);
                                currentRoom.monster.setDDG(currentRoom.monster.getDDG()+egDdgBuff);
                            }
                            if(diff==5&&adv==10&&win==0)
                                boss = 1;
                            if(diff==7)
                                boss = 2;
                            for(int i=0;i<3;i++)
                                itemStatus[i] = 0;
                        }
                    }
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

                    std::ofstream saveFile;
                    saveFile.open(filename);
                    saveFile << hero.level << " " << hero.exp << " " << hero.gold << " " << hero.getHP() << " " << hero.getMHP() << " " << hero.getMP() << " "
                             << hero.getMMP() << " " << hero.getNSTR() << " " << hero.getNCRT() << " " << hero.getNDEF() << " " << hero.getNDDG() << " " << depth
                             << " " << hero.keys << " " << hero.mask.getID() << " " << hero.eqpWpn.getID() << " " << hero.eqpAmr.getID();
                    for(int i=0;i<hero.equipment.size();i++)
                    {
                        saveFile << " " << hero.equipment[i];
                    }
                    if(hero.equipment.size()!=6)
                        saveFile << " " << -1;
                    for(int i=0;i<hero.inventory.size();i++)
                    {
                        saveFile << " " << hero.inventory[i];
                    }
                    if(hero.inventory.size()!=6)
                        saveFile << " " << -1;
                    for(int i=0;i<hero.spellbook.size();i++)
                        saveFile << " " << hero.spellbook[i];
                    saveFile << " " << -1;
                    saveFile.close();

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
                    cout << "ToV uses autosave. Would you like to enable manual save? You can re-enable" << endl;
                    cout << "autosave by typing save again or restarting the game. (y/n)" << endl;
                    yn = getch();
                    if(yn=='y')
                    {
                        cout << "Autosave disabled. Saving..." << endl;
                        manSave = 1;
                    }
                }
                else
                {
                    cout << "Autosave is disabled. Re-enable? (y/n)" << endl;
                    yn = getch();
                    if(yn=='y')
                    {
                        cout << "Autosave re-enabled." << endl;
                        manSave = 0;
                    }
                }
            }
            else if(err==8)
            {
                cout << endl;
                cout << "Actions:" << endl;
                cout << "    MOVE: move <target>" << endl;
                cout << "        -Synonyms: Go, Enter, Leave, Walk" << endl;
                cout << "        -Meaning: Used to enter a new area." << endl;
                cout << "        -EG: enter door" << endl;
                cout << "    LOOK: look <target>" << endl;
                cout << "        -Synonyms: Check, Examine" << endl;
                cout << "        -Meaning: Used to examine a feature in the room." << endl;
                cout << "        -EG: check crates" << endl;
                cout << "    GET: get <target>" << endl;
                cout << "        -Synonyms: Take, Grab, Add" << endl;
                cout << "        -Meaning: Used to acquire a new item." << endl;
                cout << "        -EG: get wooden sword" << endl;
                cout << "    ATTACK: attack <target>" << endl;
                cout << "        -Synonyms: Fight, Gank, Strike, Kill" << endl;
                cout << "        -Meaning: Used to engage in combat with a creature." << endl;
                cout << "        -EG: attack ogre" << endl;
                cout << "    MENU: menu" << endl;
                cout << "        -Synonyms: Inventory, Pause, M" << endl;
                cout << "        -Meaning: Opens up your menu." << endl;
                cout << "        -EG: menu" << endl;
                cout << "    SAVE: save" << endl;
                cout << "        -Synonyms: (None)" << endl;
                cout << "        -Meaning: Enables/Disables manual saving (Autosave enabled by default)." << endl;
                cout << "        -EG: save" << endl;
                cout << "    HELP: help" << endl;
                cout << "        -Synonyms: Manual" << endl;
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
                depth++;
                if(depth%5==0)
                {
                    if(adv<10)
                        adv++;
                }
                roomLogic(diff,rew,karma,adv,hero);
                if(diff==0)
                    pass = 1;
                else
                    pass = 0;
                std::system("cls");
                cout << "Floor " << depth << endl;
                if(depth==55&&win==0)
                    diff = 5;
                else if(depth>55&&depth<80)
                    diff = 6;
                else if(depth>=80)
                    diff = 7;
                currentRoom = roomGenerator(diff,rew,adv,dir,hero);
                //cout << "Karma: " << karma << endl;
                if(((depth/5)+1)>11&&currentRoom.monster.getName()!="Valentereth, the Tyrant"&&currentRoom.monster.getName()!="Termineth")
                {
                    egStrBuff = (hero.getLEV()-11)*4;
                    egAccBuff = (hero.getLEV()-11)*3;
                    egDefBuff = (hero.getLEV()-11)*4;
                    egDdgBuff = (hero.getLEV()-11)*2;

                    currentRoom.monster.setSTR(currentRoom.monster.getSTR()+egStrBuff);
                    currentRoom.monster.setACC(currentRoom.monster.getACC()+egAccBuff);
                    currentRoom.monster.setDEF(currentRoom.monster.getDEF()+egDefBuff);
                    currentRoom.monster.setDDG(currentRoom.monster.getDDG()+egDdgBuff);
                }
                if(diff==5&&adv==10&&win==0)
                    boss = 1;
                if(diff==7)
                    boss = 2;
                for(int i=0;i<3;i++)
                    itemStatus[i] = 0;
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
        }
        else
            end = 1;
    }
    if(win==1)
    {
        clear();
        if(pass==2)
        {
            cout <<"GAME OVER!" << endl;
            cout << "You conquered the Tower of Valentereth after " << depth << " floors!" << endl;
            remove(filename.c_str());
            Sleep(2000);
            if(hiscores(hero,depth))
            {
                cout << "On the leaderboard!" << endl;
                Sleep(2000);
            }
        }
        else if(boss==2)
        {
            cout << "CONGRATULATIONS!" << endl;
            cout << "You have broken the cycle and ascended the Tower of Valentereth!" << endl;
            remove(filename.c_str());
            Sleep(2000);
            if(hiscores(hero,100))
            {
                cout << "On the leaderboard!" << endl;
                Sleep(2000);
            }
        }
    }
    else if(pass==2)
    {
        clear();
        remove(filename.c_str());
        cout << "GAME OVER!" << endl;
        cout << "You made it to floor " << depth << "!" << endl;
        Sleep(2000);
        if(hiscores(hero,depth))
        {
            cout << "On the leaderboard!" << endl;
            Sleep(2000);
        }
    }
    else
        Sleep(2000);
    return 0;
}

int actionHandler(string act)
{
    if(act=="go"||act=="move"||act=="enter"||act=="leave"||act=="walk")
    {
        //cout << "You go to the ";
        return 0;
    }
    else if(act=="look"||act=="check"||act=="examine")
    {
        //cout << "You look at the ";
        return 1;
    }
    /*else if(act=="use"||act=="try")
    {
        cout << "You use the ";
        return 0;
    }*/
    else if(act=="take"||act=="get"||act=="grab"||act=="add")
    {
        //cout << "You take the ";
        return 2;
    }
    else if(act=="attack"||act=="fight"||act=="gank"||act=="strike"||act=="kill")
    {
        //cout << "You attack the ";
        return 3;
    }
    else if(act=="menu"||act=="inventory"||act=="pause"||act=="m")
    {
        //cout << "You open your menu." << endl;
        return 4;
    }
    else if(act=="save")
    {
        return 7;
    }
    else if(act=="help"||act=="manual"||act=="instructions")
    {
        return 8;
    }
    /*else if(act=="debug_go")
    {
        return 6;
    }*/
    /*else if(act=="room")
    {
        return 5;
    }*/
    /*else if(act=="exit")
    {
        cout << "Exiting..." << endl;
        return -1;
    }*/
    /*else if(act=="see")
    {
        return 10;
    }*/
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
                    if(hero.equipment[intChoice-1]<57)
                    {
                        cout << dir.getItemName(hero.equipment[intChoice-1]) << " | " << dir.getItemDesc(hero.equipment[intChoice-1]) << endl;
                        cout << "RARITY: " << dir.weaponDirectory[hero.equipment[intChoice-1]].getRarity() << endl;
                        cout << "STR: " << dir.weaponDirectory[hero.equipment[intChoice-1]].getStr() << endl;
                        cout << "ACC: " << dir.weaponDirectory[hero.equipment[intChoice-1]].getAcc() << endl;
                        cout << "CRIT: " << dir.weaponDirectory[hero.equipment[intChoice-1]].getCrt() << endl;
                        if(dir.weaponDirectory[hero.equipment[intChoice-1]].getMA()!=0)
                            cout << "MAGIC AMP: +" << dir.weaponDirectory[hero.equipment[intChoice-1]].getMA() << "%" << endl;
                    }
                    else
                    {
                        cout << dir.getItemName(hero.equipment[intChoice-1]) << " | " << dir.getItemDesc(hero.equipment[intChoice-1]) << endl;
                        cout << "RARITY: " << dir.armorDirectory[hero.equipment[intChoice-1]-57].getRarity() << endl;
                        cout << "DEF: " << dir.armorDirectory[hero.equipment[intChoice-1]-57].getDef() << endl;
                        cout << "DDG: " << dir.armorDirectory[hero.equipment[intChoice-1]-57].getDdg() << endl;
                        if(dir.armorDirectory[hero.equipment[intChoice-1]-57].getMG()!=0)
                            cout << "MANA REGEN: " << dir.armorDirectory[hero.equipment[intChoice-1]-57].getMG()  << endl;
                    }
                    cout << endl << "What do you want to do to " << dir.getItemName(hero.equipment[intChoice-1]) << "?" << endl;
                    cout << "1) EQUIP" << endl;
                    cout << "2) DROP" << endl;
                    cout << "0) RETURN" << endl;
                    strChoice = getch();
                    if(strChoice=="1")
                    {
                        if(hero.equipment[intChoice-1]<57)
                        {
                            hero.equipWpn(dir.weaponDirectory[hero.equipment[intChoice-1]]);
                            cout << "Equipped " << dir.getItemName(hero.equipment[intChoice-1]);
                            Sleep(2000);
                        }
                        else
                        {
                            if(hero.mask.getID()==7) //Souls
                            {
                                cout << "The armor phases right through you...";
                                Sleep(2000);
                            }
                            else
                            {
                                hero.equipAmr(dir.armorDirectory[hero.equipment[intChoice-1]-57]);
                                cout << "Equipped " << dir.getItemName(hero.equipment[intChoice-1]);
                                Sleep(2000);
                            }
                        }
                    }
                    else if(strChoice=="2")
                    {
                        cout << "Are you sure you want to drop " << dir.getItemName(hero.equipment[intChoice-1]) << "? (y/n)" << endl;
                        strChoice = getch();
                        if(strChoice=="y")
                            hero.equipment.erase(hero.equipment.begin()+intChoice-1);
                    }
                    else if(strChoice!="0")
                    {
                        cout << "Invalid action." << endl;
                        Sleep(2000);
                    }
                }
                else
                {
                    cout << "Invalid item." << endl;
                    Sleep(2000);
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
                    cout << dir.consumableDirectory[hero.inventory[intChoice-1]-100].getName() << " | " << dir.consumableDirectory[hero.inventory[intChoice-1]-100].getDesc() << endl;
                    cout << "RARITY: " << dir.consumableDirectory[hero.inventory[intChoice-1]-100].getRarity() << endl;
                    cout << "HP: " << dir.consumableDirectory[hero.inventory[intChoice-1]-100].getHP() << endl;
                    cout << "MP: " << dir.consumableDirectory[hero.inventory[intChoice-1]-100].getMP() << endl << endl;
                    cout << "What do you want to do to " << dir.getItemName(hero.inventory[intChoice-1]) << "?" << endl;
                    cout << "1) USE" << endl;
                    cout << "2) DROP" << endl;
                    cout << "0) RETURN" << endl;
                    strChoice = getch();
                    if(strChoice=="1")
                    {
                        if(dir.consumableDirectory[hero.inventory[intChoice-1]-100].getHP()>0)
                        {
                            hero.changeHP(dir.consumableDirectory[hero.inventory[intChoice-1]-100].getHP());
                            if(hero.getHP()>hero.getMHP())
                                hero.setHP(hero.getMHP());
                            cout << "You regained " << dir.consumableDirectory[hero.inventory[intChoice-1]-100].getHP() << " HP!" << endl;
                            Sleep(2000);
                        }
                        if(dir.consumableDirectory[hero.inventory[intChoice-1]-100].getMP()>0)
                        {
                            hero.changeMP(dir.consumableDirectory[hero.inventory[intChoice-1]-100].getMP());
                            if(hero.getMP()>hero.getMMP())
                                hero.setMP(hero.getMMP());
                            cout << "You regained " << dir.consumableDirectory[hero.inventory[intChoice-1]-100].getMP() << " MP!" << endl;
                            Sleep(2000);
                        }
                        hero.inventory.erase(hero.inventory.begin()+intChoice-1);
                    }
                    else if(strChoice=="2")
                    {
                        hero.inventory.erase(hero.inventory.begin()+intChoice-1);
                    }
                    else if(strChoice!="0")
                    {
                        cout << "Invalid action." << endl;
                        Sleep(2000);
                    }
                }
                else
                {
                    cout << "Invalid item." << endl;
                    Sleep(2000);
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
                    if(hero.spellbook[intChoice-1]<=214)
                    {
                        cout << "MANA COST: " << dir.attackSpellDirectory[hero.spellbook[intChoice-1]-200].getManaCost() << endl;
                        cout << "DAMAGE: " << dir.attackSpellDirectory[hero.spellbook[intChoice-1]-200].getDMG() << endl;
                    }
                    else if(hero.spellbook[intChoice-1]<=220)
                    {
                        cout << "MANA COST: " << dir.healingSpellDirectory[hero.spellbook[intChoice-1]-215].getManaCost() << endl;
                        cout << "HEALING: " << dir.healingSpellDirectory[hero.spellbook[intChoice-1]-215].getHPR() << endl;
                    }
                    else
                    {
                        cout << "MANA COST: " << dir.buffSpellDirectory[hero.spellbook[intChoice-1]-221].getManaCost() << endl;
                        if(ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-221].getATKU())+(hero.getMA()*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-221].getATKU())))>0)
                            cout << "ATK BUFF: " << ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-221].getATKU())+((static_cast<float>(hero.getMA())/100)*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-221].getATKU()))) << endl;
                        if(ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-221].getDEFU())+(hero.getMA()*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-221].getDEFU())))>0)
                            cout << "DEF BUFF: " << ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-221].getDEFU())+((static_cast<float>(hero.getMA())/100)*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-221].getDEFU()))) << endl;
                        if(ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-221].getCRTU())+(hero.getMA()*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-221].getCRTU())))>0)
                            cout << "CRT BUFF: " << ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-221].getCRTU())+((static_cast<float>(hero.getMA())/100)*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-221].getCRTU()))) << endl;
                        if(ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-221].getACCU())+(hero.getMA()*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-221].getACCU())))>0)
                            cout << "ACC BUFF: " << ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-221].getACCU())+((static_cast<float>(hero.getMA())/100)*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-221].getACCU()))) << endl;
                        if(ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-221].getDDGU())+(hero.getMA()*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-221].getDDGU())))>0)
                            cout << "DDG BUFF: " << ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-221].getDDGU())+((static_cast<float>(hero.getMA())/100)*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[intChoice-1]-221].getDDGU()))) << endl;
                    }

                    cout << endl << "What do you want to do to " << dir.getItemName(hero.spellbook[intChoice-1]) << "?" << endl;
                    if(hero.spellbook[intChoice-1]==215||hero.spellbook[intChoice-1]==216||hero.spellbook[intChoice-1]==219)
                        cout << "1) USE" << endl;
                    cout << "0) RETURN" << endl;
                    strChoice = getch();
                    if(strChoice=="1"&&(hero.spellbook[intChoice-1]==215||hero.spellbook[intChoice-1]==216||hero.spellbook[intChoice-1]==219))
                    {
                        if(hero.getMP()>=dir.healingSpellDirectory[hero.spellbook[intChoice-1]-215].getManaCost())
                        {
                            hero.changeHP(dir.healingSpellDirectory[hero.spellbook[intChoice-1]-215].getHPR());
                            hero.changeMP(-(dir.healingSpellDirectory[hero.spellbook[intChoice-1]-215].getManaCost()));
                            if(hero.getHP()>hero.getMHP())
                                hero.setHP(hero.getMHP());
                            cout << "You regained " << dir.healingSpellDirectory[hero.spellbook[intChoice-1]-215].getHPR() << " HP!" << endl;
                            Sleep(2000);
                        }
                        else
                            cout << "You don't have enough mana." << endl;
                    }
                    else if(strChoice!="0")
                    {
                        cout << "Invalid action." << endl;
                        Sleep(2000);
                    }
                }
                else
                {
                    cout << "Invalid spell." << endl;
                    Sleep(2000);
                }
            }while(nav==0);
            nav = 0;
        }
        else if(intChoice==6)
        {
            cout << "Are you sure you want to quit? Your progress will be saved under your name. (y/n): ";
            strChoice = getch();
            if(strChoice=="y")
                nav = -1;
        }
        else
        {
            cout << "Unknown command. Try one of the options on screen!" << endl;
            Sleep(2000);
        }
    }while(nav==0);
    return nav;
}

int storeMenuHandler(Player &hero,Directory dir,Room &currentRoom)
{
    if(currentRoom.store.getLevel()==-1)
    {
        cout << "No store in this room." << endl;
        Sleep(3000);
        return -1;
    }
    int instore = 1;
    int intChoice;
    int chck;
    string strChoice;
    while(instore==1)
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
            if(currentRoom.store.storeInventory[intChoice-1]<57)
            {
                cout << dir.getItemName(currentRoom.store.storeInventory[intChoice-1]) << " | " << dir.getItemDesc(currentRoom.store.storeInventory[intChoice-1]) << endl;
                cout << "RARITY: " << dir.weaponDirectory[currentRoom.store.storeInventory[intChoice-1]].getRarity() << endl;
                cout << "STR: " << dir.weaponDirectory[currentRoom.store.storeInventory[intChoice-1]].getStr() << endl;
                cout << "ACC: " << dir.weaponDirectory[currentRoom.store.storeInventory[intChoice-1]].getAcc() << endl;
                cout << "CRIT: " << dir.weaponDirectory[currentRoom.store.storeInventory[intChoice-1]].getCrt() << endl;

            }
            else if(currentRoom.store.storeInventory[intChoice-1]<99)
            {
                cout << dir.getItemName(currentRoom.store.storeInventory[intChoice-1]) << " | " << dir.getItemDesc(currentRoom.store.storeInventory[intChoice-1]) << endl;
                cout << "RARITY: " << dir.armorDirectory[currentRoom.store.storeInventory[intChoice-1]-57].getRarity() << endl;
                cout << "DEF: " << dir.armorDirectory[currentRoom.store.storeInventory[intChoice-1]-57].getDef() << endl;
                cout << "DDG: " << dir.armorDirectory[currentRoom.store.storeInventory[intChoice-1]-57].getDdg() << endl;
            }
            else if(currentRoom.store.storeInventory[intChoice-1]<200)
            {
                cout << dir.consumableDirectory[currentRoom.store.storeInventory[intChoice-1]-100].getName() << " | " << dir.consumableDirectory[currentRoom.store.storeInventory[intChoice-1]-99].getDesc() << endl;
                cout << "RARITY: " << dir.consumableDirectory[currentRoom.store.storeInventory[intChoice-1]-100].getRarity() << endl;
                cout << "HP: " << dir.consumableDirectory[currentRoom.store.storeInventory[intChoice-1]-100].getHP() << endl;
                cout << "MP: " << dir.consumableDirectory[currentRoom.store.storeInventory[intChoice-1]-100].getMP() << endl;
            }
            else
            {
                cout << dir.getItemName(currentRoom.store.storeInventory[intChoice-1]) << " | " << dir.getItemDesc(currentRoom.store.storeInventory[intChoice-1]) << endl;
                cout << "RARITY: " << dir.getItemRarity(currentRoom.store.storeInventory[intChoice-1]) << endl;
                if(currentRoom.store.storeInventory[intChoice-1]<=214)
                {
                    cout << "MANA COST: " << dir.attackSpellDirectory[currentRoom.store.storeInventory[intChoice-1]-200].getManaCost() << endl;
                    cout << "DAMAGE: " << dir.attackSpellDirectory[currentRoom.store.storeInventory[intChoice-1]-200].getDMG() << endl;
                }
                else if(currentRoom.store.storeInventory[intChoice-1]<=220)
                {
                    cout << "MANA COST: " << dir.healingSpellDirectory[currentRoom.store.storeInventory[intChoice-1]-215].getManaCost() << endl;
                    cout << "HEALING: " << dir.healingSpellDirectory[currentRoom.store.storeInventory[intChoice-1]-215].getHPR() << endl;
                }
                else
                {
                    cout << "MANA COST: " << dir.buffSpellDirectory[currentRoom.store.storeInventory[intChoice-1]-221].getManaCost() << endl;
                }
            }
            cout << "PRICE: " << currentRoom.store.storeCost[intChoice-1] << endl << endl;
            cout << "Would you like to purchase this item? (y/n)" << endl;
            strChoice = getch();
            if(strChoice=="y"||strChoice=="Y")
            {
                if(hero.gold<currentRoom.store.storeCost[intChoice-1])
                {
                    cout << "You cannot afford this item." << endl;
                    Sleep(2000);
                }
                else if(currentRoom.store.storeInventory[intChoice-1]<99)
                {
                    if(hero.equipment.size()>=6)
                    {
                        cout << "Your inventory is full." << endl;
                        Sleep(2000);
                    }
                    else
                    {
                        hero.equipment.push_back(currentRoom.store.storeInventory[intChoice-1]);
                        cout << "You got the " << dir.getItemName(currentRoom.store.storeInventory[intChoice-1]) << "!" << endl;
                        hero.gold -= currentRoom.store.storeCost[intChoice-1];
                        currentRoom.store.storeInventory.erase(currentRoom.store.storeInventory.begin()+intChoice-1);
                        currentRoom.store.storeCost.erase(currentRoom.store.storeCost.begin()+intChoice-1);
                        Sleep(2000);
                    }
                }
                else if(currentRoom.store.storeInventory[intChoice-1]<200)
                {
                    if(hero.inventory.size()>=6)
                    {
                        cout << "Your inventory is full." << endl;
                        Sleep(2000);
                    }
                    else
                    {
                        hero.inventory.push_back(currentRoom.store.storeInventory[intChoice-1]);
                        cout << "You got the " << dir.getItemName(currentRoom.store.storeInventory[intChoice-1]) << "!" << endl;
                        hero.gold -= currentRoom.store.storeCost[intChoice-1];
                        currentRoom.store.storeInventory.erase(currentRoom.store.storeInventory.begin()+intChoice-1);
                        currentRoom.store.storeCost.erase(currentRoom.store.storeCost.begin()+intChoice-1);
                        Sleep(2000);
                    }
                }
                else
                {
                    for(int i=0;i<hero.spellbook.size();i++)
                    {
                        if(hero.spellbook[i]==currentRoom.store.storeInventory[intChoice-1])
                        {
                            cout << "You already know this spell." << endl;
                            Sleep(2000);
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
                        Sleep(2000);
                    }
                }
            }
        }
        else
        {
            cout << "Invalid choice." << endl;
            Sleep(2000);
        }
    }
    return 0;
}

void saveFunc(Player &hero,string filename, int depth)
{
    std::ofstream saveFile;
    saveFile.open(filename);
    saveFile << hero.level << " " << hero.exp << " " << hero.gold << " " << hero.getHP() << " " << hero.getMHP() << " " << hero.getMP() << " "
             << hero.getMMP() << " " << hero.getNSTR() << " " << hero.getNCRT() << " " << hero.getNDEF() << " " << hero.getNDDG() << " " << depth
             << " " << hero.keys << " " << hero.mask.getID() << " " << hero.eqpWpn.getID() << " " << hero.eqpAmr.getID();
    for(int i=0;i<hero.equipment.size();i++)
    {
        saveFile << " " << hero.equipment[i];
    }
    if(hero.equipment.size()!=6)
        saveFile << " " << -1;
    for(int i=0;i<hero.inventory.size();i++)
    {
        saveFile << " " << hero.inventory[i];
    }
    if(hero.inventory.size()!=6)
        saveFile << " " << -1;
    for(int i=0;i<hero.spellbook.size();i++)
        saveFile << " " << hero.spellbook[i];
    saveFile << " " << -1;
    saveFile.close();
}

bool hiscores(Player &hero, int depth)
{
    std::ifstream readFile("HighScores.txt");
    string data;
    string nameArr[10];
    int depthArr[10];
    int i = 0;
    int flag=-1;
    string nameHold;
    int depthHold;

    while(std::getline(readFile,data))
    {
        std::stringstream line(data);
        line >> nameArr[i] >> depthArr[i];
        i++;
        if(i>=10)
            break;
    }

    for(i=9;i>=0;i--) //Determining if the score is on the leaderboard, and its position
        if(depth>=depthArr[i])
            flag = i;
    if(flag==-1)
        return 0;

    for(i=9;i>=0;i--) //Inserting it into the leaderboard
        if(i>flag)
            depthArr[i] = depthArr[i-1];
        else if(i==flag)
            depthArr[i] = depth;

    for(i=9;i>=0;i--) //Inserting name into the leaderboard
        if(i>flag)
            nameArr[i] = nameArr[i-1];
        else if(i==flag)
            nameArr[i] = hero.getName();

    readFile.close();

    std::ofstream writeFile("HighScores.txt");
    for(i=0;i<10;i++)
    {
        data = nameArr[i] + " " + std::to_string(depthArr[i]);
        writeFile << data << endl;
    }
    writeFile.close();
    return 1;
}
