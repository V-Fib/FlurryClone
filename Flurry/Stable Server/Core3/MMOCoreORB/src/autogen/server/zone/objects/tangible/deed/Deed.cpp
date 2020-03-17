/*
 *	autogen/server/zone/objects/tangible/deed/Deed.cpp generated by engine3 IDL compiler 0.70
 */

#include "Deed.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/objects/creature/CreatureObject.h"

/*
 *	DeedStub
 */

enum {RPC_INITIALIZETRANSIENTMEMBERS__ = 2548063035,RPC_SETGENERATEDOBJECTTEMPLATE__STRING_,RPC_GETGENERATEDOBJECTTEMPLATE__,RPC_SETGENERATED__BOOL_,RPC_ISDEEDOBJECT__,RPC_ISGENERATED__};

Deed::Deed() : TangibleObject(DummyConstructorParameter::instance()) {
	DeedImplementation* _implementation = new DeedImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("Deed");
}

Deed::Deed(DummyConstructorParameter* param) : TangibleObject(param) {
	_setClassName("Deed");
}

Deed::~Deed() {
}



void Deed::initializeTransientMembers() {
	DeedImplementation* _implementation = static_cast<DeedImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZETRANSIENTMEMBERS__);

		method.executeWithVoidReturn();
	} else {
		_implementation->initializeTransientMembers();
	}
}

void Deed::loadTemplateData(SharedObjectTemplate* templateData) {
	DeedImplementation* _implementation = static_cast<DeedImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		throw ObjectNotLocalException(this);

	} else {
		_implementation->loadTemplateData(templateData);
	}
}

void Deed::fillAttributeList(AttributeListMessage* alm, CreatureObject* object) {
	DeedImplementation* _implementation = static_cast<DeedImplementation*>(_getImplementationForRead());
	if (unlikely(_implementation == NULL)) {
		throw ObjectNotLocalException(this);

	} else {
		_implementation->fillAttributeList(alm, object);
	}
}

void Deed::updateCraftingValues(CraftingValues* values, bool firstUpdate) {
	DeedImplementation* _implementation = static_cast<DeedImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		throw ObjectNotLocalException(this);

	} else {
		_implementation->updateCraftingValues(values, firstUpdate);
	}
}

void Deed::setGeneratedObjectTemplate(const String& templ) {
	DeedImplementation* _implementation = static_cast<DeedImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETGENERATEDOBJECTTEMPLATE__STRING_);
		method.addAsciiParameter(templ);

		method.executeWithVoidReturn();
	} else {
		_implementation->setGeneratedObjectTemplate(templ);
	}
}

String Deed::getGeneratedObjectTemplate() {
	DeedImplementation* _implementation = static_cast<DeedImplementation*>(_getImplementationForRead());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETGENERATEDOBJECTTEMPLATE__);

		String _return_getGeneratedObjectTemplate;
		method.executeWithAsciiReturn(_return_getGeneratedObjectTemplate);
		return _return_getGeneratedObjectTemplate;
	} else {
		return _implementation->getGeneratedObjectTemplate();
	}
}

void Deed::setGenerated(bool gen) {
	DeedImplementation* _implementation = static_cast<DeedImplementation*>(_getImplementation());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETGENERATED__BOOL_);
		method.addBooleanParameter(gen);

		method.executeWithVoidReturn();
	} else {
		_implementation->setGenerated(gen);
	}
}

bool Deed::isDeedObject() {
	DeedImplementation* _implementation = static_cast<DeedImplementation*>(_getImplementationForRead());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISDEEDOBJECT__);

		return method.executeWithBooleanReturn();
	} else {
		return _implementation->isDeedObject();
	}
}

bool Deed::isGenerated() {
	DeedImplementation* _implementation = static_cast<DeedImplementation*>(_getImplementationForRead());
	if (unlikely(_implementation == NULL)) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISGENERATED__);

		return method.executeWithBooleanReturn();
	} else {
		return _implementation->isGenerated();
	}
}

DistributedObjectServant* Deed::_getImplementation() {

	 if (!_updated) _updated = true;
	return _impl;
}

DistributedObjectServant* Deed::_getImplementationForRead() const {
	return _impl;
}

void Deed::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	DeedImplementation
 */

DeedImplementation::DeedImplementation(DummyConstructorParameter* param) : TangibleObjectImplementation(param) {
	_initializeImplementation();
}


DeedImplementation::~DeedImplementation() {
}


void DeedImplementation::finalize() {
}

void DeedImplementation::_initializeImplementation() {
	_setClassHelper(DeedHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void DeedImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<Deed*>(stub);
	TangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* DeedImplementation::_getStub() {
	return _this.get();
}

DeedImplementation::operator const Deed*() {
	return _this.get();
}

void DeedImplementation::lock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->lock(doLock);
}

void DeedImplementation::lock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->lock(obj);
}

void DeedImplementation::rlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->rlock(doLock);
}

void DeedImplementation::wlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->wlock(doLock);
}

void DeedImplementation::wlock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->wlock(obj);
}

void DeedImplementation::unlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->unlock(doLock);
}

void DeedImplementation::runlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->runlock(doLock);
}

void DeedImplementation::_serializationHelperMethod() {
	TangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("Deed");

}

void DeedImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		uint32 _nameHashCode;
		TypeInfo<uint32>::parseFromBinaryStream(&_nameHashCode, stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(DeedImplementation::readObjectMember(stream, _nameHashCode)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool DeedImplementation::readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode) {
	if (TangibleObjectImplementation::readObjectMember(stream, nameHashCode))
		return true;

	switch(nameHashCode) {
	case 0x31849f3a: //Deed.generatedObjectTemplate
		TypeInfo<String >::parseFromBinaryStream(&generatedObjectTemplate, stream);
		return true;

	case 0x3c7f8158: //Deed.generated
		TypeInfo<bool >::parseFromBinaryStream(&generated, stream);
		return true;

	}

	return false;
}

void DeedImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = DeedImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int DeedImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = TangibleObjectImplementation::writeObjectMembers(stream);

	uint32 _nameHashCode;
	int _offset;
	uint32 _totalSize;
	_nameHashCode = 0x31849f3a; //Deed.generatedObjectTemplate
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<String >::toBinaryStream(&generatedObjectTemplate, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);
	_count++;

	_nameHashCode = 0x3c7f8158; //Deed.generated
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<bool >::toBinaryStream(&generated, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);
	_count++;


	return _count;
}

void DeedImplementation::writeJSON(nlohmann::json& j) {
	TangibleObjectImplementation::writeJSON(j);

	nlohmann::json thisObject = nlohmann::json::object();
	thisObject["generatedObjectTemplate"] = generatedObjectTemplate;

	thisObject["generated"] = generated;

	j["Deed"] = thisObject;
}

DeedImplementation::DeedImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/deed/Deed.idl():  		Logger.setLoggingName("Deed");
	Logger::setLoggingName("Deed");
	// server/zone/objects/tangible/deed/Deed.idl():  		generated = false;
	generated = false;
}

void DeedImplementation::updateCraftingValues(CraftingValues* values, bool firstUpdate) {
	// server/zone/objects/tangible/deed/Deed.idl():  		error("Unhandled updateCraftingValues for this object type");
	error("Unhandled updateCraftingValues for this object type");
}

void DeedImplementation::setGeneratedObjectTemplate(const String& templ) {
	// server/zone/objects/tangible/deed/Deed.idl():  		generatedObjectTemplate = templ;
	generatedObjectTemplate = templ;
}

String DeedImplementation::getGeneratedObjectTemplate() {
	// server/zone/objects/tangible/deed/Deed.idl():  		return generatedObjectTemplate;
	return generatedObjectTemplate;
}

void DeedImplementation::setGenerated(bool gen) {
	// server/zone/objects/tangible/deed/Deed.idl():  		generated = gen;
	generated = gen;
}

bool DeedImplementation::isDeedObject() {
	// server/zone/objects/tangible/deed/Deed.idl():  		return true;
	return true;
}

bool DeedImplementation::isGenerated() {
	// server/zone/objects/tangible/deed/Deed.idl():  		return generated;
	return generated;
}

/*
 *	DeedAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


DeedAdapter::DeedAdapter(Deed* obj) : TangibleObjectAdapter(obj) {
}

void DeedAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_INITIALIZETRANSIENTMEMBERS__:
		{
			
			initializeTransientMembers();
			
		}
		break;
	case RPC_SETGENERATEDOBJECTTEMPLATE__STRING_:
		{
			 String templ; inv->getAsciiParameter(templ);
			
			setGeneratedObjectTemplate(templ);
			
		}
		break;
	case RPC_GETGENERATEDOBJECTTEMPLATE__:
		{
			
			String _m_res = getGeneratedObjectTemplate();
			resp->insertAscii(_m_res);
		}
		break;
	case RPC_SETGENERATED__BOOL_:
		{
			bool gen = inv->getBooleanParameter();
			
			setGenerated(gen);
			
		}
		break;
	case RPC_ISDEEDOBJECT__:
		{
			
			bool _m_res = isDeedObject();
			resp->insertBoolean(_m_res);
		}
		break;
	case RPC_ISGENERATED__:
		{
			
			bool _m_res = isGenerated();
			resp->insertBoolean(_m_res);
		}
		break;
	default:
		TangibleObjectAdapter::invokeMethod(methid, inv);
	}
}

void DeedAdapter::initializeTransientMembers() {
	(static_cast<Deed*>(stub))->initializeTransientMembers();
}

void DeedAdapter::setGeneratedObjectTemplate(const String& templ) {
	(static_cast<Deed*>(stub))->setGeneratedObjectTemplate(templ);
}

String DeedAdapter::getGeneratedObjectTemplate() {
	return (static_cast<Deed*>(stub))->getGeneratedObjectTemplate();
}

void DeedAdapter::setGenerated(bool gen) {
	(static_cast<Deed*>(stub))->setGenerated(gen);
}

bool DeedAdapter::isDeedObject() {
	return (static_cast<Deed*>(stub))->isDeedObject();
}

bool DeedAdapter::isGenerated() {
	return (static_cast<Deed*>(stub))->isGenerated();
}

/*
 *	DeedHelper
 */

DeedHelper* DeedHelper::staticInitializer = DeedHelper::instance();

DeedHelper::DeedHelper() {
	className = "Deed";

	Core::getObjectBroker()->registerClass(className, this);
}

void DeedHelper::finalizeHelper() {
	DeedHelper::finalize();
}

DistributedObject* DeedHelper::instantiateObject() {
	return new Deed(DummyConstructorParameter::instance());
}

DistributedObjectServant* DeedHelper::instantiateServant() {
	return new DeedImplementation();
}

DistributedObjectPOD* DeedHelper::instantiatePOD() {
	return new DeedPOD();
}

DistributedObjectAdapter* DeedHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new DeedAdapter(static_cast<Deed*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

const char LuaDeed::className[] = "LuaDeed";

Luna<LuaDeed>::RegType LuaDeed::Register[] = {
	{ "_setObject", &LuaDeed::_setObject },
	{ "_getObject", &LuaDeed::_getObject },
	{ "initializeTransientMembers", &LuaDeed::initializeTransientMembers },
	{ "loadTemplateData", &LuaDeed::loadTemplateData },
	{ "fillAttributeList", &LuaDeed::fillAttributeList },
	{ "updateCraftingValues", &LuaDeed::updateCraftingValues },
	{ "setGeneratedObjectTemplate", &LuaDeed::setGeneratedObjectTemplate },
	{ "getGeneratedObjectTemplate", &LuaDeed::getGeneratedObjectTemplate },
	{ "setGenerated", &LuaDeed::setGenerated },
	{ "isDeedObject", &LuaDeed::isDeedObject },
	{ "isGenerated", &LuaDeed::isGenerated },
	{ 0, 0 }
};

LuaDeed::LuaDeed(lua_State *L) {
	realObject = static_cast<Deed*>(lua_touserdata(L, 1));
}

LuaDeed::~LuaDeed() {
}

int LuaDeed::_setObject(lua_State* L) {
	realObject = static_cast<Deed*>(lua_touserdata(L, -1));

	return 0;
}

int LuaDeed::_getObject(lua_State* L) {
	lua_pushlightuserdata(L, realObject.get());

	return 1;
}

int LuaDeed::initializeTransientMembers(lua_State *L) {
	int parameterCount = lua_gettop(L) - 1;
	
	if (parameterCount == 0) {
		realObject->initializeTransientMembers();

		return 0;
	} else {
		throw LuaCallbackException(L, "invalid argument count " + String::valueOf(parameterCount) + " for lua method 'Deed:initializeTransientMembers()'");
	}
	return 0;
}

int LuaDeed::loadTemplateData(lua_State *L) {
	int parameterCount = lua_gettop(L) - 1;
	
	if (lua_isuserdata(L, -1)) {
		if (parameterCount == 1) {
			SharedObjectTemplate* templateData = static_cast<SharedObjectTemplate*>(lua_touserdata(L, -1));

			realObject->loadTemplateData(templateData);

			return 0;
		} else {
			throw LuaCallbackException(L, "invalid argument count " + String::valueOf(parameterCount) + " for lua method 'Deed:loadTemplateData(userdata)'");
		}
	} else {
		throw LuaCallbackException(L, "invalid argument at 0 for lua method 'Deed:loadTemplateData(userdata)'");
	}
	return 0;
}

int LuaDeed::fillAttributeList(lua_State *L) {
	int parameterCount = lua_gettop(L) - 1;
	
	if (lua_isuserdata(L, -1)) {
		if (lua_isuserdata(L, -2)) {
			if (parameterCount == 2) {
				AttributeListMessage* alm = static_cast<AttributeListMessage*>(lua_touserdata(L, -2));
				CreatureObject* object = static_cast<CreatureObject*>(lua_touserdata(L, -1));

				realObject->fillAttributeList(alm, object);

				return 0;
			} else {
				throw LuaCallbackException(L, "invalid argument count " + String::valueOf(parameterCount) + " for lua method 'Deed:fillAttributeList(userdata, userdata)'");
			}
		} else {
			throw LuaCallbackException(L, "invalid argument at 1 for lua method 'Deed:fillAttributeList(userdata, userdata)'");
		}
	} else {
		throw LuaCallbackException(L, "invalid argument at 0 for lua method 'Deed:fillAttributeList(userdata, userdata)'");
	}
	return 0;
}

int LuaDeed::updateCraftingValues(lua_State *L) {
	int parameterCount = lua_gettop(L) - 1;
	
	if (lua_isboolean(L, -1)) {
		if (lua_isuserdata(L, -2)) {
			if (parameterCount == 2) {
				CraftingValues* values = static_cast<CraftingValues*>(lua_touserdata(L, -2));
				bool firstUpdate = lua_toboolean(L, -1);

				realObject->updateCraftingValues(values, firstUpdate);

				return 0;
			} else {
				throw LuaCallbackException(L, "invalid argument count " + String::valueOf(parameterCount) + " for lua method 'Deed:updateCraftingValues(userdata, boolean)'");
			}
		} else {
			throw LuaCallbackException(L, "invalid argument at 1 for lua method 'Deed:updateCraftingValues(userdata, boolean)'");
		}
	} else {
		throw LuaCallbackException(L, "invalid argument at 0 for lua method 'Deed:updateCraftingValues(userdata, boolean)'");
	}
	return 0;
}

int LuaDeed::setGeneratedObjectTemplate(lua_State *L) {
	int parameterCount = lua_gettop(L) - 1;
	
	if (lua_isstring(L, -1)) {
		if (parameterCount == 1) {
			const String templ = lua_tostring(L, -1);

			realObject->setGeneratedObjectTemplate(templ);

			return 0;
		} else {
			throw LuaCallbackException(L, "invalid argument count " + String::valueOf(parameterCount) + " for lua method 'Deed:setGeneratedObjectTemplate(string)'");
		}
	} else {
		throw LuaCallbackException(L, "invalid argument at 0 for lua method 'Deed:setGeneratedObjectTemplate(string)'");
	}
	return 0;
}

int LuaDeed::getGeneratedObjectTemplate(lua_State *L) {
	int parameterCount = lua_gettop(L) - 1;
	
	if (parameterCount == 0) {
		String result = realObject->getGeneratedObjectTemplate();

		lua_pushstring(L, result.toCharArray());
		return 1;
	} else {
		throw LuaCallbackException(L, "invalid argument count " + String::valueOf(parameterCount) + " for lua method 'Deed:getGeneratedObjectTemplate()'");
	}
	return 0;
}

int LuaDeed::setGenerated(lua_State *L) {
	int parameterCount = lua_gettop(L) - 1;
	
	if (lua_isboolean(L, -1)) {
		if (parameterCount == 1) {
			bool gen = lua_toboolean(L, -1);

			realObject->setGenerated(gen);

			return 0;
		} else {
			throw LuaCallbackException(L, "invalid argument count " + String::valueOf(parameterCount) + " for lua method 'Deed:setGenerated(boolean)'");
		}
	} else {
		throw LuaCallbackException(L, "invalid argument at 0 for lua method 'Deed:setGenerated(boolean)'");
	}
	return 0;
}

int LuaDeed::isDeedObject(lua_State *L) {
	int parameterCount = lua_gettop(L) - 1;
	
	if (parameterCount == 0) {
		bool result = realObject->isDeedObject();

		lua_pushboolean(L, result);
		return 1;
	} else {
		throw LuaCallbackException(L, "invalid argument count " + String::valueOf(parameterCount) + " for lua method 'Deed:isDeedObject()'");
	}
	return 0;
}

int LuaDeed::isGenerated(lua_State *L) {
	int parameterCount = lua_gettop(L) - 1;
	
	if (parameterCount == 0) {
		bool result = realObject->isGenerated();

		lua_pushboolean(L, result);
		return 1;
	} else {
		throw LuaCallbackException(L, "invalid argument count " + String::valueOf(parameterCount) + " for lua method 'Deed:isGenerated()'");
	}
	return 0;
}

/*
 *	DeedPOD
 */

DeedPOD::~DeedPOD() {
	finalize();
}

DeedPOD::DeedPOD(void) {
	_className = "Deed";
}


void DeedPOD::writeJSON(nlohmann::json& j) {
	TangibleObjectPOD::writeJSON(j);

	nlohmann::json thisObject = nlohmann::json::object();
	if (generatedObjectTemplate)
		thisObject["generatedObjectTemplate"] = generatedObjectTemplate.value();

	if (generated)
		thisObject["generated"] = generated.value();

	j["Deed"] = thisObject;
}


void DeedPOD::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = DeedPOD::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int DeedPOD::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = TangibleObjectPOD::writeObjectMembers(stream);

	uint32 _nameHashCode;
	int _offset;
	uint32 _totalSize;
	if (generatedObjectTemplate) {
	_nameHashCode = 0x31849f3a; //Deed.generatedObjectTemplate
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<String >::toBinaryStream(&generatedObjectTemplate.value(), stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);
	_count++;
	}

	if (generated) {
	_nameHashCode = 0x3c7f8158; //Deed.generated
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<bool >::toBinaryStream(&generated.value(), stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);
	_count++;
	}


	return _count;
}

bool DeedPOD::readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode) {
	if (TangibleObjectPOD::readObjectMember(stream, nameHashCode))
		return true;

	switch(nameHashCode) {
	case 0x31849f3a: //Deed.generatedObjectTemplate
		{
			String _mngeneratedObjectTemplate;
			TypeInfo<String >::parseFromBinaryStream(&_mngeneratedObjectTemplate, stream);
			generatedObjectTemplate = std::move(_mngeneratedObjectTemplate);
		}
		return true;

	case 0x3c7f8158: //Deed.generated
		{
			bool _mngenerated;
			TypeInfo<bool >::parseFromBinaryStream(&_mngenerated, stream);
			generated = std::move(_mngenerated);
		}
		return true;

	}

	return false;
}

void DeedPOD::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		uint32 _nameHashCode;
		TypeInfo<uint32>::parseFromBinaryStream(&_nameHashCode, stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(DeedPOD::readObjectMember(stream, _nameHashCode)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

}

void DeedPOD::writeObjectCompact(ObjectOutputStream* stream) {
	TangibleObjectPOD::writeObjectCompact(stream);

	TypeInfo<String >::toBinaryStream(&generatedObjectTemplate.value(), stream);

	TypeInfo<bool >::toBinaryStream(&generated.value(), stream);


}

