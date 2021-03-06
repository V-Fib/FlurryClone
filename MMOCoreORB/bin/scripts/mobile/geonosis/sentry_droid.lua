sentry_droid = Creature:new {
	customName = "Security Droid",
	socialGroup = "",
	faction = "",
	level = 300,
	chanceHit = 50.0,
	damageMin = 2700,
	damageMax = 4000,
	baseXp = 10000,
	baseHAM = 90000,
	baseHAMmax = 120000,
	armor = 1,
	resists = {170,170,170,170,170,130,170,170,150},--kinetic,energy,blast,heat,cold,electric,acid,stun,ls
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
	creatureBitmask = KILLER,
	optionsBitmask = AIENABLED,
	diet = NONE,
	scale = 1.0,
	templates = {"object/mobile/union_sentry_droid_crafted.iff"},
	lootGroups = {
		{
			groups = {
				{group = "weapon_component_advanced", chance = 10000000},
			},
			lootChance = 3000000
		},		
		{
			groups = {
				{group = "trash_common", chance = 8000000},
 				{group = "trash_rare", chance = 2000000},
			},
			lootChance = 10000000
		},
		{
			groups = {
				{group = "geonosian_common", chance = 10000000},   
			},
			lootChance = 3000000
		},  
		{
			groups = {
				{group = "tierone", chance = 1500000},
				{group = "tiertwo", chance = 3500000},
				{group = "tierthree", chance = 2500000},
				{group = "tierdiamond", chance = 2500000},
			},
			lootChance = 5000000
		}
	},
	conversationTemplate = "",
	defaultAttack = "defaultdroidattack",
	defaultWeapon = "object/weapon/ranged/vehicle/vehicle_atst_ranged.iff",
}

CreatureTemplates:addCreatureTemplate(sentry_droid, "sentry_droid")
