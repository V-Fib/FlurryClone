oxil_art_dealer = Creature:new {
  objectName = "",
  customName = "Art Dealer",
  socialGroup = "",
  faction = "",
  level = 7,
  chanceHit = 0.26,
  damageMin = 55,
  damageMax = 65,
  baseXp = 187,
  baseHAM = 700,
  baseHAMmax = 800,
  armor = 0,
  resists = {0,0,0,0,0,0,0,-1,-1},
  meatType = "",
  meatAmount = 0,
  hideType = "",
  hideAmount = 0,
  boneType = "",
  boneAmount = 0,
  milk = 0,
  tamingChance = 0,
  ferocity = 0,
  pvpBitmask = NONE,
  creatureBitmask = NONE,
  optionsBitmask = AIENABLED + CONVERSABLE,
  diet = HERBIVORE,

  templates = {
    "object/mobile/dressed_noble_bothan_female_01.iff",
    "object/mobile/dressed_noble_bothan_male_01.iff",
    "object/mobile/dressed_noble_fat_human_female_01.iff",
    "object/mobile/dressed_noble_fat_human_female_02.iff",
    "object/mobile/dressed_noble_fat_human_male_01.iff",
    "object/mobile/dressed_noble_fat_human_male_02.iff",
    "object/mobile/dressed_noble_fat_zabrak_male_01.iff",
    "object/mobile/dressed_noble_fat_zabrak_male_02.iff",
    "object/mobile/dressed_noble_human_female_01.iff",
    "object/mobile/dressed_noble_human_female_02.iff",
    "object/mobile/dressed_noble_human_female_03.iff",
    "object/mobile/dressed_noble_naboo_twilek_female_01.iff",
    "object/mobile/dressed_noble_naboo_twilek_female_02.iff"
  },
  lootGroups = {
  },
  weapons = {},
  conversationTemplate = "oxil_sarban_mission_target_convotemplate",
  attacks = {}
}

CreatureTemplates:addCreatureTemplate(oxil_art_dealer, "oxil_art_dealer")