--------------------------------------
--   Creator : TOXIC
--   Date : 06/15/2021
--------------------------------------
local ObjectManager = require("managers.object.object_manager")

jedi2 = ScreenPlay:new {
	numberOfActs = 1,
  	questString = "jedi2",
  	questdata = Object:new {
    	activePlayerName = "initial",
    	}
}
  
registerScreenPlay("jedi2", true)
  
function jedi2:start()
    	self:spawnActiveAreas()
end
  
function jedi2:spawnActiveAreas()
	local pSpawnArea = spawnSceneObject("dathomir", "object/active_area.iff", 5297, 78, -4129, 0, 0, 0, 0, 0)
    
	if (pSpawnArea ~= nil) then
		local activeArea = LuaActiveArea(pSpawnArea)
	        activeArea:setCellObjectID(0)
	        activeArea:setRadius(10)
	        createObserver(ENTEREDAREA, "jedi2", "notifySpawnArea", pSpawnArea)
	        createObserver(EXITEDAREA, "jedi2", "notifySpawnAreaLeave", pSpawnArea)
	    end
end
 
function jedi2:notifySpawnArea(pActiveArea, pMovingObject)
	
	if (not SceneObject(pMovingObject):isCreatureObject()) then
		return 0
	end
	
	return ObjectManager.withCreatureObject(pMovingObject, function(player)
		if (player:isAiAgent()) then
			return 0
		end
		
		if (player:hasSkill("combat_jedi_novice")) then
			player:sendSystemMessage("You have entered the training area!")
		else
			player:sendSystemMessage("You must be a gray jedi to enter the training area!")
			player:teleport(5285, 78, -4171, 0)
		end
		return 0
	end)
end

function jedi2:notifySpawnAreaLeave(pActiveArea, pMovingObject)
	
	if (not SceneObject(pMovingObject):isCreatureObject()) then
		return 0
	end
	
	return ObjectManager.withCreatureObject(pMovingObject, function(player)
		if (player:isAiAgent()) then
			return 0
		end
		
		if (player:hasSkill("combat_jedi_novice")) then
			player:sendSystemMessage("You have left training area!")
		end
		return 0
	end)
end
