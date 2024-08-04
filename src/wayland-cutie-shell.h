#pragma once

#include <qt6-foreign-toplevel-management.h>
#include <qt6-screencopy.h>

#include <QtWaylandClient/QtWaylandClient>
#include <QtQml/QQmlEngine>

class CutieShellPrivate;

class Q_WAYLANDCLIENT_EXPORT CutieShell : public QObject {
	Q_OBJECT
	Q_PROPERTY(double blur READ blur NOTIFY blurChanged)
    public:
	enum SpecialKey : uint32_t {
		PowerPress = 0,
		PowerRelease = 1,
		VolumeUpPress = 2,
		VolumeUpRelease = 3,
		VolumeDownPress = 4,
		VolumeDownRelease = 5
	};
	Q_ENUM(SpecialKey);

	CutieShell();
	Q_INVOKABLE void execApp(const QString &path);
	Q_INVOKABLE ScreencopyFrameV1 *
	getThumbnail(ForeignToplevelHandleV1 *toplevel);
	double blur();

    signals:
	void blurChanged(double opacity);
	void key(SpecialKey key);
	void thumbnailDamage(void *object);

    private:
	Q_DECLARE_PRIVATE(CutieShell)
	CutieShellPrivate *d_ptr;
};
