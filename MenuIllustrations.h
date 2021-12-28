void titleScreen()
{
    cout << " _____________________________________________________________________________________________________________________ " << endl;
    cout << " |                               ___________                                  _____                                   | " << endl;
    cout << " |                               \\__    ___/_____  _  __ ___________    _____/ ____\\                                  | " << endl;
    cout << " |                                 |    | /  _ \\ \\/ \\/ // __ \\_  __ \\  /  _ \\   __\\                                   | " << endl;
    cout << " |                                 |    |(  <_> )     /\\  ___/|  | \\/ (  <_> )  |                                     | " << endl;
    cout << " |                                 |____| \\____/ \\/\\_/  \\___  >__|     \\____/|__|                                     | " << endl;
    cout << " |                                                          \\/                                                        | " << endl;
    cout << " |                    ____   ____      .__                 __                        __  .__                          | " << endl;
    cout << " |                    \\   \\ /   /____  |  |   ____   _____/  |_  ___________   _____/  |_|  |__                       | " << endl;
    cout << " |                     \\   Y   /\\__  \\ |  | _/ __ \\ /    \\   __\\/ __ \\_  __ \\_/ __ \\   __\\  |  \\                      | " << endl;
    cout << " |                      \\     /  / __ \\|  |_\\  ___/|   |  \\  | \\  ___/|  | \\/\\  ___/|  | |   Y  \\                     | " << endl;
    cout << " |                       \\___/  (____  /____/\\___  >___|  /__|  \\___  >__|    \\___  >__| |___|  /                     | " << endl;
    cout << " |                                   \\/          \\/     \\/          \\/            \\/          \\/                      | " << endl;
    cout << " |                                                                                                                    | " << endl;
    cout << " |                                                                                                                    | " << endl;
    cout << " |                                                                                                                    | " << endl;
    cout << " |     1) New Game                                                                                                    | " << endl;
    cout << " |     2) Load Game                                                                                                   | " << endl;
    cout << " |     3) Leaderboard                                                                                                 | " << endl;
    cout << " |     4) Achievements                                                                                                | " << endl;
    cout << " |     5) Masks                                                                                                       | " << endl;
    cout << " |                                                                                                             v1.6.0 | " << endl;
    cout << " |____________________________________________________________________________________________________________________| " << endl;
    cout << "                                                                                                                        " << endl;
}

void scores()
{
    std::ifstream readFile("HighScores.txt");
    string data;
    string clear;
    string nameArr[10];
    int scoreArr[10];
    int depthArr[10];
    int i = 0;

    while(std::getline(readFile,data))
    {
        std::stringstream line(data);
        line >> nameArr[i] >> scoreArr[i] >> depthArr[i];
        i++;
        if(i>=10)
            break;
    }

    std::system("cls");
    cout << "/----------------------------------------------------------------------\\" << endl;
    cout << "|-                                                                    -|" << endl;
    cout << "|-                            HIGH  SCORES                            -|" << endl;
    cout << "|-                                                                    -|" << endl;
    for(int i=0;i<10;i++)
    {
        if(nameArr[i]=="")
            continue;
        if(depthArr[i]<0)
            depthArr[i] = 0;
        if(depthArr[i]>55&&depthArr[i]<=80)
            clear = "<+>";
        else if(depthArr[i]==100)
        {
            clear = "<<+>>";
            depthArr[i] = 80;
        }
        else
            clear = "     ";
        data = std::to_string(i+1) + ") " + nameArr[i] + " | " + std::to_string(scoreArr[i]) + " points, " + std::to_string(depthArr[i]) + " floors    " + clear;
        cout << "|-      " << setw(58) << std::left << data << "    -|" << endl;
    }
    cout << "|-                                                                    -|" << endl;
    cout << "|-      0) RETURN                                                     -|" << endl;
    cout << "|-                                                                    -|" << endl;
    cout << "\\----------------------------------------------------------------------/" << endl;
}

void maskSelect()
{
    std::system("cls");
    cout << "/----------------------------------------------------\\" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "|-                   MASK  SELECT                   -|" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "|-       1) Mask of Glass                           -|" << endl;
    cout << "|-       2) Mask of Wrath                           -|" << endl;
    cout << "|-       3) Mask of Darkness                        -|" << endl;
    cout << "|-       4) Mask of Arcana                          -|" << endl;
    cout << "|-       5) Mask of Steel                           -|" << endl;
    cout << "|-       6) Mask of Whispers                        -|" << endl;
    cout << "|-       7) Mask of Beasts                          -|" << endl;
    cout << "|-       8) Mask of Souls                           -|" << endl;
    cout << "|-       9) None                                    -|" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "|-       0) RETURN                                  -|" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "\\----------------------------------------------------/" << endl;
}

void achievementMenu()
{
    std::system("cls");
    ach.calculatePoints();
    cout << "/------------------------------------------------------------------------------------------------------------------\\" << endl;
    cout << "|-                                                                                                                -|" << endl;
    cout << "|-                                                   ACHIEVEMENTS                                                 -|" << endl;
    cout << "|-                                                                                                                -|" << endl;
    cout << "|-       COMPLETION RATE: " << setw(4) << std::right << std::setprecision(3) << float(float(ach.points)/1000)*100 << "%" << " (" << setw(4) << std::right << ach.points << "/1000)                                                                       -|" << endl;
    cout << "|-                                                                                                                -|" << endl;
    cout << "|-       (";if(ach.complete[0]) cout << "X"; else cout << " "; cout << ") Connoisseur (10pts):                    Eat 50 loaves of bread                                       -|" << endl;
    cout << "|-       (";if(ach.complete[1]) cout << "X"; else cout << " "; cout << ") Alchemist (10pts):                      Drink 50 potions                                             -|" << endl;
    cout << "|-       (";if(ach.complete[2]) cout << "X"; else cout << " "; cout << ") Expert (10pts):                         Defeat 50 enemies                                            -|" << endl;
    cout << "|-       (";if(ach.complete[3]) cout << "X"; else cout << " "; cout << ") ...and then you wake up (10pts):        Die 10 times                                                 -|" << endl;
    cout << "|-       (";if(ach.complete[4]) cout << "X"; else cout << " "; cout << ") Rise and Shine, Campers! (20pts):       Die 25 times                                                 -|" << endl;
    cout << "|-       (";if(ach.complete[5]) cout << "X"; else cout << " "; cout << ") Powerhouse (20pts):                     Deal 50 damage in one strike                                 -|" << endl;
    cout << "|-       (";if(ach.complete[6]) cout << "X"; else cout << " "; cout << ") The Tyrant (30pts):                     Defeat Valentereth                                           -|" << endl;
    cout << "|-       (";if(ach.complete[7]) cout << "X"; else cout << " "; cout << ") The Horror (15pts):                     Defeat ?????                                                 -|" << endl;
    cout << "|-       (";if(ach.complete[8]) cout << "X"; else cout << " "; cout << ") The Mercenary (15pts):                  Defeat Stiran                                                -|" << endl;
    cout << "|-       (";if(ach.complete[9]) cout << "X"; else cout << " "; cout << ") The Beast (15pts):                      Defeat Ozkoroth                                              -|" << endl;
    cout << "|-       (";if(ach.complete[10]) cout << "X"; else cout << " "; cout << ") The Scion (15pts):                      Defeat Byralt                                                -|" << endl;
    cout << "|-       (";if(ach.complete[11]) cout << "X"; else cout << " "; cout << ") The Archmage (15pts):                   Defeat Emeritus                                              -|" << endl;
    cout << "|-       (";if(ach.complete[12]) cout << "X"; else cout << " "; cout << ") The Nature's Wrath (15pts):             Defeat Endrigaia                                             -|" << endl;
    cout << "|-       (";if(ach.complete[13]) cout << "X"; else cout << " "; cout << ") Unstoppable (20pts):                    Defeat 100 enemies                                           -|" << endl;
    cout << "|-       (";if(ach.complete[14]) cout << "X"; else cout << " "; cout << ") Nuke (30pts):                           Deal 50 damage at once with a spell                          -|" << endl;
    cout << "|-       (";if(ach.complete[15]) cout << "X"; else cout << " "; cout << ") Overkill (30pts):                       Deal 100 damage in one strike                                -|" << endl;
    cout << "|-       (";if(ach.complete[16]) cout << "X"; else cout << " "; cout << ") Necromancy (30pts):                     Deal 20 necrotic damage in one turn                          -|" << endl;
    cout << "|-       (";if(ach.complete[17]) cout << "X"; else cout << " "; cout << ") Sorcerer Supreme (25pts):               Obtain the equipment of the ultimate sorcerer                -|" << endl;
    cout << "|-       (";if(ach.complete[18]) cout << "X"; else cout << " "; cout << ") Conquerer (25pts):                      Obtain the equipment of the great conquerer                  -|" << endl;
    cout << "|-       (";if(ach.complete[19]) cout << "X"; else cout << " "; cout << ") Vanguard (25pts):                       Obtain the equipment of the unstoppable vanguard             -|" << endl;
    cout << "|-       (";if(ach.complete[20]) cout << "X"; else cout << " "; cout << ") Whisper (25pts):                        Obtain the equipment of the silent assassin                  -|" << endl;
    cout << "|-       (";if(ach.complete[21]) cout << "X"; else cout << " "; cout << ") Ancient Power (25pts):                  Obtain the equipment of the ancient demigod                  -|" << endl;
    cout << "|-       (";if(ach.complete[22]) cout << "X"; else cout << " "; cout << ") Glass Triumph (40pts):                  Defeat Valentereth with the Mask of Glass                    -|" << endl;
    cout << "|-       (";if(ach.complete[23]) cout << "X"; else cout << " "; cout << ") Wrath Triumph (40pts):                  Defeat Valentereth with the Mask of Wrath                    -|" << endl;
    cout << "|-       (";if(ach.complete[24]) cout << "X"; else cout << " "; cout << ") Darkness Triumph (40pts):               Defeat Valentereth with the Mask of Darkness                 -|" << endl;
    cout << "|-       (";if(ach.complete[25]) cout << "X"; else cout << " "; cout << ") Arcana Triumph (40pts):                 Defeat Valentereth with the Mask of Arcana                   -|" << endl;
    cout << "|-       (";if(ach.complete[26]) cout << "X"; else cout << " "; cout << ") Steel Triumph (40pts):                  Defeat Valentereth with the Mask of Steel                    -|" << endl;
    cout << "|-       (";if(ach.complete[27]) cout << "X"; else cout << " "; cout << ") Whispers Triumph (40pts):               Defeat Valentereth with the Mask of Whispers                 -|" << endl;
    cout << "|-       (";if(ach.complete[28]) cout << "X"; else cout << " "; cout << ") Beasts Triumph (40pts):                 Defeat Valentereth with the Mask of Beasts                   -|" << endl;
    cout << "|-       (";if(ach.complete[29]) cout << "X"; else cout << " "; cout << ") Souls Triumph (40pts):                  Defeat Valentereth with the Mask of Souls                    -|" << endl;
    cout << "|-                                                                                                                -|" << endl;
    cout << "|-       HIDDEN ACHIEVEMENTS                                                                                      -|" << endl;
    cout << "|-                                                                                                                -|" << endl;
    if(!ach.complete[30])
        cout << "|-       ( ) Gank (40pts)                                                                                         -|" << endl;
    else
        cout << "|-       (X) Gank (40pts): Defeat Valentereth on an ascent where only the word 'gank' is used to attack enemies   -|" << endl;
    if(!ach.complete[31])
        cout << "|-       ( ) Spectrum Triumph (80pts)                                                                             -|" << endl;
    else
        cout << "|-       (X) Spectrum Triumph (80pts): Defeat Valentereth once with each mask                                     -|" << endl;
    if(!ach.complete[32])
        cout << "|-       ( ) True Heir (75pts)                                                                                    -|" << endl;
    else
        cout << "|-       (X) True Heir (75pts): Defeat Valentereth in one strike                                                  -|" << endl;
    if(!ach.complete[33])
        cout << "|-       ( ) The Truth (50pts)                                                                                    -|" << endl;
    else
        cout << "|-       (X) The Truth (50pts): Defeat Termineth                                                                  -|" << endl;
    cout << "|-                                                                                                                -|" << endl;
    cout << "|-       0) RETURN                                                                                                -|" << endl;
    cout << "|-                                                                                                                -|" << endl;
    cout << "\\------------------------------------------------------------------------------------------------------------------/" << endl;
}

void mainMenu()
{
    std::system("cls");
    cout << "/----------------------------------------------------\\" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "|-                       MENU                       -|" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "|-       1) RETURN                                  -|" << endl;
    cout << "|-       2) STATS                                   -|" << endl;
    cout << "|-       3) EQUIPMENT                               -|" << endl;
    cout << "|-       4) ITEMS                                   -|" << endl;
    cout << "|-       5) SPELLBOOK                               -|" << endl;
    cout << "|-       6) QUIT                                    -|" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "\\----------------------------------------------------/" << endl;
}

void statMenu(Player hero, Directory dir)
{//50 long
    string strString;
    string crtString;
    string accString;
    if(hero.mask.getID()==1) //Wrath
    {
        strString = std::to_string(hero.getNSTR()+(hero.getNSTR()/2)) + " (+" + std::to_string(hero.eqpWpn.getStr()) + ")";
        accString = std::to_string(hero.getACC());
        crtString = std::to_string(hero.getNCRT()+(hero.getNCRT()/2)) + " (+" + std::to_string(hero.eqpWpn.getCrt()) + ")";
    }
    else
    {
        strString = std::to_string(hero.getNSTR()) + " (+" + std::to_string(hero.eqpWpn.getStr()) + ")";
        accString = std::to_string(hero.getACC());
        crtString = std::to_string(hero.getNCRT()) + " (+" + std::to_string(hero.eqpWpn.getCrt()) + ")";
    }
    std::system("cls");
    cout << "/----------------------------------------------------\\" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "|-                    STATS LIST                    -|" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "|-      " << setw(20) << std::left << hero.getName() << "           LEVEL " << setw(2) << std::left << hero.level << "     -|" << endl;
    cout << "|-      EXP: " << setw(7) << std::left << std::to_string(hero.exp) + "/" + std::to_string(hero.getEXPGoal()) << "                   GOLD: " << setw(5) << std::left << hero.gold << "  -|" << endl;
    cout << "|-      SCORE: " << setw(6) << std::left << score << "                               -|" << endl;
    cout << "|-      HP: " << setw(3) << std::right << hero.getHP() << "/" << setw(3) << std::left << hero.getMHP() << "                 MP: " << setw(3) << std::right << hero.getMP() << "/" << setw(3) << std::left << hero.getMMP() << "     -|" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "|-      WPN: " << setw(36) << std::left << hero.eqpWpn.getName() << "   -|" << endl;
    cout << "|-      AMR: " << setw(36) << std::left << hero.eqpAmr.getName() << "   -|" << endl;
    cout << "|-      RNG: " << setw(36) << std::left << hero.eqpRng.getName() << "   -|" << endl;
    if(hero.mask.getID()>=0)
    {
    cout << "|-                                                  -|" << endl;
    cout << "|-      <--" << setw(23) << std::left << hero.mask.getName()+"-->" << "                  -|" << endl;
    }
    cout << "|-                                                  -|" << endl;
    cout << "|-      ATK: " << setw(8) << std::left << strString << "             DEF: " << setw(8) << std::left << std::to_string(hero.getNDEF()) + " (+" + std::to_string(hero.eqpAmr.getDef()) + ")" << "     -|" << endl;
    cout << "|-      CRT: " << setw(8) << std::left << crtString << "             DDG: " << setw(8) << std::left << std::to_string(hero.getNDDG()) + " (+" + std::to_string(hero.eqpAmr.getDdg()) + ")" << "     -|" << endl;
    cout << "|-      ACC: " << setw(8) << std::left << accString << "             LCK: " << setw(8) << std::left << std::to_string(hero.getLCK()) << "     -|" << endl;
    cout << "|-      AMP: " << setw(4) << std::left << std::to_string(hero.getMA()) + "%" << "                 MPG: " << setw(2) << std::left << hero.getMG() << "           -|" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "|-      0) RETURN                                   -|" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "\\----------------------------------------------------/" << endl;
}

void equipmentMenu(vector<int> &equipment, Directory dir)
{//50 long
    std::system("cls");
    int i;
    cout << "/----------------------------------------------------\\" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "|-                  EQUIPMENT LIST                  -|" << endl;
    cout << "|-                                                  -|" << endl;
    for(i=0;i<equipment.size();i++)
        cout << "|-   " << i+1 << ") " << setw(40) << std::left << dir.getItemName(equipment[i]) << "    -|" << endl;
    for(int j=i;j<6;j++)
    cout << "|-   " << j+1 << ")                                             -|" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "|-         0) RETURN                                -|" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "\\----------------------------------------------------/" << endl;
}

void itemMenu(Player &hero, vector<int> &items, Directory dir)
{//50 long
    std::system("cls");
    int i;
    cout << "/----------------------------------------------------\\" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "|-                    ITEM  LIST                    -|" << endl;
    cout << "|-                                                  -|" << endl;
    for(i=0;i<items.size();i++)
        cout << "|-   " << i+1 << ") " << setw(40) << std::left << dir.getItemName(items[i]) << "    -|" << endl;
    for(int j=i;j<6;j++)
    cout << "|-   " << j+1 << ")                                             -|" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "|-   KEYS: " << setw(2) << std::left << hero.keys << "                                       -|" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "|-         0) RETURN                                -|" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "\\----------------------------------------------------/" << endl;
}

void spellbookMenu(vector<int> &spellbook, Directory dir)
{//50 long
    std::system("cls");
    int i;
    cout << "/----------------------------------------------------\\" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "|-                    SPELL LIST                    -|" << endl;
    cout << "|-                                                  -|" << endl;
    for(i=0;i<spellbook.size();i++)
        cout << "|-   " << setw(2)  << std::right << i+1 << ") " << setw(40) << std::left << dir.getItemName(spellbook[i]) << "   -|" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "|-         0) RETURN                                -|" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "\\----------------------------------------------------/" << endl;
}

void storeMenu(Player hero, Merchant store, Directory dir)
{
    std::system("cls");
    int i;
    cout << "/--------------------------------------------------------------\\" << endl;
    cout << "|-                                                            -|" << endl;
    cout << "|-                            SHOP                            -|" << endl;
    cout << "|-                                                            -|" << endl;
    for(i=0;i<store.storeInventory.size();i++)
        cout << "|-   " << i+1 << ") " << setw(35) << std::left << dir.getItemName(store.storeInventory[i]) << "          " << setw(4) << std::right << store.storeCost[i] << "G    -|" << endl;
    for(int j=i;j<5;j++)
        cout << "|-   " << j+1 << ")                                                       -|" << endl;
    cout << "|-                                                            -|" << endl;
    cout << "|-   0) RETURN                                 GOLD: " << setw(5) << std::left << hero.gold << "    -|" << endl;
    cout << "|-                                                            -|" << endl;
    cout << "\\-------------------------------------------------------------/" << endl;
}

void diviningMenu(Player hero, Merchant store, Directory dir)
{
    std::system("cls");
    int i;
    vector<string> statUp;
    vector<int> curStatUp;
    vector<string> statDown;
    vector<int> curStatDown;
    for(int i=0;i<2;i++)
    {
        statDown.push_back("");
        statUp.push_back("");
        curStatDown.push_back(0);
        curStatUp.push_back(0);
        switch(store.getStatDown()[i])
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
        switch(store.getStatUp()[i])
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
    cout << "/--------------------------------------------------------------\\" << endl;
    cout << "|-                                                            -|" << endl;
    cout << "|-                          DIVINING                          -|" << endl;
    cout << "|-             --------------------------------               -|" << endl;
    for(int i=0;i<2;i++)
        cout << "|-               (2) " << statDown[i] << "  ---------->  (1) " << statUp[i] << "                -|" << endl;
    cout << "|-             --------------------------------               -|" << endl;
    cout << "|-                                                            -|" << endl;
    for(int i=0;i<2;i++)
    {
        cout << "|-   CURRENT " << statDown[i] << ": " << setw(3) << std::left << curStatDown[i] << "                                         -|" << endl;
        cout << "|-   CURRENT " << statUp[i] << ": " << setw(3) << std::left << curStatUp[i] << "                                         -|" << endl;
        cout << "|-                                                            -|" << endl;
    }
    cout << "|-   COST: " << setw(3) << std::left << store.getSwapCost() << "                                                -|" << endl;
    cout << "|-                                                            -|" << endl;
    cout << "|-   1) DIVINE 1                                              -|" << endl;
    cout << "|-   2) DIVINE 2                                              -|" << endl;
    cout << "|-                                                            -|" << endl;
    cout << "|-   0) RETURN                                 GOLD: " << setw(5) << std::left << hero.gold << "    -|" << endl;
    cout << "|-                                                            -|" << endl;
    cout << "\\-------------------------------------------------------------/" << endl;
}

void combatMain(Player hero, Creature monster, int monCHP)
{//111 Long
    string monName;
    string enemyHP = std::to_string(monster.getHP());
    string enemyCHP = std::to_string(monCHP);
    if(hero.mask.getID()==2)
        monName = "Silhouette";
    else
        monName = monster.getName();

    string monHP = "";
    string secondMonHP = "";
    if(monCHP<=100)
        for(int i=0;i<monCHP;i++)
            monHP += "|";
    else
        for(int i=0;i<monCHP;i++)
        {
            if(i<100)
                monHP += "|";
            else
                secondMonHP += "|";
        }

    if(hero.mask.getID()==2) //Darkness
    {
        monHP = "";
        if(monster.getHP()<=100)
            for(int i=0;i<monster.getHP();i++)
                monHP += "X";
        else
            for(int i=0;i<monster.getHP();i++)
            {
                if(i<100)
                    monHP += "X";
                else
                    secondMonHP += "X";
            }
        monName = "Silhouette";
        enemyHP = "XX";
        enemyCHP = "XX";
    }

    string plrHP = "";
    string secondPlrHP = "";
    if(hero.getHP()<=100)
        for(int i=0;i<hero.getHP();i++)
            plrHP += "|";
    else
        for(int i=0;i<hero.getHP();i++)
        {
            if(i<100)
                plrHP += "|";
            else
                secondPlrHP += "|";
        }

    std::system("cls");
    cout << "  /------------------------------------------------------------------------------------------------------------------\\" << endl;
    cout << "  |-  " << setw(59) << std::left << "< " + monName + " >  [ " + enemyCHP + " \\ " + enemyHP + " ]" << "                                                   -|" << endl;
    if(monster.getHP()<=100)
    {
        cout << "  |- {" << setw(monster.getHP()) << std::left << monHP << setw(103-monster.getHP()) << std::left << "} " << "       -|" << endl;
        cout << "  |-                                                                                                                -|" << endl;
    }
    else
    {
        cout << "  |- {" << setw(100) << std::left << monHP << setw(103-monster.getHP()) << std::left << "} " << "        -|" << endl;
        cout << "  |- {" << setw(monster.getHP()-100) << std::left << secondMonHP << setw(103-(monster.getHP()-100)) << std::left << "} " << "       -|" << endl;
    }
    cout << "  |-                                                                                                                -|" << endl;
    if(hero.getMHP()<=100)
    {
        cout << "  |-                                                                                                                -|" << endl;
        cout << "  |-                                                        " << setw(54) << std::right << "< " + hero.getName() + " >  [ " + std::to_string(hero.getHP()) + " \\ " + std::to_string(hero.getMHP()) + " ]" << "  -|" << endl;
        cout << "  |-       " << setw(103-hero.getMHP()) << std::right << " {" << setw(hero.getMHP()) << std::right << plrHP << "} -|" << endl;
    }
    else
    {
            cout << "  |-                                                        " << setw(54) << std::right << "< " + hero.getName() + " >  [ " + std::to_string(hero.getHP()) + " \\ " + std::to_string(hero.getMHP()) + " ]" << "  -|" << endl;
            cout << "  |-       " << setw(103-(hero.getMHP()-100)) << std::right << " {" << setw(hero.getMHP()-100) << std::right << secondPlrHP << "} -|" << endl;
            cout << "  |-       " << setw(103-hero.getMHP()) << std::right << "  {" << setw(100) << std::right << plrHP << "} -|" << endl;
    }
    cout << "  |------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << "  |-                           |                            |                            |                          -|" << endl;
    cout << "  |-     <--STRIKE [J]-->      |       <--CAST [K]-->       |        <--USE [L]-->       |       <--RUN [;]-->      -|" << endl;
    cout << "  |-                           |         " << setw(3) << std::right << hero.getMP() << " // " << setw(3) << std::left << hero.getMMP() << "         |                            |                          -|" << endl;
    cout << "  \\------------------------------------------------------------------------------------------------------------------/" << endl;
}//                         27                           28                            28                           28
