nightsister_ranger = Creature:new {
	objectName = "@mob/creature_names:nightsister_ranger",
	randomNameType = NAME_GENERIC,
	randomNameTag = true,
	socialGroup = "nightsister",
	faction = "nightsister",
	level = 81,
	chanceHit = 0.75,
	damageMin = 555,
	damageMax = 820,
	baseXp = 7761,
	baseHAM = 12000,
	baseHAMmax = 15000,
	armor = 1,
	resists = {30,30,30,100,100,100,100,100,-1},
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
	creatureBitmask = PACK + KILLER + STALKER,
	optionsBitmask = AIENABLED,
	diet = HERBIVORE,

	templates = {"object/mobile/dressed_dathomir_nightsister_ranger.iff"},
	lootGroups = {
		{
			groups = {
				{group = "power_crystals", chance = 10000000},
			},
			lootChance = 500000
		},
		{
			groups = {
				{group = "color_crystals", chance = 10000000},
			},
			lootChance = 500000
		},
		{
			groups = {
				{group = "nightsister_common", chance = 10000000},
			},
			lootChance = 2000000
		},
		{
			groups = {
				{group = "armor_attachments", chance = 10000000},
			},
			lootChance = 250000
		},
		{
			groups = {
				{group = "clothing_attachments", chance = 10000000},
			},
			lootChance = 250000
		},
		{
			groups = {
				{group = "melee_weapons", chance = 10000000},
			},
			lootChance = 2500000
		},
		{
			groups = {
				{group = "rifles", chance = 10000000},
			},
			lootChance = 1000000
		},
		{
			groups = {
				{group = "wearables_common", chance = 10000000},
			},
			lootChance = 500000
		},
		{
			groups = {
				{group = "carbines", chance = 10000000},
			},
			lootChance = 1000000
		},
		{
			groups = {
				{group = "tailor_components", chance = 10000000},
			},
			lootChance = 500000
		},
		{
			groups = {
				{group = "pistols", chance = 10000000},
			},
			lootChance = 1000000
		},
	},
	weapons = {"mixed_force_weapons"},
	conversationTemplate = "",
	attacks = merge(fencermid,swordsmanmid,tkamid,pikemanmid,brawlermaster,forcewielder)
}

CreatureTemplates:addCreatureTemplate(nightsister_ranger, "nightsister_ranger")
