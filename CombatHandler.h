int combatHandler(Player &hero, Creature &monster, Directory dir, int gd, int ex)
{
    int end = 0;
    bool win;
    bool confirm;
    bool parry=0; //Stiran
    bool full=0;
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
    float red;
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

        for(int i=0;i<buffCounter.size();i++)
            if(buffCounter[i].getCount()>1)
                cout << buffCounter[i].getName() << " lasts for " << buffCounter[i].getCount()-1 << " more turns." << endl;

        cout << endl << "Your Turn!" << endl << ": ";
        action = getch();
        if(action=="j"||hero.mask.getID()==6)
        {
            if(hero.mask.getID()==6)
                cout << "You lunge at the " << monName << " ferociously!" << endl;
            else if(parry==0)
                cout << "You attack the " << monName << "!" << endl;
            else
                cout << "You strike at the " << monName << "'s weak point!" << endl;
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
                    if(hero.eqpWpn.getID()==57) //Ozkoroth's Fang
                        dmg = (ceil(static_cast<float>(monster.getHP())*.25))*2;
                    if(hero.eqpWpn.getID()==58) //Energy Siphon
                    {
                        dmg = ((hero.getSTR()*2)+atkBuff - monster.getDEF())*2;
                        hero.changeMP(5);
                    }
                    if(hero.mask.getID()==0||parry) //Glass
                        dmg = dmg*2;
                    if(hero.mask.getID()==3) //Arcana
                        dmg = dmg/2;
                    if(hero.mask.getID()==6) //Beasts
                        dmg = dmg + (dmg/2);
                    if(monster.getID()==61) //?????
                        dmg = static_cast<float>(dmg)*.7;
                    monHP -= dmg;
                    cout << "Dealt " << dmg << " damage to " << monName << "!" << endl;
                    Sleep(2000);
                }
                else
                {
                    cout << "Hit!" << endl;
                    Sleep(1000);
                    dmg = hero.getSTR()+atkBuff - monster.getDEF();
                    if(hero.eqpWpn.getID()==57) //Ozkoroth's Fang
                        dmg = ceil(static_cast<float>(monster.getHP())*.25);
                    if(hero.eqpWpn.getID()==58) //Energy Siphon
                    {
                        dmg = (hero.getSTR()*2)+atkBuff - monster.getDEF();
                        hero.changeMP(5);
                    }
                    if(hero.mask.getID()==0||parry) //Glass
                        dmg = dmg*2;
                    if(hero.mask.getID()==3) //Arcana
                        dmg = dmg/2;
                    if(hero.mask.getID()==6) //Beasts
                        dmg = dmg + (dmg/2);
                    if(monster.getID()==61) //?????
                        dmg = static_cast<float>(dmg)*.7;
                    monHP -= dmg;
                    cout << "Dealt " << dmg << " damage to " << monName << "!" << endl;
                    Sleep(2000);
                }
            }
            else
            {
                cout << "You missed..." << endl;
                if(monster.getID()==60)
                    parry = 1;
                Sleep(2000);
            }
            if(hero.eqpAmr.getID()==142)
                parry = 0;
        }
        else if(action=="k")
        {
            confirm = 0;
            while(confirm==0)
            {
                spellbookMenu(hero.spellbook,dir);
                cout << "SELECT: ";
                if(hero.spellbook.size()>9)
                    cin >> strChoice;
                else
                    strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> choice;
                if(choice>50)
                    continue;
                if(choice<=hero.spellbook.size()&&choice>0)
                {
                    int manacost;
                    if(hero.spellbook[choice-1]<=314)
                        manacost = dir.attackSpellDirectory[hero.spellbook[choice-1]-300].getManaCost();
                    else if(hero.spellbook[choice-1]<=320)
                        manacost = dir.healingSpellDirectory[hero.spellbook[choice-1]-315].getManaCost();
                    else
                        manacost = dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getManaCost();
                    if(hero.getMP()>=manacost)
                    {
                        cout << dir.getItemName(hero.spellbook[choice-1]) << ": " << dir.getItemDesc(hero.spellbook[choice-1]) << endl;
                        if(hero.spellbook[choice-1]<=314)
                        {
                            cout << "MANA COST: " << dir.attackSpellDirectory[hero.spellbook[choice-1]-300].getManaCost() << endl;
                            cout << "DAMAGE: " << ceil(static_cast<float>(dir.attackSpellDirectory[hero.spellbook[choice-1]-300].getDMG())+(amp*static_cast<float>(dir.attackSpellDirectory[hero.spellbook[choice-1]-300].getDMG()))) << endl;
                        }
                        else if(hero.spellbook[choice-1]<=320)
                        {
                            cout << "MANA COST: " << dir.healingSpellDirectory[hero.spellbook[choice-1]-315].getManaCost() << endl;
                            cout << "HEALING: " << ceil(static_cast<float>(dir.healingSpellDirectory[hero.spellbook[choice-1]-315].getHPR())+(amp*static_cast<float>(dir.healingSpellDirectory[hero.spellbook[choice-1]-315].getHPR()))) << endl;
                        }
                        else
                        {
                            cout << "MANA COST: " << dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getManaCost() << endl;
                            if(ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getATKU())+(amp*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getATKU())))>0)
                                cout << "ATK BUFF: " << ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getATKU())+(amp*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getATKU()))) << endl;
                            if(ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getDEFU())+(amp*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getDEFU())))>0)
                                cout << "DEF BUFF: " << ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getDEFU())+(amp*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getDEFU()))) << endl;
                            if(ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getCRTU())+(amp*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getCRTU())))>0)
                                cout << "CRT BUFF: " << ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getCRTU())+(amp*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getCRTU()))) << endl;
                            if(ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getACCU())+(amp*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getACCU())))>0)
                                cout << "ACC BUFF: " << ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getACCU())+(amp*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getACCU()))) << endl;
                            if(ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getDDGU())+(amp*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getDDGU())))>0)
                                cout << "DDG BUFF: " << ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getDDGU())+(amp*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getDDGU()))) << endl;
                        }
                        cout << "Cast? (y/n)" << endl;
                        yn = getch();
                        if(yn=='y')
                            confirm = 1;
                    }
                    else
                    {
                        cout << "You don't have enough mana." << endl;
                        Sleep(2000);
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
                if(hero.spellbook[choice-1]<=314)
                {
                    //cout << "Attack Spell!" << endl;
                    fdmg = static_cast<float>(dir.attackSpellDirectory[hero.spellbook[choice-1]-300].getDMG());
                    dmg = ceil(fdmg+(amp*fdmg));
                    //cout << dmg << " = " << fdmg << " + (" << amp << " * " << fdmg << ")" << endl;
                    if(monster.getID()==48) //Valentereth
                        dmg = dmg/2;
                    if(monster.getID()==61) //?????
                        dmg = static_cast<float>(dmg)*.7;
                    monHP -= dmg;
                    cout << hero.getName() << " cast " << dir.getItemName(hero.spellbook[choice-1]) << "!" << endl;
                    cout << "Dealt " << dmg << " damage to " << monName << "!" << endl;
                    hero.changeMP(-(dir.attackSpellDirectory[hero.spellbook[choice-1]-300].getManaCost()));
                    Sleep(2000);
                }
                else if(hero.spellbook[choice-1]<=320)
                {
                    //cout << "Healing Spell!" << endl;

                    cout << hero.getName() << " cast " << dir.getItemName(hero.spellbook[choice-1]) << "!" << endl;
                    hero.changeMP(-(dir.healingSpellDirectory[hero.spellbook[choice-1]-315].getManaCost()));
                    if(hero.spellbook[choice-1]==317||hero.spellbook[choice-1]==318||hero.spellbook[choice-1]==320)
                    {
                        Buff regen(dir.getItemName(hero.spellbook[choice-1]),0,0,0,0,0,ceil(static_cast<float>(dir.healingSpellDirectory[hero.spellbook[choice-1]-315].getHPR())+(amp*static_cast<float>(dir.healingSpellDirectory[hero.spellbook[choice-1]-315].getHPR()))));
                        buffCounter.push_back(regen);
                    }
                    else
                    {
                        fdmg = static_cast<float>(dir.healingSpellDirectory[hero.spellbook[choice-1]-315].getHPR());
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
                    Buff newBuff(dir.getItemName(hero.spellbook[choice-1]),
                        ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getATKU())+(amp*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getATKU()))),
                        ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getDEFU())+(amp*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getDEFU()))),
                        ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getCRTU())+(amp*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getCRTU()))),
                        ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getACCU())+(amp*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getACCU()))),
                        ceil(static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getDDGU())+(amp*static_cast<float>(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getDDGU()))), 0);
                    buffCounter.push_back(newBuff);
                    cout << hero.getName() << " cast " << dir.getItemName(hero.spellbook[choice-1]) << "!" << endl;
                    hero.changeMP(-(dir.buffSpellDirectory[hero.spellbook[choice-1]-321].getManaCost()));
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
                    cout << "HP: " << dir.consumableDirectory[hero.inventory[choice-1]-200].getHP() << endl;
                    cout << "MP: " << dir.consumableDirectory[hero.inventory[choice-1]-200].getMP() << endl << endl;
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
                if(dir.consumableDirectory[hero.inventory[choice-1]-200].getHP()!=0)
                {
                    hero.changeHP(dir.consumableDirectory[hero.inventory[choice-1]-200].getHP());
                    cout << "Restored " << dir.consumableDirectory[hero.inventory[choice-1]-200].getHP() << " HP!" << endl;
                }
                if(dir.consumableDirectory[hero.inventory[choice-1]-200].getMP()!=0)
                {
                    hero.changeMP(dir.consumableDirectory[hero.inventory[choice-1]-200].getMP());
                    cout << "Restored " << dir.consumableDirectory[hero.inventory[choice-1]-200].getMP() << " MP!" << endl;
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
                        if(monster.getID()!=57)
                            dmg = monster.getSTR() - hero.getDEF() - defBuff;
                        else //Ozkoroth
                        {
                            red = .7;
                            dmg = monster.getSTR() - ceil(red*(static_cast<float>(hero.getDEF()) - defBuff));
                        }
                        if(hero.mask.getID()==0||hero.mask.getID()==5) //Glass, Whisper
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
                        if(monster.getID()!=57)
                            dmg = monster.getSTR() - hero.getDEF() - defBuff;
                        else //Ozkoroth
                        {
                            red = .7;
                            dmg = monster.getSTR() - ceil(red*(static_cast<float>(hero.getDEF()) - defBuff));
                        }
                        if(hero.mask.getID()==0||hero.mask.getID()==5) //Glass, Whisper
                            dmg = dmg*2;
                        if(hero.mask.getID()==4) //Steel
                            dmg = dmg/2;
                        if(hero.eqpAmr.getID()==142) //Mercenary's Shield
                            dmg -= dmg/4;
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
                        if(monster.getID()!=57)
                            dmg = monster.getSTR() - hero.getDEF() - defBuff;
                        else //Ozkoroth
                        {
                            red = .7;
                            dmg = monster.getSTR() - ceil(red*(static_cast<float>(hero.getDEF()) - defBuff));
                        }
                        if(hero.mask.getID()==0||hero.mask.getID()==5) //Glass, Whisper
                            dmg = dmg*2;
                        if(hero.mask.getID()==4) //Steel
                            dmg = dmg/2;
                        if(hero.eqpAmr.getID()==142) //Mercenary's Shield
                            dmg -= dmg/4;
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
                        if(monster.getID()!=57)
                            dmg = monster.getSTR() - hero.getDEF() - defBuff;
                        else //Ozkoroth
                        {
                            red = .7;
                            dmg = monster.getSTR() - ceil(red*(static_cast<float>(hero.getDEF()) - defBuff));
                        }
                        if(hero.mask.getID()==0||hero.mask.getID()==5) //Glass, Whisper
                            dmg = dmg*2;
                        if(hero.mask.getID()==4) //Steel
                            dmg = dmg/2;
                        if(hero.eqpAmr.getID()==142) //Mercenary's Shield
                            dmg -= dmg/4;
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
        if(monster.getID()<57)
            cout << monName << " attacks!" << endl;
        else
        {
            switch(monster.getID())
            {
                case 57:
                    cout << monName << " swipes at you with its claws!" << endl;
                break;
                case 58:
                    cout << monName << " lashes a long vine at you!" << endl;
                break;
                case 59:
                    cout << monName << " hurls flame at you!" << endl;
                break;
                case 60:
                    if(parry==0)
                        cout << monName << " swings at you with his greatsword!" << endl;
                    else
                        cout << monName << " parries, and strikes while your guard is down!" << endl;
                break;
                case 61:
                    cout << monName << " unleashes a splitting wail!" << endl;
                break;
                case 62:
                    cout << monName << " fires dark energy from her tome!" << endl;
                break;
            }
        }
        Sleep(1000);
        hit = rand() % 100 + 1;

        if(hero.mask.getID()==4) //Steel
            hit = -1000;

        if(hit+hero.getDDG()+ddgBuff<=monster.getACC()||monster.getID()==59) //Emeritus
        {
            cout << monName << " hits!" << endl;
            Sleep(1000);
            if(monster.getID()!=57)
                dmg = monster.getSTR() - hero.getDEF() - defBuff;
            else //Ozkoroth
            {
                red = .7;
                dmg = monster.getSTR() - ceil(red*(static_cast<float>(hero.getDEF()) - defBuff));
            }
            if(hero.mask.getID()==0||hero.mask.getID()==5||parry==1) //Glass, Whispers, Stiran
                dmg = dmg*2;
            if(hero.mask.getID()==4) //Steel
                dmg = dmg/2;
            if(hero.eqpAmr.getID()==142) //Mercenary's Shield
                dmg -= dmg/4;
            if(dmg<0)
                dmg = 0;
            hero.changeHP(-dmg);
            cout << "Dealt " << dmg << " damage!" << endl;
            Sleep(2000);
        }
        else
        {
            cout << monName << " misses!" << endl;
            if(hero.eqpAmr.getID()==142)
                parry = 1;
            Sleep(2000);
        }
        if(monster.getID()==60)
            parry = 0;
        if(monster.getID()==62) //Byralt
        {
            hero.changeHP(-hero.getLEV());
            cout << monName << "'s magic deals " << hero.getLEV() << " necrotic damage to you!" << endl;
            Sleep(2000);
        }
        if(hero.getHP()<=0)
        {
            end = 2;
            break;
        }
        if(monster.getID()==58) //Endrigaia
        {
            monHP += static_cast<float>(monster.getHP())*.15;
            if(monHP>monster.getHP())
                monHP = monster.getHP();
            dmg = static_cast<float>(monster.getHP())*.15;
            cout << monName << " recovers " << dmg << " HP!" << endl;
            Sleep(2000);
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
        if(monster.getID()>=57)
        {
            switch(monster.getID())
            {
                case 57:
                    if(hero.equipment.size()<6)
                    {
                        hero.equipment.push_back(dir.weaponDirectory[57].getID());
                        cout << "You got Ozkoroth's Fang!" << endl;
                        Sleep(2000);
                    }
                    else
                    {
                        full = 1;
                    }
                break;
                case 58:
                    hero.growth = 1;
                    cout << "You gained Endrigaia's power! Your MPG rose by 2!";
                    Sleep(2000);
                break;
                case 59:
                    if(hero.equipment.size()<6)
                    {
                        hero.equipment.push_back(dir.weaponDirectory[58].getID());
                        cout << "You got the Essence Siphon!" << endl;
                        Sleep(2000);
                    }
                    else
                    {
                        full = 1;
                    }
                break;
                case 60:
                    if(hero.equipment.size()<6)
                    {
                        hero.equipment.push_back(dir.armorDirectory[42].getID());
                        cout << "You got the " << dir.getItemName(142) << "!" << endl;
                        Sleep(2000);
                    }
                    else
                    {
                        full = 1;
                    }
                break;
                case 61:
                    hero.Boost();
                    cout << "You feel a surge of power... you gain +2 to all your stats!" << endl;
                    Sleep(2000);
                break;
                case 62:
                    hero.spellbook.push_back(dir.buffSpellDirectory[22].getID());
                    cout << "You learned Enveloping Shadow!" << endl;
                    Sleep(2000);
                break;
            }
        }
        std::system("cls");
        if(full==1)
            return 4;
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
