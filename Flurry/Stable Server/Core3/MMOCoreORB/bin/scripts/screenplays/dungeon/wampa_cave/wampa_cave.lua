--------------------------------------
--   Creator : TOXIC
--   Date : 02/19/2020
--------------------------------------
wampa_cave = ScreenPlay:new {
  numberOfActs = 1,
  questString = "wampa_cave",
  questdata = Object:new {
  activePlayerName = "initial",
  }
}
-------------------------------------------------------------
--   Register Screenplay to planet Dungeon 2 Wampa temple
-------------------------------------------------------------
spHelper = require("screenplayHelper")
registerScreenPlay("wampa_cave", true)
local ObjectManager = require("managers.object.object_manager")  --print("Object manager loaded for Wampa")
--------------------------------------
--   Initialize screenplay
--------------------------------------
function wampa_cave:start()
if (isZoneEnabled("hoth")) then
	self:spawnMobiles()
	self:spawnSceneObjects()
  end
end

function wampa_cave:spawnSceneObjects()
--spawnSceneObject("hoth", "object/tangible/terminal/terminal_quad_screen.iff", -40.4491, 0.61331, 29.3437, 14200816, 1, 0, 0, 0)
end
--------------------------------------------------
--   spawn mobiles for dungeon
--------------------------------------------------
function wampa_cave:spawnMobiles()
-------------------------------------------------------------------------
--  Spawn a NPC as a swtich once killed, triggers boss observer to spawn
-------------------------------------------------------------------------
local pBoss = spawnMobile("hoth", "baby_wampa", 10800, 15.1374, -3.58883e-09, 85.2292, 184, 14200878)--3 hour respawn to start the boss
	print("Spawning Wampa Clone")
if (pBoss ~= nil ) then
    createObserver(OBJECTDESTRUCTION, "wampa_cave", "notifyTriggerDead", pBoss)
end
    writeData("wampa_cave:spawnState",0)
    return 0
end
-----------------------------------------
--  Notify trigger is dead to spawn Boss
-----------------------------------------
function wampa_cave:notifyTriggerDead(pBoss, pPlayer)
local pBoss = spawnMobile("hoth", "wampa_boss", -1, 15.1374, -3.58883e-09, 85.2292, 184, 14200878)
    print("Spawning Wampa")
	local creature = CreatureObject(pBoss)
    CreatureObject(pPlayer):playEffect("clienteffect/sm_end_of_the_line.cef", "")
    CreatureObject(pPlayer):playMusicMessage("sound/wampa_cave.snd")
    ObjectManager.withCreatureObject(pBoss, function(oBoss)
    writeData("wampa_cave:spawnState", 1)
    writeData("wampa_cave", oBoss:getObjectID())
    spatialChat(pBoss, "Intruder Alert Activating Defense Systems")
    createObserver(DAMAGERECEIVED,"wampa_cave","boss_damage", pBoss)
    createObserver(OBJECTDESTRUCTION, "wampa_cave", "Restart", pBoss)
end)
    return 0
end
-----------------------------------------
--  Notify trigger broadcast respawning
-----------------------------------------
function wampa_cave:Restart(pPlayer, pBoss)
    print("Starting Boss Broadcast Scripts")
	createEvent(1 * 1000, "wampa_cave", "Restartstates", pPlayer, "")--Restart Wampa States
	createEvent(1 * 1000, "wampa_cave", "BroadcastRespawn", pPlayer, "")--Broadcast 3 Hour Respawn
	createEvent(300 * 1000, "wampa_cave", "KillBoss", pPlayer, "")--Clean Up Dead Corpse
	createEvent(10795 * 1000, "wampa_cave", "KillSpawnCast", pPlayer, "")--Broadcast Respawn
	createEvent(10798 * 1000, "wampa_cave", "KillSpawnCast1", pPlayer, "")--Broadcast Respawn 3
	createEvent(10799 * 1000, "wampa_cave", "KillSpawnCast2", pPlayer, "")--Broadcast Respawn 2
	createEvent(10800 * 1000, "wampa_cave", "KillSpawnCast3", pPlayer, "")--Broadcast Respawn 1
    return 0
end
--------------------------------------
--   Player, Boss Functions
--------------------------------------
function wampa_cave:boss_damage(pBoss, pPlayer, onespawn, twospawn, threespawn, fourspawn, fivespawn, sixspawn, sevenspawn, eightspawn, ninespawn, player, pMember)
local player = LuaCreatureObject(pPlayer)
local boss = LuaCreatureObject(pBoss)
createEvent(10800 * 1000, "wampa_cave", "Remove", pBoss, "")
--------------------------------------
--   Range and health checks for boss
--------------------------------------
if (boss ~= nil) then
local heal = 999999
local bossHealth = boss:getHAM(0)
local bossAction = boss:getHAM(3)
local bossMind = boss:getHAM(6)
local bossMaxHealth = boss:getMaxHAM(0)
local bossMaxAction = boss:getMaxHAM(3)
local bossMaxMind = boss:getMaxHAM(6)

local x1 = 15.1374
local y1 = 85.2292
local x2 = boss:getPositionX()
local y2 = boss:getPositionY()

local distance = ((x2 - x1)*(x2 - x1)) + ((y2 - y1)*(y2 - y1))
local maxDistance = 50 --Max distance you can fight the boss is 20 meeters, you must be within range to fight the boss. Resets to full health if you fail the check.
if distance > (maxDistance * maxDistance) then
      forcePeace(pBoss)
      forcePeace(pBoss)
      forcePeace(pBoss)
      forcePeace(pBoss)
      forcePeace(pBoss)
      forcePeace(pBoss)
      CreatureObject(pBoss):healDamage(heal, 0)
      CreatureObject(pBoss):healDamage(heal, 3)
      CreatureObject(pBoss):healDamage(heal, 6)
      CreatureObject(pBoss):playEffect("clienteffect/incubator_mutation.cef", "")
      CreatureObject(pBoss):playEffect("clienteffect/bacta_grenade.cef", "")
      CreatureObject(pBoss):playEffect("clienteffect/space_command/shp_shocked_01_noshake.cef", "")
      spatialChat(pBoss, "Systems powering down you are out of combat range")
      CreatureObject(pPlayer):sendSystemMessage("You must be within 50m of the boss to fight, boss is now resetting")
end
--------------------------------------
--  90% health check
--------------------------------------
if (((bossHealth <= (bossMaxHealth * 0.9)) or (bossAction <= (bossMaxAction * 0.9)) or (bossMind <= (bossMaxMind * 0.9))) and readData("wampa_cave:spawnState") == 1) then
      CreatureObject(pPlayer):sendSystemMessage("You take damage from the fire")
      local trapDmg = getRandomNumber(500, 1000)
      CreatureObject(pPlayer):inflictDamage(pPlayer, 0, trapDmg, 1)
      CreatureObject(pPlayer):playEffect("clienteffect/restuss_event_artillery_ground.cef", "")
      CreatureObject(pPlayer):playEffect("clienteffect/combat_turret_0_miss_terrain_01.cef", "")
      CreatureObject(pBoss):playEffect("clienteffect/incubator_mutation.cef", "")
      CreatureObject(pBoss):playEffect("clienteffect/space_command/shp_astromech_effects_04.cef", "")
      CreatureObject(pPlayer):sendSystemMessage("Enemy Wave Starting!")
      spatialChat(pBoss, "Boss Current Health = 90%")
      spatialChat(pBoss, "You fools..")
      writeData("wampa_cave:spawnState",2)
      local onespawn = spawnMobile("hoth", " ", 0, 6.70729, -0.027031, 97.9255, 169, 14200878)
      local onespawn = spawnMobile("hoth", " ", 0, 21.089, -0.0977471, 61.4571, 359, 14200878)
      ObjectManager.withCreatureObject(onespawn, function(ofirstTime)
      writeData("countspawn", ofirstTime:getObjectID())
      ofirstTime:engageCombat(pPlayer)
			end)
		end
--------------------------------------
--  80% health check
--------------------------------------
if (((bossHealth <= (bossMaxHealth * 0.8)) or (bossAction <= (bossMaxAction * 0.8)) or (bossMind <= (bossMaxMind * 0.8))) and readData("wampa_cave:spawnState") == 2) then
      CreatureObject(pPlayer):sendSystemMessage("You take damage from the fire")
      local trapDmg = getRandomNumber(500, 1000)
      CreatureObject(pPlayer):inflictDamage(pPlayer, 0, trapDmg, 1)
      CreatureObject(pPlayer):playEffect("clienteffect/restuss_event_artillery_ground.cef", "")
      CreatureObject(pPlayer):playEffect("clienteffect/combat_turret_0_miss_terrain_01.cef", "")
      CreatureObject(pBoss):playEffect("clienteffect/incubator_mutation.cef", "")
      CreatureObject(pBoss):playEffect("clienteffect/space_command/shp_astromech_effects_04.cef", "")
      CreatureObject(pPlayer):sendSystemMessage("Enemy Wave Starting!")
      spatialChat(pBoss, "Boss Current Health = 80%")
      writeData("wampa_cave:spawnState",3)
      local twospawn = spawnMobile("hoth", " ", 0, 6.70729, -0.027031, 97.9255, 169, 14200878)
      local twospawn = spawnMobile("hoth", " ", 0, 21.089, -0.0977471, 61.4571, 359, 14200878)
      ObjectManager.withCreatureObject(twospawn, function(ofirstTime)
      writeData("countspawn", ofirstTime:getObjectID())
      ofirstTime:engageCombat(pPlayer)
			end)
		end
--------------------------------------
--  70% health check
--------------------------------------
if (((bossHealth <= (bossMaxHealth * 0.7)) or (bossAction <= (bossMaxAction * 0.7)) or (bossMind <= (bossMaxMind * 0.7))) and readData("wampa_cave:spawnState") == 3) then
      CreatureObject(pPlayer):sendSystemMessage("You take damage from the fire")
      local trapDmg = getRandomNumber(500, 1000)
      CreatureObject(pPlayer):inflictDamage(pPlayer, 0, trapDmg, 1)
      CreatureObject(pPlayer):playEffect("clienteffect/restuss_event_artillery_ground.cef", "")
      CreatureObject(pPlayer):playEffect("clienteffect/combat_turret_0_miss_terrain_01.cef", "")
      CreatureObject(pBoss):playEffect("clienteffect/incubator_mutation.cef", "")
      CreatureObject(pBoss):playEffect("clienteffect/space_command/shp_astromech_effects_04.cef", "")
      CreatureObject(pPlayer):sendSystemMessage("Enemy Wave Starting!")
      spatialChat(pBoss, "Boss Current Health = 70%")
      writeData("wampa_cave:spawnState",4)
      local threespawn = spawnMobile("hoth", " ", 0, 6.70729, -0.027031, 97.9255, 169, 14200878)
      local threespawn = spawnMobile("hoth", " ", 0, 21.089, -0.0977471, 61.4571, 359, 14200878)
      ObjectManager.withCreatureObject(threespawn, function(ofirstTime)
      writeData("countadd", ofirstTime:getObjectID())
      ofirstTime:engageCombat(pPlayer)
			end)
		end	
--------------------------------------
--  60% health check
--------------------------------------
if (((bossHealth <= (bossMaxHealth * 0.6)) or (bossAction <= (bossMaxAction * 0.6)) or (bossMind <= (bossMaxMind * 0.6))) and readData("wampa_cave:spawnState") == 4) then
      CreatureObject(pPlayer):sendSystemMessage("You take damage from the fire")
      local trapDmg = getRandomNumber(500, 1000)
      CreatureObject(pPlayer):inflictDamage(pPlayer, 0, trapDmg, 1)
      CreatureObject(pPlayer):playEffect("clienteffect/restuss_event_artillery_ground.cef", "")
      CreatureObject(pPlayer):playEffect("clienteffect/combat_turret_0_miss_terrain_01.cef", "")
      CreatureObject(pBoss):playEffect("clienteffect/incubator_mutation.cef", "")
      CreatureObject(pBoss):playEffect("clienteffect/space_command/shp_astromech_effects_04.cef", "")
      CreatureObject(pPlayer):sendSystemMessage("Enemy Wave Starting!")
      spatialChat(pBoss, "Boss Current Health = 60%")
      writeData("wampa_cave:spawnState",5)
      local fourspawn = spawnMobile("hoth", " ", 0, 6.70729, -0.027031, 97.9255, 169, 14200878)
      local fourspawn = spawnMobile("hoth", " ", 0, 21.089, -0.0977471, 61.4571, 359, 14200878)
      ObjectManager.withCreatureObject(fourspawn, function(ofirstTime)
      writeData("countadd", ofirstTime:getObjectID())
      ofirstTime:engageCombat(pPlayer)
			end)
		end
--------------------------------------
--  50% health check
--------------------------------------
if (((bossHealth <= (bossMaxHealth * 0.5)) or (bossAction <= (bossMaxAction * 0.5)) or (bossMind <= (bossMaxMind * 0.5))) and readData("wampa_cave:spawnState") == 5) then
      CreatureObject(pPlayer):sendSystemMessage("You take damage from the fire")
      local trapDmg = getRandomNumber(500, 1000)
      CreatureObject(pPlayer):inflictDamage(pPlayer, 0, trapDmg, 1)
      CreatureObject(pPlayer):playEffect("clienteffect/restuss_event_artillery_ground.cef", "")
      CreatureObject(pPlayer):playEffect("clienteffect/combat_turret_0_miss_terrain_01.cef", "")
      CreatureObject(pBoss):playEffect("clienteffect/incubator_mutation.cef", "")
      CreatureObject(pBoss):playEffect("clienteffect/space_command/shp_astromech_effects_04.cef", "")
      CreatureObject(pPlayer):sendSystemMessage("Enemy Wave Starting!")
      spatialChat(pBoss, "Boss Current Health = 50%")
      writeData("wampa_cave:spawnState",6)
      local fivespawn = spawnMobile("hoth", " ", 0, 6.70729, -0.027031, 97.9255, 169, 14200878)
      local fivespawn = spawnMobile("hoth", " ", 0, 21.089, -0.0977471, 61.4571, 359, 14200878)
      ObjectManager.withCreatureObject(fivespawn, function(ofirstTime)
      writeData("countadd", ofirstTime:getObjectID())
      ofirstTime:engageCombat(pPlayer)
			end)
		end
--------------------------------------
--  40% health check
--------------------------------------
if (((bossHealth <= (bossMaxHealth * 0.4)) or (bossAction <= (bossMaxAction * 0.4)) or (bossMind <= (bossMaxMind * 0.4))) and readData("wampa_cave:spawnState") == 6) then
      CreatureObject(pPlayer):sendSystemMessage("You take damage from the fire")
      local trapDmg = getRandomNumber(500, 1000)
      CreatureObject(pPlayer):inflictDamage(pPlayer, 0, trapDmg, 1)
      CreatureObject(pPlayer):playEffect("clienteffect/restuss_event_artillery_ground.cef", "")
      CreatureObject(pPlayer):playEffect("clienteffect/combat_turret_0_miss_terrain_01.cef", "")
      CreatureObject(pBoss):playEffect("clienteffect/incubator_mutation.cef", "")
      CreatureObject(pBoss):playEffect("clienteffect/space_command/shp_astromech_effects_04.cef", "")
      CreatureObject(pPlayer):sendSystemMessage("Enemy Wave Starting!")
      spatialChat(pBoss, "Boss Current Health = 40%")
      writeData("wampa_cave:spawnState",7)
      local sixspawn = spawnMobile("hoth", " ", 0, 6.70729, -0.027031, 97.9255, 169, 14200878)
      local sixspawn = spawnMobile("hoth", " ", 0, 21.089, -0.0977471, 61.4571, 359, 14200878)
      ObjectManager.withCreatureObject(sixspawn, function(ofirstTime)
      writeData("countadd", ofirstTime:getObjectID())
      ofirstTime:engageCombat(pPlayer)
			end)
		end
--------------------------------------
--  30% health check
--------------------------------------
if (((bossHealth <= (bossMaxHealth * 0.3)) or (bossAction <= (bossMaxAction * 0.3)) or (bossMind <= (bossMaxMind * 0.3))) and readData("wampa_cave:spawnState") == 7) then
      CreatureObject(pPlayer):sendSystemMessage("You take damage from the fire")
      local trapDmg = getRandomNumber(500, 1000)
      CreatureObject(pPlayer):inflictDamage(pPlayer, 0, trapDmg, 1)
      CreatureObject(pPlayer):playEffect("clienteffect/restuss_event_artillery_ground.cef", "")
      CreatureObject(pPlayer):playEffect("clienteffect/combat_turret_0_miss_terrain_01.cef", "")
      CreatureObject(pBoss):playEffect("clienteffect/incubator_mutation.cef", "")
      CreatureObject(pBoss):playEffect("clienteffect/space_command/shp_astromech_effects_04.cef", "")
      CreatureObject(pPlayer):sendSystemMessage("Enemy Wave Starting!")
      spatialChat(pBoss, "Boss Current Health = 30%")
      writeData("wampa_cave:spawnState",8)
      local sevenspawn = spawnMobile("hoth", " ", 0, 6.70729, -0.027031, 97.9255, 169, 14200878)
      local sevenspawn = spawnMobile("hoth", " ", 0, 21.089, -0.0977471, 61.4571, 359, 14200878)
      ObjectManager.withCreatureObject(sevenspawn, function(ofirstTime)
      writeData("countadd", ofirstTime:getObjectID())
      ofirstTime:engageCombat(pPlayer)
			end)
		end
--------------------------------------
--  20% health check
--------------------------------------
if (((bossHealth <= (bossMaxHealth * 0.2)) or (bossAction <= (bossMaxAction * 0.2)) or (bossMind <= (bossMaxMind * 0.2))) and readData("wampa_cave:spawnState") == 8) then
      CreatureObject(pPlayer):sendSystemMessage("You take damage from the fire")
      local trapDmg = getRandomNumber(500, 1000)
      CreatureObject(pPlayer):inflictDamage(pPlayer, 0, trapDmg, 1)
      CreatureObject(pPlayer):playEffect("clienteffect/restuss_event_artillery_ground.cef", "")
      CreatureObject(pPlayer):playEffect("clienteffect/combat_turret_0_miss_terrain_01.cef", "")
      CreatureObject(pBoss):playEffect("clienteffect/incubator_mutation.cef", "")
      CreatureObject(pBoss):playEffect("clienteffect/space_command/shp_astromech_effects_04.cef", "")
      CreatureObject(pPlayer):sendSystemMessage("Enemy Wave Starting!")
      spatialChat(pBoss, "Boss Current Health = 20%")
      writeData("wampa_cave:spawnState",9)  
      local eightspawn = spawnMobile("hoth", " ", 0, 6.70729, -0.027031, 97.9255, 169, 14200878)
      local eightspawn = spawnMobile("hoth", " ", 0, 21.089, -0.0977471, 61.4571, 359, 14200878)
      ObjectManager.withCreatureObject(eightspawn, function(ofirstTime)
      writeData("countadd", ofirstTime:getObjectID())
      ofirstTime:engageCombat(pPlayer)
			end)
		end
--------------------------------------
--  10% health check
--------------------------------------
if (((bossHealth <= (bossMaxHealth * 0.1)) or (bossAction <= (bossMaxAction * 0.1)) or (bossMind <= (bossMaxMind * 0.1))) and readData("wampa_cave:spawnState") == 9) then
      CreatureObject(pPlayer):sendSystemMessage("You take damage from the fire")
      local trapDmg = getRandomNumber(500, 1000)
      CreatureObject(pPlayer):inflictDamage(pPlayer, 0, trapDmg, 1)
      CreatureObject(pPlayer):playEffect("clienteffect/restuss_event_artillery_ground.cef", "")
      CreatureObject(pPlayer):playEffect("clienteffect/combat_turret_0_miss_terrain_01.cef", "")
      CreatureObject(pBoss):playEffect("clienteffect/incubator_mutation.cef", "")
      CreatureObject(pBoss):playEffect("clienteffect/space_command/shp_astromech_effects_04.cef", "")
      CreatureObject(pPlayer):sendSystemMessage("Enemy Wave Starting!")
      spatialChat(pBoss, "Boss Current Health = 10%")
      writeData("wampa_cave:spawnState",10)
      local ninespawn = spawnMobile("hoth", "", 0, 6.70729, -0.027031, 97.9255, 169, 14200878)
      local ninespawn = spawnMobile("hoth", "", 0, 21.089, -0.0977471, 61.4571, 359, 14200878)
      ObjectManager.withCreatureObject(ninespawn, function(ofirstTime)
      writeData("countadd", ofirstTime:getObjectID())
      ofirstTime:engageCombat(pPlayer)
			end)
		end
--------------------------------------------------------------------------------
--   Check that the boss has died, Broadcast server wide, set state for players
--------------------------------------------------------------------------------
if (((bossHealth <= (bossMaxHealth * 0.001)) or (bossAction <= (bossMaxAction * 0.001)) or (bossMind <= (bossMaxMind * 0.001))) and readData("wampa_cave:spawnState") == 10) then
      spatialChat(pBoss, "We shall meet again uggggh!.")
      spatialChat(pBoss, "You have 5 minuets to loot my body befor it disappears.")
            writeData("wampa_cave:spawnState",11)
        end
      end
   return 0
end
----------------------------
--Broadcast Initial Respawn
----------------------------
function wampa_cave:BroadcastRespawn(pPlayer)
		local player = LuaCreatureObject(pPlayer)
		player:broadcastToServer("\\#63C8F9 Wampa Boss Respawning In 3 Hours")
		player:broadcastToDiscord("Wampa Boss Respawning In 3 Hours")
    	print("Starting Boss Respawn Broadcast Message")
end
-----------------------
--Broadcast Respawn
-----------------------
function wampa_cave:KillSpawnCast(pPlayer)
		local player = LuaCreatureObject(pPlayer)
		player:broadcastToServer("\\#63C8F9 Wampa Boss Respawning In ..")
		player:broadcastToDiscord("Janta Boss Respawning In ..")
end
-----------------------
--Broadcast Respawn 3
-----------------------
function wampa_cave:KillSpawnCast1(pPlayer)
		local player = LuaCreatureObject(pPlayer)
		player:broadcastToServer("\\#63C8F9 3")
		player:broadcastToDiscord("3")
end
-----------------------
--Broadcast Respawn 2
-----------------------
function wampa_cave:KillSpawnCast2(pPlayer)
		local player = LuaCreatureObject(pPlayer)
		player:broadcastToServer("\\#63C8F9 2")
		player:broadcastToDiscord("2")
end
-----------------------
--Broadcast Respawn 1
-----------------------
function wampa_cave:KillSpawnCast3(pPlayer)
		local player = LuaCreatureObject(pPlayer)
		player:broadcastToServer("\\#63C8F9 1")
		player:broadcastToDiscord("1")
    	print("Wampa Is Respawning")
end
-----------------------------------------------------------------------------
--The Boss Has Died Without Being Looted, "Abandon" Destroy NPC, Destroy Loot
-----------------------------------------------------------------------------
function wampa_cave:KillBoss(pBoss)
	dropObserver(pBoss, OBJECTDESTRUCTION)
	if SceneObject(pBoss) then
		print("Unlooted Wampa Boss Destroyed")
		SceneObject(pBoss):destroyObjectFromWorld()
		return 0
	end
end
----------------------------
--Remove Boss After 3 hours
----------------------------
function wampa_cave:Remove(pBoss)
	if SceneObject(pBoss) then
		print("Wampa Boss Removed")
		SceneObject(pBoss):destroyObjectFromWorld()
		dropObserver(pBoss, OBJECTDESTRUCTION)
		dropObserver(pBoss, DAMAGERECEIVED)
		forcePeace(pBoss)
		forcePeace(pBoss)
		forcePeace(pBoss)
		forcePeace(pBoss)
		forcePeace(pBoss)
		forcePeace(pBoss)
		end
		return 0
end
----------------------------
--Reset Player Boss States
----------------------------
function wampa_cave:Restartstates(pPlayer)
   writeData("wampa_cave:spawnState", 0)
end
