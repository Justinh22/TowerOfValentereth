vector<Creature> initCDir(vector<Creature> creatureDirectory)
{
    //2
    Creature Skeleton("Skeleton",2,0,12,6,65,0,0);
    creatureDirectory.push_back(Skeleton);
    Creature Bandit("Bandit",2,1,14,5,70,1,0);
    creatureDirectory.push_back(Bandit);
    Creature Goblin("Goblin",2,2,10,7,60,0,5);
    creatureDirectory.push_back(Goblin);
    //3
    Creature Ghoul("Ghoul",3,3,20,5,65,1,0);
    creatureDirectory.push_back(Ghoul);
    Creature Imp("Imp",3,4,14,9,70,0,5);
    creatureDirectory.push_back(Imp);
    Creature Spectre("Spectre",3,5,16,8,65,1,10);
    creatureDirectory.push_back(Spectre);
    //4
    Creature Assassin("Assassin",4,6,16,11,80,1,20);
    creatureDirectory.push_back(Assassin);
    Creature Giant_Spider("Giant Spider",4,7,22,8,70,1,10);
    creatureDirectory.push_back(Giant_Spider);
    Creature Barbarian("Barbarian",4,8,18,12,60,1,0);
    creatureDirectory.push_back(Barbarian);
    //5
    Creature Cultist("Cultist",5,9,20,10,80,2,10);
    creatureDirectory.push_back(Cultist);
    Creature Ogre("Ogre",5,10,28,12,60,2,0);
    creatureDirectory.push_back(Ogre);
    Creature Possessed_Armor("Possessed Armor",5,11,22,9,75,6,0);
    creatureDirectory.push_back(Possessed_Armor);
    //6
    Creature Minotaur_Skeleton("Minotaur Skeleton",6,12,30,16,70,2,10);
    creatureDirectory.push_back(Minotaur_Skeleton);
    Creature Wraith("Wraith",6,13,22,14,80,1,15);
    creatureDirectory.push_back(Wraith);
    Creature Wight("Wight",6,14,26,13,85,5,5);
    creatureDirectory.push_back(Wight);
    //7
    Creature Werewolf("Werewolf",7,15,30,20,80,4,10);
    creatureDirectory.push_back(Werewolf);
    Creature Manticore("Manticore",7,16,36,18,90,5,10);
    creatureDirectory.push_back(Manticore);
    Creature Troll("Troll",7,17,42,22,70,6,0);
    creatureDirectory.push_back(Troll);
    //8
    Creature Air_Elemental("Air Elemental",8,18,32,18,95,4,30);
    creatureDirectory.push_back(Air_Elemental);
    Creature Fire_Elemental("Fire Elemental",8,19,36,26,75,5,10);
    creatureDirectory.push_back(Fire_Elemental);
    Creature Water_Elemental("Water Elemental",8,20,37,20,85,6,20);
    creatureDirectory.push_back(Water_Elemental);
    Creature Earth_Elemental("Earth Elemental",8,21,48,22,70,9,0);
    creatureDirectory.push_back(Earth_Elemental);
    //9
    Creature Giant("Giant",9,22,54,28,70,10,0);
    creatureDirectory.push_back(Giant);
    Creature Chimera("Chimera",9,23,44,30,80,8,10);
    creatureDirectory.push_back(Chimera);
    Creature Wyvern("Wyvern",9,24,36,28,75,9,10);
    creatureDirectory.push_back(Wyvern);
    //10
    Creature Stone_Golem("Stone Golem",10,25,56,28,80,14,0);
    creatureDirectory.push_back(Stone_Golem);
    Creature Demon("Demon",10,26,32,35,90,7,15);
    creatureDirectory.push_back(Demon);
    Creature Dark_Mage("Dark Mage",10,27,26,37,85,5,15);
    creatureDirectory.push_back(Dark_Mage);
    //11
    Creature Vampire("Vampire",11,28,36,34,95,9,15);
    creatureDirectory.push_back(Vampire);
    Creature Phantom_Gladiator("Phantom Gladiator",11,29,50,32,100,10,0);
    creatureDirectory.push_back(Phantom_Gladiator);
    //12
    Creature Iron_Golem("Iron Golem",12,30,64,30,85,24,0);
    creatureDirectory.push_back(Iron_Golem);
    Creature Demon_Lord("Demon Lord",12,31,52,40,105,15,15);
    creatureDirectory.push_back(Demon_Lord);
    //13
    Creature Storm_Giant("Storm Giant",13,32,60,44,90,16,15);
    creatureDirectory.push_back(Storm_Giant);
    Creature Fallen_Angel("Fallen Angel",13,33,55,46,110,12,15);
    creatureDirectory.push_back(Fallen_Angel);
    //14
    Creature Valentium_Golem("Valentium Golem",14,34,72,34,90,30,0);
    creatureDirectory.push_back(Valentium_Golem);
    Creature Red_Dragon("Red Dragon",14,35,64,50,100,20,15);
    creatureDirectory.push_back(Red_Dragon);
    //15
    Creature Valentereth("Valentereth, the Tyrant",15,36,100,54,100,24,15);
    creatureDirectory.push_back(Valentereth);
    //16
    Creature Valentium_Titan("Valentium Titan",16,37,84,38,90,32,0);
    creatureDirectory.push_back(Valentium_Titan);
    Creature Gold_Dragon("Gold Dragon",16,38,70,56,105,24,15);
    creatureDirectory.push_back(Gold_Dragon);
    Creature Angel_of_Death("Angel of Death",16,39,62,52,120,15,20);
    creatureDirectory.push_back(Angel_of_Death);
    Creature Demon_King("Demon King",16,40,70,46,110,19,20);
    creatureDirectory.push_back(Demon_King);
    Creature Elemental_Titan("Elemental Titan",16,41,64,50,100,20,15);
    creatureDirectory.push_back(Elemental_Titan);
    Creature Hero("Hero",16,42,84,54,100,26,20);
    creatureDirectory.push_back(Hero);
    //17
    Creature Termineth("Termineth",17,43,100,80,145,60,35);
    creatureDirectory.push_back(Termineth);

    //cout << "Creature List Initialized!" << endl;

    return creatureDirectory;
}
