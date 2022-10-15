#ifndef MODESPO.H
#define MODESPO.H

#include "env_vars.h"

void modesPO_init();
void modesPO_set(mode_t mode);
mode_t modesPO_get();

#endif
