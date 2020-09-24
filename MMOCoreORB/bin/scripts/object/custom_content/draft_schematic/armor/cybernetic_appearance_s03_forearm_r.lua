object_draft_schematic_armor_cybernetic_appearance_s03_forearm_r = object_draft_schematic_armor_shared_cybernetic_appearance_s03_forearm_r:new {

   templateType = DRAFTSCHEMATIC,

   customObjectName = "Armor Right ForeArm 03",

   craftingToolTab = 2, -- (See DraftSchematicObjectTemplate.h)
   complexity = 45, 
   size = 4, 

   xpType = "crafting_droid_general", 
   xp = 250, 

   assemblySkill = "droid_assembly",
   experimentingSkill = "droid_experimentation",
   customizationSkill = "droid_customization",

   customizationOptions = {2},
   customizationStringNames = {"/private/index_color_1"},
   customizationDefaults = {0},

   ingredientTemplateNames = {"craft_droid_ingredients_n", "craft_clothing_ingredients_n", "craft_clothing_ingredients_n", "craft_clothing_ingredients_n", "craft_clothing_ingredients_n", "craft_clothing_ingredients_n", "craft_clothing_ingredients_n", "craft_clothing_ingredients_n", "craft_clothing_ingredients_n"},
   ingredientTitleNames = {"sensor_suite", "reinforcement", "liner", "hardware_and_attachments", "binding_and_reinforcement", "padding", "armor", "load_bearing_harness", "reinforcement"},
   ingredientSlotType = {1, 1, 0, 0, 0, 0, 1, 1, 1},
   resourceTypes = {"object/tangible/component/droid/shared_sensor_package_droid.iff", "object/tangible/loot/misc/shared_artifact_rare_s01.iff", "fiberplast_naboo", "aluminum", "copper_beyrllius", "metal", "object/tangible/component/armor/shared_armor_segment_composite.iff", "object/tangible/component/clothing/shared_synthetic_cloth.iff", "object/tangible/component/clothing/shared_reinforced_fiber_panels.iff"},
   resourceQuantities = {1, 1, 15, 10, 10, 10, 1, 2, 1},
   contribution = {100, 100, 100, 100, 100, 100, 100, 100, 100},


   targetTemplate = "object/tangible/wearables/cybernetic/cybernetic_crafted_forearm_r_03.iff",

   additionalTemplates = {
              }

}
ObjectTemplates:addTemplate(object_draft_schematic_armor_cybernetic_appearance_s03_forearm_r, "object/draft_schematic/armor/cybernetic_appearance_s03_forearm_r.iff")
