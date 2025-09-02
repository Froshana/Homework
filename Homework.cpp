// Завдання 1 //

RoadSegment - відрізок дороги між розв'язкою.
Lane - смуга руху.
Intersection — вузол з 4 під’їздами.
Crosswalk — пішохідний перехід.
TrafficLightController - керування трафіком світлофора.
SignalPhase - Green/Yellow/Red.
PedSignal — стан пішохідного сигналу (Walk/Don’tWalk).
Vehicle - автомобілі.
Pedestrian - пішшохід.
Detector - лічильники/датчики на стоп-лініях та на виходах.
Metrics - збирає середню затримку або дісперсію интервалів між авто.
Simulation — часова петля tick(dt).
 
struct Agent { virtual void step(double dt) = 0; virtual ~Agent() = default; };

class Vehicle : public Agent {
  // pos, speed, lane*, desiredSpeed...
  void step(double dt) override;
};

class Pedestrian : public Agent {
  // pos, speed, targetCrosswalk...
  void step(double dt) override;
};

enum class Light { Green, Yellow, Red };
struct SignalPhase { Light state; double duration; };

class TrafficLightController {
public:
  void setPlan(/*cycle, splits, offsets*/);
  void update(double t);
  Light phaseFor(int approach) const;
};

class Simulation {
  std::vector<std::unique_ptr<Agent>> agents;
  TrafficLightController tlc;
public:
  void tick(double dt);
};

// Завдання 2 //

Додавання різної поведінки водіїв

struct DriverBehavior {
  virtual double desiredSpeed() const = 0;
  virtual double headway() const = 0;            
  virtual double reactionTime() const = 0;
  virtual bool willRunRed(const TrafficLightController&) const = 0;
  virtual ~DriverBehavior() = default;
};

struct TaxiBehavior : DriverBehavior { /* агресивні параметри + p_run_red */ };
struct NonLocalBehavior : DriverBehavior { /* повільні/обережні */ };
struct LocalAdaptiveBehavior : DriverBehavior { double coolness; /* адаптація */ };

class Vehicle : public Agent {
  std::unique_ptr<DriverBehavior> behavior;
  void step(double dt) override;}

  Пішоходи
 struct PedBehavior {
 virtual bool willCrossHere(const Crosswalk& cw, /*позиція*/) const = 0;
virtual bool obeysSignal(const PedSignal& ps) const = 0;
  virtual double walkSpeed() const = 0;
  virtual ~PedBehavior() = default;
 };

struct LocalPed : PedBehavior { /* jaywalk prob > 0, obeysSignal=false інколи */ };
struct TouristPed : PedBehavior { /* obeysSignal=true, walkSpeed нижчий */ };

class Pedestrian : public Agent {
std::unique_ptr<PedBehavior> behavior;
  void step(double dt) override;
};

Велосипедисти (ненавиджу)
struct CyclistBehavior {
  virtual bool  asVehicleNow(/*context*/) const = 0; // перемикач режиму
  virtual double speedVehicleMode() const = 0;
  virtual double speedPedMode() const = 0;
 virtual ~CyclistBehavior() = default;
};

class Cyclist : public Agent {
std::unique_ptr<CyclistBehavior> behavior;
void step(double dt) override; // перемикання режимів і рух
};

// Завдання 3 //

Основні підсистеми для затосунку, який планує конференції та зустрічі
ЯДРО
Управління подіями та календарями :
Події: зустрічі, конференції тощо.
Програма подій: доповіді, спікери зали.
Приміщення: зали, переговорки інше.
Планувальник розкладу: букати час та подію.
Оптимізація людей, подій, їжі.
Реєстрація учасників та слухачів(VIP, співорбітників, персоналу).
Бронювання: бронювання готелю, подій, автозахват бронювання, якщо хтось відмовиться від участі/слухання
Платежі: рахунки, оплата, повернення.
Верификація: смс, по номеру, по пошті тощо.
Інтеграція: в гугл календар тощо.
Кабінети: учасника, відвідувача, організатора тощо.
АНАЛІТИКА
Аналітика: завантаження залів, скількі зареєстровано відвідувачів та спікерів на різні події, зміна броней, оплата кеш або кредитка тощо.
ПІДСИСТЕМИ
пошук по фільтрах подій та готелю.
Відстежування потрібних подій.
Нагадування про подію.
Локалізація для різних країн та валют.
Сховище данних: кеш(не гроші), SQL, штуки для аналітики.

// Завдання 4 //
#pragma once
#include <string>
#include <vector>
#include <optional>

namespace conf {

// ---- Мінімальні типи для сигнатур ----
using Id = std::string;
struct TimeRange { std::string startISO; std::string endISO; };
struct Money { std::string currency; long long minor = 0; }; // 12345 => 123.45

// ========== ЯДРО ==========

// Управління подіями та календарями
struct IEventCalendar {
    virtual ~IEventCalendar() = default;
    virtual Id    createEvent(const std::string& title, const std::string& tz) = 0;
    virtual bool  updateEvent(const Id& eventId, const std::string& title) = 0;
    virtual bool  deleteEvent(const Id& eventId) = 0;
    virtual bool  setEventTime(const Id& eventId, const TimeRange& when) = 0;
    virtual bool  addToCalendar(const Id& eventId, const Id& calendarId) = 0;
};

// Програма подій: доповіді, спікери, зали
struct IProgram {
    virtual ~IProgram() = default;
    virtual Id   addTalk(const Id& eventId, const std::string& title, const Id& speakerId, const Id& hallId, const TimeRange& slot) = 0;
    virtual bool updateTalk(const Id& talkId, const std::string& title) = 0;
    virtual bool moveTalk(const Id& talkId, const Id& hallId, const TimeRange& slot) = 0;
    virtual Id   addSpeaker(const std::string& name) = 0;
    virtual Id   addHall(const std::string& name, int capacity) = 0;
};

// Приміщення: зали, переговорки інше
struct IRooms {
    virtual ~IRooms() = default;
    virtual Id   createRoom(const std::string& name, int capacity) = 0;
    virtual bool setEquipment(const Id& roomId, const std::vector<std::string>& items) = 0;
    virtual bool blockRoom(const Id& roomId, const TimeRange& when, const std::string& reason) = 0;
};

// Планувальник розкладу: букати час та подію
struct ISchedulePlanner {
    virtual ~ISchedulePlanner() = default;
    virtual std::vector<TimeRange> findFreeSlots(const Id& roomId, int minMinutes) const = 0;
    virtual bool  bookSlot(const Id& eventId, const Id& roomId, const TimeRange& slot) = 0;
    virtual bool  reschedule(const Id& eventId, const TimeRange& newSlot) = 0;
};

// Оптимізація людей, подій, їжі
struct IOptimization {
    virtual ~IOptimization() = default;
    virtual bool optimizePeoplePlacement(const Id& eventId) = 0;
    virtual bool optimizeAgenda(const Id& eventId) = 0;
    virtual bool optimizeCatering(const Id& eventId) = 0;
};

// Реєстрація учасників та слухачів (VIP, співробітників, персоналу)
struct IRegistration {
    virtual ~IRegistration() = default;
    virtual Id   registerAttendee(const Id& eventId, const std::string& name, const std::string& role /*VIP/Employee/Staff/Listener*/) = 0;
    virtual bool cancelRegistration(const Id& eventId, const Id& attendeeId) = 0;
    virtual std::vector<Id> listAttendees(const Id& eventId, const std::optional<std::string>& roleFilter = std::nullopt) const = 0;
};

// Бронювання: бронювання подій, автозахват при відмові
struct IBooking {
    virtual ~IBooking() = default;
    virtual Id   bookSeat(const Id& eventId, const Id& attendeeId) = 0;
    virtual bool cancelSeat(const Id& bookingId) = 0;
    virtual bool enableAutoCaptureOnCancel(const Id& eventId, bool enable) = 0; // “автозахват бронювання”
};

// Платежі: рахунки, оплата, повернення
struct IPayments {
    virtual ~IPayments() = default;
    virtual Id   createInvoice(const Id& attendeeId, const Money& total) = 0;
    virtual bool payInvoice(const Id& invoiceId, const std::string& method /*cash/card*/)=0;
    virtual bool refund(const Id& invoiceId, const Money& amount) = 0;
};

// Верифікація: SMS, по номеру, по пошті
struct IVerification {
    virtual ~IVerification() = default;
    virtual bool sendSMSCode(const std::string& phone) = 0;
    virtual bool verifySMSCode(const std::string& phone, const std::string& code) = 0;
    virtual bool sendEmailLink(const std::string& email) = 0;
    virtual bool verifyEmailToken(const std::string& token) = 0;
};

// Інтеграція: в Google Календар тощо
struct IIntegrations {
    virtual ~IIntegrations() = default;
    virtual bool connectGoogleCalendar(const Id& userId, const std::string& oauthToken) = 0;
    virtual bool syncEventToGoogle(const Id& userId, const Id& eventId) = 0;
};

// Кабінети: учасника, відвідувача, організатора
struct IParticipantCabinet {
    virtual ~IParticipantCabinet() = default;
    virtual std::vector<Id> myEvents(const Id& userId) const = 0;
    virtual bool            updateProfile(const Id& userId, const std::string& name) = 0;
};
struct IVisitorCabinet {
    virtual ~IVisitorCabinet() = default;
    virtual std::vector<Id> recommendedEvents(const Id& userId) const = 0;
};
struct IOrganizerCabinet {
    virtual ~IOrganizerCabinet() = default;
    virtual std::vector<Id> managedEvents(const Id& orgUserId) const = 0;
    virtual bool            publishEvent(const Id& eventId) = 0;
};

// ========== АНАЛІТИКА ==========
struct IAnalytics {
    virtual ~IAnalytics() = default;
    virtual int  hallLoad(const Id& hallId, const TimeRange& range) const = 0; // %
    virtual int  attendeesCount(const Id& eventId) const = 0;
    virtual int  speakersCount(const Id& eventId) const = 0;
    virtual int  bookingChanges(const Id& eventId) const = 0;
    virtual std::pair<int,int> paymentSplitCashCard(const Id& eventId) const = 0; // {cash, card}
};

// ========== ПІДСИСТЕМИ ==========
struct ISearch {
    struct Filter {
        std::optional<std::string> text;
        std::optional<std::string> hall;
        std::optional<std::string> speaker;
        std::optional<std::string> dateISO;
    };
    virtual ~ISearch() = default;
    virtual std::vector<Id> events(const Filter& f) const = 0; // пошук по фільтрах
};

struct IWatchlist {
    virtual ~IWatchlist() = default;
    virtual bool watch(const Id& userId, const Id& eventId) = 0;      // відстежування потрібних подій
    virtual bool unwatch(const Id& userId, const Id& eventId) = 0;
    virtual std::vector<Id> list(const Id& userId) const = 0;
};

struct IReminders {
    virtual ~IReminders() = default;
    virtual bool schedule(const Id& userId, const Id& eventId, const std::string& whenISO) = 0; // нагадування
    virtual bool cancel(const Id& userId, const Id& eventId) = 0;
};

struct ILocalization {
    virtual ~ILocalization() = default;
    virtual bool  setLocale(const Id& userId, const std::string& locale, const std::string& currency) = 0;
    virtual std::string formatMoney(const Money& m, const std::string& locale) const = 0;
};

// Сховище даних: кеш, SQL, штуки для аналітики
struct ICacheStore {
    virtual ~ICacheStore() = default;
    virtual void put(const std::string& key, const std::string& val, int ttlSec) = 0;
    virtual std::optional<std::string> get(const std::string& key) const = 0;
};

struct ISqlStore {
    virtual ~ISqlStore() = default;
    virtual bool exec(const std::string& sql) = 0;
    virtual std::vector<std::vector<std::string>> query(const std::string& sql) const = 0;
};

struct IAnalyticsStore {
    virtual ~IAnalyticsStore() = default;
    virtual bool appendEvent(const std::string& topic, const std::string& jsonPayload) = 0;
};

} 
// ==== ГОТЕЛЬ: типи ====

struct Stay {
    std::string checkInISO;   // напр. "2025-09-12"
    std::string checkOutISO;  // напр. "2025-09-15"
    int adults{1};
    int children{0};
};

struct HotelRoomType {
    Id id;
    std::string name;                 // "Deluxe King"
    int capacity{2};
    std::vector<std::string> features; // Wi-Fi, SeaView, ...
};

struct HotelRoom {
    Id id;
    Id roomTypeId;
    std::string number;               // "305"
};

struct HotelRatePlan {
    Id id;
    std::string name;                 // "BAR", "Non-Refundable", ...
    std::string currency{"USD"};
    bool prepaid{false};
};

struct HotelQuote {
    Money roomAmount;  // базова вартість
    Money taxes;       // податки/збори
    Money total;       // підсумок
    std::string currency;
    Id ratePlanId;
};

enum class HotelResStatus { Hold, Confirmed, Cancelled };

struct HotelReservation {
    Id id;
    Id guestId;
    Stay stay;
    Id roomTypeId;
    std::optional<Id> assignedRoom;   // може бути призначена пізніше
    Id ratePlanId;
    HotelResStatus status{HotelResStatus::Hold};
    Money total;
    Money paid;
    std::string notes;
};

// ==== Пошук кімнат у готелі по фільтрах ====

struct IHotelSearch {
    struct Filter {
        Stay stay;
        int rooms{1};
        int minCapacity{1};
        std::vector<std::string> requiredFeatures; // напр.: {"Wi-Fi","SeaView"}
        std::optional<std::string> currency;       // бажана валюта котирування
        std::optional<std::string> promo;          // промокод
    };
    struct Option {
        HotelRoomType roomType;
        HotelRatePlan ratePlan;
        HotelQuote    quote;
        int available; // скільки номерів доступно під ці умови
    };

    virtual ~IHotelSearch() = default;
    virtual std::vector<Option> search(const Filter& f) const = 0;
};

// ==== Бронювання готелю ====

struct IHotelBooking {
    virtual ~IHotelBooking() = default;

    // Створити тимчасове бронювання (hold) під оплату/підтвердження
    virtual Id createHold(const Id& guestId,
                          const Id& roomTypeId,
                          const Id& ratePlanId,
                          const Stay& stay,
                          int rooms = 1,
                          std::optional<std::string> promo = std::nullopt,
                          const std::string& holdExpiresISO = "") = 0;

    // Підтвердити бронювання (після оплати)
    virtual bool confirm(const Id& reservationId) = 0;

    // Скасування бронювання
    virtual bool cancel(const Id& reservationId) = 0;

    // Опціонально призначити конкретну кімнату
    virtual bool assignRoom(const Id& reservationId, const Id& roomId) = 0;

    // Отримати стан бронювання
    virtual std::optional<HotelReservation> get(const Id& reservationId) const = 0;
};

// ==== Оплата готелю ====

struct IHotelPayments {
    virtual ~IHotelPayments() = default;

    // Створити рахунок до конкретної резервації
    virtual Id   createInvoice(const Id& reservationId, const Money& total) = 0;

    // Оплатити (cash|card|bank)
    virtual bool pay(const Id& invoiceId, const std::string& method) = 0;

    // Повернення коштів
    virtual bool refund(const Id& invoiceId, const Money& amount) = 0;
};


