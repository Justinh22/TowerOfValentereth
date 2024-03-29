void encounterHandler(Player &hero, Directory dir, int &adv, int &depth, vector<bool> &randEncStatus)
{
    std::system("cls");
    int encounter = rand()%20;
    bool good=0;
    bool flag=0;
    int timeout = 0;
    int amount = 0;
    string strChoice;
    int intChoice;
    vector<int> items;
    vector<int> cost;
    string checkA;
    string checkB;
    do
    {
        if(!randEncStatus[encounter]||timeout>50)
            good = 1;
        else
            encounter = rand()%15;
        timeout++;
    } while(!good);
    randEncStatus[encounter] = 1;
    good = 0;
    cout << "-------------------------------------------------------ENCOUNTER-------------------------------------------------------" << endl << endl << endl;

    switch(encounter)
    {
        case 0:
            if(hero.gold>0)
                amount = rand()%hero.gold;
            cout << "A figure jumps out from the shadows, and holds a knife to your throat. 'All right, hand over your gold if you know what's good for you!'" << endl << endl;
            cout << "1) " << 30 + hero.getDDG() << "% success - Run away." << endl;
            cout << "2) " << 30 + hero.getSTR() << "% success - Scare them off." << endl;
            cout << "3) " << "Pay them " << amount << " gold." << endl << endl;
            while(!good)
            {
                cout << "What do you do?" << endl;
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice==1)
                {
                    if(rand()%100<=40+hero.getDDG())
                    {
                        karma -= 1;
                        cout << "You manage to break free of their hold, and sprint down the corridor away from them!" << endl;
                        Sleep(longWait);
                        good = 1;
                    }
                    else
                    {
                        karma += 1;
                        cout << "The thief grabs you and cuts you with their knife. 'You're not going anywhere, pal!' You take " << hero.level << " damage!" << endl << endl;
                        hero.changeHP(-hero.level);
                        Sleep(shortWait);
                    }
                }
                else if(intChoice==2)
                {
                    if(rand()%100<=40+hero.getSTR())
                    {
                        karma -= 1;
                        cout << "You brandish your weapon toward them, and before you can say a word the thief runs off." << endl;
                        Sleep(longWait);
                        good = 1;
                    }
                    else
                    {
                        karma += 1;
                        cout << "The thief laughs at your attempt to intimidate them, and cuts you with their knife. You take " << hero.level << " damage!" << endl << endl;
                        hero.changeHP(-hero.level);
                        Sleep(shortWait);
                    }
                }
                else if(intChoice==3)
                {
                    karma += 1;
                    cout << "You fork over " << amount << " gold to the thief, and they let you pass." << endl;
                    hero.gold -= amount;
                    good = 1;
                    Sleep(midWait);
                }
                else
                {
                    cout << "Invalid input." << endl << endl;
                }
            }
            break;
        case 1:
            karma -= 2;
            cout << "A radiant spirit descends from above, shedding golden light across the passage. 'Foolhardy adventurer... you know not the cruel truth of this place. You will need all the help you can get to escape... Please accept my blessing.'" << endl << endl;
            cout << "1) Restore " << static_cast<int>(hero.getMHP()*.5) << " HP." << endl;
            cout << "2) Restore " << static_cast<int>(hero.getMMP()*.5) << " MP." << endl << endl;
            while(!good)
            {
                cout << "What do you do?" << endl;
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice==1)
                {
                    cout << "You are enveloped in pink light, and are healed for " << static_cast<int>(hero.getMHP()*.5) << " HP!" << endl;
                    hero.changeHP(static_cast<int>(hero.getMHP()*.5));
                    if(hero.getHP()>hero.getMHP())
                        hero.setHP(hero.getMHP());
                    Sleep(longWait);
                    good = 1;
                }
                else if(intChoice==2)
                {
                    cout << "You are enveloped in violet light, and are restored for " << static_cast<int>(hero.getMMP()*.5) << " MP!" << endl;
                    hero.changeMP(static_cast<int>(hero.getMMP()*.5));
                    if(hero.getMP()>hero.getMMP())
                        hero.setMP(hero.getMMP());
                    Sleep(longWait);
                    good = 1;
                }
                else
                {
                    cout << "Invalid input." << endl << endl;
                }
            }
            break;
        case 2:
            karma -= 1;
            if(hero.level<5)
            {
                items.push_back(spellPicker(1));
                items.push_back(spellPicker(2));
                items.push_back(spellPicker(3));
                cost.push_back(5);
                cost.push_back(20);
                cost.push_back(50);
            }
            else if(hero.level<8)
            {
                items.push_back(spellPicker(2));
                items.push_back(spellPicker(3));
                items.push_back(spellPicker(4));
                cost.push_back(20);
                cost.push_back(50);
                cost.push_back(100);
            }
            else
            {
                items.push_back(spellPicker(3));
                items.push_back(spellPicker(4));
                items.push_back(spellPicker(5));
                cost.push_back(50);
                cost.push_back(100);
                cost.push_back(160);
            }
            cout << "A tall woman in a long, shimmering cloak stands in the hall before the next chamber. 'This place is treacherous... but lucky for you I've got these... for a price of course.' She flashes a number of scrolls at you." << endl << endl;
            cout << "1) Purchase " << dir.getItemName(items[0]) << " for " << cost[0] << " gold." << endl;
            cout << "2) Purchase " << dir.getItemName(items[1]) << " for " << cost[1] << " gold." << endl;
            cout << "3) Purchase " << dir.getItemName(items[2]) << " for " << cost[2] << " gold." << endl;
            cout << "4) Don't buy anything." << endl << endl;
            while(!good)
            {
                cout << "What do you do?" << endl;
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice<=3&&intChoice>=1)
                {
                    for(int i=0;i<hero.spellbook.size();i++)
                        if(items[intChoice-1]==hero.spellbook[i])
                        {
                            cout << "You already know this spell." << endl << endl;
                            flag = 1;
                        }
                    if(flag)
                        continue;
                    if(cost[intChoice-1]<=hero.gold)
                    {
                        hero.gold -= cost[intChoice-1];
                        hero.spellbook.push_back(items[intChoice-1]);
                        cout << "You learned " << dir.getItemName(items[intChoice-1]) << "!" << endl;
                        Sleep(longWait);
                        good = 1;
                    }
                    else
                    {
                        cout << "The woman glares at you. 'Hey, if you don't have the gold, you should just keep moving.'" << endl << endl;
                    }
                }
                else if(intChoice==4)
                {
                    cout << "'Very well. We'll see how much longer you last in these halls...'" << endl << endl;
                    Sleep(longWait);
                    good = 1;
                }
                else
                {
                    cout << "Invalid input." << endl << endl;
                }
            }
            break;
        case 3:
            cout << "Against the wall, you see an unconscious figure slumped against the wall. They seem like they're out cold." << endl << endl;
            cout << "1) " << 60 + hero.getDDG() << "% success - Swipe some gold." << endl;
            cout << "2) " << 30 + hero.getDDG() << "% success - Steal their ring." << endl;
            cout << "3) " << 70 + hero.getLCK() << "% success - Try to wake them up." << endl;
            cout << "4) Leave them be." << endl << endl;
            while(!good)
            {
                cout << "What do you do?" << endl;
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice==1)
                {
                    if(rand()%100<=60+hero.getDDG())
                    {
                        karma -= 1;
                        cout << "You lift a few coins from a small coinpurse in their pocket. They likely won't even know they're gone..." << endl;
                        amount = ((rand()%10)*hero.level)+1;
                        Sleep(shortWait);
                        cout << "You got " << amount << " gold!" << endl;
                        hero.gold += amount;
                    }
                    else
                    {
                        karma += 1;
                        cout << "The figure wakes up with your hand in their pocket, and swings a blade at you! You hurry away from them." << endl;
                        amount = ((rand()%5)*hero.level)+1;
                        Sleep(shortWait);
                        cout << "You take " << amount << " damage!" << endl;
                        hero.changeHP(-amount);
                    }
                    Sleep(longWait);
                    good = 1;
                }
                else if(intChoice==2)
                {
                    if(rand()%100<=30+hero.getDDG())
                    {
                        karma -= 3;
                        cout << "You quietly slide a ring off of one of their fingers. They certainly won't need it now..." << endl;
                        amount = itemPicker(4,1);
                        Sleep(shortWait);
                        if(hero.equipment.size()<6)
                        {
                            cout << "You got a " << amount << "!" << endl;
                            hero.equipment.push_back(amount);
                        }
                        else
                        {
                            while(!good)
                            {
                                std::system("cls");
                                replaceMenu(hero,dir,0,amount);
                                strChoice = getch();
                                std::stringstream stoi(strChoice);
                                stoi >> intChoice;
                                if(intChoice>=1&&intChoice<=hero.equipment.size())
                                {
                                    cout << "Replaced " << dir.getItemName(hero.equipment[intChoice-1]) << " with " << dir.getItemName(amount) << "." << endl;
                                    hero.equipment[intChoice-1] = amount;
                                    good = 1;
                                }
                                else if(intChoice==0)
                                {
                                    good = 1;
                                }
                                else
                                {
                                    cout << "Invalid input." << endl;
                                    Sleep(shortWait);
                                }
                            }
                        }
                    }
                    else
                    {
                        karma += 1;
                        cout << "The figure wakes up with your hand around their ring, and swings a blade at you! You hurry away from them." << endl;
                        amount = ((rand()%5)*hero.level)+1;
                        Sleep(shortWait);
                        cout << "You take " << amount << " damage!" << endl;
                        hero.changeHP(-amount);
                    }
                    Sleep(longWait);
                    good = 1;
                }
                else if(intChoice==3)
                {
                    if(rand()%100<=70+hero.getLCK())
                    {
                        cout << "You shake the figure and they jolt awake. After a moment of shock, they jump to their feet." << endl;
                        Sleep(shortWait);
                        if(rand()%2==0)
                        {
                            karma += 1;
                            cout << "They run off down the corridor, out of sight.";
                        }
                        else
                        {
                            karma -= 1;
                            cout << "'Thank you... I don't know how long I've been out. Here, take this.'" << endl;
                            Sleep(shortWait);
                            amount = ((rand()%10)*(hero.level+1))+1;
                            cout << "You received " << amount << " gold!" << endl;
                            hero.gold += amount;
                        }
                    }
                    else
                    {
                        cout << "The figure doesn't even stir. You make your way onward." << endl;
                    }
                    Sleep(longWait);
                    good = 1;
                }
                else if(intChoice==4)
                {
                    cout << "You decide to leave them be." << endl;
                    Sleep(longWait);
                    good = 1;
                }
                else
                {
                    cout << "Invalid input." << endl << endl;
                }
            }
            break;
        case 4:
            if(hero.getSTR()>adv*5)
                checkA = "GOOD";
            else
                checkA = "X";
            checkB = "X";
            for(int i=0;i<hero.spellbook.size();i++)
            {
                if(dir.getItemRarity(hero.spellbook[i])>=3&&hero.spellbook[i]<=314)
                {
                    checkB = "GOOD";
                }
            }
            cout << "You notice that the wall to your left has a long crack down it. Through the crack, you can see some light..." << endl << endl;
            cout << "1) ATK " << adv*5 << " [" << checkA << "] - Break down the wall." << endl;
            cout << "2) Rarity 3 Attack Spell [" << checkB << "] - Blast the wall down with magic." << endl;
            cout << "3) Leave it be." << endl << endl;
            while(!good)
            {
                cout << "What do you do?" << endl;
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice==1||intChoice==2)
                {
                    if((checkA=="GOOD"&&intChoice==1)||(checkB=="GOOD"&&intChoice==2))
                    {
                        karma -= 1;
                        cout << "You break down the wall!" << endl;
                        Sleep(shortWait);
                        if(rand()%2==0)
                        {
                            cout << "Behind it, you see a weapon on a pedestal." << endl;
                            Sleep(shortWait);
                            if(adv>10)
                                amount = itemPicker(0,10);
                            else
                                amount = itemPicker(0,adv);
                        }
                        else
                        {
                            cout << "Behind it, you see a suit of armor on a pedestal." << endl;
                            Sleep(shortWait);
                            if(adv>10)
                                amount = itemPicker(1,10);
                            else
                                amount = itemPicker(1,adv);
                        }
                        if(hero.equipment.size()<6)
                        {
                            cout << "You got a " << dir.getItemName(amount) << "!" << endl;
                            hero.equipment.push_back(amount);
                        }
                        else
                        {
                            while(!good)
                            {
                                std::system("cls");
                                replaceMenu(hero,dir,0,amount);
                                strChoice = getch();
                                std::stringstream stoi(strChoice);
                                stoi >> intChoice;
                                if(intChoice>=1&&intChoice<=hero.equipment.size())
                                {
                                    cout << "Replaced " << dir.getItemName(hero.equipment[intChoice-1]) << " with " << dir.getItemName(amount) << "." << endl;
                                    hero.equipment[intChoice-1] = amount;
                                    good = 1;
                                }
                                else if(intChoice==0)
                                {
                                    good = 1;
                                }
                                else
                                {
                                    cout << "Invalid input." << endl;
                                    Sleep(shortWait);
                                }
                            }
                        }
                    }
                    else
                    {
                        cout << "As hard as you try, the wall stays standing." << endl << endl;
                        continue;
                    }
                    Sleep(midWait);
                    good = 1;
                }
                else if(intChoice==3)
                {
                    cout << "You decide to leave it be, and walk toward the next chamber." << endl;
                    Sleep(midWait);
                    good = 1;
                }
                else
                {
                    cout << "Invalid input." << endl << endl;
                }
            }
            break;
        case 5:
            if(hero.getSTR()>adv*4)
                checkA = "GOOD";
            else
                checkA = "X";
            checkB = "X";
            for(int i=0;i<hero.spellbook.size();i++)
            {
                if(hero.spellbook[i]<314&&(hero.spellbook[i]-301)%3==0)
                {
                    checkB = "GOOD";
                }
            }
            if(adv>10)
                amount = itemPicker(1,10);
            else
                amount = itemPicker(1,adv);
            cout << "At your feet, you see a set of armor frozen in thick ice." << endl << endl;
            cout << "1) ATK " << adv*4 << " [" << checkA << "] - Shatter the ice to free the armor." << endl;
            cout << "2) Fire Spell [" << checkB << "] - Melt the ice with fire magic." << endl;
            cout << "3) Move on." << endl << endl;
            while(!good)
            {
                cout << "What do you do?" << endl;
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice==1||intChoice==2)
                {
                    if((checkA=="GOOD"&&intChoice==1)||(checkB=="GOOD"&&intChoice==2))
                    {
                        karma -= 1;
                        if(intChoice==1)
                            cout << "You shatter the ice!" << endl;
                        else
                            cout << "The ice melts in the flames!" << endl;
                        Sleep(shortWait);
                        if(hero.equipment.size()<6)
                        {
                            cout << "You got a " << dir.getItemName(amount) << "!" << endl;
                            hero.equipment.push_back(amount);
                        }
                        else
                        {
                            while(!good)
                            {
                                std::system("cls");
                                replaceMenu(hero,dir,0,amount);
                                strChoice = getch();
                                std::stringstream stoi(strChoice);
                                stoi >> intChoice;
                                if(intChoice>=1&&intChoice<=hero.equipment.size())
                                {
                                    cout << "Replaced " << dir.getItemName(hero.equipment[intChoice-1]) << " with " << dir.getItemName(amount) << "." << endl;
                                    hero.equipment[intChoice-1] = amount;
                                    good = 1;
                                }
                                else if(intChoice==0)
                                {
                                    good = 1;
                                }
                                else
                                {
                                    cout << "Invalid input." << endl;
                                    Sleep(shortWait);
                                }
                            }
                        }
                    }
                    else
                    {
                        cout << "The ice is still frozen thick around the armor." << endl << endl;
                        continue;
                    }
                    Sleep(longWait);
                    good = 1;
                }
                else if(intChoice==3)
                {
                    cout << "You decide to leave it be, and walk toward the next chamber." << endl;
                    Sleep(longWait);
                    good = 1;
                }
                else
                {
                    cout << "Invalid input." << endl << endl;
                }
            }
            break;
        case 6:
            checkA = "X";
            for(int i=0;i<hero.equipment.size();i++)
            {
                if(((hero.equipment[i]%5==0&&hero.equipment[i]>111)||hero.equipment[i]==102||hero.equipment[i]==105||hero.equipment[i]==108||hero.equipment[i]==111)&&hero.equipment[i]<200)
                {
                    checkA = "GOOD";
                }
            }
            checkB = "X";
            for(int i=0;i<hero.spellbook.size();i++)
            {
                if(hero.spellbook[i]<314&&(hero.spellbook[i]-300)%3==2)
                {
                    checkB = "GOOD";
                }
            }
            if(adv>10)
                amount = itemPicker(0,10);
            else
                amount = itemPicker(0,adv);
            cout << "Stuck in the wall, you see a weapon jutting out. It is glowing red with heat..." << endl << endl;
            cout << "1) Robe [" << checkA << "] - Wrap the weapon in a robe to be able to touch it." << endl;
            cout << "2) Frost Spell [" << checkB << "] - Cool the weapon with frost magic." << endl;
            cout << "3) Move on." << endl << endl;
            while(!good)
            {
                cout << "What do you do?" << endl;
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice==1||intChoice==2)
                {
                    if((checkA=="GOOD"&&intChoice==1)||(checkB=="GOOD"&&intChoice==2))
                    {
                        karma -= 1;
                        if(intChoice==1)
                            cout << "You pull the weapon from the wall with the robe!" << endl;
                        else
                            cout << "The ice cools the weapon, and you pull it from the wall!" << endl;
                        Sleep(shortWait);
                        if(hero.equipment.size()<6)
                        {
                            cout << "You got a " << dir.getItemName(amount) << "!" << endl;
                            hero.equipment.push_back(amount);
                        }
                        else
                        {
                            while(!good)
                            {
                                std::system("cls");
                                replaceMenu(hero,dir,0,amount);
                                strChoice = getch();
                                std::stringstream stoi(strChoice);
                                stoi >> intChoice;
                                if(intChoice>=1&&intChoice<=hero.equipment.size())
                                {
                                    cout << "Replaced " << dir.getItemName(hero.equipment[intChoice-1]) << " with " << dir.getItemName(amount) << "." << endl;
                                    hero.equipment[intChoice-1] = amount;
                                    good = 1;
                                }
                                else if(intChoice==0)
                                {
                                    good = 1;
                                }
                                else
                                {
                                    cout << "Invalid input." << endl;
                                    Sleep(shortWait);
                                }
                            }
                        }
                    }
                    else
                    {
                        cout << "The weapon is red hot, you can't touch it..." << endl << endl;
                        continue;
                    }
                    Sleep(longWait);
                    good = 1;
                }
                else if(intChoice==3)
                {
                    cout << "You leave the weapon in the wall, and head into the next chamber." << endl;
                    Sleep(longWait);
                    good = 1;
                }
                else
                {
                    cout << "Invalid input." << endl << endl;
                }
            }
            break;
        case 7:
            cout << "A large, burly-looking man stands in the corridor, training against a dummy. After looking you over, he says 'Heh, looks like you need all the help you can get. I s'pose I could give you some training... I trained under Stiran after all.'" << endl << endl;
            cout << "1) " << 10*adv << "g - Train with daggers." << endl;
            cout << "2) " << 10*adv << "g - Train with spears." << endl;
            cout << "3) " << 10*adv << "g - Train with swords." << endl;
            cout << "4) " << 10*adv << "g - Train with axes." << endl;
            cout << "5) Pass on training." << endl;
            while(!good)
            {
                cout << "What do you do?" << endl;
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice>=1&&intChoice<=4)
                {
                    if(hero.gold>=10*adv)
                    {
                        karma -= 2;
                        cout << "You trained to become better with ";
                        switch(intChoice)
                        {
                            case 1:
                                cout << "daggers!" << endl;
                                break;
                            case 2:
                                cout << "spears!" << endl;
                                break;
                            case 3:
                                cout << "swords!" << endl;
                                break;
                            case 4:
                                cout << "axes!" << endl;
                                break;
                        }
                        Sleep(shortWait);
                        cout << "You will deal +2 damage and have +5% ACC when wielding them." << endl;
                        hero.meleeTraining = intChoice-1;
                        hero.gold -= 10*adv;
                        Sleep(longWait);
                        good = 1;
                    }
                    else
                    {
                        cout << "'Hey! Unless you've got gold to fork over, you'd best move along.'" << endl << endl;
                        Sleep(shortWait);
                    }
                }
                else if(intChoice==5)
                {
                    karma += 1;
                    randEncStatus[7] = 0;
                    cout << "'Hmph, suit yourself. Don't say I didn't warn ya, kid.'" << endl;
                    Sleep(longWait);
                    good = 1;
                }
                else
                {
                    cout << "Invalid input." << endl << endl;
                }
            }
            break;
        case 8:
            cout << "A small girl sits on the floor, wearing a robe far too large for her. She looks up at you and smiles. 'Oh, hi! You certainly shouldn't have come here. But if you wanna stay, let me help!'" << endl << endl;
            cout << "1) " << 10*adv << "g - Train with frost magic." << endl;
            cout << "2) " << 10*adv << "g - Train with fire magic." << endl;
            cout << "3) " << 10*adv << "g - Train with lightning magic." << endl;
            cout << "4) Pass on training." << endl;
            while(!good)
            {
                cout << "What do you do?" << endl;
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice>=1&&intChoice<=3)
                {
                    if(hero.gold>=10*adv)
                    {
                        karma -= 2;
                        cout << "You trained to become better with ";
                        switch(intChoice)
                        {
                            case 1:
                                cout << "frost magic!" << endl;
                                break;
                            case 2:
                                cout << "fire magic!" << endl;
                                break;
                            case 3:
                                cout << "lightning magic!" << endl;
                                break;
                        }
                        Sleep(shortWait);
                        cout << "You will deal +2 damage when using spells of that element, and they will cost 1 less MP." << endl;
                        hero.magicTraining = intChoice-1;
                        hero.gold -= 10*adv;
                        Sleep(longWait);
                        good = 1;
                    }
                    else
                    {
                        cout << "'Hey... I know I'm a kid, but I know how to count!'" << endl << endl;
                        Sleep(shortWait);
                    }
                }
                else if(intChoice==4)
                {
                    karma += 1;
                    randEncStatus[8] = 0;
                    cout << "'Okay, bye! Can I have your stuff when you die?'" << endl;
                    Sleep(longWait);
                    good = 1;
                }
                else
                {
                    cout << "Invalid input." << endl << endl;
                }
            }
            break;
        case 9:
            cout << "A lost soul dances around the room, shedding a pale white light. It speaks to you in an otherworldly voice: 'Please... I may have fallen to this place, but allow me to help you reach the tower's apex...'" << endl << endl;
            cout << "1) Pray for aid." << endl;
            cout << "2) " << 20 + hero.getLCK() << "% success - Try to catch it." << endl;
            while(!good)
            {
                cout << "What do you do?" << endl;
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice==1)
                {
                    karma -= 1;
                    cout << "You are healed for 20 HP!" << endl;
                    hero.changeHP(20);
                    if(hero.getHP()>hero.getMHP())
                        hero.setHP(hero.getMHP());
                    Sleep(shortWait);
                    cout << "'May you have better luck than I.' The soul fades away into the darkness." << endl;
                    Sleep(longWait);
                    good = 1;
                }
                else if(intChoice==2)
                {
                    if(rand()%100<=20+hero.getLCK())
                    {
                        karma -= 3;
                        cout << "You catch the soul in a glass bottle!" << endl;
                        Sleep(longWait);
                        if(hero.inventory.size()<6)
                        {
                            hero.inventory.push_back(224);
                        }
                        else
                        {
                            while(!good)
                            {
                                std::system("cls");
                                replaceMenu(hero,dir,1,224);
                                strChoice = getch();
                                std::stringstream stoi(strChoice);
                                stoi >> intChoice;
                                if(intChoice>=1&&intChoice<=hero.inventory.size())
                                {
                                    cout << "Replaced " << dir.getItemName(hero.inventory[intChoice-1]) << " with " << dir.getItemName(224) << "." << endl;
                                    hero.inventory[intChoice-1] = 224;
                                    good = 1;
                                }
                                else if(intChoice==0)
                                {
                                    good = 1;
                                }
                                else
                                {
                                    cout << "Invalid input." << endl;
                                    Sleep(shortWait);
                                }
                            }
                        }
                    }
                    else
                    {
                        karma += 1;
                        cout << "The soul floats just out of reach. 'Get out of here, thief! You'll soon meet the same fate.'" << endl << endl;
                        Sleep(longWait);
                        good = 1;
                    }
                }
                else
                {
                    cout << "Invalid input." << endl << endl;
                }
            }
            break;
        case 10:
            cout << "A robed woman sits meditating by the wall of the corridor, floating a few inches off the ground, with a large hourglass floating in front of her. 'For a small fee, traveler... I can revert the sands of time...'" << endl << endl;
            cout << "1) 100g - Go back 3 rooms." << endl;
            cout << "2) 200g - Go back 5 rooms." << endl;
            cout << "3) 350g - Go back 10 rooms." << endl;
            cout << "4) Refuse." << endl;
            while(!good)
            {
                cout << "What do you do?" << endl;
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice==1)
                {
                    if(hero.gold>=100)
                    {
                        karma -= 1;
                        cout << "You see the scenery around you change and warp, and suddenly you find yourself in a new place. The woman is gone." << endl;
                        hero.gold -= 100;
                        depth -= 3;
                        adv = (depth/5) + 1;
                        Sleep(longWait);
                        good = 1;
                    }
                    else
                    {
                        cout << "'The sands of time do not move for free, mortal...'" << endl << endl;
                        Sleep(shortWait);
                    }
                }
                else if(intChoice==2)
                {
                    if(hero.gold>=200)
                    {
                        karma -= 2;
                        cout << "You see the scenery around you change and warp, and suddenly you find yourself in a new place. The woman is gone." << endl;
                        hero.gold -= 200;
                        depth -= 5;
                        adv = (depth/5) + 1;
                        Sleep(longWait);
                        good = 1;
                    }
                    else
                    {
                        cout << "'The sands of time do not move for free, mortal...'" << endl << endl;
                        Sleep(shortWait);
                    }
                }
                else if(intChoice==3)
                {
                    if(hero.gold>=350)
                    {
                        karma -= 3;
                        cout << "You see the scenery around you change and warp, and suddenly you find yourself in a new place. The woman is gone." << endl;
                        hero.gold -= 350;
                        depth -= 10;
                        adv = (depth/5) + 1;
                        Sleep(longWait);
                        good = 1;
                    }
                    else
                    {
                        cout << "'The sands of time do not move for free, mortal...'" << endl << endl;
                        Sleep(shortWait);
                    }
                }
                else if(intChoice==4)
                {
                    karma += 1;
                    cout << "'Very well. May the sands of time guide you.'" << endl;
                    Sleep(longWait);
                    good = 1;
                }
                else
                {
                    cout << "Invalid input." << endl << endl;
                }
            }
            break;
        case 11:
            karma -= 2;
            if(hero.level<4)
            {
                items.push_back(itemPicker(2,2));
                items.push_back(itemPicker(2,3));
                items.push_back(itemPicker(2,3));
            }
            else if(hero.level<6)
            {
                items.push_back(itemPicker(2,3));
                items.push_back(itemPicker(2,4));
                items.push_back(itemPicker(2,4));
            }
            else
            {
                items.push_back(itemPicker(2,4));
                items.push_back(itemPicker(2,5));
                items.push_back(itemPicker(2,5));
            }
            cout << "An alchemist stands at a cauldron, and looks up at you through a veil of smoke. 'Ohhh... another poor soul lured in by the tower... The Watcher will have fun with you... here, take a potion, I wouldn't want you to perish before you even meet him...'" << endl << endl;
            cout << "1) Take a " << dir.getItemName(items[0]) << "." << endl;
            cout << "2) Take a " << dir.getItemName(items[1]) << "." << endl;
            cout << "3) Take a " << dir.getItemName(items[2]) << "." << endl;
            cout << "4) Don't take anything." << endl << endl;
            while(!good)
            {
                cout << "What do you do?" << endl;
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice<=3&&intChoice>=1)
                {
                    cout << "You take the " << dir.getItemName(items[intChoice-1]) << "!" << endl;
                    if(hero.inventory.size()<6)
                    {
                        hero.inventory.push_back(items[intChoice-1]);
                        Sleep(longWait);
                        good = 1;
                    }
                    else
                    {
                        while(!good)
                        {
                            std::system("cls");
                            replaceMenu(hero,dir,1,items[intChoice-1]);
                            strChoice = getch();
                            std::stringstream stoi(strChoice);
                            stoi >> intChoice;
                            if(intChoice>=1&&intChoice<=hero.inventory.size())
                            {
                                cout << "Replaced " << dir.getItemName(hero.inventory[intChoice-1]) << " with " << dir.getItemName(items[intChoice-1]) << "." << endl;
                                hero.inventory[intChoice-1] = items[intChoice-1];
                                good = 1;
                            }
                            else if(intChoice==0)
                            {
                                good = 1;
                            }
                            else
                            {
                                cout << "Invalid input." << endl;
                                Sleep(shortWait);
                            }
                        }
                    }
                }
                else if(intChoice==4)
                {
                    cout << "'Hah! You are a fool. You'll never see The Watcher.'" << endl << endl;
                    Sleep(longWait);
                    good = 1;
                }
                else
                {
                    cout << "Invalid input." << endl << endl;
                }
            }
            break;
        case 12:
            cout << "The hallway splits into two corridors which run parallel to each other. You see a chest in the left one." << endl << endl;
            cout << "1) " << 80 + hero.getLCK() << "% success - Go down the empty path." << endl;
            cout << "2) " << 40 + hero.getLCK() << "% success - Go down the path containing the chest." << endl << endl;
            while(!good)
            {
                cout << "What do you do?" << endl;
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice==1)
                {
                    if(rand()%100<=80+hero.getLCK())
                    {
                        cout << "You make your way down the corridor without any trouble." << endl;
                        Sleep(longWait);
                        good = 1;
                    }
                    else
                    {
                        karma += 1;
                        cout << "An arrow trap activates! You take " << hero.level*2 << " damage." << endl << endl;
                        hero.changeHP(-(hero.level*2));
                        Sleep(longWait);
                        good = 1;
                    }
                }
                else if(intChoice==2)
                {
                    if(rand()%100<=40+hero.getLCK())
                    {
                        karma -= 1;
                        cout << "You make your way down the corridor to the chest!" << endl;
                    }
                    else
                    {
                        karma += 1;
                        cout << "An arrow trap activates! You take " << hero.level*2 << " damage." << endl << endl;
                        hero.changeHP(-(hero.level*2));
                    }
                    if(rand()%2==0)
                    {
                        Sleep(shortWait);
                        cout << "Inside you see a weapon!" << endl;
                        Sleep(shortWait);
                        if(adv>10)
                            amount = itemPicker(0,10);
                        else
                            amount = itemPicker(0,adv);
                    }
                    else
                    {
                        cout << "Inside you see a suit of armor!" << endl;
                        Sleep(shortWait);
                        if(adv>10)
                            amount = itemPicker(1,10);
                        else
                            amount = itemPicker(1,adv);
                    }
                    if(hero.equipment.size()<6)
                    {
                        cout << "You got a " << dir.getItemName(amount) << "!" << endl;
                        hero.equipment.push_back(amount);
                    }
                    else
                    {
                        while(!good)
                        {
                            std::system("cls");
                            replaceMenu(hero,dir,0,amount);
                            strChoice = getch();
                            std::stringstream stoi(strChoice);
                            stoi >> intChoice;
                            if(intChoice>=1&&intChoice<=hero.equipment.size())
                            {
                                cout << "Replaced " << dir.getItemName(hero.equipment[intChoice-1]) << " with " << dir.getItemName(amount) << "." << endl;
                                hero.equipment[intChoice-1] = amount;
                                good = 1;
                            }
                            else if(intChoice==0)
                            {
                                good = 1;
                            }
                            else
                            {
                                cout << "Invalid input." << endl;
                                Sleep(shortWait);
                            }
                        }
                    }
                    Sleep(longWait);
                    good = 1;
                }
                else
                {
                    cout << "Invalid input." << endl << endl;
                }
            }
            break;
        case 13:
            karma += 2;
            cout << "A vengeful spirit descends from above, shedding an intimidating red light across the passage. 'Another greedy soul, attempting to steal power that was never meant for them... I curse thee in the name of Valentereth!'" << endl << endl;
            cout << "1) Lose " << static_cast<int>(hero.getMHP()*.25) << " HP." << endl;
            cout << "2) Lose " << static_cast<int>(hero.getMMP()*.25) << " MP." << endl << endl;
            while(!good)
            {
                cout << "What do you do?" << endl;
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice==1)
                {
                    cout << "You are enveloped in red light, and take " << static_cast<int>(hero.getMHP()*.25) << " damage." << endl;
                    hero.changeHP(-static_cast<int>(hero.getMHP()*.25));
                    Sleep(longWait);
                    good = 1;
                }
                else if(intChoice==2)
                {
                    cout << "You are enveloped in blue light, and lost " << static_cast<int>(hero.getMMP()*.25) << " MP!" << endl;
                    hero.changeMP(-static_cast<int>(hero.getMMP()*.25));
                    if(hero.getMP()<0)
                        hero.setMP(0);
                    Sleep(longWait);
                    good = 1;
                }
                else
                {
                    cout << "Invalid input." << endl << endl;
                }
            }
            break;
        case 14:
            if(hero.getDEF()>adv*3)
                checkA = "GOOD";
            else
                checkA = "X";
            cout << "As you enter the corridor, you hear an arrow trap whir into motion. From the darkness, you see a volley of arrows flying in your direction." << endl << endl;
            cout << "1) DEF " << adv*3 << " [" << checkA << "] - Let your armor deflect the arrows." << endl;
            cout << "2) " << 30 + hero.getDDG() << "% success - Try to dodge the arrows." << endl << endl;
            while(!good)
            {
                cout << "What do you do?" << endl;
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice==1)
                {
                    if(checkA=="GOOD")
                    {
                        karma -= 1;
                        cout << "The arrows bounce off of your armor, leaving you undamaged!" << endl << endl;
                        Sleep(longWait);
                        good = 1;
                    }
                    else
                    {
                        karma += 1;
                        cout << "The arrows cut through your armor, and deal " << hero.level*2 << " damage to you!" << endl << endl;
                        hero.changeHP(-(hero.level*2));
                        Sleep(longWait);
                        good = 1;
                    }
                }
                else if(intChoice==2)
                {
                    if(rand()%100<=hero.getDDG()+30)
                    {
                        karma -= 1;
                        cout << "You dodge the oncoming arrows, leaving you undamaged!" << endl << endl;
                        Sleep(longWait);
                        good = 1;
                    }
                    else
                    {
                        karma += 1;
                        cout << "The arrows pierce your side as you try to dodge them, dealing " << hero.level*2 << " damage to you!" << endl << endl;
                        hero.changeHP(-(hero.level*2));
                        Sleep(longWait);
                        good = 1;
                    }
                }
                else
                {
                    cout << "Invalid input." << endl << endl;
                }
            }
            break;
        case 15:
            karma -= 2;
            cout << "What luck! In front of you, a majestic treasure chest sits, ready to be claimed." << endl << endl;
            cout << "1) Open it." << endl;
            cout << "2) Leave it be." << endl << endl;
            while(!good)
            {
                cout << "What do you do?" << endl;
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice==1)
                {
                    cout << "You open the chest!" << endl;
                    if(rand()%2==0)
                    {
                        Sleep(shortWait);
                        cout << "Inside you see a weapon!" << endl;
                        Sleep(shortWait);
                        if(adv>=10)
                            amount = itemPicker(0,10);
                        else
                            amount = itemPicker(0,adv+1);
                    }
                    else
                    {
                        Sleep(shortWait);
                        cout << "Inside you see a suit of armor!" << endl;
                        Sleep(shortWait);
                        if(adv>=10)
                            amount = itemPicker(1,10);
                        else
                            amount = itemPicker(1,adv+1);
                    }
                    if(hero.equipment.size()<6)
                    {
                        cout << "You got a " << dir.getItemName(amount) << "!" << endl;
                        hero.equipment.push_back(amount);
                    }
                    else
                    {
                        while(!good)
                        {
                            std::system("cls");
                            replaceMenu(hero,dir,0,amount);
                            strChoice = getch();
                            std::stringstream stoi(strChoice);
                            stoi >> intChoice;
                            if(intChoice>=1&&intChoice<=hero.equipment.size())
                            {
                                cout << "Replaced " << dir.getItemName(hero.equipment[intChoice-1]) << " with " << dir.getItemName(amount) << "." << endl;
                                hero.equipment[intChoice-1] = amount;
                                good = 1;
                            }
                            else if(intChoice==0)
                            {
                                good = 1;
                            }
                            else
                            {
                                cout << "Invalid input." << endl;
                                Sleep(shortWait);
                            }
                        }
                    }
                    Sleep(longWait);
                    good = 1;
                }
                else if(intChoice==2)
                {
                    cout << "You decide not to take the treasure." << endl;
                    Sleep(longWait);
                    good = 1;
                }
                else
                {
                    cout << "Invalid input." << endl << endl;
                }
            }
            break;
        case 16:
            karma -= 2;
            cout << "A long hall stretches before you, with light shining through stained glass windows to shower the marble floor with color. A woman stands at the center of the hall, holding a set of scales. 'Balance... All things become equal over time. Good, evil... Are you here to upset that balance?'" << endl << endl;
            cout << "1) Lose 5 HP, Gain 5 MP." << endl;
            cout << "2) Lose 10 HP, Gain 10 MP." << endl;
            cout << "3) Lose 25 HP, Gain 25 MP." << endl;
            cout << "4) Avoid the woman's gaze." << endl << endl;
            while(!good)
            {
                cout << "What do you do?" << endl;
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice==1)
                {
                    cout << "You feel the energy in your body shift. 'Sometimes the small adjustments... are what keeps us steady.'" << endl;
                    hero.changeHP(-5);
                    hero.changeMP(5);
                    Sleep(longWait);
                    good = 1;
                }
                else if(intChoice==2)
                {
                    cout << "You feel the energy in your body swirl, and settle. 'Balance restored within... but will the tower survive your disruption?'" << endl;
                    hero.changeHP(-10);
                    hero.changeMP(10);
                    Sleep(longWait);
                    good = 1;
                }
                else if(intChoice==3)
                {
                    cout << "You feel the energy within you shift drastically, and are overcome with dizziness. 'Ah... a true student of order. Perhaps there is hope for us after all.'" << endl;
                    hero.changeHP(-25);
                    hero.changeMP(25);
                    Sleep(longWait);
                    good = 1;
                }
                else if(intChoice==4)
                {
                    cout << "You don't trust the woman, and leave without meeting her gaze. 'Walking in imbalance cannot last, mortal. Sooner or later you will fall...'" << endl;
                    Sleep(longWait);
                    good = 1;
                }
                else
                {
                    cout << "Invalid input." << endl << endl;
                }
            }
            break;
        case 17:
            karma -= 2;
            cout << "The hallway is overgrown here, and you feel spiritual energy in the air... You see a small creature resembling a groundhog covered in moss, with two glowing yellow antlers. In your mind, you hear it speak: 'You must be strong to have made it here, traveler. Could you lend us some of your power?'" << endl << endl;
            cout << "1) Lose 20 MP, Gain 1 MPG." << endl;
            cout << "2) Lose 50 HP, Gain 2 MPG." << endl;
            cout << "3) Offer nothing." << endl << endl;
            while(!good)
            {
                cout << "What do you do?" << endl;
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice==1)
                {
                    if(hero.getMP()>=20)
                    {
                        cout << "A small light floats from your chest toward the small creature, whose antlers glow with power. 'Oh, thank you kind traveler! Be wary of mother, she is not kind to visitors...'" << endl;
                        hero.changeMP(-20);
                        hero.growth += 1;
                        Sleep(longWait);
                        good = 1;
                    }
                    else
                    {
                        cout << "'Oh you are too kind... but you dont have that much power to give...'" << endl;
                    }
                }
                else if(intChoice==2)
                {
                    if(hero.getMP()>=50)
                    {
                        cout << "A large ball of light floats from your chest toward the small creature, whose antlers glow bright like the sun and sparkle with power. 'You are too kind, traveler! I've never known someone as nice as you to ascend the tower this far! Be wary of mother, she is not kind to visitors...'" << endl;
                        hero.changeMP(-50);
                        hero.growth += 2;
                        Sleep(longWait);
                        good = 1;
                    }
                    else
                    {
                        cout << "'Oh you are too kind... but you dont have that much power to give...'" << endl;
                    }
                }
                else if(intChoice==3)
                {
                    cout << "The creatures horns fade slightly. 'Aw... I wish you luck, traveler.'" << endl;
                    Sleep(longWait);
                    good = 1;
                }
                else
                {
                    cout << "Invalid input." << endl << endl;
                }
            }
            break;
        case 18:
            cout << "A massive beast must have rampaged through this room, leaving traces of black ooze all throughout the hall... Within one of the puddles, you see the bones of a fallen traveler, and with them a satchel of gold. The ooze looks poisonous..." << endl << endl;
            cout << "1) Lose " << 3*adv << " HP, Gain " << 10*adv << "G." << endl;
            cout << "2) Avoid the puddle of ooze." << endl << endl;
            while(!good)
            {
                cout << "What do you do?" << endl;
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice==1)
                {
                    cout << "You reach in and claim " << 10*adv << "G! The ooze burns away your flesh like acid..." << endl;
                    hero.changeHP(-(3*adv));
                    hero.gold += 10*adv;
                    Sleep(longWait);
                    good = 1;
                }
                else if(intChoice==2)
                {
                    cout << "You step over the toxic ooze, leaving the gold behind." << endl;
                    Sleep(longWait);
                    good = 1;
                }
                else
                {
                    cout << "Invalid input." << endl << endl;
                }
            }
            break;
        case 19:
            karma -= 2;
            cout << "A massive library stands before you, with books strewn all over. It seems like someone was studying the creation and combination of life... the images in these books are disturbing, and have notes scrawled along the margins. They do give you some ideas, though..." << endl << endl;
            cout << "1) Embrace the material world - Gain 10 MHP, Lose 10 MMP." << endl;
            cout << "2) Reject the material world - Gain 10 MMP, Lose 10 MHP." << endl;
            cout << "3) Leave the books." << endl << endl;
            while(!good)
            {
                cout << "What do you do?" << endl;
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice==1)
                {
                    cout << "You follow the book's instructions, finishing the ritual... you feel more anchored to the earth beneath you." << endl;
                    hero.setMHP(hero.getMHP()+10);
                    hero.setMMP(hero.getMMP()-10);
                    Sleep(longWait);
                    good = 1;
                }
                else if(intChoice==2)
                {
                    cout << "You follow the book's instructions, finishing the ritual... you feel as if you are losing grasp on the physical world." << endl;
                    hero.setMHP(hero.getMHP()-10);
                    hero.setMMP(hero.getMMP()+10);
                    Sleep(longWait);
                    good = 1;
                }
                else if(intChoice==3)
                {
                    cout << "These ideas are too dangerous... it's best not to meddle with them." << endl;
                    Sleep(longWait);
                    good = 1;
                }
                else
                {
                    cout << "Invalid input." << endl << endl;
                }
            }
            break;
            case 20:
                cout << "You step into a cold laboratory. A vat sits in its center, filled to the brim with a mysterious, murky fluid. Something about it feels... lucky?" << endl << endl;
                cout << "1) Drink a little - Lose " << hero.getMHP()/5 << " HP." << endl;
                cout << "2) Drink some - Lose " << hero.getMHP()/4 << " HP." << endl;
                cout << "3) Drink a lot - Lose " << hero.getMHP()/2 << " HP." << endl;
                cout << "4) Don't drink any." << endl << endl;
                while(!good)
                {
                    cout << "What do you do?" << endl;
                    strChoice = getch();
                    std::stringstream stoi(strChoice);
                    stoi >> intChoice;
                    if(intChoice==1)
                    {
                        cout << "You take a deep breath, then swallow a mouthful of the fluid. Good fortune may be around the corner..." << endl;
                        karma -= 2;
                        Sleep(longWait);
                        good = 1;
                    }
                    else if(intChoice==2)
                    {
                        cout << "You take a deep breath, then swallow a glass full of the fluid. 'Must have earned some karma for that...'" << endl;
                        karma -= 4;
                        Sleep(longWait);
                        good = 1;
                    }
                    else if(intChoice==3)
                    {
                        cout << "You take a deep breath, then begin guzzling the murky concoction. You feel a bit sick... but also like fate is on your side." << endl;
                        karma -= 6;
                        Sleep(longWait);
                        good = 1;
                    }
                    else if(intChoice==4)
                    {
                        cout << "Of all the things to do, why drink an unknown fluid in a lab? This is for the best. You head out of the lab." << endl;
                        Sleep(longWait);
                        good = 1;
                    }
                    else
                    {
                        cout << "Invalid input." << endl << endl;
                    }
                }
                break;
    }
    cout << endl << endl << "Press any button to continue to the next chamber." << endl;
    strChoice = getch();
}
