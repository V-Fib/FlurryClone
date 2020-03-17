/*
 *	autogen/server/zone/objects/tangible/deed/eventperk/EventPerkDeed.h generated by engine3 IDL compiler 0.70
 */

#ifndef EVENTPERKDEED_H_
#define EVENTPERKDEED_H_

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
namespace objects {
namespace tangible {

class TangibleObject;

class TangibleObjectPOD;

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

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
namespace objects {
namespace tangible {
namespace tasks {

class RemoveEventPerkDeedTask;

} // namespace tasks
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::tasks;

#include "system/lang/ref/Reference.h"

#include "system/lang/Time.h"

#include "templates/SharedObjectTemplate.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/objects/tangible/deed/Deed.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace deed {
namespace eventperk {

class EventPerkDeed : public Deed {
public:
	EventPerkDeed();

	void initializeTransientMembers();

	/**
	 * Reads and sets the template data from a SharedTangibleObjectTemplate LuaObject
	 * @pre { templateData is a valid pointer }
	 * @post { TangibleObject members are initialized }
	 * @param templateData templateData points to the SharedTangibleObjectTemplate LuaObject that is used to initialize the TangibleObject members
	 */
	void loadTemplateData(SharedObjectTemplate* templateData);

	void fillAttributeList(AttributeListMessage* alm, CreatureObject* object);

	void fillObjectMenuResponse(ObjectMenuResponse* menuResponse, CreatureObject* player);

	/**
	 * Handles the radial selection sent by the client
	 * @pre { this object is locked, player is locked }
	 * @post { this object is locked, player is locked }
	 * @returns 0 if successfull
	 */
	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	/**
	 * Destroys this object from database
	 * @pre { this is locked }
	 * @post { this is locked }
	 * @param destroyContainedObjects if true, will destroy from database all its contained objects
	 */
	void destroyObjectFromDatabase(bool destroyContainedObjects = false);

	void activateRemoveEvent(bool immediate = false);

	String getDurationString();

	void parseChildObjects(SceneObject* parent);

	void setOwner(CreatureObject* player);

	ManagedWeakReference<CreatureObject* > getOwner() const;

	ManagedWeakReference<TangibleObject* > getGeneratedObject() const;

	int getPerkType() const;

	Time* getPurchaseTime();

	bool isEventPerkDeed();

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead() const;

	void _setImplementation(DistributedObjectServant* servant);

protected:
	EventPerkDeed(DummyConstructorParameter* param);

	virtual ~EventPerkDeed();

	friend class EventPerkDeedHelper;
};

} // namespace eventperk
} // namespace deed
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::deed::eventperk;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace deed {
namespace eventperk {

class EventPerkDeedImplementation : public DeedImplementation {
protected:
	int perkType;

	unsigned long long generatedTimeToLive;

	Time purchaseTime;

	ManagedWeakReference<CreatureObject* > owner;

	ManagedWeakReference<TangibleObject* > generatedObject;

	Reference<RemoveEventPerkDeedTask*> removeEventPerkDeedTask;

public:
	EventPerkDeedImplementation();

	EventPerkDeedImplementation(DummyConstructorParameter* param);

	void initializeTransientMembers();

	/**
	 * Reads and sets the template data from a SharedTangibleObjectTemplate LuaObject
	 * @pre { templateData is a valid pointer }
	 * @post { TangibleObject members are initialized }
	 * @param templateData templateData points to the SharedTangibleObjectTemplate LuaObject that is used to initialize the TangibleObject members
	 */
	void loadTemplateData(SharedObjectTemplate* templateData);

	void fillAttributeList(AttributeListMessage* alm, CreatureObject* object);

	void fillObjectMenuResponse(ObjectMenuResponse* menuResponse, CreatureObject* player);

	/**
	 * Handles the radial selection sent by the client
	 * @pre { this object is locked, player is locked }
	 * @post { this object is locked, player is locked }
	 * @returns 0 if successfull
	 */
	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	/**
	 * Destroys this object from database
	 * @pre { this is locked }
	 * @post { this is locked }
	 * @param destroyContainedObjects if true, will destroy from database all its contained objects
	 */
	void destroyObjectFromDatabase(bool destroyContainedObjects = false);

	void activateRemoveEvent(bool immediate = false);

	String getDurationString();

	void parseChildObjects(SceneObject* parent);

	void setOwner(CreatureObject* player);

	ManagedWeakReference<CreatureObject* > getOwner() const;

	ManagedWeakReference<TangibleObject* > getGeneratedObject() const;

	int getPerkType() const;

	Time* getPurchaseTime();

	bool isEventPerkDeed();

	WeakReference<EventPerkDeed*> _this;

	operator const EventPerkDeed*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
	virtual void writeJSON(nlohmann::json& j);
protected:
	virtual ~EventPerkDeedImplementation();

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

	friend class EventPerkDeed;
};

class EventPerkDeedAdapter : public DeedAdapter {
public:
	EventPerkDeedAdapter(EventPerkDeed* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	void destroyObjectFromDatabase(bool destroyContainedObjects);

	void activateRemoveEvent(bool immediate);

	String getDurationString();

	void parseChildObjects(SceneObject* parent);

	void setOwner(CreatureObject* player);

	ManagedWeakReference<CreatureObject* > getOwner() const;

	ManagedWeakReference<TangibleObject* > getGeneratedObject() const;

	int getPerkType() const;

	bool isEventPerkDeed();

};

class EventPerkDeedHelper : public DistributedObjectClassHelper, public Singleton<EventPerkDeedHelper> {
	static EventPerkDeedHelper* staticInitializer;

public:
	EventPerkDeedHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectPOD* instantiatePOD();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<EventPerkDeedHelper>;
};

} // namespace eventperk
} // namespace deed
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::deed::eventperk;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace deed {
namespace eventperk {

class EventPerkDeedPOD : public DeedPOD {
public:
	Optional<int> perkType;

	Optional<unsigned long long> generatedTimeToLive;

	Optional<Time> purchaseTime;

	Optional<ManagedWeakReference<CreatureObjectPOD* >> owner;

	Optional<ManagedWeakReference<TangibleObjectPOD* >> generatedObject;

	String _className;
	EventPerkDeedPOD();
	virtual void writeJSON(nlohmann::json& j);
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
	bool readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode);
	int writeObjectMembers(ObjectOutputStream* stream);
	void writeObjectCompact(ObjectOutputStream* stream);



	virtual ~EventPerkDeedPOD();

};

} // namespace eventperk
} // namespace deed
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::deed::eventperk;

#endif /*EVENTPERKDEEDPOD_H_*/
