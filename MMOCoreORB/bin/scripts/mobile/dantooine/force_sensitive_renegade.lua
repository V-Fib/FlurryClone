force_sensitive_renegade = Creature:new {
	objectName = "@mob/creature_names:force_sensitive_renegade",
	randomNameType = NAME_GENERIC,
	randomNameTag = true,
	socialGroup = "force",
	faction = "",
	level = 80,
	chanceHit = 0.8,
	damageMin = 585,
	damageMax = 880,
	baseXp = 7668,
	baseHAM = 12000,
	baseHAMmax = 15000,
	armor = 2,
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
	creatureBitmask = PACK + KILLER,
	optionsBitmask = AIENABLED,
	diet = HERBIVORE,

	templates = {"object/mobile/dressed_force_sensitive_renegade.iff"},
	lootGroups = {
		{
			groups = {
				{group = "junk", chance = 5000000},
				{group = "power_crystals", chance = 500000},
				{group = "color_crystals", chance = 500000},
				{group = "holocron_dark", chance = 500000},
				{group = "holocron_light", chance = 500000},
				{group = "armor_attachments", chance = 1500000},
				{group = "clothing_attachments", chance = 1500000},
				
			}
		}
	},
	weapons = {"mixed_force_weapons"},
	conversationTemplate = "",
	attacks = merge(pikemanmaster,brawlermaster)
}

CreatureTemplates:addCreatureTemplate(force_sensitive_renegade, "force_sensitive_renegade")
