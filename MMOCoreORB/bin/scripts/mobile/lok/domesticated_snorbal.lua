domesticated_snorbal = Creature:new {
	objectName = "@mob/creature_names:domesticated_snorbal",
	socialGroup = "self",
	faction = "",
	level = 31,
	chanceHit = 0.39,
	damageMin = 260,
	damageMax = 270,
	baseXp = 3005,
	baseHAM = 8600,
	baseHAMmax = 10600,
	armor = 1,
	resists = {140,140,0,-1,-1,-1,-1,0,-1},
	meatType = "meat_herbivore",
	meatAmount = 545,
	hideType = "hide_leathery",
	hideAmount = 440,
	boneType = "bone_mammal",
	boneAmount = 400,
	milkType = "milk_domesticated",
	milk = 300,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = ATTACKABLE,
	creatureBitmask = HERD,
	optionsBitmask = AIENABLED,
	diet = HERBIVORE,
	templates = {"object/mobile/snorbal_hue.iff"},

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
		{"dizzyattack",""},
		{"stunattack",""}
	}
}

CreatureTemplates:addCreatureTemplate(domesticated_snorbal, "domesticated_snorbal")
