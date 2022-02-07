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
                id = rand() % 3 + 100;
                break;
            case 2:
                id = rand() % 3 + 103;
                break;
            case 3:
                id = rand() % 3 + 106;
                break;
            case 4:
                id = rand() % 3 + 109;
                break;
            case 5:
                id = rand() % 5 + 112;
                break;
            case 6:
                id = rand() % 5 + 117;
                break;
            case 7:
                id = rand() % 5 + 122;
                break;
            case 8:
                id = rand() % 5 + 127;
                break;
            case 9:
                id = rand() % 5 + 132;
                break;
            case 10:
                id = rand() % 5 + 137;
                break;
        }
    }
    else if(type==2)
    {
        switch(rarity)
        {
            case 1:
                id = rand() % 2 + 200;
                break;
            case 2:
                id = rand() % 2 + 202;
                break;
            case 3:
                id = rand() % 2 + 204;
                break;
            case 4:
                id = rand() % 3 + 206;
                break;
            case 5:
                id = rand() % 3 + 209;
                break;
        }
    }
    else
    {
        switch(rarity)
        {
            case 1:
                id = rand() % 10 + 400;
                break;
            case 2:
                id = rand() % 12 + 410;
                break;
            case 3:
                id = rand() % 12 + 422;
                break;
        }
    }
    return id;
}
