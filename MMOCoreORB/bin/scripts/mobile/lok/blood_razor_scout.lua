blood_razor_scout = Creature:new {
	objectName = "@mob/creature_names:blood_razor_scout",
	randomNameType = NAME_GENERIC,
	randomNameTag = true,
	socialGroup = "bloodrazor",
	faction = "bloodrazor",
	level = 32,
	chanceHit = 0.39,
	damageMin = 310,
	damageMax = 330,
	baseXp = 3279,
	baseHAM = 8400,
	baseHAMmax = 10200,
	armor = 0,
	resists = {20,45,20,20,-1,20,20,-1,-1},
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

	templates = {
		"object/mobile/dressed_blood_razor_pirate_scout_hum_f.iff",
		"object/mobile/dressed_blood_razor_pirate_scout_hum_m.iff",
		"object/mobile/dressed_blood_razor_pirate_scout_rod_m.iff",
		"object/mobile/dressed_blood_razor_pirate_scout_tran_m.iff"},

	--NPC with AA/CA Template Bloodrazor Generic
	lootGroups = {
		{
			groups = {
				{group = "junk", chance = 10000000},
		},
			lootChance = 500000 

		},
		{
			groups = {
				{group = "armor_attachments", chance = 10000000}
		},
			lootChance = 10000000
		},
		{
			groups = {
				{group = "clothing_attachments", chance = 10000000}
		},
			lootChance = 10000000
		},
		{
			groups = {
				{group = "artifact", chance = 10000000}			
		},
			lootChance = 1000000
		},
		{
			groups = {
				{group = "tierone", chance = 10000000}
		},
			lootChance = 750000
		},
		{
			groups = {
				{group = "tiertwo", chance = 10000000}
		},
			lootChance = 100000
		},
		{
			groups = {
				{group = "tierthree", chance = 10000000}
		},
			lootChance = 50000
		},
		{
			groups = {
				{group = "bloodrazor_common", chance = 10000000}
		},
			lootChance = 3000000
		},
	},
	weapons = {"blood_razer_weapons"},
	conversationTemplate = "",
	reactionStf = "@npc_reaction/slang",
	attacks = merge(pistoleermaster,pikemanmaster,tkamaster,brawlermaster,marksmanmaster)
}

CreatureTemplates:addCreatureTemplate(blood_razor_scout, "blood_razor_scout")
