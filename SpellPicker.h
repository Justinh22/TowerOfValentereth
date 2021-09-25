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
                sid = rand() % 3 + 300;
                break;
            case 2:
                sid = rand() % 3 + 303;
                break;
            case 3:
                sid = rand() % 3 + 306;
                break;
            case 4:
                sid = rand() % 3 + 309;
                break;
            case 5:
                sid = rand() % 3 + 312;
                break;
        }
    }
    else if(prob<=5)
    {
        switch(rarity)
        {
            case 1:
                sid = 315;
                break;
            case 2:
                sid = rand() % 2 + 316;
                break;
            case 3:
                sid = 318;
                break;
            case 4:
                sid = 319;
                break;
            case 5:
                sid = 320;
                break;
        }
    }
    else if(prob<=7)
    {
        switch(rarity)
        {
            case 1:
                sid = rand() % 5 + 321;
                break;
            case 2:
                sid = rand() % 5 + 326;
                break;
            case 3:
                sid = rand() % 5 + 331;
                break;
            case 4:
                sid = rand() % 6 + 336;
                break;
            case 5:
                sid = 342;
                break;
        }
    }
    return sid;
}
