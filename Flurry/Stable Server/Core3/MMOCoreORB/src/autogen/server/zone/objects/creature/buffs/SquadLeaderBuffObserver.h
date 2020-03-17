/*
 *	autogen/server/zone/objects/creature/buffs/SquadLeaderBuffObserver.h generated by engine3 IDL compiler 0.70
 */

#ifndef SQUADLEADERBUFFOBSERVER_H_
#define SQUADLEADERBUFFOBSERVER_H_

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
namespace buffs {

class SquadLeaderBuff;

class SquadLeaderBuffPOD;

} // namespace buffs
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::buffs;

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

#include "engine/core/ManagedObject.h"

#include "engine/util/Observer.h"

#include "engine/util/Observable.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace buffs {

class SquadLeaderBuffObserver : public Observer {
public:
	SquadLeaderBuffObserver(SquadLeaderBuff* b);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void handleObserverEvent(CreatureObject* player, SquadLeaderBuff* slBuff);

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead() const;

	void _setImplementation(DistributedObjectServant* servant);

protected:
	SquadLeaderBuffObserver(DummyConstructorParameter* param);

	virtual ~SquadLeaderBuffObserver();

	friend class SquadLeaderBuffObserverHelper;
};

} // namespace buffs
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::buffs;

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace buffs {

class SquadLeaderBuffObserverImplementation : public ObserverImplementation {
protected:
	ManagedWeakReference<SquadLeaderBuff* > buff;

public:
	SquadLeaderBuffObserverImplementation(SquadLeaderBuff* b);

	SquadLeaderBuffObserverImplementation(DummyConstructorParameter* param);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void handleObserverEvent(CreatureObject* player, SquadLeaderBuff* slBuff);

	WeakReference<SquadLeaderBuffObserver*> _this;

	operator const SquadLeaderBuffObserver*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
	virtual void writeJSON(nlohmann::json& j);
protected:
	virtual ~SquadLeaderBuffObserverImplementation();

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

	friend class SquadLeaderBuffObserver;
};

class SquadLeaderBuffObserverAdapter : public ObserverAdapter {
public:
	SquadLeaderBuffObserverAdapter(SquadLeaderBuffObserver* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void handleObserverEvent(CreatureObject* player, SquadLeaderBuff* slBuff);

};

class SquadLeaderBuffObserverHelper : public DistributedObjectClassHelper, public Singleton<SquadLeaderBuffObserverHelper> {
	static SquadLeaderBuffObserverHelper* staticInitializer;

public:
	SquadLeaderBuffObserverHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectPOD* instantiatePOD();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<SquadLeaderBuffObserverHelper>;
};

} // namespace buffs
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::buffs;

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace buffs {

class SquadLeaderBuffObserverPOD : public ObserverPOD {
public:
	Optional<ManagedWeakReference<SquadLeaderBuffPOD* >> buff;

	String _className;
	SquadLeaderBuffObserverPOD();
	virtual void writeJSON(nlohmann::json& j);
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
	bool readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode);
	int writeObjectMembers(ObjectOutputStream* stream);
	void writeObjectCompact(ObjectOutputStream* stream);



	virtual ~SquadLeaderBuffObserverPOD();

};

} // namespace buffs
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::buffs;

#endif /*SQUADLEADERBUFFOBSERVERPOD_H_*/
