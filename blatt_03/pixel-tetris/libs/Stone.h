//
// Created by Lukas Wolfsteiner on 11.04.17.
//

#ifndef PG2_SL_SOSE2017_STONE_H
#define PG2_SL_SOSE2017_STONE_H


#include "XyPair.h"

#define STONE_DIMENSION_DEFAULT 4

class Stone {

private:

    // Enthält Daten über Form des Spielsteines
    char buffer[STONE_DIMENSION_DEFAULT][STONE_DIMENSION_DEFAULT];

    // Position als Offset im Spielfeld
    XyPair pos = XyPair(0, 0);

    // Size als Größe der Dimension des Arrays Buffer
    XyPair size = XyPair(STONE_DIMENSION_DEFAULT, STONE_DIMENSION_DEFAULT);

public:
    Stone();

    /**
     * @return X-Wert der XyPair Variable pos
     */
    int pos_x();

    /**
     * @return Y-Wert der XyPair Variable pos
     */
    int pos_y();

    /**
     * @return X-Wert der XyPair Variable size
     */
    int size_x();

    /**
     * @return Y-Wert der XyPair Variable size
     */
    int size_y();

    /**
     * Gibt Inhalt des Buffers anhand XyPair-Koordinaten zurück
     * @param coord Position im Buffer
     *
     * @return Inhalt des Buffers
     */
    char getBuffer(XyPair coord);
};


#endif //PG2_SL_SOSE2017_STONE_H
