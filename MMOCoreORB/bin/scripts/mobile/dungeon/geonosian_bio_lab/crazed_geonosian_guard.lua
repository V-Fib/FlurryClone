crazed_geonosian_guard = Creature:new {
	objectName = "@mob/creature_names:geonosian_crazed_guard",
	randomNameType = NAME_GENERIC,
	randomNameTag = true,
	socialGroup = "self",
	faction = "",
	level = 100,
	chanceHit = 0.64,
	damageMin = 1000,
	damageMax = 1500,
	baseXp = 6288,
	baseHAM = 11000,
	baseHAMmax = 14000,
	armor = 1,
	resists = {125,135,-1,165,25,125,-1,25,-1},
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
	creatureBitmask = PACK + KILLER,
	optionsBitmask = AIENABLED,
	diet = HERBIVORE,

	templates = {
		"object/mobile/dressed_geonosian_warrior_01.iff",
		"object/mobile/dressed_geonosian_warrior_02.iff",
		"object/mobile/dressed_geonosian_warrior_03.iff"},
	lootGroups = {
		{
			groups = {
				{group = "geonosian_common", chance = 10000000},
			},
			lootChance = 5000000
		},
		{
			groups = {
				{group = "nge_all", chance = 10000000},
			},
			lootChance = 5000000
		},
		{
			groups = {
				{group = "geonosian_relic", chance = 10000000},
			},
			lootChance = 5000000
		},
	},
	weapons = {"geonosian_weapons"},
	conversationTemplate = "",
	attacks = merge(brawlermaster,marksmanmaster,pistoleermaster,riflemanmaster)
}

CreatureTemplates:addCreatureTemplate(crazed_geonosian_guard, "crazed_geonosian_guard")
