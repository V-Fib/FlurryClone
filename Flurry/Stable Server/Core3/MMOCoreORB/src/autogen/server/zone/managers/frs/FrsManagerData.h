/*
 *	autogen/server/zone/managers/frs/FrsManagerData.h generated by engine3 IDL compiler 0.70
 */

#ifndef FRSMANAGERDATA_H_
#define FRSMANAGERDATA_H_

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

#include "server/zone/managers/frs/FrsRank.h"

#include "server/zone/managers/frs/ChallengeVoteData.h"

#include "server/zone/managers/frs/ArenaChallengeData.h"

#include "server/zone/managers/frs/FrsTimeMap.h"

#include "system/lang/Time.h"

#include "engine/core/ManagedObject.h"

#include "system/util/VectorMap.h"

#include "system/util/SortedVector.h"

#include "system/util/Vector.h"

namespace server {
namespace zone {
namespace managers {
namespace frs {

class FrsManagerData : public ManagedObject {
public:
	FrsManagerData();

	Vector<ManagedReference<FrsRank* > >* getLightRanks();

	Vector<ManagedReference<FrsRank* > >* getDarkRanks();

	VectorMap<unsigned long long, ManagedReference<ChallengeVoteData* > >* getLightChallenges();

	int getTotalLightChallenges() const;

	void addLightChallenge(unsigned long long playerID, ChallengeVoteData* voteData);

	void removeLightChallenge(unsigned long long playerID);

	ChallengeVoteData* getLightChallenge(unsigned long long playerID) const;

	bool hasChallengedRecently(unsigned long long playerID, unsigned long long challengeCooldown);

	unsigned long long getChallengeTime(unsigned long long playerID) const;

	unsigned long long getChallengeDuration(unsigned long long playerID) const;

	void updateChallengeTime(unsigned long long playerID);

	void removeChallengeTime(unsigned long long playerID);

	void removeDemoteTime(unsigned long long playerID);

	bool hasDemotedRecently(unsigned long long playerID, unsigned long long demoteCooldown);

	unsigned long long getDemoteTime(unsigned long long playerID) const;

	unsigned long long getDemoteDuration(unsigned long long playerID) const;

	void updateDemoteTime(unsigned long long playerID);

	void updateLastMaintenanceTick();

	unsigned long long getLastMaintenanceTick() const;

	void updateLastVoteStatusTick();

	unsigned long long getLastVoteStatusTick() const;

	int getExperienceDebt(unsigned long long playerID) const;

	void setExperienceDebt(unsigned long long playerID, int debt);

	void removeExperienceDebt(unsigned long long playerID);

	unsigned long long getLastArenaOpenTime() const;

	void updateLastArenaOpenTime();

	short getArenaStatus() const;

	void setArenaStatus(short status);

	void addArenaChallenge(unsigned long long playerID, ArenaChallengeData* data);

	bool hasOpenArenaChallenge(unsigned long long playerID) const;

	ArenaChallengeData* getArenaChallenge(unsigned long long playerID) const;

	void removeArenaChallenge(unsigned long long playerID);

	void addArenaFighter(unsigned long long playerID);

	void removeArenaFighter(unsigned long long playerID);

	bool isFightingInArena(unsigned long long playerID) const;

	const SortedVector<unsigned long long>* getArenaFighters() const;

	VectorMap<unsigned long long, ManagedReference<ArenaChallengeData* > >* getArenaChallenges();

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead() const;

	void _setImplementation(DistributedObjectServant* servant);

protected:
	FrsManagerData(DummyConstructorParameter* param);

	virtual ~FrsManagerData();

	friend class FrsManagerDataHelper;
};

} // namespace frs
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::frs;

namespace server {
namespace zone {
namespace managers {
namespace frs {

class FrsManagerDataImplementation : public ManagedObjectImplementation {
protected:
	Time lastVoteStatusTick;

	Time lastMaintenanceTick;

	Time lastArenaOpenTime;

	VectorMap<unsigned long long, int> experienceDebt;

	VectorMap<unsigned long long, ManagedReference<ChallengeVoteData* > > lightChallenges;

	FrsTimeMap challengeTimes;

	FrsTimeMap demoteTimes;

	VectorMap<unsigned long long, ManagedReference<ArenaChallengeData* > > arenaChallenges;

	SortedVector<unsigned long long> arenaFighters;

	Vector<ManagedReference<FrsRank* > > lightRanks;

	Vector<ManagedReference<FrsRank* > > darkRanks;

	short arenaStatus;

public:
	FrsManagerDataImplementation();

	FrsManagerDataImplementation(DummyConstructorParameter* param);

	Vector<ManagedReference<FrsRank* > >* getLightRanks();

	Vector<ManagedReference<FrsRank* > >* getDarkRanks();

	VectorMap<unsigned long long, ManagedReference<ChallengeVoteData* > >* getLightChallenges();

	int getTotalLightChallenges() const;

	void addLightChallenge(unsigned long long playerID, ChallengeVoteData* voteData);

	void removeLightChallenge(unsigned long long playerID);

	ChallengeVoteData* getLightChallenge(unsigned long long playerID) const;

	bool hasChallengedRecently(unsigned long long playerID, unsigned long long challengeCooldown);

	unsigned long long getChallengeTime(unsigned long long playerID) const;

	unsigned long long getChallengeDuration(unsigned long long playerID) const;

	void updateChallengeTime(unsigned long long playerID);

	void removeChallengeTime(unsigned long long playerID);

	void removeDemoteTime(unsigned long long playerID);

	bool hasDemotedRecently(unsigned long long playerID, unsigned long long demoteCooldown);

	unsigned long long getDemoteTime(unsigned long long playerID) const;

	unsigned long long getDemoteDuration(unsigned long long playerID) const;

	void updateDemoteTime(unsigned long long playerID);

	void updateLastMaintenanceTick();

	unsigned long long getLastMaintenanceTick() const;

	void updateLastVoteStatusTick();

	unsigned long long getLastVoteStatusTick() const;

	int getExperienceDebt(unsigned long long playerID) const;

	void setExperienceDebt(unsigned long long playerID, int debt);

	void removeExperienceDebt(unsigned long long playerID);

	unsigned long long getLastArenaOpenTime() const;

	void updateLastArenaOpenTime();

	short getArenaStatus() const;

	void setArenaStatus(short status);

	void addArenaChallenge(unsigned long long playerID, ArenaChallengeData* data);

	bool hasOpenArenaChallenge(unsigned long long playerID) const;

	ArenaChallengeData* getArenaChallenge(unsigned long long playerID) const;

	void removeArenaChallenge(unsigned long long playerID);

	void addArenaFighter(unsigned long long playerID);

	void removeArenaFighter(unsigned long long playerID);

	bool isFightingInArena(unsigned long long playerID) const;

	const SortedVector<unsigned long long>* getArenaFighters() const;

	VectorMap<unsigned long long, ManagedReference<ArenaChallengeData* > >* getArenaChallenges();

	WeakReference<FrsManagerData*> _this;

	operator const FrsManagerData*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
	virtual void writeJSON(nlohmann::json& j);
protected:
	virtual ~FrsManagerDataImplementation();

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

	friend class FrsManagerData;
};

class FrsManagerDataAdapter : public ManagedObjectAdapter {
public:
	FrsManagerDataAdapter(FrsManagerData* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int getTotalLightChallenges() const;

	void addLightChallenge(unsigned long long playerID, ChallengeVoteData* voteData);

	void removeLightChallenge(unsigned long long playerID);

	bool hasChallengedRecently(unsigned long long playerID, unsigned long long challengeCooldown);

	unsigned long long getChallengeTime(unsigned long long playerID) const;

	unsigned long long getChallengeDuration(unsigned long long playerID) const;

	void updateChallengeTime(unsigned long long playerID);

	void removeChallengeTime(unsigned long long playerID);

	void removeDemoteTime(unsigned long long playerID);

	bool hasDemotedRecently(unsigned long long playerID, unsigned long long demoteCooldown);

	unsigned long long getDemoteTime(unsigned long long playerID) const;

	unsigned long long getDemoteDuration(unsigned long long playerID) const;

	void updateDemoteTime(unsigned long long playerID);

	void updateLastMaintenanceTick();

	unsigned long long getLastMaintenanceTick() const;

	void updateLastVoteStatusTick();

	unsigned long long getLastVoteStatusTick() const;

	int getExperienceDebt(unsigned long long playerID) const;

	void setExperienceDebt(unsigned long long playerID, int debt);

	void removeExperienceDebt(unsigned long long playerID);

	unsigned long long getLastArenaOpenTime() const;

	void updateLastArenaOpenTime();

	short getArenaStatus() const;

	void setArenaStatus(short status);

	void addArenaChallenge(unsigned long long playerID, ArenaChallengeData* data);

	bool hasOpenArenaChallenge(unsigned long long playerID) const;

	ArenaChallengeData* getArenaChallenge(unsigned long long playerID) const;

	void removeArenaChallenge(unsigned long long playerID);

	void addArenaFighter(unsigned long long playerID);

	void removeArenaFighter(unsigned long long playerID);

	bool isFightingInArena(unsigned long long playerID) const;

};

class FrsManagerDataHelper : public DistributedObjectClassHelper, public Singleton<FrsManagerDataHelper> {
	static FrsManagerDataHelper* staticInitializer;

public:
	FrsManagerDataHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectPOD* instantiatePOD();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<FrsManagerDataHelper>;
};

} // namespace frs
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::frs;

namespace server {
namespace zone {
namespace managers {
namespace frs {

class FrsManagerDataPOD : public ManagedObjectPOD {
public:
	Optional<Time> lastVoteStatusTick;

	Optional<Time> lastMaintenanceTick;

	Optional<Time> lastArenaOpenTime;

	Optional<VectorMap<unsigned long long, int>> experienceDebt;

	Optional<VectorMap<unsigned long long, ManagedReference<ChallengeVoteDataPOD* > >> lightChallenges;

	Optional<FrsTimeMap> challengeTimes;

	Optional<FrsTimeMap> demoteTimes;

	Optional<VectorMap<unsigned long long, ManagedReference<ArenaChallengeDataPOD* > >> arenaChallenges;

	Optional<SortedVector<unsigned long long>> arenaFighters;

	Optional<Vector<ManagedReference<FrsRankPOD* > >> lightRanks;

	Optional<Vector<ManagedReference<FrsRankPOD* > >> darkRanks;

	Optional<short> arenaStatus;

	String _className;
	FrsManagerDataPOD();
	virtual void writeJSON(nlohmann::json& j);
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
	bool readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode);
	int writeObjectMembers(ObjectOutputStream* stream);
	void writeObjectCompact(ObjectOutputStream* stream);



	virtual ~FrsManagerDataPOD();

};

} // namespace frs
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::frs;

#endif /*FRSMANAGERDATAPOD_H_*/
