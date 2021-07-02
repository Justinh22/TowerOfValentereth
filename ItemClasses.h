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
    int item; //0 = None, 1 = Weapon, 2 = Armor, 3 = Consumable, 4 = Spell
    int luck; //0-3: Probability of items within
public:
    Feature(string n,string d,int i,int l)
    {name=n;description=d;item=i;luck=l;}
    string getName(){return name;}
    string getDesc(){return description;}
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

class Merchant
{
protected:
    int level;
    bool unlocked;
public:
    Merchant(){level=-1;unlocked=0;}
    Merchant(int lv){level = lv;unlocked = 0;}
    vector<int> storeInventory;
    vector<int> storeCost;
    int getLevel(){return level;}
    bool isUnlocked(){return unlocked;}
    void setUnlocked(bool u){unlocked=u;}
    Merchant operator=(Merchant m)
    {
        this->storeInventory = m.storeInventory;
        this->storeCost = m.storeCost;
        this->level = m.getLevel();
        this->unlocked = m.isUnlocked();
        return *this;
    }
};

class Room
{
protected:
    int id;
    string description;
    vector<Feature> flist;
    vector<int> ilist;
    vector<string> blist;
public:
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
    int getCount(){return counter;}
    void tick(){counter-=1;}
    string getName(){return name;}
    int getATKU(){return atkUp;}
    int getDEFU(){return defUp;}
    int getCRTU(){return crtUp;}
    int getACCU(){return accUp;}
    int getDDGU(){return ddgUp;}
    int getHPU(){return hpUp;}
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
    Player(string n, int l, int i, int h, int m, int s, int a, int c, int df, int dg, int g, int k, int e): Creature(n,l,i,h,s,a,df,dg)
    {
        hp = h;mhp=hp;mp = m;mmp = mp;nstr = s;nacc = a;crit = c;ncrit = c;ndef = df;nddg = dg;level = l;gold = g;keys = k;exp=e;expGoal=20;empowered=0;
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
    int getMG()
    {
        if(mask.getID()==3)
            return eqpAmr.getMG()+5;
        return eqpAmr.getMG();
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
        if(mask.getID()==5) //Whispers
        {
            def=amr.getDef()+ndef;
            ddg=(amr.getDdg()+nddg)+((amr.getDdg()+nddg)/2);
        }
        else
        {
            def=amr.getDef()+ndef;
            ddg=amr.getDdg()+nddg;
        }
    }
    void equipWpn(Weapon wpn)
    {
        eqpWpn=wpn;
        if(mask.getID()==1) //Wrath
        {
            str=wpn.getStr()+(nstr+(nstr/2));
            acc=wpn.getAcc()-20;
            crit=wpn.getCrt()+(ncrit+(ncrit/2));
        }
        else
        {
            str=wpn.getStr()+nstr;
            acc=wpn.getAcc();
            crit=wpn.getCrt()+ncrit;
        }
    }
    vector<int> equipment;
    vector<int> inventory;
    vector<int> spellbook;
    int gold;
    int exp;
    int keys;
    bool empowered;
    Item mask;
    Weapon eqpWpn;
    Armor eqpAmr;
    void levelUp()
    {
        int boost;
        cout << endl << "Level Up!!" << endl;
        boost = rand() % 5 + 2;
        mhp += boost;
        hp = mhp;
        cout << "HP went up by " << boost << "!" << endl;
        boost = rand() % 5 + 2;
        mmp += boost;
        cout << "MP went up by " << boost << "!" << endl;
        boost = rand() % 3;
        nstr += boost;
        if(boost!=0)
            cout << "STR went up by " << boost << "!" << endl;
        boost = rand() % 3;
        ncrit += boost;
        if(boost!=0)
            cout << "CRT went up by " << boost << "!" << endl;
        boost = rand() % 3;
        ndef += boost;
        if(boost!=0)
            cout << "DEF went up by " << boost << "!" << endl;
        boost = rand() % 3;
        nddg += boost;
        if(boost!=0)
            cout << "DDG went up by " << boost << "!" << endl;

        if(mask.getID()==5) //Whispers
        {
            str=eqpWpn.getStr()+nstr;
            crit=eqpWpn.getCrt()+ncrit;
            def=eqpAmr.getDef()+ndef;
            ddg=(eqpAmr.getDdg()+nddg)+((eqpAmr.getDdg()+nddg)/2);
        }
        else if(mask.getID()==1) //Wrath
        {
            str=eqpWpn.getStr()+(nstr+(nstr/2));
            crit=eqpWpn.getCrt()+(ncrit+(ncrit/2));
            def=eqpAmr.getDef()+ndef;
            ddg=eqpAmr.getDdg()+nddg;
        }
        else
        {
            str=eqpWpn.getStr()+nstr;
            crit=eqpWpn.getCrt()+ncrit;
            def=eqpAmr.getDef()+ndef;
            ddg=eqpAmr.getDdg()+nddg;
        }

        level++;
        exp -= expGoal;
        expGoal += 20;
    }
    void Empower()
    {
        nstr += 5;
        ncrit += 5;
        ndef += 5;
        nddg += 5;

        if(mask.getID()==5) //Whispers
        {
            str=eqpWpn.getStr()+nstr;
            crit=eqpWpn.getCrt()+ncrit;
            def=eqpAmr.getDef()+ndef;
            ddg=(eqpAmr.getDdg()+nddg)+((eqpAmr.getDdg()+nddg)/2);
        }
        else if(mask.getID()==1) //Wrath
        {
            str=eqpWpn.getStr()+(nstr+(nstr/2));
            crit=eqpWpn.getCrt()+(ncrit+(ncrit/2));
            def=eqpAmr.getDef()+ndef;
            ddg=eqpAmr.getDdg()+nddg;
        }
        else
        {
            str=eqpWpn.getStr()+nstr;
            crit=eqpWpn.getCrt()+ncrit;
            def=eqpAmr.getDef()+ndef;
            ddg=eqpAmr.getDdg()+nddg;
        }
        empowered = 1;
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
    Directory(vector<Weapon> w, vector<Armor> a, vector<Consumable> c, vector<Item> m, vector<AttackSpell> as, vector<HealingSpell> hs, vector<BuffSpell> bs, vector<Creature> cr, vector<Feature> f, vector<Room> r)
    {weaponDirectory=w;armorDirectory=a;consumableDirectory=c;maskDirectory=m;attackSpellDirectory=as;healingSpellDirectory=hs;buffSpellDirectory=bs;creatureDirectory=cr;featureDirectory=f;roomDirectory=r;}
    string getItemName(int i)
    {
        if(i<=56)
            return weaponDirectory[i].getName();
        else if(i<=98)
            return armorDirectory[i-57].getName();
        else if(i<=112)
            return consumableDirectory[i-100].getName();
        else if(i<=214)
            return attackSpellDirectory[i-200].getName();
        else if(i<=220)
            return healingSpellDirectory[i-215].getName();
        else if(i<=229)
            return buffSpellDirectory[i-221].getName();
        else
            return "Error";
    }
    string getItemDesc(int i)
    {
        if(i<=56)
            return weaponDirectory[i].getDesc();
        else if(i<=98)
            return armorDirectory[i-57].getDesc();
        else if(i<=112)
            return consumableDirectory[i-100].getDesc();
        else if(i<=214)
            return attackSpellDirectory[i-200].getDesc();
        else if(i<=220)
            return healingSpellDirectory[i-215].getDesc();
        else if(i<=229)
            return buffSpellDirectory[i-221].getDesc();
        else
            return "Error";
    }
    int getItemRarity(int i)
    {
        if(i<=56)
            return weaponDirectory[i].getRarity();
        else if(i<=98)
            return armorDirectory[i-57].getRarity();
        else if(i<=112)
            return consumableDirectory[i-100].getRarity();
        else if(i<=214)
            return attackSpellDirectory[i-200].getRarity();
        else if(i<=220)
            return healingSpellDirectory[i-215].getRarity();
        else if(i<=229)
            return buffSpellDirectory[i-221].getRarity();
        else
            return 0;
    }
};
