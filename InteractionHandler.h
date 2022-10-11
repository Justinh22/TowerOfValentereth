bool nicknameChecker(string name, Creature monster);

string interactionHandler(int action, string target, Player &hero, Directory &dir, Room &currentRoom, int &pass, vector<bool> &itemStatus, bool debug, int &itemIndex)
{
    //cout << endl << "Entered Interaction Handler!!" << endl;
    string holder = "";
    string returner;
    string lowername;
    string name;
    bool next;
    int valid = 0;
    if(action==0) //GO
    {
        //cout << "Command was 'GO'" << endl;
        if(target=="door"||target=="doors"||target=="tunnel"||target=="doorway"||target=="ladder"||target=="passage"||target=="passageway"||target=="chamber")
        {
            if(pass==1)
                return "next";
            else
                return "escape";
        }
        if(target=="store"||target=="locked door"||target=="merchant"||target=="shop"||target=="room")
        {
            return "store";
        }
        else
        {
            return "You cannot go there.";
        }
    }
    else if(action==1) //LOOK
    {
        //cout << "Command was 'LOOK'" << endl;

        if(hero.mask.getID()==2) //Darkness
            lowername = "Silhouette";
        else
            lowername = currentRoom.monster.getName();

        if(nicknameChecker(target,currentRoom.monster))
            next = 1;
        else
            next = 0;

        std::transform(lowername.begin(), lowername.end(), lowername.begin(), ::tolower);
        if(target=="door"||target=="doors"||target=="tunnel"||target=="doorway"||target=="ladder"||target=="passage"||target=="passageway")
        {
            //cout << "Target was door." << endl;
            return currentRoom.doorDesc;
        }
        if(target=="store"||target=="locked door"||target=="merchant"||target=="shop")
        {
            return "store";
        }
        if(target=="dstore"&&debug)
        {
            hero.keys++;
            return "store";
        }
        if(target=="room")
        {
            return "room";
        }
        else if(target=="crates"||target=="crate"||target=="boxes"||target=="box"||target=="barrels"||target=="barrel"||target=="chest"||target=="treasure chest")
        {
            if(target=="crates"||target=="crate"||target=="boxes"||target=="box")
            {
                target = "crates";
            }
            else if(target=="barrels"||target=="barrel")
            {
                target = "barrels";
            }
            else if(target=="chest"||target=="treasure chest")
            {
                target = "chest";
            }
            //cout << "Target was a container: " << target << "!" << endl;
            //for(int i=0;i<currentRoom.getBList().size();i++)
            //{
            holder = "";
            if((currentRoom.getBList())[0]==target)
            {
                //cout << "Match!" << endl;
                for(int i=0;i<currentRoom.contents;i++)
                {
                    if(itemStatus[i]==0)
                    {
                        if(currentRoom.getIList()[i]<300||currentRoom.getIList()[i]>=400)
                            holder += "You see a " + dir.getItemName(currentRoom.getIList()[i]) + ".";
                        else
                            holder += "You see a Scroll of " + dir.getItemName(currentRoom.getIList()[i]) + ".";
                        valid = 1;
                        if(i<currentRoom.contents-1)
                            holder += "\n";
                    }
                }
                if(valid==0)
                    holder = "Empty.";
                return holder;
            }
            //}
            return "Unknown target.";
        }
        else if(target==lowername||target=="enemy"||target=="monster"||next==1)
        {
            if(currentRoom.monster.level==-1||pass==1)
                return "No enemy present.";
            if(hero.mask.getID()==2) //Darkness
            {
                holder = "Silhouette | Level " + std::to_string(currentRoom.monster.getLEV()-2) + "\n";
                holder += "HP: ??\n";
                holder += "Strength: ??\n";
                holder += "Accuracy: ??\n";
                holder += "Defense: ??\n";
                holder += "Dodge: ??";
                if(currentRoom.monster.getID()>=57) //Miniboss
                    holder += "\nAbility: ??";
            }
            else
            {
                if(currentRoom.monster.getID()<57) //Miniboss
                    holder = currentRoom.monster.getName() + " | Level " + std::to_string(currentRoom.monster.getLEV()-2);
                    if(currentRoom.monster.getLEV()<hero.level)
                        holder += " <-->\n";
                    else if(currentRoom.monster.getLEV()-2<hero.level)
                        holder += " <->\n";
                    else if(currentRoom.monster.getLEV()-2==hero.level)
                        holder += "\n";
                    else if(currentRoom.monster.getLEV()-4<=hero.level)
                        holder += " <+>\n";
                    else if(currentRoom.monster.getLEV()-4>hero.level)
                        holder += " <++>\n";
                else
                    holder = currentRoom.monster.getName() + " | Level " + std::to_string(hero.getLEV()+3) + " <++>\n";

                int monDmg = currentRoom.monster.getSTR() - hero.getDEF();
                int monHit = currentRoom.monster.getACC() - hero.getDDG();
                int heroDmg = hero.getSTR() - currentRoom.monster.getDEF();
                int heroHit = hero.getACC() - currentRoom.monster.getDDG();

                if(hero.eqpWpn.getID()==57)
                    heroDmg = ceil(static_cast<float>(currentRoom.monster.getHP())*.35);
                if(hero.eqpAmr.getID()==142)
                    monDmg -= monDmg/4;

                if(currentRoom.monster.getID()==57)
                    monDmg = currentRoom.monster.getSTR() - ceil(.7*(static_cast<float>(hero.getDEF())));
                if(currentRoom.monster.getID()==61)
                    heroDmg = static_cast<float>(heroDmg)*.7;

                if(hero.mask.getID()==6)
                    heroDmg = heroDmg + (heroDmg/2);
                if(hero.mask.getID()==5) //Whispers
                    monDmg = static_cast<float>(monDmg)*1.5;
                if((hero.meleeTraining==0&&(hero.eqpWpn.getName().find("Dagger")!=string::npos||hero.eqpWpn.getName().find("Knife")!=string::npos||hero.eqpWpn.getName().find("Aerolinde")!=string::npos))||
                   (hero.meleeTraining==1&&(hero.eqpWpn.getName().find("Spear")!=string::npos||hero.eqpWpn.getName().find("Pike")!=string::npos||hero.eqpWpn.getName().find("Hyliat")!=string::npos))||
                   (hero.meleeTraining==2&&(hero.eqpWpn.getName().find("Sword")!=string::npos||hero.eqpWpn.getName().find("Saber")!=string::npos||hero.eqpWpn.getName().find("Pyrithia")!=string::npos))||
                   (hero.meleeTraining==3&&(hero.eqpWpn.getName().find("Axe")!=string::npos||hero.eqpWpn.getName().find("Club")!=string::npos||hero.eqpWpn.getName().find("Teratra")!=string::npos)))
                {
                    heroDmg += 2;
                    heroHit += 5;
                }

                holder += "HP: " + std::to_string(currentRoom.monster.getHP()) + "\n";
                holder += "Strength: " + std::to_string(currentRoom.monster.getSTR()) + " (Enemy DMG: " + std::to_string(monDmg) + ")\n";
                holder += "Accuracy: " + std::to_string(currentRoom.monster.getACC()) + " (Enemy Hit Rate: " + std::to_string(monHit) + ")\n";
                holder += "Defense: " + std::to_string(currentRoom.monster.getDEF()) + " (Your DMG: " + std::to_string(heroDmg) + ")\n";
                holder += "Dodge: " + std::to_string(currentRoom.monster.getDDG()) + " (Your Hit Rate: " + std::to_string(heroHit) + ")\n";
                if(currentRoom.monster.getID()>=57||currentRoom.monster.getID()==48) //Miniboss
                {
                    holder += "\nAblity: ";
                    switch(currentRoom.monster.getID())
                    {
                        case 48:
                            holder += "Tyrant's Veil - Valentereth takes half damage from all attack spells.";
                            break;
                        case 57:
                            holder += "Armor-Piercing Fangs - Ozkoroth's attacks cut through 30% of the player's defense.";
                            break;
                        case 58:
                            holder += "Regrowth - Endrigaia will regenerate 15% of her HP every turn.";
                            break;
                        case 59:
                            holder += "Archmage - Since Emeritus is a spellcaster, he never misses.";
                            break;
                        case 60:
                            holder += "Parry - If the player misses an attack, Stiran will parry on his counterattack, dealing double damage if he hits.";
                            break;
                        case 61:
                            holder += "Absorb - Damage dealt to ????? will be reduced by 30%.";
                            break;
                        case 62:
                            holder += "Dark Magic - The player will lose HP equal to their level every turn in combat.";
                            break;
                        case 63:
                            holder += "Undying - Halliot will take a stronger form after her first death.";
                            break;
                    }
                }
            }
            return holder;
        }
        else
        {
            for(int i=0;i<currentRoom.getFList().size();i++)
            {
                for(int j=0;j<currentRoom.getFList()[i].getKeyList().size();j++)
                {
                    if((currentRoom.getFList())[i].getKeyList()[j]==target)
                    {
                        holder = (currentRoom.getFList())[i].getDesc();
                        name = currentRoom.getFList()[i].getName();
                    }
                }
            }
            for(int j=0;j<currentRoom.getBList().size();j++)
            {
                if(name==currentRoom.getBList()[j])
                {
                    for(int i=0;i<currentRoom.getFList().size();i++)
                    {
                        if(currentRoom.getBList()[j]==currentRoom.getFList()[i].getName())
                            if(currentRoom.getFList()[i].getItem()<=3)
                            {
                                if(itemStatus[j-1+currentRoom.contents]==0)
                                {
                                    if(holder!="")
                                        holder += "\n";
                                    if(currentRoom.getIList()[j-1+currentRoom.contents]<300||currentRoom.getIList()[j-1+currentRoom.contents]>=400)
                                        holder += "You find a " + dir.getItemName(currentRoom.getIList()[j-1+currentRoom.contents]) + ".";
                                    else
                                        holder += "You find a Scroll of " + dir.getItemName(currentRoom.getIList()[j-1+currentRoom.contents]) + ".";
                                }
                            }
                            else if(currentRoom.getFList()[i].getItem()==4)
                            {
                                if(itemStatus[j-1+currentRoom.contents]==0)
                                {
                                    if(holder=="")
                                        holder = "Your mind spirals... You begin to recall " + dir.getItemName(currentRoom.getIList()[j-1+currentRoom.contents]) + ".";
                                    else
                                        holder += "\nYour mind spirals... You begin to recall " + dir.getItemName(currentRoom.getIList()[j-1+currentRoom.contents]) + ".";
                                }
                            }
                    }
                }
            }
            if(holder!="")
                return holder;
            for(int i=0;i<currentRoom.getIList().size();i++)
            {
                valid = 0;
                if(itemStatus[i]==1)
                    continue;
                holder = dir.getItemName((currentRoom.getIList())[i]);
                std::transform(holder.begin(), holder.end(), holder.begin(), ::tolower);
                //cout << holder << ", " << target << endl;
                //cout << "The substring reads " << target.substr(0,9) << endl;
                if(target.substr(0,10)=="scroll of ")
                {
                    //cout << "Valid!" << endl;
                    target.erase(0,10);
                }
                if(holder==target)
                    valid = 1;
                else if(target=="axe"&&((currentRoom.getIList()[i]%6==3&&currentRoom.getIList()[i]!=3)||currentRoom.getIList()[i]==4||currentRoom.getIList()[i]==44)&&currentRoom.getIList()[i]<=56)
                    valid = 1;
                else if((target=="sword"||target=="saber"||target=="cleaver")&&((currentRoom.getIList()[i]%6==4&&currentRoom.getIList()[i]!=4)||currentRoom.getIList()[i]==0||currentRoom.getIList()[i]==1||currentRoom.getIList()[i]==5||currentRoom.getIList()[i]==20||currentRoom.getIList()[i]==26)&&currentRoom.getIList()[i]<=56)
                    valid = 1;
                else if((target=="spear"||target=="pike")&&((currentRoom.getIList()[i]%6==5&&currentRoom.getIList()[i]>5)||currentRoom.getIList()[i]==6||currentRoom.getIList()[i]==50)&&currentRoom.getIList()[i]<=56)
                    valid = 1;
                else if((target=="dagger"||target=="knife")&&((currentRoom.getIList()[i]%6==0&&currentRoom.getIList()[i]>6)||currentRoom.getIList()[i]==2||currentRoom.getIList()[i]==7||currentRoom.getIList()[i]==32)&&currentRoom.getIList()[i]<=56)
                    valid = 1;
                else if((target=="staff"||target=="rod"||target=="sceptre"||target=="wand")&&((currentRoom.getIList()[i]%6==1&&currentRoom.getIList()[i]>7)||currentRoom.getIList()[i]==3||currentRoom.getIList()[i]==8)&&currentRoom.getIList()[i]<56)
                    valid = 1;
                else if(target=="club"&&currentRoom.getIList()[i]==14)
                    valid = 1;
                else if(target=="gauntlet"&&currentRoom.getIList()[i]==38)
                    valid = 1;
                else if(target=="armor"&&currentRoom.getIList()[i]>=100&&currentRoom.getIList()[i]<200)
                    valid = 1;
                else if(target=="robe"&&((currentRoom.getIList()[i]%5==0&&currentRoom.getIList()[i]>111)||currentRoom.getIList()[i]==102||currentRoom.getIList()[i]==105||currentRoom.getIList()[i]==108||currentRoom.getIList()[i]==111)&&currentRoom.getIList()[i]<200)
                    valid = 1;
                else if(target=="food"&&currentRoom.getIList()[i]>=200&&currentRoom.getIList()[i]<=203)
                    valid = 1;
                else if(target=="gem"&&currentRoom.getIList()[i]==203)
                    valid = 1;
                else if(target=="berry"&&currentRoom.getIList()[i]==201)
                    valid = 1;
                else if(target=="potion"&&currentRoom.getIList()[i]>=204&&currentRoom.getIList()[i]<=211)
                    valid = 1;
                else if(target=="bomb"&&(currentRoom.getIList()[i]==213||currentRoom.getIList()[i]==216||currentRoom.getIList()[i]==219))
                    valid = 1;
                else if(target=="capsule"&&currentRoom.getIList()[i]==214)
                    valid = 1;
                else if(target=="herbs"&&currentRoom.getIList()[i]==215)
                    valid = 1;
                else if(target=="vial"&&(currentRoom.getIList()[i]==217||currentRoom.getIList()[i]==218||currentRoom.getIList()[i]==221))
                    valid = 1;
                else if((target=="venom"||target=="poison")&&currentRoom.getIList()[i]==218)
                    valid = 1;
                else if(target=="flower"&&currentRoom.getIList()[i]==220)
                    valid = 1;
                else if((target=="tincture"||target=="bottle")&&currentRoom.getIList()[i]==221)
                    valid = 1;
                else if((target=="veil"||target=="statue")&&currentRoom.getIList()[i]==222)
                    valid = 1;
                else if((target=="dust"||target=="powder")&&currentRoom.getIList()[i]==223)
                    valid = 1;
                else if((target=="soul"||target=="sphere")&&currentRoom.getIList()[i]==224)
                    valid = 1;
                else if((target=="spell"||target=="scroll")&&currentRoom.getIList()[i]>=300&&currentRoom.getIList()[i]<=342)
                    valid = 1;
                else if((target=="ring")&&currentRoom.getIList()[i]>=400&&currentRoom.getIList()[i]<500)
                    valid = 1;
                if(valid==1)
                {
                    if(currentRoom.getIList()[i]<100)
                    {
                        cout << dir.getItemName(currentRoom.getIList()[i]) << " | " << dir.getItemDesc(currentRoom.getIList()[i]) << endl;
                        cout << "RARITY: " << dir.weaponDirectory[currentRoom.getIList()[i]].getRarity() << endl;
                        if((hero.meleeTraining==0&&(dir.getItemName(currentRoom.getIList()[i]).find("Dagger")!=string::npos||dir.getItemName(currentRoom.getIList()[i]).find("Knife")!=string::npos||dir.getItemName(currentRoom.getIList()[i]).find("Aerolinde")!=string::npos))||
                           (hero.meleeTraining==1&&(dir.getItemName(currentRoom.getIList()[i]).find("Spear")!=string::npos||dir.getItemName(currentRoom.getIList()[i]).find("Pike")!=string::npos||dir.getItemName(currentRoom.getIList()[i]).find("Hyliat")!=string::npos))||
                           (hero.meleeTraining==2&&(dir.getItemName(currentRoom.getIList()[i]).find("Sword")!=string::npos||dir.getItemName(currentRoom.getIList()[i]).find("Saber")!=string::npos||dir.getItemName(currentRoom.getIList()[i]).find("Pyrithia")!=string::npos))||
                           (hero.meleeTraining==3&&(dir.getItemName(currentRoom.getIList()[i]).find("Axe")!=string::npos||dir.getItemName(currentRoom.getIList()[i]).find("Club")!=string::npos||dir.getItemName(currentRoom.getIList()[i]).find("Teratra")!=string::npos)))
                        {
                            cout << "STR " << dir.weaponDirectory[currentRoom.getIList()[i]].getStr()+2 << endl;
                            cout << "ACC " << dir.weaponDirectory[currentRoom.getIList()[i]].getAcc()+5 << endl;
                            cout << "CRIT " << dir.weaponDirectory[currentRoom.getIList()[i]].getCrt()+5 << endl;
                        }
                        else
                        {
                            cout << "STR " << dir.weaponDirectory[currentRoom.getIList()[i]].getStr() << endl;
                            cout << "ACC " << dir.weaponDirectory[currentRoom.getIList()[i]].getAcc() << endl;
                            cout << "CRIT " << dir.weaponDirectory[currentRoom.getIList()[i]].getCrt() << endl;
                        }
                        if(dir.weaponDirectory[currentRoom.getIList()[i]].getMA()!=0)
                            cout << "MAGIC AMP: +" << dir.weaponDirectory[currentRoom.getIList()[i]].getMA() << "%" << endl;
                    }
                    else if(currentRoom.getIList()[i]<200)
                    {
                        cout << dir.getItemName(currentRoom.getIList()[i]) << " | " << dir.getItemDesc(currentRoom.getIList()[i]) << endl;
                        cout << "RARITY: " << dir.armorDirectory[currentRoom.getIList()[i]-100].getRarity() << endl;
                        cout << "DEF " << dir.armorDirectory[currentRoom.getIList()[i]-100].getDef() << endl;
                        cout << "DDG " << dir.armorDirectory[currentRoom.getIList()[i]-100].getDdg() << endl;
                        if(dir.armorDirectory[currentRoom.getIList()[i]-100].getMG()!=0)
                            cout << "MANA REGEN: " << dir.armorDirectory[currentRoom.getIList()[i]-100].getMG()  << endl;
                    }
                    else if(currentRoom.getIList()[i]<300)
                    {
                        if(currentRoom.getIList()[i]==212)
                        {
                            cout << "A small, silver key." << endl;
                        }
                        else
                        {
                            cout << dir.consumableDirectory[currentRoom.getIList()[i]-200].getName() << " | " << dir.consumableDirectory[currentRoom.getIList()[i]-200].getDesc() << endl;
                            cout << "RARITY: " << dir.consumableDirectory[currentRoom.getIList()[i]-200].getRarity() << endl;
                            if(dir.consumableDirectory[currentRoom.getIList()[i]-200].getHP()>0)
                                cout << "HP " << dir.consumableDirectory[currentRoom.getIList()[i]-200].getHP() << endl;
                            if(dir.consumableDirectory[currentRoom.getIList()[i]-200].getMP()>0)
                                cout << "MP " << dir.consumableDirectory[currentRoom.getIList()[i]-200].getMP() << endl;
                        }
                    }
                    else if(currentRoom.getIList()[i]<400)
                    {
                        cout << dir.getItemName(currentRoom.getIList()[i]) << " | " << dir.getItemDesc(currentRoom.getIList()[i]) << endl;
                        cout << "RARITY: " << dir.getItemRarity(currentRoom.getIList()[i]) << endl;
                        if(currentRoom.getIList()[i]<=314)
                        {
                            if((hero.magicTraining==0&&(currentRoom.getIList()[i]%3==2))||
                               (hero.magicTraining==1&&(currentRoom.getIList()[i]%3==1))||
                               (hero.magicTraining==2&&(currentRoom.getIList()[i]%3==0)))
                            {
                                cout << "MANA COST: " << dir.attackSpellDirectory[currentRoom.getIList()[i]-300].getManaCost()-1 << endl;
                                cout << "DAMAGE: " << dir.attackSpellDirectory[currentRoom.getIList()[i]-300].getDMG()+2 << endl;
                            }
                            else
                            {
                                cout << "MANA COST: " << dir.attackSpellDirectory[currentRoom.getIList()[i]-300].getManaCost() << endl;
                                cout << "DAMAGE: " << dir.attackSpellDirectory[currentRoom.getIList()[i]-300].getDMG() << endl;
                            }
                        }
                        else if(currentRoom.getIList()[i]<=320)
                        {
                            cout << "MANA COST: " << dir.healingSpellDirectory[currentRoom.getIList()[i]-315].getManaCost() << endl;
                            cout << "HEALING: " << dir.healingSpellDirectory[currentRoom.getIList()[i]-315].getHPR() << endl;
                        }
                        else
                        {
                            cout << "MANA COST: " << dir.buffSpellDirectory[currentRoom.getIList()[i]-321].getManaCost() << endl;
                            if(dir.buffSpellDirectory[currentRoom.getIList()[i]-321].getATKU()>0)
                                cout << "ATK BUFF: " << dir.buffSpellDirectory[currentRoom.getIList()[i]-321].getATKU() << endl;
                            if(dir.buffSpellDirectory[currentRoom.getIList()[i]-321].getDEFU()>0)
                                cout << "DEF BUFF: " << dir.buffSpellDirectory[currentRoom.getIList()[i]-321].getDEFU() << endl;
                            if(dir.buffSpellDirectory[currentRoom.getIList()[i]-321].getCRTU()>0)
                                cout << "CRT BUFF: " << dir.buffSpellDirectory[currentRoom.getIList()[i]-321].getCRTU() << endl;
                            if(dir.buffSpellDirectory[currentRoom.getIList()[i]-321].getACCU()>0)
                                cout << "ACC BUFF: " << dir.buffSpellDirectory[currentRoom.getIList()[i]-321].getACCU() << endl;
                            if(dir.buffSpellDirectory[currentRoom.getIList()[i]-321].getDDGU()>0)
                                cout << "DDG BUFF: " << dir.buffSpellDirectory[currentRoom.getIList()[i]-321].getDDGU() << endl;
                        }
                    }
                    else
                    {
                        cout << dir.ringDirectory[currentRoom.getIList()[i]-400].getName() << " | " << dir.ringDirectory[currentRoom.getIList()[i]-400].getDesc() << endl;
                        cout << "RARITY: " << dir.ringDirectory[currentRoom.getIList()[i]-400].getRarity() << endl;
                        if(dir.ringDirectory[currentRoom.getIList()[i]-400].getAct()>0)
                            cout << "ACTIVATION RATE: " << dir.ringDirectory[currentRoom.getIList()[i]-400].getAct() << "%" << endl;
                        if(dir.ringDirectory[currentRoom.getIList()[i]-400].getHPR()>0)
                            cout << "HP REGEN: " << dir.ringDirectory[currentRoom.getIList()[i]-400].getHPR() << endl;
                        if(dir.ringDirectory[currentRoom.getIList()[i]-400].getMPR()>0)
                            cout << "MP REGEN: " << dir.ringDirectory[currentRoom.getIList()[i]-400].getMPR() << endl;
                    }
                    return "check";
                }
            }
            if (currentRoom.getDesc().find(target)!=std::string::npos)
                return "You don't see anything interesting here.";
            else
                return "You don't see anything there.";
        }
    }
    else if(action==2) //TAKE
    {
        //cout << "Command was 'GET'" << endl;
        returner = "";
        //cout << currentRoom.getIList().size();
        for(int i=0;i<currentRoom.getIList().size();i++)
        {
            if(itemStatus[i]==1)
                continue;
            valid = 0;
            holder = dir.getItemName((currentRoom.getIList())[i]);
            std::transform(holder.begin(), holder.end(), holder.begin(), ::tolower);
            //cout << holder << ", " << target << endl;
            //cout << "The substring reads " << target.substr(0,9) << endl;
            if(target.substr(0,10)=="scroll of ")
            {
                //cout << "Valid!" << endl;
                target.erase(0,10);
            }
            if(holder==target)
                valid = 1;
            else if(target=="axe"&&((currentRoom.getIList()[i]%6==3&&currentRoom.getIList()[i]!=3)||currentRoom.getIList()[i]==4||currentRoom.getIList()[i]==44)&&currentRoom.getIList()[i]<=56)
                valid = 1;
            else if((target=="sword"||target=="saber"||target=="cleaver")&&((currentRoom.getIList()[i]%6==4&&currentRoom.getIList()[i]!=4)||currentRoom.getIList()[i]==0||currentRoom.getIList()[i]==1||currentRoom.getIList()[i]==5||currentRoom.getIList()[i]==20||currentRoom.getIList()[i]==26)&&currentRoom.getIList()[i]<=56)
                valid = 1;
            else if((target=="spear"||target=="pike")&&((currentRoom.getIList()[i]%6==5&&currentRoom.getIList()[i]>5)||currentRoom.getIList()[i]==6||currentRoom.getIList()[i]==50)&&currentRoom.getIList()[i]<=56)
                valid = 1;
            else if((target=="dagger"||target=="knife")&&((currentRoom.getIList()[i]%6==0&&currentRoom.getIList()[i]>6)||currentRoom.getIList()[i]==2||currentRoom.getIList()[i]==7||currentRoom.getIList()[i]==32)&&currentRoom.getIList()[i]<=56)
                valid = 1;
            else if((target=="staff"||target=="rod"||target=="sceptre"||target=="wand")&&((currentRoom.getIList()[i]%6==1&&currentRoom.getIList()[i]>7)||currentRoom.getIList()[i]==3||currentRoom.getIList()[i]==8)&&currentRoom.getIList()[i]<=56)
                valid = 1;
            else if(target=="club"&&currentRoom.getIList()[i]==14)
                valid = 1;
            else if(target=="gauntlet"&&currentRoom.getIList()[i]==38)
                valid = 1;
            else if(target=="fang"&&currentRoom.getIList()[i]==57)
                valid = 1;
            else if((target=="sceptre"||target=="siphon")&&currentRoom.getIList()[i]==58)
                valid = 1;
            else if(target=="shield"&&(currentRoom.getIList()[i]==139||currentRoom.getIList()[i]==142))
                valid = 1;
            else if(target=="cloak"&&currentRoom.getIList()[i]==137)
                valid = 1;
            else if(target=="plate"&&currentRoom.getIList()[i]==138)
                valid = 1;
            else if(target=="helm"&&currentRoom.getIList()[i]==141)
                valid = 1;
            else if(target=="armor"&&currentRoom.getIList()[i]>=100&&currentRoom.getIList()[i]<200)
                valid = 1;
            else if(target=="robe"&&((currentRoom.getIList()[i]%5==0&&currentRoom.getIList()[i]>111)||currentRoom.getIList()[i]==102||currentRoom.getIList()[i]==105||currentRoom.getIList()[i]==108||currentRoom.getIList()[i]==111)&&currentRoom.getIList()[i]<200)
                valid = 1;
            else if(target=="food"&&currentRoom.getIList()[i]>=200&&currentRoom.getIList()[i]<=203)
                valid = 1;
            else if(target=="gem"&&currentRoom.getIList()[i]==203)
                valid = 1;
            else if(target=="berry"&&currentRoom.getIList()[i]==201)
                valid = 1;
            else if(target=="potion"&&currentRoom.getIList()[i]>=204&&currentRoom.getIList()[i]<=211)
                valid = 1;
            else if(target=="bomb"&&(currentRoom.getIList()[i]==213||currentRoom.getIList()[i]==216||currentRoom.getIList()[i]==219))
                valid = 1;
            else if(target=="capsule"&&currentRoom.getIList()[i]==214)
                valid = 1;
            else if((target=="herbs"||target=="herb")&&currentRoom.getIList()[i]==215)
                valid = 1;
            else if(target=="vial"&&(currentRoom.getIList()[i]==217||currentRoom.getIList()[i]==218||currentRoom.getIList()[i]==221))
                valid = 1;
            else if((target=="venom"||target=="poison")&&currentRoom.getIList()[i]==218)
                valid = 1;
            else if(target=="flower"&&currentRoom.getIList()[i]==220)
                valid = 1;
            else if((target=="tincture"||target=="bottle")&&currentRoom.getIList()[i]==221)
                valid = 1;
            else if((target=="veil"||target=="statue")&&currentRoom.getIList()[i]==222)
                valid = 1;
            else if((target=="dust"||target=="powder")&&currentRoom.getIList()[i]==223)
                valid = 1;
            else if((target=="soul"||target=="sphere")&&currentRoom.getIList()[i]==224)
                valid = 1;
            else if((target=="spell"||target=="scroll")&&currentRoom.getIList()[i]>=300&&currentRoom.getIList()[i]<=342)
                valid = 1;
            else if((target=="ring")&&currentRoom.getIList()[i]>=400&&currentRoom.getIList()[i]<500)
                valid = 1;
            else if(target=="all"||target=="everything")
                valid = 2;
            //cout << valid << endl;
            if(valid >= 1)
            {
                //cout << "Match!: " << currentRoom.getIList()[i] << endl;
                if(itemStatus[i]==1)
                    return "Empty.";
                if(currentRoom.getIList()[i]<200||currentRoom.getIList()[i]>=400)
                {
                    if(hero.equipment.size()>=6)
                    {
                        if(valid==1)
                        {
                            itemIndex = i;
                            return "replace";
                        }
                        else if(valid!=2||i<currentRoom.contents)
                        {
                            if(returner!="")
                                returner += "\n";
                            returner += "Your inventory is full.";
                            continue;
                        }
                    }
                    if(valid!=2||i<currentRoom.contents)
                    {
                        itemStatus[i] = 1;
                        hero.equipment.push_back(currentRoom.getIList()[i]);
                        if(currentRoom.getIList()[i]==57||currentRoom.getIList()[i]==58||currentRoom.getIList()[i]==142||currentRoom.getIList()[i]==434)
                            currentRoom.creatDesc = "";
                    }
                    //cout << "Size of equipment inventory: " << hero.equipment.size() << endl;
                }
                else if(currentRoom.getIList()[i]<=224&&currentRoom.getIList()[i]!=212)
                {
                    if(hero.inventory.size()>=6)
                    {
                        if(valid==1)
                        {
                            itemIndex = i;
                            return "replace";
                        }
                        else if(valid!=2||i<currentRoom.contents)
                        {
                            if(returner!="")
                                returner += "\n";
                            returner += "Your inventory is full.";
                            continue;
                        }
                    }
                    if(valid!=2||i<currentRoom.contents)
                    {
                        itemStatus[i] = 1;
                        hero.inventory.push_back(currentRoom.getIList()[i]);
                    }
                    //cout << "Size of item inventory: " << hero.inventory.size() << endl;
                }
                else if(currentRoom.getIList()[i]==212)
                {
                    if(valid!=2||i<currentRoom.contents)
                    {
                        itemStatus[i] = 1;
                        hero.keys += 1;
                    }
                }
                else if(currentRoom.getIList()[i]<=343&&currentRoom.getIList()[i]>=300)
                {
                    for(int j=0;j<hero.spellbook.size();j++)
                        if(currentRoom.getIList()[i]==hero.spellbook[j])
                        {
                            if(valid==1)
                                return "You already know this spell.";
                            else
                            {
                                next = 1;
                                break;
                            }
                        }
                    if(next==1&&i<currentRoom.contents)
                    {
                        if(returner!="")
                            returner += "\n";
                        returner += "You already know this spell.";
                        continue;
                    }
                    if(valid!=2||i<currentRoom.contents)
                    {
                        itemStatus[i] = 1;
                        hero.spellbook.push_back(currentRoom.getIList()[i]);
                    }
                    //cout << "Size of spellbook: " << hero.spellbook.size() << endl;
                }
                //currentRoom.delItem(i);
                if(valid==1)
                {
                    if(currentRoom.getIList()[i]<300||currentRoom.getIList()[i]>=400)
                        return "You picked up the " + dir.getItemName((currentRoom.getIList())[i]) + "!";
                    else
                        return "You learned " + dir.getItemName((currentRoom.getIList())[i]) + "!";
                }
                else if(i<currentRoom.contents)
                {
                    if(returner!="")
                        returner += "\n";
                    if(currentRoom.getIList()[i]<300||currentRoom.getIList()[i]>=400)
                        returner += "You picked up the " + dir.getItemName((currentRoom.getIList())[i]) + "!";
                    else
                        returner += "You learned " + dir.getItemName((currentRoom.getIList())[i]) + "!";

                    if(i==currentRoom.getIList().size()-1)
                        return returner;
                }
            }
        }
        //cout << valid << endl;
        if(valid!=2)
            return "You can't seem to pick that up.";
        else
            return returner;

    }
    else if(action==3) //ATTACK
    {
        //cout << "Command was 'ATTACK'" << endl;
        if(pass>0)
            return "Enemy has already been defeated.";
        if(hero.mask.getID()==2) //Darkness
            holder = "Silhouette";
        else
            holder = currentRoom.monster.getName();

        if(nicknameChecker(target,currentRoom.monster))
            next = 1;
        else
            next = 0;

        std::transform(holder.begin(), holder.end(), holder.begin(), ::tolower);
        if(target==holder||target=="enemy"||target=="monster"||next==1)
        {
            if(currentRoom.monster.getID()!=-1)
                return "fight";
        }
        else
            return "You decide not to attack that.";
    }
    else
    {
        return "You decide not to attack that.";
    }
    return "Error!";
}

bool nicknameChecker(string name, Creature monster)
{
    if(monster.getID()==9)
        return name=="spider";
    else if(monster.getID()==14)
        return name=="armor";
    else if(monster.getID()==16)
        return name=="minotaur"||name=="skeleton";
    else if(monster.getID()==14)
        return name=="armor";
    else if(monster.getID()==24||monster.getID()==25||monster.getID()==26||monster.getID()==27)
        return name=="elemental";
    else if(monster.getID()==32||monster.getID()==39||monster.getID()==45)
        return name=="golem";
    else if(monster.getID()==34)
        return name=="mage";
    else if(monster.getID()==37)
        return name=="gladiator"||name=="phantom";
    else if(monster.getID()==40||monster.getID()==52)
        return name=="demon";
    else if(monster.getID()==42)
        return name=="giant";
    else if(monster.getID()==43)
        return name=="angel";
    else if(monster.getID()==46||monster.getID()==50||monster.getID()==51)
        return name=="dragon";
    else if(monster.getID()==49||monster.getID()==53)
        return name=="titan";
    else if(monster.getID()==56)
        return name=="man"||name=="boss"||name=="watcher"||name=="termineth"||name=="the watcher";
    else if(monster.getID()==57)
        return name=="behemoth"||name=="beast"||name=="ozkoroth";
    else if(monster.getID()==58)
        return name=="figure"||name=="vines"||name=="endrigaia";
    else if(monster.getID()==59)
        return name=="man"||name=="wizard"||name=="mage"||name=="sorcerer"||name=="emeritus";
    else if(monster.getID()==60)
        return name=="man"||name=="warrior"||name=="bounty hunter"||name=="big boi"||name=="big boy"||name=="stiran";
    else if(monster.getID()==61)
        return name=="figure"||name=="creature"||name=="horror"||name=="humanoid"||name=="?"||name=="???"||name=="?????";
    else if(monster.getID()==62)
        return name=="woman"||name=="short woman"||name=="minion"||name=="scion"||name=="wizard"||name=="mage"||name=="sorcerer"||name=="byralt";
    else if(monster.getID()==48)
        return name=="valentereth"||name=="the tyrant"||name=="goddess"||name=="boss";
    else if(monster.getID()==63)
        return name=="halliot"||name=="woman"||name=="awakened";
    else
        return 0;
}
