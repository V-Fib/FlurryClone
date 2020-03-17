/*
 *	autogen/server/zone/objects/tangible/terminal/startinglocation/StartingLocationTerminal.cpp generated by engine3 IDL compiler 0.70
 */

#include "StartingLocationTerminal.h"

#include "server/zone/objects/creature/CreatureObject.h"

/*
 *	StartingLocationTerminalStub
 */

enum {RPC_INITIALIZETRANSIENTMEMBERS__ = 712503614,RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_,RPC_SETAUTHORIZATIONSTATE__BOOL_};

StartingLocationTerminal::StartingLocationTerminal() : Terminal(DummyConstructorParameter::instance()) {
	StartingLocationTerminalImplementation* _implementation = new StartingLocationTerminalImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("StartingLocationTerminal");
}

StartingLocationTerminal::StartingLocationTerminal(DummyConstructorParameter* param) : Terminal(param) {
	_setClassName("StartingLocationTerminal");
}

StartingLocationTerminal::~StartingLocationTerminal() {
}



void StartingLocationTerminal::initializeTransientMembers() {
	StartingLocationTerminalImplementation* _implementation = static_cast<StartingLocationTerminalImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZETRANSIENTMEMBERS__);

		method.executeWithVoidReturn();
	} else {
		_implementation->initializeTransientMembers();
	}
}

int StartingLocationTerminal::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	StartingLocationTerminalImplementation* _implementation = static_cast<StartingLocationTerminalImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_);
		method.addObjectParameter(player);
		method.addByteParameter(selectedID);

		return method.executeWithSignedIntReturn();
	} else {
		return _implementation->handleObjectMenuSelect(player, selectedID);
	}
}

void StartingLocationTerminal::setAuthorizationState(bool state) {
	StartingLocationTerminalImplementation* _implementation = static_cast<StartingLocationTerminalImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETAUTHORIZATIONSTATE__BOOL_);
		method.addBooleanParameter(state);

		method.executeWithVoidReturn();
	} else {
		_implementation->setAuthorizationState(state);
	}
}

DistributedObjectServant* StartingLocationTerminal::_getImplementation() {

	 if (!_updated) _updated = true;
	return _impl;
}

DistributedObjectServant* StartingLocationTerminal::_getImplementationForRead() const {
	return _impl;
}

void StartingLocationTerminal::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	StartingLocationTerminalImplementation
 */

StartingLocationTerminalImplementation::StartingLocationTerminalImplementation(DummyConstructorParameter* param) : TerminalImplementation(param) {
	_initializeImplementation();
}


StartingLocationTerminalImplementation::~StartingLocationTerminalImplementation() {
}


void StartingLocationTerminalImplementation::finalize() {
}

void StartingLocationTerminalImplementation::_initializeImplementation() {
	_setClassHelper(StartingLocationTerminalHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void StartingLocationTerminalImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<StartingLocationTerminal*>(stub);
	TerminalImplementation::_setStub(stub);
}

DistributedObjectStub* StartingLocationTerminalImplementation::_getStub() {
	return _this.get();
}

StartingLocationTerminalImplementation::operator const StartingLocationTerminal*() {
	return _this.get();
}

void StartingLocationTerminalImplementation::lock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->lock(doLock);
}

void StartingLocationTerminalImplementation::lock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->lock(obj);
}

void StartingLocationTerminalImplementation::rlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->rlock(doLock);
}

void StartingLocationTerminalImplementation::wlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->wlock(doLock);
}

void StartingLocationTerminalImplementation::wlock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->wlock(obj);
}

void StartingLocationTerminalImplementation::unlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->unlock(doLock);
}

void StartingLocationTerminalImplementation::runlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->runlock(doLock);
}

void StartingLocationTerminalImplementation::_serializationHelperMethod() {
	TerminalImplementation::_serializationHelperMethod();

	_setClassName("StartingLocationTerminal");

}

void StartingLocationTerminalImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		uint32 _nameHashCode;
		TypeInfo<uint32>::parseFromBinaryStream(&_nameHashCode, stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(StartingLocationTerminalImplementation::readObjectMember(stream, _nameHashCode)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool StartingLocationTerminalImplementation::readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode) {
	if (TerminalImplementation::readObjectMember(stream, nameHashCode))
		return true;

	switch(nameHashCode) {
	case 0x5e87bdca: //StartingLocationTerminal.authorizationState
		TypeInfo<bool >::parseFromBinaryStream(&authorizationState, stream);
		return true;

	}

	return false;
}

void StartingLocationTerminalImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = StartingLocationTerminalImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int StartingLocationTerminalImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = TerminalImplementation::writeObjectMembers(stream);

	uint32 _nameHashCode;
	int _offset;
	uint32 _totalSize;
	_nameHashCode = 0x5e87bdca; //StartingLocationTerminal.authorizationState
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<bool >::toBinaryStream(&authorizationState, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);
	_count++;


	return _count;
}

void StartingLocationTerminalImplementation::writeJSON(nlohmann::json& j) {
	TerminalImplementation::writeJSON(j);

	nlohmann::json thisObject = nlohmann::json::object();
	thisObject["authorizationState"] = authorizationState;

	j["StartingLocationTerminal"] = thisObject;
}

StartingLocationTerminalImplementation::StartingLocationTerminalImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/terminal/startinglocation/StartingLocationTerminal.idl():  		Logger.setLoggingName("StartingLocationTerminal");
	Logger::setLoggingName("StartingLocationTerminal");
	// server/zone/objects/tangible/terminal/startinglocation/StartingLocationTerminal.idl():  		authorizationState = true;
	authorizationState = true;
}

void StartingLocationTerminalImplementation::setAuthorizationState(bool state) {
	// server/zone/objects/tangible/terminal/startinglocation/StartingLocationTerminal.idl():  		authorizationState = state;
	authorizationState = state;
}

/*
 *	StartingLocationTerminalAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


StartingLocationTerminalAdapter::StartingLocationTerminalAdapter(StartingLocationTerminal* obj) : TerminalAdapter(obj) {
}

void StartingLocationTerminalAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_INITIALIZETRANSIENTMEMBERS__:
		{
			
			initializeTransientMembers();
			
		}
		break;
	case RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_:
		{
			CreatureObject* player = static_cast<CreatureObject*>(inv->getObjectParameter());
			byte selectedID = inv->getByteParameter();
			
			int _m_res = handleObjectMenuSelect(player, selectedID);
			resp->insertSignedInt(_m_res);
		}
		break;
	case RPC_SETAUTHORIZATIONSTATE__BOOL_:
		{
			bool state = inv->getBooleanParameter();
			
			setAuthorizationState(state);
			
		}
		break;
	default:
		TerminalAdapter::invokeMethod(methid, inv);
	}
}

void StartingLocationTerminalAdapter::initializeTransientMembers() {
	(static_cast<StartingLocationTerminal*>(stub))->initializeTransientMembers();
}

int StartingLocationTerminalAdapter::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	return (static_cast<StartingLocationTerminal*>(stub))->handleObjectMenuSelect(player, selectedID);
}

void StartingLocationTerminalAdapter::setAuthorizationState(bool state) {
	(static_cast<StartingLocationTerminal*>(stub))->setAuthorizationState(state);
}

/*
 *	StartingLocationTerminalHelper
 */

StartingLocationTerminalHelper* StartingLocationTerminalHelper::staticInitializer = StartingLocationTerminalHelper::instance();

StartingLocationTerminalHelper::StartingLocationTerminalHelper() {
	className = "StartingLocationTerminal";

	Core::getObjectBroker()->registerClass(className, this);
}

void StartingLocationTerminalHelper::finalizeHelper() {
	StartingLocationTerminalHelper::finalize();
}

DistributedObject* StartingLocationTerminalHelper::instantiateObject() {
	return new StartingLocationTerminal(DummyConstructorParameter::instance());
}

DistributedObjectServant* StartingLocationTerminalHelper::instantiateServant() {
	return new StartingLocationTerminalImplementation();
}

DistributedObjectPOD* StartingLocationTerminalHelper::instantiatePOD() {
	return new StartingLocationTerminalPOD();
}

DistributedObjectAdapter* StartingLocationTerminalHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new StartingLocationTerminalAdapter(static_cast<StartingLocationTerminal*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	StartingLocationTerminalPOD
 */

StartingLocationTerminalPOD::~StartingLocationTerminalPOD() {
	finalize();
}

StartingLocationTerminalPOD::StartingLocationTerminalPOD(void) {
	_className = "StartingLocationTerminal";
}


void StartingLocationTerminalPOD::writeJSON(nlohmann::json& j) {
	TerminalPOD::writeJSON(j);

	nlohmann::json thisObject = nlohmann::json::object();
	if (authorizationState)
		thisObject["authorizationState"] = authorizationState.value();

	j["StartingLocationTerminal"] = thisObject;
}


void StartingLocationTerminalPOD::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = StartingLocationTerminalPOD::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int StartingLocationTerminalPOD::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = TerminalPOD::writeObjectMembers(stream);

	uint32 _nameHashCode;
	int _offset;
	uint32 _totalSize;
	if (authorizationState) {
	_nameHashCode = 0x5e87bdca; //StartingLocationTerminal.authorizationState
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<bool >::toBinaryStream(&authorizationState.value(), stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);
	_count++;
	}


	return _count;
}

bool StartingLocationTerminalPOD::readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode) {
	if (TerminalPOD::readObjectMember(stream, nameHashCode))
		return true;

	switch(nameHashCode) {
	case 0x5e87bdca: //StartingLocationTerminal.authorizationState
		{
			bool _mnauthorizationState;
			TypeInfo<bool >::parseFromBinaryStream(&_mnauthorizationState, stream);
			authorizationState = std::move(_mnauthorizationState);
		}
		return true;

	}

	return false;
}

void StartingLocationTerminalPOD::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		uint32 _nameHashCode;
		TypeInfo<uint32>::parseFromBinaryStream(&_nameHashCode, stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(StartingLocationTerminalPOD::readObjectMember(stream, _nameHashCode)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

}

void StartingLocationTerminalPOD::writeObjectCompact(ObjectOutputStream* stream) {
	TerminalPOD::writeObjectCompact(stream);

	TypeInfo<bool >::toBinaryStream(&authorizationState.value(), stream);


}

