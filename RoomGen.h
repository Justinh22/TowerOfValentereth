#include "ItemPicker.h"
#include "CreaturePicker.h"
#include "SpellPicker.h"
#include "RoomDescriptions.h"

vector<int> rewardGen(int rew, int adv, Directory dir)
{
//Rew: The chosen value of the rewards contained within the generated room. From 1-20
//Adv: The current level of advancement the player is at within the dungeon. From 1-10
    vector<int> loot;
    int lootcnt = 0;
    int iid;
    int itemType;
    int itemRarity;
    int maxCost;
    int remaining = rew;
    int cost;
    int maxRarity;
    int foo;
    int change;
    bool abort = 0;
    bool wpnFlag = 0;
    bool amrFlag = 0;
    bool conFlag = 0;
    bool splFlag = 0;
    bool keyFlag = 0;
    cout << endl;
    while(remaining > 0)
    {
        if(lootcnt>=3)
            break;
        do
        {
            change = 0;
            itemType = rand() % 4; // 0 = Weapon, 1 = Armor, 2 = Consumable, 3 = Spell
            if(itemType==0)
                if(wpnFlag==1)
                    change = 1;
            if(itemType==1)
                if(amrFlag==1)
                    change = 1;
            if(itemType==2)
                if(conFlag==1)
                    change = 1;
            if(itemType==3)
                if(splFlag==1)
                    change = 1;
        }while(change==1);
        //cout << "ItemType is " << itemType << endl;
        if(itemType < 2)
        {
            if(itemType==0)
                wpnFlag = 1;
            if(itemType==1)
                amrFlag = 1;

            maxRarity = adv+1;
            if(maxRarity > 10)
                maxRarity = 10;

            foo = 0;
            while(foo==0)
            {
                if(maxRarity<=5)
                    maxCost = 3;
                else if(maxRarity<=8)
                    maxCost = 4;
                else if(maxRarity<=10)
                    maxCost = 5;

                if(maxCost>remaining)
                    if(maxCost==3)
                        foo = 1;
                    else
                        maxRarity -= 2;
                else
                    foo = 1;
            }

            foo = rand() % 10 + 1;
            switch(maxRarity)
            {
                case 2:
                    if(foo<7)
                    {
                        itemRarity = 1;
                        cost = 1;
                    }
                    else
                    {
                        itemRarity = 2;
                        cost = 2;
                    }
                    break;
                case 3:
                    if(foo<4)
                    {
                        itemRarity = 1;
                        cost = 1;
                    }
                    else if(foo<9)
                    {
                        itemRarity = 2;
                        cost = 2;
                    }
                    else
                    {
                        itemRarity = 3;
                        cost = 3;
                    }
                    break;
                case 4:
                    if(foo<4)
                    {
                        itemRarity = 2;
                        cost = 1;
                    }
                    else if(foo<9)
                    {
                        itemRarity = 3;
                        cost = 2;
                    }
                    else
                    {
                        itemRarity = 4;
                        cost = 3;
                    }
                    break;
                case 5:
                    if(foo<4)
                    {
                        itemRarity = 3;
                        cost = 1;
                    }
                    else if(foo<9)
                    {
                        itemRarity = 4;
                        cost = 2;
                    }
                    else
                    {
                        itemRarity = 5;
                        cost = 3;
                    }
                    break;
                case 6:
                    if(foo<4)
                    {
                        itemRarity = 4;
                        cost = 2;
                    }
                    else if(foo<9)
                    {
                        itemRarity = 5;
                        cost = 3;
                    }
                    else
                    {
                        itemRarity = 6;
                        cost = 4;
                    }
                    break;
                case 7:
                    if(foo<4)
                    {
                        itemRarity = 5;
                        cost = 2;
                    }
                    else if(foo<9)
                    {
                        itemRarity = 6;
                        cost = 3;
                    }
                    else
                    {
                        itemRarity = 7;
                        cost = 4;
                    }
                    break;
                case 8:
                    if(foo<4)
                    {
                        itemRarity = 6;
                        cost = 2;
                    }
                    else if(foo<9)
                    {
                        itemRarity = 7;
                        cost = 3;
                    }
                    else
                    {
                        itemRarity = 8;
                        cost = 4;
                    }
                    break;
                case 9:
                    if(foo<4)
                    {
                        itemRarity = 7;
                        cost = 3;
                    }
                    else if(foo<9)
                    {
                        itemRarity = 8;
                        cost = 4;
                    }
                    else
                    {
                        itemRarity = 9;
                        cost = 5;
                    }
                    break;
                case 10:
                    if(foo<4)
                    {
                        itemRarity = 8;
                        cost = 3;
                    }
                    else if(foo<9)
                    {
                        itemRarity = 9;
                        cost = 4;
                    }
                    else
                    {
                        itemRarity = 10;
                        cost = 5;
                    }
                    break;
                default:
                    abort = 1;
                    break;
            }
            if(abort==0)
            {
                iid = itemPicker(itemType,itemRarity);
                //cout << "ITEMPICKER: Type was " << itemType << ", Rarity was " << itemRarity << ", Item was " << iid << "." << endl;
                loot.push_back(iid);
            }
        }
        else if(itemType==2)
        {
            conFlag = 1;
            foo = rand() % 13 + 1; //DEBUG | Original is 12
            if(foo>10)
            {
                keyFlag = 1;
            }
            else if(adv < 4)
            {
                if(foo<=5)
                    itemRarity = 1;
                else if(foo<=8)
                    itemRarity = 2;
                else
                    itemRarity = 3;
            }
            else if(adv < 7)
            {
                if(foo<=5)
                    itemRarity = 2;
                else if(foo<=8)
                    itemRarity = 3;
                else
                    itemRarity = 4;
            }
            else
            {
                if(foo<=5)
                    itemRarity = 3;
                else if(foo<=8)
                    itemRarity = 4;
                else
                    itemRarity = 5;
            }
            if(keyFlag==0)
            {
                iid = itemPicker(itemType,itemRarity);
                loot.push_back(iid);
                cost = itemRarity;
            }
            else
            {
                iid = 112;
                loot.push_back(iid);
                cost = 2;
            }
        }
        else if(itemType==3)
        {
            splFlag = 1;
            foo = rand() % 10 + 1;
            if(adv < 3)
            {
                if(foo<=8)
                    itemRarity = 1;
                else
                    itemRarity = 2;
            }
            else if(adv < 5)
            {
                if(foo<=4)
                    itemRarity = 1;
                else if(foo<=8)
                    itemRarity = 2;
                else
                    itemRarity = 3;
            }
            else if(adv < 7)
            {
                if(foo<=2)
                    itemRarity = 1;
                else if(foo<=5)
                    itemRarity = 2;
                else if(foo<=8)
                    itemRarity = 3;
                else
                    itemRarity = 4;
            }
            else if(adv < 9)
            {
                if(foo<=1)
                    itemRarity = 1;
                else if(foo<=3)
                    itemRarity = 2;
                else if(foo<=5)
                    itemRarity = 3;
                else if(foo<=8)
                    itemRarity = 4;
                else
                    itemRarity = 5;
            }
            else
            {
                if(foo<=1)
                    itemRarity = 1;
                else if(foo<=2)
                    itemRarity = 2;
                else if(foo<=4)
                    itemRarity = 3;
                else if(foo<=7)
                    itemRarity = 4;
                else
                    itemRarity = 5;
            }
            foo = rand() % 7 + 1;
            iid = spellPicker(itemRarity);
            loot.push_back(iid);
            cost = itemRarity;
        }
        remaining -= cost;

        lootcnt++;
    }
    /*cout << "The final loot vector contains: ";
    for(int i=0;i<loot.size();i++)
        cout << dir.getItemName(loot[i]) << " ";
    cout << endl;*/
    return loot;
}

int difficultyGen(int diff, int adv)
{
//Diff: The difficulty level of the chamber. From 1-5
//Adv: The current level of advancement the player is at within the dungeon. From 1-10
    int cid;
    int creatureLevel = diff + adv;
    if(diff==0)
        return -1;
    else
    {
        //cout << "Creature Level: " << creatureLevel << endl;
        cid = creaturePicker(creatureLevel);
        return cid;
    }
}

Room roomBuilder(int type, vector<int> loot, int cid, Directory dir)
{
    //cout << "In builder." << endl;
    int id;
    Room newRoom;
    if(type==0)
    {
        id = rand() % 31;
        newRoom = dir.roomDirectory[id];
        bool crateTog = 0;
        bool chestTog = 0;
        bool barrelTog = 0;
        bool cont = 0;
        int foo;

        newRoom.contents = loot.size();
        foo = rand() % 3 + 1;
        if(foo==1)
        {
            //cout << "Crates" << endl;
            newRoom.addBox("crates");
        }
        else if(foo==2)
        {
            //cout << "Barrels" << endl;
            newRoom.addBox("barrels");
        }
        else if(foo==3)
        {
            //cout << "Chest" << endl;
            newRoom.addBox("chest");
        }
        //cout << "Handling loot; Size = " << loot.size() << endl;
        for(int i=0;i<loot.size();i++)
        {
            //cout << "Loot " << i+1 << endl;
            /*do
            {
                cont = 0;
                foo = rand() % 3 + 1;
                if(foo==1)
                    if(crateTog==1)
                    {
                        cont = 1;
                    }
                if(foo==2)
                    if(barrelTog==1)
                    {
                        cont = 1;
                    }
                if(foo==3)
                    if(chestTog==1)
                    {
                        cont = 1;
                    }
            }while(cont==1);*/
            newRoom.addItem(loot[i]);
            //cout << "Loot added!" << endl;

            /*
            if(loot[i]<=38)
                newRoom.addItem(dir.weaponDirectory[loot[i]]);
            else if(loot[i]<=64)
                newRoom.addItem(dir.armorDirectory[loot[i]]);
            else if(loot[i]<=76)
                newRoom.addItem(dir.consumableDirectory[loot[i]]);
            else if(loot[i]<=114)
                newRoom.addItem(dir.attackSpellDirectory[loot[i]-100]);
            else if(loot[i]<=120)
                newRoom.addItem(dir.healingSpellDirectory[loot[i]-100]);
            else if(loot[i]<=129)
                newRoom.addItem(dir.buffSpellDirectory[loot[i]-100]);
            */
        }

        //cout << "It contains: ";
        /*for(int i=0;i<newRoom.getIList().size();i++)
        {
            cout << loot[i] << ": " << dir.getItemName(loot[i]) << ", " << type << " | ";
            cout <<
        }
        cout << endl;*/

        //cout << "CID: " << cid << endl;
        if(cid!=-1)
            newRoom.setCreature(dir.creatureDirectory[cid]);

    }
    //cout << "Room Built!" << endl;
    return newRoom;
}

Merchant storeHandler(int level)
{
    int foo;
    int id;
    if(level>10)
        level = 10;
    Merchant store(level);
    int itemType;
    int itemRarity;
    int itemCost;
    for(int i=0;i<5;i++)
    {
        itemType = rand() % 4 + 1;
        if(itemType<=2)
        {
            if(level==1)
                itemRarity = 1;
            else if(level==2)
                itemRarity = rand() % 2 + 1;
            else if(level>=3)
            {
                foo = rand() % 10 + 1;
                if(foo<3)
                    itemRarity = level - 2;
                else if(foo<7)
                    itemRarity = level - 1;
                else
                    itemRarity = level;
            }
            id = itemPicker(itemType-1,itemRarity);
            store.storeInventory.push_back(id);
            switch(itemRarity)
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
            store.storeCost.push_back(itemCost);
        }
        else if(itemType==3)
        {
            if(level<=2)
                itemRarity = rand() % 2 + 1;
            else if(level<=4)
            {
                foo = rand() % 10 + 1;
                if(foo<3)
                    itemRarity = 1;
                else if(foo<7)
                    itemRarity = 2;
                else
                    itemRarity = 3;
            }
            else if(level<=7)
            {
                foo = rand() % 10 + 1;
                if(foo<2)
                    itemRarity = 1;
                else if(foo<4)
                    itemRarity = 2;
                else if(foo<7)
                    itemRarity = 3;
                else
                    itemRarity = 4;
            }
            else
            {
                foo = rand() % 10 + 1;
                if(foo<2)
                    itemRarity = 2;
                else if(foo<4)
                    itemRarity = 3;
                else if(foo<7)
                    itemRarity = 4;
                else
                    itemRarity = 5;
            }
            id = itemPicker(itemType-1,itemRarity);
            store.storeInventory.push_back(id);
            switch(itemRarity)
            {
                case 1:
                    itemCost = 8;
                    break;
                case 2:
                    itemCost = 25;
                    break;
                case 3:
                    itemCost = 60;
                    break;
                case 4:
                    itemCost = 115;
                    break;
                case 5:
                    itemCost = 190;
                    break;
            }
            store.storeCost.push_back(itemCost);
        }
        else if(itemType==4)
        {
            foo = rand() % 10 + 1;
            if(level < 3)
            {
                if(foo<=7)
                    itemRarity = 1;
                else
                    itemRarity = 2;
            }
            else if(level < 5)
            {
                if(foo<=3)
                    itemRarity = 1;
                else if(foo<=7)
                    itemRarity = 2;
                else
                    itemRarity = 3;
            }
            else if(level < 7)
            {
                if(foo<=2)
                    itemRarity = 1;
                else if(foo<=4)
                    itemRarity = 2;
                else if(foo<=7)
                    itemRarity = 3;
                else
                    itemRarity = 4;
            }
            else if(level < 9)
            {
                if(foo<=1)
                    itemRarity = 1;
                else if(foo<=3)
                    itemRarity = 2;
                else if(foo<=4)
                    itemRarity = 3;
                else if(foo<=7)
                    itemRarity = 4;
                else
                    itemRarity = 5;
            }
            else
            {
                if(foo<=1)
                    itemRarity = 1;
                else if(foo<=2)
                    itemRarity = 2;
                else if(foo<=4)
                    itemRarity = 3;
                else if(foo<=7)
                    itemRarity = 4;
                else
                    itemRarity = 5;
            }
            id = spellPicker(itemRarity);
            store.storeInventory.push_back(id);
            switch(itemRarity)
            {
                case 1:
                    itemCost = 8;
                    break;
                case 2:
                    itemCost = 25;
                    break;
                case 3:
                    itemCost = 60;
                    break;
                case 4:
                    itemCost = 115;
                    break;
                case 5:
                    itemCost = 190;
                    break;
            }
            store.storeCost.push_back(itemCost);
        }
    }
    return store;
}

Room roomGenerator(int diff, int rew, int adv, Directory dir, Player &hero)
{
    vector<int> loot;
    int foo;
    loot = rewardGen(rew,adv,dir);
    int creature = difficultyGen(diff,adv);
    Room currentRoom;
    //cout << "Building room..." << endl;
    currentRoom = roomBuilder(0,loot,creature,dir);
    foo = rand() % 5 + 1;
    if(foo==5)
        currentRoom.setMerchant(storeHandler(adv));
    //cout << "Room built!" << endl;
    cout << endl << currentRoom.getDesc() << endl;

    string desc;
    if((currentRoom.getBList())[0]=="crates")
        desc = lootDesc(0);
    else if((currentRoom.getBList())[0]=="barrels")
        desc = lootDesc(1);
    else if((currentRoom.getBList())[0]=="chest")
        desc = lootDesc(2);
    cout << desc << endl;
    currentRoom.addLDesc(desc);
    if(hero.empowered==1)
    {
        desc = ascensionDesc();
        currentRoom.ascDesc = desc;
        cout << desc << endl;
    }
    desc = doorDesc(0);
    currentRoom.setDrDesc(desc);
    cout << desc << endl;
    if(currentRoom.store.getLevel()!=-1)
    {
        cout << "There is a locked door at the side of the room. The sign above it says it is a shop." << endl;
    }
    if(creature!=-1)
    {
        desc = creatureDesc(creature,dir.creatureDirectory,hero);
        currentRoom.creatDesc = desc;
        cout << desc << endl;
    }
    for(int i=0;i<currentRoom.getFList().size();i++)
    {
        if(currentRoom.getFList()[i].getItem()!=0)
        {
            foo = rand() % 3 + 1;
            int featid;
            //cout << "Chance is " << foo << ", while luck of finding is " << currentRoom.getFList()[i].getLuck() << "." << endl;
            if(currentRoom.getFList()[i].getLuck()>=foo)
            {
                if(currentRoom.getFList()[i].getItem()<=2)
                {
                    featid = itemPicker(currentRoom.getFList()[i].getItem()-1,adv);
                    //cout << "Adding " << featid << "." << endl;
                    currentRoom.addItem(featid);
                }
                else if(currentRoom.getFList()[i].getItem()<=3)
                {
                    if(adv/2==0)
                        featid = itemPicker(2,1);
                    else
                        featid = itemPicker(2,adv/2);
                    //cout << "Adding " << featid << "." << endl;
                    currentRoom.addItem(featid);
                }
                else
                {
                    if(adv/2==0)
                        featid = spellPicker(1);
                    else
                        featid = spellPicker(adv/2);
                    //cout << "Adding " << featid << "." << endl;
                    currentRoom.addItem(featid);
                }
                currentRoom.addBox(currentRoom.getFList()[i].getName());
            }
        }
    }
    return currentRoom;
}
