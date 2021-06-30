string lootDesc(int type)
{
    int choice = rand() % 5;
    if(type==0) //Crates
    {
        switch(choice)
        {
            case 0:
                return "A pile of crates lies in the corner of the room";
                break;
            case 1:
                return "Next to the doorway lies a pile of crates.";
                break;
            case 2:
                return "At the back of the room, there are a few crates stacked atop one another.";
                break;
            case 3:
                return "There are some crates stacked against the wall.";
                break;
            case 4:
                return "Some crates lie scattered across the floor.";
                break;
        }
    }
    else if(type==1) //Barrels
    {
        switch(choice)
        {
            case 0:
                return "Some barrels are stacked on top of one another at the wall.";
                break;
            case 1:
                return "In the corner of the room is a pile of overturned barrels.";
                break;
            case 2:
                return "A few barrels are stacked in the corner of the room.";
                break;
            case 3:
                return "Barrels are overturned in the center of the room.";
                break;
            case 4:
                return "In the back of the room, there is a stack of wooden barrels.";
                break;
        }
    }
    else if(type==2) //Chest
    {
        switch(choice)
        {
            case 0:
                return "At the back of the room, there is a beautiful wooden chest.";
                break;
            case 1:
                return "In the center of the room, there is a single chest.";
                break;
            case 2:
                return "A chest lies at the wall, unlocked.";
                break;
            case 3:
                return "Next to the doorway, there sits an open chest.";
                break;
            case 4:
                return "At the wall, there sits an ornate treasure chest.";
                break;
        }
    }
    return "Error!";
}

string doorDesc(int type)
{
    if(type==0)
    {
        int choice = rand() % 10;
        switch(choice)
        {
            case 0:
                return "There is a door at the back of the room, leading to the next chamber.";
                break;
            case 1:
                return "A doorway lies at the back of the room.";
                break;
            case 2:
                return "Toward the back of the room, a ladder ascends to the next chamber.";
                break;
            case 3:
                return "There is a tunnel bored into the back of the room, leading to the next room.";
                break;
            case 4:
                return "A set of double doors at the side of the room leads to the next chamber.";
                break;
            case 5:
                return "A massive doorway towers at the end of the chamber.";
                break;
            case 6:
                return "A wooden door sits in the wall to your left.";
                break;
            case 7:
                return "A tall door stands at the back of the room.";
                break;
            case 8:
                return "A narrow passageway leads off to the next chamber.";
                break;
            case 9:
                return "The door stands to your right, nearly off its hinges.";
                break;
        }
    }
    return "Error!";
}

string creatureDesc(int cid, vector<Creature> creatureDirectory, Player &hero)
{
    string name;
    int choice = rand() % 5;
    if(hero.mask.getID()==2) //Darkness
        name = "Silhouette";
    else
        name = creatureDirectory[cid].getName();

    if(cid==36)
    {
        return "The light escapes from the room; the voices in your head become deafening, and from the shadows in front of you, you see a figure appear, axe in hand. It is Valentereth, the Tyrant. The voices beg you to leave, but you seem to be caught in a trance... Valentereth's eyes seem almost glazed over as she calls you to battle.";
    }
    if(cid==43)
    {
        return "This is the end. Before you, stands its guardian. Termineth stands at the tower's apex.";
    }
    switch(choice)
    {
        case 0:
            return "In the center of the room, a " + name + " stands ready for combat.";
            break;
        case 1:
            return "A " + name + " is waiting for you when you enter the room.";
            break;
        case 2:
            return "You're confronted by a " + name + ", who looms over you menacingly.";
            break;
        case 3:
            return "A " + name + " stands in the center of the room.";
            break;
        case 4:
            return "As soon as you enter, you're confronted by a " + name + ".";
            break;
        default:
            break;
    }
    return "Error!";
}

string ascensionDesc()
{
    int choice = rand() % 5;
    switch(choice)
    {
        case 0:
            return "The voices in your mind grow louder as you ascend...";
        case 1:
            return "You hear the booming voice laugh as you grow closer...";
        case 2:
            return "Dread overtakes you as you enter the next chamber.";
        case 3:
            return "Your mind urges you to turn back, but you continue onward...";
        case 4:
            return "You feel the end growing closer... the source of the curse getting nearer...";
        default:
            break;
    }
    return "Error!";
}
