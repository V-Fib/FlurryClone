/*
 *	autogen/server/zone/objects/tangible/components/droid/DroidPersonalityObserver.cpp generated by engine3 IDL compiler 0.70
 */

#include "DroidPersonalityObserver.h"

#include "server/zone/objects/tangible/components/droid/DroidPersonalityModuleDataComponent.h"

/*
 *	DroidPersonalityObserverStub
 */

enum {RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_ = 2585724761};

DroidPersonalityObserver::DroidPersonalityObserver(DroidPersonalityModuleDataComponent* m) : Observer(DummyConstructorParameter::instance()) {
	DroidPersonalityObserverImplementation* _implementation = new DroidPersonalityObserverImplementation(m);
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("DroidPersonalityObserver");
}

DroidPersonalityObserver::DroidPersonalityObserver(DummyConstructorParameter* param) : Observer(param) {
	_setClassName("DroidPersonalityObserver");
}

DroidPersonalityObserver::~DroidPersonalityObserver() {
}



int DroidPersonalityObserver::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	DroidPersonalityObserverImplementation* _implementation = static_cast<DroidPersonalityObserverImplementation*>(_getImplementationForRead());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_);
		method.addUnsignedIntParameter(eventType);
		method.addObjectParameter(observable);
		method.addObjectParameter(arg1);
		method.addSignedLongParameter(arg2);

		return method.executeWithSignedIntReturn();
	} else {
		return _implementation->notifyObserverEvent(eventType, observable, arg1, arg2);
	}
}

DistributedObjectServant* DroidPersonalityObserver::_getImplementation() {

	 if (!_updated) _updated = true;
	return _impl;
}

DistributedObjectServant* DroidPersonalityObserver::_getImplementationForRead() const {
	return _impl;
}

void DroidPersonalityObserver::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	DroidPersonalityObserverImplementation
 */

DroidPersonalityObserverImplementation::DroidPersonalityObserverImplementation(DummyConstructorParameter* param) : ObserverImplementation(param) {
	_initializeImplementation();
}


DroidPersonalityObserverImplementation::~DroidPersonalityObserverImplementation() {
}


void DroidPersonalityObserverImplementation::finalize() {
}

void DroidPersonalityObserverImplementation::_initializeImplementation() {
	_setClassHelper(DroidPersonalityObserverHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void DroidPersonalityObserverImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<DroidPersonalityObserver*>(stub);
	ObserverImplementation::_setStub(stub);
}

DistributedObjectStub* DroidPersonalityObserverImplementation::_getStub() {
	return _this.get();
}

DroidPersonalityObserverImplementation::operator const DroidPersonalityObserver*() {
	return _this.get();
}

void DroidPersonalityObserverImplementation::lock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->lock(doLock);
}

void DroidPersonalityObserverImplementation::lock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->lock(obj);
}

void DroidPersonalityObserverImplementation::rlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->rlock(doLock);
}

void DroidPersonalityObserverImplementation::wlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->wlock(doLock);
}

void DroidPersonalityObserverImplementation::wlock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->wlock(obj);
}

void DroidPersonalityObserverImplementation::unlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->unlock(doLock);
}

void DroidPersonalityObserverImplementation::runlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->runlock(doLock);
}

void DroidPersonalityObserverImplementation::_serializationHelperMethod() {
	ObserverImplementation::_serializationHelperMethod();

	_setClassName("DroidPersonalityObserver");

}

void DroidPersonalityObserverImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		uint32 _nameHashCode;
		TypeInfo<uint32>::parseFromBinaryStream(&_nameHashCode, stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(DroidPersonalityObserverImplementation::readObjectMember(stream, _nameHashCode)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool DroidPersonalityObserverImplementation::readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode) {
	if (ObserverImplementation::readObjectMember(stream, nameHashCode))
		return true;

	switch(nameHashCode) {
	case 0x3f19f8db: //DroidPersonalityObserver.module
		TypeInfo<WeakReference<DroidPersonalityModuleDataComponent* > >::parseFromBinaryStream(&module, stream);
		return true;

	}

	return false;
}

void DroidPersonalityObserverImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = DroidPersonalityObserverImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int DroidPersonalityObserverImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ObserverImplementation::writeObjectMembers(stream);

	uint32 _nameHashCode;
	int _offset;
	uint32 _totalSize;
	_nameHashCode = 0x3f19f8db; //DroidPersonalityObserver.module
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<WeakReference<DroidPersonalityModuleDataComponent* > >::toBinaryStream(&module, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);
	_count++;


	return _count;
}

DroidPersonalityObserverImplementation::DroidPersonalityObserverImplementation(DroidPersonalityModuleDataComponent* m) {
	_initializeImplementation();
	// server/zone/objects/tangible/components/droid/DroidPersonalityObserver.idl():  		module = m;
	module = m;
}

/*
 *	DroidPersonalityObserverAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


DroidPersonalityObserverAdapter::DroidPersonalityObserverAdapter(DroidPersonalityObserver* obj) : ObserverAdapter(obj) {
}

void DroidPersonalityObserverAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_:
		{
			unsigned int eventType = inv->getUnsignedIntParameter();
			Observable* observable = static_cast<Observable*>(inv->getObjectParameter());
			ManagedObject* arg1 = static_cast<ManagedObject*>(inv->getObjectParameter());
			long long arg2 = inv->getSignedLongParameter();
			
			int _m_res = notifyObserverEvent(eventType, observable, arg1, arg2);
			resp->insertSignedInt(_m_res);
		}
		break;
	default:
		ObserverAdapter::invokeMethod(methid, inv);
	}
}

int DroidPersonalityObserverAdapter::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	return (static_cast<DroidPersonalityObserver*>(stub))->notifyObserverEvent(eventType, observable, arg1, arg2);
}

/*
 *	DroidPersonalityObserverHelper
 */

DroidPersonalityObserverHelper* DroidPersonalityObserverHelper::staticInitializer = DroidPersonalityObserverHelper::instance();

DroidPersonalityObserverHelper::DroidPersonalityObserverHelper() {
	className = "DroidPersonalityObserver";

	Core::getObjectBroker()->registerClass(className, this);
}

void DroidPersonalityObserverHelper::finalizeHelper() {
	DroidPersonalityObserverHelper::finalize();
}

DistributedObject* DroidPersonalityObserverHelper::instantiateObject() {
	return new DroidPersonalityObserver(DummyConstructorParameter::instance());
}

DistributedObjectServant* DroidPersonalityObserverHelper::instantiateServant() {
	return new DroidPersonalityObserverImplementation(DummyConstructorParameter::instance());
}

DistributedObjectPOD* DroidPersonalityObserverHelper::instantiatePOD() {
	return new DroidPersonalityObserverPOD();
}

DistributedObjectAdapter* DroidPersonalityObserverHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new DroidPersonalityObserverAdapter(static_cast<DroidPersonalityObserver*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	DroidPersonalityObserverPOD
 */

DroidPersonalityObserverPOD::~DroidPersonalityObserverPOD() {
}

DroidPersonalityObserverPOD::DroidPersonalityObserverPOD(void) {
	_className = "DroidPersonalityObserver";
}


void DroidPersonalityObserverPOD::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = DroidPersonalityObserverPOD::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int DroidPersonalityObserverPOD::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ObserverPOD::writeObjectMembers(stream);

	uint32 _nameHashCode;
	int _offset;
	uint32 _totalSize;
	if (module) {
	_nameHashCode = 0x3f19f8db; //DroidPersonalityObserver.module
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<WeakReference<DroidPersonalityModuleDataComponent* > >::toBinaryStream(&module.value(), stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);
	_count++;
	}


	return _count;
}

bool DroidPersonalityObserverPOD::readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode) {
	if (ObserverPOD::readObjectMember(stream, nameHashCode))
		return true;

	switch(nameHashCode) {
	case 0x3f19f8db: //DroidPersonalityObserver.module
		{
			WeakReference<DroidPersonalityModuleDataComponent* > _mnmodule;
			TypeInfo<WeakReference<DroidPersonalityModuleDataComponent* > >::parseFromBinaryStream(&_mnmodule, stream);
			module = std::move(_mnmodule);
		}
		return true;

	}

	return false;
}

void DroidPersonalityObserverPOD::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		uint32 _nameHashCode;
		TypeInfo<uint32>::parseFromBinaryStream(&_nameHashCode, stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(DroidPersonalityObserverPOD::readObjectMember(stream, _nameHashCode)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

}

void DroidPersonalityObserverPOD::writeObjectCompact(ObjectOutputStream* stream) {
	ObserverPOD::writeObjectCompact(stream);

	TypeInfo<WeakReference<DroidPersonalityModuleDataComponent* > >::toBinaryStream(&module.value(), stream);


}

