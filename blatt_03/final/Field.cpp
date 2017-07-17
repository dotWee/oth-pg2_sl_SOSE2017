#include "Field.h"

Field::Field(xy_pair pos, Stone *currStone, Stone *nextStone) : pos(pos), currStone(currStone), nextStone(nextStone) {
}

Field::~Field() {
}
