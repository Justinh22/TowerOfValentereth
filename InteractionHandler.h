string interactionHandler(int action, string target, Player &hero, Directory &dir, Room &currentRoom, int &pass, bool itemStatus[3])
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
        if(target=="door"||target=="doors"||target=="tunnel"||target=="doorway"||target=="ladder"||target=="passage"||target=="passageway"||target=="room"||target=="chamber")
        {
            if(pass==1)
                return "next";
            else
                return "escape";
        }
        if(target=="store"||target=="locked door"||target=="merchant"||target=="shop")
        {
            return "store";
        }
        else
            return "Unknown target.";
    }
    else if(action==1) //LOOK
    {
        //cout << "Command was 'LOOK'" << endl;

        if(hero.mask.getID()==2) //Darkness
            lowername = "Silhouette";
        else
            lowername = currentRoom.monster.getName();

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
                        if(currentRoom.getIList()[i]<200)
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
        else if(target==lowername||target=="enemy"||target=="monster")
        {
            if(currentRoom.monster.level==-1)
                return "No enemy present.";
            if(hero.mask.getID()==2) //Darkness
            {
                holder = "Silhouette | Level " + std::to_string(currentRoom.monster.getLEV()) + "\n";
                holder += "HP: ??\n";
                holder += "Strength: ??\n";
                holder += "Accuracy: ??\n";
                holder += "Defense: ??\n";
                holder += "Dodge: ??";
            }
            else
            {
                holder = currentRoom.monster.getName() + " | Level " + std::to_string(currentRoom.monster.getLEV()) + "\n";
                holder += "HP: " + std::to_string(currentRoom.monster.getHP()) + "\n";
                holder += "Strength: " + std::to_string(currentRoom.monster.getSTR()) + "\n";
                holder += "Accuracy: " + std::to_string(currentRoom.monster.getACC()) + "\n";
                holder += "Defense: " + std::to_string(currentRoom.monster.getDEF()) + "\n";
                holder += "Dodge: " + std::to_string(currentRoom.monster.getDDG());
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
                                    if(currentRoom.getIList()[j-1+currentRoom.contents]<200)
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
                else if((target=="spear"||target=="pike")&&((currentRoom.getIList()[i]%6==5&&currentRoom.getIList()[i]>5)||currentRoom.getIList()[i]==6)&&currentRoom.getIList()[i]<=56)
                    valid = 1;
                else if((target=="dagger"||target=="knife")&&((currentRoom.getIList()[i]%6==0&&currentRoom.getIList()[i]>6)||currentRoom.getIList()[i]==2||currentRoom.getIList()[i]==7||currentRoom.getIList()[i]==32)&&currentRoom.getIList()[i]<=56)
                    valid = 1;
                else if((target=="staff"||target=="rod"||target=="sceptre"||target=="wand")&&((currentRoom.getIList()[i]%6==1&&currentRoom.getIList()[i]>7)||currentRoom.getIList()[i]==3||currentRoom.getIList()[i]==8)&&currentRoom.getIList()[i]<56)
                    valid = 1;
                else if(target=="club"&&currentRoom.getIList()[i]==14)
                    valid = 1;
                else if(target=="gauntlet"&&currentRoom.getIList()[i]==38)
                    valid = 1;
                else if(target=="armor"&&currentRoom.getIList()[i]>56&&currentRoom.getIList()[i]<99)
                    valid = 1;
                else if(target=="robe"&&((currentRoom.getIList()[i]%5==2&&currentRoom.getIList()[i]>69)||currentRoom.getIList()[i]==59||currentRoom.getIList()[i]==62||currentRoom.getIList()[i]==65)&&currentRoom.getIList()[i]<=98)
                    valid = 1;
                else if(target=="food"&&currentRoom.getIList()[i]>=100&&currentRoom.getIList()[i]<=103)
                    valid = 1;
                else if(target=="potion"&&currentRoom.getIList()[i]>=104&&currentRoom.getIList()[i]<=111)
                    valid = 1;
                else if((target=="spell"||target=="scroll")&&currentRoom.getIList()[i]>=200&&currentRoom.getIList()[i]<=242)
                    valid = 1;
                if(valid==1)
                {
                    if(currentRoom.getIList()[i]<57)
                    {
                        cout << dir.getItemName(currentRoom.getIList()[i]) << " | " << dir.getItemDesc(currentRoom.getIList()[i]) << endl;
                        cout << "RARITY: " << dir.weaponDirectory[currentRoom.getIList()[i]].getRarity() << endl;
                        cout << "STR " << dir.weaponDirectory[currentRoom.getIList()[i]].getStr() << endl;
                        cout << "ACC " << dir.weaponDirectory[currentRoom.getIList()[i]].getAcc() << endl;
                        cout << "CRIT " << dir.weaponDirectory[currentRoom.getIList()[i]].getCrt() << endl;
                    }
                    else if(currentRoom.getIList()[i]<99)
                    {
                        cout << dir.getItemName(currentRoom.getIList()[i]) << " | " << dir.getItemDesc(currentRoom.getIList()[i]) << endl;
                        cout << "RARITY: " << dir.armorDirectory[currentRoom.getIList()[i]-57].getRarity() << endl;
                        cout << "DEF " << dir.armorDirectory[currentRoom.getIList()[i]-57].getDef() << endl;
                        cout << "DDG " << dir.armorDirectory[currentRoom.getIList()[i]-57].getDdg() << endl;
                    }
                    else if(currentRoom.getIList()[i]<200)
                    {
                        if(currentRoom.getIList()[i]==112)
                        {
                            cout << "A small, silver key." << endl;
                        }
                        else
                        {
                            cout << dir.consumableDirectory[currentRoom.getIList()[i]-100].getName() << " | " << dir.consumableDirectory[currentRoom.getIList()[i]-100].getDesc() << endl;
                            cout << "RARITY: " << dir.consumableDirectory[currentRoom.getIList()[i]-100].getRarity() << endl;
                            cout << "HP " << dir.consumableDirectory[currentRoom.getIList()[i]-100].getHP() << endl;
                            cout << "MP " << dir.consumableDirectory[currentRoom.getIList()[i]-100].getMP() << endl;
                        }
                    }
                    else
                    {
                        cout << dir.getItemName(currentRoom.getIList()[i]) << " | " << dir.getItemDesc(currentRoom.getIList()[i]) << endl;
                        cout << "RARITY: " << dir.getItemRarity(currentRoom.getIList()[i]) << endl;
                        if(currentRoom.getIList()[i]<=214)
                        {
                            cout << "MANA COST: " << dir.attackSpellDirectory[currentRoom.getIList()[i]-200].getManaCost() << endl;
                            cout << "DAMAGE: " << dir.attackSpellDirectory[currentRoom.getIList()[i]-200].getDMG() << endl;
                        }
                        else if(currentRoom.getIList()[i]<=220)
                        {
                            cout << "MANA COST: " << dir.healingSpellDirectory[currentRoom.getIList()[i]-215].getManaCost() << endl;
                            cout << "HEALING: " << dir.healingSpellDirectory[currentRoom.getIList()[i]-215].getHPR() << endl;
                        }
                        else
                        {
                            cout << "MANA COST: " << dir.buffSpellDirectory[currentRoom.getIList()[i]-221].getManaCost() << endl;
                        }
                    }
                    return "check";
                }
            }
            return "Unknown target.";
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
            else if((target=="spear"||target=="pike")&&((currentRoom.getIList()[i]%6==5&&currentRoom.getIList()[i]>5)||currentRoom.getIList()[i]==6)&&currentRoom.getIList()[i]<=56)
                valid = 1;
            else if((target=="dagger"||target=="knife")&&((currentRoom.getIList()[i]%6==0&&currentRoom.getIList()[i]>6)||currentRoom.getIList()[i]==2||currentRoom.getIList()[i]==7||currentRoom.getIList()[i]==32)&&currentRoom.getIList()[i]<=56)
                valid = 1;
            else if((target=="staff"||target=="rod"||target=="sceptre"||target=="wand")&&((currentRoom.getIList()[i]%6==1&&currentRoom.getIList()[i]>7)||currentRoom.getIList()[i]==3||currentRoom.getIList()[i]==8)&&currentRoom.getIList()[i]<56)
                valid = 1;
            else if(target=="club"&&currentRoom.getIList()[i]==14)
                valid = 1;
            else if(target=="gauntlet"&&currentRoom.getIList()[i]==38)
                valid = 1;
            else if(target=="armor"&&currentRoom.getIList()[i]>56&&currentRoom.getIList()[i]<99)
                valid = 1;
            else if(target=="robe"&&((currentRoom.getIList()[i]%5==2&&currentRoom.getIList()[i]>69)||currentRoom.getIList()[i]==59||currentRoom.getIList()[i]==62||currentRoom.getIList()[i]==65||currentRoom.getIList()[i]==68)&&currentRoom.getIList()[i]<=98)
                valid = 1;
            else if(target=="food"&&currentRoom.getIList()[i]>=100&&currentRoom.getIList()[i]<=103)
                valid = 1;
            else if(target=="potion"&&currentRoom.getIList()[i]>=104&&currentRoom.getIList()[i]<=111)
                valid = 1;
            else if((target=="spell"||target=="scroll")&&currentRoom.getIList()[i]>=200&&currentRoom.getIList()[i]<=242)
                valid = 1;
            else if(target=="all"||target=="everything")
                valid = 2;
            //cout << valid << endl;
            if(valid >= 1)
            {
                //cout << "Match!: " << currentRoom.getIList()[i] << endl;
                if(itemStatus[i]==1)
                    return "Empty.";
                if(currentRoom.getIList()[i]<=98)
                {
                    if(hero.equipment.size()>=6)
                    {
                        if(valid==1)
                            return "Your inventory is full.";
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
                    }
                    //cout << "Size of equipment inventory: " << hero.equipment.size() << endl;
                }
                else if(currentRoom.getIList()[i]<=111)
                {
                    if(hero.inventory.size()>=6)
                    {
                        if(valid==1)
                            return "Your inventory is full.";
                        else if(valid!=2||i>=currentRoom.contents)
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
                else if(currentRoom.getIList()[i]==112)
                {
                    if(valid!=2||i<currentRoom.contents)
                    {
                        itemStatus[i] = 1;
                        hero.keys += 1;
                    }
                }
                else if(currentRoom.getIList()[i]<=242&&currentRoom.getIList()[i]>112)
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
                    if(currentRoom.getIList()[i]<200)
                        return "You picked up the " + dir.getItemName((currentRoom.getIList())[i]) + "!";
                    else
                        return "You learned " + dir.getItemName((currentRoom.getIList())[i]) + "!";
                }
                else if(i<currentRoom.contents)
                {
                    if(returner!="")
                        returner += "\n";
                    if(currentRoom.getIList()[i]<200)
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
            return "Unknown target.";
        else
            return returner;

    }
    else if(action==3) //ATTACK
    {
        //cout << "Command was 'ATTACK'" << endl;
        if(hero.mask.getID()==2) //Darkness
            holder = "Silhouette";
        else
            holder = currentRoom.monster.getName();

        std::transform(holder.begin(), holder.end(), holder.begin(), ::tolower);
        if(target==holder||target=="enemy"||target=="monster")
        {
            if(currentRoom.monster.getID()!=-1)
                return "fight";
        }
        else
            return "Unknown target.";
    }
    else
    {
        return "Unknown action.";
    }
    return "Error!";
}
