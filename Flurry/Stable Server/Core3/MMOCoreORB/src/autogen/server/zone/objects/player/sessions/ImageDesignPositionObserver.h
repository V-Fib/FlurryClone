/*
 *	autogen/server/zone/objects/player/sessions/ImageDesignPositionObserver.h generated by engine3 IDL compiler 0.70
 */

#ifndef IMAGEDESIGNPOSITIONOBSERVER_H_
#define IMAGEDESIGNPOSITIONOBSERVER_H_

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
namespace player {
namespace sessions {

class ImageDesignSession;

class ImageDesignSessionPOD;

} // namespace sessions
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sessions;

#include "server/zone/objects/scene/ObserverType.h"

#include "engine/core/ManagedObject.h"

#include "engine/util/Observer.h"

#include "engine/util/Observable.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sessions {

class ImageDesignPositionObserver : public Observer {
public:
	ImageDesignPositionObserver(ImageDesignSession* designSession);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead() const;

	void _setImplementation(DistributedObjectServant* servant);

protected:
	ImageDesignPositionObserver(DummyConstructorParameter* param);

	virtual ~ImageDesignPositionObserver();

	friend class ImageDesignPositionObserverHelper;
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

class ImageDesignPositionObserverImplementation : public ObserverImplementation {
	ManagedWeakReference<ImageDesignSession* > session;

public:
	ImageDesignPositionObserverImplementation(ImageDesignSession* designSession);

	ImageDesignPositionObserverImplementation(DummyConstructorParameter* param);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	WeakReference<ImageDesignPositionObserver*> _this;

	operator const ImageDesignPositionObserver*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~ImageDesignPositionObserverImplementation();

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

	friend class ImageDesignPositionObserver;
};

class ImageDesignPositionObserverAdapter : public ObserverAdapter {
public:
	ImageDesignPositionObserverAdapter(ImageDesignPositionObserver* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

};

class ImageDesignPositionObserverHelper : public DistributedObjectClassHelper, public Singleton<ImageDesignPositionObserverHelper> {
	static ImageDesignPositionObserverHelper* staticInitializer;

public:
	ImageDesignPositionObserverHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectPOD* instantiatePOD();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<ImageDesignPositionObserverHelper>;
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

class ImageDesignPositionObserverPOD : public ObserverPOD {
public:
	Optional<ManagedWeakReference<ImageDesignSessionPOD* >> session;

	String _className;
	ImageDesignPositionObserverPOD();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
	bool readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode);
	int writeObjectMembers(ObjectOutputStream* stream);
	void writeObjectCompact(ObjectOutputStream* stream);



	virtual ~ImageDesignPositionObserverPOD();

};

} // namespace sessions
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sessions;

#endif /*IMAGEDESIGNPOSITIONOBSERVERPOD_H_*/
