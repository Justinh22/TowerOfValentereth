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

    Room R15(15,"You look upon a massive room, with large niches cut into the stone walls, colding coffins.");
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


    //cout << "Room List Initialized!" << endl;

    return roomDirectory;
}
