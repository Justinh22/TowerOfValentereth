int creaturePicker(int level)
{
    int id;
    switch(level)
    {
        case 2:
            id = rand() % 4;
            break;
        case 3:
            id = rand() % 4 + 4;
            break;
        case 4:
            id = rand() % 4 + 8;
            break;
        case 5:
            id = rand() % 4 + 12;
            break;
        case 6:
            id = rand() % 4 + 16;
            break;
        case 7:
            id = rand() % 4 + 20;
            break;
        case 8:
            id = rand() % 4 + 24;
            break;
        case 9:
            id = rand() % 4 + 28;
            break;
        case 10:
            id = rand() % 4 + 32;
            break;
        case 11:
            id = rand() % 3 + 36;
            break;
        case 12:
            id = rand() % 3 + 39;
            break;
        case 13:
            id = rand() % 3 + 42;
            break;
        case 14:
            id = rand() % 3 + 45;
            break;
        case 15:
            id = 48;
            break;
        case 16:
            id = rand() % 7 + 49;
            break;
        case 17:
            id = 56;
            break;
    }
    return id;
}
