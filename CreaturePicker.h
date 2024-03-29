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

int minibossPicker(vector<bool> &mbStatus)
{
    int id=-1;
    for(int i=0;i<mbStatus.size();i++)
        if(mbStatus[i]==0)
        {
            id = 0;
            break;
        }
    if(id==-1)
        return -1;

    do{
        id = rand() % 7;
    }while(mbStatus[id]==1);
    mbStatus[id] = 1;
    return id+57;
}

void minibossStatGen(int adv, Creature &mon)
{
    adv--;
    int mod = (adv-3)/3;
    int hpBuff;
    int strBuff;
    int accBuff;
    int defBuff;
    int ddgBuff;

    if(mon.getID()==57) //Ozkoroth
    {
        hpBuff = (adv-3)*(4+mod);
        strBuff = (adv-3)*(4+mod);
        accBuff = (adv-3)*(3+mod);
        defBuff = (adv-3)*(3+mod);
        ddgBuff = (adv-3)*(2+mod);

        mon.setHP(mon.getHP()+hpBuff);
        mon.setSTR(mon.getSTR()+strBuff);
        mon.setACC(mon.getACC()+accBuff);
        mon.setDEF(mon.getDEF()+defBuff);
        mon.setDDG(mon.getDDG()+ddgBuff);
    }
    else if(mon.getID()==58) // Endrigaia
    {
        hpBuff = (adv-3)*(5+mod);
        strBuff = (adv-3)*(3+mod);
        accBuff = (adv-3)*(4+mod);
        defBuff = (adv-3)*(2+mod);
        ddgBuff = (adv-3)*(2+mod);

        mon.setHP(mon.getHP()+hpBuff);
        mon.setSTR(mon.getSTR()+strBuff);
        mon.setACC(mon.getACC()+accBuff);
        mon.setDEF(mon.getDEF()+defBuff);
        mon.setDDG(mon.getDDG()+ddgBuff);
    }
    else if(mon.getID()==59) //Emeritus
    {
        hpBuff = (adv-3)*(3+mod);
        strBuff = (adv-3)*(5+mod);
        accBuff = (adv-3)*(3+mod);
        defBuff = (adv-3)*(2+mod);
        ddgBuff = (adv-3)*(3+mod);

        mon.setHP(mon.getHP()+hpBuff);
        mon.setSTR(mon.getSTR()+strBuff);
        mon.setACC(mon.getACC()+accBuff);
        mon.setDEF(mon.getDEF()+defBuff);
        mon.setDDG(mon.getDDG()+ddgBuff);
    }
    else if(mon.getID()==60) //Stiran
    {
        hpBuff = (adv-3)*(4+mod);
        strBuff = (adv-3)*(4+mod);
        accBuff = (adv-3)*(2+mod);
        defBuff = (adv-3)*(3+mod);
        ddgBuff = (adv-3)*(3+mod);

        mon.setHP(mon.getHP()+hpBuff);
        mon.setSTR(mon.getSTR()+strBuff);
        mon.setACC(mon.getACC()+accBuff);
        mon.setDEF(mon.getDEF()+defBuff);
        mon.setDDG(mon.getDDG()+ddgBuff);
    }
    else if(mon.getID()==61) //?????
    {
        hpBuff = (adv-3)*(5+mod);
        strBuff = (adv-3)*(3+mod);
        accBuff = (adv-3)*(2+mod);
        defBuff = (adv-3)*(3+mod);
        ddgBuff = (adv-3)*(3+mod);

        mon.setHP(mon.getHP()+hpBuff);
        mon.setSTR(mon.getSTR()+strBuff);
        mon.setACC(mon.getACC()+accBuff);
        mon.setDEF(mon.getDEF()+defBuff);
        mon.setDDG(mon.getDDG()+ddgBuff);
    }
    else if(mon.getID()==62) //Byralt
    {
        hpBuff = (adv-3)*(3+mod);
        strBuff = (adv-3)*(3+mod);
        accBuff = (adv-3)*(4+mod);
        defBuff = (adv-3)*(2+mod);
        ddgBuff = (adv-3)*(4+mod);

        mon.setHP(mon.getHP()+hpBuff);
        mon.setSTR(mon.getSTR()+strBuff);
        mon.setACC(mon.getACC()+accBuff);
        mon.setDEF(mon.getDEF()+defBuff);
        mon.setDDG(mon.getDDG()+ddgBuff);
    }
    else if(mon.getID()==63) //Halliot
    {
        hpBuff = (adv-3)*(4+mod);
        strBuff = (adv-3)*(3+mod);
        accBuff = (adv-3)*(3+mod);
        defBuff = (adv-3)*(4+mod);
        ddgBuff = (adv-3)*(2+mod);

        mon.setHP(mon.getHP()+hpBuff);
        mon.setSTR(mon.getSTR()+strBuff);
        mon.setACC(mon.getACC()+accBuff);
        mon.setDEF(mon.getDEF()+defBuff);
        mon.setDDG(mon.getDDG()+ddgBuff);
    }
}
