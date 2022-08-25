void encounterHandler(Player &hero, Directory dir, int adv, vector<bool> &randEncStatus)
{
    std::system("cls");
    int encounter = rand()%6;
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
            encounter = rand()%6;
        timeout++;
    } while(!good);
    randEncStatus[encounter] = 1;
    good = 0;

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
                        cout << "You manage to break free of their hold, and sprint down the corridor away from them!" << endl;
                        Sleep(2500);
                        good = 1;
                    }
                    else
                    {
                        cout << "The thief grabs you and cuts you with their knife. 'You're not going anywhere, pal!' You take " << hero.level << " damage!" << endl << endl;
                        hero.changeHP(-hero.level);
                        Sleep(1000);
                    }
                }
                else if(intChoice==2)
                {
                    if(rand()%100<=40+hero.getSTR())
                    {
                        cout << "You brandish your weapon toward them, and before you can say a word the thief runs off." << endl;
                        Sleep(2500);
                        good = 1;
                    }
                    else
                    {
                        cout << "The thief laughs at your attempt to intimidate them, and cuts you with their knife. You take " << hero.level << " damage!" << endl << endl;
                        hero.changeHP(-hero.level);
                        Sleep(1000);
                    }
                }
                else if(intChoice==3)
                {
                    cout << "You fork over " << amount << " gold to the thief, and they let you pass." << endl;
                    hero.gold -= amount;
                    good = 1;
                    Sleep(2000);
                }
                else
                {
                    cout << "Invalid input." << endl << endl;
                }
            }
            break;
        case 1:
            cout << "A radiant spirit descends from above, shedding golden light across the passage. 'Foolhardy adventurer... you know not the cruel truth of this place. You will need all the help you can get to escape... Please accept my blessing.'" << endl << endl;
            cout << "1) Restore " << hero.getMHP()*.5 << " HP." << endl;
            cout << "2) Restore " << hero.getMMP()*.5 << " MP." << endl << endl;
            while(!good)
            {
                cout << "What do you do?" << endl;
                strChoice = getch();
                std::stringstream stoi(strChoice);
                stoi >> intChoice;
                if(intChoice==1)
                {
                    cout << "You are enveloped in pink light, and are healed for " << hero.getMHP()*.5 << " HP!" << endl;
                    hero.changeHP(hero.getMHP()*.5);
                    if(hero.getHP()>hero.getMHP())
                        hero.setHP(hero.getMHP());
                    Sleep(2500);
                    good = 1;
                }
                else if(intChoice==2)
                {
                    cout << "You are enveloped in violet light, and are restored for " << hero.getMMP()*.5 << " MP!" << endl;
                    hero.changeMP(hero.getMMP()*.5);
                    if(hero.getMP()>hero.getMMP())
                        hero.setMP(hero.getMMP());
                    Sleep(2500);
                    good = 1;
                }
                else
                {
                    cout << "Invalid input." << endl << endl;
                }
            }
            break;
        case 2:
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
                        Sleep(2500);
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
                    Sleep(2500);
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
                        cout << "You lift a few coins from a small coinpurse in their pocket. They likely won't even know they're gone..." << endl;
                        amount = ((rand()%10)*hero.level)+1;
                        Sleep(1000);
                        cout << "You got " << amount << " gold!" << endl;
                        hero.gold += amount;
                    }
                    else
                    {
                        cout << "The figure wakes up with your hand in their pocket, and swings a blade at you! You hurry away from them." << endl;
                        amount = ((rand()%5)*hero.level)+1;
                        Sleep(1000);
                        cout << "You take " << amount << " damage!" << endl;
                        hero.changeHP(-amount);
                    }
                    Sleep(2500);
                    good = 1;
                }
                else if(intChoice==2)
                {
                    if(rand()%100<=30+hero.getDDG())
                    {
                        cout << "You quietly slide a ring off of one of their fingers. They certainly won't need it now..." << endl;
                        amount = itemPicker(4,1);
                        Sleep(1000);
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
                                    Sleep(2000);
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
                                    Sleep(1000);
                                }
                            }
                        }
                    }
                    else
                    {
                        cout << "The figure wakes up with your hand around their ring, and swings a blade at you! You hurry away from them." << endl;
                        amount = ((rand()%5)*hero.level)+1;
                        Sleep(1000);
                        cout << "You take " << amount << " damage!" << endl;
                        hero.changeHP(-amount);
                    }
                    Sleep(2500);
                    good = 1;
                }
                else if(intChoice==3)
                {
                    if(rand()%100<=70+hero.getLCK())
                    {
                        cout << "You shake the figure and they jolt awake. After a moment of shock, they jump to their feet." << endl;
                        Sleep(1000);
                        if(rand()%2==0)
                        {
                            cout << "They run off down the corridor, out of sight.";
                        }
                        else
                        {
                            cout << "'Thank you... I don't know how long I've been out. Here, take this.'" << endl;
                            Sleep(1000);
                            amount = ((rand()%10)*(hero.level+1))+1;
                            cout << "You received " << amount << " gold!" << endl;
                            hero.gold += amount;
                        }
                    }
                    else
                    {
                        cout << "The figure doesn't even stir. You make your way onward." << endl;
                    }
                    Sleep(2500);
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
                        cout << "You break down the wall!" << endl;
                        Sleep(1000);
                        if(rand()%2==0)
                        {
                            cout << "Behind it, you see a weapon on a pedestal." << endl;
                            Sleep(1000);
                            if(adv>10)
                                amount = itemPicker(0,10);
                            else
                                amount = itemPicker(0,adv);
                        }
                        else
                        {
                            cout << "Behind it, you see a suit of armor on a pedestal." << endl;
                            Sleep(1000);
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
                                    Sleep(2000);
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
                                    Sleep(1000);
                                }
                            }
                        }
                    }
                    else
                    {
                        cout << "As hard as you try, the wall stays standing." << endl << endl;
                        continue;
                    }
                    Sleep(2000);
                    good = 1;
                }
                else if(intChoice==3)
                {
                    cout << "You decide to leave it be, and walk toward the next chamber." << endl;
                    Sleep(2000);
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
                        if(intChoice==1)
                            cout << "You shatter the ice!" << endl;
                        else
                            cout << "The ice melts in the flames!" << endl;
                        Sleep(1000);
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
                                    Sleep(2000);
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
                                    Sleep(1000);
                                }
                            }
                        }
                    }
                    else
                    {
                        cout << "The ice is still frozen thick around the armor." << endl << endl;
                        continue;
                    }
                    Sleep(2500);
                    good = 1;
                }
                else if(intChoice==3)
                {
                    cout << "You decide to leave it be, and walk toward the next chamber." << endl;
                    Sleep(2500);
                    good = 1;
                }
                else
                {
                    cout << "Invalid input." << endl << endl;
                }
            }
            break;
        case 6:

            break;
        case 7:

            break;
        case 8:

            break;
        case 9:

            break;
        case 10:

            break;
        case 11:

            break;
        case 12:

            break;
        case 13:

            break;
        case 14:

            break;
        case 15:

            break;
        case 16:

            break;
        case 17:

            break;
        case 18:

            break;
        case 19:

            break;
    }
}
