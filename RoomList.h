vector<Room> initRDir(vector<Room> roomDirectory, vector<Feature> featureDirectory)
{
    Room R0(0,"You step into a stone room, lit by torchlight.");
    R0.addFeat(featureDirectory[0]);
    roomDirectory.push_back(R0);

    Room R1(1,"Above you, a candelabra sheds a dim light on the cobblestone floor.");
    R1.addFeat(featureDirectory[1]);
    R1.addFeat(featureDirectory[2]);
    roomDirectory.push_back(R1);

    Room R2(2,"You step on the soft, dirt floor as you enter a massive ovular room.");
    R2.addFeat(featureDirectory[3]);
    roomDirectory.push_back(R2);

    Room R3(3,"Thunder crashes outside as you step into a small square room built from stone.");
    roomDirectory.push_back(R3);

    Room R4(4,"You step into the room, and through windows on the walls around you you see the bright flash of lightning.");
    R4.addFeat(featureDirectory[4]);
    roomDirectory.push_back(R4);

    Room R5(5,"You walk into a room, and you swear you hear whispers around you...");
    R5.addFeat(featureDirectory[5]);
    roomDirectory.push_back(R5);

    Room R6(6,"You thought you saw a silhouette of someone when you enter the room, but it must have been your imagination...");
    R6.addFeat(featureDirectory[6]);
    roomDirectory.push_back(R6);

    Room R7(7,"As you walk into the room, you hear a booming voice in your mind, urging you to turn back.");
    R7.addFeat(featureDirectory[7]);
    roomDirectory.push_back(R7);

    Room R8(8,"Your head aches as you step into this room...");
    roomDirectory.push_back(R8);

    Room R9(9,"Your shoes sink into the soft dirt that covers the floor of this room as you step inside.");
    R9.addFeat(featureDirectory[3]);
    roomDirectory.push_back(R9);

    Room R10(10,"The walls of this room are an inky black, giving you an uneasy feeling...");
    R10.addFeat(featureDirectory[8]);
    roomDirectory.push_back(R10);

    Room R11(11,"You see candles floating in midair around the room, suspended by magic.");
    R11.addFeat(featureDirectory[9]);
    roomDirectory.push_back(R11);

    Room R12(12,"This room emanates a dim red glow between the cracks of each stone...");
    R12.addFeat(featureDirectory[10]);
    roomDirectory.push_back(R12);

    Room R13(13,"A flurry of bats suddenly flaps through the doorway, their screeching barely audible as they careen past your head.");
    R13.addFeat(featureDirectory[18]);
    roomDirectory.push_back(R13);

    Room R14(14,"An unnatural shade fills this room, making it difficult to see around the walls of the chamber...");
    roomDirectory.push_back(R14);

    Room R15(15,"You look upon a massive room, with large niches cut into the stone walls, holding coffins.");
    R15.addFeat(featureDirectory[11]);
    roomDirectory.push_back(R15);

    Room R16(16,"You step into a long chamber, with suits of armor lining the walls.");
    R16.addFeat(featureDirectory[12]);
    roomDirectory.push_back(R16);

    Room R17(17,"Bright torches line the stone walls of the chamber, lighting a stone altar in the center of the room, blood spattered along its surface.");
    R17.addFeat(featureDirectory[10]);
    R17.addFeat(featureDirectory[13]);
    R17.addFeat(featureDirectory[14]);
    roomDirectory.push_back(R17);

    Room R18(18,"You step into small, circular room. Etched into the stone bricks in the walls are strange runes and glyphs.");
    R18.addFeat(featureDirectory[10]);
    R18.addFeat(featureDirectory[15]);
    roomDirectory.push_back(R18);

    Room R19(19,"Rusted metal panels cover the floor, forming a mosaic of a bat.");
    R19.addFeat(featureDirectory[16]);
    roomDirectory.push_back(R19);

    Room R20(20,"Carved into the ceiling of this room is a large sigil, its meaning lost to time...");
    R20.addFeat(featureDirectory[17]);
    roomDirectory.push_back(R20);

    Room R21(21,"You see a figure dash out of a doorway, but you can't quite make out what it was...");
    roomDirectory.push_back(R21);

    Room R22(22,"The room contains stone pedestals, outlining the outside of a massive circular sigil on the floor in the center of the room. A puddle of blood lies in the center.");
    R22.addFeat(featureDirectory[17]);
    R22.addFeat(featureDirectory[14]);
    R22.addFeat(featureDirectory[19]);
    roomDirectory.push_back(R22);

    Room R23(23,"All over the floor of this room are piles upon piles of bones. In the center of the room, there is a single stone statue of a beast.");
    R23.addFeat(featureDirectory[20]);
    R23.addFeat(featureDirectory[21]);
    roomDirectory.push_back(R23);

    Room R24(24,"Black slime oozes from cracks in the stone walls. The floor has a puddle of it about an inch deep, making it hard to move...");
    R24.addFeat(featureDirectory[10]);
    R24.addFeat(featureDirectory[22]);
    roomDirectory.push_back(R24);

    Room R25(25,"In the center of a tiny stone room, there is a single coffin.");
    R25.addFeat(featureDirectory[23]);
    roomDirectory.push_back(R25);

    Room R26(26,"There is a human skeleton leaned up against the wall of this room. All over the wall are messages, etched into the stone...");
    R26.addFeat(featureDirectory[24]);
    R26.addFeat(featureDirectory[25]);
    roomDirectory.push_back(R26);

    Room R27(27,"The clean, marble walls of this room look entirely out of place from the rest of the tower. On a pedestal in the center of the room is a book.");
    R27.addFeat(featureDirectory[26]);
    R27.addFeat(featureDirectory[27]);
    roomDirectory.push_back(R27);

    Room R28(28,"There are human skeletons hanging from chains around their wrists along the stone walls of this room, dimly lit from a single torch.");
    R28.addFeat(featureDirectory[10]);
    R28.addFeat(featureDirectory[24]);
    R28.addFeat(featureDirectory[0]);
    R28.addFeat(featureDirectory[28]);
    roomDirectory.push_back(R28);

    Room R29(29,"The walls of this room are nearly obscured by thick vines, entangled in one another. You can see the vines growing before your very eyes...");
    R29.addFeat(featureDirectory[29]);
    R29.addFeat(featureDirectory[30]);
    roomDirectory.push_back(R29);

    Room R30(30,"Vines are sprouting from the far end of the room, winding around a statue. It's eyes seem to glow...");
    R30.addFeat(featureDirectory[30]);
    R30.addFeat(featureDirectory[31]);
    roomDirectory.push_back(R30);

    Room R31(31,"The stone floor at the sides of the room seem to have fallen through, revealing a bed of razor-sharp stalagmites at the bottom of a deep pit.");
    R31.addFeat(featureDirectory[2]);
    R31.addFeat(featureDirectory[32]);
    roomDirectory.push_back(R31);

    Room R32(32,"A single human skeleton is stuck to the wall at the far side of the room, as if it were an effigy. It is affixed with a dark, black slime...");
    R32.addFeat(featureDirectory[22]);
    R32.addFeat(featureDirectory[24]);
    roomDirectory.push_back(R32);

    Room R33(33,"Empty suits of armor stand guard around the perimeter of the circular room, looming over you menacingly. In the center of the room in the middle of the cobblestone floor, a glowing sigil pulses.");
    R33.addFeat(featureDirectory[2]);
    R33.addFeat(featureDirectory[12]);
    R33.addFeat(featureDirectory[17]);
    roomDirectory.push_back(R33);

    Room R34(34,"Shockingly, this room seems to almost open up to a flourishing garden surrounded by stone walls, and the ceiling above disappears to reveal a blinding sun.");
    R34.addFeat(featureDirectory[10]);
    R34.addFeat(featureDirectory[33]);
    R34.addFeat(featureDirectory[34]);
    roomDirectory.push_back(R34);

    Room R35(35,"You step into a crowded study, filled with bookshelves, papers, and books scattered all about, all lit by a candelabra hanging from the ceiling.");
    R35.addFeat(featureDirectory[1]);
    R35.addFeat(featureDirectory[35]);
    R35.addFeat(featureDirectory[36]);
    R35.addFeat(featureDirectory[rand()%4+37]);
    roomDirectory.push_back(R35);

    Room R36(36,"You wade into a massive pool of water, consuming nearly all of the space in the marble room.");
    R36.addFeat(featureDirectory[26]);
    R36.addFeat(featureDirectory[41]);
    roomDirectory.push_back(R36);

    Room R37(37,"A corpse lies in the center of an empty circular room, with its blood soaking into the stone floor.");
    R37.addFeat(featureDirectory[1]);
    R37.addFeat(featureDirectory[14]);
    R37.addFeat(featureDirectory[rand()%3+42]);
    roomDirectory.push_back(R37);

    Room R38(38,"The room is littered with pieces of scrap, lit only by a single torch, forcing you to watch your step to traverse it.");
    R38.addFeat(featureDirectory[0]);
    R38.addFeat(featureDirectory[45]);
    roomDirectory.push_back(R38);

    Room R39(39,"An unnatural wind billows through the room, seemingly through the loose stone walls. The plants and vines sprouting from the dirt floor blow violently from the wind.");
    R39.addFeat(featureDirectory[3]);
    R39.addFeat(featureDirectory[10]);
    R39.addFeat(featureDirectory[30]);
    R39.addFeat(featureDirectory[33]);
    roomDirectory.push_back(R39);

    Room R40(40,"A forge is set up in the corner of the room, lighting the stone walls dimly, with weapon racks on the walls around it.");
    R40.addFeat(featureDirectory[10]);
    R40.addFeat(featureDirectory[46]);
    R40.addFeat(featureDirectory[47]);
    roomDirectory.push_back(R40);

    Room R41(41,"Cages line the walls of the room, with skeletons in each one bound to the walls with chains.");
    R41.addFeat(featureDirectory[10]);
    R41.addFeat(featureDirectory[24]);
    R41.addFeat(featureDirectory[28]);
    R41.addFeat(featureDirectory[48]);
    roomDirectory.push_back(R41);

    Room R42(42,"A deep pit lies in the center of the room, with vines growing out of it at an impossible rate. They extend into the walls and ceiling through cracks in the stone...");
    R42.addFeat(featureDirectory[10]);
    R42.addFeat(featureDirectory[30]);
    R42.addFeat(featureDirectory[49]);
    roomDirectory.push_back(R42);

    Room R43(43,"A great hall spans out before you, with tables stretching down the length of the room, lit magnificently by glowing candelabras.");
    R43.addFeat(featureDirectory[1]);
    R43.addFeat(featureDirectory[50]);
    roomDirectory.push_back(R43);

    Room R44(44,"The floor narrows to a small pathway, with the cobblestone floor on either side of it opening up to a pit of spikes.");
    R44.addFeat(featureDirectory[2]);
    R44.addFeat(featureDirectory[32]);
    roomDirectory.push_back(R44);

    Room R45(45,"The light in this room seems to almost be absorbed by a suit of armor at its center, whose eyes are glowing with light.");
    R45.addFeat(featureDirectory[8]);
    R45.addFeat(featureDirectory[12]);
    roomDirectory.push_back(R45);

    Room R46(46,"The room is filled with racks full of weapons, and suits of armor all over. It appears this used to be an armory.");
    R46.addFeat(featureDirectory[12]);
    R46.addFeat(featureDirectory[47]);
    roomDirectory.push_back(R46);

    Room R47(47,"The wall to your left as you enter the room is in shambles, and through the rubble you can see the sun shining brightly in at you. You could have sworn it was nighttime when you entered...");
    R47.addFeat(featureDirectory[10]);
    R47.addFeat(featureDirectory[34]);
    R47.addFeat(featureDirectory[61]);
    roomDirectory.push_back(R47);

    Room R48(48,"A single torch illuminates a long wooden table, upon which you see a number of scrolls and books.");
    R48.addFeat(featureDirectory[0]);
    R48.addFeat(featureDirectory[35]);
    R48.addFeat(featureDirectory[rand()%4+37]);
    R48.addFeat(featureDirectory[50]);
    roomDirectory.push_back(R48);

    Room R49(49,"A sigil of some sort is etched into the ceiling of the room, and from its center you can see black ooze dripping to the floor...");
    R49.addFeat(featureDirectory[17]);
    R49.addFeat(featureDirectory[22]);
    roomDirectory.push_back(R49);

    Room R50(50,"A body has been affixed to the rugged stone wall of the chamber, by a spear through its center. A message has been written in blood on the wall.");
    R50.addFeat(featureDirectory[rand()%3+42]);
    R50.addFeat(featureDirectory[10]);
    R50.addFeat(featureDirectory[59]);
    R50.addFeat(featureDirectory[62]);
    roomDirectory.push_back(R50);

    Room R51(51,"The room seems ruined, with rubble covering the coarse dirt floor... at the back of the room, 'STIRAN' has been carved into the wall.");
    R51.addFeat(featureDirectory[3]);
    R51.addFeat(featureDirectory[60]);
    R51.addFeat(featureDirectory[61]);
    roomDirectory.push_back(R51);

    Room R52(52,"The room is filled with metal tables, with strange pieces of equipment upon them. There are puddles of blood on the floor...");
    R52.addFeat(featureDirectory[14]);
    R52.addFeat(featureDirectory[54]);
    R52.addFeat(featureDirectory[56]);
    roomDirectory.push_back(R52);

    Room R53(53,"A roaring fire engulfs the room, filling your eyes and lungs with smoke. A burned body lies in the corner.");
    R53.addFeat(featureDirectory[63]);
    R53.addFeat(featureDirectory[64]);
    roomDirectory.push_back(R53);

    Room R54(54,"You find a room with walls covered with drawings and blueprints, as you hear the whispers in your mind growing louder...");
    R54.addFeat(featureDirectory[5]);
    R54.addFeat(featureDirectory[65]);
    roomDirectory.push_back(R54);

    Room R55(55,"A figure was looking at something on a cluttered bookshelf, but when they see you enter they bolt before you can say anything, nearly tripping on a table as they dash out of the room.");
    R55.addFeat(featureDirectory[6]);
    R55.addFeat(featureDirectory[36]);
    R55.addFeat(featureDirectory[50]);
    roomDirectory.push_back(R55);

    Room R56(56,"You step into a narrow, circular room. The smooth stone walls are filled with glowing runes, stretching up for as long as you can see...");
    R56.addFeat(featureDirectory[15]);
    R56.addFeat(featureDirectory[29]);
    roomDirectory.push_back(R56);

    Room R57(57,"You stumble into what looks like it was once a hideout, with a campfire still lit. A wooden table sits with a book open atop it, and a body sits slumped over in a chair next to it.");
    R57.addFeat(featureDirectory[rand()%4+37]);
    R57.addFeat(featureDirectory[rand()%3+42]);
    R57.addFeat(featureDirectory[50]);
    R57.addFeat(featureDirectory[53]);
    roomDirectory.push_back(R57);

    Room R58(58,"You step into a long, narrow hallway. On either side of the hall, you see floating, spectral eyes that follow your movements as you make your way through the chamber...");
    R58.addFeat(featureDirectory[66]);
    roomDirectory.push_back(R58);

    Room R59(59,"You enter a small, dark study. A small desk sits in the center of the room, lit dimly from floating candles around it. You see various books, papers, and drawings on the desk");
    R59.addFeat(featureDirectory[9]);
    R59.addFeat(featureDirectory[rand()%4+37]);
    R59.addFeat(featureDirectory[35]);
    R59.addFeat(featureDirectory[65]);
    R59.addFeat(featureDirectory[67]);
    roomDirectory.push_back(R59);

    Room R60(60,"You have to catch yourself as you enter a wide circular room, with most the floor missing apart from a walkway around the outer stone wall. The pit in the center of the room seems to have no bottom...");
    R60.addFeat(featureDirectory[10]);
    R60.addFeat(featureDirectory[68]);
    roomDirectory.push_back(R60);

    Room R61(61,"You step into... your room. You can't tell if it's an illusion, but you see your own desk, and a few spare books lying open on your bed. You feel uneasy in here...");
    R61.addFeat(featureDirectory[rand()%4+37]);
    R61.addFeat(featureDirectory[57]);
    R61.addFeat(featureDirectory[67]);
    roomDirectory.push_back(R61);

    Room R62(62,"The room is lit dimly by the soft glow of a single torch. Something has clearly happened here, but it seems you're too late; a burned body lies in the corner, next to several piles of charred rubble. Several weapon racks lie at the other end of the room.");
    R62.addFeat(featureDirectory[0]);
    R62.addFeat(featureDirectory[47]);
    R62.addFeat(featureDirectory[61]);
    R62.addFeat(featureDirectory[63]);
    roomDirectory.push_back(R62);

    Room R63(63,"The side wall of this room is destroyed, revealing the night sky through the rubble. Leading from the remains of the wall are tracks of black ooze, leading out of the room...");
    R63.addFeat(featureDirectory[10]);
    R63.addFeat(featureDirectory[22]);
    R63.addFeat(featureDirectory[61]);
    R63.addFeat(featureDirectory[69]);
    roomDirectory.push_back(R63);

    Room R64(64,"The doorway leads to a cascading staircase, hugging the marble walls and leading downward in the chamber, circling a massive statue of a figure holding an axe.");
    R64.addFeat(featureDirectory[26]);
    R64.addFeat(featureDirectory[31]);
    roomDirectory.push_back(R64);

    Room R65(65,"Through the dim light that this room is blanketed in from a number of floating candles, you can see that the floor of this room is covered in piles upon piles of bones.");
    R65.addFeat(featureDirectory[9]);
    R65.addFeat(featureDirectory[20]);
    roomDirectory.push_back(R65);

    Room R66(66,"You can't quite tell if this room is a lab, or a ritual site... metal tables and shelves line the walls, but in the center of the room is an altar soaked in blood, bathed in the light of a magic sigil on the ceiling above it.");
    R66.addFeat(featureDirectory[13]);
    R66.addFeat(featureDirectory[14]);
    R66.addFeat(featureDirectory[17]);
    R66.addFeat(featureDirectory[54]);
    R66.addFeat(featureDirectory[55]);
    R66.addFeat(featureDirectory[56]);
    roomDirectory.push_back(R66);

    Room R67(67,"In the middle of the room is a massive cage, coated in dark black ooze. The door of the cage is hanging open...");
    R67.addFeat(featureDirectory[22]);
    R67.addFeat(featureDirectory[48]);
    roomDirectory.push_back(R67);

    Room R68(68,"It seems like somebody was collecting things in this room... There are small piles of bones, scrap, and pieces of equipment scattered around the dirt floor of the room.");
    R68.addFeat(featureDirectory[3]);
    R68.addFeat(featureDirectory[20]);
    R68.addFeat(featureDirectory[45]);
    R68.addFeat(featureDirectory[56]);
    roomDirectory.push_back(R68);

    Room R69(69,"The cobblestone floor beneath your feet is cold and damp, and at the side of the room falls off into a deep pond.");
    R69.addFeat(featureDirectory[2]);
    R69.addFeat(featureDirectory[41]);
    roomDirectory.push_back(R69);

    Room R70(70,"The whole room is filled with a peculiar fog, making it difficult to step over the rubble scattered over the floor...");
    R70.addFeat(featureDirectory[61]);
    R70.addFeat(featureDirectory[70]);
    roomDirectory.push_back(R70);

    Room R71(71,"A single statue of a beast protrudes from a pond in the center of the room, producing an unusual fog...");
    R71.addFeat(featureDirectory[21]);
    R71.addFeat(featureDirectory[41]);
    R71.addFeat(featureDirectory[70]);
    roomDirectory.push_back(R71);

    Room R72(72,"A sigil is carved into the center of the floor of a dark, dome-shaped room, emitting an amber light onto the walls. The light reveals countless runes and symbols, resembling an ancient language...");
    R72.addFeat(featureDirectory[15]);
    R72.addFeat(featureDirectory[17]);
    roomDirectory.push_back(R72);

    Room R73(73,"On the eastern wall you see a roaring campfire built atop the dirt, with a table set up next to it. A pantry is settled beside them.");
    R73.addFeat(featureDirectory[3]);
    R73.addFeat(featureDirectory[50]);
    R73.addFeat(featureDirectory[53]);
    R73.addFeat(featureDirectory[71]);
    roomDirectory.push_back(R73);

    Room R74(74,"The dirt floor of this room is covered in tombstones. You can't even walk through without having to step over them...");
    R74.addFeat(featureDirectory[3]);
    R74.addFeat(featureDirectory[72]);
    roomDirectory.push_back(R74);

    Room R75(75,"All of the sudden, you find yourself in a massive graveyard. Fog covers obscures your vision, but you can make out rows upon rows of tombstones over graves, with bones littering the field...");
    R75.addFeat(featureDirectory[3]);
    R75.addFeat(featureDirectory[20]);
    R75.addFeat(featureDirectory[70]);
    R75.addFeat(featureDirectory[72]);
    R75.addFeat(featureDirectory[73]);
    roomDirectory.push_back(R75);

    Room R76(76,"The room is nearly pitch-black, with the only light coming from a crack in the stone wall to your left. The light shines onto a grave, with flowers sitting beside the headstone.");
    R76.addFeat(featureDirectory[3]);
    R76.addFeat(featureDirectory[10]);
    R76.addFeat(featureDirectory[72]);
    R76.addFeat(featureDirectory[73]);
    R76.addFeat(featureDirectory[77]);
    roomDirectory.push_back(R76);

    Room R77(77,"You step onto a pile of bones, the floor beneath them not even visible. You can't begin to fathom how many people may have died here...");
    R77.addFeat(featureDirectory[20]);
    R77.addFeat(featureDirectory[75]);
    roomDirectory.push_back(R77);

    Room R78(78,"You step onto a large pile of sand, and as you look around the rest of the room you see various bones and skulls buried in the sand.");
    R78.addFeat(featureDirectory[20]);
    R78.addFeat(featureDirectory[74]);
    R78.addFeat(featureDirectory[76]);
    roomDirectory.push_back(R78);

    Room R79(79,"On a pedestal in the middle of the room, you see some tools lying in a puddle of blood. The floor is etched with runes in a circle around the pedestal.");
    R79.addFeat(featureDirectory[19]);
    R79.addFeat(featureDirectory[14]);
    R79.addFeat(featureDirectory[15]);
    R79.addFeat(featureDirectory[56]);
    roomDirectory.push_back(R79);

    Room R80(80,"Hanging from the ceiling of this room are human skulls, suspended by chains. The stone room is illuminated by a single torch at the back of the room.");
    R80.addFeat(featureDirectory[10]);
    R80.addFeat(featureDirectory[28]);
    R80.addFeat(featureDirectory[0]);
    R80.addFeat(featureDirectory[75]);
    roomDirectory.push_back(R80);

    Room R81(81,"A scorched body hangs from the ceiling by chains. Skulls litter the stone floor beneath it.");
    R81.addFeat(featureDirectory[2]);
    R81.addFeat(featureDirectory[28]);
    R81.addFeat(featureDirectory[63]);
    R81.addFeat(featureDirectory[75]);
    roomDirectory.push_back(R81);


    //MINIBOSS LAIRS
    Room R82(82,"Black slime covers every surface of a grand hall, pulsing as if it were alive... long pillars reach toward the ceilings, decorated by savage claw marks on their surface.");
    R82.addFeat(featureDirectory[22]); //OZKOROTH
    R82.addFeat(featureDirectory[51]);
    R82.addFeat(featureDirectory[52]);
    roomDirectory.push_back(R82);

    Room R83(83,"The room is covered with interwoven vines, racing out of a hole in the the ceiling... You can see them growing before your very eyes...");
    R83.addFeat(featureDirectory[30]); //ENDRIGAIA
    R83.addFeat(featureDirectory[49]);
    roomDirectory.push_back(R83);

    Room R84(84,"You find yourself in a cramped, sprawling library, with bookshelves impossibly tall scattered about the room. Papers and books litter the floor.");
    R84.addFeat(featureDirectory[17]); //EMERITUS
    R84.addFeat(featureDirectory[35]);
    R84.addFeat(featureDirectory[36]);
    R84.addFeat(featureDirectory[rand()%4+37]);
    roomDirectory.push_back(R84);

    Room R85(85,"You enter what looks like a small haven, with a light fire burning in the corner next to a long table.");
    R85.addFeat(featureDirectory[50]); //STIRAN
    R85.addFeat(featureDirectory[53]);
    roomDirectory.push_back(R85);

    Room R86(86,"The atmosphere of the room is chilling as you enter; cold, metal tables and shelves lie at the perimeter of the room, with pieces of equipment lying about.");
    R86.addFeat(featureDirectory[54]); //?????
    R86.addFeat(featureDirectory[55]);
    R86.addFeat(featureDirectory[56]);
    roomDirectory.push_back(R86);

    Room R87(87,"You step into what seems to be a quarters, with a small bed in the corner, with a dresser beside it. There is also a wooden table surrounded by chairs.");
    R87.addFeat(featureDirectory[rand()%4+37]); //BYRALT
    R87.addFeat(featureDirectory[50]);
    R87.addFeat(featureDirectory[57]);
    R87.addFeat(featureDirectory[58]);
    roomDirectory.push_back(R87);

    Room R88(88,"A long, regal throne room extends before you. A marble pathway is lit by candelabras positioned on the pillars on either side of you, stretching up into the inky darkness above you. The marble floor leads you to a blood-red throne, cloaked in shadow.");
    R88.addFeat(featureDirectory[1]); //VALENTERETH
    R88.addFeat(featureDirectory[26]);
    R88.addFeat(featureDirectory[78]);
    R88.addFeat(featureDirectory[79]);
    roomDirectory.push_back(R88);

    Room R89(89,"You finally reach the top of the tower, only to be met with a deafening crash of thunder as a storm rages from the dark sky above. Lightning flashes before you, silhouetting a massive man standing at the tower's edge. He raises a warhammer in one hand, and brings it down on the stone in front of you, causing another deafening crash of thunder to send a tremor to your very core.");
    R89.addFeat(featureDirectory[2]); //TERMINETH
    R89.addFeat(featureDirectory[79]);
    R89.addFeat(featureDirectory[80]);
    roomDirectory.push_back(R89);


    return roomDirectory;
}
