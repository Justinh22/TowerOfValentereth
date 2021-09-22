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
    cout << " |     4) Masks                                                                                                       | " << endl;
    cout << " |                                                                                                             v1.5.2 | " << endl;
    cout << " |____________________________________________________________________________________________________________________| " << endl;
    cout << "                                                                                                                        " << endl;
}

void scores()
{
    std::ifstream readFile("HighScores.txt");
    string data;
    string clear;
    string nameArr[10];
    int depthArr[10];
    int i = 0;

    while(std::getline(readFile,data))
    {
        std::stringstream line(data);
        line >> nameArr[i] >> depthArr[i];
        i++;
        if(i>=10)
            break;
    }

    std::system("cls");
    cout << "/----------------------------------------------------\\" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "|-                   HIGH  SCORES                   -|" << endl;
    cout << "|-                                                  -|" << endl;
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
        data = std::to_string(i+1) + ") " + nameArr[i] + " | " + std::to_string(depthArr[i]) + " floors    " + clear;
        cout << "|-      " << setw(40) << std::left << data << "    -|" << endl;
    }
    cout << "|-                                                  -|" << endl;
    cout << "|-      0) RETURN                                   -|" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "\\----------------------------------------------------/" << endl;
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
    cout << "|-      HP: " << setw(3) << std::right << hero.getHP() << "/" << setw(3) << std::left << hero.getMHP() << "                 MP: " << setw(3) << std::right << hero.getMP() << "/" << setw(3) << std::left << hero.getMMP() << "     -|" << endl;
    cout << "|-                                                  -|" << endl;
    cout << "|-      WPN: " << setw(36) << std::left << hero.eqpWpn.getName() << "   -|" << endl;
    cout << "|-      AMR: " << setw(36) << std::left << hero.eqpAmr.getName() << "   -|" << endl;
    if(hero.mask.getID()>=0)
    {
    cout << "|-                                                  -|" << endl;
    cout << "|-      <--" << setw(23) << std::left << hero.mask.getName()+"-->" << "                  -|" << endl;
    }
    cout << "|-                                                  -|" << endl;
    cout << "|-      ATK: " << setw(8) << std::left << strString << "             DEF: " << setw(8) << std::left << std::to_string(hero.getNDEF()) + " (+" + std::to_string(hero.eqpAmr.getDef()) + ")" << "     -|" << endl;
    cout << "|-      CRT: " << setw(8) << std::left << crtString << "             DDG: " << setw(8) << std::left << std::to_string(hero.getNDDG()) + " (+" + std::to_string(hero.eqpAmr.getDdg()) + ")" << "     -|" << endl;
    cout << "|-      ACC: " << setw(8) << std::left << accString << "                               -|" << endl;
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
    for(int i=0;i<monCHP;i++)
        monHP += "|";

    if(hero.mask.getID()==2) //Darkness
    {
        monHP = "";
        for(int i=0;i<monster.getHP();i++)
            monHP += "X";
        monName = "Silhouette";
        enemyHP = "XX";
        enemyCHP = "XX";
    }

    string plrHP;
    for(int i=0;i<hero.getHP();i++)
        plrHP += "|";
    std::system("cls");
    cout << "  /------------------------------------------------------------------------------------------------------------------\\" << endl;
    cout << "  |-  " << setw(59) << std::left << "< " + monName + " >  [ " + enemyCHP + " \\ " + enemyHP + " ]" << "                                                   -|" << endl;
    cout << "  |- {" << setw(monster.getHP()) << std::left << monHP << setw(103-monster.getHP()) << std::left << "} " << "       -|" << endl;
    cout << "  |-                                                                                                                -|" << endl;
    cout << "  |-                                                                                                                -|" << endl;
    cout << "  |-                                                                                                                -|" << endl;
    cout << "  |-                                                        " << setw(54) << std::right << "< " + hero.getName() + " >  [ " + std::to_string(hero.getHP()) + " \\ " + std::to_string(hero.getMHP()) + " ]" << "  -|" << endl;
    cout << "  |-       " << setw(103-hero.getMHP()) << std::right << " {" << setw(hero.getMHP()) << std::right << plrHP << "} -|" << endl;
    cout << "  |------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << "  |-                           |                            |                            |                          -|" << endl;
    cout << "  |-     <--STRIKE [J]-->      |       <--CAST [K]-->       |        <--USE [L]-->       |       <--RUN [;]-->      -|" << endl;
    cout << "  |-                           |         " << setw(3) << std::right << hero.getMP() << " // " << setw(3) << std::left << hero.getMMP() << "         |                            |                          -|" << endl;
    cout << "  \\------------------------------------------------------------------------------------------------------------------/" << endl;
}//                         27                           28                            28                           28
