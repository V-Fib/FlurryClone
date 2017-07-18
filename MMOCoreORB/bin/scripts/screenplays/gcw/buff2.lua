local ObjectManager = require("managers.object.object_manager")

buff2 = ScreenPlay:new {
	numberOfActs = 1,
  	questString = "buff2",
  	questdata = Object:new {
    	activePlayerName = "initial",
    	}
}
  
registerScreenPlay("buff2", true)
  
function buff2:start()
    	self:spawnActiveAreas()
end

function buff2:spawnActiveAreas()
	local pSpawnArea = spawnSceneObject("naboo", "object/active_area.iff", -5183, 5, 4266, 0, 0, 0, 0, 0)
    
	if (pSpawnArea ~= nil) then
		local activeArea = LuaActiveArea(pSpawnArea)
	        activeArea:setCellObjectID(0)
	        activeArea:setRadius(25)
	        createObserver(ENTEREDAREA, "buff2", "notifySpawnArea", pSpawnArea)
	        createObserver(EXITEDAREA, "buff2", "notifySpawnAreaLeave", pSpawnArea)
	    end
end
 
function buff2:notifySpawnArea(pActiveArea, pMovingObject)
	
	if (not SceneObject(pMovingObject):isCreatureObject()) then
		return 0
	end
	
	return ObjectManager.withCreatureObject(pMovingObject, function(player)
		if (player:isAiAgent()) then
			return 0
		end
		
		if (player:isInCombat() ~= true) then
			--player:broadcastToServer("\\#00E604" .. player:getFirstName() .. "\\#63C8F9 Has entered the buff2 Zone!")
			player:sendSystemMessage("You have entered the buff2 zone!")
			player:removeAllStructureSkillMod()
			player:addStructureSkillMod("private_buff2_mind", 150)
			player:addStructureSkillMod("private_med_battle_fatigue", 15)
			player:addStructureSkillMod("private_med_wound_mind", 15)
			player:addStructureSkillMod("private_medical_rating", 150)
			player:addStructureSkillMod("private_med_wound_mind", 20)
			player:addStructureSkillMod("private_buff2_mind", 150)
			player:addStructureSkillMod("private_med_battle_fatigue", 5)
			player:addStructureSkillMod("private_med_wound_health", 150)
			player:addStructureSkillMod("private_med_wound_action", 150)
			player:addStructureSkillMod("private_safe_logout", 1)

		else
			player:sendSystemMessage("You must be out of combat to enter the buff2 zone!")
			player:teleport(3469, 5, -4883, 0)
		end
		return 0
	end)
end

function buff2:notifySpawnAreaLeave(pActiveArea, pMovingObject)
	
	if (not SceneObject(pMovingObject):isCreatureObject()) then
		return 0
	end
	
	return ObjectManager.withCreatureObject(pMovingObject, function(player)
		if (player:isAiAgent()) then
			return 0
		end
		
		if (player:isImperial() or player:isRebel() or player:isNeutral()) then
			player:sendSystemMessage("You have left the buff2 zone!")
			player:removeAllStructureSkillMod()
		end
		return 0
	end)
end
