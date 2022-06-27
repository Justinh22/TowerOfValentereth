void saveFunc(Player &hero,string filename, int depth, vector<bool> minibossStatus, vector<bool> itemStatus, Room currentRoom, int pass, Directory dir)
{
    std::ofstream saveFile;
    int boxNum;
    saveFile.open(filename);
    saveFile << hero.level << " " << hero.exp << " " << hero.gold << " " << hero.getHP() << " " << hero.getMHP() << " " << hero.getMP() << " " << hero.getMMP()
             << " " << hero.getNSTR() << " " << hero.getNCRT() << " " << hero.getNACC() << " " << hero.getNDEF() << " " << hero.getNDDG() << " " << hero.getLCK() << " " << depth
             << " " << hero.keys << " " << hero.growth << " " << hero.mask.getID() << " " << hero.eqpWpn.getID() << " " << hero.eqpAmr.getID() << " " << hero.eqpRng.getID()
             << " " << minibossStatus[0] << " " << minibossStatus[1] << " " << minibossStatus[2] << " " << minibossStatus[3] << " " << minibossStatus[4] << " " << minibossStatus[5]
             << " " << minibossStatus[6] << " " << score;
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
    saveFile << " " << -1 << "\n";

    //ROOM SAVE

    //cout << "Saving room..." << endl;

    saveFile << currentRoom.getID() << " ";

    for(int i=0;i<currentRoom.flist.size();i++)
        saveFile << currentRoom.flist[i].getID() << " ";
    saveFile << -1 << " ";

    for(int i=0;i<currentRoom.ilist.size();i++)
        saveFile << currentRoom.ilist[i] << " ";
    saveFile << -1 << " ";

    for(int i=0;i<currentRoom.blist.size();i++)
    {
        if(currentRoom.blist[i]=="crates")
        {
            boxNum = -2;
            saveFile << boxNum << " ";
        }
        else if(currentRoom.blist[i]=="barrels")
        {
            boxNum = -3;
            saveFile << boxNum << " ";
        }
        else if(currentRoom.blist[i]=="chest")
        {
            boxNum = -4;
            saveFile << boxNum << " ";
        }
        else
        {
            for(int j=0;j<dir.featureDirectory.size();j++)
            {
                if(currentRoom.blist[i]==dir.featureDirectory[j].getName())
                {
                    saveFile << j << " ";
                    break;
                }
            }
        }
    }
    saveFile << -1 << " ";

    //cout << "Features + Items Saved..." << endl;

    for(int i=0;i<itemStatus.size();i++)
        saveFile << itemStatus[i] << " ";
    //cout << "ItemStatus Done..." << endl;

    saveFile << currentRoom.monster.getID() << " ";
    //cout << "Creature Done..." << endl;

    for(int i=0;i<10;i++)
    {
        if(doorDesc(0,i)==currentRoom.doorDesc)
        {
            saveFile << i << " ";
            break;
        }
    }
    //cout << "DoorDesc Done..." << endl;
    for(int i=0;i<5;i++)
    {
        if(lootDesc(-(boxNum+2),i)==currentRoom.lootDesc[0])
        {
            saveFile << i << " ";
            break;
        }
    }
    //cout << "LootDesc Done..." << endl;
    if(currentRoom.creatDesc!="")
        for(int i=0;i<5;i++)
        {
            if(creatureDesc(currentRoom.monster.getID(),dir.creatureDirectory,hero,i)==currentRoom.creatDesc)
            {
                saveFile << i << " ";
                break;
            }
        }
    else
        saveFile << -1 << " ";
    //cout << "CreatDesc Done..." << endl;
    if(currentRoom.ascDesc!="")
        for(int i=0;i<5;i++)
        {
            if(ascensionDesc(i)==currentRoom.ascDesc)
            {
                saveFile << i << " ";
                break;
            }
        }
    else
        saveFile << -1 << " ";
    //cout << "AscDesc Done..." << endl;

    //cout << "Descriptions Saved..." << endl;

    saveFile << currentRoom.contents << " ";
    saveFile << pass << " ";

    if(currentRoom.store.getLevel()==-1&&currentRoom.store.getType()==0)
        saveFile << "-1 -1 -1 -1 -1 -1 -1";
    else
    {
        if(currentRoom.store.getType()==0)
        {
            saveFile << currentRoom.store.getLevel() << " ";
            saveFile << currentRoom.store.isUnlocked() << " ";
            int it=0;
            for(it=0;it<currentRoom.store.storeInventory.size();it++)
            {
                //cout << "Saving " << it << ": " << currentRoom.store.storeInventory[it] << endl;
                saveFile << currentRoom.store.storeInventory[it] << " ";
            }
            //cout << it << endl;
            for(int i=it;i<5;i++)
                saveFile << -1 << " ";
        }
        else
        {
            saveFile << 0 << " ";
            saveFile << currentRoom.store.isUnlocked() << " ";
            saveFile << currentRoom.store.getStatUp()[0] << " ";
            saveFile << currentRoom.store.getStatUp()[1] << " ";
            saveFile << currentRoom.store.getStatDown()[0] << " ";
            saveFile << currentRoom.store.getStatDown()[1] << " ";
            saveFile << currentRoom.store.getStatCount() << " ";
        }
    }

    //cout << "Done!" << endl;

    ach.writeAchievements();
    saveFile.close();
}

bool hiscores(Player &hero, int depth)
{
    std::ifstream readFile("HighScores.txt");
    string data;
    string nameArr[10];
    int scoreArr[10];
    int depthArr[10];
    int i = 0;
    int flag=-1;
    string nameHold;
    int scoreHold;
    int depthHold;

    while(std::getline(readFile,data))
    {
        std::stringstream line(data);
        line >> nameArr[i] >> scoreArr[i] >> depthArr[i];
        i++;
        if(i>=10)
            break;
    }

    for(i=9;i>=0;i--) //Determining if the score is on the leaderboard, and its position
        if(score>=scoreArr[i])
            flag = i;
    if(flag==-1)
        return 0;

    for(i=9;i>=0;i--) //Inserting it into the leaderboard
        if(i>flag)
            scoreArr[i] = scoreArr[i-1];
        else if(i==flag)
            scoreArr[i] = score;

    for(i=9;i>=0;i--) //Inserting name into the leaderboard
        if(i>flag)
            nameArr[i] = nameArr[i-1];
        else if(i==flag)
            nameArr[i] = hero.getName();

    for(i=9;i>=0;i--) //Inserting name into the leaderboard
        if(i>flag)
            depthArr[i] = depthArr[i-1];
        else if(i==flag)
            depthArr[i] = depth;

    readFile.close();

    std::ofstream writeFile("HighScores.txt");
    for(i=0;i<10;i++)
    {
        data = nameArr[i] + " " + std::to_string(scoreArr[i]) + " " + std::to_string(depthArr[i]);
        writeFile << data << endl;
    }
    writeFile.close();
    return 1;
}
