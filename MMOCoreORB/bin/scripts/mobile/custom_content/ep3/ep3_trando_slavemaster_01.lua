ep3_trando_slavemaster_01 = Creature:new {
	customName = "Trandoshan Slavemaster",
	randomNameType = NAME_GENERIC_TAG,
	socialGroup = "trandoshan",
	faction = "",
	level = 100,
	chanceHit = 1.00,
	damageMin = 1150,
	damageMax = 1470,
	baseXp = 7500,
	baseHAM = 50000,
	baseHAMmax = 75000,
	armor = 2,
	resists = {60,60,80,60,55,65,85,45,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0.0,
	ferocity = 0,
	pvpBitmask = AGGRESSIVE + ATTACKABLE + ENEMY,
	creatureBitmask = NONE,
	optionsBitmask = AIENABLED,
	diet = HERBIVORE,

	templates = {"object/mobile/ep3/ep3_trando_slavemaster_01.iff"},
	lootGroups = {},
	weapons = {"pirate_weapons_heavy"},
	conversationTemplate = "",
	reactionStf = "@npc_reaction/slang",
	attacks = merge(brawlermaster,marksmanmaster)
}

CreatureTemplates:addCreatureTemplate(ep3_trando_slavemaster_01, "ep3_trando_slavemaster_01")
