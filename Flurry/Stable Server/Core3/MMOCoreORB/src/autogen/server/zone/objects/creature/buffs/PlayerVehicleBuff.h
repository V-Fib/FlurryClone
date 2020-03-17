/*
 *	autogen/server/zone/objects/creature/buffs/PlayerVehicleBuff.h generated by engine3 IDL compiler 0.70
 */

#ifndef PLAYERVEHICLEBUFF_H_
#define PLAYERVEHICLEBUFF_H_

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

#include "server/zone/objects/creature/buffs/Buff.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace buffs {

class PlayerVehicleBuff : public Buff {
public:
	PlayerVehicleBuff(CreatureObject* creo, unsigned int buffcrc, float duration, int bufftype);

	void applyAllModifiers();

	void removeAllModifiers();

	void activate(bool applyModifiers);

	void deactivate(bool removeModifiers);

	void updateRiderSpeeds();

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead() const;

	void _setImplementation(DistributedObjectServant* servant);

protected:
	PlayerVehicleBuff(DummyConstructorParameter* param);

	virtual ~PlayerVehicleBuff();

	friend class PlayerVehicleBuffHelper;
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

class PlayerVehicleBuffImplementation : public BuffImplementation {

public:
	PlayerVehicleBuffImplementation(CreatureObject* creo, unsigned int buffcrc, float duration, int bufftype);

	PlayerVehicleBuffImplementation(DummyConstructorParameter* param);

	virtual void applyAllModifiers();

	virtual void removeAllModifiers();

	virtual void activate(bool applyModifiers);

	virtual void deactivate(bool removeModifiers);

	void updateRiderSpeeds();

	WeakReference<PlayerVehicleBuff*> _this;

	operator const PlayerVehicleBuff*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
	virtual void writeJSON(nlohmann::json& j);
protected:
	virtual ~PlayerVehicleBuffImplementation();

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

	friend class PlayerVehicleBuff;
};

class PlayerVehicleBuffAdapter : public BuffAdapter {
public:
	PlayerVehicleBuffAdapter(PlayerVehicleBuff* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void applyAllModifiers();

	void removeAllModifiers();

	void activate(bool applyModifiers);

	void deactivate(bool removeModifiers);

	void updateRiderSpeeds();

};

class PlayerVehicleBuffHelper : public DistributedObjectClassHelper, public Singleton<PlayerVehicleBuffHelper> {
	static PlayerVehicleBuffHelper* staticInitializer;

public:
	PlayerVehicleBuffHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectPOD* instantiatePOD();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<PlayerVehicleBuffHelper>;
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

class PlayerVehicleBuffPOD : public BuffPOD {
public:

	PlayerVehicleBuffPOD();
	virtual void writeJSON(nlohmann::json& j);
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
	bool readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode);
	int writeObjectMembers(ObjectOutputStream* stream);
	void writeObjectCompact(ObjectOutputStream* stream);



	virtual ~PlayerVehicleBuffPOD();

};

} // namespace buffs
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::buffs;

#endif /*PLAYERVEHICLEBUFFPOD_H_*/
