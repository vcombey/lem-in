#include "lem-in.h"
#include <stdlib.h>

int		room_len(t_room *r)
{
	return ((r == NULL) ? 0 : 1 + room_len(r->next));
}
