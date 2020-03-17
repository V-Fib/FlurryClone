/*
 *	autogen/server/zone/objects/pathfinding/NavArea.h generated by engine3 IDL compiler 0.70
 */

#ifndef NAVAREA_H_
#define NAVAREA_H_

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

class Zone;

class ZonePOD;

} // namespace zone
} // namespace server

using namespace server::zone;

#include "pathfinding/RecastNavMesh.h"

#include "system/util/HashSet.h"

#include "server/zone/objects/area/ActiveArea.h"

#include "engine/util/u3d/AABB.h"

#include "engine/util/u3d/Vector3.h"

#include "system/thread/ReadWriteLock.h"

namespace server {
namespace zone {
namespace objects {
namespace pathfinding {

class NavArea : public ActiveArea {
public:
	NavArea();

	void initializeNavArea(Vector3& position, float radius, Zone* zone, const String& name, bool forceRebuild = false);

	void initialize();

	void notifyEnter(SceneObject* object);

	void notifyExit(SceneObject* object);

	/**
	 * Destroys the object from the world
	 */
	void destroyObjectFromWorld(bool sendSelfDestroy);

	/**
	 * Gets called when this objects is loaded from database
	 * @pre { this locked }
	 * @post { this locked }
	 */
	void notifyLoadFromDatabase();

	const AABB* getMeshBounds();

	RecastNavMesh* getNavMesh();

	void disableMeshUpdates(bool disable);

	bool isNavArea();

	NavArea* asNavArea();

	bool objectInMesh(SceneObject* obj);

	String getMeshName();

	void setMeshName(const String& name);

	bool isInRange(float x, float y, float range);

	void updateNavMesh(const AABB& area);

	void updateNavMesh(SceneObject* object, bool toRemove);

	void setRadius(float f);

	AABB getBoundingBox();

	bool containsPoint(float x, float y);

	bool isNavMeshLoaded() const;

	int getContainedObjectsCount();

	float getAreaTerrainHeight() const;

	void setAreaTerrainHeight(float value);

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead() const;

	void _setImplementation(DistributedObjectServant* servant);

protected:
	NavArea(DummyConstructorParameter* param);

	virtual ~NavArea();

	friend class NavAreaHelper;
};

} // namespace pathfinding
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::pathfinding;

namespace server {
namespace zone {
namespace objects {
namespace pathfinding {

class NavAreaImplementation : public ActiveAreaImplementation {
protected:
	String meshName;

	RecastNavMesh recastNavMesh;

	bool disableUpdates;

	AABB meshBounds;

	HashSet<unsigned long long> containedObjects;

	ReadWriteLock containedLock;

	float terrainHeight;

public:
	NavAreaImplementation();

	NavAreaImplementation(DummyConstructorParameter* param);

	void initializeNavArea(Vector3& position, float radius, Zone* zone, const String& name, bool forceRebuild = false);

	void initialize();

	void notifyEnter(SceneObject* object);

	void notifyExit(SceneObject* object);

	/**
	 * Destroys the object from the world
	 */
	void destroyObjectFromWorld(bool sendSelfDestroy);

	/**
	 * Gets called when this objects is loaded from database
	 * @pre { this locked }
	 * @post { this locked }
	 */
	void notifyLoadFromDatabase();

	const AABB* getMeshBounds();

	RecastNavMesh* getNavMesh();

	void disableMeshUpdates(bool disable);

	bool isNavArea();

	NavArea* asNavArea();

	bool objectInMesh(SceneObject* obj);

	String getMeshName();

	void setMeshName(const String& name);

	bool isInRange(float x, float y, float range);

	void updateNavMesh(const AABB& area);

	void updateNavMesh(SceneObject* object, bool toRemove);

	void setRadius(float f);

	AABB getBoundingBox();

	virtual bool containsPoint(float x, float y);

	bool isNavMeshLoaded() const;

	int getContainedObjectsCount();

	float getAreaTerrainHeight() const;

	void setAreaTerrainHeight(float value);

	WeakReference<NavArea*> _this;

	operator const NavArea*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~NavAreaImplementation();

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

	friend class NavArea;
};

class NavAreaAdapter : public ActiveAreaAdapter {
public:
	NavAreaAdapter(NavArea* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initialize();

	void notifyEnter(SceneObject* object);

	void notifyExit(SceneObject* object);

	void destroyObjectFromWorld(bool sendSelfDestroy);

	void notifyLoadFromDatabase();

	bool isNavArea();

	NavArea* asNavArea();

	bool objectInMesh(SceneObject* obj);

	String getMeshName();

	void setMeshName(const String& name);

	bool isInRange(float x, float y, float range);

	void updateNavMesh(SceneObject* object, bool toRemove);

	bool containsPoint(float x, float y);

	bool isNavMeshLoaded() const;

	int getContainedObjectsCount();

	float getAreaTerrainHeight() const;

	void setAreaTerrainHeight(float value);

};

class NavAreaHelper : public DistributedObjectClassHelper, public Singleton<NavAreaHelper> {
	static NavAreaHelper* staticInitializer;

public:
	NavAreaHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectPOD* instantiatePOD();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<NavAreaHelper>;
};

} // namespace pathfinding
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::pathfinding;

namespace server {
namespace zone {
namespace objects {
namespace pathfinding {

class NavAreaPOD : public ActiveAreaPOD {
public:
	Optional<String> meshName;

	Optional<RecastNavMesh> recastNavMesh;

	Optional<bool> disableUpdates;

	Optional<AABB> meshBounds;

	Optional<HashSet<unsigned long long>> containedObjects;

	String _className;
	NavAreaPOD();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
	bool readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode);
	int writeObjectMembers(ObjectOutputStream* stream);
	void writeObjectCompact(ObjectOutputStream* stream);



	virtual ~NavAreaPOD();

};

} // namespace pathfinding
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::pathfinding;

#endif /*NAVAREAPOD_H_*/
