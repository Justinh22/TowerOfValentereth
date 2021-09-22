int itemPicker(int type, int rarity)
{
    int id;
    if(type==0)
    {
        switch(rarity)
        {
            case 1:
                id = rand() % 4;
                break;
            case 2:
                id = rand() % 5 + 4;
                break;
            case 3:
                id = rand() % 6 + 9;
                break;
            case 4:
                id = rand() % 6 + 15;
                break;
            case 5:
                id = rand() % 6 + 21;
                break;
            case 6:
                id = rand() % 6 + 27;
                break;
            case 7:
                id = rand() % 6 + 33;
                break;
            case 8:
                id = rand() % 6 + 39;
                break;
            case 9:
                id = rand() % 6 + 45;
                break;
            case 10:
                id = rand() % 6 + 51;
                break;
        }
    }
    else if(type==1)
    {
        switch(rarity)
        {
            case 1:
                id = rand() % 3 + 57;
                break;
            case 2:
                id = rand() % 3 + 60;
                break;
            case 3:
                id = rand() % 3 + 63;
                break;
            case 4:
                id = rand() % 3 + 66;
                break;
            case 5:
                id = rand() % 5 + 69;
                break;
            case 6:
                id = rand() % 5 + 74;
                break;
            case 7:
                id = rand() % 5 + 79;
                break;
            case 8:
                id = rand() % 5 + 84;
                break;
            case 9:
                id = rand() % 5 + 89;
                break;
            case 10:
                id = rand() % 5 + 94;
                break;
        }
    }
    else
    {
        switch(rarity)
        {
            case 1:
                id = rand() % 2 + 100;
                break;
            case 2:
                id = rand() % 2 + 102;
                break;
            case 3:
                id = rand() % 2 + 104;
                break;
            case 4:
                id = rand() % 3 + 106;
                break;
            case 5:
                id = rand() % 3 + 109;
                break;
        }
    }
    return id;
}
