/*
* HolocronMenuComponent.cpp
*
*  Created on: 09/16/2019
*	 Author: TOXIC  
*/

#include "HolocronMenuComponent.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/managers/jedi/JediManager.h"

int HolocronMenuComponent::handleObjectMenuSelect(SceneObject* sceneObject, CreatureObject* creature, byte selectedID) const {
	if (selectedID != 20)
		return 0;

	if (!sceneObject->isASubChildOf(creature))
		return 0;

	JediManager::instance()->useItem(sceneObject, JediManager::ITEMHOLOCRON, creature);

	return 0;
}
