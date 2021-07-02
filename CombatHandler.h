int combatHandler(Player &hero, Creature &monster, Directory dir, int gd, int ex)
{
    int end = 0;
    bool win;
    bool confirm;
    char yn;
    string action;
    string strChoice;
    string monName = monster.getName();
    int choice;
    int hit;
    int crit;
    int dmg;
    float fdmg;
    int atkBuff=0;
    int defBuff=0;
    int accBuff=0;
    int ddgBuff=0;
    int crtBuff=0;
    int hpBuff=0;
    float amp;
    int monHP = monster.getHP();
    vector<Buff> buffCounter;

    if(hero.mask.getID()==2) //Darkness
        monName = "Silhouette";

    amp = static_cast<float>(hero.getMA())/100;
    //cout << "AMP: " << hero.getMA() << " / 100 = " << amp << endl;
    //Sleep(3000);

    while(end==0)
    {
        if(hero.getHP()>hero.getMHP())
            hero.setHP(hero.getMHP());
        if(hero.getMP()>hero.getMMP())
            hero.setMP(hero.getMMP());
        combatMain(hero,monster,monHP);
        cout << endl << "Your Turn!" << endl << ": ";
        action = getch();
        if(action=="j"||hero.mask.getID()==6)
        {
            if(hero.mask.getID()==6)
                cout << "You lunge at the " << monName << " ferociously!" << endl;
            else
                cout << "You attack the " << monName << "!" << endl;
            Sleep(1000);
            hit = rand() % 100 + 1;
            //cout << hit+monster.getDDG() << ", " << hero.getACC()+accBuff << endl;
            if(hit+monster.getDDG()<=hero.getACC()+accBuff)
            {
                crit = rand() % 100 + 1;
                if(crit<=hero.getCRT()+crtBuff)
                {
                    cout << "Critical Hit!" << endl;
                    Sleep(1000);
                    dmg = (hero.getSTR()+atkBuff - monster.getDEF())*2;
                    if(hero.mask.getID()==0) //Glass
                        dmg = dmg*2;
                    if(hero.mask.getID()==3) //Arcana
                        dmg = dmg/2;
                    if(hero.mask.getID()==6) //Beasts
                        dmg = dmg + (dmg/2);
                    monHP -= dmg;
                    cout << "Dealt " << dmg << " damage to " << monName << "!" << endl;
                    Sleep(2000);
                }
                else
                {
                    cout << "Hit!" << endl;
                    Sleep(1000);
                    dmg = hero.getSTR()+atkBuff - monster.getDEF();
                    if(hero.mask.getID()==0) //Glass
                        dmg = dmg*2;
                    if(hero.mask.getID()==3) //Arcana
                        dmg = dmg/2;
                    if(hero.mask.getID()==6) //Beasts
                        dmg = dmg + (dmg/2);
                    monHP -= dmg;
                    cout << "Dealt " << dmg << " damage to " << monName << "!" << endl;
                    Sleep(2000);
                }
            }
            else
            {
                cout << "You missed..." << endl;
                Sleep(2000);
            }
        }
        else if(action=="k")
        {
            confirm = 0;
            while(confirm==0)
            {
                spellbookMenu(hero.spellbook,dir);
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> choice;
                if(choice>50)
                    continue;
                if(choice<=hero.spellbook.size()&&choice>0)
                {
                    int manacost;
                    if(hero.spellbook[choice-1]<=214)
                        manacost = dir.attackSpellDirectory[hero.spellbook[choice-1]-200].getManaCost();
                    else if(hero.spellbook[choice-1]<=220)
                        manacost = dir.healingSpellDirectory[hero.spellbook[choice-1]-215].getManaCost();
                    else
                        manacost = dir.buffSpellDirectory[hero.spellbook[choice-1]-221].getManaCost();
                    if(hero.getMP()>=manacost)
                    {
                        cout << dir.getItemName(hero.spellbook[choice-1]) << ": " << dir.getItemDesc(hero.spellbook[choice-1]) << endl;
                        if(hero.spellbook[choice-1]<=214)
                        {
                            cout << "MANA COST: " << dir.attackSpellDirectory[hero.spellbook[choice-1]-200].getManaCost() << endl;
                            cout << "DAMAGE: " << ceil(static_cast<float>(dir.attackSpellDirectory[hero.spellbook[choice-1]-200].getDMG())+(amp*static_cast<float>(dir.attackSpellDirectory[hero.spellbook[choice-1]-200].getDMG()))) << endl;
                        }
                        else if(hero.spellbook[choice-1]<=220)
                        {
                            cout << "MANA COST: " << dir.healingSpellDirectory[hero.spellbook[choice-1]-215].getManaCost() << endl;
                            cout << "HEALING: " << ceil(static_cast<float>(dir.healingSpellDirectory[hero.spellbook[choice-1]-215].getHPR())+(amp*static_cast<float>(dir.healingSpellDirectory[hero.spellbook[choice-1]-215].getHPR()))) << endl;
                        }
                        else
                        {
                            cout << "MANA COST: " << dir.buffSpellDirectory[hero.spellbook[choice-1]-221].getManaCost() << endl;
                        }
                        cout << "Cast? (y/n)" << endl;
                        yn = getch();
                        if(yn=='y')
                            confirm = 1;
                    }
                    else
                    {
                        cout << "You don't have enough mana." << endl;
                        break;
                    }
                }
                else if(choice==0)
                {
                    break;
                }
                else
                {
                    cout << "Unknown spell." << endl;
                    Sleep(2000);
                }
            }
            if(confirm==0)
                continue;
            if(confirm==1)
            {
                if(hero.spellbook[choice-1]<=214)
                {
                    //cout << "Attack Spell!" << endl;
                    fdmg = static_cast<float>(dir.attackSpellDirectory[hero.spellbook[choice-1]-200].getDMG());
                    dmg = ceil(fdmg+(amp*fdmg));
                    //cout << dmg << " = " << fdmg << " + (" << amp << " * " << fdmg << ")" << endl;
                    if(monster.getID()==43)
                        dmg = dmg/2;
                    monHP -= dmg;
                    cout << hero.getName() << " cast " << dir.getItemName(hero.spellbook[choice-1]) << "!" << endl;
                    cout << "Dealt " << dmg << " damage to " << monName << "!" << endl;
                    hero.changeMP(-(dir.attackSpellDirectory[hero.spellbook[choice-1]-200].getManaCost()));
                    Sleep(2000);
                }
                else if(hero.spellbook[choice-1]<=220)
                {
                    //cout << "Healing Spell!" << endl;

                    cout << hero.getName() << " cast " << dir.getItemName(hero.spellbook[choice-1]) << "!" << endl;
                    hero.changeMP(-(dir.healingSpellDirectory[hero.spellbook[choice-1]-215].getManaCost()));
                    if(hero.spellbook[choice-1]==217||hero.spellbook[choice-1]==218||hero.spellbook[choice-1]==220)
                    {
                        Buff regen(0,0,0,0,0,dir.healingSpellDirectory[hero.spellbook[choice-1]-215].getHPR());
                        buffCounter.push_back(regen);
                    }
                    else
                    {
                        fdmg = static_cast<float>(dir.healingSpellDirectory[hero.spellbook[choice-1]-215].getHPR());
                        dmg = ceil(fdmg+(amp*fdmg));
                        cout << "Restored " << dmg << " HP!" << endl;
                        hero.changeHP(dmg);
                        if(hero.getHP()>hero.getMHP())
                            hero.changeHP(-(hero.getMHP()-hero.getHP()));
                    }
                    Sleep(2000);
                }
                else
                {
                    //cout << "Buff Spell!" << endl;
                    Buff newBuff(dir.buffSpellDirectory[hero.spellbook[choice-1]-221].getATKU(),
                        dir.buffSpellDirectory[hero.spellbook[choice-1]-221].getDEFU(),
                        dir.buffSpellDirectory[hero.spellbook[choice-1]-221].getCRTU(),
                        dir.buffSpellDirectory[hero.spellbook[choice-1]-221].getACCU(),
                        dir.buffSpellDirectory[hero.spellbook[choice-1]-221].getDDGU(), 0);
                    buffCounter.push_back(newBuff);
                    cout << hero.getName() << " cast " << dir.getItemName(hero.spellbook[choice-1]) << "!" << endl;
                    hero.changeMP(-(dir.buffSpellDirectory[hero.spellbook[choice-1]-221].getManaCost()));
                    Sleep(2000);
                }
            }
        }
        else if(action=="l")
        {
            confirm = 0;
            while(confirm==0)
            {
                itemMenu(hero,hero.inventory,dir);
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> choice;
                if(choice<=hero.inventory.size()&&choice>0)
                {
                    cout << dir.getItemName(hero.inventory[choice-1]) << ": " << dir.getItemDesc(hero.inventory[choice-1]) << endl;
                    cout << "Use this? (y/n)" << endl;
                    yn = getch();
                    if(yn=='y')
                        confirm = 1;
                }
                else if(choice==0)
                    break;
                else
                {
                    cout << "Unknown item." << endl;
                    Sleep(2000);
                }
            }
            if(choice==0)
                continue;
            if(confirm==1)
            {
                cout << hero.getName() << " used " << dir.getItemName(hero.inventory[choice-1]) << "!" << endl;
                if(dir.consumableDirectory[hero.inventory[choice-1]-100].getHP()!=0)
                {
                    hero.changeHP(dir.consumableDirectory[hero.inventory[choice-1]-100].getHP());
                    cout << "Restored " << dir.consumableDirectory[hero.inventory[choice-1]-100].getHP() << " HP!" << endl;
                }
                if(dir.consumableDirectory[hero.inventory[choice-1]-100].getMP()!=0)
                {
                    hero.changeMP(dir.consumableDirectory[hero.inventory[choice-1]-100].getMP());
                    cout << "Restored " << dir.consumableDirectory[hero.inventory[choice-1]-100].getMP() << " MP!" << endl;
                }
                hero.inventory.erase(hero.inventory.begin()+choice-1);
            }
        }
        else if(action==";")
        {
            {
                hit = rand() % 100 + 1;
                if(hero.getDDG()>=15)
                {
                    if(hit>50) //pass
                    {
                        cout << "You escape successfully!" << endl;
                        Sleep(2000);
                        end = 3;
                        break;
                    }
                    else if(hit>25) //pass, but damage
                    {
                        cout << "The enemy attacks as you escape!" << endl;
                        Sleep(2000);
                        dmg = monster.getSTR() - hero.getDEF();
                        if(hero.mask.getID()==0) //Glass
                            dmg = dmg*2;
                        if(hero.mask.getID()==4) //Steel
                            dmg = dmg/2;
                        if(dmg<0)
                            dmg = 0;
                        hero.changeHP(-dmg);
                        cout << "Dealt " << dmg << " damage!" << endl;
                        Sleep(2000);
                        if(hero.getHP()<=0)
                        {
                            end = 2;
                            break;
                        }
                        end = 3;
                        break;
                    }
                    else //no pass, damage
                    {
                        cout << "The enemy knocks you back into the room, blocking your way!" << endl;
                        Sleep(2000);
                        dmg = monster.getSTR() - hero.getDEF();
                        if(hero.mask.getID()==0) //Glass
                            dmg = dmg*2;
                        if(hero.mask.getID()==4) //Steel
                            dmg = dmg/2;
                        if(dmg<0)
                            dmg = 0;
                        hero.changeHP(-dmg);
                        cout << "Dealt " << dmg << " damage!" << endl;
                        Sleep(2000);
                    }
                }
                else
                {
                    if(hit>66) //pass
                    {
                        cout << "You escape successfully!" << endl;
                        Sleep(2000);
                        end = 3;
                        break;
                    }
                    else if(hit>33) //pass, but damage
                    {
                        cout << "The enemy attacks as you escape!" << endl;
                        Sleep(2000);
                        dmg = monster.getSTR() - hero.getDEF();
                        if(hero.mask.getID()==0)
                            dmg = dmg*2;
                        if(dmg<0)
                            dmg = 0;
                        hero.changeHP(-dmg);
                        cout << "Dealt " << dmg << " damage!" << endl;
                        Sleep(2000);
                        if(hero.getHP()<=0)
                        {
                            end = 2;
                            break;
                        }
                        end = 3;
                        break;
                    }
                    else //no pass, damage
                    {
                        cout << "The enemy knocks you back into the room, blocking your way!" << endl;
                        Sleep(2000);
                        dmg = monster.getSTR() - hero.getDEF();
                        if(hero.mask.getID()==0)
                            dmg = dmg*2;
                        if(dmg<0)
                            dmg = 0;
                        hero.changeHP(-dmg);
                        cout << "Dealt " << dmg << " damage!" << endl;
                        Sleep(2000);
                    }
                }
            }
        }
        else
        {
            cout << "Unknown action." << endl;
            Sleep(1000);
            continue;
        }
        if(monHP<=0)
        {
            end = 1;
            break;
        }
        if(hero.getHP()<=0)
        {
            end = 2;
            break;
        }

        for(int i=0;i<buffCounter.size();i++)
        {
            //cout << "Count on buff " << i << " is " << buffCounter[i].getCount() << endl;
            buffCounter[i].tick();
            if(buffCounter[i].getCount()==0)
            {
                buffCounter.erase(buffCounter.begin()+i);
                i--;
            }
        }
        atkBuff = 0;
        defBuff = 0;
        accBuff = 0;
        ddgBuff = 0;
        crtBuff = 0;
        hpBuff = 0;
        for(int i=0;i<buffCounter.size();i++)
        {
            atkBuff += buffCounter[i].getATKU();
            defBuff += buffCounter[i].getDEFU();
            accBuff += buffCounter[i].getACCU();
            ddgBuff += buffCounter[i].getDDGU();
            crtBuff += buffCounter[i].getCRTU();
            hpBuff += buffCounter[i].getHPU();
        }
        /*cout << "Attack Buff: " << atkBuff << endl;
        cout << "Defense Buff: " << defBuff << endl;
        cout << "Accuracy Buff: " << accBuff << endl;
        cout << "Dodge Buff: " << ddgBuff << endl;
        cout << "Crit Buff: " << crtBuff << endl;
        cout << "HP Buff: " << hpBuff << endl;*/
        hero.changeHP(hpBuff);
        hero.changeMP(hero.getMG());
        //Sleep(1000);
        cout << monName << "'s Turn!" << endl;
        Sleep(1000);
        cout << monName << " attacks!" << endl;
        Sleep(1000);
        hit = rand() % 100 + 1;

        if(hero.mask.getID()==4) //Steel
            hit = -1000;

        if(hit+hero.getDDG()+ddgBuff<=monster.getACC())
        {
            cout << monName << " hits!" << endl;
            Sleep(1000);
            dmg = monster.getSTR() - hero.getDEF() - defBuff;
            if(hero.mask.getID()==0||hero.mask.getID()==5) //Glass, Whispers
                dmg = dmg*2;
            if(hero.mask.getID()==4) //Steel
                dmg = dmg/2;
            if(dmg<0)
                dmg = 0;
            hero.changeHP(-dmg);
            cout << "Dealt " << dmg << " damage!" << endl;
            Sleep(2000);
        }
        else
        {
            cout << monName << " misses!" << endl;
            Sleep(2000);
        }
        if(hero.getHP()<=0)
        {
            end = 2;
            break;
        }
    }

    if(end==1)
    {
        cout << "You win!" << endl;
        Sleep(2000);
        hero.gold += gd;
        hero.exp += ex;
        cout << "You earned " << gd << " gold!" << endl;
        cout << "You gained " << ex << " exp!" << endl;
        Sleep(2000);
        std::system("cls");
        return 1;
    }
    if(end==2)
    {
        cout << "You have fallen..." << endl;
        Sleep(2000);
        std::system("cls");
        return 2;
    }
    if(end==3)
    {
        std::system("cls");
        return 3;
    }
    cout << "Error!" << endl;
    return 0;
}
