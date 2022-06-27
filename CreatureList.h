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
    Creature Stone_Golem("Stone Golem",10,32,56,30,80,16,0);
    creatureDirectory.push_back(Stone_Golem);
    Creature Demon("Demon",10,33,40,37,90,9,15);
    creatureDirectory.push_back(Demon);
    Creature Dark_Mage("Dark Mage",10,34,32,40,85,7,15);
    creatureDirectory.push_back(Dark_Mage);
    Creature Cyclops("Cyclops",10,35,50,36,85,14,0);
    creatureDirectory.push_back(Cyclops);
    //11
    Creature Vampire("Vampire",11,36,44,38,95,11,15);
    creatureDirectory.push_back(Vampire);
    Creature Phantom_Gladiator("Phantom Gladiator",11,37,60,35,100,12,0);
    creatureDirectory.push_back(Phantom_Gladiator);
    Creature Gorgon("Gorgon",11,38,74,33,85,14,0);
    creatureDirectory.push_back(Gorgon);
    //12
    Creature Iron_Golem("Iron Golem",12,39,80,36,90,27,0);
    creatureDirectory.push_back(Iron_Golem);
    Creature Demon_Lord("Demon Lord",12,40,68,43,115,17,15);
    creatureDirectory.push_back(Demon_Lord);
    Creature Behemoth("Behemoth",12,41,76,40,100,20,10);
    creatureDirectory.push_back(Behemoth);
    //13
    Creature Storm_Giant("Storm Giant",13,42,86,48,105,20,15);
    creatureDirectory.push_back(Storm_Giant);
    Creature Fallen_Angel("Fallen Angel",13,43,68,50,120,18,15);
    creatureDirectory.push_back(Fallen_Angel);
    Creature Pheonix("Pheonix",13,44,66,47,115,18,25);
    creatureDirectory.push_back(Pheonix);
    //14
    Creature Valentium_Golem("Valentium Golem",14,45,96,40,110,34,0);
    creatureDirectory.push_back(Valentium_Golem);
    Creature Red_Dragon("Red Dragon",14,46,80,56,125,26,15);
    creatureDirectory.push_back(Red_Dragon);
    Creature Duskwalker("Duskwalker",14,47,64,58,120,22,35);
    creatureDirectory.push_back(Duskwalker);
    //15
    Creature Valentereth("Valentereth, the Tyrant",15,48,100,64,150,32,15); //48
    creatureDirectory.push_back(Valentereth);
    //16
    Creature Valentium_Titan("Valentium Titan",16,49,112,44,120,38,0);
    creatureDirectory.push_back(Valentium_Titan);
    Creature Gold_Dragon("Gold Dragon",16,50,86,60,135,30,15);
    creatureDirectory.push_back(Gold_Dragon);
    Creature Silver_Dragon("Silver Dragon",16,51,86,56,150,26,20);
    creatureDirectory.push_back(Silver_Dragon);
    Creature Demon_King("Demon King",16,52,86,58,130,28,25);
    creatureDirectory.push_back(Demon_King);
    Creature Elemental_Titan("Elemental Titan",16,53,80,46,120,34,15);
    creatureDirectory.push_back(Elemental_Titan);
    Creature Hero("Hero",16,54,90,58,140,30,20);
    creatureDirectory.push_back(Hero);
    Creature Hydra("Hydra",16,55,96,54,125,32,10);
    creatureDirectory.push_back(Hydra);
    //17
    Creature Termineth("Termineth, the Watcher",17,56,200,80,180,56,35); //56
    creatureDirectory.push_back(Termineth);

    //Minibosses
    /*
        Can start to appear at depth 15. When one of the six minibosses are found,
        they will have their own specific lair. The miniboss' power will be determined
        by an algorithm which will scale their difficulty depending on the depth at
        which it is found. Each will provide a unique reward for defeating it, from
        stat boosts, to unique weapons, to unique spells.

        The stats given in these blocks are the stats found at depth 15, they increase
        at varying rates beyond this.
    */
    Creature Ozkoroth("Ozkoroth, the Slime-Soaked Behemoth",18,57,34,20,75,4,5);
    creatureDirectory.push_back(Ozkoroth);
    //ABILITY: Armor-Piercing Fangs - Player's defense is cut by 30%
    Creature Endrigaia("Endrigaia, the Ever-Growing",18,58,34,18,85,1,5);
    creatureDirectory.push_back(Endrigaia);
    //ABILITY: Regrowth - Endrigaia will regenerate 15% of her HP every turn
    Creature Emeritus("Emeritus, the Enlightened Sorcerer",18,59,26,22,80,2,15);
    creatureDirectory.push_back(Emeritus);
    //ABILITY: Archmage - Emeritus never misses with his spells
    Creature Stiran("Stiran, the Famed Bounty-Hunter",18,60,34,20,70,4,10);
    creatureDirectory.push_back(Stiran);
    //ABILITY: Parry - If the player misses an attack, Stiran will parry, dealing double damage if he hits
    Creature Question("?????, the Cursed Amalgamation",18,61,42,17,70,1,15);
    creatureDirectory.push_back(Question);
    //ABILITY: Absorb - Damage dealt to ????? will be reduced by 30%
    Creature Byralt("Byralt, Valentereth's Scion",18,62,30,20,90,2,20);
    creatureDirectory.push_back(Byralt);
    //ABILITY: Dark Magic - The player will lose HP equal to their level every turn in combat
    Creature Halliot("Halliot, the Ascended",18,63,38,18,80,2,5);
    creatureDirectory.push_back(Halliot);
    //ABILITY: Undying - Halliot will survive with 1 HP when reduced to 0 when HP is greater than 0, and will heal herself afterwards

    //cout << "Creature List Initialized!" << endl;

    return creatureDirectory;
}
