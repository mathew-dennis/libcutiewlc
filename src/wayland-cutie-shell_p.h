#pragma once

#include <wayland-cutie-shell.h>

#include <wayland-util.h>
#include <QtWaylandClient/QWaylandClientExtensionTemplate>
#include <qwayland-cutie-shell-private.h>

class CutieShellPrivate
	: public QWaylandClientExtensionTemplate<CutieShellPrivate>
	, public QtWayland::cutie_shell_private {
public:
	CutieShellPrivate(CutieShell *q);
private:
	CutieShell* q;
};