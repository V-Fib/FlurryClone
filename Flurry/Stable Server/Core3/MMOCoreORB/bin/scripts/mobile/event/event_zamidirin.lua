event_zamidirin = Creature:new {
	-- objectName = "@mob/creature_names:",
	customName = "Zamidirin (Force Crystal Horder)",
	socialGroup = "event",
	faction = "",
	level = 300,
	chanceHit = 50.0,
	damageMin = 3000,
	damageMax = 6000,
	baseXp = 28549,
	baseHAM = 9500000,
	baseHAMmax = 9900000,
	armor = 3,
	resists = {195,195,195,195,195,195,195,195,195},
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
	creatureBitmask = PACK + KILLER,
	optionsBitmask = AIENABLED,
	diet = HERBIVORE,
  	scale = 3.0,
  
	templates = {"object/mobile/dressed_dark_force_crystal_hunter.iff"},
	lootGroups = {
		{
			groups = {
				{group = "g_named_crystals", chance = 10000000},
			},
			lootChance = 5000000
		},
		{
			groups = {
				{group = "g_cloak_of_hate", chance = 10000000},
			},
			lootChance = 1500000
		},
		{
			groups = {
				{group = "capes", chance = 10000000},
			},
			lootChance = 1500000
		},
		{
			groups = {
				{group = "nge_all", chance = 10000000},
			},
			lootChance = 10000000
		},
		{
			groups = {
				{group = "krayt_dragon", chance = 10000000},
			},
			lootChance = 2000000
		},
		{
			groups = {
				{group = "neck_crafter", chance = 10000000},
			},
			lootChance = 2000000
		},
		{
			groups = {
				{group = "non_jedi_ring_crafter_second", chance = 10000000},
			},
			lootChance = 2000000
		},
		{
			groups = {
				{group = "non_jedi_ring_crafter", chance = 10000000},
			},
			lootChance = 2000000
		},
		{
			groups = {
				{group = "non_jedi_rings_ranged", chance = 10000000},
			},
			lootChance = 2000000
		},
		{
			groups = {
				{group = "non_jedi_rings", chance = 10000000},
			},
			lootChance = 2000000
		},
		{
			groups = {
				{group = "jedi_earings", chance = 10000000},
			},
			lootChance = 2000000
		},
		{
			groups = {
				{group = "jedi_bracelets", chance = 10000000},
			},
			lootChance = 2000000
		},
		{
			groups = {
				{group = "jedi_neck", chance = 10000000},
			},
			lootChance = 2000000
		},
		{
			groups = {
				{group = "jedi_rings", chance = 10000000},
			},
			lootChance = 2000000
		},
		{
			groups = {
				{group = "g_necklaces", chance = 10000000},
			},
			lootChance = 2000000
		},
		{
			groups = {
				{group = "clothing_attachments", chance = 10000000},
			},
			lootChance = 10000000
		},
		{
			groups = {
				{group = "armor_attachments", chance = 10000000},
			},
			lootChance = 10000000
		},
		{
			groups = {
				{group = "weapons_all", chance = 10000000},
			},
			lootChance = 10000000
		},
		{
			groups = {
				{group = "worldbosscrate", chance = 10000000},
			},
			lootChance = 10000000
		},
		{
			groups = {
				{group = "vehicledeedsnormal", chance = 10000000},
			},
			lootChance = 5000000
		},
		{
			groups = {
				{group = "vehicledeedsrare", chance = 10000000},
			},
			lootChance = 2500000
		},
		{
			groups = {
				{group = "tierone", chance = 1500000},
				{group = "tiertwo", chance = 3500000},
				{group = "tierthree", chance = 2500000},
				{group = "tierdiamond", chance = 2500000},
			},
			lootChance = 10000000
		},
		{
			groups = {
				{group = "tierone", chance = 1500000},
				{group = "tiertwo", chance = 3500000},
				{group = "tierthree", chance = 2500000},
				{group = "tierdiamond", chance = 2500000},
			},
			lootChance = 10000000
		}
	},
	weapons = {"mixed_force_weapons"},
	conversationTemplate = "",
	attacks = merge(pikemanmaster,brawlermaster,fencermaster,swordsmanmaster)
}

CreatureTemplates:addCreatureTemplate(event_zamidirin, "event_zamidirin")
