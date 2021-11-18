#ifdef RGB_MATRIX_ENABLE

#include "rgb_matrix.h"
#include "config_led.h"

led_config_t g_led_config = {
    {
        {   0,       1,       2,       3,       4,       5,       6,       7,       8,       9,      10,      11,      12,      13,      14,      15 },
        {  16,      17,      18,      19,      20,      21,      22,      23,      24,      25,      26,      27,      28,      29,      30,      31 },
        {  32,      33,      34,      35,      36,      37,      38,      39,      40,      41,      42,      43,      NO_LED,  44,      NO_LED,  NO_LED },
        {  45,      NO_LED,  46,      47,      48,      49,      50,      51,      52,      53,      54,      55,      56,      NO_LED,  57,      NO_LED },
        {  58,      59,      60,      NO_LED,  NO_LED,  NO_LED,  61,      NO_LED,  NO_LED,  NO_LED,  62,      63,      64,      65,      66,      67 }
    },
    {
        {8,    6}, {22,   6}, {35,   6}, {49,   6}, {63,   6}, {77,   6}, {91,   6}, {105,  6}, {119,  6}, {133,  6}, {146,  6}, {160,  6}, {174,  6}, {195,  6}, {202,  6}, {216,  6},
        {11,  19}, {29,  19}, {43,  19}, {56,  19}, {70,  19}, {84,  19}, {98,  19}, {112, 19}, {126, 19}, {140, 19}, {154, 19}, {168, 19}, {181, 19}, {199, 19}, {202, 19}, {216, 19},
        {13,  31}, {32,  31}, {46,  31}, {60,  31}, {73,  31}, {87,  31}, {101, 31}, {115, 31}, {129, 31}, {143, 31}, {157, 31}, {171, 31},            {194, 31},
        {17,  44},            {39,  44}, {53,  44}, {67,  44}, {81,  44}, {95,  44}, {108, 44}, {122, 44}, {136, 44}, {150, 44}, {164, 44}, {188, 44},            {202, 44},
        {9,   56}, {27,  56}, {44,  56},                                  {95,  56},                                  {147, 56}, {161, 56}, {175, 56}, {189, 56}, {202, 56}, {216, 56}
    },
    {
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4,
        4,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4,
        4, 4, 4,          4,          4, 4, 4, 4, 4, 4
    }
};

#endif
