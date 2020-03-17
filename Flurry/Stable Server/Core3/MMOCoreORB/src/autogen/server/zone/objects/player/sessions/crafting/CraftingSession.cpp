/*
 *	autogen/server/zone/objects/player/sessions/crafting/CraftingSession.cpp generated by engine3 IDL compiler 0.70
 */

#include "CraftingSession.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/player/PlayerObject.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "server/zone/objects/tangible/tool/CraftingStation.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"

#include "server/zone/objects/draftschematic/DraftSchematic.h"

#include "server/zone/managers/crafting/CraftingManager.h"

/*
 *	CraftingSessionStub
 */

enum {RPC_INITIALIZESESSION__CRAFTINGTOOL_CRAFTINGSTATION_ = 932433072,RPC_CANCELSESSION__,RPC_CLEARSESSION__,RPC_GETSCHEMATIC__,RPC_SELECTDRAFTSCHEMATIC__INT_,RPC_SENDINGREDIENTFORUILISTEN__,RPC_ADDINGREDIENT__TANGIBLEOBJECT_INT_INT_,RPC_REMOVEINGREDIENT__TANGIBLEOBJECT_INT_INT_,RPC_NEXTCRAFTINGSTAGE__INT_,RPC_EXPERIMENT__INT_STRING_INT_,RPC_CUSTOMIZATION__STRING_BYTE_INT_STRING_,RPC_CREATEPROTOTYPE__INT_BOOL_,RPC_CREATEMANUFACTURESCHEMATIC__INT_,RPC_GETSTATE__,};

CraftingSession::CraftingSession(CreatureObject* creature) : Facade(DummyConstructorParameter::instance()) {
	CraftingSessionImplementation* _implementation = new CraftingSessionImplementation(creature);
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("CraftingSession");
}

CraftingSession::CraftingSession(DummyConstructorParameter* param) : Facade(param) {
	_setClassName("CraftingSession");
}

CraftingSession::~CraftingSession() {
}



int CraftingSession::initializeSession(CraftingTool* tool, CraftingStation* station) {
	CraftingSessionImplementation* _implementation = static_cast<CraftingSessionImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZESESSION__CRAFTINGTOOL_CRAFTINGSTATION_);
		method.addObjectParameter(tool);
		method.addObjectParameter(station);

		return method.executeWithSignedIntReturn();
	} else {
		return _implementation->initializeSession(tool, station);
	}
}

int CraftingSession::cancelSession() {
	CraftingSessionImplementation* _implementation = static_cast<CraftingSessionImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CANCELSESSION__);

		return method.executeWithSignedIntReturn();
	} else {
		return _implementation->cancelSession();
	}
}

int CraftingSession::clearSession() {
	CraftingSessionImplementation* _implementation = static_cast<CraftingSessionImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CLEARSESSION__);

		return method.executeWithSignedIntReturn();
	} else {
		return _implementation->clearSession();
	}
}

ManagedWeakReference<ManufactureSchematic* > CraftingSession::getSchematic() {
	CraftingSessionImplementation* _implementation = static_cast<CraftingSessionImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETSCHEMATIC__);

		return static_cast<ManufactureSchematic*>(method.executeWithObjectReturn());
	} else {
		return _implementation->getSchematic();
	}
}

void CraftingSession::selectDraftSchematic(int index) {
	CraftingSessionImplementation* _implementation = static_cast<CraftingSessionImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SELECTDRAFTSCHEMATIC__INT_);
		method.addSignedIntParameter(index);

		method.executeWithVoidReturn();
	} else {
		assert(this->isLockedByCurrentThread());
		_implementation->selectDraftSchematic(index);
	}
}

void CraftingSession::sendIngredientForUIListen() {
	CraftingSessionImplementation* _implementation = static_cast<CraftingSessionImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDINGREDIENTFORUILISTEN__);

		method.executeWithVoidReturn();
	} else {
		assert(this->isLockedByCurrentThread());
		_implementation->sendIngredientForUIListen();
	}
}

void CraftingSession::addIngredient(TangibleObject* tano, int slotUpdated, int clientCounter) {
	CraftingSessionImplementation* _implementation = static_cast<CraftingSessionImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ADDINGREDIENT__TANGIBLEOBJECT_INT_INT_);
		method.addObjectParameter(tano);
		method.addSignedIntParameter(slotUpdated);
		method.addSignedIntParameter(clientCounter);

		method.executeWithVoidReturn();
	} else {
		assert(this->isLockedByCurrentThread());
		_implementation->addIngredient(tano, slotUpdated, clientCounter);
	}
}

void CraftingSession::removeIngredient(TangibleObject* tano, int slotUpdated, int clientCounter) {
	CraftingSessionImplementation* _implementation = static_cast<CraftingSessionImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_REMOVEINGREDIENT__TANGIBLEOBJECT_INT_INT_);
		method.addObjectParameter(tano);
		method.addSignedIntParameter(slotUpdated);
		method.addSignedIntParameter(clientCounter);

		method.executeWithVoidReturn();
	} else {
		assert(this->isLockedByCurrentThread());
		_implementation->removeIngredient(tano, slotUpdated, clientCounter);
	}
}

void CraftingSession::nextCraftingStage(int clientCounter) {
	CraftingSessionImplementation* _implementation = static_cast<CraftingSessionImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NEXTCRAFTINGSTAGE__INT_);
		method.addSignedIntParameter(clientCounter);

		method.executeWithVoidReturn();
	} else {
		assert(this->isLockedByCurrentThread());
		_implementation->nextCraftingStage(clientCounter);
	}
}

void CraftingSession::experiment(int rowsAttempted, const String& expAttempt, int clientCounter) {
	CraftingSessionImplementation* _implementation = static_cast<CraftingSessionImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_EXPERIMENT__INT_STRING_INT_);
		method.addSignedIntParameter(rowsAttempted);
		method.addAsciiParameter(expAttempt);
		method.addSignedIntParameter(clientCounter);

		method.executeWithVoidReturn();
	} else {
		assert(this->isLockedByCurrentThread());
		_implementation->experiment(rowsAttempted, expAttempt, clientCounter);
	}
}

void CraftingSession::customization(const String& name, byte templateChoice, int schematicCount, const String& customizationString) {
	CraftingSessionImplementation* _implementation = static_cast<CraftingSessionImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CUSTOMIZATION__STRING_BYTE_INT_STRING_);
		method.addAsciiParameter(name);
		method.addByteParameter(templateChoice);
		method.addSignedIntParameter(schematicCount);
		method.addAsciiParameter(customizationString);

		method.executeWithVoidReturn();
	} else {
		assert(this->isLockedByCurrentThread());
		_implementation->customization(name, templateChoice, schematicCount, customizationString);
	}
}

void CraftingSession::createPrototype(int clientCounter, bool practice) {
	CraftingSessionImplementation* _implementation = static_cast<CraftingSessionImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CREATEPROTOTYPE__INT_BOOL_);
		method.addSignedIntParameter(clientCounter);
		method.addBooleanParameter(practice);

		method.executeWithVoidReturn();
	} else {
		assert(this->isLockedByCurrentThread());
		_implementation->createPrototype(clientCounter, practice);
	}
}

void CraftingSession::createManufactureSchematic(int clientCounter) {
	CraftingSessionImplementation* _implementation = static_cast<CraftingSessionImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CREATEMANUFACTURESCHEMATIC__INT_);
		method.addSignedIntParameter(clientCounter);

		method.executeWithVoidReturn();
	} else {
		assert(this->isLockedByCurrentThread());
		_implementation->createManufactureSchematic(clientCounter);
	}
}

int CraftingSession::getState() {
	CraftingSessionImplementation* _implementation = static_cast<CraftingSessionImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETSTATE__);

		return method.executeWithSignedIntReturn();
	} else {
		return _implementation->getState();
	}
}

DistributedObjectServant* CraftingSession::_getImplementation() {

	 if (!_updated) _updated = true;
	return _impl;
}

DistributedObjectServant* CraftingSession::_getImplementationForRead() const {
	return _impl;
}

void CraftingSession::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	CraftingSessionImplementation
 */

CraftingSessionImplementation::CraftingSessionImplementation(DummyConstructorParameter* param) : FacadeImplementation(param) {
	_initializeImplementation();
}


CraftingSessionImplementation::~CraftingSessionImplementation() {
}


void CraftingSessionImplementation::finalize() {
}

void CraftingSessionImplementation::_initializeImplementation() {
	_setClassHelper(CraftingSessionHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void CraftingSessionImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<CraftingSession*>(stub);
	FacadeImplementation::_setStub(stub);
}

DistributedObjectStub* CraftingSessionImplementation::_getStub() {
	return _this.get();
}

CraftingSessionImplementation::operator const CraftingSession*() {
	return _this.get();
}

void CraftingSessionImplementation::lock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->lock(doLock);
}

void CraftingSessionImplementation::lock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->lock(obj);
}

void CraftingSessionImplementation::rlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->rlock(doLock);
}

void CraftingSessionImplementation::wlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->wlock(doLock);
}

void CraftingSessionImplementation::wlock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->wlock(obj);
}

void CraftingSessionImplementation::unlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->unlock(doLock);
}

void CraftingSessionImplementation::runlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->runlock(doLock);
}

void CraftingSessionImplementation::_serializationHelperMethod() {
	FacadeImplementation::_serializationHelperMethod();

	_setClassName("CraftingSession");

}

void CraftingSessionImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		uint32 _nameHashCode;
		TypeInfo<uint32>::parseFromBinaryStream(&_nameHashCode, stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(CraftingSessionImplementation::readObjectMember(stream, _nameHashCode)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool CraftingSessionImplementation::readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode) {
	if (FacadeImplementation::readObjectMember(stream, nameHashCode))
		return true;

	switch(nameHashCode) {
	}

	return false;
}

void CraftingSessionImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = CraftingSessionImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int CraftingSessionImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = FacadeImplementation::writeObjectMembers(stream);

	uint32 _nameHashCode;
	int _offset;
	uint32 _totalSize;

	return _count;
}

CraftingSessionImplementation::CraftingSessionImplementation(CreatureObject* creature) {
	_initializeImplementation();
	// server/zone/objects/player/sessions/crafting/CraftingSession.idl():  		Logger.setLoggingName("CraftingSession");
	Logger::setLoggingName("CraftingSession");
	// server/zone/objects/player/sessions/crafting/CraftingSession.idl():  		Logger.setLogging(true);
	Logger::setLogging(true);
	// server/zone/objects/player/sessions/crafting/CraftingSession.idl():  		crafter = creature;
	crafter = creature;
	// server/zone/objects/player/sessions/crafting/CraftingSession.idl():  		craftingManager = null;
	craftingManager = NULL;
}

ManagedWeakReference<ManufactureSchematic* > CraftingSessionImplementation::getSchematic() {
	// server/zone/objects/player/sessions/crafting/CraftingSession.idl():  		return manufactureSchematic;
	return manufactureSchematic;
}

int CraftingSessionImplementation::getState() {
	// server/zone/objects/player/sessions/crafting/CraftingSession.idl():  		return state;
	return state;
}

/*
 *	CraftingSessionAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


CraftingSessionAdapter::CraftingSessionAdapter(CraftingSession* obj) : FacadeAdapter(obj) {
}

void CraftingSessionAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_INITIALIZESESSION__CRAFTINGTOOL_CRAFTINGSTATION_:
		{
			CraftingTool* tool = static_cast<CraftingTool*>(inv->getObjectParameter());
			CraftingStation* station = static_cast<CraftingStation*>(inv->getObjectParameter());
			
			int _m_res = initializeSession(tool, station);
			resp->insertSignedInt(_m_res);
		}
		break;
	case RPC_CANCELSESSION__:
		{
			
			int _m_res = cancelSession();
			resp->insertSignedInt(_m_res);
		}
		break;
	case RPC_CLEARSESSION__:
		{
			
			int _m_res = clearSession();
			resp->insertSignedInt(_m_res);
		}
		break;
	case RPC_GETSCHEMATIC__:
		{
			
			DistributedObject* _m_res = getSchematic().get();
			resp->insertLong(_m_res == NULL ? 0 : _m_res->_getObjectID());
		}
		break;
	case RPC_SELECTDRAFTSCHEMATIC__INT_:
		{
			int index = inv->getSignedIntParameter();
			
			selectDraftSchematic(index);
			
		}
		break;
	case RPC_SENDINGREDIENTFORUILISTEN__:
		{
			
			sendIngredientForUIListen();
			
		}
		break;
	case RPC_ADDINGREDIENT__TANGIBLEOBJECT_INT_INT_:
		{
			TangibleObject* tano = static_cast<TangibleObject*>(inv->getObjectParameter());
			int slotUpdated = inv->getSignedIntParameter();
			int clientCounter = inv->getSignedIntParameter();
			
			addIngredient(tano, slotUpdated, clientCounter);
			
		}
		break;
	case RPC_REMOVEINGREDIENT__TANGIBLEOBJECT_INT_INT_:
		{
			TangibleObject* tano = static_cast<TangibleObject*>(inv->getObjectParameter());
			int slotUpdated = inv->getSignedIntParameter();
			int clientCounter = inv->getSignedIntParameter();
			
			removeIngredient(tano, slotUpdated, clientCounter);
			
		}
		break;
	case RPC_NEXTCRAFTINGSTAGE__INT_:
		{
			int clientCounter = inv->getSignedIntParameter();
			
			nextCraftingStage(clientCounter);
			
		}
		break;
	case RPC_EXPERIMENT__INT_STRING_INT_:
		{
			int rowsAttempted = inv->getSignedIntParameter();
			 String expAttempt; inv->getAsciiParameter(expAttempt);
			int clientCounter = inv->getSignedIntParameter();
			
			experiment(rowsAttempted, expAttempt, clientCounter);
			
		}
		break;
	case RPC_CUSTOMIZATION__STRING_BYTE_INT_STRING_:
		{
			 String name; inv->getAsciiParameter(name);
			byte templateChoice = inv->getByteParameter();
			int schematicCount = inv->getSignedIntParameter();
			 String customizationString; inv->getAsciiParameter(customizationString);
			
			customization(name, templateChoice, schematicCount, customizationString);
			
		}
		break;
	case RPC_CREATEPROTOTYPE__INT_BOOL_:
		{
			int clientCounter = inv->getSignedIntParameter();
			bool practice = inv->getBooleanParameter();
			
			createPrototype(clientCounter, practice);
			
		}
		break;
	case RPC_CREATEMANUFACTURESCHEMATIC__INT_:
		{
			int clientCounter = inv->getSignedIntParameter();
			
			createManufactureSchematic(clientCounter);
			
		}
		break;
	case RPC_GETSTATE__:
		{
			
			int _m_res = getState();
			resp->insertSignedInt(_m_res);
		}
		break;
	default:
		FacadeAdapter::invokeMethod(methid, inv);
	}
}

int CraftingSessionAdapter::initializeSession(CraftingTool* tool, CraftingStation* station) {
	return (static_cast<CraftingSession*>(stub))->initializeSession(tool, station);
}

int CraftingSessionAdapter::cancelSession() {
	return (static_cast<CraftingSession*>(stub))->cancelSession();
}

int CraftingSessionAdapter::clearSession() {
	return (static_cast<CraftingSession*>(stub))->clearSession();
}

ManagedWeakReference<ManufactureSchematic* > CraftingSessionAdapter::getSchematic() {
	return (static_cast<CraftingSession*>(stub))->getSchematic();
}

void CraftingSessionAdapter::selectDraftSchematic(int index) {
	(static_cast<CraftingSession*>(stub))->selectDraftSchematic(index);
}

void CraftingSessionAdapter::sendIngredientForUIListen() {
	(static_cast<CraftingSession*>(stub))->sendIngredientForUIListen();
}

void CraftingSessionAdapter::addIngredient(TangibleObject* tano, int slotUpdated, int clientCounter) {
	(static_cast<CraftingSession*>(stub))->addIngredient(tano, slotUpdated, clientCounter);
}

void CraftingSessionAdapter::removeIngredient(TangibleObject* tano, int slotUpdated, int clientCounter) {
	(static_cast<CraftingSession*>(stub))->removeIngredient(tano, slotUpdated, clientCounter);
}

void CraftingSessionAdapter::nextCraftingStage(int clientCounter) {
	(static_cast<CraftingSession*>(stub))->nextCraftingStage(clientCounter);
}

void CraftingSessionAdapter::experiment(int rowsAttempted, const String& expAttempt, int clientCounter) {
	(static_cast<CraftingSession*>(stub))->experiment(rowsAttempted, expAttempt, clientCounter);
}

void CraftingSessionAdapter::customization(const String& name, byte templateChoice, int schematicCount, const String& customizationString) {
	(static_cast<CraftingSession*>(stub))->customization(name, templateChoice, schematicCount, customizationString);
}

void CraftingSessionAdapter::createPrototype(int clientCounter, bool practice) {
	(static_cast<CraftingSession*>(stub))->createPrototype(clientCounter, practice);
}

void CraftingSessionAdapter::createManufactureSchematic(int clientCounter) {
	(static_cast<CraftingSession*>(stub))->createManufactureSchematic(clientCounter);
}

int CraftingSessionAdapter::getState() {
	return (static_cast<CraftingSession*>(stub))->getState();
}

/*
 *	CraftingSessionHelper
 */

CraftingSessionHelper* CraftingSessionHelper::staticInitializer = CraftingSessionHelper::instance();

CraftingSessionHelper::CraftingSessionHelper() {
	className = "CraftingSession";

	Core::getObjectBroker()->registerClass(className, this);
}

void CraftingSessionHelper::finalizeHelper() {
	CraftingSessionHelper::finalize();
}

DistributedObject* CraftingSessionHelper::instantiateObject() {
	return new CraftingSession(DummyConstructorParameter::instance());
}

DistributedObjectServant* CraftingSessionHelper::instantiateServant() {
	return new CraftingSessionImplementation(DummyConstructorParameter::instance());
}

DistributedObjectPOD* CraftingSessionHelper::instantiatePOD() {
	return new CraftingSessionPOD();
}

DistributedObjectAdapter* CraftingSessionHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new CraftingSessionAdapter(static_cast<CraftingSession*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	CraftingSessionPOD
 */

CraftingSessionPOD::~CraftingSessionPOD() {
}

CraftingSessionPOD::CraftingSessionPOD(void) {
	_className = "CraftingSession";
}


void CraftingSessionPOD::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = CraftingSessionPOD::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int CraftingSessionPOD::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = FacadePOD::writeObjectMembers(stream);

	uint32 _nameHashCode;
	int _offset;
	uint32 _totalSize;

	return _count;
}

bool CraftingSessionPOD::readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode) {
	if (FacadePOD::readObjectMember(stream, nameHashCode))
		return true;

	switch(nameHashCode) {
	}

	return false;
}

void CraftingSessionPOD::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		uint32 _nameHashCode;
		TypeInfo<uint32>::parseFromBinaryStream(&_nameHashCode, stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(CraftingSessionPOD::readObjectMember(stream, _nameHashCode)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

}

void CraftingSessionPOD::writeObjectCompact(ObjectOutputStream* stream) {
	FacadePOD::writeObjectCompact(stream);


}

