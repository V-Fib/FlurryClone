/*
 *	autogen/server/zone/objects/player/sessions/FindSession.h generated by engine3 IDL compiler 0.70
 */

#ifndef FINDSESSION_H_
#define FINDSESSION_H_

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
namespace waypoint {

class WaypointObject;

class WaypointObjectPOD;

} // namespace waypoint
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::waypoint;

#include "server/zone/objects/scene/SessionFacadeType.h"

#include "server/zone/objects/player/sui/listbox/SuiListBox.h"

#include "engine/log/Logger.h"

#include "engine/util/Facade.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sessions {

class FindSession : public Facade {
public:
	FindSession(CreatureObject* pl);

	int initializeSession();

	int cancelSession();

	int clearSession();

	void initalizeFindMenu();

	WaypointObject* addWaypoint(float x, float y, const String& name);

	void findPlanetaryObject(String& maplocationtype);

	void clearWaypoint();

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead() const;

	void _setImplementation(DistributedObjectServant* servant);

protected:
	FindSession(DummyConstructorParameter* param);

	virtual ~FindSession();

	friend class FindSessionHelper;
};

} // namespace sessions
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sessions;

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sessions {

class FindSessionImplementation : public FacadeImplementation {
protected:
	ManagedWeakReference<CreatureObject* > player;

	ManagedReference<SuiListBox* > findSuiBox;

public:
	FindSessionImplementation(CreatureObject* pl);

	FindSessionImplementation(DummyConstructorParameter* param);

	int initializeSession();

	int cancelSession();

	int clearSession();

	void initalizeFindMenu();

	WaypointObject* addWaypoint(float x, float y, const String& name);

	void findPlanetaryObject(String& maplocationtype);

	void clearWaypoint();

	WeakReference<FindSession*> _this;

	operator const FindSession*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~FindSessionImplementation();

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

	friend class FindSession;
};

class FindSessionAdapter : public FacadeAdapter {
public:
	FindSessionAdapter(FindSession* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int initializeSession();

	int cancelSession();

	int clearSession();

	WaypointObject* addWaypoint(float x, float y, const String& name);

	void clearWaypoint();

};

class FindSessionHelper : public DistributedObjectClassHelper, public Singleton<FindSessionHelper> {
	static FindSessionHelper* staticInitializer;

public:
	FindSessionHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectPOD* instantiatePOD();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<FindSessionHelper>;
};

} // namespace sessions
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sessions;

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sessions {

class FindSessionPOD : public FacadePOD {
public:
	Optional<ManagedWeakReference<CreatureObjectPOD* >> player;

	Optional<ManagedReference<SuiListBoxPOD* >> findSuiBox;

	String _className;
	FindSessionPOD();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
	bool readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode);
	int writeObjectMembers(ObjectOutputStream* stream);
	void writeObjectCompact(ObjectOutputStream* stream);



	virtual ~FindSessionPOD();

};

} // namespace sessions
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sessions;

#endif /*FINDSESSIONPOD_H_*/
