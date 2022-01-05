vector<Feature> initFDir(vector<Feature> featureDirectory)
{ //1: Weapon, 2: Armor, 3: Consumable, 4: Spell
    Feature Torches("torch","The torch glows brightly on the wall.",0,0); //0
    Torches.addKey("torch");
    Torches.addKey("torches");
    Torches.addKey("sconce");
    featureDirectory.push_back(Torches);

    Feature Candelabra("candelabra","The candelabra is formed from bone. It almost seems like the candles grew from it....",0,0); //1
    Candelabra.addKey("candelabra");
    Candelabra.addKey("light");
    featureDirectory.push_back(Candelabra);

    Feature Cobblestones("cobblestones","Stones are wedged in next to each other, forming a solid floor.",3,1); //2
    Cobblestones.addKey("stone");
    Cobblestones.addKey("stones");
    Cobblestones.addKey("cobblestone");
    Cobblestones.addKey("cobblestones");
    Cobblestones.addKey("floor");
    Cobblestones.addKey("ground");
    featureDirectory.push_back(Cobblestones);

    Feature Dirt("dirt","Soft dirt covers the floor of the room, with some mounds of it piled at the sides.",3,1); //3
    Dirt.addKey("dirt");
    Dirt.addKey("mounds");
    Dirt.addKey("floor");
    Dirt.addKey("earth");
    Dirt.addKey("ground");
    Dirt.addKey("piles");
    featureDirectory.push_back(Dirt);

    Feature Windows("windows","Through the windows you can see the inky darkness of the night, illuminated by flashes of lightning.",0,0); //4
    Windows.addKey("windows");
    Windows.addKey("window");
    Windows.addKey("sky");
    Windows.addKey("lightning");
    Windows.addKey("flash");
    Windows.addKey("flashes");
    Windows.addKey("outside");
    Windows.addKey("darkness");
    featureDirectory.push_back(Windows);

    Feature Whispers("whispers","The whispers faintly sound like threats, and pleas for help...",0,0); //5
    Whispers.addKey("whispers");
    Whispers.addKey("whispering");
    Whispers.addKey("voice");
    Whispers.addKey("voices");
    featureDirectory.push_back(Whispers);

    Feature Silhouette("silhouette","The silhouette glared back at you for just a moment, before dashing out of the room.",0,0); //6
    Silhouette.addKey("silhouette");
    Silhouette.addKey("silhouettes");
    Silhouette.addKey("shadow");
    Silhouette.addKey("shadows");
    Silhouette.addKey("figure");
    Silhouette.addKey("figures");
    Silhouette.addKey("woman");
    featureDirectory.push_back(Silhouette);

    Feature Voice("voice","The voice sounds like that of a deity, booming down from above.",0,0); //7
    Voice.addKey("voice");
    Voice.addKey("voices");
    Voice.addKey("talking");
    Voice.addKey("speaking");
    Voice.addKey("sound");
    featureDirectory.push_back(Voice);

    Feature Dark_Walls("walls","Coming close to the walls, you can see stone bricks along them.",3,2); //8
    Dark_Walls.addKey("walls");
    Dark_Walls.addKey("wall");
    Dark_Walls.addKey("dark walls");
    Dark_Walls.addKey("dark wall");
    Dark_Walls.addKey("bricks");
    Dark_Walls.addKey("brick");
    Dark_Walls.addKey("stone");
    Dark_Walls.addKey("stones");
    featureDirectory.push_back(Dark_Walls);

    Feature Candles("candles","Small, wax candles, emitting a dim light.",0,0); //9
    Candles.addKey("candles");
    Candles.addKey("candle");
    Candles.addKey("light");
    Candles.addKey("lights");
    Candles.addKey("floating candles");
    Candles.addKey("floating candle");
    featureDirectory.push_back(Candles);

    Feature Stones("stones","Loose stones form the walls of the room.",3,1); //10
    Stones.addKey("stones");
    Stones.addKey("stone");
    Stones.addKey("cracks");
    Stones.addKey("crack");
    Stones.addKey("walls");
    Stones.addKey("wall");
    featureDirectory.push_back(Stones);

    Feature Coffins("coffins","The coffins are etched with names you don't recognize...",1,2); //11
    Coffins.addKey("coffins");
    Coffins.addKey("coffin");
    Coffins.addKey("niche");
    Coffins.addKey("niches");
    featureDirectory.push_back(Coffins);

    Feature Suit_of_Armor("armor","The suits of dark, rusted armor stand vigilant on either side of the chamber.",2,2); //12
    Suit_of_Armor.addKey("armor");
    Suit_of_Armor.addKey("suit of armor");
    Suit_of_Armor.addKey("suits of armor");
    Suit_of_Armor.addKey("suit");
    Suit_of_Armor.addKey("suits");
    featureDirectory.push_back(Suit_of_Armor);

    Feature Altar("altar","The stone altar has runes etched into it, and some candles atop it, now soaked in blood.",1,1); //13
    Altar.addKey("altar");
    Altar.addKey("stone altar");
    Altar.addKey("pedestal");
    featureDirectory.push_back(Altar);

    Feature Blood("blood","Dark red blood lies in a puddle...",0,0); //14
    Blood.addKey("blood");
    Blood.addKey("puddle of blood");
    Blood.addKey("blood puddle");
    Blood.addKey("puddle");
    Blood.addKey("kool-aid");
    featureDirectory.push_back(Blood);

    Feature Runes("runes","The runes appear to be from an ancient divine language, now lost to time...",4,2); //15
    Runes.addKey("runes");
    Runes.addKey("rune");
    Runes.addKey("glyphs");
    Runes.addKey("glyph");
    Runes.addKey("runes and glyphs");
    Runes.addKey("symbols");
    featureDirectory.push_back(Runes);

    Feature Mosaic("mosaic","The metal forms the shape of a threatening bat, which shimmers in the dim light...",0,0); //16
    Mosaic.addKey("mosaic");
    Mosaic.addKey("metal");
    Mosaic.addKey("bat");
    Mosaic.addKey("bat mosaic");
    featureDirectory.push_back(Mosaic);

    Feature Sigil("sigil","You recognize the sigil as belonging to the Tyrant, Valentereth.",4,2); //17
    Sigil.addKey("sigil");
    Sigil.addKey("symbol");
    featureDirectory.push_back(Sigil);

    Feature Bats("bats","The bats fly over your head, and out the door behind you.",0,0); //18
    Bats.addKey("bats");
    Bats.addKey("bat");
    Bats.addKey("spooky birds");
    featureDirectory.push_back(Bats);

    Feature StonePedestal("pedestal","Roughly carved stone pedestals.",3,1); //19
    StonePedestal.addKey("pedestal");
    StonePedestal.addKey("pedestals");
    StonePedestal.addKey("stone pedestal");
    StonePedestal.addKey("stone pedestals");
    featureDirectory.push_back(StonePedestal);

    Feature Bones("bones","A pile of scattered bones.",3,2); //20
    Bones.addKey("bones");
    Bones.addKey("bone");
    Bones.addKey("bone pile");
    Bones.addKey("bone piles");
    featureDirectory.push_back(Bones);

    Feature StoneStatue("statue","A serene stone statue of a mythical beast.\nAs you approach it, you hear a voice in your head; 'BEGONE HUMAN. OR FACE THE WRATH OF VALENTERETH HERSELF.'",0,0); //21
    StoneStatue.addKey("statue");
    StoneStatue.addKey("stone statue");
    StoneStatue.addKey("beast");
    StoneStatue.addKey("beast statue");
    featureDirectory.push_back(StoneStatue);

    Feature BlackSlime("slime","A thick black slime. If you listen close enough, it even has a heartbeat.",3,1); //22
    BlackSlime.addKey("slime");
    BlackSlime.addKey("black slime");
    BlackSlime.addKey("ooze");
    BlackSlime.addKey("black ooze");
    featureDirectory.push_back(BlackSlime);

    Feature SingleCoffin("coffin","You recognize the name on the coffin... it was someone who had ventured into the tower before you.\nBut when you look inside the coffin, they look nothing like what they once did...",1,2); //23
    SingleCoffin.addKey("coffin");
    SingleCoffin.addKey("body");
    featureDirectory.push_back(SingleCoffin);

    Feature Skeleton("skeleton","The full skeleton of a human man.",1,2); //24
    Skeleton.addKey("skeleton");
    Skeleton.addKey("skeletons");
    Skeleton.addKey("bones");
    Skeleton.addKey("bone");
    Skeleton.addKey("man");
    Skeleton.addKey("human skeleton");
    Skeleton.addKey("spooky scary skeleton");
    featureDirectory.push_back(Skeleton);

    Feature Messages("messages","Messages are scrawled into the stone wall. The ones you can make out say 'TRAPPED', 'CURSED', 'NO ESCAPE', and 'DON'T INHERIT THE THRONE'",0,0); //25
    Messages.addKey("messages");
    Messages.addKey("writing");
    Messages.addKey("etchings");
    Messages.addKey("message");
    Messages.addKey("wall");
    Messages.addKey("walls");
    featureDirectory.push_back(Messages);

    Feature Marble("marble","The walls are carved from a shimmering white marble.",0,0); //26
    Marble.addKey("marble");
    Marble.addKey("marble walls");
    Marble.addKey("wall");
    Marble.addKey("walls");
    featureDirectory.push_back(Marble);

    Feature Book("book","On the cover of the book is written 'SUCCESSORS'. Inside is a list of names, and at the bottom of it is your name...",0,0); //27
    Book.addKey("book");
    Book.addKey("pedestal");
    Book.addKey("marble pedestal");
    Book.addKey("book on pedestal");
    featureDirectory.push_back(Book);

    Feature Chains("chains","Rusty iron chains, affixed to the stone.",0,0); //28
    Chains.addKey("chain");
    Chains.addKey("chains");
    Chains.addKey("shackles");
    featureDirectory.push_back(Chains);

    Feature StoneWall("wall","A smooth stone wall.",0,0); //29
    StoneWall.addKey("wall");
    StoneWall.addKey("walls");
    StoneWall.addKey("stone wall");
    StoneWall.addKey("stone walls");
    featureDirectory.push_back(StoneWall);

    Feature Vines("vines","Thick, green vines. None of your weapons seem to be able to cut them...",3,1); //30
    Vines.addKey("vines");
    Vines.addKey("vine");
    Vines.addKey("thick vines");
    Vines.addKey("thick vine");
    featureDirectory.push_back(Vines);

    Feature Statue("statue","A statue dedicated to Valentereth.",4,2); //31
    Statue.addKey("statue");
    Statue.addKey("glowing statue");
    Statue.addKey("eyes");
    featureDirectory.push_back(Statue);

    Feature Spikes("spikes","Sharp, pointed spikes lie at the bottom of the pit. A number of skeletons lie littered among them.",0,0); //32
    Spikes.addKey("spikes");
    Spikes.addKey("stalagmites");
    Spikes.addKey("spike");
    Spikes.addKey("stalagmite");
    Spikes.addKey("pit");
    Spikes.addKey("bottom");
    Spikes.addKey("down");
    featureDirectory.push_back(Spikes);

    Feature Plants("plants","Beautiful roses, tulips, and other wildflowers are flourishing here.",3,1); //33
    Plants.addKey("plants");
    Plants.addKey("plant");
    Plants.addKey("flowers");
    Plants.addKey("flower");
    Plants.addKey("garden");
    Plants.addKey("grass");
    featureDirectory.push_back(Plants);

    Feature Sunlight("sunlight","The sunlight is blinding, keeping you from gazing right into it.",0,0); //34
    Sunlight.addKey("sunlight");
    Sunlight.addKey("sun");
    Sunlight.addKey("light");
    Sunlight.addKey("ceiling");
    Sunlight.addKey("sky");
    featureDirectory.push_back(Sunlight);

    Feature Scroll("scroll","A piece of parchment covered in ancient runes and glyphs, detailing the casting of a spell.",4,3); //35
    Scroll.addKey("scroll");
    Scroll.addKey("scrolls");
    Scroll.addKey("paper");
    Scroll.addKey("papers");
    Scroll.addKey("parchment");
    featureDirectory.push_back(Scroll);

    Feature Bookshelf("bookshelf","A rustic-looking bookshelf. Some random junk sits on the shelves.",3,1); //36
    Bookshelf.addKey("bookshelf");
    Bookshelf.addKey("bookshelves");
    Bookshelf.addKey("shelf");
    Bookshelf.addKey("shelves");
    featureDirectory.push_back(Bookshelf);

    Feature BookA("book","An old book, filled with ancient runes.",4,2); //37
    BookA.addKey("book");
    BookA.addKey("books");
    BookA.addKey("tome");
    BookA.addKey("tomes");
    featureDirectory.push_back(BookA);

    Feature BookB("book","An tattered book, filled with illegible writing.",0,0); //38
    BookB.addKey("book");
    BookB.addKey("books");
    BookB.addKey("tome");
    BookB.addKey("tomes");
    featureDirectory.push_back(BookB);

    Feature BookC("book","An old spellbook, detailing the casting of a specific spell.",4,3); //39
    BookC.addKey("book");
    BookC.addKey("books");
    BookC.addKey("tome");
    BookC.addKey("tomes");
    featureDirectory.push_back(BookC);

    Feature BookD("book","A hollowed-out book, with space for something to be hidden inside.",3,3); //40
    BookD.addKey("book");
    BookD.addKey("books");
    BookD.addKey("tome");
    BookD.addKey("tomes");
    featureDirectory.push_back(BookD);

    Feature Pond("pond","A deep pool of water, which you cannot see the bottom of.",3,2); //41
    Pond.addKey("pond");
    Pond.addKey("puddle");
    Pond.addKey("pool");
    Pond.addKey("water");
    Pond.addKey("sweet juice");
    featureDirectory.push_back(Pond);

    Feature BodyA("body","The body of a young man, with a large gash along it's chest.",3,1); //42
    BodyA.addKey("body");
    BodyA.addKey("bodies");
    BodyA.addKey("corpse");
    BodyA.addKey("corpses");
    BodyA.addKey("dead body");
    BodyA.addKey("dead bodies");
    featureDirectory.push_back(BodyA);

    Feature BodyB("body","The body of a woman, with a weapon in her hand.",1,3); //43
    BodyB.addKey("body");
    BodyB.addKey("bodies");
    BodyB.addKey("corpse");
    BodyB.addKey("corpses");
    BodyB.addKey("dead body");
    BodyB.addKey("dead bodies");
    featureDirectory.push_back(BodyB);

    Feature BodyC("body","A decayed body, whose gender and age are completely undecipherable.",0,0); //44
    BodyC.addKey("body");
    BodyC.addKey("bodies");
    BodyC.addKey("corpse");
    BodyC.addKey("corpses");
    BodyC.addKey("dead body");
    BodyC.addKey("dead bodies");
    featureDirectory.push_back(BodyC);

    Feature Scrap("scrap","Sharp pieces of scrap metal, wood, and other materials.",1,1); //45
    Scrap.addKey("scrap");
    Scrap.addKey("scraps");
    Scrap.addKey("metal");
    Scrap.addKey("wood");
    Scrap.addKey("shards");
    Scrap.addKey("shard");
    featureDirectory.push_back(Scrap);

    Feature Furnace("furnace","A stone furnace, with its walls seared from use.",1,1); //46
    Furnace.addKey("furnace");
    Furnace.addKey("oven");
    Furnace.addKey("forge");
    featureDirectory.push_back(Furnace);

    Feature WeaponRack("weapon rack","A wooden rack filled with weapons, most of which are rusted.",1,3); //47
    WeaponRack.addKey("weapon rack");
    WeaponRack.addKey("weapon racks");
    WeaponRack.addKey("rack");
    WeaponRack.addKey("racks");
    WeaponRack.addKey("shelf");
    WeaponRack.addKey("shelves");
    WeaponRack.addKey("weapons");
    featureDirectory.push_back(WeaponRack);

    Feature Cage("cage","A sturdy metal cage, locked tight.",3,1); //48
    Cage.addKey("cage");
    Cage.addKey("cages");
    Cage.addKey("bars");
    Cage.addKey("prison");
    Cage.addKey("cell");
    featureDirectory.push_back(Cage);

    Feature VinePit("vine pit","A bottomless pit, with vines rushing out from it.",0,0); //49
    VinePit.addKey("vine pit");
    VinePit.addKey("pit");
    VinePit.addKey("bottomless pit");
    VinePit.addKey("hole");
    VinePit.addKey("deep pit");
    featureDirectory.push_back(VinePit);

    Feature Table("table","A long wooden table, covered with plates and cutlery.",3,2); //50
    Table.addKey("table");
    Table.addKey("tables");
    Table.addKey("plates");
    featureDirectory.push_back(Table);

    Feature RuinedPillar("pillar","Towering marble pillars, covered by a pulsing black ooze. Savage claw marks cut deep into the marble.",0,0); //51
    RuinedPillar.addKey("pillar");
    RuinedPillar.addKey("pillars");
    RuinedPillar.addKey("marble pillar");
    RuinedPillar.addKey("marble pillars");
    featureDirectory.push_back(RuinedPillar);

    Feature ClawMarks("claw marks","Massive claw marks are cut into the marble, drippning a dark black slime...",0,0); //52
    ClawMarks.addKey("claw marks");
    ClawMarks.addKey("claws");
    ClawMarks.addKey("claw mark");
    ClawMarks.addKey("claw");
    ClawMarks.addKey("marks");
    ClawMarks.addKey("mark");
    featureDirectory.push_back(ClawMarks);

    Feature Campfire("fire","A modest campfire, emitting a warm glow on its surroundings.",0,0); //53
    Campfire.addKey("fire");
    Campfire.addKey("campfire");
    Campfire.addKey("flame");
    featureDirectory.push_back(Campfire);

    Feature MetalTable("table","A cold, metal table. It seems to have been cleaned recently...",3,1); //54
    MetalTable.addKey("table");
    MetalTable.addKey("tables");
    MetalTable.addKey("metal table");
    MetalTable.addKey("metal tables");
    featureDirectory.push_back(MetalTable);

    Feature MetalShelf("shelf","A clean, metal shelf, filled with pieces of lab equipment.",1,1); //55
    MetalShelf.addKey("shelf");
    MetalShelf.addKey("shelves");
    MetalShelf.addKey("metal shelf");
    MetalShelf.addKey("metal shelves");
    featureDirectory.push_back(MetalShelf);

    Feature Equipment("equipment","Various pieces of equipment, most of which unfamiliar to you.",1,2); //56
    Equipment.addKey("equipment");
    Equipment.addKey("lab equipment");
    Equipment.addKey("stuff");
    Equipment.addKey("tools");
    Equipment.addKey("tool");
    featureDirectory.push_back(Equipment);

    Feature Bed("bed","A rather uncomforable bed, with ragged sheets.",3,1); //57
    Bed.addKey("bed");
    Bed.addKey("beds");
    featureDirectory.push_back(Bed);

    Feature Dresser("dresser","An old, wooden dresser, filled with clothes and books",3,1); //58
    Dresser.addKey("dresser");
    Dresser.addKey("dressers");
    Dresser.addKey("wardrobe");
    Dresser.addKey("wardrobes");
    featureDirectory.push_back(Dresser);

    Feature BloodThreat("message","A message is written in blood on the wall: 'THE TOWER BELONGS TO STIRAN'",0,0); //59
    BloodThreat.addKey("message");
    BloodThreat.addKey("blood");
    BloodThreat.addKey("threat");
    BloodThreat.addKey("blood message");
    BloodThreat.addKey("bloody message");
    featureDirectory.push_back(BloodThreat);

    Feature StiranMessage("carving","STIRAN is carved into the stone here, which you know to be the name of an infamous bounty hunter.",0,0); //60
    StiranMessage.addKey("carving");
    StiranMessage.addKey("stiran carving");
    StiranMessage.addKey("stiran");
    StiranMessage.addKey("message");
    StiranMessage.addKey("writing");
    StiranMessage.addKey("stiran message");
    StiranMessage.addKey("name");
    featureDirectory.push_back(StiranMessage);

    Feature Rubble("rubble","A pile of useless rubble.",3,1); //61
    Rubble.addKey("rubble");
    Rubble.addKey("stones");
    Rubble.addKey("stone");
    featureDirectory.push_back(Rubble);

    Feature Spear("spear","An old, rusty spear, stained with blood.",0,0); //62
    Spear.addKey("spear");
    featureDirectory.push_back(Spear);

    Feature BurnedBody("burned body","A charred body, burned beyond recognition. You notice a message written in ink on the wall behind it: 'BEWARE OF BYRALT'.",3,1); //63
    BurnedBody.addKey("burned body");
    BurnedBody.addKey("body");
    BurnedBody.addKey("burned corpse");
    BurnedBody.addKey("corpse");
    BurnedBody.addKey("charred body");
    BurnedBody.addKey("charred corpse");
    featureDirectory.push_back(BurnedBody);

    Feature Fire("fire","A massive, roaring flame.",0,0); //64
    Fire.addKey("fire");
    Fire.addKey("flame");
    Fire.addKey("flames");
    Fire.addKey("inferno");
    featureDirectory.push_back(Fire);

    Feature Blueprints("blueprints","Various drawings of unnerving and unnatural, almost patchwork, creatures. You get the feeling this is some form of recipe...",0,0); //65
    Blueprints.addKey("blueprints");
    Blueprints.addKey("blueprint");
    Blueprints.addKey("drawing");
    Blueprints.addKey("drawings");
    featureDirectory.push_back(Blueprints);

    Feature Eyes("eyes","Magic, spectral eyes. As you move, they follow your movements silently, giving you an uneasy feeling...",0,0); //66
    Eyes.addKey("eyes");
    Eyes.addKey("eye");
    Eyes.addKey("spectral eyes");
    Eyes.addKey("floating eyes");
    Eyes.addKey("spectral eye");
    Eyes.addKey("floating eye");
    featureDirectory.push_back(Eyes);

    Feature Desk("desk","A small wooden desk.",1,1); //67
    Desk.addKey("desk");
    Desk.addKey("wooden desk");
    featureDirectory.push_back(Desk);

    Feature BottomlessPit("pit","A dark pit, which you can't see the bottom of...",0,0); //68
    BottomlessPit.addKey("pit");
    BottomlessPit.addKey("bottomless pit");
    BottomlessPit.addKey("hole");
    featureDirectory.push_back(BottomlessPit);

    Feature SlimeTracks("tracks","Massive tracks of black ooze. From the size of them, whatever left them must be massive...",0,0); //69
    SlimeTracks.addKey("tracks");
    SlimeTracks.addKey("ooze tracks");
    SlimeTracks.addKey("slime tracks");
    SlimeTracks.addKey("slimy tracks");
    SlimeTracks.addKey("black slime tracks");
    SlimeTracks.addKey("prints");
    SlimeTracks.addKey("ooze prints");
    SlimeTracks.addKey("slime prints");
    SlimeTracks.addKey("slimy prints");
    SlimeTracks.addKey("black slime prints");
    featureDirectory.push_back(SlimeTracks);

    Feature Fog("fog","A cold, dense fog. Coming in contact with it makes your head spin...",4,1); //70
    Fog.addKey("fog");
    Fog.addKey("mist");
    Fog.addKey("smoke");
    featureDirectory.push_back(Fog);

    Feature Pantry("pantry","A group of shelves, full of food and items. Sadly, most of it has gone bad...",3,3); //71
    Pantry.addKey("pantry");
    Pantry.addKey("shelves");
    Pantry.addKey("cabinet");
    featureDirectory.push_back(Pantry);

    Feature Tombstone("tombstone","An old tombstone, with illegible writing on it...",0,0); //72
    Tombstone.addKey("tombstone");
    Tombstone.addKey("gravestone");
    Tombstone.addKey("headstone");
    Tombstone.addKey("epitaph");
    featureDirectory.push_back(Tombstone);

    Feature Grave("grave","A grave filled with soft dirt. It appears to have been filled in recently...",3,1); //73
    Grave.addKey("grave");
    Grave.addKey("graves");
    featureDirectory.push_back(Grave);

    Feature Sand("sand","Dry, coarse sand.",3,2); //74
    Sand.addKey("sand");
    Sand.addKey("pile");
    Sand.addKey("piles");
    Sand.addKey("sand piles");
    Sand.addKey("pile of sand");
    Sand.addKey("piles of sand");
    Sand.addKey("sand pile");
    featureDirectory.push_back(Sand);

    Feature HumanSkull("skull","An old human skull, with a long crack running from the eye socket down to the mouth.",0,0); //75
    HumanSkull.addKey("skull");
    HumanSkull.addKey("human skull");
    HumanSkull.addKey("old skull");
    HumanSkull.addKey("cracked skull");
    HumanSkull.addKey("skulls");
    HumanSkull.addKey("human skulls");
    featureDirectory.push_back(HumanSkull);

    Feature BeastSkull("skull","The skull of a beast, which sends a chill down your spine...",0,0); //76
    BeastSkull.addKey("skull");
    BeastSkull.addKey("skulls");
    BeastSkull.addKey("beast skull");
    BeastSkull.addKey("beast skulls");
    featureDirectory.push_back(BeastSkull);

    Feature Flowers("flowers","Decorative flowers, in an array of colors.",0,0); //77
    Flowers.addKey("flowers");
    Flowers.addKey("flower");
    Flowers.addKey("roses");
    Flowers.addKey("rose");
    featureDirectory.push_back(Flowers);

    Feature Pillar("pillar","A beautiful marble pillar, stretching upward toward the ceiling.",0,0); //78
    Pillar.addKey("pillar");
    Pillar.addKey("pillars");
    Pillar.addKey("marble pillar");
    Pillar.addKey("marble pillars");
    featureDirectory.push_back(Pillar);

    Feature Throne("throne","The sight of the throne sends a horrible tremor through your body... yet you can't seem to resist the urge to claim it for your own...",0,0); //79
    Throne.addKey("throne");
    Throne.addKey("chair");
    Throne.addKey("valentereth's throne");
    featureDirectory.push_back(Throne);

    Feature Sky("sky","It seems like it's been ages since you've last seen the natural sky... but the horrible storm keeps you from appreciating it for very long.",0,0); //80
    Sky.addKey("sky");
    Sky.addKey("storm");
    Sky.addKey("thunder");
    Sky.addKey("rain");
    Sky.addKey("lightning");
    featureDirectory.push_back(Sky);

    Feature Carpet("carpet","A soft, red carpet.",3,1); //81
    Carpet.addKey("carpet");
    Carpet.addKey("red carpet");
    featureDirectory.push_back(Carpet);

    Feature StainedGlass("stained glass","Colorful stained glass windows, depicting a large figure weilding a hammer, and another weilding an axe in chains.",0,0); //82
    StainedGlass.addKey("stained glass");
    StainedGlass.addKey("glass");
    StainedGlass.addKey("stained glass window");
    StainedGlass.addKey("stained window");
    StainedGlass.addKey("window");
    StainedGlass.addKey("stained glass windows");
    StainedGlass.addKey("windows");
    featureDirectory.push_back(StainedGlass);

    //cout << "Feature List Initialized!" << endl;

    return featureDirectory;
}
