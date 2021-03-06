#ifndef TAPPSETTINGS_H
#define TAPPSETTINGS_H

#include <TGlobal>
#include <QMap>
#include <QVariant>
#include <QMutex>

class QSettings;


class T_CORE_EXPORT TAppSettings
{
public:
    QVariant value(Tf::AppAttribute attr, const QVariant &defaultValue = QVariant()) const;
    QVariant readValue(const QString &attr, const QVariant &defaultValue = QVariant()) const;
    static TAppSettings *instance();

private:
    TAppSettings(const QString &path);
    static void instantiate(const QString &path);

    mutable QMutex mutex;
    mutable QMap<int, QVariant> settingsCache;
    QSettings *appIniSettings {nullptr};

    friend class TWebApplication;
    T_DISABLE_COPY(TAppSettings)
    T_DISABLE_MOVE(TAppSettings)
};
#endif // TAPPSETTINGS_H
