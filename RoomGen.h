#include "ItemPicker.h"
#include "CreaturePicker.h"
#include "SpellPicker.h"
#include "RoomDescriptions.h"

vector<int> rewardGen(int rew, int adv, Player hero, Directory dir)
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
    bool rngFlag = 0;
    bool keyFlag = 0;
    cout << endl;
    while(remaining > 0)
    {
        if(lootcnt>=3)
            break;
        do
        {
            change = 0;
            itemType = rand() % 5; // 0 = Weapon, 1 = Armor, 2 = Consumable, 3 = Spell, 4 = Ring
            if((adv<3&&itemType==4)||rand()%2==0)
                itemType = rand() % 4;
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
            if(itemType==4)
                if(rngFlag==1)
                    change = 1;
        }while(change==1);
        //cout << "ItemType is " << itemType << endl;
        if(itemType < 2)
        {
            if(itemType==0)
                wpnFlag = 1;
            if(itemType==1)
                amrFlag = 1;

            maxRarity = adv;
            if(maxRarity==1)
                maxRarity++;
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
            if(lootcnt==0)
                foo+=2;
            else if(lootcnt==1)
                foo++;

            switch(maxRarity)
            {
                case 2:
                    if(foo<5)
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
                    if(foo<3)
                    {
                        itemRarity = 1;
                        cost = 1;
                    }
                    else if(foo<=8)
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
                    if(foo<3)
                    {
                        itemRarity = 2;
                        cost = 1;
                    }
                    else if(foo<=8)
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
                    if(foo<3)
                    {
                        itemRarity = 3;
                        cost = 1;
                    }
                    else if(foo<=8)
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
                    if(foo<3)
                    {
                        itemRarity = 4;
                        cost = 2;
                    }
                    else if(foo<=8)
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
                    else if(foo<=8)
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
                    else if(foo<=8)
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
                    else if(foo<=8)
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
                    else if(foo<=9)
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
            if(rand()%4==0)
            {
                itemType = 3;
            }
            if(itemType==2) //Potion/Food
            {
                if(adv < 4)
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
            }
            else //Special
            {
                if(adv < 4)
                {
                    if(foo<=6)
                        itemRarity = 1;
                    else
                        itemRarity = 2;
                }
                else if(adv < 6)
                {
                    if(foo<=3)
                        itemRarity = 1;
                    else if(foo<=8)
                        itemRarity = 2;
                    else
                        itemRarity = 3;
                }
                else if(adv < 8)
                {
                    if(foo<=2)
                        itemRarity = 1;
                    else if(foo<=7)
                        itemRarity = 2;
                    else
                        itemRarity = 3;
                }
                else
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
            }
            if(keyFlag==0)
            {
                iid = itemPicker(itemType,itemRarity);
                if(iid==224)
                    for(int i=0;i<hero.inventory.size();i++)
                        while(hero.inventory[i]==224&&iid==224)
                            iid = itemPicker(itemType,itemRarity);
                loot.push_back(iid);
                cost = itemRarity;
            }
            else
            {
                iid = 212;
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
                else if(foo<=6)
                    itemRarity = 3;
                else
                    itemRarity = 4;
            }
            else
            {
                if(foo<=1)
                    itemRarity = 1;
                else if(foo<=2)
                    itemRarity = 2;
                else if(foo<=4)
                    itemRarity = 3;
                else if(foo<=8)
                    itemRarity = 4;
                else
                    itemRarity = 5;
            }
            foo = rand() % 7 + 1;
            iid = spellPicker(itemRarity);
            loot.push_back(iid);
            cost = itemRarity;
        }
        else //RING
        {
            rngFlag = 1;
            foo = rand() % 10 + 1;
            if(adv<6)
                itemRarity = 1;
            else if(adv<8)
            {
                if(foo<=7)
                    itemRarity = 1;
                else
                    itemRarity = 2;
            }
            else
            {
                if(foo<=3)
                    itemRarity = 1;
                else
                    itemRarity = 2;
            }
            iid = itemPicker(itemType,itemRarity);
            loot.push_back(iid);
            cost = (itemRarity*2)-1;
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

int difficultyGen(int &diff, int adv, vector<bool> &mbStatus, Player hero)
{
//Diff: The difficulty level of the chamber. From 1-5
//Adv: The current level of advancement the player is at within the dungeon. From 1-10
    int cid;
    int creatureLevel = diff + adv;
    if(diff==0)
        return -1;
    else
    {
        if(diff!=8)
        {
            if(creatureLevel==15&&hero.empowered==1)
                creatureLevel = 14;
            cid = creaturePicker(creatureLevel);
            //cout << "Creature Level: " << creatureLevel << endl;
            return cid;
        }
        else
        {
            cid = minibossPicker(mbStatus);
            if(cid==-1)
            {
                diff = 5;
                cid = creaturePicker(diff+adv);
            }
            return cid;
        }
    }
    //cout << "Creature: " << cid << endl;
    //Sleep(midWait);
}

Room roomBuilder(int type, vector<int> loot, int cid, Directory dir, vector<bool> &rmStatus)
{
    //cout << "In builder." << endl;
    int id;
    int timeout=0;
    Room newRoom;
    if(type==0)
    {

        if(cid==48) //Valentereth
            id = 89;
        else if(cid==56)
            id = 90;
        else if(cid<57)
        {
            do //Room not seen
            {
                id = rand() % (dir.roomDirectory.size()-9);
                timeout++;
            }while(rmStatus[id]==1||timeout>=30);
            rmStatus[id] = 1;
        }
        else
            id = cid + 25;
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
            newRoom.addBox("crates");
        }
        else if(foo==2)
        {
            newRoom.addBox("barrels");
        }
        else if(foo==3)
        {
            newRoom.addBox("chest");
        }
        for(int i=0;i<loot.size();i++)
        {
            newRoom.addItem(loot[i]);
        }
        //cout << "CID: " << cid << endl;
        if(cid!=-1)
            newRoom.setCreature(dir.creatureDirectory[cid]);

    }
    //cout << "Room Built!" << endl;
    return newRoom;
}

Merchant storeHandler(int level, Player hero)
{
    int foo;
    int id;
    if(level>10)
        level = 10;
    Merchant store(level,rand()%2);
    int itemType;
    int itemRarity;
    int itemCost;
    if(store.getType()==0)
    {
        for(int i=0;i<5;i++)
        {
            itemType = rand() % 5 + 1;
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
                    else if(foo<6)
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
                if(rand()%3>0)
                    itemType = 2;
                if(itemType==2)
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
                }
                else
                {
                    foo = rand() % 10 + 1;
                    if(level < 4)
                    {
                        if(foo<=6)
                            itemRarity = 1;
                        else
                            itemRarity = 2;
                    }
                    else if(level < 6)
                    {
                        if(foo<=3)
                            itemRarity = 1;
                        else if(foo<=8)
                            itemRarity = 2;
                        else
                            itemRarity = 3;
                    }
                    else if(level < 8)
                    {
                        if(foo<=2)
                            itemRarity = 1;
                        else if(foo<=7)
                            itemRarity = 2;
                        else
                            itemRarity = 3;
                    }
                    else
                    {
                        if(foo<=2)
                            itemRarity = 1;
                        else if(foo<=5)
                            itemRarity = 2;
                        else if(foo<=7)
                            itemRarity = 3;
                        else
                            itemRarity = 4;
                    }
                }
                id = itemPicker(itemType,itemRarity);
                if(id==224)
                    for(int i=0;i<hero.inventory.size();i++)
                        while(hero.inventory[i]==224&&id==224)
                            id = itemPicker(itemType,itemRarity);
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
            else if(itemType==5) //RING
            {
                foo = rand() % 10 + 1;
                if(level<6)
                    itemRarity = 1;
                else if(level<8)
                {
                    if(foo<=7)
                        itemRarity = 1;
                    else
                        itemRarity = 2;
                }
                else
                {
                    if(foo<=8)
                        itemRarity = 2;
                    else
                        itemRarity = 3;
                }
                id = itemPicker(3,itemRarity);
                store.storeInventory.push_back(id);
                switch(itemRarity)
                {
                    case 1:
                        itemCost = 50;
                        break;
                    case 2:
                        itemCost = 125;
                        break;
                    case 3:
                        itemCost = 200;
                        break;
                }
                store.storeCost.push_back(itemCost);
            }
        }
    }
    else if(store.getType()==1)
    {
        store.setStatSwap();
        //cout << "Divining alert!" << endl;
    }
    return store;
}

Room roomGenerator(int diff, int rew, int adv, Directory dir, Player &hero, vector<bool> &mbStatus, vector<bool> &rmStatus)
{
    vector<int> loot;
    int foo;
    loot = rewardGen(rew,adv,hero,dir);
    int creature = difficultyGen(diff,adv,mbStatus,hero);
    Room currentRoom;
    //cout << "Building room..." << endl;
    currentRoom = roomBuilder(0,loot,creature,dir,rmStatus);
    if(diff==8)
        minibossStatGen(adv,currentRoom.monster);

    foo = rand() % 4 + 1;
    if(foo==4)
        currentRoom.setMerchant(storeHandler(adv,hero));
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
        if(currentRoom.store.getType()==0)
            cout << "There is a locked door at the side of the room. The sign above it says it is a shop." << endl;
        else
            cout << "There is a locked door at the side of the room. The sign above says it is a diviner." << endl;
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
            int rty;
            //cout << "Chance is " << foo << ", while luck of finding is " << currentRoom.getFList()[i].getLuck() << "." << endl;
            if(currentRoom.getFList()[i].getLuck()>=foo)
            {
                if(currentRoom.getFList()[i].getItem()<=2)
                {
                    if(adv>3)
                    {
                        foo = rand() % 10 + 1;
                        if(adv<10)
                        {
                            if(foo<5)
                                rty = adv;
                            else
                                rty = adv - 1;
                        }
                        else
                        {
                            if(foo<9)
                                rty = adv - 1;
                            else
                                rty = adv;
                        }
                    }
                    else
                    {
                        rty = adv;
                    }
                    featid = itemPicker(currentRoom.getFList()[i].getItem()-1,rty);
                    //cout << "Adding " << featid << "." << endl;
                    currentRoom.addItem(featid);
                }
                else if(currentRoom.getFList()[i].getItem()<=3)
                {
                    if(foo%3==0)
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
                            featid = itemPicker(3,1);
                        else
                            featid = itemPicker(3,adv/2);
                        //cout << "Adding " << featid << "." << endl;
                        currentRoom.addItem(featid);
                    }
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
