#pragma once

#include <wayland-cutie-shell.h>

#include <wayland-util.h>
#include <QtWaylandClient/QWaylandClientExtensionTemplate>
#include <qwayland-cutie-shell-private.h>

class CutieShellPrivate
	: public QWaylandClientExtensionTemplate<CutieShellPrivate>,
	  public QtWayland::cutie_shell_private {
	Q_OBJECT
	Q_DECLARE_PUBLIC(CutieShell)
    public:
	CutieShellPrivate(CutieShell *q);

    protected:
	void cutie_shell_private_blur(wl_fixed_t opacity) override;
	void cutie_shell_private_key(uint32_t key) override;
	void cutie_shell_private_thumbnail_damage(
		struct ::zwlr_foreign_toplevel_handle_v1 *toplevel);
	double m_blur = 0.0;

    private:
	CutieShell *q_ptr;
};