sbd2_droids = Creature:new {
	customName = "Super Battle Droid",
	socialGroup = "",
	faction = "",
	level = 100,
	chanceHit = 1.0,
	damageMin = 500,
	damageMax = 1500,
	baseXp = 128549,
	baseHAM = 100000,
	baseHAMmax = 110000,
	armor = 3,
	resists = {90,90,90,90,90,90,90,90,50},--kinetic,energy,blast,heat,cold,electric,acid,stun,ls
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = AGGRESSIVE + ATTACKABLE + ENEMY,
	creatureBitmask = KILLER,
	optionsBitmask = AIENABLED,
	diet = NONE,
	scale = 1.0,
	templates = {"object/mobile/bomarr_monk_spider_droid_greeter.iff"},
	lootGroups = {
		{
			groups = {
				{group = "junk", chance = 10000000},
			},
			lootChance = 10000000
		},	
		{
			groups = {
				{group = "junk", chance = 10000000},
			},
			lootChance = 10000000
		}
	},
	weapons = {"pirate_weapons_heavy"},
	conversationTemplate = "",
	attacks = merge(bountyhuntermaster,marksmanmaster,brawlermaster)
}

CreatureTemplates:addCreatureTemplate(sbd2_droids, "sbd2_droids")

