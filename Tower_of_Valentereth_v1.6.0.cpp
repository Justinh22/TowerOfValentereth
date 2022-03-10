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
#include "RoomLogic.h"
#include "CombatHandler.h"
#include "GoldPicker.h"
#include "SaveFunctions.h"

int actionHandler(string act,bool debug_opt, int gankTracker);  //Done!
int combatHandler(); //Done!
int menuHandler(Player &hero,Directory dir); //Done!
int storeMenuHandler(Player &hero,Directory dir,Room &currentRoom);
Room advance(int &depth, bool &itemDrop, int &adv, int &diff, int &rew, int &karma, Player &hero, int &pass, bool &win, Directory dir, int &boss, vector<bool> &mStatus, vector<bool> &rStatus, vector<bool> &iStatus, bool &dev);

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
                achievementMenu();
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
        if(intChoice==8)
        {
            cout << "Debug mode activated.";
            Sleep(2000);
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
    int saveStats[28];
    int roomData[15];
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
        saveStats[16] = -1;
        saveStats[17] = -1;
        saveStats[18] = -1;
        saveStats[19] = -1;
        saveStats[20] = 0;
        saveStats[21] = 0;
        saveStats[22] = 0;
        saveStats[23] = 0;
        saveStats[24] = 0;
        saveStats[25] = 0;
        saveStats[26] = 0;
        saveStats[27] = 0;
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
                        for(int i=0;i<28;i++)
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
                cout << "SCORE: " << saveStats[27] << endl;
                if(saveStats[16]>=0)
                {
                    cout << "MASK: " << dir.maskDirectory[saveStats[16]].getName() << endl << endl;
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
                    saveStats[16] = -1;
                    saveStats[17] = -1;
                    saveStats[18] = -1;
                    saveStats[19] = -1;
                    saveStats[20] = 0;
                    saveStats[21] = 0;
                    saveStats[22] = 0;
                    saveStats[23] = 0;
                    saveStats[24] = 0;
                    saveStats[25] = 0;
                    saveStats[26] = 0;
                    saveStats[27] = 0;
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
    if(saveStats[16]>=0)
        mask = saveStats[16];
    if(intChoice==2)
    {
        hero.equipment = equipSave;
        hero.inventory = itemSave;
        hero.spellbook = spellSave;
    }
    depth = saveStats[13];
    score = saveStats[27];
    if((depth/5)+2>11)
        hero.empowered = 1;
    if(saveStats[17]!=-1)
        hero.equipWpn(dir.weaponDirectory[saveStats[17]]);
    if(saveStats[18]!=-1)
        hero.equipAmr(dir.armorDirectory[saveStats[18]-100]);
    if(saveStats[19]!=-1)
        hero.equipRng(dir.ringDirectory[saveStats[19]-400]);

    if(mask>=0)
    {
        hero.mask = dir.maskDirectory[mask];
    }

    if(hero.getNDDG()==0&&hero.mask.getID()==5) //Whispers
        hero.setNDDG(10);
    if(hero.mask.getID()==1) //Wrath
        hero.setACC(hero.getACC()-10);
    if(hero.mask.getID()==7) //Souls
        hero.setACC(hero.getNACC());
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
    vector<bool> minibossStatus{saveStats[20]>=1,saveStats[21]>=1,saveStats[22]>=1,saveStats[23]>=1,saveStats[24]>=1,saveStats[25]>=1,saveStats[26]>=1};
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

    if(!saveFound)
    {
        std::system("cls");
        cout << "Word has been passed for centuries of a tower at the far edge of the land, filled with monsters, riches, and power unimaginable." << endl;
        Sleep(1000);
        cout << "At the heart of the tower waits a tyrant with god-like power, who calls themself Valentereth." << endl;
        Sleep(1000);
        cout << "Several people from your village have left for the tower, seeking the treasures within, but none have returned." << endl << endl;
        Sleep(1000);
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
        Sleep(1000);
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
        if(manSave==0)
            saveFunc(hero,filename,depth,minibossStatus,itemStatus,currentRoom,pass,dir);
        if(debug_opt&&depth%5==0&&depth>0)
        {
            string debugFile = "Saves/" + hero.getName() + "_Flr" + std::to_string(depth) + ".txt";
            saveFunc(hero,debugFile,depth,minibossStatus,itemStatus,currentRoom,pass,dir);
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
                text = interactionHandler(err,target,hero,dir,currentRoom,pass,itemStatus,debug_opt);
                if(text=="next")
                {
                    currentRoom = advance(depth,itemDrop,adv,diff,rew,karma,hero,pass,win,dir,boss,minibossStatus,roomStatus,itemStatus,dev);
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
                        currentRoom = advance(depth,itemDrop,adv,diff,rew,karma,hero,pass,win,dir,boss,minibossStatus,roomStatus,itemStatus,dev);
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
                            ach.WrathTriumph = 1;
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
                        if(ach.GlassTriumph==1&&ach.WrathTriumph==1&&ach.DarknessTriumph==1&&ach.ArcanaTriumph==1&&ach.SteelTriumph==1&&ach.WhispersTriumph==1&&ach.BeastsTriumph==1&&ach.SoulsTriumph==1)
                            ach.SpectrumTriumph = 1;
                        if(gankTracker==1)
                            ach.Gank = 1;
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
                            end = 2;
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
                    if(currentRoom.monster.getName()=="Valentereth, the Tyrant"||currentRoom.monster.getName()=="Termineth, the Watcher")
                    {
                        cout << "You cannot run from this enemy." << endl;
                        Sleep(2000);
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
                                Sleep(2000);
                                good = 1;
                            }
                            else if(foo>10) //pass, but damage
                            {
                                cout << "The enemy attacks as you escape!" << endl;
                                Sleep(2000);
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
                                Sleep(2000);
                                good = 1;
                            }
                            else //no pass, damage
                            {
                                cout << "The enemy knocks you back into the room, blocking your way!" << endl;
                                Sleep(2000);
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
                                Sleep(2000);
                                good = 0;
                            }
                        }
                        else
                        {
                            if(foo>40) //pass
                            {
                                cout << "You escape successfully!" << endl;
                                Sleep(2000);
                                good = 1;
                            }
                            else if(foo>20) //pass, but damage
                            {
                                cout << "The enemy attacks as you escape!" << endl;
                                Sleep(2000);
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
                                Sleep(2000);
                                good = 1;
                            }
                            else //no pass, damage
                            {
                                cout << "The enemy knocks you back into the room, blocking your way!" << endl;
                                Sleep(2000);
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
                            score += 10;
                            currentRoom = advance(depth,itemDrop,adv,diff,rew,karma,hero,pass,win,dir,boss,minibossStatus,roomStatus,itemStatus,dev);
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
                    saveFunc(hero,filename,depth,minibossStatus,itemStatus,currentRoom,pass,dir);
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
                        saveFunc(hero,filename,depth,minibossStatus,itemStatus,currentRoom,pass,dir);
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
                    saveFunc(hero,filename,depth,minibossStatus,itemStatus,currentRoom,pass,dir);
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
                currentRoom = advance(depth,itemDrop,adv,diff,rew,karma,hero,pass,win,dir,boss,minibossStatus,roomStatus,itemStatus,dev);
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
        }
        else
            end = 1;
    }
    if(win==1)
    {
        clear();
        if(end==2)
        {
            cout << "You sit upon the throne, brimming with ancient power." << endl;
            Sleep(2000);
            cout << "At long last, after all the trials you endured, you are the ruler of the tower." << endl << endl;
            Sleep(3000);
            cout << "Your head aches and your vision blurs, but the feeling of power within is all that matters now." << endl;
            Sleep(2000);
            cout << "Perhaps some fool may ascend the tower someday, trying to take what is rightfully yours. The thought of it makes your blood boil." << endl << endl;
            Sleep(2000);
            cout << "But you will never, ever, let that happen." << endl << endl;
            Sleep(3000);
            cout << "Numb from the searing pain in your head, you grab your axe, and await your next challenger." << endl << endl << endl;
        }
        if(pass==2)
        {
            cout << "GAME OVER!" << endl;
            cout << "You inherited the throne of the Tower of Valentereth after " << depth << " rooms!" << endl;
            remove(filename.c_str());
            if(end!=2)
            {
                ach.DejaVu++;
                ach.RiseAndShine++;
            }
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
            cout << "You have broken the curse and ascended to the top of the Tower of Valentereth!" << endl;
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
        ach.DejaVu++;
        ach.RiseAndShine++;
        cout << "GAME OVER!" << endl;
        cout << "You made it to room " << depth << "!" << endl;
        Sleep(2000);
        if(hiscores(hero,depth))
        {
            cout << "On the leaderboard!" << endl;
            Sleep(2000);
        }
    }
    else
        Sleep(2000);
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
    else if((act=="dsee"||act=="look_all")&&debug_opt)
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
                        cout << "STR: " << dir.weaponDirectory[hero.equipment[intChoice-1]].getStr() << endl;
                        cout << "ACC: " << dir.weaponDirectory[hero.equipment[intChoice-1]].getAcc() << endl;
                        cout << "CRIT: " << dir.weaponDirectory[hero.equipment[intChoice-1]].getCrt() << endl;
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
                                Sleep(2000);
                            }
                            else
                            {
                                hero.equipWpn(dir.weaponDirectory[hero.equipment[intChoice-1]]);
                                cout << "Equipped " << dir.getItemName(hero.equipment[intChoice-1]);
                                Sleep(2000);
                            }
                        }
                        else if(hero.equipment[intChoice-1]<200)
                        {
                            if(hero.mask.getID()==7) //Souls
                            {
                                cout << "The armor phases right through you...";
                                Sleep(2000);
                            }
                            else
                            {
                                hero.equipAmr(dir.armorDirectory[hero.equipment[intChoice-1]-100]);
                                cout << "Equipped " << dir.getItemName(hero.equipment[intChoice-1]);
                                Sleep(2000);
                            }
                        }
                        else
                        {
                            hero.equipRng(dir.ringDirectory[hero.equipment[intChoice-1]-400]);
                            cout << "Equipped " << dir.getItemName(hero.equipment[intChoice-1]);
                            Sleep(2000);
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
                            Sleep(2000);
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
                                Sleep(2000);
                                continue;
                            }
                            if(hero.getMP()<mCost)
                            {
                                cout << "You do not have enough MP to enhance this ring." << endl;
                                Sleep(2000);
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
                            Sleep(2000);
                        }
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
                                Sleep(2000);
                            }
                            if(dir.consumableDirectory[hero.inventory[intChoice-1]-200].getMP()>0)
                            {
                                hero.changeMP(dir.consumableDirectory[hero.inventory[intChoice-1]-200].getMP());
                                if(hero.getMP()>hero.getMMP())
                                    hero.setMP(hero.getMMP());
                                cout << "You regained " << dir.consumableDirectory[hero.inventory[intChoice-1]-200].getMP() << " MP!" << endl;
                                Sleep(2000);
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
                            Sleep(2000);
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
                            Sleep(2000);
                        }
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
                    if(hero.spellbook[intChoice-1]<=314)
                    {
                        cout << "MANA COST: " << dir.attackSpellDirectory[hero.spellbook[intChoice-1]-300].getManaCost() << endl;
                        cout << "DAMAGE: " << dir.attackSpellDirectory[hero.spellbook[intChoice-1]-300].getDMG() << endl;
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
                    cout << "STR: " << dir.weaponDirectory[currentRoom.store.storeInventory[intChoice-1]].getStr() << endl;
                    cout << "ACC: " << dir.weaponDirectory[currentRoom.store.storeInventory[intChoice-1]].getAcc() << endl;
                    cout << "CRIT: " << dir.weaponDirectory[currentRoom.store.storeInventory[intChoice-1]].getCrt() << endl;
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
                        cout << "MANA COST: " << dir.attackSpellDirectory[currentRoom.store.storeInventory[intChoice-1]-300].getManaCost() << endl;
                        cout << "DAMAGE: " << dir.attackSpellDirectory[currentRoom.store.storeInventory[intChoice-1]-300].getDMG() << endl;
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
                        Sleep(2000);
                    }
                    else if(currentRoom.store.storeInventory[intChoice-1]<200||currentRoom.store.storeInventory[intChoice-1]>=400)
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
                    else if(currentRoom.store.storeInventory[intChoice-1]<300)
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
                    Sleep(2000);
                }
                else if(curStatDown[0]<2)
                {
                    cout << "You don't have enough " << statDown[0] << "." << endl;
                    Sleep(2000);
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
                Sleep(2000);
            }
            if(intChoice==2)
            {
                if(hero.gold<currentRoom.store.getSwapCost())
                {
                    cout << "You cannot afford to divine." << endl;
                    Sleep(2000);
                }
                else if(curStatDown[1]<2)
                {
                    cout << "You don't have enough " << statDown[1] << "." << endl;
                    Sleep(2000);
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
                Sleep(2000);
            }
        }
    }
    return 0;
}

Room advance(int &depth, bool &itemDrop, int &adv, int &diff, int &rew, int &karma, Player &hero, int &pass, bool &win, Directory dir, int &boss, vector<bool> &mStatus, vector<bool> &rStatus, vector<bool> &iStatus, bool &dev)
{
    score += 100;
    depth++;
    itemDrop = 0;
    godMode = 0;
    if(depth%5==0)
    {
        if(adv<10)
            adv++;
    }
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
    if(((depth/5)+1)>11&&currentRoom.monster.getName()!="Valentereth, the Tyrant"&&currentRoom.monster.getName()!="Termineth")
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

    //cout << "Karma: " << karma << endl;
    return currentRoom;
}
