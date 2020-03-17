/*
 *	autogen/server/zone/managers/auction/AuctionManager.h generated by engine3 IDL compiler 0.70
 */

#ifndef AUCTIONMANAGER_H_
#define AUCTIONMANAGER_H_

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

class ZoneServer;

class ZoneServerPOD;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {

class ZoneServer;

class ZoneServerPOD;

} // namespace zone
} // namespace server

using namespace server::zone;

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
namespace managers {
namespace auction {

class AuctionsMap;

class AuctionsMapPOD;

} // namespace auction
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::auction;

namespace server {
namespace zone {
namespace objects {
namespace auction {

class AuctionItem;

class AuctionItemPOD;

} // namespace auction
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::auction;

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

#include "server/zone/packets/auction/AuctionQueryHeadersResponseMessage.h"

#include "server/zone/managers/auction/TerminalListVector.h"

#include "server/zone/managers/auction/AuctionEventsMap.h"

#include "system/util/SynchronizedVectorMap.h"

#include "engine/log/Logger.h"

#include "engine/core/ManagedService.h"

#include "system/util/VectorMap.h"

namespace server {
namespace zone {
namespace managers {
namespace auction {

class AuctionManager : public ManagedService {
public:
	static const int MAXBAZAARPRICE = 1000000;

	static const int MAXSALES = 100;

	static const int SALESFEE = 20;

	static const int CHECKEVERY = 60;

	static const int MAXVENDORPRICE = 99999999;

	static const int ITEMSPERPAGE = 100;

	static const int VENDOREXPIREPERIOD = 7776000;

	static const int COMMODITYEXPIREPERIOD = 604800;

	static const int LT_GALAXY = 0;

	static const int LT_PLANET = 1;

	static const int LT_REGION = 2;

	static const int LT_MARKET = 3;

	static const int ST_CATEGORY = 0;

	static const int ST_LOCATION = 1;

	static const int ST_ALL = 2;

	static const int ST_PLAYER_SALES = 3;

	static const int ST_PLAYER_BIDS = 4;

	static const int ST_PLAYER_STOCKROOM = 5;

	static const int ST_VENDOR_OFFERS = 6;

	static const int ST_VENDOR_SELLING = 7;

	static const int ST_VENDOR_STOCKROOM = 8;

	static const int ST_PLAYER_OFFERS_TO_VENDOR = 9;

	AuctionManager(ZoneServer* server);

	void initialize();

	void addSaleItem(CreatureObject* player, unsigned long long objectid, SceneObject* vendor, const UnicodeString& description, int price, unsigned int duration, bool auction, bool premium);

	AuctionItem* createVendorItem(CreatureObject* player, SceneObject* objectToSell, SceneObject* vendor, const UnicodeString& description, int price, unsigned int duration, bool auction, bool premium);

	int checkSaleItem(CreatureObject* player, SceneObject* object, SceneObject* vendor, int price, bool premium, bool stockroomSale);

	void getItemAttributes(CreatureObject* player, unsigned long long objectid);

	void getData(CreatureObject* player, int locationType, unsigned long long vendorObjectID, int searchType, unsigned int itemCategory, const UnicodeString& filterText, int minPrice, int maxPrice, bool includeEntranceFee, int count, int offset);

	void getAuctionData(CreatureObject* player, SceneObject* usedVendor, const String& planet, const String& region, SceneObject* vendor, int screen, unsigned int category, const UnicodeString& filterText, int minPrice, int maxPrice, bool includeEntranceFee, int count, int offset);

	int checkRetrieve(CreatureObject* player, unsigned long long objectIdToRetrieve, SceneObject* vendor);

	void retrieveItem(CreatureObject* player, unsigned long long objectid, unsigned long long vendorID);

	void buyItem(CreatureObject* player, unsigned long long objectid, int price1, int price2);

	void doAuctionBid(CreatureObject* player, AuctionItem* item, int price1, int price2);

	void doInstantBuy(CreatureObject* player, AuctionItem* item);

	int checkBidAuction(CreatureObject* player, AuctionItem* item, int price1, int price2);

	void cancelItem(CreatureObject* player, unsigned long long objectID);

	AuctionQueryHeadersResponseMessage* fillAuctionQueryHeadersResponseMessage(CreatureObject* player, SceneObject* vendor, TerminalListVector* terminalList, int screen, unsigned int category, const UnicodeString& filterText, int minPrice, int maxPrice, bool includeEntranceFee, int count, int offset);

	AuctionsMap* getAuctionMap();

	void checkVendorItems(bool startupTask = false);

	void checkAuctions(bool startupTask = false);

	String getVendorUID(SceneObject* vendor);

	void updateVendorUID(SceneObject* vendor, const String& oldUID, const String& newUID);

	void updateVendorSearch(SceneObject* vendor, bool enabled);

	void expireSale(AuctionItem* item);

	void expireBidAuction(AuctionItem* item);

	void expireAuction(AuctionItem* item);

	void deleteExpiredSale(AuctionItem* item);

	bool isMarketEnabled();

	void setMarketEnabled(bool value);

	void displayInfo(CreatureObject* player);

	void updateAuctionOwner(AuctionItem* item, CreatureObject* player);

	String removeColorCodes(const String& name);

	bool checkItemCategory(int category, AuctionItem* item);

	ZoneServer* getZoneServer();

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead() const;

	void _setImplementation(DistributedObjectServant* servant);

protected:
	AuctionManager(DummyConstructorParameter* param);

	virtual ~AuctionManager();

	friend class AuctionManagerHelper;
};

} // namespace auction
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::auction;

namespace server {
namespace zone {
namespace managers {
namespace auction {

class AuctionManagerImplementation : public ManagedServiceImplementation, public Logger {
protected:
	ManagedReference<AuctionsMap* > auctionMap;

	ManagedReference<ZoneServer* > zoneServer;

	AuctionEventsMap auctionEvents;

	VectorMap<ManagedReference<SceneObject* >, String> pendingUIDUpdates;

	VectorMap<ManagedReference<SceneObject* >, String> pendingOldUIDUpdates;

public:
	static const int MAXBAZAARPRICE = 1000000;

	static const int MAXSALES = 100;

	static const int SALESFEE = 20;

	static const int CHECKEVERY = 60;

	static const int MAXVENDORPRICE = 99999999;

	static const int ITEMSPERPAGE = 100;

	static const int VENDOREXPIREPERIOD = 7776000;

	static const int COMMODITYEXPIREPERIOD = 604800;

	static const int LT_GALAXY = 0;

	static const int LT_PLANET = 1;

	static const int LT_REGION = 2;

	static const int LT_MARKET = 3;

	static const int ST_CATEGORY = 0;

	static const int ST_LOCATION = 1;

	static const int ST_ALL = 2;

	static const int ST_PLAYER_SALES = 3;

	static const int ST_PLAYER_BIDS = 4;

	static const int ST_PLAYER_STOCKROOM = 5;

	static const int ST_VENDOR_OFFERS = 6;

	static const int ST_VENDOR_SELLING = 7;

	static const int ST_VENDOR_STOCKROOM = 8;

	static const int ST_PLAYER_OFFERS_TO_VENDOR = 9;

private:
	bool marketEnabled;

public:
	AuctionManagerImplementation(ZoneServer* server);

	AuctionManagerImplementation(DummyConstructorParameter* param);

	void initialize();

	void addSaleItem(CreatureObject* player, unsigned long long objectid, SceneObject* vendor, const UnicodeString& description, int price, unsigned int duration, bool auction, bool premium);

	AuctionItem* createVendorItem(CreatureObject* player, SceneObject* objectToSell, SceneObject* vendor, const UnicodeString& description, int price, unsigned int duration, bool auction, bool premium);

	int checkSaleItem(CreatureObject* player, SceneObject* object, SceneObject* vendor, int price, bool premium, bool stockroomSale);

	void getItemAttributes(CreatureObject* player, unsigned long long objectid);

	void getData(CreatureObject* player, int locationType, unsigned long long vendorObjectID, int searchType, unsigned int itemCategory, const UnicodeString& filterText, int minPrice, int maxPrice, bool includeEntranceFee, int count, int offset);

	void getAuctionData(CreatureObject* player, SceneObject* usedVendor, const String& planet, const String& region, SceneObject* vendor, int screen, unsigned int category, const UnicodeString& filterText, int minPrice, int maxPrice, bool includeEntranceFee, int count, int offset);

private:
	void refundAuction(AuctionItem* item);

	void sendVendorUpdateMail(SceneObject* vendor, bool isEmpty);

public:
	int checkRetrieve(CreatureObject* player, unsigned long long objectIdToRetrieve, SceneObject* vendor);

	void retrieveItem(CreatureObject* player, unsigned long long objectid, unsigned long long vendorID);

	void buyItem(CreatureObject* player, unsigned long long objectid, int price1, int price2);

	void doAuctionBid(CreatureObject* player, AuctionItem* item, int price1, int price2);

	void doInstantBuy(CreatureObject* player, AuctionItem* item);

	int checkBidAuction(CreatureObject* player, AuctionItem* item, int price1, int price2);

	void cancelItem(CreatureObject* player, unsigned long long objectID);

	AuctionQueryHeadersResponseMessage* fillAuctionQueryHeadersResponseMessage(CreatureObject* player, SceneObject* vendor, TerminalListVector* terminalList, int screen, unsigned int category, const UnicodeString& filterText, int minPrice, int maxPrice, bool includeEntranceFee, int count, int offset);

	AuctionsMap* getAuctionMap();

	void checkVendorItems(bool startupTask = false);

	void checkAuctions(bool startupTask = false);

private:
	void doAuctionMaint(TerminalListVector* items, const String& logTag, bool startupTask);

public:
	String getVendorUID(SceneObject* vendor);

	void updateVendorUID(SceneObject* vendor, const String& oldUID, const String& newUID);

	void updateVendorSearch(SceneObject* vendor, bool enabled);

	void expireSale(AuctionItem* item);

	void expireBidAuction(AuctionItem* item);

	void expireAuction(AuctionItem* item);

	void deleteExpiredSale(AuctionItem* item);

	bool isMarketEnabled();

	void setMarketEnabled(bool value);

	void displayInfo(CreatureObject* player);

	void updateAuctionOwner(AuctionItem* item, CreatureObject* player);

	String removeColorCodes(const String& name);

	bool checkItemCategory(int category, AuctionItem* item);

	ZoneServer* getZoneServer();

	WeakReference<AuctionManager*> _this;

	operator const AuctionManager*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~AuctionManagerImplementation();

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

	friend class AuctionManager;
};

class AuctionManagerAdapter : public ManagedServiceAdapter {
public:
	AuctionManagerAdapter(AuctionManager* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initialize();

	void getItemAttributes(CreatureObject* player, unsigned long long objectid);

	void getData(CreatureObject* player, int locationType, unsigned long long vendorObjectID, int searchType, unsigned int itemCategory, const UnicodeString& filterText, int minPrice, int maxPrice, bool includeEntranceFee, int count, int offset);

	void retrieveItem(CreatureObject* player, unsigned long long objectid, unsigned long long vendorID);

	void buyItem(CreatureObject* player, unsigned long long objectid, int price1, int price2);

	void doAuctionBid(CreatureObject* player, AuctionItem* item, int price1, int price2);

	void doInstantBuy(CreatureObject* player, AuctionItem* item);

	int checkBidAuction(CreatureObject* player, AuctionItem* item, int price1, int price2);

	void cancelItem(CreatureObject* player, unsigned long long objectID);

	AuctionsMap* getAuctionMap();

	void checkVendorItems(bool startupTask);

	void checkAuctions(bool startupTask);

	String getVendorUID(SceneObject* vendor);

	void updateVendorUID(SceneObject* vendor, const String& oldUID, const String& newUID);

	void updateVendorSearch(SceneObject* vendor, bool enabled);

	void expireSale(AuctionItem* item);

	void expireBidAuction(AuctionItem* item);

	void expireAuction(AuctionItem* item);

	void deleteExpiredSale(AuctionItem* item);

	bool isMarketEnabled();

	void setMarketEnabled(bool value);

	void displayInfo(CreatureObject* player);

	void updateAuctionOwner(AuctionItem* item, CreatureObject* player);

	String removeColorCodes(const String& name);

	ZoneServer* getZoneServer();

};

class AuctionManagerHelper : public DistributedObjectClassHelper, public Singleton<AuctionManagerHelper> {
	static AuctionManagerHelper* staticInitializer;

public:
	AuctionManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectPOD* instantiatePOD();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<AuctionManagerHelper>;
};

} // namespace auction
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::auction;

namespace server {
namespace zone {
namespace managers {
namespace auction {

class AuctionManagerPOD : public ManagedServicePOD {
public:
	Optional<ManagedReference<AuctionsMapPOD* >> auctionMap;

	Optional<ManagedReference<ZoneServerPOD* >> zoneServer;

	Optional<AuctionEventsMap> auctionEvents;

	Optional<VectorMap<ManagedReference<SceneObjectPOD* >, String>> pendingUIDUpdates;

	Optional<VectorMap<ManagedReference<SceneObjectPOD* >, String>> pendingOldUIDUpdates;

	Optional<bool> marketEnabled;

	String _className;
	AuctionManagerPOD();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
	bool readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode);
	int writeObjectMembers(ObjectOutputStream* stream);
	void writeObjectCompact(ObjectOutputStream* stream);



	virtual ~AuctionManagerPOD();

};

} // namespace auction
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::auction;

#endif /*AUCTIONMANAGERPOD_H_*/
