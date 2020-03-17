/*
 *	autogen/server/zone/objects/building/PoiBuilding.h generated by engine3 IDL compiler 0.70
 */

#ifndef POIBUILDING_H_
#define POIBUILDING_H_

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
namespace tangible {

class DespawnLairOnPlayerDisappear;

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

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

class QuadTreeEntry;

class QuadTreeEntryPOD;

} // namespace zone
} // namespace server

using namespace server::zone;

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

#include "server/zone/CloseObjectsVector.h"

#include "system/thread/atomic/AtomicInteger.h"

#include "engine/log/Logger.h"

#include "server/zone/objects/building/BuildingObject.h"

namespace server {
namespace zone {
namespace objects {
namespace building {

class PoiBuilding : public BuildingObject {
public:
	PoiBuilding();

	int getNumberOfPlayersInRange();

	bool getDespawnOnNoPlayersInRange() const;

	void setDespawnOnNoPlayersInRange(bool b);

	void notifyInsert(QuadTreeEntry* entry);

	void notifyDissapear(QuadTreeEntry* entry);

	void activateDespawnEvent();

	void clearDespawnEvent();

	bool isPoiBuilding();

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead() const;

	void _setImplementation(DistributedObjectServant* servant);

protected:
	PoiBuilding(DummyConstructorParameter* param);

	virtual ~PoiBuilding();

	friend class PoiBuildingHelper;
};

} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building;

namespace server {
namespace zone {
namespace objects {
namespace building {

class PoiBuildingImplementation : public BuildingObjectImplementation {
protected:
	AtomicInteger numberOfPlayersInRange;

	bool despawnOnNoPlayersInRange;

	Reference<DespawnLairOnPlayerDisappear* > despawnEvent;

public:
	PoiBuildingImplementation();

	PoiBuildingImplementation(DummyConstructorParameter* param);

	int getNumberOfPlayersInRange();

	bool getDespawnOnNoPlayersInRange() const;

	void setDespawnOnNoPlayersInRange(bool b);

	void notifyInsert(QuadTreeEntry* entry);

	void notifyDissapear(QuadTreeEntry* entry);

	void activateDespawnEvent();

	void clearDespawnEvent();

	bool isPoiBuilding();

	WeakReference<PoiBuilding*> _this;

	operator const PoiBuilding*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~PoiBuildingImplementation();

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

	friend class PoiBuilding;
};

class PoiBuildingAdapter : public BuildingObjectAdapter {
public:
	PoiBuildingAdapter(PoiBuilding* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int getNumberOfPlayersInRange();

	bool getDespawnOnNoPlayersInRange() const;

	void setDespawnOnNoPlayersInRange(bool b);

	void notifyInsert(QuadTreeEntry* entry);

	void notifyDissapear(QuadTreeEntry* entry);

	void activateDespawnEvent();

	void clearDespawnEvent();

	bool isPoiBuilding();

};

class PoiBuildingHelper : public DistributedObjectClassHelper, public Singleton<PoiBuildingHelper> {
	static PoiBuildingHelper* staticInitializer;

public:
	PoiBuildingHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectPOD* instantiatePOD();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<PoiBuildingHelper>;
};

} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building;

namespace server {
namespace zone {
namespace objects {
namespace building {

class PoiBuildingPOD : public BuildingObjectPOD {
public:
	Optional<bool> despawnOnNoPlayersInRange;

	String _className;
	PoiBuildingPOD();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
	bool readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode);
	int writeObjectMembers(ObjectOutputStream* stream);
	void writeObjectCompact(ObjectOutputStream* stream);



	virtual ~PoiBuildingPOD();

};

} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building;

#endif /*POIBUILDINGPOD_H_*/
