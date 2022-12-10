#ifndef APP_H
#define APP_H

#include "../participante/participante.h"
#include "../admin_cursos/admincursos.h"
#include "../admin_recursos/adminrecursos.h"
#include "../ponente/ponente.h"
#include "../visitante/visitante.h"

	void participanteMenu(Participante participante);
	void adminCursosMenu(Admin_Cursos admin);
	void adminRecursosMenu(Admin_Recursos admin);
	void ponenteMenu(Ponente ponente);

	bool ver_info_contacto();

#endif
