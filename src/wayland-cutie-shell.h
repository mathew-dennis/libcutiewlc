#pragma once

#include <QtWaylandClient/QtWaylandClient>
#include <QtQml/QQmlEngine>

class CutieShellPrivate;

class Q_WAYLANDCLIENT_EXPORT CutieShell 
	: public QObject {
	Q_OBJECT
	Q_PROPERTY(double blur READ blur NOTIFY blurChanged)
public:
	enum SpecialKey: uint32_t {
		PowerPress = 0,
		PowerRelease = 1
	};
	Q_ENUM(SpecialKey);

	CutieShell();
	Q_INVOKABLE void execApp(const QString &path);
	double blur();

signals:
	void blurChanged(double opacity);
	void key(SpecialKey key);

private:
	Q_DECLARE_PRIVATE(CutieShell)
	CutieShellPrivate *d_ptr;
};
