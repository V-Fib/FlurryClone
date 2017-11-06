gerak_vurtimis = Creature:new {
	objectName = "@mob/creature_names:commoner_human_male",
	customName = "Gerak Vurtimis",
	socialGroup = "townsperson",
	faction = "townsperson",
	level = 21,
	chanceHit = 0.33,
	damageMin = 210,
	damageMax = 220,
	baseXp = 1609,
	baseHAM = 5000,
	baseHAMmax = 6100,
	armor = 0,
	resists = {15,15,0,0,0,-1,0,-1,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = NONE,
	creatureBitmask = NONE,
	optionsBitmask = AIENABLED,
	diet = HERBIVORE,
	templates = {"object/mobile/dressed_commoner_fat_human_male_01.iff"},

--Quest NPC no loot
	lootGroups = {},
	weapons = {},
	conversationTemplate = "",
	reactionStf = "@npc_reaction/townperson",
	attacks = brawlermaster
}

CreatureTemplates:addCreatureTemplate(gerak_vurtimis, "gerak_vurtimis")
