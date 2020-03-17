/*
 *	autogen/server/zone/objects/building/TutorialBuildingObject.h generated by engine3 IDL compiler 0.70
 */

#ifndef TUTORIALBUILDINGOBJECT_H_
#define TUTORIALBUILDINGOBJECT_H_

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

#include "server/zone/objects/building/BuildingObject.h"

namespace server {
namespace zone {
namespace objects {
namespace building {

class TutorialBuildingObject : public BuildingObject {
public:
	TutorialBuildingObject();

	void setTutorialOwnerID(unsigned long long ownerID);

	unsigned long long getTutorialOwnerID() const;

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead() const;

	void _setImplementation(DistributedObjectServant* servant);

protected:
	TutorialBuildingObject(DummyConstructorParameter* param);

	virtual ~TutorialBuildingObject();

	friend class TutorialBuildingObjectHelper;
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

class TutorialBuildingObjectImplementation : public BuildingObjectImplementation {
protected:
	unsigned long long tutorialOwnerID;

public:
	TutorialBuildingObjectImplementation();

	TutorialBuildingObjectImplementation(DummyConstructorParameter* param);

	void setTutorialOwnerID(unsigned long long ownerID);

	unsigned long long getTutorialOwnerID() const;

	WeakReference<TutorialBuildingObject*> _this;

	operator const TutorialBuildingObject*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~TutorialBuildingObjectImplementation();

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

	friend class TutorialBuildingObject;
};

class TutorialBuildingObjectAdapter : public BuildingObjectAdapter {
public:
	TutorialBuildingObjectAdapter(TutorialBuildingObject* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void setTutorialOwnerID(unsigned long long ownerID);

	unsigned long long getTutorialOwnerID() const;

};

class TutorialBuildingObjectHelper : public DistributedObjectClassHelper, public Singleton<TutorialBuildingObjectHelper> {
	static TutorialBuildingObjectHelper* staticInitializer;

public:
	TutorialBuildingObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectPOD* instantiatePOD();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<TutorialBuildingObjectHelper>;
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

class TutorialBuildingObjectPOD : public BuildingObjectPOD {
public:
	Optional<unsigned long long> tutorialOwnerID;

	String _className;
	TutorialBuildingObjectPOD();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
	bool readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode);
	int writeObjectMembers(ObjectOutputStream* stream);
	void writeObjectCompact(ObjectOutputStream* stream);



	virtual ~TutorialBuildingObjectPOD();

};

} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building;

#endif /*TUTORIALBUILDINGOBJECTPOD_H_*/
