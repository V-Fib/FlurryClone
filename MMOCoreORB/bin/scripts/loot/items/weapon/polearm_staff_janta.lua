--Automatically generated by SWGEmu Spawn Tool v0.12 loot editor.

polearm_staff_janta = {
	minimumLevel = 0,
	maximumLevel = -1,
	customObjectName = "",
	directObjectTemplate = "object/weapon/melee/polearm/lance_staff_janta.iff",
	craftingValues = {
		{"mindamage",35,40,0},
		{"maxdamage",70,80,0},
		{"attackspeed",5.8,4,1},
		{"woundchance",7,7,0},
		{"hitpoints",750,1500,0},
		{"zerorangemod",7,17,0},
		{"maxrangemod",7,17,0},
		{"midrange",3,3,0},
		{"midrangemod",7,17,0},
		{"maxrange",7,7,0},
		{"attackhealthcost",28,14,0},
		{"attackactioncost",38,27,0},
		{"attackmindcost",15,11,0},
	},
	customizationStringNames = {},
	customizationValues = {},

	-- randomDotChance: The chance of this weapon object dropping with a random dot on it. Higher number means less chance. Set to 0 to always have a random dot.
	randomDotChance = 375,
	junkDealerTypeNeeded = JUNKARMS,
	junkMinValue = 20,
	junkMaxValue = 60

}

addLootItemTemplate("polearm_staff_janta", polearm_staff_janta)
