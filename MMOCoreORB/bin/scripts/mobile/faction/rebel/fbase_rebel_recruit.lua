fbase_rebel_recruit = Creature:new {
	objectName = "@mob/creature_names:fbase_rebel_recruit",
	randomNameType = NAME_GENERIC,
	randomNameTag = true,
	socialGroup = "rebel",
	faction = "rebel",
	level = 24,
	chanceHit = 0.37,
	damageMin = 230,
	damageMax = 240,
	baseXp = 2400,
	baseHAM = 6800,
	baseHAMmax = 8300,
	armor = 0,
	resists = {0,0,0,0,0,0,0,0,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = ATTACKABLE,
	creatureBitmask = PACK,
	optionsBitmask = AIENABLED,
	diet = HERBIVORE,

	templates = {"object/mobile/dressed_rebel_crewman_human_male_01.iff",
			"object/mobile/dressed_rebel_crewman_human_male_02.iff",
			"object/mobile/dressed_rebel_crewman_human_male_03.iff",
			"object/mobile/dressed_rebel_crewman_human_male_04.iff",
			"object/mobile/dressed_rebel_crewman_human_female_01.iff",
			"object/mobile/dressed_rebel_crewman_human_female_02.iff"
	},
	lootGroups = {
		{
			groups = {
				{group = "color_crystals", chance = 200000},
				{group = "junk", chance = 8800000},
				{group = "clothing_attachments", chance = 500000},
				{group = "armor_attachments", chance = 500000}
			}
		}
	},
	weapons = {"rebel_weapons_light"},
	conversationTemplate = "",
	reactionStf = "@npc_reaction/military",
	attacks = merge(marksmanmaster,brawlermaster,pistoleernovice)
}

CreatureTemplates:addCreatureTemplate(fbase_rebel_recruit, "fbase_rebel_recruit")
