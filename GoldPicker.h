int goldPicker(int level)
{
    int gold;
    switch(level)
    {
        case 2:
            gold = rand() % 2 + 2;
            break;
        case 3:
            gold = rand() % 3 + 4;
            break;
        case 4:
            gold = rand() % 3 + 7;
            break;
        case 5:
            gold = rand() % 4 + 14;
            break;
        case 6:
            gold = rand() % 5 + 23;
            break;
        case 7:
            gold = rand() % 6 + 30;
            break;
        case 8:
            gold = rand() % 7 + 40;
            break;
        case 9:
            gold = rand() % 8 + 52;
            break;
        case 10:
            gold = rand() % 9 + 66;
            break;
        case 11:
            gold = rand() % 10 + 80;
            break;
        case 12:
            gold = rand() % 11 + 96;
            break;
        case 13:
            gold = rand() % 12 + 114;
            break;
        case 14:
            gold = rand() % 13 + 130;
            break;
        case 15:
            gold = 250;
            break;
        case 16:
            gold = rand() % 25 + 125;
            break;
        case 17:
            gold = 1000;
            break;
    }
    return gold;
}

int expPicker(int level)
{
    int exp;
    switch(level)
    {
        case 2:
            exp = rand() % 2 + 5;
            break;
        case 3:
            exp = rand() % 2 + 8;
            break;
        case 4:
            exp = rand() % 3 + 12;
            break;
        case 5:
            exp = rand() % 3 + 16;
            break;
        case 6:
            exp = rand() % 4 + 21;
            break;
        case 7:
            exp = rand() % 4 + 25;
            break;
        case 8:
            exp = rand() % 5 + 30;
            break;
        case 9:
            exp = rand() % 5 + 35;
            break;
        case 10:
            exp = rand() % 6 + 41;
            break;
        case 11:
            exp = rand() % 6 + 47;
            break;
        case 12:
            exp = rand() % 7 + 53;
            break;
        case 13:
            exp = rand() % 7 + 60;
            break;
        case 14:
            exp = rand() % 8 + 68;
            break;
        case 15:
            exp = 200;
            break;
        case 16:
            exp = rand() % 25 + 65;
            break;
        case 17:
            exp = 1000;
            break;
    }
    return exp;
}
