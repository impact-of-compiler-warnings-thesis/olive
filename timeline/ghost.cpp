#include "ghost.h"

Selection Ghost::ToSelection() const
{
  return Selection(in, out, track);
}
