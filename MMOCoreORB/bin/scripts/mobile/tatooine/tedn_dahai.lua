tedn_dahai = Creature:new {
	objectName = "@npc_name:bith_base_male",
	customName = "Tedn Dahai",
	socialGroup = "townsperson",
	faction = "townsperson",
	level = 10,
	chanceHit = 0.28,
	damageMin = 90,
	damageMax = 110,
	baseXp = 356,
	baseHAM = 810,
	baseHAMmax = 990,
	armor = 0,
	resists = {0,0,0,0,0,0,0,-1,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0.0,
	ferocity = 0,
	pvpBitmask = NONE,
	creatureBitmask = PACK,
	optionsBitmask = AIENABLED,
	diet = HERBIVORE,

	templates = {"object/mobile/tatooine_npc/figrin_dan.iff"},
	lootGroups = {},
	weapons = {},
	conversationTemplate = "",
	outfit = "band_fanfar_outfit",
	attacks = {
	}
}

CreatureTemplates:addCreatureTemplate(tedn_dahai, "tedn_dahai")
