skaak_tipper_bandit = Creature:new {
	objectName = "@mob/creature_names:skaak_tipper_bandit",
	randomNameType = NAME_GENERIC,
	randomNameTag = true,
	socialGroup = "skaak_tipper_gang",
	faction = "thug",
	level = 8,
	chanceHit = 0.270000,
	damageMin = 70,
	damageMax = 75,
	baseXp = 187,
	baseHAM = 405,
	baseHAMmax = 495,
	armor = 0,
	resists = {0,0,0,0,0,0,0,-1,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0.000000,
	ferocity = 0,
	pvpBitmask = ATTACKABLE,
	creatureBitmask = HERD,
	diet = HERBIVORE,

	templates = {
		"object/mobile/dressed_robber_twk_male_01.iff",
		"object/mobile/dressed_robber_twk_female_01.iff"},
	lootGroups = {
		{
			groups = {
				{group = "junk", chance = 6000000},
				{group = "tailor_components", chance = 2000000},
				{group = "loot_kit_parts", chance = 1000000},
				{group = "skaak_tipper_common", chance = 1000000}
			}
		}
	},
	weapons = {"pirate_weapons_light"},
	reactionStf = "@npc_reaction/slang",
	attacks = merge(brawlernovice,marksmannovice)
}

CreatureTemplates:addCreatureTemplate(skaak_tipper_bandit, "skaak_tipper_bandit")
