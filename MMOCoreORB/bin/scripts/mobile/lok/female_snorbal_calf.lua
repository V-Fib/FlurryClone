female_snorbal_calf = Creature:new {
	objectName = "@mob/creature_names:female_snorbal_calf",
	socialGroup = "snorbal",
	faction = "",
	level = 19,
	chanceHit = 0.33,
	damageMin = 180,
	damageMax = 190,
	baseXp = 1257,
	baseHAM = 4500,
	baseHAMmax = 5500,
	armor = 0,
	resists = {120,5,-1,5,5,5,-1,-1,-1},
	meatType = "meat_herbivore",
	meatAmount = 500,
	hideType = "hide_leathery",
	hideAmount = 400,
	boneType = "bone_mammal",
	boneAmount = 350,
	milkType = "milk_wild",
	milk = 400,
	tamingChance = 0.25,
	ferocity = 0,
	pvpBitmask = ATTACKABLE,
	creatureBitmask = HERD,
	optionsBitmask = AIENABLED,
	diet = CARNIVORE,

	templates = {"object/mobile/female_snorbal_calf.iff"},
	hues = { 16, 17, 18, 19, 20, 21, 22, 23 },
	scale = 0.6,
	lootGroups = {},
	weapons = {},
	conversationTemplate = "",
	attacks = {
		{"stunattack",""}
	}
}

CreatureTemplates:addCreatureTemplate(female_snorbal_calf, "female_snorbal_calf")
