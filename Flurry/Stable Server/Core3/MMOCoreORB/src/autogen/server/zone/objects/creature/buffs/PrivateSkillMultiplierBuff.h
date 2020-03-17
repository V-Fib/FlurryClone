/*
 *	autogen/server/zone/objects/creature/buffs/PrivateSkillMultiplierBuff.h generated by engine3 IDL compiler 0.70
 */

#ifndef PRIVATESKILLMULTIPLIERBUFF_H_
#define PRIVATESKILLMULTIPLIERBUFF_H_

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

#include "server/zone/objects/creature/buffs/PrivateBuff.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace buffs {

class PrivateSkillMultiplierBuff : public PrivateBuff {
public:
	PrivateSkillMultiplierBuff(CreatureObject* creo, unsigned int buffcrc, float duration, int bufftype);

	void applySkillModifiers();

	void removeSkillModifiers();

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead() const;

	void _setImplementation(DistributedObjectServant* servant);

protected:
	PrivateSkillMultiplierBuff(DummyConstructorParameter* param);

	virtual ~PrivateSkillMultiplierBuff();

	friend class PrivateSkillMultiplierBuffHelper;
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

class PrivateSkillMultiplierBuffImplementation : public PrivateBuffImplementation {

public:
	PrivateSkillMultiplierBuffImplementation(CreatureObject* creo, unsigned int buffcrc, float duration, int bufftype);

	PrivateSkillMultiplierBuffImplementation(DummyConstructorParameter* param);

	void applySkillModifiers();

	void removeSkillModifiers();

	WeakReference<PrivateSkillMultiplierBuff*> _this;

	operator const PrivateSkillMultiplierBuff*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
	virtual void writeJSON(nlohmann::json& j);
protected:
	virtual ~PrivateSkillMultiplierBuffImplementation();

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

	friend class PrivateSkillMultiplierBuff;
};

class PrivateSkillMultiplierBuffAdapter : public PrivateBuffAdapter {
public:
	PrivateSkillMultiplierBuffAdapter(PrivateSkillMultiplierBuff* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void applySkillModifiers();

	void removeSkillModifiers();

};

class PrivateSkillMultiplierBuffHelper : public DistributedObjectClassHelper, public Singleton<PrivateSkillMultiplierBuffHelper> {
	static PrivateSkillMultiplierBuffHelper* staticInitializer;

public:
	PrivateSkillMultiplierBuffHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectPOD* instantiatePOD();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<PrivateSkillMultiplierBuffHelper>;
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

class PrivateSkillMultiplierBuffPOD : public PrivateBuffPOD {
public:

	PrivateSkillMultiplierBuffPOD();
	virtual void writeJSON(nlohmann::json& j);
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
	bool readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode);
	int writeObjectMembers(ObjectOutputStream* stream);
	void writeObjectCompact(ObjectOutputStream* stream);



	virtual ~PrivateSkillMultiplierBuffPOD();

};

} // namespace buffs
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::buffs;

#endif /*PRIVATESKILLMULTIPLIERBUFFPOD_H_*/
