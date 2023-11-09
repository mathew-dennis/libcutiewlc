#pragma once

#include <QtWaylandClient/QtWaylandClient>
#include <QtQml/QQmlEngine>

class CutieShellPrivate;

class Q_WAYLANDCLIENT_EXPORT CutieShell 
	: public QObject {
	Q_OBJECT
public:
	CutieShell();
	Q_INVOKABLE void execApp(const QString &path);
private:
	CutieShellPrivate* d;
};
