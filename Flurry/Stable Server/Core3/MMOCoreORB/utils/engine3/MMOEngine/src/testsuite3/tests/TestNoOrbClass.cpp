/*
 *	testsuite3/tests/TestNoOrbClass.cpp generated by engine3 IDL compiler 0.70
 */

#include "TestNoOrbClass.h"

/*
 *	TestNoOrbClassStub
 */

TestNoOrbClass::TestNoOrbClass(DummyConstructorParameter* param) : ManagedObject(param) {
	_setClassName("TestNoOrbClass");
}

TestNoOrbClass::~TestNoOrbClass() {
}



DistributedObjectServant* TestNoOrbClass::_getImplementation() {

	 if (!_updated) _updated = true;
	return _impl;
}

DistributedObjectServant* TestNoOrbClass::_getImplementationForRead() const {
	return _impl;
}

void TestNoOrbClass::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	TestNoOrbClassImplementation
 */

TestNoOrbClassImplementation::TestNoOrbClassImplementation() : ManagedObjectImplementation() {
	_initializeImplementation();
}

TestNoOrbClassImplementation::TestNoOrbClassImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}


TestNoOrbClassImplementation::~TestNoOrbClassImplementation() {
}


void TestNoOrbClassImplementation::finalize() {
}

void TestNoOrbClassImplementation::_initializeImplementation() {
	_setClassHelper(TestNoOrbClassHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void TestNoOrbClassImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<TestNoOrbClass*>(stub);
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* TestNoOrbClassImplementation::_getStub() {
	return _this.get();
}

TestNoOrbClassImplementation::operator const TestNoOrbClass*() {
	return _this.get();
}

void TestNoOrbClassImplementation::lock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->lock(doLock);
}

void TestNoOrbClassImplementation::lock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->lock(obj);
}

void TestNoOrbClassImplementation::rlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->rlock(doLock);
}

void TestNoOrbClassImplementation::wlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->wlock(doLock);
}

void TestNoOrbClassImplementation::wlock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->wlock(obj);
}

void TestNoOrbClassImplementation::unlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->unlock(doLock);
}

void TestNoOrbClassImplementation::runlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->runlock(doLock);
}

void TestNoOrbClassImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("TestNoOrbClass");

}

void TestNoOrbClassImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		uint32 _nameHashCode;
		TypeInfo<uint32>::parseFromBinaryStream(&_nameHashCode, stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(TestNoOrbClassImplementation::readObjectMember(stream, _nameHashCode)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool TestNoOrbClassImplementation::readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode) {
	if (ManagedObjectImplementation::readObjectMember(stream, nameHashCode))
		return true;

	switch(nameHashCode) {
	}

	return false;
}

void TestNoOrbClassImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = TestNoOrbClassImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int TestNoOrbClassImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ManagedObjectImplementation::writeObjectMembers(stream);

	uint32 _nameHashCode;
	int _offset;
	uint32 _totalSize;

	return _count;
}

/*
 *	TestNoOrbClassAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


TestNoOrbClassAdapter::TestNoOrbClassAdapter(TestNoOrbClass* obj) : ManagedObjectAdapter(obj) {
}

void TestNoOrbClassAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	default:
		ManagedObjectAdapter::invokeMethod(methid, inv);
	}
}

/*
 *	TestNoOrbClassHelper
 */

TestNoOrbClassHelper* TestNoOrbClassHelper::staticInitializer = TestNoOrbClassHelper::instance();

TestNoOrbClassHelper::TestNoOrbClassHelper() {
	className = "TestNoOrbClass";

	Core::getObjectBroker()->registerClass(className, this);
}

void TestNoOrbClassHelper::finalizeHelper() {
	TestNoOrbClassHelper::finalize();
}

DistributedObject* TestNoOrbClassHelper::instantiateObject() {
	return new TestNoOrbClass(DummyConstructorParameter::instance());
}

DistributedObjectServant* TestNoOrbClassHelper::instantiateServant() {
	return new TestNoOrbClassImplementation(DummyConstructorParameter::instance());
}

DistributedObjectPOD* TestNoOrbClassHelper::instantiatePOD() {
	return new TestNoOrbClassPOD();
}

DistributedObjectAdapter* TestNoOrbClassHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new TestNoOrbClassAdapter(static_cast<TestNoOrbClass*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	TestNoOrbClassPOD
 */

TestNoOrbClassPOD::~TestNoOrbClassPOD() {
}

TestNoOrbClassPOD::TestNoOrbClassPOD(void) {
	_className = "TestNoOrbClass";
}


void TestNoOrbClassPOD::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = TestNoOrbClassPOD::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int TestNoOrbClassPOD::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ManagedObjectPOD::writeObjectMembers(stream);

	uint32 _nameHashCode;
	int _offset;
	uint32 _totalSize;

	return _count;
}

bool TestNoOrbClassPOD::readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode) {
	if (ManagedObjectPOD::readObjectMember(stream, nameHashCode))
		return true;

	switch(nameHashCode) {
	}

	return false;
}

void TestNoOrbClassPOD::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		uint32 _nameHashCode;
		TypeInfo<uint32>::parseFromBinaryStream(&_nameHashCode, stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(TestNoOrbClassPOD::readObjectMember(stream, _nameHashCode)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

}

void TestNoOrbClassPOD::writeObjectCompact(ObjectOutputStream* stream) {
	ManagedObjectPOD::writeObjectCompact(stream);


}

