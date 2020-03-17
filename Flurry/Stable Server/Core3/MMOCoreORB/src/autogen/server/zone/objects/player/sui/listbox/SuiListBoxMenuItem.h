/*
 *	autogen/server/zone/objects/player/sui/listbox/SuiListBoxMenuItem.h generated by engine3 IDL compiler 0.70
 */

#ifndef SUILISTBOXMENUITEM_H_
#define SUILISTBOXMENUITEM_H_

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

#include "engine/core/ManagedObject.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace listbox {

class SuiListBoxMenuItem : public ManagedObject {
public:
	SuiListBoxMenuItem(const String& name, unsigned long long oid = 0);

	unsigned long long getObjectID() const;

	String getOptionName() const;

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead() const;

	void _setImplementation(DistributedObjectServant* servant);

protected:
	SuiListBoxMenuItem(DummyConstructorParameter* param);

	virtual ~SuiListBoxMenuItem();

	friend class SuiListBoxMenuItemHelper;
};

} // namespace listbox
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::listbox;

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace listbox {

class SuiListBoxMenuItemImplementation : public ManagedObjectImplementation {
protected:
	String optionName;

	unsigned long long objectID;

public:
	SuiListBoxMenuItemImplementation(const String& name, unsigned long long oid = 0);

	SuiListBoxMenuItemImplementation(DummyConstructorParameter* param);

	unsigned long long getObjectID() const;

	String getOptionName() const;

	WeakReference<SuiListBoxMenuItem*> _this;

	operator const SuiListBoxMenuItem*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~SuiListBoxMenuItemImplementation();

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

	friend class SuiListBoxMenuItem;
};

class SuiListBoxMenuItemAdapter : public ManagedObjectAdapter {
public:
	SuiListBoxMenuItemAdapter(SuiListBoxMenuItem* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	unsigned long long getObjectID() const;

	String getOptionName() const;

};

class SuiListBoxMenuItemHelper : public DistributedObjectClassHelper, public Singleton<SuiListBoxMenuItemHelper> {
	static SuiListBoxMenuItemHelper* staticInitializer;

public:
	SuiListBoxMenuItemHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectPOD* instantiatePOD();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<SuiListBoxMenuItemHelper>;
};

} // namespace listbox
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::listbox;

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace listbox {

class SuiListBoxMenuItemPOD : public ManagedObjectPOD {
public:
	Optional<String> optionName;

	Optional<unsigned long long> objectID;

	String _className;
	SuiListBoxMenuItemPOD();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
	bool readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode);
	int writeObjectMembers(ObjectOutputStream* stream);
	void writeObjectCompact(ObjectOutputStream* stream);



	virtual ~SuiListBoxMenuItemPOD();

};

} // namespace listbox
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::listbox;

#endif /*SUILISTBOXMENUITEMPOD_H_*/
