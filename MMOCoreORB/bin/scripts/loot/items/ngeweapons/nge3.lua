--Automatically generated by SWGEmu Spawn Tool v0.12 loot editor. 

nge3 = {
	minimumLevel = 0,
	maximumLevel = -1,
	customObjectName = "2H PvP Sword",
	directObjectTemplate = "object/weapon/melee/2h_sword/2h_sword_pvp_bf_01.iff",
	craftingValues = {
		{"mindamage",53,98,0},
		{"maxdamage",235,436,0},
		{"attackspeed",8.5,5.8,1},
		{"woundchance",11,20,0},
		{"hitpoints",750,1500,0},
		{"zerorangemod",-46,-25,0},
		{"maxrangemod",-46,-25,0},
		{"midrange",3,3,0},
		{"midrangemod",-46,-25,0},
		{"maxrange",7,7,0},
		{"attackhealthcost",120,63,0},
		{"attackactioncost",30,15,0},
		{"attackmindcost",16,7,0},
	},
	customizationStringNames = {},
	customizationValues = {},

	-- randomDotChance: The chance of this weapon object dropping with a random dot on it. Higher number means less chance. Set to 0 to always have a random dot.
	randomDotChance = 750,
	junkDealerTypeNeeded = JUNKARMS,
	junkMinValue = 30,
	junkMaxValue = 55

}

addLootItemTemplate("nge3", nge3)
