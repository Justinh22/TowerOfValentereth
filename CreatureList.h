vector<Creature> initCDir(vector<Creature> creatureDirectory)
{ //HP, ATK, ACC, DEF, DDG
    //2
    Creature Skeleton("Skeleton",2,0,12,6,65,0,0);
    creatureDirectory.push_back(Skeleton);
    Creature Bandit("Bandit",2,1,14,5,70,1,0);
    creatureDirectory.push_back(Bandit);
    Creature Goblin("Goblin",2,2,10,7,60,0,5);
    creatureDirectory.push_back(Goblin);
    Creature Slime("Slime",2,3,16,4,65,0,5);
    creatureDirectory.push_back(Slime);
    //3
    Creature Ghoul("Ghoul",3,4,20,5,65,1,0);
    creatureDirectory.push_back(Ghoul);
    Creature Imp("Imp",3,5,14,9,70,0,5);
    creatureDirectory.push_back(Imp);
    Creature Spectre("Spectre",3,6,16,8,65,1,10);
    creatureDirectory.push_back(Spectre);
    Creature Kobold("Kobold",3,7,16,7,65,2,5);
    creatureDirectory.push_back(Kobold);
    //4
    Creature Assassin("Assassin",4,8,16,11,80,1,20);
    creatureDirectory.push_back(Assassin);
    Creature Giant_Spider("Giant Spider",4,9,22,8,70,1,10);
    creatureDirectory.push_back(Giant_Spider);
    Creature Barbarian("Barbarian",4,10,18,12,60,1,0);
    creatureDirectory.push_back(Barbarian);
    Creature Harpy("Harpy",4,11,16,8,90,0,25);
    creatureDirectory.push_back(Harpy);
    //5
    Creature Cultist("Cultist",5,12,20,10,80,2,10);
    creatureDirectory.push_back(Cultist);
    Creature Ogre("Ogre",5,13,28,12,60,2,0);
    creatureDirectory.push_back(Ogre);
    Creature Possessed_Armor("Possessed Armor",5,14,22,9,75,6,0);
    creatureDirectory.push_back(Possessed_Armor);
    Creature Banshee("Banshee",5,15,22,12,75,1,15);
    creatureDirectory.push_back(Banshee);
    //6
    Creature Minotaur_Skeleton("Minotaur Skeleton",6,16,30,16,70,2,10);
    creatureDirectory.push_back(Minotaur_Skeleton);
    Creature Wraith("Wraith",6,17,22,14,80,1,15);
    creatureDirectory.push_back(Wraith);
    Creature Wight("Wight",6,18,26,13,85,5,5);
    creatureDirectory.push_back(Wight);
    Creature Wyrm("Wyrm",6,19,28,15,75,1,25);
    creatureDirectory.push_back(Wyrm);
    //7
    Creature Werewolf("Werewolf",7,20,30,20,80,4,10);
    creatureDirectory.push_back(Werewolf);
    Creature Manticore("Manticore",7,21,36,18,90,5,10);
    creatureDirectory.push_back(Manticore);
    Creature Troll("Troll",7,22,42,22,70,6,0);
    creatureDirectory.push_back(Troll);
    Creature Oni("Oni",7,23,28,24,85,2,5);
    creatureDirectory.push_back(Oni);
    //8
    Creature Air_Elemental("Air Elemental",8,24,32,18,95,4,30);
    creatureDirectory.push_back(Air_Elemental);
    Creature Fire_Elemental("Fire Elemental",8,25,36,26,75,5,10);
    creatureDirectory.push_back(Fire_Elemental);
    Creature Water_Elemental("Water Elemental",8,26,37,20,85,6,20);
    creatureDirectory.push_back(Water_Elemental);
    Creature Earth_Elemental("Earth Elemental",8,27,48,22,70,9,0);
    creatureDirectory.push_back(Earth_Elemental);
    //9
    Creature Giant("Giant",9,28,54,28,70,10,0);
    creatureDirectory.push_back(Giant);
    Creature Chimera("Chimera",9,29,44,30,80,8,10);
    creatureDirectory.push_back(Chimera);
    Creature Wyvern("Wyvern",9,30,36,28,75,9,10);
    creatureDirectory.push_back(Wyvern);
    Creature Basilisk("Basilisk",9,31,40,32,75,12,5);
    creatureDirectory.push_back(Basilisk);
    //10
    Creature Stone_Golem("Stone Golem",10,32,56,28,80,14,0);
    creatureDirectory.push_back(Stone_Golem);
    Creature Demon("Demon",10,33,32,35,90,7,15);
    creatureDirectory.push_back(Demon);
    Creature Dark_Mage("Dark Mage",10,34,26,37,85,5,15);
    creatureDirectory.push_back(Dark_Mage);
    Creature Cyclops("Cyclops",10,35,44,34,85,11,0);
    creatureDirectory.push_back(Cyclops);
    //11
    Creature Vampire("Vampire",11,36,36,34,95,9,15);
    creatureDirectory.push_back(Vampire);
    Creature Phantom_Gladiator("Phantom Gladiator",11,37,50,32,100,10,0);
    creatureDirectory.push_back(Phantom_Gladiator);
    Creature Gorgon("Gorgon",11,38,64,30,85,12,0);
    creatureDirectory.push_back(Gorgon);
    //12
    Creature Iron_Golem("Iron Golem",12,39,64,30,85,24,0);
    creatureDirectory.push_back(Iron_Golem);
    Creature Demon_Lord("Demon Lord",12,40,52,40,105,15,15);
    creatureDirectory.push_back(Demon_Lord);
    Creature Behemoth("Behemoth",12,41,60,36,90,18,10);
    creatureDirectory.push_back(Behemoth);
    //13
    Creature Storm_Giant("Storm Giant",13,42,60,44,90,16,15);
    creatureDirectory.push_back(Storm_Giant);
    Creature Fallen_Angel("Fallen Angel",13,43,55,46,110,12,15);
    creatureDirectory.push_back(Fallen_Angel);
    Creature Pheonix("Pheonix",13,44,58,44,100,13,25);
    creatureDirectory.push_back(Pheonix);
    //14
    Creature Valentium_Golem("Valentium Golem",14,45,72,34,90,30,0);
    creatureDirectory.push_back(Valentium_Golem);
    Creature Red_Dragon("Red Dragon",14,46,64,50,100,20,15);
    creatureDirectory.push_back(Red_Dragon);
    Creature Duskwalker("Duskwalker",14,47,50,52,100,14,35);
    creatureDirectory.push_back(Duskwalker);
    //15
    Creature Valentereth("Valentereth, the Tyrant",15,48,100,54,100,24,15); //36
    creatureDirectory.push_back(Valentereth);
    //16
    Creature Valentium_Titan("Valentium Titan",16,49,84,38,90,32,0);
    creatureDirectory.push_back(Valentium_Titan);
    Creature Gold_Dragon("Gold Dragon",16,50,70,56,105,24,15);
    creatureDirectory.push_back(Gold_Dragon);
    Creature Angel_of_Death("Angel of Death",16,51,62,52,120,15,20);
    creatureDirectory.push_back(Angel_of_Death);
    Creature Demon_King("Demon King",16,52,70,46,110,19,20);
    creatureDirectory.push_back(Demon_King);
    Creature Elemental_Titan("Elemental Titan",16,53,64,50,100,20,15);
    creatureDirectory.push_back(Elemental_Titan);
    Creature Hero("Hero",16,54,84,54,100,26,20);
    creatureDirectory.push_back(Hero);
    Creature Hydra("Hydra",16,55,80,50,100,30,10);
    creatureDirectory.push_back(Hydra);
    //17
    Creature Termineth("Termineth",17,56,100,80,145,60,35); //43
    creatureDirectory.push_back(Termineth);

    //cout << "Creature List Initialized!" << endl;

    return creatureDirectory;
}
