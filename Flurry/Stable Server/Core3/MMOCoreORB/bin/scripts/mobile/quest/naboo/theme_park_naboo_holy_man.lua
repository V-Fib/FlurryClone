theme_park_naboo_holy_man = Creature:new {
  objectName = "@mob/creature_names:naboo_holy_man",
  randomNameType = NAME_GENERIC,
  randomNameTag = true,
  socialGroup = "naboo",
  faction = "naboo",
  level = 5,
  chanceHit = 0.250000,
  damageMin = 45,
  damageMax = 50,
  baseXp = 85,
  baseHAM = 135,
  baseHAMmax = 165,
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
  pvpBitmask = NONE,
  creatureBitmask = HERD,
  optionsBitmask = AIENABLED + CONVERSABLE,
  diet = HERBIVORE,

  templates = {"object/mobile/gungan_male.iff"},
  lootGroups = {},
  weapons = {},
  conversationTemplate = "theme_park_smc_vurlene_aujante_mission_target_convotemplate",
  reactionStf = "@npc_reaction/fancy",
  attacks = {}
}

CreatureTemplates:addCreatureTemplate(theme_park_naboo_holy_man, "theme_park_naboo_holy_man")
