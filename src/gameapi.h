#ifndef INC_1OOM_GAMEAPI_H
#define INC_1OOM_GAMEAPI_H

#include "types.h"

extern bool game_num_patch(const char *numid, const int32_t *patchnums, int first, int num);
extern bool game_str_patch(const char *strid, const char *patchstr, int i);

#endif
