malkloc_bull = Creature:new {
	objectName = "@mob/creature_names:malkloc_bull",
	socialGroup = "malkloc",
	faction = "",
	level = 28,
	chanceHit = 0.35,
	damageMin = 240,
	damageMax = 250,
	baseXp = 2822,
	baseHAM = 8200,
	baseHAMmax = 10000,
	armor = 0,
	resists = {135,135,10,-1,-1,-1,10,150,-1},
	meatType = "meat_herbivore",
	meatAmount = 1000,
	hideType = "hide_leathery",
	hideAmount = 1000,
	boneType = "bone_mammal",
	boneAmount = 1000,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = ATTACKABLE,
	creatureBitmask = PACK + HERD,
	optionsBitmask = AIENABLED,
	diet = CARNIVORE,
	templates = {"object/mobile/malkloc_bull.iff"},
	scale = 1.05,

--Creature Default Loot Template
	lootGroups = {
		{
			groups = {
				{group = "artifact", chance = 10000000}			
		},
			lootChance = 100000
		},
		{
			groups = {
				{group = "tierone", chance = 10000000}
		},
			lootChance = 50000
		},
		{
			groups = {
				{group = "tiertwo", chance = 10000000}
		},
			lootChance = 25000
		},
		{
			groups = {
				{group = "tierthree", chance = 10000000}
		},
			lootChance = 10000
		}
	},
	weapons = {},
	conversationTemplate = "",
	attacks = {
		{"stunattack",""}
	}
}

CreatureTemplates:addCreatureTemplate(malkloc_bull, "malkloc_bull")
