#ifndef ROSTERITEM_H
#define ROSTERITEM_H

#include <QObject>
#include <QQmlEngine>

class RosterItem : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
	Q_PROPERTY(QString jid READ getJid WRITE setJid NOTIFY jidChanged)
	Q_PROPERTY(Subscription subscription READ getSubscription WRITE setSubscription NOTIFY subscriptionChanged)
    Q_PROPERTY(Availability availability READ getAvailability WRITE setAvailability NOTIFY availabilityChanged)
    Q_PROPERTY(QString status READ getStatus WRITE setStatus NOTIFY statusChanged)

public:

    enum Subscription
    {
        SUBSCRIPTION_NONE,
        SUBSCRIPTION_TO,
        SUBSCRIPTION_FROM,
        SUBSCRIPTION_BOTH
    };
    Q_ENUMS(Subscription)

    enum Availability
    {
        AVAILABILITY_UNKNOWN,
        AVAILABILITY_ONLINE,
        AVAILABILITY_OFFLINE
    };
    Q_ENUMS(Availability)

	explicit RosterItem(QObject *parent = 0);
	RosterItem(const QString& jid, const QString& name, const Subscription& subscription, QObject* parent = 0);

	QString getName();
	void setName(const QString& name);

	QString getJid();
	void setJid(const QString& jid);

	Subscription getSubscription();
	void setSubscription(const Subscription& subscription);

    Availability getAvailability();
    void setAvailability(const Availability& availability);

    QString getStatus();
    void setStatus(const QString& status);

signals:
	void nameChanged();
	void jidChanged();
	void subscriptionChanged();
    void availabilityChanged();
    //void isOnlineChanged();
    void statusChanged();

public slots:

private:
	QString jid_;
	QString name_;
	Subscription subscription_;
    Availability availability_;
    QString status_;
};

#endif // ROSTERITEM_H
