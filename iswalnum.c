#include "dictP.h"

static const int start [] = {
     0,
    48,    65,    97,   170,   181,   186,   192,   216,
   248,   546,   592,   688,   699,   720,   736,   750,
   837,   890,   902,   904,   908,   910,   931,   976,
   986,  1024,  1164,  1223,  1227,  1232,  1272,  1329,
  1369,  1377,  1488,  1520,  1569,  1600,  1632,  1649,
  1749,  1765,  1776,  1808,  1810,  1920,  2309,  2365,
  2384,  2392,  2406,  2437,  2447,  2451,  2474,  2482,
  2486,  2524,  2527,  2534,  2565,  2575,  2579,  2602,
  2610,  2613,  2616,  2649,  2654,  2662,  2674,  2693,
  2701,  2703,  2707,  2730,  2738,  2741,  2749,  2768,
  2784,  2790,  2821,  2831,  2835,  2858,  2866,  2870,
  2877,  2908,  2911,  2918,  2949,  2958,  2962,  2969,
  2972,  2974,  2979,  2984,  2990,  2999,  3047,  3077,
  3086,  3090,  3114,  3125,  3168,  3174,  3205,  3214,
  3218,  3242,  3253,  3294,  3296,  3302,  3333,  3342,
  3346,  3370,  3424,  3430,  3461,  3482,  3507,  3517,
  3520,  3585,  3632,  3648,  3655,  3664,  3713,  3716,
  3719,  3722,  3725,  3732,  3737,  3745,  3749,  3751,
  3754,  3757,  3762,  3773,  3776,  3782,  3792,  3804,
  3840,  3872,  3904,  3913,  3976,  4096,  4131,  4137,
  4160,  4176,  4256,  4304,  4352,  4447,  4520,  4608,
  4616,  4680,  4682,  4688,  4696,  4698,  4704,  4744,
  4746,  4752,  4784,  4786,  4792,  4800,  4802,  4808,
  4816,  4824,  4848,  4880,  4882,  4888,  4896,  4936,
  4969,  5024,  5121,  5743,  5761,  5792,  5870,  6016,
  6112,  6160,  6176,  6272,  7680,  7840,  7936,  7960,
  7968,  8008,  8016,  8025,  8027,  8029,  8031,  8064,
  8118,  8126,  8130,  8134,  8144,  8150,  8160,  8178,
  8182,  8319,  8450,  8455,  8458,  8469,  8473,  8484,
  8486,  8488,  8495,  8499,  8544,  9372, 12293, 12321,
 12337, 12344, 12353, 12445, 12449, 12540, 12549, 12593,
 12704, 13312, 19968, 40960, 44032, 63744, 64256, 64275,
 64285, 64287, 64298, 64312, 64318, 64320, 64323, 64326,
 64467, 64848, 64914, 65008, 65136, 65140, 65142, 65296,
 65313, 65345, 65382, 65474, 65482, 65490, 65498,

/* over BMP */
 66304, 66352, 66560, 66600, 119808,119894,119966,119970,
 119973,119977,119982,119995,119997,120002,120005,120071,
 120077,120086,120094,120123,120128,120134,120138,120146,
 120488,120514,120540,120572,120598,120630,120656,120688,
 120714,120746,120772,120782,131072,194560,
};

static int count [] = {
     0,
    10,    26,    26,     1,     1,     1,    23,    31,
   296,    18,    94,     9,     7,     2,     5,     1,
     1,     1,     1,     3,     1,    20,    44,     8,
    28,   130,    57,     2,     2,    38,     2,    38,
     1,    39,    27,     3,    26,    11,    10,    99,
     1,     2,    13,     1,    27,    38,    53,     1,
     1,    10,    10,     8,     2,    22,     7,     1,
     4,     2,     3,    12,     6,     2,    22,     7,
     2,     2,     2,     4,     1,    10,     3,     7,
     1,     3,    22,     7,     2,     5,     1,     1,
     1,    10,     8,     2,    22,     7,     2,     4,
     1,     2,     3,    10,     6,     3,     4,     2,
     1,     2,     2,     3,     8,     3,     9,     8,
     3,    23,    10,     5,     2,    10,     8,     3,
    23,    10,     5,     1,     2,    10,     8,     3,
    23,    16,     2,    10,    18,    24,     9,     1,
     7,    46,    11,     6,     8,    10,     2,     1,
     2,     1,     1,     4,     7,     3,     1,     1,
     2,     4,     2,     1,     5,     1,    10,     2,
     1,    10,     8,    34,     4,    34,     5,     2,
    10,     6,    38,    39,    90,    68,    82,     7,
    63,     1,     4,     7,     1,     4,    39,     1,
     4,    31,     1,     4,     7,     1,     4,     7,
     7,    23,    31,     1,     4,     7,    39,    19,
     9,    85,   620,     8,    26,    75,     3,    52,
    10,    10,    88,    41,   156,    90,    22,     6,
    38,     6,     8,     1,     1,     1,    31,    53,
     7,     1,     3,     7,     4,     6,    13,     3,
     7,     1,     1,     1,    10,     1,     5,     1,
     1,     6,     3,     7,    36,    78,     3,     9,
     5,     3,    84,     2,    90,     3,    40,    94,
    24,  6582, 20902,  1165, 11172,   302,     7,     5,
     1,    10,    13,     5,     1,     2,     2,   108,
   363,    64,    54,    12,     3,     1,   135,    10,
    26,    26,    89,     6,     6,     6,     3,

/* over BMP */
     31,   27,    38,    38,    85,    71,     2,     1,
     2,     4,    12,     1,     4,     2,    65,     4,
     8,     7,    28,     4,     5,     1,     7,   338,
     25,   25,    31,    25,    31,    25,    31,    25,
     31,   25,     6,    50, 42711,   542,
};

#define ARRAY_SIZE (sizeof (start) / sizeof (start [0]))

int iswalnum__ (wint_t wc);

int iswalnum__ (wint_t wc)
{
   const int *l = start;
   const int *r = start + ARRAY_SIZE;
   const int *s = NULL;

   if (wc < 0)
      return 0;

   while (l < r) {
      s = l + ((r - l) >> 1);

      if (*s <= wc){
	 l = s + 1;
      }else{
	 r = s;
      }
   }

   --l;

   if (wc < l [0] + count [l - start])
      return 1;
   else
      return 0;
}
