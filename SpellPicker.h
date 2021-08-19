int spellPicker(int rarity)
{
    int sid;
    int prob;
    prob = rand() % 7 + 1;
    if(prob<=3)
    {
        switch(rarity)
        {
            case 1:
                sid = rand() % 3 + 200;
                break;
            case 2:
                sid = rand() % 3 + 203;
                break;
            case 3:
                sid = rand() % 3 + 206;
                break;
            case 4:
                sid = rand() % 3 + 209;
                break;
            case 5:
                sid = rand() % 3 + 212;
                break;
        }
    }
    else if(prob<=5)
    {
        switch(rarity)
        {
            case 1:
                sid = 215;
                break;
            case 2:
                sid = rand() % 2 + 216;
                break;
            case 3:
                sid = 218;
                break;
            case 4:
                sid = 219;
                break;
            case 5:
                sid = 220;
                break;
        }
    }
    else if(prob<=7)
    {
        switch(rarity)
        {
            case 1:
                sid = rand() % 5 + 221;
                break;
            case 2:
                sid = rand() % 5 + 226;
                break;
            case 3:
                sid = rand() % 5 + 231;
                break;
            case 4:
                sid = rand() % 6 + 236;
                break;
            case 5:
                sid = 242;
                break;
        }
    }
    return sid;
}
