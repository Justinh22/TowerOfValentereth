vector<Weapon> initWDir(vector<Weapon> weaponDirectory)
{
    //WEAPONS// --Rarity, ID, STR, ACC, CRT, MD--
    //1
    Weapon Rusty_Sword("Rusty Sword","A dull blade, coated in rust.",1,0,5,65,0,0);
    weaponDirectory.push_back(Rusty_Sword);
    Weapon Wooden_Sword("Wooden Sword","A rough wooden blade.",1,1,4,70,0,0);
    weaponDirectory.push_back(Wooden_Sword);
    Weapon Rusty_Dagger("Rusty Dagger","A dull knife, coated in rust.",1,2,3,75,5,0);
    weaponDirectory.push_back(Rusty_Dagger);
    Weapon Wooden_Staff("Wooden Staff","A bent wooden staff, resembling a branch.",1,3,2,70,0,5);
    weaponDirectory.push_back(Wooden_Staff);
    //2
    Weapon Jagged_Axe("Jagged Axe","A hastily-crafted iron axe, with a sharp and jagged edge.",2,4,7,65,5,0);
    weaponDirectory.push_back(Jagged_Axe);
    Weapon Crooked_Saber("Crooked Saber","A jagged iron blade, resembling a long piece of schrapnel.",2,5,6,75,0,0);
    weaponDirectory.push_back(Crooked_Saber);
    Weapon Vicious_Pike("Vicious Pike","A long spear, with a sharp shard of iron affixed to the end.",2,6,5,80,0,0);
    weaponDirectory.push_back(Vicious_Pike);
    Weapon Crooked_Dagger("Crooked Dagger","A sharp fragment of metal, shaped into a dagger.",2,7,4,85,10,0);
    weaponDirectory.push_back(Crooked_Dagger);
    Weapon Gnarled_Rod("Gnarled Rod","A tangled wooden rod, containing a green gem at its top.",2,8,4,75,0,10);
    weaponDirectory.push_back(Gnarled_Rod);
    //3
    Weapon Iron_Axe("Iron Axe","A sturdy iron axe.",3,9,10,65,5,0);
    weaponDirectory.push_back(Iron_Axe);
    Weapon Iron_Sword("Iron Sword","A sturdy iron sword.",3,10,8,80,0,0);
    weaponDirectory.push_back(Iron_Sword);
    Weapon Iron_Spear("Iron Spear","A sturdy iron spear.",3,11,7,85,0,0);
    weaponDirectory.push_back(Iron_Spear);
    Weapon Iron_Dagger("Iron Dagger","A sturdy iron dagger.",3,12,6,90,10,0);
    weaponDirectory.push_back(Iron_Dagger);
    Weapon Woven_Staff("Woven Staff","A tall mahogany staff, woven around a sapphire.",3,13,5,80,0,15);
    weaponDirectory.push_back(Woven_Staff);
    Weapon Mana_Club("Mana Club","An iron club, with a sapphire embedded in its handle.",3,14,8,70,0,5);
    weaponDirectory.push_back(Mana_Club);
    //4
    Weapon Steel_Axe("Steel Axe","A sharp, shining steel axe.",4,15,13,70,5,0);
    weaponDirectory.push_back(Steel_Axe);
    Weapon Steel_Sword("Steel Sword","A sharp, shining steel sword.",4,16,12,80,0,0);
    weaponDirectory.push_back(Steel_Sword);
    Weapon Steel_Spear("Steel Spear","A sharp, shining steel spear.",4,17,10,85,5,0);
    weaponDirectory.push_back(Steel_Spear);
    Weapon Steel_Dagger("Steel Dagger","A sharp, shining steel dagger.",4,18,8,90,15,0);
    weaponDirectory.push_back(Steel_Dagger);
    Weapon Steel_Wand("Steel Wand","A long, shining steel wand.",4,19,7,80,0,20);
    weaponDirectory.push_back(Steel_Wand);
    Weapon Casters_Sword("Caster's Sword","A long, shining steel blade with an amethyst embedded in the hilt.",4,20,10,75,0,10);
    weaponDirectory.push_back(Casters_Sword);
    //5
    Weapon Dark_Steel_Axe("Dark Steel Axe","An axe made of a dark, menacing steel, emanating an evil aura.",5,21,16,60,15,0);
    weaponDirectory.push_back(Dark_Steel_Axe);
    Weapon Dark_Steel_Sword("Dark Steel Sword","A sword made of a dark, menacing steel, emanating an evil aura.",5,22,14,70,10,0);
    weaponDirectory.push_back(Dark_Steel_Sword);
    Weapon Dark_Steel_Spear("Dark Steel Spear","A spear made of a dark, menacing steel, emanating an evil aura.",5,23,12,75,15,0);
    weaponDirectory.push_back(Dark_Steel_Spear);
    Weapon Dark_Steel_Dagger("Dark Steel Dagger","A dagger made of a dark, menacing steel, emanating an evil aura.",5,24,10,80,25,0);
    weaponDirectory.push_back(Dark_Steel_Dagger);
    Weapon Dark_Sceptre("Dark Sceptre","A long, menacing sceptre made of a dark black metal.",5,25,7,75,10,25);
    weaponDirectory.push_back(Dark_Sceptre);
    Weapon Mana_Cleaver("Mana Cleaver","A massive dark blade with a ruby core, emanating an evil aura.",5,26,14,60,10,15);
    weaponDirectory.push_back(Mana_Cleaver);
    //6
    Weapon Golden_Axe("Golden Axe","An axe made of shimmering gold.",6,27,20,75,10,0);
    weaponDirectory.push_back(Golden_Axe);
    Weapon Golden_Sword("Golden Sword","A sword made of shimmering gold.",6,28,17,85,5,0);
    weaponDirectory.push_back(Golden_Sword);
    Weapon Golden_Spear("Golden Spear","A spear made of shimmering gold.",6,29,15,90,10,0);
    weaponDirectory.push_back(Golden_Spear);
    Weapon Golden_Dagger("Golden Dagger","A dagger made of shimmering gold.",6,30,13,95,20,0);
    weaponDirectory.push_back(Golden_Dagger);
    Weapon Golden_Staff("Golden Staff","A shining, golden staff, radiating magical energy.",6,31,10,85,0,30);
    weaponDirectory.push_back(Golden_Staff);
    Weapon Enchanted_Knife("Enchanted Knife","A shimmering, enchanted knife, radiating magical energy.",6,32,12,90,20,15);
    weaponDirectory.push_back(Enchanted_Knife);
    //7
    Weapon Jeweled_Axe("Jeweled Axe","An axe made of shining gold, with bright gemstones embedded into it.",7,33,32,55,10,0);
    weaponDirectory.push_back(Jeweled_Axe);
    Weapon Jeweled_Sword("Jeweled Sword","A sword made of shining gold, with bright gemstones embedded into it.",7,34,28,65,5,0);
    weaponDirectory.push_back(Jeweled_Sword);
    Weapon Jeweled_Spear("Jeweled Spear","A spear made of shining gold, with bright gemstones embedded into it.",7,35,25,70,10,0);
    weaponDirectory.push_back(Jeweled_Spear);
    Weapon Jeweled_Dagger("Jeweled Dagger","A dagger made of shining gold, with bright gemstones embedded into it.",7,36,22,75,20,0);
    weaponDirectory.push_back(Jeweled_Dagger);
    Weapon Jeweled_Wand("Jeweled Wand","A golden wand, encrusted with bright gemstones.",7,37,14,75,5,35);
    weaponDirectory.push_back(Jeweled_Wand);
    Weapon Magic_Gauntlet("Magic Gauntlet","A shining metal gauntlet, with a bright diamond on the back of the palm.",7,38,30,60,10,20);
    weaponDirectory.push_back(Magic_Gauntlet);
    //8
    Weapon Valentium_Axe("Valentium Axe","An axe made of a magical, indestructable metal.",8,39,30,80,15,5);
    weaponDirectory.push_back(Valentium_Axe);
    Weapon Valentium_Sword("Valentium Sword","A sword made of a magical, indestructable metal.",8,40,26,90,10,5);
    weaponDirectory.push_back(Valentium_Sword);
    Weapon Valentium_Spear("Valentium Spear","A spear made of a magical, indestructable metal.",8,41,23,95,15,5);
    weaponDirectory.push_back(Valentium_Spear);
    Weapon Valentium_Dagger("Valentium Dagger","An dagger made of a magical, indestructable metal.",8,42,20,100,25,5);
    weaponDirectory.push_back(Valentium_Dagger);
    Weapon Valentium_Sceptre("Valentium Sceptre","A sceptre made of a magical, indestructable metal.",8,43,16,90,10,40);
    weaponDirectory.push_back(Valentium_Sceptre);
    Weapon Arcane_Axe("Arcane Axe","A massive axe made of a magical, indestructable metal, emanating a powerful aura.",8,44,26,70,15,25);
    weaponDirectory.push_back(Arcane_Axe);
    //9
    Weapon Mechanical_Axe("Mechanical Axe","An axe covered in whirring gears, arcing with electricity.",9,45,28,80,35,0);
    weaponDirectory.push_back(Mechanical_Axe);
    Weapon Mechanical_Sword("Mechanical Sword","A sword covered in whirring gears, arcing with electricity.",9,46,24,90,30,0);
    weaponDirectory.push_back(Mechanical_Sword);
    Weapon Mechanical_Spear("Mechanical Spear","A spear covered in whirring gears, arcing with electricity.",9,47,21,95,35,0);
    weaponDirectory.push_back(Mechanical_Spear);
    Weapon Mechanical_Dagger("Mechanical Dagger","A dagger covered in whirring gears, arcing with electricity.",9,48,18,100,45,0);
    weaponDirectory.push_back(Mechanical_Dagger);
    Weapon Rod_of_Order("Rod of Order","A magic staff, covered in spinning gears.",9,49,18,90,20,45);
    weaponDirectory.push_back(Rod_of_Order);
    Weapon Spear_of_Storms("Spear of Storms","A spear covered in whirring gears, with an electrical core brimming with power.",9,50,23,90,30,30);
    weaponDirectory.push_back(Spear_of_Storms);
    //10
    Weapon Teratra("Teratra","A mythical axe of legend, raised from the earth.",10,51,42,75,20,5);
    weaponDirectory.push_back(Teratra);
    Weapon Pyrithia("Pyrithia","A mythical sword of legend, born from flame.",10,52,36,90,10,10);
    weaponDirectory.push_back(Pyrithia);
    Weapon Hyliat("Hyliat","A mythical spear of legend, created in the depths of the ocean.",10,53,34,95,20,10);
    weaponDirectory.push_back(Hyliat);
    Weapon Aerolinde("Aerolinde","A mythical dagger of legend, formed from the raging winds.",10,54,32,100,35,10);
    weaponDirectory.push_back(Aerolinde);
    Weapon Ordointh("Ordointh","A magical staff of legend, formed from the forces of balance and order.",10,55,20,90,10,50);
    weaponDirectory.push_back(Ordointh);
    Weapon Chaotrix("Chaotrix","A magical warhammer of legend, formed from the forces of entropy and chaos.",10,56,34,85,20,35);
    weaponDirectory.push_back(Chaotrix);

    //11: Unique
    Weapon Ozkoroths_Fang("Ozkoroth's Fang","Fang of a ravenous beast, this dagger cuts through armor. Deals damage equal to 25% of the target's max HP.",11,57,0,95,20,0);
    weaponDirectory.push_back(Ozkoroths_Fang);
    Weapon Essence_Siphon("Essence Siphon","Sceptre of an archmage. Its power is equal to your STR. Whenever damage is dealt with this weapon, the wielder gains 5 MP.",11,58,0,80,10,25);
    weaponDirectory.push_back(Essence_Siphon);

    //cout << "Weapon Directory Initialized!" << endl;

    return weaponDirectory;
}

vector<Armor> initADir(vector<Armor> armorDirectory)
{
    //ARMOR// --DEF, DDG, MPG--
    //1
    Armor Leather_Breastplate("Leather Breastplate","A tough, leather breastplate.",1,100,1,5,0);
    armorDirectory.push_back(Leather_Breastplate);
    Armor Rusty_Iron_Breastplate("Rusty Iron Breastplate","A rusted iron breastplate.",1,101,2,0,0);
    armorDirectory.push_back(Rusty_Iron_Breastplate);
    Armor Tattered_Robe("Tattered Robe","A tattered, cloth robe.",1,102,0,5,1);
    armorDirectory.push_back(Tattered_Robe);
    //2
    Armor Leather_Armor("Leather Armor","A suit of sturdy leather armor.",2,103,2,10,0);
    armorDirectory.push_back(Leather_Armor);
    Armor Rusty_Iron_Armor("Rusty Iron Armor","A suit of rusted iron armor.",2,104,3,0,0);
    armorDirectory.push_back(Rusty_Iron_Armor);
    Armor Silk_Robe("Silk Robe","A soft, silk robe.",2,105,2,5,1);
    armorDirectory.push_back(Silk_Robe);
    //3
    Armor Hide_Armor("Hide Armor","A suit of armor made from tough animal hides.",3,106,4,10,0);
    armorDirectory.push_back(Hide_Armor);
    Armor Chainmail("Chainmail","A suit of armor made from intertwined links of chains.",3,107,5,0,0);
    armorDirectory.push_back(Chainmail);
    Armor Shimmering_Robe("Shimmering Robe","A long velvet robe, that seems to shimmer magically.",3,108,2,10,2);
    armorDirectory.push_back(Shimmering_Robe);
    //4
    Armor Studded_Leather_Armor("Studded Leather Armor","A suit of leather armor, studded with steel.",4,109,6,15,0);
    armorDirectory.push_back(Studded_Leather_Armor);
    Armor Iron_Armor("Iron Armor","A suit of solid iron armor.",4,110,7,0,0);
    armorDirectory.push_back(Iron_Armor);
    Armor Enchanted_Robe("Enchanted Robe","An enchanted robe, which glows magically.",4,111,4,10,2);
    armorDirectory.push_back(Enchanted_Robe);
    //5
    Armor Light_Steel_Armor("Light Steel Armor","A suit of lightweight steel armor.",5,112,7,15,0);
    armorDirectory.push_back(Light_Steel_Armor);
    Armor Steel_Armor("Steel Armor","A suit of standard steel armor.",5,113,8,5,0);
    armorDirectory.push_back(Steel_Armor);
    Armor Heavy_Steel_Armor("Heavy Steel Armor","A suit of heavy steel armor.",5,114,9,0,0);
    armorDirectory.push_back(Heavy_Steel_Armor);
    Armor Amethyst_Robe("Amethyst Robe","A bright purple robe, pulsing with arcane energy.",5,115,5,10,3);
    armorDirectory.push_back(Amethyst_Robe);
    Armor Steel_Arcanist_Armor("Steel Arcanist Armor","A set of steel battlemage armor, with magical capabilities.",6,116,7,5,1);
    armorDirectory.push_back(Steel_Arcanist_Armor);
    //6
    Armor Light_Golden_Armor("Light Golden Armor","A suit of lightweight golden armor.",6,117,8,20,0);
    armorDirectory.push_back(Light_Golden_Armor);
    Armor Golden_Armor("Golden Armor","A suit of standard golden armor.",6,118,10,10,0);
    armorDirectory.push_back(Golden_Armor);
    Armor Heavy_Golden_Armor("Heavy Golden Armor","A suit of heavy golden armor.",6,119,12,0,0);
    armorDirectory.push_back(Heavy_Golden_Armor);
    Armor Gilded_Robe("Gilded Robe","A flowing robe sewn from golden threads, imbued with magical power.",6,120,6,15,3);
    armorDirectory.push_back(Gilded_Robe);
    Armor Golden_Arcanist_Armor("Golden Arcanist Armor","A set of golden battlemage armor, with magical capabilities.",6,121,8,10,1);
    armorDirectory.push_back(Golden_Arcanist_Armor);
    //7
    Armor Light_Jeweled_Armor("Light Jeweled Armor","A suit of lightweight golden armor embedded with shining gemstones.",7,122,10,25,0);
    armorDirectory.push_back(Light_Jeweled_Armor);
    Armor Jeweled_Armor("Jeweled Armor","A suit of standard golden armor embedded with shining gemstones.",7,123,12,15,0);
    armorDirectory.push_back(Jeweled_Armor);
    Armor Heavy_Jeweled_Armor("Heavy Jeweled Armor","A suit of heavy golden armor embedded with shining gemstones.",7,124,14,0,0);
    armorDirectory.push_back(Heavy_Jeweled_Armor);
    Armor Jeweled_Robe("Jeweled Robe","A flowing robe sewn from golden threads, with arcane gemstones embedded at the base.",8,125,7,20,4);
    armorDirectory.push_back(Jeweled_Robe);
    Armor Jeweled_Arcanist_Armor("Jeweled Arcanist Armor","A suit of jeweled golden armor, embedded with arcane gemstones.",8,126,10,15,2);
    armorDirectory.push_back(Jeweled_Arcanist_Armor);
    //8
    Armor Light_Valentium_Armor("Light Valentium Armor","A suit of lightweight Valentium armor, which pulses with magical energy.",8,127,12,30,2);
    armorDirectory.push_back(Light_Valentium_Armor);
    Armor Valentium_Armor("Valentium Armor","A suit of Valentium armor, which pulses with magical energy.",8,128,15,15,2);
    armorDirectory.push_back(Valentium_Armor);
    Armor Heavy_Valentium_Armor("Heavy Valentium Armor","A suit of heavy Valentium armor, which pulses with magical energy.",8,129,18,0,2);
    armorDirectory.push_back(Heavy_Valentium_Armor);
    Armor Valentium_Robe("Valentium Robe","A robe sewn from threads of Valentium, which pulses with magical energy.",8,130,8,25,4);
    armorDirectory.push_back(Valentium_Robe);
    Armor Valentium_Arcanist_Armor("Valentium Arcanist Armor","A set of Valentium battlemage armor, which pulses with unbridled magical energy.",8,131,12,15,2);
    armorDirectory.push_back(Valentium_Arcanist_Armor);
    //9
    Armor Light_Mechanical_Armor("Light Mechanical Armor","A suit of lightweight armor with cogs and pipes whirring along it.",9,132,13,45,0);
    armorDirectory.push_back(Light_Mechanical_Armor);
    Armor Mechanical_Armor("Mechanical Armor","A suit of armor with cogs and pipes whirring along it.",9,133,16,30,0);
    armorDirectory.push_back(Mechanical_Armor);
    Armor Heavy_Mechanical_Armor("Heavy Mechanical Armor","A suit of heavy armor with cogs and pipes whirring along it.",9,134,19,15,0);
    armorDirectory.push_back(Heavy_Mechanical_Armor);
    Armor Clockwork_Robe("Clockwork Robe","A robe sewn from threads of time itself.",9,135,10,30,5);
    armorDirectory.push_back(Clockwork_Robe);
    Armor Clockwork_Arcanist_Armor("Clockwork Arcanist Armor","A set of clockwork battlemage armor, with magical energy flowing through it like time itself.",9,136,13,30,3);
    armorDirectory.push_back(Clockwork_Arcanist_Armor);
    //10
    Armor Cloak_of_the_Whisper("Cloak of the Whisper","A cloak that envelops its wearer in shadow.",10,137,13,60,0);
    armorDirectory.push_back(Cloak_of_the_Whisper);
    Armor Plate_of_the_Vanguard("Plate of the Vanguard","A suit of regal armor worn by a hero of legend.",10,138,18,30,0);
    armorDirectory.push_back(Plate_of_the_Vanguard);
    Armor Shield_of_the_Conquerer("Shield of the Conquerer","A massive suit of heavy armor once worn by the ruler of an ancient kingdom.",10,139,24,0,0);
    armorDirectory.push_back(Shield_of_the_Conquerer);
    Armor Robe_of_the_Archmage("Robe of the Archmage","A robe that harnesses the magical power of the world.",10,140,12,30,7);
    armorDirectory.push_back(Robe_of_the_Archmage);
    Armor Helm_of_the_Ancients("Helm of the Ancients","A demigod's suit of armor, passed down from an ancient kingdom of magic.",10,141,16,25,5);
    armorDirectory.push_back(Helm_of_the_Ancients);

    //11
    Armor Mercenarys_Shield("Mercenary's Shield","Stiran's shield. Reduces incoming damage by 25%. If an enemy misses their attack against you, your next attack has the potential to deal double damage.",11,142,3,20,0);
    armorDirectory.push_back(Mercenarys_Shield);

    //cout << "Armor Directory Initialized!" << endl;

    return armorDirectory;

}

vector<Consumable> initCDir(vector<Consumable> consumableDirectory)
{
    //CONSUMABLES// --HP, MP--
    //1
    Consumable Bread("Bread","A small loaf of stale bread.",1,200,10,0);
    consumableDirectory.push_back(Bread);
    Consumable Manaberry("Mana Berry","A tiny berry, pulsing with a dim blue glow.",1,201,0,10);
    consumableDirectory.push_back(Manaberry);
    //2
    Consumable Ration("Ration","A preserved ration of food.",2,202,20,0);
    consumableDirectory.push_back(Ration);
    Consumable Mana_Gem("Mana Gem","A small violet gemstone, holding potent magical energy.",2,203,0,20);
    consumableDirectory.push_back(Mana_Gem);
    //3
    Consumable Potion_of_Healing("Potion of Healing","A potion capable of restoring life.",3,204,30,0);
    consumableDirectory.push_back(Potion_of_Healing);
    Consumable Potion_of_Calming("Potion of Calming","A potion capable of restoring magical ability.",3,205,0,30);
    consumableDirectory.push_back(Potion_of_Calming);
    //4
    Consumable Greater_Potion_of_Healing("Greater Potion of Healing","A potion capable of restoring a great amount of life.",4,206,50,0);
    consumableDirectory.push_back(Greater_Potion_of_Healing);
    Consumable Greater_Potion_of_Calming("Greater Potion of Calming","A potion capable of restoring a great amount of magical ability.",4,207,0,50);
    consumableDirectory.push_back(Greater_Potion_of_Calming);
    Consumable Potion_of_Replenishment("Potion of Replenishment","A potion capable of restoring both life and magical ability.",4,208,30,30);
    consumableDirectory.push_back(Potion_of_Replenishment);
    //5
    Consumable Potion_of_Full_Healing("Potion of Full Healing","A potion capable of restoring all life.",5,209,100,0);
    consumableDirectory.push_back(Potion_of_Full_Healing);
    Consumable Potion_of_Full_Calming("Potion of Full Calming","A potion capable of restoring all magical ability.",5,210,0,100);
    consumableDirectory.push_back(Potion_of_Full_Calming);
    Consumable Greater_Potion_of_Replenishment("Greater Potion of Replenishment","A potion capable of restoring both life and magical ability.",5,211,50,50);
    consumableDirectory.push_back(Greater_Potion_of_Replenishment);
    //Key
    Consumable Key("Key","A small, silver key.",0,212,0,0);
    consumableDirectory.push_back(Key);

    //cout << "Consumable List Initialized!" << endl;

    return consumableDirectory;
}

vector<Item> initMDir(vector<Item> maskDirectory)
{
    Item Mask_of_Glass("Mask of Glass","A smiling mask made of shimmering glass. When worn, doubles the damage dealt with strikes, but doubles the damage dealt to the wearer.",10,0);
    maskDirectory.push_back(Mask_of_Glass);

    Item Mask_of_Wrath("Mask of Wrath","An enraged mask made of searing hot stone. When worn, raises strength and crit chance by 50%, but lowers accuracy by 10.",10,1);
    maskDirectory.push_back(Mask_of_Wrath);

    Item Mask_of_Darkness("Mask of Darkness","A screaming mask made of dark obsidian. When worn, spells are amplified by 50%, but enemies cannot be identified.",10,2);
    maskDirectory.push_back(Mask_of_Darkness);

    Item Mask_of_Arcana("Mask of Arcana","A peaceful mask made of smooth marble. When worn, increases mana regeneration by 5, but all strikes deal half damage.",10,3);
    maskDirectory.push_back(Mask_of_Arcana);

    Item Mask_of_Steel("Mask of Steel","A stoic mask made of hardened metal. When worn, reduces damage taken from attacks by 30%, but enemies never miss.",10,4);
    maskDirectory.push_back(Mask_of_Steel);

    Item Mask_of_Whispers("Mask of Whispers","A transparent mask made of invisible threads. When worn, increases chance to dodge by 25% and increases dodge gained on level up, but enemies deal 150% damage to the wearer.",10,5);
    maskDirectory.push_back(Mask_of_Whispers);

    Item Mask_of_Beasts("Mask of Beasts","A ravenous mask made of bloodied pelts. When worn, increases strength by 50%, but the wearer must strike each round of combat.",10,6);
    maskDirectory.push_back(Mask_of_Beasts);

    Item Mask_of_Souls("Mask of Souls","An expressionless mask made of light itself. When worn, triples the amount of EXP earned by the wearer, but restricts the wearer from equipping any armor.",10,7);
    maskDirectory.push_back(Mask_of_Souls);

    return maskDirectory;
}

vector<Ring> initRGDir(vector<Ring> ringDirectory)
{
    Ring Minor_Regeneration("Ring of Minor Regeneration","A ring capable of regenerating a small amount of the wearer's vitality over time.",1,400,0,2,0);
    ringDirectory.push_back(Minor_Regeneration);
    Ring Minor_Conservation("Ring of Minor Conservation","A ring that grants the wearer a slight chance of conserving the mana used after casting a spell.",1,401,10,0,0);
    ringDirectory.push_back(Minor_Conservation);
    Ring Minor_Bravery("Ring of Minor Bravery","A ring that grants the wearer a slight chance of negating incoming damage.",1,402,10,0,0);
    ringDirectory.push_back(Minor_Bravery);
    Ring Minor_Leeching("Ring of Minor Leeching","A ring that grants the wearer a slight chance of recovering health equal to half the amount of damage dealt.",1,403,10,0,0);
    ringDirectory.push_back(Minor_Leeching);
    Ring Minor_Vengeance("Ring of Minor Vengeance","A ring that deals additional damage equal to 15% of the wearer's damage taken when attacking an enemy.",1,404,0,0,0);
    ringDirectory.push_back(Minor_Vengeance);
    Ring Minor_Sight("Ring of Minor Sight","A ring that grants the wearer a slight chance of ensuring a successful hit when attacking.",1,405,10,0,0);
    ringDirectory.push_back(Minor_Sight);
    Ring Minor_Piercing("Ring of Minor Piercing","A ring that grants the wearer a slight chance of cutting a foe's defense in half.",1,406,10,0,0);
    ringDirectory.push_back(Minor_Piercing);
    Ring Minor_Overcharging("Ring of Minor Overcharging","A ring that grants the wearer a slight chance of increasing attack spell potency by 50%.",1,407,10,0,0);
    ringDirectory.push_back(Minor_Overcharging);
    Ring Minor_Reflection("Ring of Minor Reflection","A ring that grants the wearer a slight chance of dealing damage dealt to the wearer back to the enemy.",1,408,10,0,0);
    ringDirectory.push_back(Minor_Reflection);
    Ring Minor_Fury("Ring of Minor Fury","A ring that deals an additional 1 damage to the enemy with each consecutive hit.",1,409,0,0,0);
    ringDirectory.push_back(Minor_Fury);

    Ring Regeneration("Ring of Regeneration","A ring capable of regenerating a moderate amount of the wearer's vitality over time.",2,410,0,4,0);
    ringDirectory.push_back(Regeneration);
    Ring Conservation("Ring of Conservation","A ring that grants the wearer a chance of conserving the mana used after casting a spell.",2,411,20,0,0);
    ringDirectory.push_back(Conservation);
    Ring Bravery("Ring of Bravery","A ring that grants the wearer a chance of negating incoming damage.",2,412,20,0,0);
    ringDirectory.push_back(Bravery);
    Ring Leeching("Ring of Leeching","A ring that grants the wearer a chance of recovering health equal to half the amount of damage dealt.",2,413,20,0,0);
    ringDirectory.push_back(Leeching);
    Ring Vengeance("Ring of Vengeance","A ring that deals additional damage equal to 30% of the wearer's damage taken when attacking an enemy.",2,414,0,0,0);
    ringDirectory.push_back(Vengeance);
    Ring Sight("Ring of Sight","A ring that grants the wearer a chance of ensuring a successful hit when attacking.",2,415,20,0,0);
    ringDirectory.push_back(Sight);
    Ring Piercing("Ring of Piercing","A ring that grants the wearer a chance of cutting a foe's defense in half.",2,416,20,0,0);
    ringDirectory.push_back(Piercing);
    Ring Overcharging("Ring of Overcharging","A ring that grants the wearer a chance of increasing attack spell potency by 50%.",2,417,20,0,0);
    ringDirectory.push_back(Overcharging);
    Ring Reflection("Ring of Reflection","A ring that grants the wearer a chance of dealing damage dealt to the wearer back to the enemy.",2,418,20,0,0);
    ringDirectory.push_back(Reflection);
    Ring Fury("Ring of Fury","A ring that deals an additional 2 damage to the enemy with each consecutive hit.",2,419,0,0,0);
    ringDirectory.push_back(Fury);
    Ring Mana_Regeneration("Ring of Mana Regeneration","A ring capable of regenerating a small amount of the wearer's magical ability over time.",2,420,0,0,1);
    ringDirectory.push_back(Mana_Regeneration);
    Ring Blitzing("Ring of Blitzing","A ring that grants the wearer a slight chance of taking a second turn in combat before the enemy can take one.",2,421,10,0,0);
    ringDirectory.push_back(Blitzing);

    Ring Major_Regeneration("Ring of Major Regeneration","A ring capable of regenerating a large amount of the wearer's vitality over time.",3,422,0,6,0);
    ringDirectory.push_back(Major_Regeneration);
    Ring Major_Conservation("Ring of Major Conservation","A ring that grants the wearer a significant chance of conserving the mana used after casting a spell.",3,423,30,0,0);
    ringDirectory.push_back(Major_Conservation);
    Ring Major_Bravery("Ring of Major Bravery","A ring that grants the wearer a significant chance of negating incoming damage.",3,424,30,0,0);
    ringDirectory.push_back(Major_Bravery);
    Ring Major_Leeching("Ring of Major Leeching","A ring that grants the wearer a significant chance of recovering health equal to half the amount of damage dealt.",3,425,30,0,0);
    ringDirectory.push_back(Major_Leeching);
    Ring Major_Vengeance("Ring of Major Vengeance","A ring that deals additional damage equal to 50% of the wearer's damage taken when attacking an enemy.",3,426,0,0,0);
    ringDirectory.push_back(Major_Vengeance);
    Ring Major_Sight("Ring of Major Sight","A ring that grants the wearer a significant chance of ensuring a successful hit when attacking.",3,427,30,0,0);
    ringDirectory.push_back(Major_Sight);
    Ring Major_Piercing("Ring of Major Piercing","A ring that grants the wearer a significant chance of cutting a foe's defense in half.",3,428,30,0,0);
    ringDirectory.push_back(Major_Piercing);
    Ring Major_Overcharging("Ring of Major Overcharging","A ring that grants the wearer a significant chance of increasing attack spell potency by 50%.",3,429,30,0,0);
    ringDirectory.push_back(Major_Overcharging);
    Ring Major_Reflection("Ring of Major Reflection","A ring that grants the wearer a significant chance of dealing damage dealt to the wearer back to the enemy.",3,430,30,0,0);
    ringDirectory.push_back(Major_Reflection);
    Ring Major_Fury("Ring of Major Fury","A ring that deals an additional 3 damage to the enemy with each consecutive hit.",3,431,0,0,0);
    ringDirectory.push_back(Major_Fury);
    Ring Major_Mana_Regeneration("Ring of Major Mana Regeneration","A ring capable of regenerating a small amount of the wearer's magical ability over time.",3,432,0,0,2);
    ringDirectory.push_back(Major_Mana_Regeneration);
    Ring Major_Blitzing("Ring of Major Blitzing","A ring that grants the wearer a chance of taking a second turn in combat before the enemy can take one.",3,433,15,0,0);
    ringDirectory.push_back(Major_Blitzing);
    Ring Miracles("Ring of Miracles","A ring that will save the wearer from a killing blow once per combat, leaving them with 1 HP.",3,434,0,0,0);
    ringDirectory.push_back(Miracles);

    return ringDirectory;
}
