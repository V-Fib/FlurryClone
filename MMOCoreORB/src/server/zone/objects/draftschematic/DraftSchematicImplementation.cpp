/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#include "server/zone/objects/draftschematic/DraftSchematic.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"
#include "server/zone/objects/intangible/IntangibleObject.h"

void DraftSchematicImplementation::initializeTransientMembers() {
	IntangibleObjectImplementation::initializeTransientMembers();

	setGlobalLogging(true);
	setLogging(false);

	setLoggingName("DraftSchematic");
}

void DraftSchematicImplementation::loadTemplateData(SharedObjectTemplate* templateData) {
	IntangibleObjectImplementation::loadTemplateData(templateData);

	schematicTemplate = dynamic_cast<DraftSchematicObjectTemplate*>(templateData);
}

void DraftSchematicImplementation::fillAttributeList(AttributeListMessage* alm, CreatureObject* object) {


}

void DraftSchematicImplementation::sendBaselinesTo(SceneObject* player) {
	if (!player->isPlayerCreature())
		return;

	error("Trying to send DraftSchematic baselines, should not be sending");
}

void DraftSchematicImplementation::sendDraftSlotsTo(CreatureObject* player) {
	CreatureObject* playerCreature = cast<CreatureObject*>( player);

	ObjectControllerMessage* msg = new ObjectControllerMessage(player->getObjectID(), 0x0B, 0x01BF);

	msg->insertInt(clientObjectCRC);
	msg->insertInt(clientObjectCRC);

	msg->insertInt(schematicTemplate->getComplexity()); // ex: 3
	msg->insertInt(schematicTemplate->getSize()); // ex: 1
	msg->insertByte(2);

	insertIngredients(msg);

	player->sendMessage(msg);

}

void DraftSchematicImplementation::insertIngredients(ObjectControllerMessage* msg) {
	const Vector<Reference<DraftSlot* > >* draftSlots = schematicTemplate->getDraftSlots();

	msg->insertInt(draftSlots->size());

	for(int i = 0; i < draftSlots->size(); ++i) {
		draftSlots->get(i)->insertToMessage(msg);
	}

	msg->insertShort(0);
}

void DraftSchematicImplementation::sendResourceWeightsTo(CreatureObject* player) {
	const Vector<Reference<ResourceWeight* > >* resourceWeights = schematicTemplate->getResourceWeights();

	if (resourceWeights == NULL){
		Logger::console.error("resourceWeights null for draft schematic template: " + schematicTemplate->getTemplateFileName() + " This is likely due to a typo in the lua template file.");		
		player->sendSystemMessage("There was an error on server that prevented this crafting action from completing. The error has been logged. Please contact support for further assistance.");
		
		// Note: The broken draft schematic will be added to the player's crafting tool, but the tool will not let them use it.

		return;
	}

	ObjectControllerMessage* msg = new ObjectControllerMessage(player->getObjectID(), 0x0B, 0x0207);

	msg->insertInt(clientObjectCRC);
	msg->insertInt(clientObjectCRC);

	msg->insertByte(resourceWeights->size());

	//Send all the resource batch property data
	for (int i = 0; i < resourceWeights->size(); i++)
		resourceWeights->get(i)->insertBatchToMessage(msg);

	msg->insertByte(resourceWeights->size());

	//Send all the resource property data
	for (int i = 0; i < resourceWeights->size(); i++)
		resourceWeights->get(i)->insertToMessage(msg);

	player->sendMessage(msg);
}

Reference<SceneObject*> DraftSchematicImplementation::createManufactureSchematic(SceneObject* craftingTool) {
	Reference<ManufactureSchematic*> manuSchematic =
			 (getZoneServer()->createObject(0xF75E04C2, 0)).castTo<ManufactureSchematic* >();

	if(manuSchematic == nullptr) {
		error("Could not create ManufactureSchematic for " + getObjectNameStringIdName());
		return nullptr;
	}

	Locker locker(manuSchematic);

	manuSchematic->createChildObjects();

	manuSchematic->setDraftSchematic(_this.getReferenceUnsafeStaticCast());

	return Reference<SceneObject*>(manuSchematic.get());
}

int DraftSchematicImplementation::getDraftSlotCount() {
	return schematicTemplate->getDraftSlots()->size();
}

DraftSlot* DraftSchematicImplementation::getDraftSlot(int i) {
	return schematicTemplate->getDraftSlots()->get(i);
}

int DraftSchematicImplementation::getResourceWeightCount() {
	return schematicTemplate->getResourceWeights()->size();
}

ResourceWeight* DraftSchematicImplementation::getResourceWeight(int i) {
	return schematicTemplate->getResourceWeights()->get(i);
}


float DraftSchematicImplementation::getComplexity() {
	return (float)schematicTemplate->getComplexity();
}

uint32 DraftSchematicImplementation::getToolTab() {
	return (uint32)schematicTemplate->getCraftingToolTab();
}

float DraftSchematicImplementation::getSize() {
	return (float)schematicTemplate->getSize();
}

String DraftSchematicImplementation::getXpType() {
	return schematicTemplate->getXpType();
}

int DraftSchematicImplementation::getXpAmount() {
	return schematicTemplate->getXp();
}

bool DraftSchematicImplementation::getIsMagic() {
	return schematicTemplate->getIsMagic();
}

String DraftSchematicImplementation::getAssemblySkill() {
	return schematicTemplate->getAssemblySkill();
}

String DraftSchematicImplementation::getExperimentationSkill() {
	return schematicTemplate->getExperimentingSkill();
}

String DraftSchematicImplementation::getCustomizationSkill() {
	return schematicTemplate->getCustomizationSkill();
}

String DraftSchematicImplementation::getCustomName() {
if (schematicTemplate == nullptr) {		
	error("ERROR Illegal Argument Exception");
	return nullptr;
	}
	return schematicTemplate->getCustomObjectName();
	error("Safe Argument Exception");
}

uint32 DraftSchematicImplementation::getTanoCRC() {
	return schematicTemplate->getTanoCRC();
}

int DraftSchematicImplementation::getLabratory() {
	return schematicTemplate->getLabratory();
}

int DraftSchematicImplementation::getFactoryCrateSize() {
	return schematicTemplate->getFactoryCrateSize();
}
