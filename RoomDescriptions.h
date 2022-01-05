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

    if(cid==48)
    {
        return "The light escapes from the room; the voices in your head become deafening, and from the shadows in front of you, you see a figure appear, axe in hand. It is Valentereth, the Tyrant. The voices beg you to leave, but you seem to be caught in a trance... Valentereth's eyes seem almost glazed over as she calls you to battle.";
    }
    else if(cid==56)
    {
        return "The man raises his power and approaches you. 'Some curses aren't meant to be broken, fool... Those who hunger for power are all the same. Wretched, evil worms who are doomed to ruin the lives of others. This tower is all that keeps the power-hungry at bay, attracting them like moths to a flame, promising glory, riches, power beyond their wildest fantasy... You are one of them, you should know. Are these truly the ones you hope to save by defeating me? Then so be it. I will not let the world suffer for the sake of your glory.' The man raises his hammer toward the sky at the tower's apex, ready for battle.";
    }
    else if(cid==57)
    {
        return "Prowling around the hall is a massive behemoth, completely entombed in black slime aside from its razor-sharp claws, and piercing yellow eyes. Upon seeing you enter, it lets out a deafening roar.";
    }
    else if(cid==58)
    {
        return "The vines rushing from the ceiling wind together to form a figure at their center, with two long arms stretching out from its sides, and long, glowing yellow antlers to match its eyes, which lock onto you as it sees you enter.";
    }
    else if(cid==59)
    {
        return "At the back of the room, shuffling through papers and books on the floor, is a tall, lanky man. As he hears you come in he turns to face you, with a long, dark sceptre in hand. When you see his face, you notice dark violet veins coursing under his skin, to match his dark sunken eyes...";
    }
    else if(cid==60)
    {
        return "Sitting at the fire in a small stool is a burly-looking man, who looks up at you and gives you a sneer as you enter. \"Ah, I was beginning to think I was the only one lootin' this hell hole. Well, unfortunately for you, there's barely enough in here for the one of us, let alone two.\" He stands up from his stool, and picks up a massive greatsword and shield at his side, and readies for battle.";
    }
    else if(cid==61)
    {
        return "Although your vision can't quite lock onto it, you see a figure darting around the room, bumping into tables... Something about this creature's form makes it imperceivable, but you can see a horrid combination of parts, forming an a vaguely humanoid form. You hear a cacophony of voices in your mind as the creature barrels toward you...";
    }
    else if(cid==62)
    {
        return "A short woman is startled from your entrance, jumping up from her chair at the table. She turns to grab a tome off of the table, and as she does you see Valentereth's sigil on the back of her robes. The woman whirls back around and shouts an incantation, as the room is filled with an inky-black smoke...";
    }
    else if(cid==63)
    {
        return "A tall woman in shining black armor stands vigilant in the center of the hall, her eyes glowing a with blinding light. 'Your seige of this place comes to an end now. In the name of the Watcher, I sentence you to death!' Pulling a long spear from her back, she charges toward you.";
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
