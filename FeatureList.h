vector<Feature> initFDir(vector<Feature> featureDirectory)
{
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

    //cout << "Feature List Initialized!" << endl;

    return featureDirectory;
}
