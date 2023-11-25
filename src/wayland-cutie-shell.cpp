#include "wayland-cutie-shell_p.h"

CutieShell::CutieShell()
    : d_ptr(new CutieShellPrivate(this)) {}

CutieShellPrivate::CutieShellPrivate(CutieShell *q)
    : QWaylandClientExtensionTemplate(1)
    , q_ptr(q) {}

void CutieShell::execApp(const QString &path)
{
    Q_D(CutieShell);
    if (d->isActive()) {
	    d->exec_app(path);
    } else {
        qWarning() << "CutieShell protocol is not activated!";
    }
}

double CutieShell::blur() {
    Q_D(CutieShell);
    return d->m_blur;
}

void CutieShellPrivate::cutie_shell_private_blur(wl_fixed_t opacity) {
    Q_Q(CutieShell);
    if (m_blur == wl_fixed_to_double(opacity)) return;
    m_blur = wl_fixed_to_double(opacity);
    emit q->blurChanged(m_blur);
}