/*
 *	autogen/server/zone/objects/tangible/consumable/Drink.cpp generated by engine3 IDL compiler 0.70
 */

#include "Drink.h"

/*
 *	DrinkStub
 */

enum {RPC_INITIALIZETRANSIENTMEMBERS__ = 630441367,RPC_INITIALIZEPRIVATEDATA__};

Drink::Drink() : Consumable(DummyConstructorParameter::instance()) {
	DrinkImplementation* _implementation = new DrinkImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("Drink");
}

Drink::Drink(DummyConstructorParameter* param) : Consumable(param) {
	_setClassName("Drink");
}

Drink::~Drink() {
}



void Drink::initializeTransientMembers() {
	DrinkImplementation* _implementation = static_cast<DrinkImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZETRANSIENTMEMBERS__);

		method.executeWithVoidReturn();
	} else {
		_implementation->initializeTransientMembers();
	}
}

void Drink::initializePrivateData() {
	DrinkImplementation* _implementation = static_cast<DrinkImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZEPRIVATEDATA__);

		method.executeWithVoidReturn();
	} else {
		_implementation->initializePrivateData();
	}
}

DistributedObjectServant* Drink::_getImplementation() {

	 if (!_updated) _updated = true;
	return _impl;
}

DistributedObjectServant* Drink::_getImplementationForRead() const {
	return _impl;
}

void Drink::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	DrinkImplementation
 */

DrinkImplementation::DrinkImplementation(DummyConstructorParameter* param) : ConsumableImplementation(param) {
	_initializeImplementation();
}


DrinkImplementation::~DrinkImplementation() {
}


void DrinkImplementation::finalize() {
}

void DrinkImplementation::_initializeImplementation() {
	_setClassHelper(DrinkHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void DrinkImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<Drink*>(stub);
	ConsumableImplementation::_setStub(stub);
}

DistributedObjectStub* DrinkImplementation::_getStub() {
	return _this.get();
}

DrinkImplementation::operator const Drink*() {
	return _this.get();
}

void DrinkImplementation::lock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->lock(doLock);
}

void DrinkImplementation::lock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->lock(obj);
}

void DrinkImplementation::rlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->rlock(doLock);
}

void DrinkImplementation::wlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->wlock(doLock);
}

void DrinkImplementation::wlock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->wlock(obj);
}

void DrinkImplementation::unlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->unlock(doLock);
}

void DrinkImplementation::runlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->runlock(doLock);
}

void DrinkImplementation::_serializationHelperMethod() {
	ConsumableImplementation::_serializationHelperMethod();

	_setClassName("Drink");

}

void DrinkImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		uint32 _nameHashCode;
		TypeInfo<uint32>::parseFromBinaryStream(&_nameHashCode, stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(DrinkImplementation::readObjectMember(stream, _nameHashCode)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool DrinkImplementation::readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode) {
	if (ConsumableImplementation::readObjectMember(stream, nameHashCode))
		return true;

	switch(nameHashCode) {
	}

	return false;
}

void DrinkImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = DrinkImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int DrinkImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ConsumableImplementation::writeObjectMembers(stream);

	uint32 _nameHashCode;
	int _offset;
	uint32 _totalSize;

	return _count;
}

void DrinkImplementation::writeJSON(nlohmann::json& j) {
	ConsumableImplementation::writeJSON(j);

	nlohmann::json thisObject = nlohmann::json::object();
}

DrinkImplementation::DrinkImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/consumable/Drink.idl():  		Logger.setLoggingName("Drink");
	Logger::setLoggingName("Drink");
	// server/zone/objects/tangible/consumable/Drink.idl():  		initializePrivateData();
	initializePrivateData();
}

void DrinkImplementation::initializeTransientMembers() {
	// server/zone/objects/tangible/consumable/Drink.idl():  		super.initializeTransientMembers();
	ConsumableImplementation::initializeTransientMembers();
	// server/zone/objects/tangible/consumable/Drink.idl():  		Logger.setLoggingName("Drink");
	Logger::setLoggingName("Drink");
}

void DrinkImplementation::initializePrivateData() {
	// server/zone/objects/tangible/consumable/Drink.idl():  		super.consumableType = super.DRINK;
	ConsumableImplementation::consumableType = ConsumableImplementation::DRINK;
}

/*
 *	DrinkAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


DrinkAdapter::DrinkAdapter(Drink* obj) : ConsumableAdapter(obj) {
}

void DrinkAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_INITIALIZETRANSIENTMEMBERS__:
		{
			
			initializeTransientMembers();
			
		}
		break;
	case RPC_INITIALIZEPRIVATEDATA__:
		{
			
			initializePrivateData();
			
		}
		break;
	default:
		ConsumableAdapter::invokeMethod(methid, inv);
	}
}

void DrinkAdapter::initializeTransientMembers() {
	(static_cast<Drink*>(stub))->initializeTransientMembers();
}

void DrinkAdapter::initializePrivateData() {
	(static_cast<Drink*>(stub))->initializePrivateData();
}

/*
 *	DrinkHelper
 */

DrinkHelper* DrinkHelper::staticInitializer = DrinkHelper::instance();

DrinkHelper::DrinkHelper() {
	className = "Drink";

	Core::getObjectBroker()->registerClass(className, this);
}

void DrinkHelper::finalizeHelper() {
	DrinkHelper::finalize();
}

DistributedObject* DrinkHelper::instantiateObject() {
	return new Drink(DummyConstructorParameter::instance());
}

DistributedObjectServant* DrinkHelper::instantiateServant() {
	return new DrinkImplementation();
}

DistributedObjectPOD* DrinkHelper::instantiatePOD() {
	return new DrinkPOD();
}

DistributedObjectAdapter* DrinkHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new DrinkAdapter(static_cast<Drink*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	DrinkPOD
 */

DrinkPOD::~DrinkPOD() {
	finalize();
}

DrinkPOD::DrinkPOD(void) {
	_className = "Drink";
}


void DrinkPOD::writeJSON(nlohmann::json& j) {
	ConsumablePOD::writeJSON(j);

	nlohmann::json thisObject = nlohmann::json::object();
}


void DrinkPOD::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = DrinkPOD::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int DrinkPOD::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ConsumablePOD::writeObjectMembers(stream);

	uint32 _nameHashCode;
	int _offset;
	uint32 _totalSize;

	return _count;
}

bool DrinkPOD::readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode) {
	if (ConsumablePOD::readObjectMember(stream, nameHashCode))
		return true;

	switch(nameHashCode) {
	}

	return false;
}

void DrinkPOD::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		uint32 _nameHashCode;
		TypeInfo<uint32>::parseFromBinaryStream(&_nameHashCode, stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(DrinkPOD::readObjectMember(stream, _nameHashCode)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

}

void DrinkPOD::writeObjectCompact(ObjectOutputStream* stream) {
	ConsumablePOD::writeObjectCompact(stream);


}

