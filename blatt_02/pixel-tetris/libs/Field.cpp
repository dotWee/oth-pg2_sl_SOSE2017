//
// Created by Lukas Wolfsteiner on 11.04.17.
//

#include "Field.h"

int Field::pos_x() {
    return pos.getX();
}

int Field::pos_y() {
    return pos.getY();
}

int Field::size_x() {
    return size.getX();
}

int Field::size_y() {
    return size.getY();
}

char Field::getBuffer(XyPair coord) {
    return buffer[coord.getY()][coord.getX()];
}

Field::Field() {
    pos = XyPair(0, 0);
    size = XyPair(FIELD_WIDTH_X - 2, FIELD_HEIGHT_Y - 2);

    // Für jede der 22 Spalten
    for (int y = 0; y <= FIELD_HEIGHT_Y; ++y) {

        // Für jede der 12 Zeilen
        for (int x = 0; x <= FIELD_WIDTH_X; ++x) {

            // Alles über der letzten Zeile
            if (y < FIELD_HEIGHT_Y) {
                switch (x) {
                    // Wenn wir uns am linken äußeren Spielfeldrand befinden...
                    case 0:
                        buffer[y][x] = (char) 124; // '|' 186;
                        break;

                        // Wenn wir uns am rechten äußeren Spielfeldrand befinden...
                    case FIELD_WIDTH_X:
                        buffer[y][x] = (char) 124; // '|' 186;
                        break;

                        // Alle Zeichen zwischen den Rändern
                    default:
                        buffer[y][x] = (char) 32; // ' '
                        break;
                }
            }

                // Wenn wir uns an der letzten Zeile befinden...
            else {
                switch (x) {

                    // Wenn wir uns an der unteren linken Ecke befinden...
                    case 0:
                        buffer[y][x] = (char) 43; // 200;
                        break;

                        // Wenn wir uns an der unteren rechten Ecke befinden...
                    case FIELD_WIDTH_X:
                        buffer[y][x] = (char) 43; // 188;
                        break;

                        // Alle Zeichen zwischen der unteren linken Ecke und der unteren rechten Ecke
                    default:
                        buffer[y][x] = (char) 45; // 205;
                        break;
                }
            }
        }
    }
}