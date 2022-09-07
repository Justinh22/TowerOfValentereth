class Achievements
{
public:
    Achievements()
    {
        string line;
        int value;
        int i=0;
        achVals.clear();
        complete.clear();
        unlocked.clear();
        std::ifstream ach(".achievements.txt");
        while(std::getline(ach,line))
        {
            std::stringstream data(line);
            data >> value;
            achVals.push_back(value);
            i++;
        }
        Connoisseur = achVals[0];
        complete.push_back(Connoisseur>=20);
        Alchemist = achVals[1];
        complete.push_back(Alchemist>=50);
        Expert = achVals[2];
        complete.push_back(Expert>=50);
        DejaVu = achVals[3];
        complete.push_back(DejaVu>=10);
        RiseAndShine = achVals[4];
        complete.push_back(RiseAndShine>=25);
        Powerhouse = achVals[5];
        complete.push_back(Powerhouse==1);
        Tyrant = achVals[6];
        complete.push_back(Tyrant==1);
        Horror = achVals[7];
        complete.push_back(Horror==1);
        Mercenary = achVals[8];
        complete.push_back(Mercenary==1);
        Beast = achVals[9];
        complete.push_back(Beast==1);
        Scion = achVals[10];
        complete.push_back(Scion==1);
        Archmage = achVals[11];
        complete.push_back(Archmage==1);
        NaturesWrath = achVals[12];
        complete.push_back(NaturesWrath==1);
        Ascended = achVals[13];
        complete.push_back(Ascended==1);
        Unstoppable = achVals[14];
        complete.push_back(Unstoppable>=100);
        Nuke = achVals[15];
        complete.push_back(Nuke==1);
        Overkill = achVals[16];
        complete.push_back(Overkill==1);
        Necromancy = achVals[17];
        complete.push_back(Necromancy==1);
        SorcererSupreme = achVals[18];
        complete.push_back(SorcererSupreme==1);
        Conquerer = achVals[19];
        complete.push_back(Conquerer==1);
        Vanguard = achVals[20];
        complete.push_back(Vanguard==1);
        Whisper = achVals[21];
        complete.push_back(Whisper==1);
        AncientPower = achVals[22];
        complete.push_back(AncientPower==1);
        GlassTriumph = achVals[23];
        complete.push_back(GlassTriumph==1);
        FateTriumph = achVals[24];
        complete.push_back(FateTriumph==1);
        DarknessTriumph = achVals[25];
        complete.push_back(DarknessTriumph==1);
        ArcanaTriumph = achVals[26];
        complete.push_back(ArcanaTriumph==1);
        SteelTriumph = achVals[27];
        complete.push_back(SteelTriumph==1);
        WhispersTriumph = achVals[28];
        complete.push_back(WhispersTriumph==1);
        BeastsTriumph = achVals[29];
        complete.push_back(BeastsTriumph==1);
        SoulsTriumph = achVals[30];
        complete.push_back(SoulsTriumph==1);
        Gank = achVals[31];
        complete.push_back(Gank==1);
        SpectrumTriumph = achVals[32];
        complete.push_back(SpectrumTriumph==8);
        CurseBearer = achVals[33];
        complete.push_back(CurseBearer==1);
        TrueHeir = achVals[34];
        complete.push_back(TrueHeir==1);
        Watcher = achVals[35];
        complete.push_back(Watcher==1);
        Vale = achVals[36];
        complete.push_back(1);
        ach.close();
    }
    writeAchievements()
    {
        std::ofstream ach(".achievements.txt");
        ach << Connoisseur << " Connoisseur\n";
        ach << Alchemist << " Alchemist\n";
        ach << Expert << " Expert\n";
        ach << DejaVu << " DejaVu\n";
        ach << RiseAndShine << " RiseAndShine\n";
        ach << Powerhouse << " Powerhouse\n";
        ach << Tyrant << " Tyrant\n";
        ach << Horror << " Horror\n";
        ach << Mercenary << " Mercenary\n";
        ach << Beast << " Beast\n";
        ach << Scion << " Scion\n";
        ach << Archmage << " Archmage\n";
        ach << NaturesWrath << " NaturesWrath\n";
        ach << Ascended << " Ascended\n";
        ach << Unstoppable << " Unstoppable\n";
        ach << Nuke << " Nuke\n";
        ach << Overkill << " Overkill\n";
        ach << Necromancy << " Necromancy\n";
        ach << SorcererSupreme << " SorcererSupreme\n";
        ach << Conquerer << " Conquerer\n";
        ach << Vanguard << " Vanguard\n";
        ach << Whisper << " Whisper\n";
        ach << AncientPower << " AncientPower\n";
        ach << GlassTriumph << " GlassTriumph\n";
        ach << FateTriumph << " FateTriumph\n";
        ach << DarknessTriumph << " DarknessTriumph\n";
        ach << ArcanaTriumph << " ArcanaTriumph\n";
        ach << SteelTriumph << " SteelTriumph\n";
        ach << WhispersTriumph << " WhispersTriumph\n";
        ach << BeastsTriumph << " BeastsTriumph\n";
        ach << SoulsTriumph << " SoulsTriumph\n";
        ach << Gank << " Gank\n";
        ach << SpectrumTriumph << " SpectrumTriumph\n";
        ach << TrueHeir << " TrueHeir\n";
        ach << CurseBearer << " CurseBearer\n";
        ach << Watcher << " Watcher\n";
        ach << Vale << " Vale\n";
        ach << UnlockHeal << " UnlockHeal\n";
        ach << UnlockJolt << " UnlockJolt\n";
        ach << UnlockHealingPot << " UnlockHealingPot\n";
        ach << UnlockCalmingPot << " UnlockCalmingPot\n";
        ach << UnlockSword << " UnlockSword\n";
        ach << UnlockArmor << " UnlockArmor\n";
        ach << UnlockMelee << " UnlockMelee\n";
        ach << UnlockMagic << " UnlockMagic\n";
        ach << UnlockRing << " UnlockRing\n";
        ach.close();
    }
    calculatePoints()
    {
        points = 0;
        if(complete[0])
            points += 10;
        if(complete[1])
            points += 10;
        if(complete[2])
            points += 10;
        if(complete[3])
            points += 10;
        if(complete[4])
            points += 20;
        if(complete[5])
            points += 20;
        if(complete[6])
            points += 30;
        if(complete[7])
            points += 15;
        if(complete[8])
            points += 15;
        if(complete[9])
            points += 15;
        if(complete[10])
            points += 15;
        if(complete[11])
            points += 15;
        if(complete[12])
            points += 15;
        if(complete[13])
            points += 15;
        if(complete[14])
            points += 20;
        if(complete[15])
            points += 25;
        if(complete[16])
            points += 25;
        if(complete[17])
            points += 25;
        if(complete[18])
            points += 25;
        if(complete[19])
            points += 25;
        if(complete[20])
            points += 25;
        if(complete[21])
            points += 25;
        if(complete[22])
            points += 25;
        if(complete[23])
            points += 40;
        if(complete[24])
            points += 40;
        if(complete[25])
            points += 40;
        if(complete[26])
            points += 40;
        if(complete[27])
            points += 40;
        if(complete[28])
            points += 40;
        if(complete[29])
            points += 40;
        if(complete[30])
            points += 40;
        if(complete[31])
            points += 30;
        if(complete[32])
            points += 60;
        if(complete[33])
            points += 50;
        if(complete[34])
            points += 50;
        if(complete[35])
            points += 50;
    }
    vector<int> achVals;
    vector<bool> complete;
    vector<bool> unlocked;
    int points;
    int Connoisseur;
    int Alchemist;
    int Expert;
    int DejaVu;
    int RiseAndShine;
    int Powerhouse;
    int Tyrant;
    int Horror;
    int Mercenary;
    int Beast;
    int Scion;
    int Archmage;
    int NaturesWrath;
    int Ascended;
    int Unstoppable;
    int Nuke;
    int Overkill;
    int Necromancy;
    int SorcererSupreme;
    int Conquerer;
    int Vanguard;
    int Whisper;
    int AncientPower;
    int GlassTriumph;
    int FateTriumph;
    int DarknessTriumph;
    int ArcanaTriumph;
    int SteelTriumph;
    int WhispersTriumph;
    int BeastsTriumph;
    int SoulsTriumph;
    int Gank;
    int SpectrumTriumph;
    int CurseBearer
    int TrueHeir;
    int Watcher;
    int Vale;
    int UnlockHeal;
    int UnlockJolt;
    int UnlockHealingPot;
    int UnlockCalmingPot;
    int UnlockSword;
    int UnlockArmor;
    int UnlockMelee;
    int UnlockMagic;
    int UnlockRing;
};
