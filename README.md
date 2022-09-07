# TowerOfValentereth
A turn-based roguelike rpg, entirely in text.

Welcome to Tower of Valentereth!!

TO INSTALL:
	Download the "Tower of Valentereth.msi" file, and use the installer to finish the installation progress. Files will be installed at the chosen
	path, and player data will be kept at C:\Users\{USER}\AppData\Local\VirtualStore.

Intro:
    Tower of Valentereth is a text-based, turn-based roguelike in which you must navigate through chamber after chamber collecting items,
    defeating enemies, and becoming stronger as you go. The UI is entirely text based, so all of your interactions will be done by typing
    an action into the command line when prompted. All actions and targets are accepted in all lower case. A list of applicable actions
    is provided below.

Exploration:
    The game follows a set pattern; you advance to a new floor, and examine its surroundings. You can examine sections of the room's
    description to learn more about it, or look at containers around the room to find new items, equipment, and spells for you to pick up.
    Sometimes, even features around the room can have items hidden within them. If you wish to get items more quickly, you can target "all"
	to pick up all items in the room, excluding those hidden in features.
    If a creature is present in the room with you, they must be defeated before you can advance to the next floor, unless you attempt to run past.
    Once you gain enough experience points, your character will level up, gaining stat boosts and being restored to full health. The rarity and
    power of items you find will increase the further you ascend the tower. This can continue for countless floors, however, the end of your journey
    could lie behind any door, and there is no going back if you fall. Valentereth lies at floor 55, but what lies beyond that is a mystery.

Menu:
    By using the menu command, you can access your inventory. Inside, you will find a variety of options; firstly, is your stats. This screen
    states your player name, your level, your HP, your MP, and your current strength, defense, accuracy, dodge, critical hit rate, and luck. It also
    displays how many experience points you have, as well as any buffs you may have to your magic power. If you are doing a mask run, the mask
    you are wearing will be shown here as well. When on a menu, reference the different options available by their number, if given. Otherwise, just
    by their name.
    In your equipment menu, you will find a list of all of the equipment you are holding, however you can only hold a maximum of 6 pieces of
    equipment at a time. You can examine, drop, and equip your equipment in this menu. In your items menu you will find all of the consumable
    items you have, but only 6 can be held, similarly to the equipment menu. These can be examined and used here. In your spellbook, you will
    find a list of all of the spells you have collected, with no maximum capacity. You can check the description of spells here, or if you
    have a healing spell, those can be cast here as well. Lastly, you can quit the game from this menu, or return to the game.

Combat:
    When you decide to fight a creature, you will enter combat. In combat, you and the enemy will take turns performing an action. The
    enemy will always attack, but the player has the choice of either attacking (strike), casting a spell (cast), using an item
    (use), or running away (run). Strike will be a normal weapon attack, which will have a chance to hit equal to your accuracy minus the opponent's
    dodge. The damage done from this will be equal to your attack minus the opponent's defense. Casting a spell can have a variety of effects;
    offensive spells, like ember, thunderbolt, and freeze, will deal damage to the opponent that will always hit, and is not reduced by
    the enemy's defense. The damage of these spells can be amplified while some pieces of equipment are being held, such as staves. Healing spells,
    such as heal or regenerate, will restore HP to the player either on the turn it is cast, or over a period of time. Using an item will allow you
    to spend a turn using an item in your inventory to restore HP or MP.
    Running away can have a number of effects; the player can either escape successfully with no damage taken, escape at the cost of taking damage,
    or taking damage and being unable to escape. No rewards will be won if the player escapes from combat, such as gold or experience. Having a higher
    dodge stat will provide a greater chance of escape.

Shops:
    Throughout the tower, the player can often find locked doors. If unlocked, behind the door will be one of several shop types; a merchant, a divining
	room, or an altar. At a merchant, the player will be able to spend their gold for items and equipment. In a divining room, they will be able to spend
	gold to perform one of the given stat transfers at the top of the screen (2 for 1) for an increasing gold cost. At an altar, the player can spend gold
	to receive a random effect, relating to the given hint. Keys for these rooms can be found throughout the tower.

Masks:
    Masks are a special item that can only be equipped at the start of an ascension of the tower. Each type of mask is an overhaul of one of the game's
    mechanics, and wearing one throughout the game will drastically alter the playstyle. Try them out and see how far you can make it!
	-MASK OF GLASS: A smiling mask made of shimmering glass. When worn, doubles the damage dealt with strikes, but doubles the damage dealt to the
		wearer.
	-MASK OF FATE: A black and white mask, resembling a yin-yang. When worn, gain increased luck on level up, but become less lucky.
	-MASK OF DARKNESS: A screaming mask made of dark obsidian. When worn, spells are amplified by 50%, but enemies cannot be identified.
	-MASK OF ARCANA: A peaceful mask made of smooth marble. When worn, increases mana regeneration by 5, but all strikes deal half damage.
	-MASK OF STEEL: A stoic mask made of hardened metal. When worn, halves damage taken from attacks, but enemies never miss.
	-MASK OF WHISPERS: A transparent mask made of invisible threads. When worn, increases chance to dodge by 50%, but enemies deal double damage to
		the wearer.
	-MASK OF BEASTS: A ravenous mask made of bloodied pelts. When worn, increases strength by 50%, but the wearer must strike each round of combat.
	-MASK OF SOULS: An expressionless mask made of light itself. When worn, triples the amount of EXP earned by the wearer, but restricts the wearer
		from equipping any armor.

Karma:
    Karma is a hidden statistic that effects the difficulty of the rooms generated during the game. The difficulty of enemies and the amount and quality
    of loot found in each room varies based on previous rooms: if you have bad luck in some rooms, perhaps you will have better luck in future rooms.

Leaderboard:
    The leaderboard can be accessed from the main menu. The leaderboard displays the top ten scores from previous games, with the name, floor, and score
	of each entry. Scores with the <+> defeated the tyrant, and scores with <<+>> broke the cycle.

Achievements:
	Achievement progress can be viewed from the main menu. As you play the game, you can unlock achievements from the list, and earn points toward a
	completion total. Some achievements have their requirements hidden, not revealing how to complete them.

Saving:
    Tower of Valentereth uses autosave to save your level, stats, and items as you ascend the tower. Your save data is kept under your character's name.
    By using the "save" command, you can disable autosave and use manual saving.

Stats:
    LEVEL: The current level of your character. Increases every time your EXP meter fills up. For each time this stat increases, your other stats increase.
    FLOOR: The current floor of the tower you are on. The difficulty of monsters and rarity of loot increases as you ascend.
    EXP: Experience points. This increases by defeating enemies. When your number of experience points hits its goal, your character will level up, your
        stats will increase, your EXP will be reset, and the goal will increase by 20.
    GOLD: Currency in the tower. You collect gold by defeating enemies. Can be spent in shops.
    HP: Hit points. Shows the current health of your character. Decreases when you take damage, you lose when it hits 0. Can be regained by leveling up,
        or by using spells or items.
    MP: Mana points. Capacity for casting spells. Will deplete by the mana cost of spells used. You will be unable to cast spells that you do not have the
        required MP for. Can be regained through items, or equipment.
    WPN: Your currently equipped weapon. Affects your ATK, CRT, and ACC.
    AMR: Your currently equipped armor. Affects your DEF, and DDG.
    ATK: Attack. Shows your attack power. When striking in combat, this minus the DEF of the enemy will determine the damage done.
    DEF: Defense. Shows your defensive capability. When taking damage in combat, the enemy's ATK minus your DEF will determine how much damage you take.
    CRT: Critical Hit Rate. Your percent chance of performing a critical hit upon hitting an enemy. Upon performing a critical hit, you will deal double
        your normal damage.
    ACC: Accuracy. Your chance of hitting an enemy. When striking in combat, this minus the DDG of the enemy will determine your percent chance of hitting.
    DDG: Dodge. Your chance of dodging enemy attacks. When being attacked in combat, the enemy's ACC minus this will determine if you are hit.
	LCK: Luck. Your chance of activating a ring's effect, in addition to its default activation rate. Each luck is treated as an additional 1% chance.
    AMP: Magical Amplifier. Your percent bonus to magical abilities. Your attack and healing spells will be boosted by this percent of their original amount.
        This stat is increased by wielding magical weapons or staves.
    MPG: Mana Point Gain. The number of MP you regain during each round of combat. This stat is increased by wearing Arcanist Armor or robes.

Actions:
    MOVE: move <target>
        -Synonyms: Go, Enter, Leave, Walk
        -Meaning: Used to enter a new area.
        -EG: enter door
    LOOK: look <target>
        -Synonyms: Check, Examine
        -Meaning: Used to examine a feature in the room.
        -EG: check crates
    GET: get <target>
        -Synonyms: Take, Grab, Add
        -Meaning: Used to acquire a new item.
        -EG: get wooden sword
    ATTACK: attack <target>
        -Synonyms: Fight, Gank, Strike, Kill
        -Meaning: Used to engage in combat with a creature.
        -EG: attack ogre
    MENU: menu
        -Synonyms: Inventory, Pause, M
        -Meaning: Opens up your menu.
        -EG: menu
    SAVE: save
	    -Synonyms: (None)
	    -Meaning: Enables/Disables manual saving (Autosave enabled by default).
	    -EG: save
    HELP: help
	    -Synonyms: Manual
	    -Meaning: Opens a guide to actions similar to this file.
	    -EG: help
