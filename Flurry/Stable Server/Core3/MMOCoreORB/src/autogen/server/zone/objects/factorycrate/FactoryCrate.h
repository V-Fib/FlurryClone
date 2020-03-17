/*
 *	autogen/server/zone/objects/factorycrate/FactoryCrate.h generated by engine3 IDL compiler 0.70
 */

#ifndef FACTORYCRATE_H_
#define FACTORYCRATE_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

#include "system/util/Optional.h"

#ifndef likely
#ifdef __GNUC__
#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)
#else
#define likely(x)       (x)
#define unlikely(x)     (x)
#endif
#endif
#include "engine/util/json_utils.h"

namespace server {
namespace zone {
namespace objects {
namespace scene {

class SceneObject;

class SceneObjectPOD;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

namespace server {
namespace zone {
namespace packets {
namespace scene {

class AttributeListMessage;

} // namespace scene
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::scene;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class CreatureObject;

class CreatureObjectPOD;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace packets {
namespace object {

class ObjectMenuResponse;

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;

namespace server {
namespace zone {
namespace objects {
namespace scene {
namespace variables {

class ContainerPermissions;

} // namespace variables
} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene::variables;

#include "templates/SharedObjectTemplate.h"

#include "server/zone/objects/tangible/TangibleObject.h"

namespace server {
namespace zone {
namespace objects {
namespace factorycrate {

class FactoryCrate : public TangibleObject {
public:
	FactoryCrate();

	void loadTemplateData(SharedObjectTemplate* templateData);

	void initializeTransientMembers();

	void sendBaselinesTo(SceneObject* player);

	/**
	 * Fills the attribute list message options that are sent to player creature
	 * @pre { }
	 * @post { }
	 * @param msg attribute list message with the attributes
	 * @param object player creature to which the message is sent
	 */
	void fillAttributeList(AttributeListMessage* msg, CreatureObject* object);

	/**
	 * Fills the radial options, needs to be overriden
	 * @pre { this object is locked }
	 * @post { this object is locked, menuResponse is complete}
	 * @param menuResponse ObjectMenuResponse that will be sent to the client
	 */
	void fillObjectMenuResponse(ObjectMenuResponse* menuResponse, CreatureObject* player);

	/**
	 * Handles the radial selection sent by the client, must be overriden by inherited objects
	 * @pre { this object is locked, player is locked }
	 * @post { this object is locked, player is locked }
	 * @param player CreatureObject that selected the option
	 * @param selectedID selected menu id
	 * @returns 0 if successfull
	 */
	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	bool isFactoryCrate();

	int getMaxCapacity() const;

	void setMaxCapacity(int value);

	void setUseCount(unsigned int newUseCount, bool notifyClient = true);

	Reference<TangibleObject* > getPrototype();

	String getCraftersName();

	String getSerialNumber();

	bool extractObjectToInventory(CreatureObject* player);

	Reference<TangibleObject* > extractObject(int count = 1);

	void split(int newStackSize);

	int getCountableObjectsRecursive();

	int getSizeOnVendorRecursive();

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead() const;

	void _setImplementation(DistributedObjectServant* servant);

protected:
	FactoryCrate(DummyConstructorParameter* param);

	virtual ~FactoryCrate();

	friend class FactoryCrateHelper;
};

} // namespace factorycrate
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::factorycrate;

namespace server {
namespace zone {
namespace objects {
namespace factorycrate {

class FactoryCrateImplementation : public TangibleObjectImplementation {
protected:
	int maxCapacity;

public:
	FactoryCrateImplementation();

	FactoryCrateImplementation(DummyConstructorParameter* param);

	void loadTemplateData(SharedObjectTemplate* templateData);

	void initializeTransientMembers();

	void sendBaselinesTo(SceneObject* player);

	/**
	 * Fills the attribute list message options that are sent to player creature
	 * @pre { }
	 * @post { }
	 * @param msg attribute list message with the attributes
	 * @param object player creature to which the message is sent
	 */
	void fillAttributeList(AttributeListMessage* msg, CreatureObject* object);

	/**
	 * Fills the radial options, needs to be overriden
	 * @pre { this object is locked }
	 * @post { this object is locked, menuResponse is complete}
	 * @param menuResponse ObjectMenuResponse that will be sent to the client
	 */
	void fillObjectMenuResponse(ObjectMenuResponse* menuResponse, CreatureObject* player);

	/**
	 * Handles the radial selection sent by the client, must be overriden by inherited objects
	 * @pre { this object is locked, player is locked }
	 * @post { this object is locked, player is locked }
	 * @param player CreatureObject that selected the option
	 * @param selectedID selected menu id
	 * @returns 0 if successfull
	 */
	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	virtual bool isFactoryCrate();

	int getMaxCapacity() const;

	void setMaxCapacity(int value);

	void setUseCount(unsigned int newUseCount, bool notifyClient = true);

	Reference<TangibleObject* > getPrototype();

	String getCraftersName();

	String getSerialNumber();

	bool extractObjectToInventory(CreatureObject* player);

	Reference<TangibleObject* > extractObject(int count = 1);

	void split(int newStackSize);

	virtual int getCountableObjectsRecursive();

	virtual int getSizeOnVendorRecursive();

	WeakReference<FactoryCrate*> _this;

	operator const FactoryCrate*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
	virtual void writeJSON(nlohmann::json& j);
protected:
	virtual ~FactoryCrateImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();
	bool readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class FactoryCrate;
};

class FactoryCrateAdapter : public TangibleObjectAdapter {
public:
	FactoryCrateAdapter(FactoryCrate* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

	void sendBaselinesTo(SceneObject* player);

	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	bool isFactoryCrate();

	int getMaxCapacity() const;

	void setMaxCapacity(int value);

	void setUseCount(unsigned int newUseCount, bool notifyClient);

	Reference<TangibleObject* > getPrototype();

	String getCraftersName();

	String getSerialNumber();

	bool extractObjectToInventory(CreatureObject* player);

	Reference<TangibleObject* > extractObject(int count);

	void split(int newStackSize);

	int getCountableObjectsRecursive();

	int getSizeOnVendorRecursive();

};

class FactoryCrateHelper : public DistributedObjectClassHelper, public Singleton<FactoryCrateHelper> {
	static FactoryCrateHelper* staticInitializer;

public:
	FactoryCrateHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectPOD* instantiatePOD();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<FactoryCrateHelper>;
};

} // namespace factorycrate
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::factorycrate;

namespace server {
namespace zone {
namespace objects {
namespace factorycrate {

class FactoryCratePOD : public TangibleObjectPOD {
public:
	Optional<int> maxCapacity;

	String _className;
	FactoryCratePOD();
	virtual void writeJSON(nlohmann::json& j);
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
	bool readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode);
	int writeObjectMembers(ObjectOutputStream* stream);
	void writeObjectCompact(ObjectOutputStream* stream);



	virtual ~FactoryCratePOD();

};

} // namespace factorycrate
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::factorycrate;

#endif /*FACTORYCRATEPOD_H_*/
