class Creature
{
protected:
    string name;
    int id;
    int hp;
    int str;
    int acc;
    int def;
    int ddg;
public:
    int level;
    Creature(){name="Null";level=-1;id=-1;hp=-1;str=-1;acc=-1;def=-1;ddg=-1;}
    Creature(string n, int l, int i, int h, int s, int a, int df, int dg)
    {name=n;level=l;id=i;hp=h;str=s;acc=a;def=df;ddg=dg;}
    Creature operator=(Creature c)
    {
        this->name = c.getName();
        this->level = c.getLEV();
        this->id = c.getID();
        this->hp = c.getHP();
        this->str = c.getSTR();
        this->acc = c.getACC();
        this->def = c.getDEF();
        this->ddg = c.getDDG();

        return *this;
    }
    string getName(){return name;}
    int getLEV(){return level;}
    int getID(){return id;}
    void setHP(int h){hp=h;}
    void changeHP(int delta){hp+=delta;}
    int getHP(){return hp;}
    int getSTR(){return str;}
    void setSTR(int s){str=s;}
    int getACC(){return acc;}
    void setACC(int a){acc=a;}
    int getDEF(){return def;}
    void setDEF(int d){def=d;}
    int getDDG(){return ddg;}
    void setDDG(int d){ddg=d;}
};

class Feature
{
protected:
    string name;
    vector<string> keywords;
    string description;
    int id;
    int item; //0 = None, 1 = Weapon, 2 = Armor, 3 = Consumable, 4 = Spell
    int luck; //0-3: Probability of items within
public:
    Feature(string n,string d,int idIn,int i,int l)
    {name=n;description=d;id=idIn;item=i;luck=l;}
    string getName(){return name;}
    string getDesc(){return description;}
    int getID(){return id;}
    void addKey(string key){keywords.push_back(key);}
    vector<string> getKeyList(){return keywords;}
    int getItem(){return item;}
    int getLuck(){return luck;}
};

class Item
{
protected:
    string name;
    string description;
    int rarity;
    int id;
public:
    Item(string n, string d, int r, int i)
    {name=n;description=d;rarity=r;id=i;}
    Item()
    {name="None";description="None.";rarity=-1;id=-1;}
    Item operator=(Item i)
    {
        this->name = i.getName();
        this->description = i.getDesc();
        this->rarity = i.getRarity();
        this->id = i.getID();
        return *this;
    }
    string getName(){return name;}
    string getDesc(){return description;}
    int getRarity(){return rarity;}
    int getID(){return id;}
};

class Weapon: public Item
{
public:
    Weapon(string n,string d,int r,int i,int s,int a,int c,int ma):Item(n,d,r,i)
    {strength=s;accuracy=a;critrate=c;magicamp=ma;}
    Weapon():Item()
    {strength=0;accuracy=0;critrate=0;magicamp=0;}
    int getStr(){return strength;}
    int getAcc(){return accuracy;}
    int getCrt(){return critrate;}
    int getMA(){return magicamp;}
    Weapon operator=(Weapon w)
    {
        this->name = w.getName();
        this->description = w.getDesc();
        this->rarity = w.getRarity();
        this->id = w.getID();
        this->strength = w.getStr();
        this->accuracy = w.getAcc();
        this->critrate = w.getCrt();
        this->magicamp = w.getMA();
        return *this;
    }
protected:
    int strength;
    int accuracy;
    int critrate;
    int magicamp;
};

class Armor: public Item
{
public:
    Armor(string n,string d,int r,int i,int df,int dg,int mg):Item(n,d,r,i)
    {defense=df;dodge=dg;managain=mg;}
    Armor():Item()
    {defense=0;dodge=0;managain=0;}
    int getDef(){return defense;}
    int getDdg(){return dodge;}
    int getMG(){return managain;}
    Armor operator=(Armor a)
    {
        this->name = a.getName();
        this->description = a.getDesc();
        this->rarity = a.getRarity();
        this->id = a.getID();
        this->defense = a.getDef();
        this->dodge = a.getDdg();
        this->managain = a.getMG();
        return *this;
    }
protected:
    int defense;
    int dodge;
    int managain;
};

class Consumable: public Item
{
public:
    Consumable(string n,string d,int r,int i,int h,int m):Item(n,d,r,i)
    {hprestored=h;mprestored=m;}
    int getHP(){return hprestored;}
    int getMP(){return mprestored;}
protected:
    int hprestored;
    int mprestored;
};

class Ring: public Item
{
public:
    Ring(string n,string d,int r,int i,int a,int h,int m):Item(n,d,r,i)
    {
        activation = a;
        hpr = h;
        mpr = m;
    }
    Ring():Item()
    {hpr=0;mpr=0;activation=0;}
    int getAct(){return activation;}
    int getHPR(){return hpr;}
    int getMPR(){return mpr;}
    int activate(int luck)
    {
        return activation+luck;
    }
    Ring operator=(Ring r)
    {
        this->name = r.getName();
        this->description = r.getDesc();
        this->rarity = r.getRarity();
        this->id = r.getID();
        this->hpr = r.getHPR();
        this->mpr = r.getMPR();
        this->activation = r.getAct();
        return *this;
    }
private:
    int activation;
    int hpr;
    int mpr;
};

class Merchant
{
protected:
    int level;
    bool unlocked;
    int type; //0 = Shop, 1 = Stat Swap
    int statCount;
public:
    vector<int> statUp;
    vector<int> statDown;
    Merchant(){level=-1;unlocked=0;type=0;}
    Merchant(int lv,int tp){level = lv;unlocked = 0;type = tp;statCount=0;}
    vector<int> storeInventory;
    vector<int> storeCost;
    int getLevel(){return level;}
    void setLevel(int l){level=l;}
    bool isUnlocked(){return unlocked;}
    void setUnlocked(bool u){unlocked=u;}
    int getType(){return type;}
    void incStatCount(){statCount++;}
    void setStatCount(int s){statCount=s;}
    int getStatCount(){return statCount;}
    vector<int> getStatUp(){return statUp;}
    vector<int> getStatDown(){return statDown;}
    int getSwapCost()
    {
        switch(statCount)
        {
            case 0:
                return 10;
            break;
            case 1:
                return 25;
            break;
            case 2:
                return 50;
            break;
            case 3:
                return 100;
            break;
            case 4:
                return 150;
            break;
            case 5:
                return 300;
            break;
            case 6:
                return 500;
            break;
            case 7:
                return 800;
            break;
            case 8:
                return 1000;
            break;
            case 9:
                return 1250;
            break;
            default:
                return 1500;
            break;
        }
        return -1;
    }
    void setStatSwap()
    {
        //0 = ATK, 1 = DEF, 2 = CRT, 3 = DDG, 4 = MHP, 5 = MMP
        for(int i=0;i<2;i++)
        {
            statUp.push_back(0);
            statDown.push_back(0);
            statUp[i] = rand() % 6;
            do {
                statDown[i] = rand() % 6;
            } while(statUp[i]==statDown[i]);
        }
        while(statUp[0]==statUp[1]||statUp[0]==statDown[0]||statUp[1]==statDown[1])
        {
            statUp[0] = rand() % 6;
        }
        while(statDown[0]==statDown[1]||statUp[0]==statDown[0]||statUp[1]==statDown[1])
        {
            statDown[0] = rand() % 6;
        }
        statCount = 0;
    }
    Merchant operator=(Merchant m)
    {
        this->storeInventory = m.storeInventory;
        this->storeCost = m.storeCost;
        this->level = m.getLevel();
        this->unlocked = m.isUnlocked();
        this->type = m.getType();
        this->statUp = m.getStatUp();
        this->statDown = m.getStatDown();
        this->statCount = m.getStatCount();
        return *this;
    }
};

class Room
{
protected:
    int id;
    string description;
public:
    vector<Feature> flist;
    vector<int> ilist;
    vector<string> blist;
    Creature monster;
    string doorDesc;
    vector<string> lootDesc;
    string creatDesc;
    string ascDesc;
    Merchant store;
    int contents;
    Room(){id=-1;description="Empty.";}
    Room(int i,string d)
    {id=i;description=d;}
    void setID(int i){id=i;}
    int getID(){return id;}
    string getDrDesc(){return doorDesc;}
    void setDrDesc(string d){doorDesc=d;}
    vector<string> getLDescList(){return lootDesc;}
    void setLDescList(vector<string> list){lootDesc=list;}
    void addLDesc(string loot){lootDesc.push_back(loot);}
    string getDesc(){return description;}
    void setDesc(string d){description=d;}
    vector<Feature> getFList(){return flist;}
    void setFList(vector<Feature> fl){flist=fl;}
    void addFeat(Feature feat){flist.push_back(feat);}
    Creature getCreature(){return monster;}
    void setCreature(Creature m){monster=m;}
    vector<int> getIList(){return ilist;}
    void setIList(vector<int> i){ilist=i;}
    void addItem(int i){ilist.push_back(i);}
    void delItem(int i){ilist.erase(ilist.begin()+i);}
    vector<string> getBList(){return blist;}
    void setBList(vector<string> b){blist=b;}
    void addBox(string b){blist.push_back(b);}
    void setMerchant(Merchant m){store=m;}
    Room operator=(Room r)
    {
        this->id = r.getID();
        this->description = r.getDesc();
        this->monster = r.getCreature();
        this->setFList(r.getFList());
        this->setIList(r.getIList());
        this->setBList(r.getBList());
        this->doorDesc = r.doorDesc;
        this->lootDesc = r.lootDesc;
        this->creatDesc = r.creatDesc;
        this->ascDesc = r.ascDesc;
        this->store = r.store;
        this->contents = r.contents;
        return *this;
    }
};

class Spell: public Item
{
public:
    Spell(string n, string d, int r, int i, int mc):Item(n,d,r,i)
    {manaCost=mc;}
    int getManaCost(){return manaCost;}
protected:
    int manaCost;
};

class HealingSpell: public Spell
{
public:
    HealingSpell(string n, string d, int r, int i, int mc, int hpr):Spell(n,d,r,i,mc)
    {hpRestored=hpr;}
    int getHPR(){return hpRestored;}
protected:
    int hpRestored;
};

class AttackSpell: public Spell
{
public:
    AttackSpell(string n, string d, int r, int i, int mc, int dm):Spell(n,d,r,i,mc)
    {dmg=dm;}
    int getDMG(){return dmg;}
protected:
    int dmg;
};

class BuffSpell: public Spell
{
public:
    BuffSpell(string n, string d, int r, int i, int mc, int atu, int dfu, int cu, int acu, int dgu):Spell(n,d,r,i,mc)
    {atkUp=atu;defUp=dfu;crtUp=cu;accUp=acu;ddgUp=dgu;}
    int getATKU(){return atkUp;}
    int getDEFU(){return defUp;}
    int getCRTU(){return crtUp;}
    int getACCU(){return accUp;}
    int getDDGU(){return ddgUp;}
protected:
    int atkUp;
    int defUp;
    int crtUp;
    int accUp;
    int ddgUp;
};

class Buff
{
public:
    Buff(string nm, int atu, int dfu, int cu, int acu, int dgu, int hpu)
    {name=nm;atkUp=atu;defUp=dfu;crtUp=cu;accUp=acu;ddgUp=dgu;hpUp=hpu;counter=6;}
    Buff(string nm, int atu, int dfu, int cu, int acu, int dgu, int hpu, int c)
    {name=nm;atkUp=atu;defUp=dfu;crtUp=cu;accUp=acu;ddgUp=dgu;hpUp=hpu;counter=c;}
    Buff()
    {name="Null";atkUp=0;defUp=0;crtUp=0;accUp=0;ddgUp=0;hpUp=0;counter=200;}
    int getCount(){return counter;}
    void tick(){counter-=1;}
    string getName(){return name;}
    int getATKU(){return atkUp;}
    int getDEFU(){return defUp;}
    int getCRTU(){return crtUp;}
    int getACCU(){return accUp;}
    int getDDGU(){return ddgUp;}
    int getHPU(){return hpUp;}
    void setName(string n){name=n;}
    void setCount(int c){counter=c;}
protected:
    int counter;
    string name;
    int atkUp;
    int defUp;
    int crtUp;
    int accUp;
    int ddgUp;
    int hpUp;
};

class Player: public Creature
{
public:
    Player(string n, int l, int i, int h, int m, int s, int a, int c, int df, int dg, int lk, int g, int k, int e): Creature(n,l,i,h,s,a,df,dg)
    {
        hp = h;mhp=hp;mp = m;mmp = mp;nstr = s;nacc = a;crit = c;ncrit = c;ndef = df;nddg = dg;level = l;gold = g;keys = k;exp=e;expGoal=20;empowered=0;growth=0;lck=lk;meleeTraining=-1;magicTraining=-1;
    }
    void changeMP(int delta){mp+=delta;}
    void setMP(int m){mp=m;}
    int getMP(){return mp;}
    int getMMP(){return mmp;}
    int getMHP(){return mhp;}
    int getNSTR(){return nstr;}
    int getNACC(){return nacc;}
    int getCRT(){return crit;}
    int getNCRT(){return ncrit;}
    int getNDEF(){return ndef;}
    int getNDDG(){return nddg;}
    int getLCK(){return lck;}
    void setMMP(int m){mmp=m;}
    void setMHP(int m){mhp=m;}
    void setNSTR(int s){nstr=s;}
    void setNCRT(int c){ncrit=c;}
    void setNDEF(int d){ndef=d;}
    void setNDDG(int d){nddg=d;}
    void setLCK(int l){lck=l;}
    int getMG()
    {
        int gain=0;
        if(mask.getID()==3)
            gain+=5;
        if(growth>0)
            gain+=2;
        return eqpAmr.getMG()+gain+eqpRng.getMPR();
    }
    int getMA()
    {
        if(mask.getID()==2)
            return eqpWpn.getMA() + 50;
        return eqpWpn.getMA();
    }
    int getEXPGoal(){return expGoal;}
    void setEXPGoal(int g){expGoal=g;}
    void equipAmr(Armor amr)
    {
        if(mask.getID()!=7)
            eqpAmr=amr;
        def=amr.getDef()+ndef;
        ddg=amr.getDdg()+nddg;

        if(eqpWpn.getName()=="Ordointh"&&eqpAmr.getName()=="Robe of the Archmage")
            ach.SorcererSupreme = 1;
        if(eqpWpn.getName()=="Teratra"&&eqpAmr.getName()=="Shield of the Conquerer")
            ach.Conquerer = 1;
        if((eqpWpn.getName()=="Hyliat"||eqpWpn.getName()=="Pyrithia")&&eqpAmr.getName()=="Plate of the Vanguard")
            ach.Vanguard = 1;
        if(eqpWpn.getName()=="Aerolinde"&&eqpAmr.getName()=="Cloak of the Whisper")
            ach.Whisper = 1;
        if(eqpWpn.getName()=="Chaotrix"&&eqpAmr.getName()=="Helm of the Ancients")
            ach.AncientPower = 1;
    }
    void equipWpn(Weapon wpn)
    {
        eqpWpn=wpn;

        str=wpn.getStr()+nstr;
        acc=wpn.getAcc();
        crit=wpn.getCrt()+ncrit;

        if(eqpWpn.getName()=="Ordointh"&&eqpAmr.getName()=="Robe of the Archmage")
            ach.SorcererSupreme = 1;
        if(eqpWpn.getName()=="Teratra"&&eqpAmr.getName()=="Shield of the Conquerer")
            ach.Conquerer = 1;
        if((eqpWpn.getName()=="Hyliat"||eqpWpn.getName()=="Pyrithia")&&eqpAmr.getName()=="Plate of the Vanguard")
            ach.Vanguard = 1;
        if(eqpWpn.getName()=="Aerolinde"&&eqpAmr.getName()=="Cloak of the Whisper")
            ach.Whisper = 1;
        if(eqpWpn.getName()=="Chaotrix"&&eqpAmr.getName()=="Helm of the Ancients")
            ach.AncientPower = 1;
    }
    void equipRng(Ring rng)
    {
        eqpRng = rng;
    }
    vector<int> equipment;
    vector<int> inventory;
    vector<int> spellbook;
    int gold;
    int exp;
    int keys;
    int growth;
    bool empowered;
    Item mask;
    int meleeTraining; // -1 = None, 0 = Dagger, 1 = Spear, 2 = Sword, 3 = Axe
    int magicTraining; // -1 = None, 0 = Frost, 1 = Fire, 2 = Lightning
    Weapon eqpWpn;
    Armor eqpAmr;
    Ring eqpRng;
    void levelUp()
    {
        level++;
        int mod=0;
        if(mask.getID()==7)
            mod = level/7;
        int boost;
        score += 100;
        cout << endl << "Level Up!!" << endl;

        boost = rand() % 3 + 4 + mod;
        mhp += boost;
        hp = mhp;
        cout << "HP went up by " << boost << "!" << endl;

        boost = rand() % 3 + 4 + mod;
        mmp += boost;
        cout << "MP went up by " << boost << "!" << endl;

        switch(rand()%6)
        {
            case 0:
                nstr += mod;
                if(mod>0)
                    cout << "STR went up by " << mod << "!" << endl;
                break;
            case 1:case 2:case 3:
                nstr += mod + 1;
                cout << "STR went up by " << mod+1 << "!" << endl;
                break;
            case 4:case 5:
                nstr += mod + 2;
                cout << "STR went up by " << mod+2 << "!" << endl;
                break;
        }

        switch(rand()%6)
        {
            case 0:
                ncrit += mod;
                if(mod>0)
                    cout << "CRT went up by " << mod << "!" << endl;
                break;
            case 1:case 2:case 3:
                ncrit += mod + 1;
                cout << "CRT went up by " << mod+1 << "!" << endl;
                break;
            case 4:case 5:
                ncrit += mod + 2;
                cout << "CRT went up by " << mod+2 << "!" << endl;
                break;
        }

        if(mask.getID()==7) //SOULS
        {
            switch(rand()%6)
            {
                case 0:
                    nacc += mod;
                    if(mod>0)
                        cout << "ACC went up by " << mod << "!" << endl;
                    break;
                case 1:case 2:case 3:
                    nacc += mod + 1;
                    cout << "ACC went up by " << mod+1 << "!" << endl;
                    break;
                case 4:case 5:
                    nacc += mod + 2;
                    cout << "ACC went up by " << mod+2 << "!" << endl;
                    break;
            }
            setACC(nacc);
        }

        switch(rand()%6)
        {
            case 0:
                ndef += mod;
                if(mod>0)
                    cout << "DEF went up by " << mod << "!" << endl;
                break;
            case 1:case 2:case 3:
                ndef += mod + 1;
                cout << "DEF went up by " << mod+1 << "!" << endl;
                break;
            case 4:case 5:
                ndef += mod + 2;
                cout << "DEF went up by " << mod+2 << "!" << endl;
                break;
        }

        if(mask.getID()==5) //Whispers
        {
            switch(rand()%8)
            {
                case 0:
                    nddg += mod + 2;
                    cout << "DDG went up by " << mod+2 << "!" << endl;
                    break;
                case 1:case 2:
                    nddg += mod + 3;
                    cout << "DDG went up by " << mod+3 << "!" << endl;
                    break;
                case 3:case 4:case 5:
                    nddg += mod + 4;
                    cout << "DDG went up by " << mod+4 << "!" << endl;
                    break;
                case 6:case 7:
                    nddg += mod + 5;
                    cout << "DDG went up by " << mod+5 << "!" << endl;
                    break;
            }
        }
        else
        {
            switch(rand()%6)
            {
                case 0:
                    nddg += mod;
                    if(mod>0)
                        cout << "DDG went up by " << mod << "!" << endl;
                    break;
                case 1:case 2:case 3:
                    nddg += mod + 1;
                    cout << "DDG went up by " << mod+1 << "!" << endl;
                    break;
                case 4:case 5:
                    nddg += mod + 2;
                    cout << "DDG went up by " << mod+2 << "!" << endl;
                    break;
            }
        }

        if(mask.getID()==1)
        {
            switch(rand()%8)
            {
                case 0:
                    lck += mod + 2;
                    cout << "LCK went up by " << mod+2 << "!" << endl;
                    break;
                case 1:case 2:
                    lck += mod + 3;
                    cout << "LCK went up by " << mod+3 << "!" << endl;
                    break;
                case 3:case 4:case 5:
                    lck += mod + 4;
                    cout << "LCK went up by " << mod+4 << "!" << endl;
                    break;
                case 6:case 7:
                    lck += mod + 5;
                    cout << "LCK went up by " << mod+5 << "!" << endl;
                    break;
            }
        }
        else
        {
            switch(rand()%6)
            {
                case 0:
                    lck += mod;
                    if(mod>0)
                        cout << "LCK went up by " << mod << "!" << endl;
                    break;
                case 1:case 2:case 3:
                    lck += mod + 1;
                    cout << "LCK went up by " << mod+1 << "!" << endl;
                    break;
                case 4:case 5:
                    lck += mod + 2;
                    cout << "LCK went up by " << mod+2 << "!" << endl;
                    break;
            }
        }

        str=eqpWpn.getStr()+nstr;
        crit=eqpWpn.getCrt()+ncrit;
        def=eqpAmr.getDef()+ndef;
        ddg=eqpAmr.getDdg()+nddg;

        exp -= expGoal;
        expGoal += 20;
    }
    void Empower()
    {
        nstr += 5;
        ncrit += 5;
        if(mask.getID()==7) //SOULS
            nacc += 5;
        ndef += 5;
        nddg += 5;

        str=eqpWpn.getStr()+nstr;
        crit=eqpWpn.getCrt()+ncrit;
        def=eqpAmr.getDef()+ndef;
        ddg=eqpAmr.getDdg()+nddg;

        lck += 2;
        empowered = 1;
    }
    void Boost()
    {
        mhp += 2;
        mmp += 2;
        nstr += 2;
        ncrit += 2;
        if(mask.getID()==7) //SOULS
            nacc += 2;
        ndef += 2;
        nddg += 2;
        lck += 2;
    }
protected:
    int mhp;
    int mp;
    int mmp;
    int nstr;
    int nacc;
    int crit;
    int ncrit;
    int ndef;
    int nddg;
    int lck;
    int expGoal;
};

class Directory
{
public:
    vector<Weapon> weaponDirectory;
    vector<Armor> armorDirectory;
    vector<Consumable> consumableDirectory;
    vector<Item> maskDirectory;
    vector<AttackSpell> attackSpellDirectory;
    vector<HealingSpell> healingSpellDirectory;
    vector<BuffSpell> buffSpellDirectory;
    vector<Creature> creatureDirectory;
    vector<Feature> featureDirectory;
    vector<Room> roomDirectory;
    vector<Ring> ringDirectory;
    Directory(vector<Weapon> w, vector<Armor> a, vector<Consumable> c, vector<Item> m, vector<AttackSpell> as, vector<HealingSpell> hs, vector<BuffSpell> bs, vector<Creature> cr, vector<Feature> f, vector<Room> r, vector<Ring> rn)
    {weaponDirectory=w;armorDirectory=a;consumableDirectory=c;maskDirectory=m;attackSpellDirectory=as;healingSpellDirectory=hs;buffSpellDirectory=bs;creatureDirectory=cr;featureDirectory=f;roomDirectory=r;ringDirectory=rn;}
    string getItemName(int i)
    {
        if(i<100)
            return weaponDirectory[i].getName();
        else if(i<200)
            return armorDirectory[i-100].getName();
        else if(i<300)
            return consumableDirectory[i-200].getName();
        else if(i<315)
            return attackSpellDirectory[i-300].getName();
        else if(i<321)
            return healingSpellDirectory[i-315].getName();
        else if(i<=343)
            return buffSpellDirectory[i-321].getName();
        else if(i<=435)
            return ringDirectory[i-400].getName();
        else
            return "Error";
    }
    string getItemDesc(int i)
    {
        if(i<100)
            return weaponDirectory[i].getDesc();
        else if(i<200)
            return armorDirectory[i-100].getDesc();
        else if(i<300)
            return consumableDirectory[i-200].getDesc();
        else if(i<315)
            return attackSpellDirectory[i-300].getDesc();
        else if(i<321)
            return healingSpellDirectory[i-315].getDesc();
        else if(i<=343)
            return buffSpellDirectory[i-321].getDesc();
        else if(i<=435)
            return ringDirectory[i-400].getDesc();
        else
            return "Error";
    }
    int getItemRarity(int i)
    {
        if(i<100)
            return weaponDirectory[i].getRarity();
        else if(i<200)
            return armorDirectory[i-100].getRarity();
        else if(i<300)
            return consumableDirectory[i-200].getRarity();
        else if(i<315)
            return attackSpellDirectory[i-300].getRarity();
        else if(i<321)
            return healingSpellDirectory[i-315].getRarity();
        else if(i<=343)
            return buffSpellDirectory[i-321].getRarity();
        else if(i<=435)
            return ringDirectory[i-400].getRarity();
        else
            return 0;
    }
};
