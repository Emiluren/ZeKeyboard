#include "water.h"
#include "util.h"
#include <math.h>
#include <Arduino.h>

void convert_colors(LED leds[][Ze::NUM_COLS],
        WaterParticle particles[][WATER_WIDTH], uint64_t it) {
    // TODO finish morph function
}

void copy_particles(WaterParticle main[][WATER_WIDTH],
        WaterParticle copy[][WATER_WIDTH] ) {
    for (uint8_t row = 0; row < WATER_HEIGHT; ++row) {
        for (uint8_t col = 0; col < WATER_WIDTH; ++col) {
            copy[row][col] = main[row][col];
        }
    }
}

void map_leds(LED leds[][Ze::NUM_COLS],
        WaterParticle particles[][WATER_WIDTH]) {

    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        int curr_width = 0;
        int row_index = (int)(row * HEIGHT_UNIT) + HEIGHT_UNIT / 2;
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            if (!leds[row][col].is_dummy()) {
                float width = KEY_WIDTHS[row][col];
                float offset = width * WIDTH_UNIT / 2;
                int index = (int)curr_width + offset;
                leds[row][col].aux = (void*)&particles[row_index][index];
                curr_width += (int)2 * offset;
                particles[row_index][index].used = true;
            }
        }
    }
}

void water_setup(LED leds[][Ze::NUM_COLS],
        WaterParticle particles[][WATER_WIDTH]) {
    for (uint8_t row = 0; row < WATER_HEIGHT; ++row) {
        for (uint8_t col = 0; col < WATER_WIDTH; ++col) {
            particles[row][col] = {0, 0, false};
        }
    }
    map_leds(leds, particles);
}

void water_update(LED leds[][Ze::NUM_COLS], 
        Ze::Board* board, WaterParticle particles[][WATER_WIDTH], uint64_t it) {
    WaterParticle copy[WATER_HEIGHT][WATER_WIDTH];
    copy_particles(particles, copy);

    // TODO update particles and LED:s
}

