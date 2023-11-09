#include "wayland-cutie-shell_p.h"

CutieShell::CutieShell()
    : d(new CutieShellPrivate(this)) {}

CutieShellPrivate::CutieShellPrivate(CutieShell *q)
    : QWaylandClientExtensionTemplate(1)
    , q(q) {}

void CutieShell::execApp(const QString &path)
{
    if (d->isActive()) {
	    d->exec_app(path);
    } else {
        qWarning() << "CutieShell protocol is not activated!";
    }
}