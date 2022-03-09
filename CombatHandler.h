int combatHandler(Player &hero, Creature &monster, Directory dir, int gd, int ex, bool debug)
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
    int lckBuff=0;
    int hpBuff=0;
    float amp;
    float red;
    int monHP = monster.getHP();
    int furyDmg=0;
    int poisonDmg=0;
    bool miracleFlag=0;
    int manacost;
    bool healFlag=0;
    bool halliotHeal=0;
    bool blitz=0;
    vector<Buff> buffCounter;

    if(hero.mask.getID()==2) //Darkness
        monName = "Silhouette";

    amp = static_cast<float>(hero.getMA())/100;
    //cout << "AMP: " << hero.getMA() << " / 100 = " << amp << endl;
    //Sleep(3000);

    while(end==0)
    {
        if(godMode)
        {
            atkBuff = 100;
            defBuff = 100;
        }
        if(hero.getHP()>hero.getMHP())
            hero.setHP(hero.getMHP());
        if(hero.getMP()>hero.getMMP())
            hero.setMP(hero.getMMP());
        combatMain(hero,monster,monHP);

        for(int i=0;i<buffCounter.size();i++)
            if(buffCounter[i].getCount()>1)
            {
                if(buffCounter[i].getCount()<10)
                    cout << buffCounter[i].getName() << " lasts for " << buffCounter[i].getCount()-1 << " more turns." << endl;
                else
                    cout << buffCounter[i].getName() << " is active." << endl;
            }

        cout << endl << "Your Turn!" << endl << ": ";
        action = getch();
        if(action=="j"||hero.mask.getID()==6)
        {
            blitz = 0;
            do
            {
                if(hero.mask.getID()==6)
                    cout << "You lunge at the " << monName << " ferociously!" << endl;
                else if(parry==0)
                    cout << "You attack the " << monName << "!" << endl;
                else
                    cout << "You strike at the " << monName << "'s weak point!" << endl;
                Sleep(1000);
                hit = ((rand() % 100) + (rand() % 100) + 2) / 2;
                //cout << hit+monster.getDDG() << ", " << hero.getACC()+accBuff << endl;
                if(hero.eqpRng.getID()==405||hero.eqpRng.getID()==415||hero.eqpRng.getID()==427) //SIGHT
                {
                    if((rand()%100+1)<=hero.eqpRng.activate(hero.getLCK())+lckBuff)
                    {
                        cout << hero.eqpRng.getName() << " activated!" << endl;
                        hit = -100;
                        Sleep(1000);
                    }
                }
                if(hit+monster.getDDG()<=hero.getACC()+accBuff)
                {
                    if(hero.eqpRng.getID()==409||hero.eqpRng.getID()==419||hero.eqpRng.getID()==431) //FURY
                    {
                        cout << hero.eqpRng.getName() << " activated!" << endl;
                        switch(hero.eqpRng.getID())
                        {
                            case 431:
                                furyDmg += 3;
                                break;
                            case 419:
                                furyDmg += 2;
                                break;
                            case 409:
                                furyDmg += 1;
                                break;
                        }
                        Sleep(1000);
                    }
                    crit = ((rand() % 100) + (rand() % 100) + 2) / 2;
                    if(crit<=hero.getCRT()+crtBuff)
                    {
                        cout << "Critical Hit!" << endl;
                        Sleep(1000);
                        dmg = (hero.getSTR()+atkBuff - monster.getDEF())*2;
                        if(hero.eqpRng.getID()==406||hero.eqpRng.getID()==416||hero.eqpRng.getID()==428) //PIERCING
                        {
                            if((rand()%100+1)<=hero.eqpRng.activate(hero.getLCK())+lckBuff)
                            {
                                cout << hero.eqpRng.getName() << " activated!" << endl;
                                dmg = (hero.getSTR()+atkBuff - (static_cast<float>(monster.getDEF())*.5))*2;
                                Sleep(1000);
                            }
                        }
                        if(hero.eqpWpn.getID()==57) //Ozkoroth's Fang
                            dmg = (ceil(static_cast<float>(monster.getHP())*.35))*2;
                        if(hero.eqpWpn.getID()==58) //Energy Siphon
                        {
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
                        if(hero.eqpRng.getID()==404||hero.eqpRng.getID()==414||hero.eqpRng.getID()==426) //VENGEANCE
                        {
                            switch(hero.eqpRng.getID())
                            {
                                case 404:
                                    dmg += static_cast<float>(hero.getMHP()-hero.getHP())*.15;
                                    break;
                                case 414:
                                    dmg += static_cast<float>(hero.getMHP()-hero.getHP())*.3;
                                    break;
                                case 426:
                                    dmg += static_cast<float>(hero.getMHP()-hero.getHP())*.5;
                                    break;
                            }
                        }
                        dmg += furyDmg;
                        if(poisonDmg>0)
                        {
                            dmg += poisonDmg;
                            poisonDmg += 5;
                        }
                        if(dmg<0)
                            dmg = 0;
                        monHP -= dmg;
                        cout << "Dealt " << dmg << " damage to " << monName << "!" << endl;
                        if(hero.mask.getID()==6) //Beasts
                        {
                            hero.changeHP(dmg/4);
                            cout << "Restored " << static_cast<int>(dmg/4) << " HP!" << endl;
                            Sleep(1000);
                        }
                        Sleep(2000);
                    }
                    else
                    {
                        cout << "Hit!" << endl;
                        Sleep(1000);
                        dmg = hero.getSTR()+atkBuff - monster.getDEF();
                        if(hero.eqpRng.getID()==406||hero.eqpRng.getID()==416||hero.eqpRng.getID()==428) //PIERCING
                        {
                            if((rand()%100+1)<=hero.eqpRng.activate(hero.getLCK())+lckBuff)
                            {
                                cout << hero.eqpRng.getName() << " activated!" << endl;
                                dmg = hero.getSTR()+atkBuff - (static_cast<float>(monster.getDEF())*.5);
                                Sleep(1000);
                            }
                        }
                        if(hero.eqpWpn.getID()==57) //Ozkoroth's Fang
                            dmg = ceil(static_cast<float>(monster.getHP())*.35);
                        if(hero.eqpWpn.getID()==58) //Energy Siphon
                        {
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
                        if(hero.eqpRng.getID()==404||hero.eqpRng.getID()==414||hero.eqpRng.getID()==426) //VENGEANCE
                        {
                            switch(hero.eqpRng.getID())
                            {
                                case 404:
                                    dmg += static_cast<float>(hero.getMHP()-hero.getHP())*.15;
                                    break;
                                case 414:
                                    dmg += static_cast<float>(hero.getMHP()-hero.getHP())*.3;
                                    break;
                                case 426:
                                    dmg += static_cast<float>(hero.getMHP()-hero.getHP())*.5;
                                    break;
                            }
                        }
                        dmg += furyDmg;
                        if(poisonDmg>0)
                        {
                            dmg += poisonDmg;
                            poisonDmg += 5;
                        }
                        if(dmg<0)
                            dmg = 0;
                        monHP -= dmg;
                        cout << "Dealt " << dmg << " damage to " << monName << "!" << endl;
                        if(hero.mask.getID()==6) //Beasts
                        {
                            hero.changeHP(dmg/4);
                            cout << "Restored " << static_cast<int>(dmg/4) << " HP!" << endl;
                            Sleep(1000);
                        }
                        Sleep(2000);
                    }
                    if(dmg>=50)
                        ach.Powerhouse = 1;
                    if(dmg>=100)
                        ach.Overkill = 1;
                    if(dmg>=100&&monster.getName()=="Valentereth, the Tyrant")
                        ach.TrueHeir = 1;
                    if(hero.eqpRng.getID()==403||hero.eqpRng.getID()==413||hero.eqpRng.getID()==425) //LEECHING
                    {
                        if((rand()%100+1)<=hero.eqpRng.activate(hero.getLCK())+lckBuff)
                        {
                            cout << hero.eqpRng.getName() << " activated!" << endl;
                            Sleep(1000);
                            hero.changeHP(dmg/2);
                            cout << "Recovered " << hero.level << " HP!" << endl;
                            Sleep(1000);
                        }
                    }
                }
                else
                {
                    cout << "You missed..." << endl;
                    if(hero.eqpRng.getID()==409||hero.eqpRng.getID()==419||hero.eqpRng.getID()==431) //FURY
                    {
                        cout << hero.eqpRng.getName() << " streak broken!" << endl;
                        furyDmg = 0;
                    }
                    if(monster.getID()==60)
                        parry = 1;
                    Sleep(2000);
                }
                if(hero.eqpAmr.getID()==142)
                    parry = 0;
                if((hero.eqpRng.getID()==421||hero.eqpRng.getID()==433)&&!blitz) //BLITZING
                {
                    if((rand()%100+1)<=hero.eqpRng.activate(hero.getLCK())+lckBuff)
                    {
                        cout << hero.eqpRng.getName() << " activated!" << endl;
                        blitz = 1;
                        Sleep(2000);
                    }
                }
                else
                    blitz = 0;
            } while(blitz);
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
                if(hero.eqpRng.getID()==401||hero.eqpRng.getID()==411||hero.eqpRng.getID()==423) //CONSERVATION
                {
                    if((rand()%100+1)<=hero.eqpRng.activate(hero.getLCK())+lckBuff)
                    {
                        cout << hero.eqpRng.getName() << " activated!" << endl;
                        hero.changeMP(manacost);
                        Sleep(1000);
                    }
                }
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
                    cout << hero.getName() << " cast " << dir.getItemName(hero.spellbook[choice-1]) << "!" << endl;
                    if(hero.eqpRng.getID()==407||hero.eqpRng.getID()==417||hero.eqpRng.getID()==429) //OVERCHARGING
                    {
                        if((rand()%100+1)<=hero.eqpRng.activate(hero.getLCK())+lckBuff)
                        {
                            cout << hero.eqpRng.getName() << " activated!" << endl;
                            dmg += static_cast<float>(dmg)*.5;
                            Sleep(1000);
                        }
                    }
                    monHP -= dmg;
                    cout << "Dealt " << dmg << " damage to " << monName << "!" << endl;
                    if(hero.eqpRng.getID()==403||hero.eqpRng.getID()==413||hero.eqpRng.getID()==425) //LEECHING
                    {
                        if((rand()%100+1)<=hero.eqpRng.activate(hero.getLCK())+lckBuff)
                        {
                            cout << hero.eqpRng.getName() << " activated!" << endl;
                            Sleep(1000);
                            hero.changeHP(dmg/2);
                            cout << "Recovered " << dmg/2 << " HP!" << endl;
                            Sleep(1000);
                        }
                    }
                    if(dmg>=50)
                        ach.Nuke = 1;
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
                    if(dir.consumableDirectory[hero.inventory[choice-1]-200].getHP()>0)
                        cout << "HP: " << dir.consumableDirectory[hero.inventory[choice-1]-200].getHP() << endl;
                    if(dir.consumableDirectory[hero.inventory[choice-1]-200].getMP()>0)
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

                //Special Consumable Code Here!
                if(hero.inventory[choice-1]>=213)
                {
                    Buff ItemBuff;
                    switch(hero.inventory[choice-1])
                    {
                        case 213: //Fire Bomb
                            cout << "Dealt 10 damage to " << monName << "!" << endl;
                            monHP -= 10;
                            break;
                        case 214: //Smoke Capsule
                            cout << "DDG rose by 25!" << endl;
                            ItemBuff.setName("Smoke Capsule");
                            buffCounter.push_back(ItemBuff);
                            break;
                        case 215: //Gaia Herbs
                            cout << "HP Regeneration rose by 5!" << endl;
                            ItemBuff.setName("Gaia Herbs");
                            buffCounter.push_back(ItemBuff);
                            break;
                        case 216: //Blast Bomb
                            cout << "Dealt 30 damage to " << monName << "!" << endl;
                            monHP -= 30;
                            break;
                        case 217: //Aether Vial
                            cout << "MP Regeneration rose by 3!" << endl;
                            ItemBuff.setName("Aether Vial");
                            buffCounter.push_back(ItemBuff);
                            break;
                        case 218: //Pyllich Venom
                            cout << "Your weapon was coated in poison!" << endl;
                            poisonDmg += 5;
                            break;
                        case 219: //Nova Bomb
                            cout << "Dealt 50 damage to " << monName << "!" << endl;
                            monHP -= 50;
                            break;
                        case 220: //Gaia Flower
                            cout << "HP Regeneration rose by 10!" << endl;
                            ItemBuff.setName("Gaia Flower");
                            buffCounter.push_back(ItemBuff);
                            break;
                        case 221: //Fortune Tincture
                            cout << "LCK rose by 30!" << endl;
                            ItemBuff.setName("Fortune Tincture");
                            buffCounter.push_back(ItemBuff);
                            break;
                        case 222: //Rendai's Veil
                            cout << "You are surrounded in a golden veil of light!" << endl;
                            ItemBuff.setName("Rendai's Veil");
                            ItemBuff.setCount(3);
                            buffCounter.push_back(ItemBuff);
                            break;
                        case 223: //Faerie Dust
                            cout << "CRT, DDG, and ACC rose by 30!" << endl;
                            ItemBuff.setName("Faerie Dust");
                            buffCounter.push_back(ItemBuff);
                            break;
                        case 224: //Second Soul
                            break;
                    }
                    Sleep(1000);
                }

                hero.inventory.erase(hero.inventory.begin()+choice-1);
                if(dir.consumableDirectory[hero.inventory[choice-1]-200].getName()=="Bread")
                    ach.Connoisseur++;
                if(dir.consumableDirectory[hero.inventory[choice-1]-200].getID()>=204&&dir.consumableDirectory[hero.inventory[choice-1]-200].getID()<=211)
                    ach.Alchemist++;
            }
        }
        else if(action==";")
        {
           hit = ((rand() % 100) + (rand() % 100) + 2) / 2;
           if(hero.getDDG()>=monster.getLEV()*3)
           {
               if(hit>25) //pass
               {
                   cout << "You escape successfully!" << endl;
                   Sleep(2000);
                   end = 3;
                   break;
               }
               else if(hit>10) //pass, but damage
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
                   if(hero.getHP()<=0)
                   {
                       if(hero.eqpRng.getID()==434&&!miracleFlag) //MIRACLE
                       {
                           cout << hero.eqpRng.getName() << " activated!" << endl;
                           hero.setHP(1);
                           miracleFlag = 1;
                           Sleep(2000);
                       }
                       else if(std::count(hero.inventory.begin(),hero.inventory.end(),224))
                       {
                           for(int i=0;i<hero.inventory.size();i++)
                           {
                               if(hero.inventory[i]==224)
                               {
                                   hero.inventory.erase(hero.inventory.begin()+i);
                                   break;
                               }
                           }
                           hero.setHP(hero.getMHP());
                           hero.setMP(hero.getMMP());
                           cout << "The Second Soul breaks free of the glass sphere!" << endl;
                           Sleep(1000);
                           cout << "HP and MP maxed out!" << endl;
                           Sleep(2000);
                       }
                       else
                       {
                           end = 2;
                           break;
                       }
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
                   if(hero.mask.getID()==0) //Glass
                       dmg = dmg*2;
                   if(hero.mask.getID()==5) //Whispers
                       dmg = static_cast<float>(dmg)*1.5;
                   if(hero.mask.getID()==4) //Steel
                       dmg = static_cast<float>(dmg)*.7;
                   if(hero.eqpAmr.getID()==142) //Mercenary's Shield
                       dmg -= dmg/4;
                   if(dmg<0)
                       dmg = 0;
                   hero.changeHP(-dmg);
                   cout << "Dealt " << dmg << " damage!" << endl;
                   Sleep(2000);
                   if(hero.getHP()<=0)
                   {
                       if(hero.eqpRng.getID()==434&&!miracleFlag) //MIRACLE
                       {
                           cout << hero.eqpRng.getName() << " activated!" << endl;
                           hero.setHP(1);
                           miracleFlag = 1;
                           Sleep(2000);
                       }
                       else if(std::count(hero.inventory.begin(),hero.inventory.end(),224))
                       {
                           for(int i=0;i<hero.inventory.size();i++)
                           {
                               if(hero.inventory[i]==224)
                               {
                                   hero.inventory.erase(hero.inventory.begin()+i);
                                   break;
                               }
                           }
                           hero.setHP(hero.getMHP());
                           hero.setMP(hero.getMMP());
                           cout << "The Second Soul breaks free of the glass sphere!" << endl;
                           Sleep(1000);
                           cout << "HP and MP maxed out!" << endl;
                           Sleep(2000);
                       }
                       else
                       {
                           end = 2;
                           break;
                       }
                   }
               }
           }
           else
           {
               if(hit>40) //pass
               {
                   cout << "You escape successfully!" << endl;
                   Sleep(2000);
                   end = 3;
                   break;
               }
               else if(hit>20) //pass, but damage
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
                   if(hero.mask.getID()==0) //Glass
                       dmg = dmg*2;
                   if(hero.mask.getID()==5) //Whispers
                       dmg = static_cast<float>(dmg)*1.5;
                   if(hero.mask.getID()==4) //Steel
                       dmg = static_cast<float>(dmg)*.7;
                   if(hero.eqpAmr.getID()==142) //Mercenary's Shield
                       dmg -= dmg/4;
                   if(dmg<0)
                       dmg = 0;
                   hero.changeHP(-dmg);
                   cout << "Dealt " << dmg << " damage!" << endl;
                   Sleep(2000);
                   if(hero.getHP()<=0)
                   {
                       if(hero.eqpRng.getID()==434&&!miracleFlag) //MIRACLE
                       {
                           cout << hero.eqpRng.getName() << " activated!" << endl;
                           hero.setHP(1);
                           miracleFlag = 1;
                           Sleep(2000);
                       }
                       else if(std::count(hero.inventory.begin(),hero.inventory.end(),224))
                       {
                           for(int i=0;i<hero.inventory.size();i++)
                           {
                               if(hero.inventory[i]==224)
                               {
                                   hero.inventory.erase(hero.inventory.begin()+i);
                                   break;
                               }
                           }
                           hero.setHP(hero.getMHP());
                           hero.setMP(hero.getMMP());
                           cout << "The Second Soul breaks free of the glass sphere!" << endl;
                           Sleep(1000);
                           cout << "HP and MP maxed out!" << endl;
                           Sleep(2000);
                       }
                       else
                       {
                           end = 2;
                           break;
                       }
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
                   if(hero.mask.getID()==0) //Glass
                       dmg = dmg*2;
                   if(hero.mask.getID()==5) //Whispers
                       dmg = static_cast<float>(dmg)*1.5;
                   if(hero.mask.getID()==4) //Steel
                       dmg = static_cast<float>(dmg)*.7;
                   if(hero.eqpAmr.getID()==142) //Mercenary's Shield
                       dmg -= dmg/4;
                   if(dmg<0)
                       dmg = 0;
                   hero.changeHP(-dmg);
                   cout << "Dealt " << dmg << " damage!" << endl;
                   Sleep(2000);
                   if(hero.getHP()<=0)
                   {
                       if(hero.eqpRng.getID()==434&&!miracleFlag) //MIRACLE
                       {
                           cout << hero.eqpRng.getName() << " activated!" << endl;
                           hero.setHP(1);
                           miracleFlag = 1;
                           Sleep(2000);
                       }
                       else if(std::count(hero.inventory.begin(),hero.inventory.end(),224))
                       {
                           for(int i=0;i<hero.inventory.size();i++)
                           {
                               if(hero.inventory[i]==224)
                               {
                                   hero.inventory.erase(hero.inventory.begin()+i);
                                   break;
                               }
                           }
                           hero.setHP(hero.getMHP());
                           hero.setMP(hero.getMMP());
                           cout << "The Second Soul breaks free of the glass sphere!" << endl;
                           Sleep(1000);
                           cout << "HP and MP maxed out!" << endl;
                           Sleep(2000);
                       }
                       else
                       {
                           end = 2;
                           break;
                       }
                   }
               }
           }
        }
        else if(action=="w"&&debug)
        {
            cout << "Waiting..." << endl;
            Sleep(1000);
        }
        else
        {
            cout << "Unknown action." << endl;
            Sleep(1000);
            continue;
        }
        if(monHP<=0)
        {
            if(monster.getID()==63&&!halliotHeal) //Halliot
            {
                cout << monName << " endures the blow, and shimmers with arcane light!" << endl;
                Sleep(2000);
                halliotHeal = 1;
                cout << monName << " is embraced in golden light, and emerges with her eyes glowing golden, and wings of mystical light at her back!" << endl;
                monster.setSTR(static_cast<int>(monster.getSTR()*1.2));
                monster.setDEF(static_cast<int>(monster.getDEF()*1.2));
                monster.setHP(static_cast<int>(monster.getHP()*1.3));
                monHP = monster.getHP();
                Sleep(3000);
            }
            else
            {
                end = 1;
                break;
            }
        }
        if(hero.getHP()<=0)
        {
            if(hero.eqpRng.getID()==434&&!miracleFlag) //MIRACLE
            {
                cout << hero.eqpRng.getName() << " activated!" << endl;
                hero.setHP(1);
                miracleFlag = 1;
                Sleep(2000);
            }
            else
            {
                end = 2;
                break;
            }
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
        lckBuff = 0;
        hpBuff = 0;
        dmg = 0;
        for(int i=0;i<buffCounter.size();i++)
        {
            if(buffCounter[i].getName()=="Enveloping Shadow")
                dmg += 5;
            else if(buffCounter[i].getName()=="Smoke Capsule")
                ddgBuff += 25;
            else if(buffCounter[i].getName()=="Gaia Herbs")
                hpBuff += 5;
            else if(buffCounter[i].getName()=="Aether Vial")
            {
                hero.changeMP(3);
                if(hero.getMP()>hero.getMMP())
                    hero.setMP(hero.getMMP());
            }
            else if(buffCounter[i].getName()=="Gaia Flower")
                hpBuff += 10;
            else if(buffCounter[i].getName()=="Fortune Tincture")
                lckBuff += 30;
            else if(buffCounter[i].getName()=="Rendai's Veil")
                defBuff += 500;
            else if(buffCounter[i].getName()=="Faerie Dust")
            {
                accBuff += 30;
                ddgBuff += 30;
                crtBuff += 30;
            }
            atkBuff += buffCounter[i].getATKU();
            defBuff += buffCounter[i].getDEFU();
            accBuff += buffCounter[i].getACCU();
            ddgBuff += buffCounter[i].getDDGU();
            crtBuff += buffCounter[i].getCRTU();
            hpBuff += buffCounter[i].getHPU();
        }
        if(dmg>0)
        {
            monHP -= dmg;
            cout << hero.getName() << " dealt " << dmg << " necrotic damage to " << monName << "!" << endl;
            if(dmg>=20)
                ach.Necromancy = 1;
            Sleep(1000);
        }
        if(monHP<=0)
        {
            if(monster.getID()==63&&!halliotHeal) //Halliot
            {
                cout << monName << " endures the blow, and shimmers with arcane light!" << endl;
                Sleep(2000);
                halliotHeal = 1;
                cout << monName << " is embraced in golden light, and emerges with her eyes glowing golden, and wings of mystical light at her back!" << endl;
                monster.setSTR(static_cast<int>(monster.getSTR()*1.2));
                monster.setDEF(static_cast<int>(monster.getDEF()*1.2));
                monster.setHP(static_cast<int>(monster.getHP()*1.3));
                monHP = monster.getHP();
                Sleep(3000);
            }
            else
            {
                end = 1;
                break;
            }
        }
        /*cout << "Attack Buff: " << atkBuff << endl;
        cout << "Defense Buff: " << defBuff << endl;
        cout << "Accuracy Buff: " << accBuff << endl;
        cout << "Dodge Buff: " << ddgBuff << endl;
        cout << "Crit Buff: " << crtBuff << endl;
        cout << "HP Buff: " << hpBuff << endl;*/
        hero.changeHP(hpBuff);
        hero.changeMP(hero.getMG());

        //--------------------------ENEMY TURN-------------------------
        //Sleep(1000);
        cout << monName << "'s Turn!" << endl;
        Sleep(1000);
        if(monster.getID()<57)
            cout << monName << " attacks!" << endl;
        else
        {
            switch(monster.getID())
            {
                case 48:
                    cout << monName << " swings her axe at you!" << endl;
                break;
                case 56:
                    if(rand()%2==0)
                        cout << monName << " smashes his warhammer down upon you!" << endl;
                    else
                        cout << monName << " calls down lightning to strike you!" << endl;
                break;
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
                case 63:
                    if(!halliotHeal)
                        cout << monName << " thrusts her spear at you!" << endl;
                    else
                        cout << monName << " lets out a battle cry and soars toward you, her spear shining with light!" << endl;
                break;
            }
        }
        Sleep(1000);
        hit = (rand() % 100) + 1;

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
            if(hero.mask.getID()==0||parry) //Glass
                dmg = dmg*2;
            if(hero.mask.getID()==5) //Whispers
                dmg = static_cast<float>(dmg)*1.5;
            if(hero.mask.getID()==4) //Steel
                dmg = static_cast<float>(dmg)*.7;
            if(hero.eqpAmr.getID()==142) //Mercenary's Shield
                dmg -= dmg/4;
            if(dmg<0)
                dmg = 0;
            if(hero.eqpRng.getID()==402||hero.eqpRng.getID()==412||hero.eqpRng.getID()==424) //BRAVERY
            {
                if((rand()%100+1)<=hero.eqpRng.activate(hero.getLCK())+lckBuff)
                {
                    cout << hero.eqpRng.getName() << " activated!" << endl;
                    dmg = 0;
                    Sleep(1000);
                }
            }
            hero.changeHP(-dmg);
            cout << "Dealt " << dmg << " damage!" << endl;
            if(hero.eqpRng.getID()==408||hero.eqpRng.getID()==418||hero.eqpRng.getID()==430) //REFLECTION
            {
                if((rand()%100+1)<=hero.eqpRng.activate(hero.getLCK())+lckBuff)
                {
                    Sleep(1000);
                    cout << hero.eqpRng.getName() << " activated!" << endl;
                    Sleep(1000);
                    cout << "Reflected " << dmg << " back to " << monName << "!" << endl;
                    monHP -= dmg;
                }
            }
            Sleep(2000);
        }
        else
        {
            cout << monName << " misses!" << endl;
            if(hero.eqpAmr.getID()==142)
                parry = 1;
            Sleep(2000);
        }
        if(monHP<=0)
        {
            if(monster.getID()==63&&!halliotHeal) //Halliot
            {
                cout << monName << " endures the blow, and shimmers with arcane light!" << endl;
                Sleep(2000);
                halliotHeal = 1;
                cout << monName << " is embraced in golden light, and emerges with her eyes glowing golden, and wings of mystical light at her back!" << endl;
                monster.setSTR(static_cast<int>(monster.getSTR()*1.2));
                monster.setDEF(static_cast<int>(monster.getDEF()*1.2));
                monster.setHP(static_cast<int>(monster.getHP()*1.3));
                monHP = monster.getHP();
                Sleep(3000);
            }
            else
            {
                end = 1;
                break;
            }
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
            if(hero.eqpRng.getID()==434&&!miracleFlag) //MIRACLE
            {
                cout << hero.eqpRng.getName() << " activated!" << endl;
                hero.setHP(1);
                miracleFlag = 1;
                Sleep(2000);
            }
            else if(std::count(hero.inventory.begin(),hero.inventory.end(),224))
            {
                for(int i=0;i<hero.inventory.size();i++)
                {
                    if(hero.inventory[i]==224)
                    {
                        hero.inventory.erase(hero.inventory.begin()+i);
                        break;
                    }
                }
                hero.setHP(hero.getMHP());
                hero.setMP(hero.getMMP());
                cout << "The Second Soul breaks free of the glass sphere!" << endl;
                Sleep(1000);
                cout << "HP and MP maxed out!" << endl;
                Sleep(2000);
            }
            else
            {
                end = 2;
                break;
            }
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
        if(hero.eqpRng.getID()==400||hero.eqpRng.getID()==410||hero.eqpRng.getID()==422) //REGENERATION
        {
            cout << hero.eqpRng.getName() << " activated!" << endl;
            Sleep(1000);
            hero.changeHP(hero.eqpRng.getHPR());
            cout << "Restored " << hero.eqpRng.getHPR() << " HP!" << endl;
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
        score += 10*monster.getLEV();
        score += gd;
        ach.Expert++;
        ach.Unstoppable++;
        Sleep(2000);
        if(monster.getID()>=57)
        {
            score += 100;
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
                    ach.Beast = 1;
                break;
                case 58:
                    hero.growth = 1;
                    cout << "You gained Endrigaia's power! Your MPG rose by 2!";
                    ach.NaturesWrath = 1;
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
                    ach.Archmage = 1;
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
                    ach.Mercenary = 1;
                break;
                case 61:
                    hero.Boost();
                    cout << "You feel a surge of power... you gain +2 to all your stats!" << endl;
                    ach.Horror = 1;
                    Sleep(2000);
                break;
                case 62:
                    hero.spellbook.push_back(dir.buffSpellDirectory[22].getID());
                    cout << "You learned Enveloping Shadow!" << endl;
                    ach.Scion = 1;
                    Sleep(2000);
                break;
                case 63:
                    if(hero.equipment.size()<6)
                    {
                        hero.equipment.push_back(dir.ringDirectory[34].getID());
                        cout << "You got the " << dir.getItemName(434) << "!" << endl;
                        Sleep(2000);
                    }
                    else
                    {
                        full = 1;
                    }
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
        score += 10;
        std::system("cls");
        return 3;
    }
    cout << "Error!" << endl;
    return 0;
}
