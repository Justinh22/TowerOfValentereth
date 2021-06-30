vector<AttackSpell> initASDir(vector<AttackSpell> attackSpellDirectory)
{
    AttackSpell Jolt("Jolt","Fires a small jolt of lightning at a target.",1,200,4,10);
    attackSpellDirectory.push_back(Jolt);
    AttackSpell Ember("Ember","Fires a small burst of flame at a target.",1,201,3,8);
    attackSpellDirectory.push_back(Ember);
    AttackSpell Chill("Chill","Fires a small burst of cold at a target.",1,202,2,6);
    attackSpellDirectory.push_back(Chill);
    AttackSpell Thunderbolt("Thunderbolt","Fires a bolt of lightning at a target.",2,203,8,16);
    attackSpellDirectory.push_back(Thunderbolt);
    AttackSpell Firebolt("Firebolt","Fires a bolt of fire at a target.",2,204,7,14);
    attackSpellDirectory.push_back(Firebolt);
    AttackSpell Frostbolt("Frostbolt","Fires a bolt of freezing energy at a target.",2,205,6,12);
    attackSpellDirectory.push_back(Frostbolt);
    AttackSpell Lightning_Strike("Lightning Strike","Strikes down a bolt of lightning at a target.",3,206,12,22);
    attackSpellDirectory.push_back(Lightning_Strike);
    AttackSpell Fireball("Fireball","Hurls a fireball at a target.",3,207,11,20);
    attackSpellDirectory.push_back(Fireball);
    AttackSpell Freeze("Freeze","Launches a blast of freezing magic at a target.",3,208,10,18);
    attackSpellDirectory.push_back(Freeze);
    AttackSpell Electrocute("Electrocute","Unleashes a massive jolt of electricity at a target.",4,209,16,28);
    attackSpellDirectory.push_back(Electrocute);
    AttackSpell Fire_Blast("Fire Blast","Unleashes a blast of flame at a target.",4,210,15,26);
    attackSpellDirectory.push_back(Fire_Blast);
    AttackSpell Cryo_Beam("Cryo Beam","Fires a beam of pure freezing magic at a target.",4,211,14,24);
    attackSpellDirectory.push_back(Cryo_Beam);
    AttackSpell Thunderstorm("Thunderstorm","Calls down a raging storm to electrify a target.",5,212,20,34);
    attackSpellDirectory.push_back(Thunderstorm);
    AttackSpell Inferno("Inferno","Calls a raging inferno to incinerate a target.",5,213,19,32);
    attackSpellDirectory.push_back(Inferno);
    AttackSpell Blizzard("Blizzard","Calls a raging blizzard to freeze a target.",5,214,18,30);
    attackSpellDirectory.push_back(Blizzard);

    //cout << "Spell List Initialized! (1/3)" << endl;

    return attackSpellDirectory;
}


vector<HealingSpell> initHSDir(vector<HealingSpell> healingSpellDirectory)
{
    //1

    HealingSpell Minor_Heal("Minor Heal","Heals for a small amount of health.",1,215,4,10);
    healingSpellDirectory.push_back(Minor_Heal);
    HealingSpell Heal("Heal","Heals for a moderate amount of health.",2,216,10,35);
    healingSpellDirectory.push_back(Heal);
    HealingSpell Minor_Regenerate("Minor Regenerate","Heals for a small amount of health over time.",2,217,10,6);
    healingSpellDirectory.push_back(Minor_Regenerate);
    HealingSpell Regenerate("Regenerate","Heals for a moderate amount of health over time.",3,218,16,12);
    healingSpellDirectory.push_back(Regenerate);
    HealingSpell Major_Heal("Major Heal","Heals for a large amount of health.",4,219,16,80);
    healingSpellDirectory.push_back(Major_Heal);
    HealingSpell Major_Regenerate("Major Regenerate","Heals for a large amount of health over time.",5,220,24,30);
    healingSpellDirectory.push_back(Major_Regenerate);

    //cout << "Spell List Initialized! (2/3)" << endl;

    return healingSpellDirectory;
}

vector<BuffSpell> initBSDir(vector<BuffSpell> buffSpellDirectory)
{

    BuffSpell Rage("Rage","Increases your Atk by 5.",1,221,6,5,0,0,0,0);
    buffSpellDirectory.push_back(Rage);
    BuffSpell Brace("Brace","Increases your Def by 5.",1,222,6,0,5,0,0,0);
    buffSpellDirectory.push_back(Brace);
    BuffSpell Focus("Focus","Increases your Acc by 15.",2,223,8,0,0,0,15,0);
    buffSpellDirectory.push_back(Focus);
    BuffSpell Speed("Speed","Increases your Ddg by 15.",2,224,8,0,0,0,0,15);
    buffSpellDirectory.push_back(Speed);
    BuffSpell Luck("Luck","Increases your Crt by 15.",3,225,10,0,0,15,0,0);
    buffSpellDirectory.push_back(Luck);
    BuffSpell Rage_II("Rage II","Increases your Atk by 10.",4,226,12,10,0,0,0,0);
    buffSpellDirectory.push_back(Rage_II);
    BuffSpell Brace_II("Brace II","Increases your Def by 10.",4,227,12,0,10,0,0,0);
    buffSpellDirectory.push_back(Brace_II);
    BuffSpell Focus_II("Focus II","Increases your Acc by 30.",5,228,16,0,0,0,30,0);
    buffSpellDirectory.push_back(Focus_II);
    BuffSpell Speed_II("Speed II","Increases your Ddg by 30.",5,229,16,0,0,0,0,30);
    buffSpellDirectory.push_back(Speed_II);

    //cout << "Spell List Initialized! (3/3)" << endl;

    return buffSpellDirectory;
}
