int creaturePicker(int level)
{
    int id;
    switch(level)
    {
        case 2:
            id = rand() % 3;
            break;
        case 3:
            id = rand() % 3 + 3;
            break;
        case 4:
            id = rand() % 3 + 6;
            break;
        case 5:
            id = rand() % 3 + 9;
            break;
        case 6:
            id = rand() % 3 + 12;
            break;
        case 7:
            id = rand() % 3 + 15;
            break;
        case 8:
            id = rand() % 4 + 18;
            break;
        case 9:
            id = rand() % 3 + 22;
            break;
        case 10:
            id = rand() % 3 + 25;
            break;
        case 11:
            id = rand() % 2 + 28;
            break;
        case 12:
            id = rand() % 2 + 30;
            break;
        case 13:
            id = rand() % 2 + 32;
            break;
        case 14:
            id = rand() % 2 + 34;
            break;
        case 15:
            id = 36;
            break;
        case 16:
            id = rand() % 6 + 37;
            break;
        case 17:
            id = 43;
            break;
    }
    return id;
}
