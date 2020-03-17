/*
 *	autogen/server/zone/objects/area/CampSiteObserver.cpp generated by engine3 IDL compiler 0.70
 */

#include "CampSiteObserver.h"

/*
 *	CampSiteObserverStub
 */

enum {RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_ = 409021232};

CampSiteObserver::CampSiteObserver(CampSiteActiveArea* area) : Observer(DummyConstructorParameter::instance()) {
	CampSiteObserverImplementation* _implementation = new CampSiteObserverImplementation(area);
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("CampSiteObserver");
}

CampSiteObserver::CampSiteObserver(DummyConstructorParameter* param) : Observer(param) {
	_setClassName("CampSiteObserver");
}

CampSiteObserver::~CampSiteObserver() {
}



int CampSiteObserver::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	CampSiteObserverImplementation* _implementation = static_cast<CampSiteObserverImplementation*>(_getImplementationForRead());
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

DistributedObjectServant* CampSiteObserver::_getImplementation() {

	 if (!_updated) _updated = true;
	return _impl;
}

DistributedObjectServant* CampSiteObserver::_getImplementationForRead() const {
	return _impl;
}

void CampSiteObserver::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	CampSiteObserverImplementation
 */

CampSiteObserverImplementation::CampSiteObserverImplementation(DummyConstructorParameter* param) : ObserverImplementation(param) {
	_initializeImplementation();
}


CampSiteObserverImplementation::~CampSiteObserverImplementation() {
}


void CampSiteObserverImplementation::finalize() {
}

void CampSiteObserverImplementation::_initializeImplementation() {
	_setClassHelper(CampSiteObserverHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void CampSiteObserverImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<CampSiteObserver*>(stub);
	ObserverImplementation::_setStub(stub);
}

DistributedObjectStub* CampSiteObserverImplementation::_getStub() {
	return _this.get();
}

CampSiteObserverImplementation::operator const CampSiteObserver*() {
	return _this.get();
}

void CampSiteObserverImplementation::lock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->lock(doLock);
}

void CampSiteObserverImplementation::lock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->lock(obj);
}

void CampSiteObserverImplementation::rlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->rlock(doLock);
}

void CampSiteObserverImplementation::wlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->wlock(doLock);
}

void CampSiteObserverImplementation::wlock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->wlock(obj);
}

void CampSiteObserverImplementation::unlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->unlock(doLock);
}

void CampSiteObserverImplementation::runlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->runlock(doLock);
}

void CampSiteObserverImplementation::_serializationHelperMethod() {
	ObserverImplementation::_serializationHelperMethod();

	_setClassName("CampSiteObserver");

}

void CampSiteObserverImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		uint32 _nameHashCode;
		TypeInfo<uint32>::parseFromBinaryStream(&_nameHashCode, stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(CampSiteObserverImplementation::readObjectMember(stream, _nameHashCode)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool CampSiteObserverImplementation::readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode) {
	if (ObserverImplementation::readObjectMember(stream, nameHashCode))
		return true;

	switch(nameHashCode) {
	case 0xf88c5c20: //CampSiteObserver.campArea
		TypeInfo<ManagedWeakReference<CampSiteActiveArea* > >::parseFromBinaryStream(&campArea, stream);
		return true;

	}

	return false;
}

void CampSiteObserverImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = CampSiteObserverImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int CampSiteObserverImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ObserverImplementation::writeObjectMembers(stream);

	uint32 _nameHashCode;
	int _offset;
	uint32 _totalSize;
	_nameHashCode = 0xf88c5c20; //CampSiteObserver.campArea
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<ManagedWeakReference<CampSiteActiveArea* > >::toBinaryStream(&campArea, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);
	_count++;


	return _count;
}

CampSiteObserverImplementation::CampSiteObserverImplementation(CampSiteActiveArea* area) {
	_initializeImplementation();
	// server/zone/objects/area/CampSiteObserver.idl():  		campArea = area;
	campArea = area;
	// server/zone/objects/area/CampSiteObserver.idl():  		Logger.setLoggingName("CampSiteObserver");
	Logger::setLoggingName("CampSiteObserver");
}

int CampSiteObserverImplementation::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	// server/zone/objects/area/CampSiteObserver.idl():  		CampSiteActiveArea strongRef = campArea;
	ManagedReference<CampSiteActiveArea* > strongRef = campArea;
	// server/zone/objects/area/CampSiteObserver.idl():  		if(
	if (strongRef != NULL && eventType == ObserverEventType::HEALINGRECEIVED)	// server/zone/objects/area/CampSiteObserver.idl():  			return strongRef.notifyHealEvent(arg2);
	return strongRef->notifyHealEvent(arg2);
	// server/zone/objects/area/CampSiteObserver.idl():  		return 
	if (strongRef != NULL && eventType == ObserverEventType::STARTCOMBAT)	// server/zone/objects/area/CampSiteObserver.idl():  			return strongRef.notifyCombatEvent();
	return strongRef->notifyCombatEvent();
	// server/zone/objects/area/CampSiteObserver.idl():  		return 0;
	return 0;
}

/*
 *	CampSiteObserverAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


CampSiteObserverAdapter::CampSiteObserverAdapter(CampSiteObserver* obj) : ObserverAdapter(obj) {
}

void CampSiteObserverAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
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

int CampSiteObserverAdapter::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	return (static_cast<CampSiteObserver*>(stub))->notifyObserverEvent(eventType, observable, arg1, arg2);
}

/*
 *	CampSiteObserverHelper
 */

CampSiteObserverHelper* CampSiteObserverHelper::staticInitializer = CampSiteObserverHelper::instance();

CampSiteObserverHelper::CampSiteObserverHelper() {
	className = "CampSiteObserver";

	Core::getObjectBroker()->registerClass(className, this);
}

void CampSiteObserverHelper::finalizeHelper() {
	CampSiteObserverHelper::finalize();
}

DistributedObject* CampSiteObserverHelper::instantiateObject() {
	return new CampSiteObserver(DummyConstructorParameter::instance());
}

DistributedObjectServant* CampSiteObserverHelper::instantiateServant() {
	return new CampSiteObserverImplementation(DummyConstructorParameter::instance());
}

DistributedObjectPOD* CampSiteObserverHelper::instantiatePOD() {
	return new CampSiteObserverPOD();
}

DistributedObjectAdapter* CampSiteObserverHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new CampSiteObserverAdapter(static_cast<CampSiteObserver*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	CampSiteObserverPOD
 */

CampSiteObserverPOD::~CampSiteObserverPOD() {
}

CampSiteObserverPOD::CampSiteObserverPOD(void) {
	_className = "CampSiteObserver";
}


void CampSiteObserverPOD::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = CampSiteObserverPOD::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int CampSiteObserverPOD::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ObserverPOD::writeObjectMembers(stream);

	uint32 _nameHashCode;
	int _offset;
	uint32 _totalSize;
	if (campArea) {
	_nameHashCode = 0xf88c5c20; //CampSiteObserver.campArea
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<ManagedWeakReference<CampSiteActiveAreaPOD* > >::toBinaryStream(&campArea.value(), stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);
	_count++;
	}


	return _count;
}

bool CampSiteObserverPOD::readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode) {
	if (ObserverPOD::readObjectMember(stream, nameHashCode))
		return true;

	switch(nameHashCode) {
	case 0xf88c5c20: //CampSiteObserver.campArea
		{
			ManagedWeakReference<CampSiteActiveAreaPOD* > _mncampArea;
			TypeInfo<ManagedWeakReference<CampSiteActiveAreaPOD* > >::parseFromBinaryStream(&_mncampArea, stream);
			campArea = std::move(_mncampArea);
		}
		return true;

	}

	return false;
}

void CampSiteObserverPOD::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		uint32 _nameHashCode;
		TypeInfo<uint32>::parseFromBinaryStream(&_nameHashCode, stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(CampSiteObserverPOD::readObjectMember(stream, _nameHashCode)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

}

void CampSiteObserverPOD::writeObjectCompact(ObjectOutputStream* stream) {
	ObserverPOD::writeObjectCompact(stream);

	TypeInfo<ManagedWeakReference<CampSiteActiveAreaPOD* > >::toBinaryStream(&campArea.value(), stream);


}

