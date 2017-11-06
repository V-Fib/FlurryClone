j1_po = Creature:new {
	objectName = "@npc_spawner_n:j1_po",
	socialGroup = "",
	faction = "",
	level = 30,
	chanceHit = 0.390000,
	damageMin = 290,
	damageMax = 300,
	baseXp = 2914,
	baseHAM = 8400,
	baseHAMmax = 10200,
	armor = 0,
	resists = {0,45,0,-1,40,-1,40,-1,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0.000000,
	ferocity = 0,
	pvpBitmask = NONE,
	creatureBitmask = NONE,
	diet = HERBIVORE,
	templates = {"object/mobile/3po_protocol_droid_silver.iff"},

--Quest NPC no loot
	lootGroups = {},
	weapons = {},
	attacks = {},
	conversationTemplate = "",
	optionsBitmask = AIENABLED
}

CreatureTemplates:addCreatureTemplate(j1_po, "j1_po")
