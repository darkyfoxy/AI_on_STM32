/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Tue Nov 23 15:47:02 2021
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */


#include "network.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



/*
#define AI_TOOLS_VERSION_MAJOR 6
#define AI_TOOLS_VERSION_MINOR 0
#define AI_TOOLS_VERSION_MICRO 0
#define AI_TOOLS_VERSION_EXTRA "RC6"

*/

/*
#define AI_TOOLS_API_VERSION_MAJOR 1
#define AI_TOOLS_API_VERSION_MINOR 4
#define AI_TOOLS_API_VERSION_MICRO 0
*/

#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network
 
#undef AI_NETWORK_MODEL_SIGNATURE
#define AI_NETWORK_MODEL_SIGNATURE     "d5e0368d26f3d6bf9a8e8a6cbe6b2758"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Tue Nov 23 15:47:02 2021"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array input_output_array;   /* Array #0 */
AI_STATIC ai_array conv2d_0_output_array;   /* Array #1 */
AI_STATIC ai_array conv2d_1_output_array;   /* Array #2 */
AI_STATIC ai_array conv2d_2_output_array;   /* Array #3 */
AI_STATIC ai_array conv2d_3_output_array;   /* Array #4 */
AI_STATIC ai_array conv2d_4_output_array;   /* Array #5 */
AI_STATIC ai_array conv2d_5_output_array;   /* Array #6 */
AI_STATIC ai_array conv2d_6_output_array;   /* Array #7 */
AI_STATIC ai_array conv2d_7_output_array;   /* Array #8 */
AI_STATIC ai_array conv2d_8_output_array;   /* Array #9 */
AI_STATIC ai_array conv2d_9_output_array;   /* Array #10 */
AI_STATIC ai_array conv2d_10_output_array;   /* Array #11 */
AI_STATIC ai_array conv2d_11_output_array;   /* Array #12 */
AI_STATIC ai_array conv2d_12_output_array;   /* Array #13 */
AI_STATIC ai_array conv2d_13_output_array;   /* Array #14 */
AI_STATIC ai_array conv2d_14_output_array;   /* Array #15 */
AI_STATIC ai_array conv2d_15_output_array;   /* Array #16 */
AI_STATIC ai_array conv2d_16_output_array;   /* Array #17 */
AI_STATIC ai_array conv2d_17_output_array;   /* Array #18 */
AI_STATIC ai_array conv2d_18_output_array;   /* Array #19 */
AI_STATIC ai_array conv2d_19_output_array;   /* Array #20 */
AI_STATIC ai_array conv2d_20_output_array;   /* Array #21 */
AI_STATIC ai_array conv2d_21_output_array;   /* Array #22 */
AI_STATIC ai_array conv2d_22_output_array;   /* Array #23 */
AI_STATIC ai_array conv2d_23_output_array;   /* Array #24 */
AI_STATIC ai_array conv2d_24_output_array;   /* Array #25 */
AI_STATIC ai_array conv2d_25_output_array;   /* Array #26 */
AI_STATIC ai_array conv2d_26_output_array;   /* Array #27 */
AI_STATIC ai_array conv2d_28_output_array;   /* Array #28 */
AI_STATIC ai_array reshape_29_fmt_output_array;   /* Array #29 */
AI_STATIC ai_array nl_30_output_array;   /* Array #30 */
AI_STATIC ai_array nl_30_fmt_output_array;   /* Array #31 */
AI_STATIC ai_array conv2d_0_weights_array;   /* Array #32 */
AI_STATIC ai_array conv2d_0_bias_array;   /* Array #33 */
AI_STATIC ai_array conv2d_1_weights_array;   /* Array #34 */
AI_STATIC ai_array conv2d_1_bias_array;   /* Array #35 */
AI_STATIC ai_array conv2d_2_weights_array;   /* Array #36 */
AI_STATIC ai_array conv2d_2_bias_array;   /* Array #37 */
AI_STATIC ai_array conv2d_3_weights_array;   /* Array #38 */
AI_STATIC ai_array conv2d_3_bias_array;   /* Array #39 */
AI_STATIC ai_array conv2d_4_weights_array;   /* Array #40 */
AI_STATIC ai_array conv2d_4_bias_array;   /* Array #41 */
AI_STATIC ai_array conv2d_5_weights_array;   /* Array #42 */
AI_STATIC ai_array conv2d_5_bias_array;   /* Array #43 */
AI_STATIC ai_array conv2d_6_weights_array;   /* Array #44 */
AI_STATIC ai_array conv2d_6_bias_array;   /* Array #45 */
AI_STATIC ai_array conv2d_7_weights_array;   /* Array #46 */
AI_STATIC ai_array conv2d_7_bias_array;   /* Array #47 */
AI_STATIC ai_array conv2d_8_weights_array;   /* Array #48 */
AI_STATIC ai_array conv2d_8_bias_array;   /* Array #49 */
AI_STATIC ai_array conv2d_9_weights_array;   /* Array #50 */
AI_STATIC ai_array conv2d_9_bias_array;   /* Array #51 */
AI_STATIC ai_array conv2d_10_weights_array;   /* Array #52 */
AI_STATIC ai_array conv2d_10_bias_array;   /* Array #53 */
AI_STATIC ai_array conv2d_11_weights_array;   /* Array #54 */
AI_STATIC ai_array conv2d_11_bias_array;   /* Array #55 */
AI_STATIC ai_array conv2d_12_weights_array;   /* Array #56 */
AI_STATIC ai_array conv2d_12_bias_array;   /* Array #57 */
AI_STATIC ai_array conv2d_13_weights_array;   /* Array #58 */
AI_STATIC ai_array conv2d_13_bias_array;   /* Array #59 */
AI_STATIC ai_array conv2d_14_weights_array;   /* Array #60 */
AI_STATIC ai_array conv2d_14_bias_array;   /* Array #61 */
AI_STATIC ai_array conv2d_15_weights_array;   /* Array #62 */
AI_STATIC ai_array conv2d_15_bias_array;   /* Array #63 */
AI_STATIC ai_array conv2d_16_weights_array;   /* Array #64 */
AI_STATIC ai_array conv2d_16_bias_array;   /* Array #65 */
AI_STATIC ai_array conv2d_17_weights_array;   /* Array #66 */
AI_STATIC ai_array conv2d_17_bias_array;   /* Array #67 */
AI_STATIC ai_array conv2d_18_weights_array;   /* Array #68 */
AI_STATIC ai_array conv2d_18_bias_array;   /* Array #69 */
AI_STATIC ai_array conv2d_19_weights_array;   /* Array #70 */
AI_STATIC ai_array conv2d_19_bias_array;   /* Array #71 */
AI_STATIC ai_array conv2d_20_weights_array;   /* Array #72 */
AI_STATIC ai_array conv2d_20_bias_array;   /* Array #73 */
AI_STATIC ai_array conv2d_21_weights_array;   /* Array #74 */
AI_STATIC ai_array conv2d_21_bias_array;   /* Array #75 */
AI_STATIC ai_array conv2d_22_weights_array;   /* Array #76 */
AI_STATIC ai_array conv2d_22_bias_array;   /* Array #77 */
AI_STATIC ai_array conv2d_23_weights_array;   /* Array #78 */
AI_STATIC ai_array conv2d_23_bias_array;   /* Array #79 */
AI_STATIC ai_array conv2d_24_weights_array;   /* Array #80 */
AI_STATIC ai_array conv2d_24_bias_array;   /* Array #81 */
AI_STATIC ai_array conv2d_25_weights_array;   /* Array #82 */
AI_STATIC ai_array conv2d_25_bias_array;   /* Array #83 */
AI_STATIC ai_array conv2d_26_weights_array;   /* Array #84 */
AI_STATIC ai_array conv2d_26_bias_array;   /* Array #85 */
AI_STATIC ai_array conv2d_28_weights_array;   /* Array #86 */
AI_STATIC ai_array conv2d_28_bias_array;   /* Array #87 */
AI_STATIC ai_array conv2d_0_scratch0_array;   /* Array #88 */
AI_STATIC ai_array conv2d_0_scratch1_array;   /* Array #89 */
AI_STATIC ai_array conv2d_1_scratch0_array;   /* Array #90 */
AI_STATIC ai_array conv2d_1_scratch1_array;   /* Array #91 */
AI_STATIC ai_array conv2d_2_scratch0_array;   /* Array #92 */
AI_STATIC ai_array conv2d_2_scratch1_array;   /* Array #93 */
AI_STATIC ai_array conv2d_3_scratch0_array;   /* Array #94 */
AI_STATIC ai_array conv2d_3_scratch1_array;   /* Array #95 */
AI_STATIC ai_array conv2d_4_scratch0_array;   /* Array #96 */
AI_STATIC ai_array conv2d_4_scratch1_array;   /* Array #97 */
AI_STATIC ai_array conv2d_5_scratch0_array;   /* Array #98 */
AI_STATIC ai_array conv2d_5_scratch1_array;   /* Array #99 */
AI_STATIC ai_array conv2d_6_scratch0_array;   /* Array #100 */
AI_STATIC ai_array conv2d_6_scratch1_array;   /* Array #101 */
AI_STATIC ai_array conv2d_7_scratch0_array;   /* Array #102 */
AI_STATIC ai_array conv2d_7_scratch1_array;   /* Array #103 */
AI_STATIC ai_array conv2d_8_scratch0_array;   /* Array #104 */
AI_STATIC ai_array conv2d_8_scratch1_array;   /* Array #105 */
AI_STATIC ai_array conv2d_9_scratch0_array;   /* Array #106 */
AI_STATIC ai_array conv2d_9_scratch1_array;   /* Array #107 */
AI_STATIC ai_array conv2d_10_scratch0_array;   /* Array #108 */
AI_STATIC ai_array conv2d_10_scratch1_array;   /* Array #109 */
AI_STATIC ai_array conv2d_11_scratch0_array;   /* Array #110 */
AI_STATIC ai_array conv2d_11_scratch1_array;   /* Array #111 */
AI_STATIC ai_array conv2d_12_scratch0_array;   /* Array #112 */
AI_STATIC ai_array conv2d_12_scratch1_array;   /* Array #113 */
AI_STATIC ai_array conv2d_13_scratch0_array;   /* Array #114 */
AI_STATIC ai_array conv2d_13_scratch1_array;   /* Array #115 */
AI_STATIC ai_array conv2d_14_scratch0_array;   /* Array #116 */
AI_STATIC ai_array conv2d_14_scratch1_array;   /* Array #117 */
AI_STATIC ai_array conv2d_15_scratch0_array;   /* Array #118 */
AI_STATIC ai_array conv2d_15_scratch1_array;   /* Array #119 */
AI_STATIC ai_array conv2d_16_scratch0_array;   /* Array #120 */
AI_STATIC ai_array conv2d_16_scratch1_array;   /* Array #121 */
AI_STATIC ai_array conv2d_17_scratch0_array;   /* Array #122 */
AI_STATIC ai_array conv2d_17_scratch1_array;   /* Array #123 */
AI_STATIC ai_array conv2d_18_scratch0_array;   /* Array #124 */
AI_STATIC ai_array conv2d_18_scratch1_array;   /* Array #125 */
AI_STATIC ai_array conv2d_19_scratch0_array;   /* Array #126 */
AI_STATIC ai_array conv2d_19_scratch1_array;   /* Array #127 */
AI_STATIC ai_array conv2d_20_scratch0_array;   /* Array #128 */
AI_STATIC ai_array conv2d_20_scratch1_array;   /* Array #129 */
AI_STATIC ai_array conv2d_21_scratch0_array;   /* Array #130 */
AI_STATIC ai_array conv2d_21_scratch1_array;   /* Array #131 */
AI_STATIC ai_array conv2d_22_scratch0_array;   /* Array #132 */
AI_STATIC ai_array conv2d_22_scratch1_array;   /* Array #133 */
AI_STATIC ai_array conv2d_23_scratch0_array;   /* Array #134 */
AI_STATIC ai_array conv2d_23_scratch1_array;   /* Array #135 */
AI_STATIC ai_array conv2d_24_scratch0_array;   /* Array #136 */
AI_STATIC ai_array conv2d_24_scratch1_array;   /* Array #137 */
AI_STATIC ai_array conv2d_25_scratch0_array;   /* Array #138 */
AI_STATIC ai_array conv2d_25_scratch1_array;   /* Array #139 */
AI_STATIC ai_array conv2d_26_scratch0_array;   /* Array #140 */
AI_STATIC ai_array conv2d_26_scratch1_array;   /* Array #141 */
AI_STATIC ai_array conv2d_28_scratch0_array;   /* Array #142 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor input_output;   /* Tensor #0 */
AI_STATIC ai_tensor conv2d_0_output;   /* Tensor #1 */
AI_STATIC ai_tensor conv2d_1_output;   /* Tensor #2 */
AI_STATIC ai_tensor conv2d_2_output;   /* Tensor #3 */
AI_STATIC ai_tensor conv2d_3_output;   /* Tensor #4 */
AI_STATIC ai_tensor conv2d_4_output;   /* Tensor #5 */
AI_STATIC ai_tensor conv2d_5_output;   /* Tensor #6 */
AI_STATIC ai_tensor conv2d_6_output;   /* Tensor #7 */
AI_STATIC ai_tensor conv2d_7_output;   /* Tensor #8 */
AI_STATIC ai_tensor conv2d_8_output;   /* Tensor #9 */
AI_STATIC ai_tensor conv2d_9_output;   /* Tensor #10 */
AI_STATIC ai_tensor conv2d_10_output;   /* Tensor #11 */
AI_STATIC ai_tensor conv2d_11_output;   /* Tensor #12 */
AI_STATIC ai_tensor conv2d_12_output;   /* Tensor #13 */
AI_STATIC ai_tensor conv2d_13_output;   /* Tensor #14 */
AI_STATIC ai_tensor conv2d_14_output;   /* Tensor #15 */
AI_STATIC ai_tensor conv2d_15_output;   /* Tensor #16 */
AI_STATIC ai_tensor conv2d_16_output;   /* Tensor #17 */
AI_STATIC ai_tensor conv2d_17_output;   /* Tensor #18 */
AI_STATIC ai_tensor conv2d_18_output;   /* Tensor #19 */
AI_STATIC ai_tensor conv2d_19_output;   /* Tensor #20 */
AI_STATIC ai_tensor conv2d_20_output;   /* Tensor #21 */
AI_STATIC ai_tensor conv2d_21_output;   /* Tensor #22 */
AI_STATIC ai_tensor conv2d_22_output;   /* Tensor #23 */
AI_STATIC ai_tensor conv2d_23_output;   /* Tensor #24 */
AI_STATIC ai_tensor conv2d_24_output;   /* Tensor #25 */
AI_STATIC ai_tensor conv2d_25_output;   /* Tensor #26 */
AI_STATIC ai_tensor conv2d_26_output;   /* Tensor #27 */
AI_STATIC ai_tensor conv2d_28_output;   /* Tensor #28 */
AI_STATIC ai_tensor reshape_29_fmt_output;   /* Tensor #29 */
AI_STATIC ai_tensor nl_30_output;   /* Tensor #30 */
AI_STATIC ai_tensor nl_30_fmt_output;   /* Tensor #31 */
AI_STATIC ai_tensor conv2d_0_weights;   /* Tensor #32 */
AI_STATIC ai_tensor conv2d_0_bias;   /* Tensor #33 */
AI_STATIC ai_tensor conv2d_1_weights;   /* Tensor #34 */
AI_STATIC ai_tensor conv2d_1_bias;   /* Tensor #35 */
AI_STATIC ai_tensor conv2d_2_weights;   /* Tensor #36 */
AI_STATIC ai_tensor conv2d_2_bias;   /* Tensor #37 */
AI_STATIC ai_tensor conv2d_3_weights;   /* Tensor #38 */
AI_STATIC ai_tensor conv2d_3_bias;   /* Tensor #39 */
AI_STATIC ai_tensor conv2d_4_weights;   /* Tensor #40 */
AI_STATIC ai_tensor conv2d_4_bias;   /* Tensor #41 */
AI_STATIC ai_tensor conv2d_5_weights;   /* Tensor #42 */
AI_STATIC ai_tensor conv2d_5_bias;   /* Tensor #43 */
AI_STATIC ai_tensor conv2d_6_weights;   /* Tensor #44 */
AI_STATIC ai_tensor conv2d_6_bias;   /* Tensor #45 */
AI_STATIC ai_tensor conv2d_7_weights;   /* Tensor #46 */
AI_STATIC ai_tensor conv2d_7_bias;   /* Tensor #47 */
AI_STATIC ai_tensor conv2d_8_weights;   /* Tensor #48 */
AI_STATIC ai_tensor conv2d_8_bias;   /* Tensor #49 */
AI_STATIC ai_tensor conv2d_9_weights;   /* Tensor #50 */
AI_STATIC ai_tensor conv2d_9_bias;   /* Tensor #51 */
AI_STATIC ai_tensor conv2d_10_weights;   /* Tensor #52 */
AI_STATIC ai_tensor conv2d_10_bias;   /* Tensor #53 */
AI_STATIC ai_tensor conv2d_11_weights;   /* Tensor #54 */
AI_STATIC ai_tensor conv2d_11_bias;   /* Tensor #55 */
AI_STATIC ai_tensor conv2d_12_weights;   /* Tensor #56 */
AI_STATIC ai_tensor conv2d_12_bias;   /* Tensor #57 */
AI_STATIC ai_tensor conv2d_13_weights;   /* Tensor #58 */
AI_STATIC ai_tensor conv2d_13_bias;   /* Tensor #59 */
AI_STATIC ai_tensor conv2d_14_weights;   /* Tensor #60 */
AI_STATIC ai_tensor conv2d_14_bias;   /* Tensor #61 */
AI_STATIC ai_tensor conv2d_15_weights;   /* Tensor #62 */
AI_STATIC ai_tensor conv2d_15_bias;   /* Tensor #63 */
AI_STATIC ai_tensor conv2d_16_weights;   /* Tensor #64 */
AI_STATIC ai_tensor conv2d_16_bias;   /* Tensor #65 */
AI_STATIC ai_tensor conv2d_17_weights;   /* Tensor #66 */
AI_STATIC ai_tensor conv2d_17_bias;   /* Tensor #67 */
AI_STATIC ai_tensor conv2d_18_weights;   /* Tensor #68 */
AI_STATIC ai_tensor conv2d_18_bias;   /* Tensor #69 */
AI_STATIC ai_tensor conv2d_19_weights;   /* Tensor #70 */
AI_STATIC ai_tensor conv2d_19_bias;   /* Tensor #71 */
AI_STATIC ai_tensor conv2d_20_weights;   /* Tensor #72 */
AI_STATIC ai_tensor conv2d_20_bias;   /* Tensor #73 */
AI_STATIC ai_tensor conv2d_21_weights;   /* Tensor #74 */
AI_STATIC ai_tensor conv2d_21_bias;   /* Tensor #75 */
AI_STATIC ai_tensor conv2d_22_weights;   /* Tensor #76 */
AI_STATIC ai_tensor conv2d_22_bias;   /* Tensor #77 */
AI_STATIC ai_tensor conv2d_23_weights;   /* Tensor #78 */
AI_STATIC ai_tensor conv2d_23_bias;   /* Tensor #79 */
AI_STATIC ai_tensor conv2d_24_weights;   /* Tensor #80 */
AI_STATIC ai_tensor conv2d_24_bias;   /* Tensor #81 */
AI_STATIC ai_tensor conv2d_25_weights;   /* Tensor #82 */
AI_STATIC ai_tensor conv2d_25_bias;   /* Tensor #83 */
AI_STATIC ai_tensor conv2d_26_weights;   /* Tensor #84 */
AI_STATIC ai_tensor conv2d_26_bias;   /* Tensor #85 */
AI_STATIC ai_tensor conv2d_28_weights;   /* Tensor #86 */
AI_STATIC ai_tensor conv2d_28_bias;   /* Tensor #87 */
AI_STATIC ai_tensor conv2d_0_scratch0;   /* Tensor #88 */
AI_STATIC ai_tensor conv2d_0_scratch1;   /* Tensor #89 */
AI_STATIC ai_tensor conv2d_1_scratch0;   /* Tensor #90 */
AI_STATIC ai_tensor conv2d_1_scratch1;   /* Tensor #91 */
AI_STATIC ai_tensor conv2d_2_scratch0;   /* Tensor #92 */
AI_STATIC ai_tensor conv2d_2_scratch1;   /* Tensor #93 */
AI_STATIC ai_tensor conv2d_3_scratch0;   /* Tensor #94 */
AI_STATIC ai_tensor conv2d_3_scratch1;   /* Tensor #95 */
AI_STATIC ai_tensor conv2d_4_scratch0;   /* Tensor #96 */
AI_STATIC ai_tensor conv2d_4_scratch1;   /* Tensor #97 */
AI_STATIC ai_tensor conv2d_5_scratch0;   /* Tensor #98 */
AI_STATIC ai_tensor conv2d_5_scratch1;   /* Tensor #99 */
AI_STATIC ai_tensor conv2d_6_scratch0;   /* Tensor #100 */
AI_STATIC ai_tensor conv2d_6_scratch1;   /* Tensor #101 */
AI_STATIC ai_tensor conv2d_7_scratch0;   /* Tensor #102 */
AI_STATIC ai_tensor conv2d_7_scratch1;   /* Tensor #103 */
AI_STATIC ai_tensor conv2d_8_scratch0;   /* Tensor #104 */
AI_STATIC ai_tensor conv2d_8_scratch1;   /* Tensor #105 */
AI_STATIC ai_tensor conv2d_9_scratch0;   /* Tensor #106 */
AI_STATIC ai_tensor conv2d_9_scratch1;   /* Tensor #107 */
AI_STATIC ai_tensor conv2d_10_scratch0;   /* Tensor #108 */
AI_STATIC ai_tensor conv2d_10_scratch1;   /* Tensor #109 */
AI_STATIC ai_tensor conv2d_11_scratch0;   /* Tensor #110 */
AI_STATIC ai_tensor conv2d_11_scratch1;   /* Tensor #111 */
AI_STATIC ai_tensor conv2d_12_scratch0;   /* Tensor #112 */
AI_STATIC ai_tensor conv2d_12_scratch1;   /* Tensor #113 */
AI_STATIC ai_tensor conv2d_13_scratch0;   /* Tensor #114 */
AI_STATIC ai_tensor conv2d_13_scratch1;   /* Tensor #115 */
AI_STATIC ai_tensor conv2d_14_scratch0;   /* Tensor #116 */
AI_STATIC ai_tensor conv2d_14_scratch1;   /* Tensor #117 */
AI_STATIC ai_tensor conv2d_15_scratch0;   /* Tensor #118 */
AI_STATIC ai_tensor conv2d_15_scratch1;   /* Tensor #119 */
AI_STATIC ai_tensor conv2d_16_scratch0;   /* Tensor #120 */
AI_STATIC ai_tensor conv2d_16_scratch1;   /* Tensor #121 */
AI_STATIC ai_tensor conv2d_17_scratch0;   /* Tensor #122 */
AI_STATIC ai_tensor conv2d_17_scratch1;   /* Tensor #123 */
AI_STATIC ai_tensor conv2d_18_scratch0;   /* Tensor #124 */
AI_STATIC ai_tensor conv2d_18_scratch1;   /* Tensor #125 */
AI_STATIC ai_tensor conv2d_19_scratch0;   /* Tensor #126 */
AI_STATIC ai_tensor conv2d_19_scratch1;   /* Tensor #127 */
AI_STATIC ai_tensor conv2d_20_scratch0;   /* Tensor #128 */
AI_STATIC ai_tensor conv2d_20_scratch1;   /* Tensor #129 */
AI_STATIC ai_tensor conv2d_21_scratch0;   /* Tensor #130 */
AI_STATIC ai_tensor conv2d_21_scratch1;   /* Tensor #131 */
AI_STATIC ai_tensor conv2d_22_scratch0;   /* Tensor #132 */
AI_STATIC ai_tensor conv2d_22_scratch1;   /* Tensor #133 */
AI_STATIC ai_tensor conv2d_23_scratch0;   /* Tensor #134 */
AI_STATIC ai_tensor conv2d_23_scratch1;   /* Tensor #135 */
AI_STATIC ai_tensor conv2d_24_scratch0;   /* Tensor #136 */
AI_STATIC ai_tensor conv2d_24_scratch1;   /* Tensor #137 */
AI_STATIC ai_tensor conv2d_25_scratch0;   /* Tensor #138 */
AI_STATIC ai_tensor conv2d_25_scratch1;   /* Tensor #139 */
AI_STATIC ai_tensor conv2d_26_scratch0;   /* Tensor #140 */
AI_STATIC ai_tensor conv2d_26_scratch1;   /* Tensor #141 */
AI_STATIC ai_tensor conv2d_28_scratch0;   /* Tensor #142 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conv2d_0_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain conv2d_1_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain conv2d_2_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain conv2d_3_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain conv2d_4_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain conv2d_5_chain;   /* Chain #5 */
AI_STATIC_CONST ai_tensor_chain conv2d_6_chain;   /* Chain #6 */
AI_STATIC_CONST ai_tensor_chain conv2d_7_chain;   /* Chain #7 */
AI_STATIC_CONST ai_tensor_chain conv2d_8_chain;   /* Chain #8 */
AI_STATIC_CONST ai_tensor_chain conv2d_9_chain;   /* Chain #9 */
AI_STATIC_CONST ai_tensor_chain conv2d_10_chain;   /* Chain #10 */
AI_STATIC_CONST ai_tensor_chain conv2d_11_chain;   /* Chain #11 */
AI_STATIC_CONST ai_tensor_chain conv2d_12_chain;   /* Chain #12 */
AI_STATIC_CONST ai_tensor_chain conv2d_13_chain;   /* Chain #13 */
AI_STATIC_CONST ai_tensor_chain conv2d_14_chain;   /* Chain #14 */
AI_STATIC_CONST ai_tensor_chain conv2d_15_chain;   /* Chain #15 */
AI_STATIC_CONST ai_tensor_chain conv2d_16_chain;   /* Chain #16 */
AI_STATIC_CONST ai_tensor_chain conv2d_17_chain;   /* Chain #17 */
AI_STATIC_CONST ai_tensor_chain conv2d_18_chain;   /* Chain #18 */
AI_STATIC_CONST ai_tensor_chain conv2d_19_chain;   /* Chain #19 */
AI_STATIC_CONST ai_tensor_chain conv2d_20_chain;   /* Chain #20 */
AI_STATIC_CONST ai_tensor_chain conv2d_21_chain;   /* Chain #21 */
AI_STATIC_CONST ai_tensor_chain conv2d_22_chain;   /* Chain #22 */
AI_STATIC_CONST ai_tensor_chain conv2d_23_chain;   /* Chain #23 */
AI_STATIC_CONST ai_tensor_chain conv2d_24_chain;   /* Chain #24 */
AI_STATIC_CONST ai_tensor_chain conv2d_25_chain;   /* Chain #25 */
AI_STATIC_CONST ai_tensor_chain conv2d_26_chain;   /* Chain #26 */
AI_STATIC_CONST ai_tensor_chain conv2d_28_chain;   /* Chain #27 */
AI_STATIC_CONST ai_tensor_chain reshape_29_fmt_chain;   /* Chain #28 */
AI_STATIC_CONST ai_tensor_chain nl_30_chain;   /* Chain #29 */
AI_STATIC_CONST ai_tensor_chain nl_30_fmt_chain;   /* Chain #30 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_conv2d conv2d_0_layer; /* Layer #0 */
AI_STATIC ai_layer_conv2d conv2d_1_layer; /* Layer #1 */
AI_STATIC ai_layer_conv2d conv2d_2_layer; /* Layer #2 */
AI_STATIC ai_layer_conv2d conv2d_3_layer; /* Layer #3 */
AI_STATIC ai_layer_conv2d conv2d_4_layer; /* Layer #4 */
AI_STATIC ai_layer_conv2d conv2d_5_layer; /* Layer #5 */
AI_STATIC ai_layer_conv2d conv2d_6_layer; /* Layer #6 */
AI_STATIC ai_layer_conv2d conv2d_7_layer; /* Layer #7 */
AI_STATIC ai_layer_conv2d conv2d_8_layer; /* Layer #8 */
AI_STATIC ai_layer_conv2d conv2d_9_layer; /* Layer #9 */
AI_STATIC ai_layer_conv2d conv2d_10_layer; /* Layer #10 */
AI_STATIC ai_layer_conv2d conv2d_11_layer; /* Layer #11 */
AI_STATIC ai_layer_conv2d conv2d_12_layer; /* Layer #12 */
AI_STATIC ai_layer_conv2d conv2d_13_layer; /* Layer #13 */
AI_STATIC ai_layer_conv2d conv2d_14_layer; /* Layer #14 */
AI_STATIC ai_layer_conv2d conv2d_15_layer; /* Layer #15 */
AI_STATIC ai_layer_conv2d conv2d_16_layer; /* Layer #16 */
AI_STATIC ai_layer_conv2d conv2d_17_layer; /* Layer #17 */
AI_STATIC ai_layer_conv2d conv2d_18_layer; /* Layer #18 */
AI_STATIC ai_layer_conv2d conv2d_19_layer; /* Layer #19 */
AI_STATIC ai_layer_conv2d conv2d_20_layer; /* Layer #20 */
AI_STATIC ai_layer_conv2d conv2d_21_layer; /* Layer #21 */
AI_STATIC ai_layer_conv2d conv2d_22_layer; /* Layer #22 */
AI_STATIC ai_layer_conv2d conv2d_23_layer; /* Layer #23 */
AI_STATIC ai_layer_conv2d conv2d_24_layer; /* Layer #24 */
AI_STATIC ai_layer_conv2d conv2d_25_layer; /* Layer #25 */
AI_STATIC ai_layer_conv2d_nl_pool conv2d_26_layer; /* Layer #26 */
AI_STATIC ai_layer_conv2d conv2d_28_layer; /* Layer #27 */
AI_STATIC ai_layer_nl reshape_29_fmt_layer; /* Layer #28 */
AI_STATIC ai_layer_nl nl_30_layer; /* Layer #29 */
AI_STATIC ai_layer_nl nl_30_fmt_layer; /* Layer #30 */




/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  input_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 9216, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 256, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  reshape_29_fmt_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  nl_30_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  nl_30_fmt_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 2, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 72, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 72, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 144, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 288, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 288, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 576, AI_STATIC)

/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 576, AI_STATIC)

/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#67 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#68 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#69 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#70 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#71 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#72 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#73 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#74 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#75 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#76 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#77 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#78 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#79 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#80 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#81 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)

/* Array#82 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#83 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)

/* Array#84 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 65536, AI_STATIC)

/* Array#85 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)

/* Array#86 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#87 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 2, AI_STATIC)

/* Array#88 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 292, AI_STATIC)

/* Array#89 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#90 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 297, AI_STATIC)

/* Array#91 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#92 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 192, AI_STATIC)

/* Array#93 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#94 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 593, AI_STATIC)

/* Array#95 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#96 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#97 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#98 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1185, AI_STATIC)

/* Array#99 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#100 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 448, AI_STATIC)

/* Array#101 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#102 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1185, AI_STATIC)

/* Array#103 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#104 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 768, AI_STATIC)

/* Array#105 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#106 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2369, AI_STATIC)

/* Array#107 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#108 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)

/* Array#109 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#110 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2369, AI_STATIC)

/* Array#111 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#112 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#113 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#114 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#115 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#116 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#117 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#118 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#119 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#120 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#121 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#122 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#123 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#124 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#125 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#126 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#127 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#128 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#129 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#130 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#131 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#132 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#133 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#134 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#135 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#136 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3072, AI_STATIC)

/* Array#137 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#138 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9473, AI_STATIC)

/* Array#139 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#140 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3584, AI_STATIC)

/* Array#141 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#142 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1044, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(input_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_0_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #25 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #26 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #27 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_26_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01860933005809784f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #28 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012518751434981823f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_30_fmt_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #30 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_0_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.016358856111764908f, 0.02661055326461792f, 0.0030382154509425163f, 0.0032625109888613224f, 0.011536277830600739f, 0.037382204085588455f, 0.018140187487006187f, 0.0010862220078706741f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #31 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_0_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00012830476043745875f, 0.00020871023298241198f, 2.382914135523606e-05f, 2.558832238719333e-05f, 9.048061474459246e-05f, 0.0002931937633547932f, 0.00014227598148863763f, 8.519388757122215e-06f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #32 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004282447509467602f, 0.006182645447552204f, 0.14600451290607452f, 0.0029036880005151033f, 0.01466022152453661f, 0.0026488567236810923f, 0.007373996544629335f, 0.3196430802345276f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001007634709822014f, 0.00014547401224263012f, 0.003435400314629078f, 6.832207145635039e-05f, 0.00034494639839977026f, 6.23260420979932e-05f, 0.00017350580310449004f, 0.007521013729274273f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #34 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.013826617039740086f, 0.008839202113449574f, 0.01652754470705986f, 0.007271260488778353f, 0.012153873220086098f, 0.012306750752031803f, 0.007830707356333733f, 0.008570464327931404f, 0.014284062199294567f, 0.008282698690891266f, 0.012864994816482067f, 0.008019245229661465f, 0.012126094661653042f, 0.006952868774533272f, 0.00811417680233717f, 0.01090773195028305f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #35 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00032533216290175915f, 0.0002079812256852165f, 0.0003888834035024047f, 0.00017108848260249943f, 0.0002859734813682735f, 0.00028957059839740396f, 0.00018425194139126688f, 0.00020165798196103424f, 0.00033609557431191206f, 0.00019488703401293606f, 0.00030270576826296747f, 0.00018868812185246497f, 0.00028531986754387617f, 0.0001635969092603773f, 0.00019092181173618883f, 0.0002566525072325021f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #36 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003504690481349826f, 0.0030338442884385586f, 0.00492874113842845f, 0.004002050030976534f, 0.0058423494920134544f, 0.004800408612936735f, 0.005058407783508301f, 0.002678049262613058f, 0.005025816150009632f, 0.008900696411728859f, 0.002994187641888857f, 0.004956091288477182f, 0.0036077459808439016f, 0.0035060737282037735f, 0.006657086778432131f, 0.007236542645841837f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.246330980909988e-05f, 7.138457294786349e-05f, 0.00011597038246691227f, 9.416588727617636e-05f, 0.00013746705371886492f, 0.00011295079457340762f, 0.0001190213588415645f, 6.301292160060257e-05f, 0.00011825450201286003f, 0.00020942815172020346f, 7.045147503959015e-05f, 0.00011661391181405634f, 8.488813909934834e-05f, 8.249585516750813e-05f, 0.00015663733938708901f, 0.00017027159628923982f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #38 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011522140353918076f, 0.004014539532363415f, 0.006260255351662636f, 0.006391320377588272f, 0.004975421354174614f, 0.0015950315864756703f, 0.005341943819075823f, 0.006881502456963062f, 0.0037601105868816376f, 0.003396629123017192f, 0.0017530005425214767f, 0.005150331184267998f, 0.006354652810841799f, 0.005098525434732437f, 0.00982401892542839f, 0.011464330367743969f, 0.006650646682828665f, 0.00765557074919343f, 0.0022131442092359066f, 0.003144657937809825f, 0.005392806604504585f, 0.0019361866870895028f, 0.0059038009494543076f, 0.006723729893565178f, 0.0053926752880215645f, 0.001115211402066052f, 0.005510017275810242f, 0.0073087806813418865f, 0.009491825476288795f, 0.004709278233349323f, 0.008319336920976639f, 0.00368461012840271f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #39 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002711091947276145f, 9.445975592825562e-05f, 0.00014730013208463788f, 0.00015038401761557907f, 0.00011706873920047656f, 3.753015698748641e-05f, 0.0001256927935173735f, 0.00016191770555451512f, 8.847319259075448e-05f, 7.992069004103541e-05f, 4.1247072658734396e-05f, 0.00012118426820961758f, 0.00014952124911360443f, 0.00011996530520264059f, 0.00023115338990464807f, 0.00026974896900355816f, 0.00015648581029381603f, 0.00018013108638115227f, 5.207398135098629e-05f, 7.39919560146518e-05f, 0.00012688957212958485f, 4.555733539746143e-05f, 0.0001389129611197859f, 0.00015820541011635214f, 0.0001268864725716412f, 2.6240268198307604e-05f, 0.00012964746565558016f, 0.00017197131819557399f, 0.0002233370760222897f, 0.00011080654803663492f, 0.00019574910402297974f, 8.669670933159068e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #40 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008089429698884487f, 0.009632223285734653f, 0.007008004933595657f, 0.009896927513182163f, 0.012743614614009857f, 0.024141401052474976f, 0.004379767458885908f, 0.007172843907028437f, 0.007292597554624081f, 0.016973942518234253f, 0.021708376705646515f, 0.006722067948430777f, 0.0027490935754030943f, 0.013131093233823776f, 0.0084508853033185f, 0.002057901583611965f, 0.007000336889177561f, 0.004261521156877279f, 0.02188444323837757f, 0.024417920038104057f, 0.005509122274816036f, 0.023451460525393486f, 0.003173015546053648f, 0.006475931033492088f, 0.006081317085772753f, 0.029360849410295486f, 0.007583173923194408f, 0.0032094919588416815f, 0.00509500689804554f, 0.006852855905890465f, 0.006458194926381111f, 0.011236500926315784f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #41 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00019033953140024096f, 0.00022664054995402694f, 0.00016489424160681665f, 0.00023286888608708978f, 0.0002998497511725873f, 0.0005680329632014036f, 0.00010305335308657959f, 0.00016877280722837895f, 0.0001715905382297933f, 0.0003993868886027485f, 0.000510785321239382f, 0.00015816630912013352f, 6.468455831054598e-05f, 0.00030896690441295505f, 0.0001988443691516295f, 4.8421214160043746e-05f, 0.00016471381240990013f, 0.00010027108510257676f, 0.0005149280768819153f, 0.0005745392991229892f, 0.00012962640903424472f, 0.0005517990794032812f, 7.465919043170288e-05f, 0.0001523748505860567f, 0.00014308981189969927f, 0.0006908435025252402f, 0.00017842762463260442f, 7.551746239187196e-05f, 0.00011988251935690641f, 0.0001612436753930524f, 0.0001519575307611376f, 0.00026438827626407146f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #42 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00432790769264102f, 0.006065879948437214f, 0.004967047832906246f, 0.004002489149570465f, 0.002101216232404113f, 0.002862849272787571f, 0.0037212700117379427f, 0.0034035639837384224f, 0.004939038306474686f, 0.0037457046564668417f, 0.005765086971223354f, 0.003418384585529566f, 0.00522745493799448f, 0.005362580064684153f, 0.0032464393880218267f, 0.003832563292235136f, 0.004021866712719202f, 0.004730307497084141f, 0.005799105390906334f, 0.004816326778382063f, 0.0067365351133048534f, 0.004041776992380619f, 0.0036440955009311438f, 0.005132235120981932f, 0.006409043446183205f, 0.008103039115667343f, 0.0065780929289758205f, 0.00538314413279295f, 0.002849738812074065f, 0.00385641073808074f, 0.00465537142008543f, 0.00388823333196342f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #43 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00010183312406297773f, 0.00014272659609559923f, 0.00011687171354424208f, 9.41762191359885e-05f, 4.944038300891407e-05f, 6.736115756211802e-05f, 8.755929593462497e-05f, 8.008386066649109e-05f, 0.00011621267185546458f, 8.813422755338252e-05f, 0.0001356491120532155f, 8.043258276302367e-05f, 0.00012299894297029823f, 0.00012617836182471365f, 7.638680835952982e-05f, 9.017796401167288e-05f, 9.46321597439237e-05f, 0.00011130135681014508f, 0.00013644954015035182f, 0.00011332533904351294f, 0.00015850670752115548f, 9.510063682682812e-05f, 8.57434279168956e-05f, 0.00012075847917003557f, 0.00015080103185027838f, 0.00019065974629484117f, 0.0001547786669107154f, 0.00012666221300605685f, 6.705267878714949e-05f, 9.07390785869211e-05f, 0.00010953815217362717f, 9.148784738499671e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #44 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0028519663028419018f, 0.0034310235641896725f, 0.0026347090024501085f, 0.003559932578355074f, 0.008049708791077137f, 0.004126663785427809f, 0.0030332959722727537f, 0.0030573878902941942f, 0.0030465188901871443f, 0.0023521841503679752f, 0.00348919490352273f, 0.003030171385034919f, 0.00431682588532567f, 0.006812374107539654f, 0.004512785002589226f, 0.003324041608721018f, 0.003130687866359949f, 0.002908827271312475f, 0.004910151474177837f, 0.003193049691617489f, 0.004857565276324749f, 0.004389337729662657f, 0.002067029708996415f, 0.0035091848112642765f, 0.006919906008988619f, 0.003798156278207898f, 0.0032897137571126223f, 0.0029371425043791533f, 0.004756495356559753f, 0.0033922535367310047f, 0.0044181388802826405f, 0.006571158766746521f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #45 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(6.710508750984445e-05f, 8.072996570263058e-05f, 6.199315248522907e-05f, 8.376312325708568e-05f, 0.00018940492009278387f, 9.709797450341284e-05f, 7.137167267501354e-05f, 7.193854253273457e-05f, 7.168279989855364e-05f, 5.534551019081846e-05f, 8.209870429709554e-05f, 7.129814912332222e-05f, 0.00010157237556995824f, 0.00016029116522986442f, 0.00010618317901389673f, 7.821274630259722e-05f, 7.366324280155823e-05f, 6.844299787189811e-05f, 0.00011553298099897802f, 7.51305851736106e-05f, 0.00011429565347498283f, 0.00010327853669878095f, 4.863599315285683e-05f, 8.256905857706442e-05f, 0.0001628213212825358f, 8.936838275985792e-05f, 7.74050276959315e-05f, 6.910923548275605e-05f, 0.00011191754310857505f, 7.981773524079472e-05f, 0.00010395621211500838f, 0.00015461549628525972f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #46 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0042300960049033165f, 0.0026852863375097513f, 0.0050364769995212555f, 0.004233118612319231f, 0.0032636055257171392f, 0.003694792976602912f, 0.0048807901330292225f, 0.004024822730571032f, 0.0027623523492366076f, 0.004289160016924143f, 0.00227759568952024f, 0.00488121947273612f, 0.002745862351730466f, 0.00421172846108675f, 0.005308842286467552f, 0.008007572032511234f, 0.004134221002459526f, 0.0039891707710921764f, 0.004294834099709988f, 0.002871996257454157f, 0.007043118588626385f, 0.0032361524645239115f, 0.0033641159534454346f, 0.005956759676337242f, 0.005691688507795334f, 0.0017276839353144169f, 0.0026566600427031517f, 0.006568112410604954f, 0.005484770052134991f, 0.004002146888524294f, 0.004215613007545471f, 0.005949888378381729f, 0.005199229810386896f, 0.0024731275625526905f, 0.0036391266621649265f, 0.006808779202401638f, 0.0024148421362042427f, 0.002503411378711462f, 0.003657164517790079f, 0.0027681668289005756f, 0.0034119943156838417f, 0.0043283686973154545f, 0.003233760129660368f, 0.004359607119113207f, 0.006307332310825586f, 0.0063668424263596535f, 0.0020496794022619724f, 0.0036822427064180374f, 0.005289251916110516f, 0.008575708605349064f, 0.008090073242783546f, 0.004386741667985916f, 0.0043262611143291f, 0.008368639275431633f, 0.005266557913273573f, 0.004655885975807905f, 0.003240912454202771f, 0.006501851137727499f, 0.004458935000002384f, 0.005073776468634605f, 0.0029611163772642612f, 0.007733507081866264f, 0.005725600756704807f, 0.0030629062093794346f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #47 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(9.953167318599299e-05f, 6.318320811260492e-05f, 0.000118505340651609f, 9.960279567167163e-05f, 7.679071859456599e-05f, 8.693630661582574e-05f, 0.00011484212154755369f, 9.470171062275767e-05f, 6.499652954516932e-05f, 0.00010092141747009009f, 5.3590487368637696e-05f, 0.00011485222785267979f, 6.460852455347776e-05f, 9.909949585562572e-05f, 0.00012491393135860562f, 0.00018841346900444478f, 9.727579163154587e-05f, 9.386284364154562e-05f, 0.00010105492401635274f, 6.757638038834557e-05f, 0.0001657204411458224f, 7.61447663535364e-05f, 7.915567402960733e-05f, 0.0001401590561727062f, 0.00013392209075391293f, 4.065138637088239e-05f, 6.250965088838711e-05f, 0.00015454382810276002f, 0.00012905341282021254f, 9.41681646509096e-05f, 9.919089643517509e-05f, 0.0001399973698426038f, 0.00012233482266310602f, 5.8191239077132195e-05f, 8.562651055399328e-05f, 0.00016020657494664192f, 5.6819815654307604e-05f, 5.890379907214083e-05f, 8.605093171354383e-05f, 6.513333937618881e-05f, 8.028221782296896e-05f, 0.00010184397251578048f, 7.608847226947546e-05f, 0.00010257898975396529f, 0.00014840782387182117f, 0.0001498080528108403f, 4.8227750085061416e-05f, 8.66410046000965e-05f, 0.00012445298489183187f, 0.0002017813822021708f, 0.00019035466539207846f, 0.00010321745503460988f, 0.0001017943795886822f, 0.0001969091681530699f, 0.00012391901691444218f, 0.00010955025936709717f, 7.625676516909152e-05f, 0.0001529847359051928f, 0.00010491612192708999f, 0.00011938298121094704f, 6.967332592466846e-05f, 0.00018196487508248538f, 0.00013472001592162997f, 7.206838199635968e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #48 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005109510850161314f, 0.009459360502660275f, 0.007336295675486326f, 0.007518338039517403f, 0.009334520436823368f, 0.004385118838399649f, 0.005419708788394928f, 0.0030659011099487543f, 0.012715761549770832f, 0.014465331099927425f, 0.017258184030652046f, 0.009264904074370861f, 0.009068564511835575f, 0.0038580133114010096f, 0.006530741695314646f, 0.007820227183401585f, 0.0058050802908837795f, 0.004727560095489025f, 0.006589245982468128f, 0.0048025622963905334f, 0.00454771239310503f, 0.005886252038180828f, 0.017020585015416145f, 0.0062013790011405945f, 0.005413149483501911f, 0.013955467380583286f, 0.01126223336905241f, 0.004563675262033939f, 0.005881777033209801f, 0.007130143698304892f, 0.005408892408013344f, 0.007096423301845789f, 0.004256489686667919f, 0.0055601815693080425f, 0.006566857919096947f, 0.0035519120283424854f, 0.010933599434792995f, 0.011856107041239738f, 0.0055757081136107445f, 0.005385298281908035f, 0.007252965588122606f, 0.006911314558237791f, 0.010004405863583088f, 0.006650133989751339f, 0.00382491503842175f, 0.0034051614347845316f, 0.01161592360585928f, 0.004051681142300367f, 0.010450385510921478f, 0.008915186859667301f, 0.007443483918905258f, 0.008641836233437061f, 0.01308601163327694f, 0.00547426613047719f, 0.00445722509175539f, 0.005184614565223455f, 0.008592098951339722f, 0.006110287271440029f, 0.004736986011266708f, 0.004919664468616247f, 0.012334911152720451f, 0.004221485462039709f, 0.00561250327154994f, 0.01155971921980381f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #49 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00012022378359688446f, 0.0002225731877842918f, 0.0001726187183521688f, 0.00017690207459963858f, 0.00021963578183203936f, 0.00010317927080905065f, 0.00012752256589010358f, 7.213884964585304e-05f, 0.00029919439111836255f, 0.0003403607406653464f, 0.00040607491973787546f, 0.00021799774549435824f, 0.0002133779926225543f, 9.07767825992778e-05f, 0.00015366451407317072f, 0.00018400534463580698f, 0.00013659012620337307f, 0.00011123670992674306f, 0.00015504108159802854f, 0.00011300147161819041f, 0.00010700499842641875f, 0.000138500050525181f, 0.0004004843649454415f, 0.00014591480430681258f, 0.00012736822827719152f, 0.00032836393802426755f, 0.0002649937232490629f, 0.00010738059791037813f, 0.00013839475286658853f, 0.0001677680847933516f, 0.00012726805289275944f, 0.00016697467071935534f, 0.00010015269799623638f, 0.00013082780060358346f, 0.00015451430226676166f, 8.357439946848899e-05f, 0.0002572611556388438f, 0.0002789672289509326f, 0.00013119314098730683f, 0.00012671289732679725f, 0.0001706580223981291f, 0.00016261916607618332f, 0.0002353977906750515f, 0.00015647374675609171f, 8.999800047604367e-05f, 8.012144826352596e-05f, 0.00027331584715284407f, 9.53336784732528e-05f, 0.00024589142412878573f, 0.0002097691030940041f, 0.00017514079809188843f, 0.0002033373311860487f, 0.00030790615710429847f, 0.00012880626309197396f, 0.00010487588588148355f, 0.00012199093180242926f, 0.00020216703705955297f, 0.00014377146726474166f, 0.0001114584956667386f, 0.00011575681128306314f, 0.0002902332053054124f, 9.932907414622605e-05f, 0.00013205890718381852f, 0.00027199339820072055f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #50 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0026212120428681374f, 0.0038210335187613964f, 0.00431398069486022f, 0.005020868964493275f, 0.0034485228825360537f, 0.0028270536568015814f, 0.003582642413675785f, 0.00331981317140162f, 0.0043295882642269135f, 0.003942897077649832f, 0.0038837487809360027f, 0.0034380992874503136f, 0.003934171516448259f, 0.0024297393392771482f, 0.005148804746568203f, 0.002186858095228672f, 0.0039443932473659515f, 0.0022046503145247698f, 0.002568918513134122f, 0.004635757766664028f, 0.003661138005554676f, 0.0032629226334393024f, 0.003575714537873864f, 0.003673926927149296f, 0.0026251496747136116f, 0.0023919804953038692f, 0.004751597996801138f, 0.003442320041358471f, 0.004401158541440964f, 0.0033518264535814524f, 0.003951811231672764f, 0.0033759213984012604f, 0.002953064627945423f, 0.0033175628632307053f, 0.0031233381014317274f, 0.002875818870961666f, 0.0033030386548489332f, 0.0022971907164901495f, 0.002634866861626506f, 0.004258723463863134f, 0.0039886413142085075f, 0.003574421163648367f, 0.0028210612945258617f, 0.0036443169228732586f, 0.003736499696969986f, 0.003423259826377034f, 0.0028635833878070116f, 0.0023936473298817873f, 0.0030181948095560074f, 0.0019155963091179729f, 0.0035381445195525885f, 0.00433013029396534f, 0.0015468288911506534f, 0.0021683487575501204f, 0.0035803746432065964f, 0.0033210094552487135f, 0.003173206001520157f, 0.0035837730392813683f, 0.0035118230152875185f, 0.0033882353454828262f, 0.003885408863425255f, 0.004013123922049999f, 0.00226271222345531f, 0.0022408338263630867f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #51 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(6.167557876324281e-05f, 8.990667265607044e-05f, 0.00010150542948395014f, 0.00011813809396699071f, 8.114171941997483e-05f, 6.651890726061538e-05f, 8.429746958427131e-05f, 7.811325485818088e-05f, 0.00010187266889261082f, 9.277404751628637e-05f, 9.138232417171821e-05f, 8.089645416475832e-05f, 9.256874182028696e-05f, 5.71703385503497e-05f, 0.00012114834680687636f, 5.145548493601382e-05f, 9.28092558751814e-05f, 5.18741253472399e-05f, 6.044514157110825e-05f, 0.00010907665273407474f, 8.614442776888609e-05f, 7.677465328015387e-05f, 8.413445902988315e-05f, 8.644533954793587e-05f, 6.176823080750182e-05f, 5.628189683193341e-05f, 0.00011180230649188161f, 8.099576371023431e-05f, 0.00010355667473049834f, 7.886650564614683e-05f, 9.298379882238805e-05f, 7.9433448263444e-05f, 6.948387454031035e-05f, 7.806030771462247e-05f, 7.349030784098431e-05f, 6.76663257763721e-05f, 7.771855598548427e-05f, 5.4051546612754464e-05f, 6.199687049956992e-05f, 0.00010020525951404124f, 9.385038720211014e-05f, 8.410403097514063e-05f, 6.637791375396773e-05f, 8.574863750254735e-05f, 8.791764412308112e-05f, 8.054728823481128e-05f, 6.73784306854941e-05f, 5.632111424347386e-05f, 7.10163512849249e-05f, 4.5072854845784605e-05f, 8.325045928359032e-05f, 0.00010188542364630848f, 3.639597343862988e-05f, 5.101997157908045e-05f, 8.424410771112889e-05f, 7.814139826223254e-05f, 7.466367242159322e-05f, 8.432407048530877e-05f, 8.263112977147102e-05f, 7.97231841715984e-05f, 9.142138878814876e-05f, 9.442644659429789e-05f, 5.3240288252709433e-05f, 5.2725503337569535e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #52 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004415512550622225f, 0.0041644456796348095f, 0.0034937174059450626f, 0.0037939518224447966f, 0.0028801369480788708f, 0.0029594656080007553f, 0.004940325859934092f, 0.003829853842034936f, 0.003777828300371766f, 0.00542642455548048f, 0.0037685378920286894f, 0.0041281175799667835f, 0.004181575961410999f, 0.0039054853841662407f, 0.0038426879327744246f, 0.007420756854116917f, 0.00360864051617682f, 0.009579085744917393f, 0.003712864127010107f, 0.0043688081204891205f, 0.0034809554927051067f, 0.00398525083437562f, 0.0055859703570604324f, 0.003351488383486867f, 0.0048091537319123745f, 0.0036559742875397205f, 0.004541113972663879f, 0.0038936366327106953f, 0.0038822032511234283f, 0.004570825025439262f, 0.003457534359768033f, 0.003935878165066242f, 0.003487665904685855f, 0.003673194209113717f, 0.007544705178588629f, 0.005262719467282295f, 0.004556913394480944f, 0.00466811703518033f, 0.0030945823527872562f, 0.003178758779540658f, 0.003686870913952589f, 0.00513577600941062f, 0.005000615492463112f, 0.004506805445998907f, 0.0034679104574024677f, 0.004494982771575451f, 0.0032412544824182987f, 0.00462720962241292f, 0.0037739237304776907f, 0.004242244642227888f, 0.0027439917903393507f, 0.0046756393276154995f, 0.006259150803089142f, 0.005901080556213856f, 0.0035542466212064028f, 0.0040087089873850346f, 0.006636403501033783f, 0.004002059809863567f, 0.003019174328073859f, 0.0030496707186102867f, 0.0028876997530460358f, 0.004340425133705139f, 0.00415077293291688f, 0.006651267874985933f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #53 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00010389441740699112f, 9.798695828067139e-05f, 8.220511517720297e-05f, 8.926945884013548e-05f, 6.776792724849656e-05f, 6.963448686292395e-05f, 0.00011624296166701242f, 9.011421207105741e-05f, 8.889007585821673e-05f, 0.00012768058513756841f, 8.867148426361382e-05f, 9.713217878015712e-05f, 9.839002450462431e-05f, 9.1893773060292e-05f, 9.041618613991886e-05f, 0.0001746060443110764f, 8.490918844472617e-05f, 0.00022539026394952089f, 8.736151357879862e-05f, 0.00010279548587277532f, 8.190483640646562e-05f, 9.377060632687062e-05f, 0.00013143460091669112f, 7.885855302447453e-05f, 0.00011315655865473673f, 8.602292655268684e-05f, 0.0001068497440428473f, 9.161498019238934e-05f, 9.134595893556252e-05f, 0.00010754882532637566f, 8.135374810080975e-05f, 9.260889783035964e-05f, 8.206273196265101e-05f, 8.642810280434787e-05f, 0.00017752248095348477f, 0.0001238286931766197f, 0.00010722149454522878f, 0.00010983805259456858f, 7.281370199052617e-05f, 7.479432679247111e-05f, 8.674990385770798e-05f, 0.00012084178888471797f, 0.00011766154057113454f, 0.00010604248382151127f, 8.159789285855368e-05f, 0.0001057643021340482f, 7.626481237821281e-05f, 0.00010887552343774587f, 8.879820961738005e-05f, 9.981752373278141e-05f, 6.456451228586957e-05f, 0.0001100150475394912f, 0.00014727414236404002f, 0.00013884896179661155f, 8.362933294847608e-05f, 9.432256774744019e-05f, 0.00015615067968610674f, 9.41661128308624e-05f, 7.103939424268901e-05f, 7.17569564585574e-05f, 6.794587534386665e-05f, 0.00010212765482719988f, 9.766524453880265e-05f, 0.0001565004204167053f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #54 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003770283190533519f, 0.003118843073025346f, 0.005743131041526794f, 0.00386966485530138f, 0.0031029388774186373f, 0.0048121679574251175f, 0.002407751977443695f, 0.003218806581571698f, 0.004437438677996397f, 0.003398965112864971f, 0.0031060308683663607f, 0.004317550919950008f, 0.0027235979214310646f, 0.0018734099576249719f, 0.0025715960655361414f, 0.0028233772609382868f, 0.002771718194708228f, 0.0030236276797950268f, 0.0038004794623702765f, 0.0025806871708482504f, 0.003527272492647171f, 0.002719700103625655f, 0.004009133204817772f, 0.0041353702545166016f, 0.00437702052295208f, 0.002897061873227358f, 0.0033084650058299303f, 0.0036629214882850647f, 0.003159110201522708f, 0.004097639583051205f, 0.0035056190099567175f, 0.002994634909555316f, 0.0036355566699057817f, 0.0028307356406003237f, 0.0027265213429927826f, 0.0026573881041258574f, 0.0031658150255680084f, 0.0018412204226478934f, 0.0033791977912187576f, 0.003851980436593294f, 0.004004702903330326f, 0.0033832956105470657f, 0.0030213340651243925f, 0.003462893422693014f, 0.004052671603858471f, 0.0020407531410455704f, 0.0033271885477006435f, 0.003413865575566888f, 0.002307454589754343f, 0.0024554261472076178f, 0.0039346907287836075f, 0.003584476187825203f, 0.003366433549672365f, 0.0034502956550568342f, 0.0030312680173665285f, 0.003075398039072752f, 0.003701689187437296f, 0.0033467081375420094f, 0.0026736250147223473f, 0.0020299158059060574f, 0.003003298072144389f, 0.0028087084647268057f, 0.0026609282940626144f, 0.003057940397411585f, 0.0034444336779415607f, 0.003372309496626258f, 0.0025157034397125244f, 0.004759080242365599f, 0.0030017613898962736f, 0.0029566818848252296f, 0.003084085416048765f, 0.0022432878613471985f, 0.0033298858907073736f, 0.003207526169717312f, 0.0030967623461037874f, 0.0020593011286109686f, 0.002531029051169753f, 0.002770933322608471f, 0.0027404327411204576f, 0.0026933280751109123f, 0.003425280097872019f, 0.0031954781152307987f, 0.0038585150614380836f, 0.003095800057053566f, 0.0029796832241117954f, 0.0031757650431245565f, 0.0023061882238835096f, 0.003079148242250085f, 0.002935976954177022f, 0.0024786852300167084f, 0.003714695805683732f, 0.0025931752752512693f, 0.003382069058716297f, 0.0024716516491025686f, 0.004165794234722853f, 0.002513958141207695f, 0.0023998571559786797f, 0.0038303036708384752f, 0.003077386412769556f, 0.0033569466322660446f, 0.003986627794802189f, 0.004135106690227985f, 0.003402290865778923f, 0.0037022626493126154f, 0.0035306133795529604f, 0.002454922068864107f, 0.0027622126508504152f, 0.0030583986081182957f, 0.0030999353621155024f, 0.0033484145533293486f, 0.003665527096018195f, 0.0020816472824662924f, 0.0029568432364612818f, 0.0030102962628006935f, 0.0027649407275021076f, 0.003191325580701232f, 0.0033416012302041054f, 0.0024207565002143383f, 0.002849919255822897f, 0.0019201397662982345f, 0.0029877524357289076f, 0.0024054618552327156f, 0.00315587199293077f, 0.0044683120213449f, 0.004208098631352186f, 0.002571621909737587f, 0.0032517919316887856f, 0.003033136948943138f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #55 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.871254976838827e-05f, 7.338454452110454e-05f, 0.00013513250451069325f, 9.105094068218023e-05f, 7.301032746909186e-05f, 0.00011322748468955979f, 5.66529888601508e-05f, 7.573662878712639e-05f, 0.00010441032645758241f, 7.997565262485296e-05f, 7.308307976927608e-05f, 0.0001015894376905635f, 6.408465560525656e-05f, 4.408023596624844e-05f, 6.0508144088089466e-05f, 6.643241067649797e-05f, 6.52168964734301e-05f, 7.114418258424848e-05f, 8.942304702941328e-05f, 6.072205360396765e-05f, 8.299465116579086e-05f, 6.399294215952978e-05f, 9.433255036128685e-05f, 9.730282909004018e-05f, 0.0001029887207550928f, 6.816616223659366e-05f, 7.784623448969796e-05f, 8.618638821644709e-05f, 7.433200516970828e-05f, 9.641505312174559e-05f, 8.248515223385766e-05f, 7.046199607430026e-05f, 8.554250962333754e-05f, 6.660554936388507e-05f, 6.415344250854105e-05f, 6.25267784926109e-05f, 7.448976975865662e-05f, 4.332283424446359e-05f, 7.951053703436628e-05f, 9.063483594218269e-05f, 9.422830771654844e-05f, 7.960695802466944e-05f, 7.109021680662408e-05f, 8.147984772222117e-05f, 9.535698336549103e-05f, 4.80177222925704e-05f, 7.828679372323677e-05f, 8.032625191845e-05f, 5.429305019788444e-05f, 5.777473415946588e-05f, 9.258095815312117e-05f, 8.434061601292342e-05f, 7.921020005596802e-05f, 8.118342520901933e-05f, 7.132395694497973e-05f, 7.236230885609984e-05f, 8.709856774657965e-05f, 7.874607399571687e-05f, 6.290882447501644e-05f, 4.776272544404492e-05f, 7.066583930281922e-05f, 6.608726107515395e-05f, 6.261008093133569e-05f, 7.19515373930335e-05f, 8.104550215648487e-05f, 7.934845780255273e-05f, 5.9193022025283426e-05f, 0.000111978362838272f, 7.062967779347673e-05f, 6.956898869248107e-05f, 7.256671960931271e-05f, 5.2783245337195694e-05f, 7.835025462554768e-05f, 7.547120185336098e-05f, 7.286499749170616e-05f, 4.845414514420554e-05f, 5.955362576059997e-05f, 6.51984300930053e-05f, 6.448077328968793e-05f, 6.337242666631937e-05f, 8.059482934186235e-05f, 7.518772326875478e-05f, 9.078859147848561e-05f, 7.284235471161082e-05f, 7.011019624769688e-05f, 7.47238882468082e-05f, 5.426325515145436e-05f, 7.245055167004466e-05f, 6.908181239850819e-05f, 5.832200622535311e-05f, 8.740460907574743e-05f, 6.101588951423764e-05f, 7.957809430081397e-05f, 5.81565109314397e-05f, 9.801868873182684e-05f, 5.9151956520508975e-05f, 5.646723002428189e-05f, 9.012479131342843e-05f, 7.240909326355904e-05f, 7.898698095232248e-05f, 9.380300616612658e-05f, 9.729662997415289e-05f, 8.00539055489935e-05f, 8.711206464795396e-05f, 8.30732606118545e-05f, 5.776287434855476e-05f, 6.499324081232771e-05f, 7.196232036221772e-05f, 7.29396560927853e-05f, 7.878622272983193e-05f, 8.62476954353042e-05f, 4.89799385832157e-05f, 6.957278674235567e-05f, 7.083050149958581e-05f, 6.505742931040004e-05f, 7.509001443395391e-05f, 7.862591155571863e-05f, 5.695897925761528e-05f, 6.705692794639617e-05f, 4.51797604910098e-05f, 7.030005508568138e-05f, 5.659910311806016e-05f, 7.425581134157255e-05f, 0.00010513675806578249f, 9.901409066515043e-05f, 6.050875163055025e-05f, 7.651275518583134e-05f, 7.136793283279985e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #56 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004641817416995764f, 0.006829611957073212f, 0.006720353849232197f, 0.00918852724134922f, 0.007470945827662945f, 0.003732319688424468f, 0.0054968358017504215f, 0.009205141104757786f, 0.005820909980684519f, 0.005674795713275671f, 0.008465114049613476f, 0.008374599739909172f, 0.010853477753698826f, 0.016958998516201973f, 0.005936526693403721f, 0.007270969450473785f, 0.009189635515213013f, 0.009222839958965778f, 0.007531242910772562f, 0.012598130851984024f, 0.010403120890259743f, 0.008535385131835938f, 0.009908733889460564f, 0.00555999344214797f, 0.0039857011288404465f, 0.006540575064718723f, 0.005978821776807308f, 0.008199303410947323f, 0.006489388179033995f, 0.0097402548417449f, 0.004738659597933292f, 0.006050681695342064f, 0.005363661330193281f, 0.00732505414634943f, 0.007013291586190462f, 0.009039984084665775f, 0.005493103060871363f, 0.007437543943524361f, 0.006668323650956154f, 0.00572677468881011f, 0.006159893702715635f, 0.00794640276581049f, 0.005919866729527712f, 0.005945988465100527f, 0.006333756726235151f, 0.00436541810631752f, 0.006688922178000212f, 0.009698733687400818f, 0.010087735950946808f, 0.007199147716164589f, 0.006285354495048523f, 0.00786086730659008f, 0.006351796444505453f, 0.005983094219118357f, 0.0057192277163267136f, 0.005449720658361912f, 0.007645423989742994f, 0.010224596597254276f, 0.006570467725396156f, 0.007173929829150438f, 0.0085576381534338f, 0.005327558144927025f, 0.010705998167395592f, 0.012492971494793892f, 0.005305483937263489f, 0.0044937473721802235f, 0.010208362713456154f, 0.0054260739125311375f, 0.006703691557049751f, 0.007933204062283039f, 0.004609318450093269f, 0.009647888131439686f, 0.007414758205413818f, 0.006406552158296108f, 0.01164426188915968f, 0.01518384087830782f, 0.0062753562815487385f, 0.004043529275804758f, 0.005889376625418663f, 0.006152925547212362f, 0.008702445775270462f, 0.01001041941344738f, 0.008037364110350609f, 0.005564345512539148f, 0.005006374791264534f, 0.007480964530259371f, 0.009214087389409542f, 0.007938135415315628f, 0.0056259105913341045f, 0.015803981572389603f, 0.00801888108253479f, 0.0057380045764148235f, 0.006042997352778912f, 0.005921787116676569f, 0.006403708830475807f, 0.007350089959800243f, 0.007882066071033478f, 0.009221685118973255f, 0.005190492141991854f, 0.009496478363871574f, 0.006777406204491854f, 0.006562652066349983f, 0.010046095587313175f, 0.004947819747030735f, 0.005228400230407715f, 0.006022070534527302f, 0.007383964490145445f, 0.004373961128294468f, 0.006187134888023138f, 0.008992012590169907f, 0.012042440474033356f, 0.013314926065504551f, 0.005857672076672316f, 0.011635317467153072f, 0.006460837088525295f, 0.011514708399772644f, 0.0062861572951078415f, 0.009617816656827927f, 0.006700758356601f, 0.009746026247739792f, 0.007512024603784084f, 0.004185080993920565f, 0.004750173073261976f, 0.004555956926196814f, 0.00940211396664381f, 0.00783315859735012f, 0.008319910615682602f, 0.004426814615726471f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #57 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00010921923239948228f, 0.00016069675621110946f, 0.00015812597121112049f, 0.00021620064217131585f, 0.00017578696133568883f, 8.781928772805259e-05f, 0.00012933732068631798f, 0.0002165915648220107f, 0.00013696259702555835f, 0.00013352460518945009f, 0.00019917916506528854f, 0.00019704940496012568f, 0.00025537595502100885f, 0.00039903525612317026f, 0.00013968299026601017f, 0.0001710816432023421f, 0.00021622671920340508f, 0.00021700799698010087f, 0.00017720571486279368f, 0.00029642661684192717f, 0.000244779308559373f, 0.00020083259732928127f, 0.0002331466821487993f, 0.00013082337682135403f, 9.378120739711449e-05f, 0.00015389588952530175f, 0.00014067816664464772f, 0.00019292479555588216f, 0.00015269148570951074f, 0.00022918247850611806f, 0.00011149787314934656f, 0.00014236898277886212f, 0.00012620379857253283f, 0.000172354222740978f, 0.00016501863137818873f, 0.00021270550496410578f, 0.00012924948532599956f, 0.0001750010414980352f, 0.0001569017331348732f, 0.0001347476354567334f, 0.00014493867638520896f, 0.0001869741827249527f, 0.00013929099077358842f, 0.00013990562001708895f, 0.00014902956900186837f, 0.00010271571954945102f, 0.00015738641377538443f, 0.0002282055065734312f, 0.00023735850118100643f, 0.00016939171473495662f, 0.0001478906924603507f, 0.00018496158008929342f, 0.0001494540338171646f, 0.00014077869127504528f, 0.00013457007298711687f, 0.00012822872668039054f, 0.00017989233310800046f, 0.00024057875270955265f, 0.00015459924179594964f, 0.00016879834583960474f, 0.00020135618979111314f, 0.0001253543159691617f, 0.0002519058471079916f, 0.0002939522673841566f, 0.0001248349144589156f, 0.00010573523468337953f, 0.00024019677948672324f, 0.00012767233420163393f, 0.00015773392806295305f, 0.00018666363030206412f, 0.00010845455108210444f, 0.00022700913541484624f, 0.00017446490528527647f, 0.0001507424021838233f, 0.0002739826450124383f, 0.0003572668647393584f, 0.00014765544619876891f, 9.51418696786277e-05f, 0.0001385735668009147f, 0.00014477471995633096f, 0.00020476343343034387f, 0.00023553927894681692f, 0.00018911444931291044f, 0.00013092577864881605f, 0.0001177970552816987f, 0.00017602270236238837f, 0.00021680205827578902f, 0.00018677966727409512f, 0.00013237436360213906f, 0.0003718583902809769f, 0.0001886795653263107f, 0.0001350118691334501f, 0.00014218817523214966f, 0.0001393361744703725f, 0.00015067550702951849f, 0.00017294329882133752f, 0.00018546037608757615f, 0.0002169808285543695f, 0.00012212923320475966f, 0.0002234465500805527f, 0.00015946838539093733f, 0.00015441534924320877f, 0.0002363787207286805f, 0.00011641928722383454f, 0.00012302117829676718f, 0.0001416957820765674f, 0.00017374035087414086f, 0.00010291673243045807f, 0.00014557964459527284f, 0.00021157677110750228f, 0.0002833515463862568f, 0.0003132923739030957f, 0.0001378275774186477f, 0.00027377219521440566f, 0.0001520196965429932f, 0.0002709343098104f, 0.0001479095808463171f, 0.00022630157764069736f, 0.0001576649083290249f, 0.00022931826242711395f, 0.0001767535286489874f, 9.847249748418108e-05f, 0.00011176877887919545f, 0.00010719899000832811f, 0.00022122621885500848f, 0.0001843096106313169f, 0.00019576260820031166f, 0.00010416034638183191f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #58 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002280378947034478f, 0.0036341834347695112f, 0.002875986974686384f, 0.0027309958823025227f, 0.0022755595855414867f, 0.0022309848573058844f, 0.0022963592782616615f, 0.003662023926153779f, 0.002270036144182086f, 0.0022683274000883102f, 0.004248185083270073f, 0.0032036069314926863f, 0.002195514738559723f, 0.0028085201047360897f, 0.0028577246703207493f, 0.0027211660053581f, 0.0022486282978206873f, 0.0031330804340541363f, 0.003057750640437007f, 0.002673446200788021f, 0.0029081436805427074f, 0.0026133169885724783f, 0.0023506248835474253f, 0.002894740318879485f, 0.003048446960747242f, 0.003089279169216752f, 0.0020192202646285295f, 0.0025622763205319643f, 0.002064847620204091f, 0.0026676938869059086f, 0.0026475312188267708f, 0.0031600352376699448f, 0.0023392208386212587f, 0.002701077377423644f, 0.0024149634409695864f, 0.0037436126731336117f, 0.0027063568122684956f, 0.0019596524070948362f, 0.0027647630777209997f, 0.002461119322106242f, 0.0035376553423702717f, 0.0032095906790345907f, 0.0025091557763516903f, 0.0025132247246801853f, 0.002658940153196454f, 0.0023901399690657854f, 0.0025190713349729776f, 0.0028283020947128534f, 0.002811853773891926f, 0.0027115289121866226f, 0.00211741728708148f, 0.00285256071947515f, 0.002171911532059312f, 0.0022130031138658524f, 0.002303643152117729f, 0.002377219032496214f, 0.002223310060799122f, 0.0021961387246847153f, 0.002160971285775304f, 0.003122426802292466f, 0.0030175046995282173f, 0.0018945375923067331f, 0.002333655022084713f, 0.002369777299463749f, 0.0029737174045294523f, 0.0026908833533525467f, 0.0031674772035330534f, 0.0022736627142876387f, 0.002702999161556363f, 0.002548393327742815f, 0.0032776950392872095f, 0.002842726418748498f, 0.002775892149657011f, 0.002618653466925025f, 0.0030312829185277224f, 0.003096217755228281f, 0.0031533653382211924f, 0.002596446545794606f, 0.002624772721901536f, 0.002569537376984954f, 0.0036089932546019554f, 0.0026876607444137335f, 0.0025407541543245316f, 0.0027447007596492767f, 0.002986815059557557f, 0.003107263706624508f, 0.0019443727796897292f, 0.001984736416488886f, 0.0023186076432466507f, 0.00258411793038249f, 0.0024002064019441605f, 0.0029276784043759108f, 0.0021870709024369717f, 0.00253436085768044f, 0.0035711918026208878f, 0.0027162781916558743f, 0.0020179138518869877f, 0.002366316504776478f, 0.004182660952210426f, 0.002225971082225442f, 0.0031187930144369602f, 0.002258847700431943f, 0.003233067924156785f, 0.002801339142024517f, 0.002653589006513357f, 0.002552205929532647f, 0.00243007973767817f, 0.00303220865316689f, 0.002221418311819434f, 0.002403849270194769f, 0.0022183614782989025f, 0.0030523939058184624f, 0.00414053350687027f, 0.0020355870947241783f, 0.0018881364958360791f, 0.0021790743339806795f, 0.0038992862682789564f, 0.002051000250503421f, 0.0024269847199320793f, 0.0031915672589093447f, 0.002422850579023361f, 0.002891675103455782f, 0.0024590766988694668f, 0.002655029296875f, 0.0022254118230193853f, 0.0027914594393223524f, 0.003166140988469124f, 0.002803190378472209f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #59 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.3655974625144154e-05f, 8.551019709557295e-05f, 6.767028389731422e-05f, 6.425872561521828e-05f, 5.3542578825727105e-05f, 5.249376408755779e-05f, 5.403198520070873e-05f, 8.616527338745072e-05f, 5.341261567082256e-05f, 5.337240872904658e-05f, 9.995729487854987e-05f, 7.537898636655882e-05f, 5.1659171731444076e-05f, 6.608283001696691e-05f, 6.724058039253578e-05f, 6.402743747457862e-05f, 5.290890112519264e-05f, 7.371954416157678e-05f, 7.194707723101601e-05f, 6.290461897151545e-05f, 6.842691072961316e-05f, 6.14898162893951e-05f, 5.530882117454894e-05f, 6.811154162278399e-05f, 7.172816549427807e-05f, 7.268892659340054e-05f, 4.751106462208554e-05f, 6.028885400155559e-05f, 4.858465035795234e-05f, 6.276927160797641e-05f, 6.229485006770119e-05f, 7.435377483488992e-05f, 5.504049113369547e-05f, 6.355476216413081e-05f, 5.682267146767117e-05f, 8.808500570012257e-05f, 6.367898458847776e-05f, 4.610946780303493e-05f, 6.50532529107295e-05f, 5.790869181510061e-05f, 8.323894871864468e-05f, 7.551978342235088e-05f, 5.9038960898760706e-05f, 5.913470158702694e-05f, 6.256329652387649e-05f, 5.623859033221379e-05f, 5.9272268117638305e-05f, 6.654828757746145e-05f, 6.61612648400478e-05f, 6.380068225553259e-05f, 4.9821584980236366e-05f, 6.711907917633653e-05f, 5.110380152473226e-05f, 5.207066351431422e-05f, 5.420337038231082e-05f, 5.593456808128394e-05f, 5.231317845755257e-05f, 5.16738546139095e-05f, 5.0846385420300066e-05f, 7.346886559389532e-05f, 7.100011134753004e-05f, 4.45773548563011e-05f, 5.490953117259778e-05f, 5.575946852331981e-05f, 6.996982119744644e-05f, 6.331490294542164e-05f, 7.452887803083286e-05f, 5.3497948101721704e-05f, 6.359998224070296e-05f, 5.996219624648802e-05f, 7.712224032729864e-05f, 6.688768189633265e-05f, 6.531510734930634e-05f, 6.161537748994306e-05f, 7.132430619094521e-05f, 7.285218453034759e-05f, 7.419683242915198e-05f, 6.109286186983809e-05f, 6.175936141517013e-05f, 6.045970440027304e-05f, 8.491749031236395e-05f, 6.323908019112423e-05f, 5.978245098958723e-05f, 6.458119605667889e-05f, 7.027800165815279e-05f, 7.311208901228383e-05f, 4.57499481854029e-05f, 4.669968257076107e-05f, 5.4555475799134e-05f, 6.080277671571821e-05f, 5.64754445804283e-05f, 6.888655479997396e-05f, 5.146049443283118e-05f, 5.963202056591399e-05f, 8.40280408738181e-05f, 6.391242641257122e-05f, 4.7480327339144424e-05f, 5.567803600570187e-05f, 9.841555583989248e-05f, 5.237579171080142e-05f, 7.338336581597105e-05f, 5.3149356972426176e-05f, 7.607218867633492e-05f, 6.591386045329273e-05f, 6.243738607736304e-05f, 6.0051905165892094e-05f, 5.7178349379682913e-05f, 7.134609040804207e-05f, 5.22686677868478e-05f, 5.656115899910219e-05f, 5.219674130785279e-05f, 7.182103581726551e-05f, 9.742432303028181e-05f, 4.789616650668904e-05f, 4.44267425336875e-05f, 5.12723381689284e-05f, 9.174791193800047e-05f, 4.82588293380104e-05f, 5.710552431992255e-05f, 7.50957042328082e-05f, 5.7008248404599726e-05f, 6.803941505495459e-05f, 5.786063047708012e-05f, 6.247127748792991e-05f, 5.236263314145617e-05f, 6.568140088347718e-05f, 7.449743861798197e-05f, 6.595742161152884e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #60 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0056696790270507336f, 0.008241244591772556f, 0.005194553639739752f, 0.004157221410423517f, 0.005689661484211683f, 0.009030363522469997f, 0.00896777305752039f, 0.006716701667755842f, 0.00453453091904521f, 0.00525089493021369f, 0.0049724457785487175f, 0.009765733033418655f, 0.005141301546245813f, 0.004625586327165365f, 0.004220971371978521f, 0.0044863116927444935f, 0.010189438238739967f, 0.00655242009088397f, 0.011370409280061722f, 0.0050045219250023365f, 0.010794784873723984f, 0.004893649369478226f, 0.006448694970458746f, 0.0055406466126441956f, 0.0044830976985394955f, 0.0060789501294493675f, 0.00752445450052619f, 0.005221950355917215f, 0.005658344365656376f, 0.006024249363690615f, 0.010523221455514431f, 0.008732089772820473f, 0.007167438976466656f, 0.006440923549234867f, 0.003875081893056631f, 0.006266892421990633f, 0.004979582037776709f, 0.006594722159206867f, 0.004946508910506964f, 0.005352434236556292f, 0.005281499121338129f, 0.008625934831798077f, 0.006697247736155987f, 0.005574369803071022f, 0.003953323233872652f, 0.0048639047890901566f, 0.007403072435408831f, 0.00950201041996479f, 0.004673351533710957f, 0.006518710404634476f, 0.005980235058814287f, 0.005104016046971083f, 0.006313169375061989f, 0.004691054113209248f, 0.005191250238567591f, 0.006772086955606937f, 0.00716787576675415f, 0.010922924615442753f, 0.006857350934296846f, 0.0044352165423333645f, 0.010153047740459442f, 0.006261624861508608f, 0.004938696976751089f, 0.0075620245188474655f, 0.00625905767083168f, 0.008374308235943317f, 0.0048629227094352245f, 0.0041904691606760025f, 0.008434528484940529f, 0.005610673222690821f, 0.006606265902519226f, 0.007170591503381729f, 0.006741298362612724f, 0.0043554361909627914f, 0.0072845397517085075f, 0.00593098159879446f, 0.006167394574731588f, 0.005360891576856375f, 0.006895354483276606f, 0.012403878383338451f, 0.005578698590397835f, 0.00470307981595397f, 0.009711331687867641f, 0.0052991523407399654f, 0.006767674814909697f, 0.004788846243172884f, 0.00652774702757597f, 0.009218268096446991f, 0.007403465919196606f, 0.00735913310199976f, 0.012113403528928757f, 0.005144045688211918f, 0.007943433709442616f, 0.004191886633634567f, 0.004749591462314129f, 0.00452963775023818f, 0.00884699635207653f, 0.006776039954274893f, 0.006503616459667683f, 0.006680019665509462f, 0.004413737915456295f, 0.005024798680096865f, 0.004777451977133751f, 0.007234321907162666f, 0.004293827805668116f, 0.004941274411976337f, 0.006890728138387203f, 0.00716771837323904f, 0.0055809649638831615f, 0.009177105501294136f, 0.00543984305113554f, 0.007641370873898268f, 0.006795122753828764f, 0.009225788526237011f, 0.006981279700994492f, 0.005103609524667263f, 0.00444297818467021f, 0.004822004586458206f, 0.010596880689263344f, 0.004384794272482395f, 0.00484608206897974f, 0.00977377314120531f, 0.00462185638025403f, 0.0110738854855299f, 0.007368368096649647f, 0.005100158043205738f, 0.005285327322781086f, 0.006129208020865917f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #61 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001334042171947658f, 0.00019391164823900908f, 0.00012222479563206434f, 9.781697735888883e-05f, 0.00013387438957579434f, 0.00021247914992272854f, 0.00021100642334204167f, 0.00015804004215169698f, 0.00010669484618119895f, 0.00012355047510936856f, 0.00011699872993631288f, 0.00022978195920586586f, 0.00012097180297132581f, 0.0001088373246602714f, 9.931697422871366e-05f, 0.00010556027700658888f, 0.00023975149088073522f, 0.00015417458780575544f, 0.00026753905694931746f, 0.00011775345774367452f, 0.0002539949491620064f, 0.0001151446922449395f, 0.00015173399879131466f, 0.00013036816380918026f, 0.00010548465070314705f, 0.0001430341217201203f, 0.00017704599304124713f, 0.00012286941637285054f, 0.00013313752424437553f, 0.00014174704847391695f, 0.0002476052031852305f, 0.00020546093583106995f, 0.00016864562348928303f, 0.000151551139424555f, 9.117840090766549e-05f, 0.00014745628868695349f, 0.0001171666372101754f, 0.00015516993880737573f, 0.00011638844443950802f, 0.0001259396376553923f, 0.0001242705766344443f, 0.00020296317234169692f, 0.00015758229710627347f, 0.00013116165064275265f, 9.30193709791638e-05f, 0.0001144448178820312f, 0.00017418994684703648f, 0.00022357671696227044f, 0.00010996121272910386f, 0.00015338142111431807f, 0.00014071141777094454f, 0.00012009449710603803f, 0.0001485451648477465f, 0.00011037774675060064f, 0.00012214707385282964f, 0.00015934322436805815f, 0.00016865589714143425f, 0.00025700998958200216f, 0.00016134943871293217f, 0.00010435804142616689f, 0.00023889524163678288f, 0.00014733235002495348f, 0.00011620463919825852f, 0.00017792999278753996f, 0.00014727194502484053f, 0.00019704255100805312f, 0.00011442170944064856f, 9.859927376965061e-05f, 0.00019845950009766966f, 0.00013201584806665778f, 0.0001554415503051132f, 0.00016871980915311724f, 0.00015861878637224436f, 0.00010248085163766518f, 0.00017140094132628292f, 0.00013955251779407263f, 0.00014511517656501383f, 0.00012613862054422498f, 0.00016224363935180008f, 0.00029185597668401897f, 0.000131263499497436f, 0.00011066070146625862f, 0.00022850192908663303f, 0.0001246859465027228f, 0.00015923941100481898f, 0.00011267873924225569f, 0.00015359405369963497f, 0.00021690042922273278f, 0.00017419920186512172f, 0.0001731560769258067f, 0.0002850212622433901f, 0.00012103636981919408f, 0.0001869043189799413f, 9.863262675935403e-05f, 0.00011175509280292317f, 0.00010657971142791212f, 0.0002081646234728396f, 0.00015943624021019787f, 0.00015302626707125455f, 0.00015717693895567209f, 0.00010385266068624333f, 0.00011823055683635175f, 0.00011241063475608826f, 0.00017021934036165476f, 0.00010103124805027619f, 0.00011626528430497274f, 0.00016213477647397667f, 0.00016865220095496625f, 0.00013131683226674795f, 0.00021593189740087837f, 0.00012799630349036306f, 0.00017979695985559374f, 0.00015988523955456913f, 0.00021707738051190972f, 0.00016426540969405323f, 0.00012008492922177538f, 0.0001045406679622829f, 0.00011345893290126696f, 0.00024933836539275944f, 0.00010317163105355576f, 0.00011402546078898013f, 0.00022997113410383463f, 0.00010874956205952913f, 0.00026056202477775514f, 0.00017337336612399668f, 0.00012000372225884348f, 0.00012436063843779266f, 0.00014421666855923831f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #62 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002143391640856862f, 0.002570032374933362f, 0.0024900734424591064f, 0.0024434521328657866f, 0.0035931486636400223f, 0.0035446682013571262f, 0.002464818535372615f, 0.002336525358259678f, 0.0023807703983038664f, 0.003117801621556282f, 0.002736370312049985f, 0.0026524807326495647f, 0.0026502935215830803f, 0.0027382499538362026f, 0.0021125986240804195f, 0.0022013355046510696f, 0.002850873861461878f, 0.0029512690380215645f, 0.002584706526249647f, 0.002158086048439145f, 0.0028486214578151703f, 0.00257583474740386f, 0.0027739284560084343f, 0.0027398185338824987f, 0.00296750757843256f, 0.002580731874331832f, 0.0024706628173589706f, 0.00302316527813673f, 0.0026598782278597355f, 0.002668608445674181f, 0.002728264080360532f, 0.003013008739799261f, 0.0029180790297687054f, 0.0023215815890580416f, 0.0023434448521584272f, 0.0027076033875346184f, 0.0035946054849773645f, 0.002895834855735302f, 0.0026715926360338926f, 0.0024329936131834984f, 0.002815622603520751f, 0.0026607769541442394f, 0.0022350044455379248f, 0.0025384556502103806f, 0.002126550069078803f, 0.0024849153123795986f, 0.0030486576724797487f, 0.0030282558873295784f, 0.0018031955696642399f, 0.0017490324098616838f, 0.0028284501750022173f, 0.001810469664633274f, 0.002613670192658901f, 0.002332647331058979f, 0.0019592922180891037f, 0.002765890210866928f, 0.0026992529164999723f, 0.0021171707194298506f, 0.002723830286413431f, 0.0026042996905744076f, 0.001979813678190112f, 0.002435882342979312f, 0.002682050922885537f, 0.0030658997129648924f, 0.0022738848347216845f, 0.002673220820724964f, 0.002064966829493642f, 0.0026281739119440317f, 0.0024661491625010967f, 0.00259138154797256f, 0.0032275922130793333f, 0.0029826487880200148f, 0.0029104261193424463f, 0.003499163081869483f, 0.003573163878172636f, 0.0026880039367824793f, 0.003730106633156538f, 0.0022620533127337694f, 0.002663441002368927f, 0.0023753594141453505f, 0.0027514412067830563f, 0.003492222400382161f, 0.0030384964775294065f, 0.0028191255405545235f, 0.0035649952478706837f, 0.002633551601320505f, 0.0019319149432703853f, 0.0022450408432632685f, 0.001994404708966613f, 0.0027477573603391647f, 0.0025353049859404564f, 0.002928767818957567f, 0.0025289233308285475f, 0.0029879508074373007f, 0.0023946892470121384f, 0.00262172962538898f, 0.0033962130546569824f, 0.002874684287235141f, 0.00229846965521574f, 0.0023938152007758617f, 0.003343190997838974f, 0.00215285480953753f, 0.002997001865878701f, 0.0019166588317602873f, 0.002995158778503537f, 0.002244924195110798f, 0.003009235253557563f, 0.003754371078684926f, 0.0021623047068715096f, 0.0023396096657961607f, 0.0021588813979178667f, 0.002686593681573868f, 0.0027919874992221594f, 0.0026997902896255255f, 0.0029141686391085386f, 0.0026637825649231672f, 0.0024219241458922625f, 0.001911028171889484f, 0.0025698277167975903f, 0.0020574929658323526f, 0.0024666867684572935f, 0.0023685311898589134f, 0.0025757625699043274f, 0.0026144443545490503f, 0.003056531772017479f, 0.0022393525578081608f, 0.00254419376142323f, 0.0026328428648412228f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #63 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.043274722993374e-05f, 6.047134957043454e-05f, 5.8589965192368254e-05f, 5.749299089075066e-05f, 8.454467752017081e-05f, 8.340396016137674e-05f, 5.799573045806028e-05f, 5.497706661117263e-05f, 5.601812881650403e-05f, 7.336003909585997e-05f, 6.438518175855279e-05f, 6.241130904527381e-05f, 6.235984619706869e-05f, 6.442941230488941e-05f, 4.9708203732734546e-05f, 5.179613071959466e-05f, 6.707938882755116e-05f, 6.944162305444479e-05f, 6.081662650103681e-05f, 5.077849709778093e-05f, 6.702639075228944e-05f, 6.0607879277085885e-05f, 6.526890501845628e-05f, 6.446632323786616e-05f, 6.982371269259602e-05f, 6.07231049798429e-05f, 5.813324241898954e-05f, 7.113330502761528e-05f, 6.258537177927792e-05f, 6.279078661464155e-05f, 6.419444980565459e-05f, 7.089432619977742e-05f, 6.866068724775687e-05f, 5.46254486835096e-05f, 5.5139880714705214e-05f, 6.370831397362053e-05f, 8.457895455649123e-05f, 6.813729123678058e-05f, 6.286100688157603e-05f, 5.7246910728281364e-05f, 6.624994421144947e-05f, 6.260651571210474e-05f, 5.2588340622605756e-05f, 5.972836879664101e-05f, 5.003647311241366e-05f, 5.846859494340606e-05f, 7.173312042141333e-05f, 7.125308184185997e-05f, 4.24281315645203e-05f, 4.115370393265039e-05f, 6.655177276115865e-05f, 4.259928755345754e-05f, 6.149812543299049e-05f, 5.488581882673316e-05f, 4.6100994950393215e-05f, 6.50797737762332e-05f, 6.351183401420712e-05f, 4.9815782404039055e-05f, 6.409012712538242e-05f, 6.127764208940789e-05f, 4.6583852963522077e-05f, 5.731487908633426e-05f, 6.310707976808771e-05f, 7.213882054202259e-05f, 5.350317223928869e-05f, 6.289931479841471e-05f, 4.858745523961261e-05f, 6.183938967296854e-05f, 5.802703890367411e-05f, 6.097368532209657e-05f, 7.594334601890296e-05f, 7.01799726812169e-05f, 6.848061457276344e-05f, 8.233325206674635e-05f, 8.407444693148136e-05f, 6.324714922811836e-05f, 8.776721369940788e-05f, 5.322478318703361e-05f, 6.266919808695093e-05f, 5.589081047219224e-05f, 6.473979738075286e-05f, 8.216994319809601e-05f, 7.149403973016888e-05f, 6.633236625930294e-05f, 8.388224523514509e-05f, 6.196591857587919e-05f, 4.545682168100029e-05f, 5.28244927409105e-05f, 4.692716902354732e-05f, 6.46531188976951e-05f, 5.96542377024889e-05f, 6.891218799864873e-05f, 5.950408012722619e-05f, 7.030472625046968e-05f, 5.634563058265485e-05f, 6.168775871628895e-05f, 7.991089660208672e-05f, 6.763963028788567e-05f, 5.408163997344673e-05f, 5.632506508845836e-05f, 7.866331725381315e-05f, 5.065540972282179e-05f, 7.051769352983683e-05f, 4.509785503614694e-05f, 7.04743288224563e-05f, 5.2821746066911146e-05f, 7.080553768901154e-05f, 8.833814354147762e-05f, 5.0877759349532425e-05f, 5.5049640650395304e-05f, 5.079721086076461e-05f, 6.321397086139768e-05f, 6.56938282190822e-05f, 6.352447962854058e-05f, 6.85686754877679e-05f, 6.26772380201146e-05f, 5.698645327356644e-05f, 4.496537076192908e-05f, 6.046653652447276e-05f, 4.84115989820566e-05f, 5.803968815598637e-05f, 5.573014641413465e-05f, 6.0606180340982974e-05f, 6.151633715489879e-05f, 7.19183954061009e-05f, 5.269064786261879e-05f, 5.98633851041086e-05f, 6.194924208102748e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #64 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0066388072445988655f, 0.004205390345305204f, 0.004479760304093361f, 0.005615423433482647f, 0.010135654360055923f, 0.005449003539979458f, 0.005183429457247257f, 0.0063761440105736256f, 0.004638529382646084f, 0.0044395048171281815f, 0.0062735299579799175f, 0.007764166686683893f, 0.004559889901429415f, 0.004308958072215319f, 0.00863438006490469f, 0.0071439193561673164f, 0.007564278785139322f, 0.005192942451685667f, 0.004579415079206228f, 0.0035383158829063177f, 0.007382581941783428f, 0.0044291578233242035f, 0.008575290441513062f, 0.009330052882432938f, 0.008474190719425678f, 0.006929824128746986f, 0.004326569382101297f, 0.008652369491755962f, 0.007567133288830519f, 0.012093976140022278f, 0.008147443644702435f, 0.006512751802802086f, 0.005379187408834696f, 0.006903042085468769f, 0.006275045685470104f, 0.007615154143422842f, 0.006555124185979366f, 0.005292731337249279f, 0.005355294328182936f, 0.009526306763291359f, 0.004102635197341442f, 0.005519614554941654f, 0.004572972189635038f, 0.007910250686109066f, 0.0073918793350458145f, 0.00553264282643795f, 0.0049338494427502155f, 0.0055540078319609165f, 0.00958299171179533f, 0.010358859784901142f, 0.005362249910831451f, 0.008197794668376446f, 0.006447128485888243f, 0.004712261725217104f, 0.0053880237974226475f, 0.005416762549430132f, 0.006051991600543261f, 0.0066084968857467175f, 0.013666772283613682f, 0.010153532959520817f, 0.006258868146687746f, 0.011364584788680077f, 0.006187449209392071f, 0.005320822820067406f, 0.006630017422139645f, 0.008950373157858849f, 0.004392134491354227f, 0.006176139693707228f, 0.009696961380541325f, 0.0034860370215028524f, 0.008113069459795952f, 0.0066149127669632435f, 0.0047090984880924225f, 0.004664896056056023f, 0.0055649494752287865f, 0.014016548171639442f, 0.0055475695990026f, 0.00714313006028533f, 0.004888402763754129f, 0.004356353543698788f, 0.004829663783311844f, 0.0058077070862054825f, 0.00797616969794035f, 0.0048651983961462975f, 0.007320081349462271f, 0.00447841314598918f, 0.0048974803648889065f, 0.006091156043112278f, 0.007648248691111803f, 0.0074176485650241375f, 0.004682197701185942f, 0.005115942098200321f, 0.005409829318523407f, 0.003711032448336482f, 0.012250065803527832f, 0.004251699894666672f, 0.007397121284157038f, 0.008197381161153316f, 0.004731314722448587f, 0.0045807319693267345f, 0.007849880494177341f, 0.004709247965365648f, 0.005607579834759235f, 0.004381999839097261f, 0.0043182773515582085f, 0.005012271460145712f, 0.007549842353910208f, 0.006659270264208317f, 0.005200490355491638f, 0.0077668786980211735f, 0.004768465645611286f, 0.007797213736921549f, 0.00459750322625041f, 0.0041853273287415504f, 0.005715743638575077f, 0.0052537680603563786f, 0.006227562204003334f, 0.006259124726057053f, 0.008264248259365559f, 0.007346926722675562f, 0.00800276268273592f, 0.0036278122570365667f, 0.004632257856428623f, 0.0043046786449849606f, 0.005294910632073879f, 0.004237181041389704f, 0.0049921381287276745f, 0.005808607675135136f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #65 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00015620722842868418f, 9.89503605524078e-05f, 0.00010540612856857479f, 0.00013212760677561164f, 0.0002384859835729003f, 0.00012821184645872563f, 0.00012196305033285171f, 0.00015002691361587495f, 0.00010914186714217067f, 0.00010445893713040277f, 0.00014761247439309955f, 0.00018268627172801644f, 0.0001072915256372653f, 0.00010138725338038057f, 0.0002031618932960555f, 0.00016809222870506346f, 0.00017798303451854736f, 0.00012218688789289445f, 0.00010775094415294006f, 8.325449016410857e-05f, 0.00017370781279169023f, 0.0001042154835886322f, 0.0002017715451074764f, 0.00021953065879642963f, 0.00019939272897318006f, 0.0001630546903470531f, 0.00010180163371842355f, 0.000203585164854303f, 0.00017805019160732627f, 0.0002845641574822366f, 0.00019170455925632268f, 0.000153241227963008f, 0.00012656912440434098f, 0.00016242451965808868f, 0.00014764814113732427f, 0.00017918010416906327f, 0.00015423822333104908f, 0.00012453485396690667f, 0.00012600692571140826f, 0.00022414840350393206f, 9.653259621700272e-05f, 0.00012987328227609396f, 0.00010759934957604855f, 0.0001861235505202785f, 0.00017392657173331827f, 0.00013017983292229474f, 0.00011609057401074097f, 0.0001306825433857739f, 0.00022548215929418802f, 0.00024373788619413972f, 0.0001261705911019817f, 0.00019288928888272494f, 0.0001516971387900412f, 0.00011087674647569656f, 0.00012677702761720866f, 0.00012745324056595564f, 0.0001423998037353158f, 0.00015549405361525714f, 0.00032157113309949636f, 0.00023890666489023715f, 0.00014726749213878065f, 0.0002674020070116967f, 0.00014558703696820885f, 0.00012519583106040955f, 0.00015600041660945863f, 0.0002105970197590068f, 0.00010334434045944363f, 0.00014532094064634293f, 0.0002281638007843867f, 8.20244022179395e-05f, 0.00019089574925601482f, 0.00015564501518383622f, 0.00011080232070526108f, 0.00010976225894410163f, 0.00013093999586999416f, 0.000329801143379882f, 0.0001305310579482466f, 0.00016807364590931684f, 0.00011502124107209966f, 0.00010250243940390646f, 0.00011363915109541267f, 0.00013665192818734795f, 0.00018767458095680922f, 0.00011447526048868895f, 0.0001722372107906267f, 0.00010537442722124979f, 0.00011523483408382162f, 0.00014332131831906736f, 0.0001799587917048484f, 0.00017453290638513863f, 0.00011016936332453042f, 0.00012037510896334425f, 0.00012729009904433042f, 8.73184108058922e-05f, 0.0002882368571590632f, 0.0001000400006887503f, 0.0001740499137667939f, 0.00019287955365143716f, 0.00011132505460409448f, 0.00010778193245641887f, 0.0001847030798671767f, 0.00011080583499278873f, 0.0001319430593866855f, 0.00010310587822459638f, 0.00010160652891499922f, 0.00011793580051744357f, 0.0001776433491613716f, 0.00015668872219976038f, 0.00012236447946634144f, 0.00018275009642820805f, 0.00011219919542782009f, 0.00018346385331824422f, 0.00010817655129358172f, 9.847828914644197e-05f, 0.00013448808749672025f, 0.00012361806875560433f, 0.00014653087418992072f, 0.00014727353118360043f, 0.0001944529067259282f, 0.00017286886577494442f, 0.00018830029875971377f, 8.536029054084793e-05f, 0.00010899430344579741f, 0.00010128656140295789f, 0.00012458613491617143f, 9.969837992684916e-05f, 0.00011746207746909931f, 0.00013667313032783568f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #66 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0021760575473308563f, 0.0028117254842072725f, 0.002232964849099517f, 0.0025744971353560686f, 0.002096783136948943f, 0.0036120677832514048f, 0.0026661467272788286f, 0.0030411076731979847f, 0.0022056703455746174f, 0.0030799901578575373f, 0.002871259581297636f, 0.002808937104418874f, 0.0020846640691161156f, 0.0025743653532117605f, 0.0026133425999432802f, 0.0017773332074284554f, 0.0023565778974443674f, 0.002159257885068655f, 0.0017873727483674884f, 0.00307382270693779f, 0.002599582774564624f, 0.0026154068764299154f, 0.0023699768353253603f, 0.002122018951922655f, 0.001879973104223609f, 0.004005139227956533f, 0.00197499874047935f, 0.003524353029206395f, 0.003906313329935074f, 0.0027147303335368633f, 0.002562906127423048f, 0.0032398246694356203f, 0.003093739738687873f, 0.002249751938506961f, 0.00296372314915061f, 0.002081500831991434f, 0.002876304555684328f, 0.002648686058819294f, 0.0021659452468156815f, 0.0031864286866039038f, 0.003120975336059928f, 0.0032247123308479786f, 0.0022166355047374964f, 0.0025477849412709475f, 0.0021393902134150267f, 0.00216746237128973f, 0.0028536454774439335f, 0.002538735745474696f, 0.0027286552358418703f, 0.00275512901134789f, 0.0023624226450920105f, 0.0025979664642363787f, 0.0030270477291196585f, 0.002698842901736498f, 0.003009261330589652f, 0.0030722389928996563f, 0.0026060298550873995f, 0.0020736309234052896f, 0.0025537549518048763f, 0.002639060840010643f, 0.002422122983261943f, 0.002520224777981639f, 0.0021183218341320753f, 0.002730955835431814f, 0.0030958193819969893f, 0.0025957084726542234f, 0.0028350367210805416f, 0.002726000966504216f, 0.002137979492545128f, 0.002691450761631131f, 0.0035260673612356186f, 0.002169201849028468f, 0.002587671158835292f, 0.002627277746796608f, 0.003811025060713291f, 0.0033779360819607973f, 0.0025904455687850714f, 0.00295299687422812f, 0.002762585412710905f, 0.0027036238461732864f, 0.0027761030942201614f, 0.002532890299335122f, 0.003064611693844199f, 0.003065042896196246f, 0.0025428279768675566f, 0.0022428124211728573f, 0.002301489934325218f, 0.002556696068495512f, 0.003271025139838457f, 0.003306616796180606f, 0.003607855411246419f, 0.003028612583875656f, 0.002419797470793128f, 0.0026835338212549686f, 0.0025174636393785477f, 0.0025151395238935947f, 0.002288177842274308f, 0.0030553059186786413f, 0.0021078004501760006f, 0.0027786241844296455f, 0.0025900949258357286f, 0.002264586975798011f, 0.002436140552163124f, 0.0023211538791656494f, 0.0029454242903739214f, 0.0024040916468948126f, 0.0027892275247722864f, 0.0021771113388240337f, 0.0022603068500757217f, 0.0020595702808350325f, 0.003941805567592382f, 0.002289876574650407f, 0.0037658812943845987f, 0.0029916332568973303f, 0.001877654460258782f, 0.0024385040160268545f, 0.002288280753418803f, 0.002436412265524268f, 0.0034236174542456865f, 0.004216930363327265f, 0.00388296484015882f, 0.002680298639461398f, 0.002868448384106159f, 0.0018858155235648155f, 0.0022838746663182974f, 0.0024694865569472313f, 0.002484086435288191f, 0.003075685352087021f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #67 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.1201353926444426e-05f, 6.615824531763792e-05f, 5.254035204416141e-05f, 6.057640348444693e-05f, 4.9336074880557135e-05f, 8.498983515892178e-05f, 6.273286271607503e-05f, 7.155547791626304e-05f, 5.189812509343028e-05f, 7.247035682667047e-05f, 6.755904905730858e-05f, 6.609263800783083e-05f, 4.9050919187720865e-05f, 6.0573303926503286e-05f, 6.149041291791946e-05f, 4.181960684945807e-05f, 5.544889427255839e-05f, 5.0806069339159876e-05f, 4.2055831727338955e-05f, 7.23252451280132e-05f, 6.116665463196114e-05f, 6.153898721095175e-05f, 5.576416151598096e-05f, 4.992985850549303e-05f, 4.423466089065187e-05f, 9.423857409274206e-05f, 4.6470559027511626e-05f, 8.292595884995535e-05f, 9.191325807478279e-05f, 6.387601024471223e-05f, 6.0303675127215683e-05f, 7.623116835020483e-05f, 7.279387500602752e-05f, 5.2935341955162585e-05f, 6.973466224735603e-05f, 4.8976489779306576e-05f, 6.767775630578399e-05f, 6.232202576939017e-05f, 5.096341919852421e-05f, 7.49747923691757e-05f, 7.343471224885434e-05f, 7.587558502564207e-05f, 5.2156130550429225e-05f, 5.9947880799882114e-05f, 5.03385927004274e-05f, 5.099911504657939e-05f, 6.714460323564708e-05f, 5.973496081423946e-05f, 6.420365389203653e-05f, 6.4826563175302e-05f, 5.558641714742407e-05f, 6.11286232015118e-05f, 7.122465467546135e-05f, 6.350218609441072e-05f, 7.080614886945114e-05f, 7.228797767311335e-05f, 6.131835107225925e-05f, 4.879131665802561e-05f, 6.0088354075560346e-05f, 6.209554703673348e-05f, 5.699113171431236e-05f, 5.929940743953921e-05f, 4.984286715625785e-05f, 6.425778701668605e-05f, 7.284281309694052e-05f, 6.107549415901303e-05f, 6.670675065834075e-05f, 6.414119707187638e-05f, 5.030539978179149e-05f, 6.332825432764366e-05f, 8.296628948301077e-05f, 5.104004594613798e-05f, 6.0886381106683984e-05f, 6.181830394780263e-05f, 8.967117901192978e-05f, 7.948085112730041e-05f, 6.095166099839844e-05f, 6.948228110559285e-05f, 6.50020083412528e-05f, 6.361467967508361e-05f, 6.532007682835683e-05f, 5.959741974947974e-05f, 7.21085089026019e-05f, 7.211865886347368e-05f, 5.9831247199326754e-05f, 5.277205855236389e-05f, 5.4152704251464456e-05f, 6.0157555708428845e-05f, 7.69652979215607e-05f, 7.780274609103799e-05f, 8.489071478834376e-05f, 7.126147102098912e-05f, 5.693641287507489e-05f, 6.314197526080534e-05f, 5.9234440414002165e-05f, 5.917975431657396e-05f, 5.383947791415267e-05f, 7.188955351011828e-05f, 4.959530633641407e-05f, 6.537939043482766e-05f, 6.0943410062463954e-05f, 5.328439874574542e-05f, 5.73209545109421e-05f, 5.461538603412919e-05f, 6.930410017957911e-05f, 5.656686334987171e-05f, 6.5628883021418e-05f, 5.122615038999356e-05f, 5.318369221640751e-05f, 4.846047886530869e-05f, 9.274837066186592e-05f, 5.3879448387306184e-05f, 8.860897651175037e-05f, 7.0391375629697e-05f, 4.418010576046072e-05f, 5.7376564654987305e-05f, 5.384190080803819e-05f, 5.732735007768497e-05f, 8.055570651777089e-05f, 9.922189201461151e-05f, 9.136387961916625e-05f, 6.306585419224575e-05f, 6.749290332663804e-05f, 4.437212919583544e-05f, 5.37382293259725e-05f, 5.810556831420399e-05f, 5.844909537700005e-05f, 7.236906822072342e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #68 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0056218854151666164f, 0.005949766840785742f, 0.007108958438038826f, 0.006187743972986937f, 0.006354900076985359f, 0.007420397363603115f, 0.005536975804716349f, 0.006607728078961372f, 0.006352860014885664f, 0.004896833561360836f, 0.00670631043612957f, 0.00827100221067667f, 0.007180999498814344f, 0.008132132701575756f, 0.010144026950001717f, 0.004354539792984724f, 0.008386940695345402f, 0.007728240452706814f, 0.005286082625389099f, 0.005021825432777405f, 0.007879105396568775f, 0.006142623722553253f, 0.0036391091998666525f, 0.0067885201424360275f, 0.009703806601464748f, 0.004434270318597555f, 0.005647155921906233f, 0.005414396058768034f, 0.006946333218365908f, 0.009944047778844833f, 0.006990394555032253f, 0.003691243939101696f, 0.008057236671447754f, 0.007873029448091984f, 0.006003046408295631f, 0.011396300047636032f, 0.0052152713760733604f, 0.007354049943387508f, 0.008560015819966793f, 0.0051184482872486115f, 0.0068883528001606464f, 0.00451773451641202f, 0.00884217582643032f, 0.010543390177190304f, 0.00789785198867321f, 0.004229818005114794f, 0.006571559701114893f, 0.005992666352540255f, 0.008635849691927433f, 0.00419175298884511f, 0.006856967229396105f, 0.007557577919214964f, 0.008004775270819664f, 0.006874655839055777f, 0.004317540675401688f, 0.007144319359213114f, 0.004787134006619453f, 0.0036729180719703436f, 0.007261053659021854f, 0.0038472197484225035f, 0.004220209550112486f, 0.006722728721797466f, 0.011957439593970776f, 0.00620557926595211f, 0.004879959858953953f, 0.007471419870853424f, 0.004871080629527569f, 0.007144961506128311f, 0.008751722984015942f, 0.0063659921288490295f, 0.0065558478236198425f, 0.009015417657792568f, 0.005237278062850237f, 0.0037124964874237776f, 0.0047981953248381615f, 0.0061526792123913765f, 0.004272373393177986f, 0.005330809857696295f, 0.004090089350938797f, 0.005320670548826456f, 0.006473372224718332f, 0.005109583027660847f, 0.009123512543737888f, 0.005810236092656851f, 0.003655106294900179f, 0.0065688518807291985f, 0.009138817898929119f, 0.009565486572682858f, 0.007170279044657946f, 0.011254759505391121f, 0.006448095198720694f, 0.006826247554272413f, 0.007795897778123617f, 0.004457121714949608f, 0.013003392145037651f, 0.007811392191797495f, 0.01068249810487032f, 0.005790541414171457f, 0.004836530890315771f, 0.0066774943843483925f, 0.00585912587121129f, 0.004733602982014418f, 0.0034503904171288013f, 0.007432167883962393f, 0.0042331828735768795f, 0.006532585248351097f, 0.007859848439693451f, 0.008839488960802555f, 0.011421896517276764f, 0.009397996589541435f, 0.007034109905362129f, 0.006304868496954441f, 0.004679575562477112f, 0.006886281538754702f, 0.005601569544523954f, 0.004119492135941982f, 0.006812702398747206f, 0.007336713839322329f, 0.006506934762001038f, 0.00492263725027442f, 0.0038060799706727266f, 0.005980051588267088f, 0.00785058457404375f, 0.007465846370905638f, 0.008979657664895058f, 0.004013267811387777f, 0.0075004915706813335f, 0.007557077333331108f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #69 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00013227965973783284f, 0.00013999451766721904f, 0.00016726960893720388f, 0.00014559397823177278f, 0.00014952706987969577f, 0.00017459758964832872f, 0.00013028178364038467f, 0.00015547595103271306f, 0.0001494790631113574f, 0.00011521961278049275f, 0.00015779554087202996f, 0.00019461181364022195f, 0.00016896470333449543f, 0.000191344297491014f, 0.00023868298740126193f, 0.00010245975863654166f, 0.00019733978842850775f, 0.0001818409509724006f, 0.00012437842087820172f, 0.00011816059850389138f, 0.00018539071606937796f, 0.00014453232870437205f, 8.562610310036689e-05f, 0.00015972988330759108f, 0.00022832486138213426f, 0.00010433577699586749f, 0.00013287426554597914f, 0.00012739755038637668f, 0.00016344313917215914f, 0.00023397759650833905f, 0.0001644798758206889f, 8.685280045028776e-05f, 0.00018958204600494355f, 0.00018524775805417448f, 0.00014124815061222762f, 0.00026814822922460735f, 0.0001227122702402994f, 0.00017303647473454475f, 0.0002014121419051662f, 0.0001204340805998072f, 0.00016207889711949974f, 0.00010629963799146935f, 0.0002080512058455497f, 0.000248079770244658f, 0.00018583181372378021f, 9.952513210009784e-05f, 0.00015462494047824293f, 0.0001410039112670347f, 0.0002031964686466381f, 9.86294835456647e-05f, 0.00016134040197357535f, 0.000177825364517048f, 0.00018834765069186687f, 0.0001617566158529371f, 0.00010158919758396223f, 0.000168101629242301f, 0.00011263845226494595f, 8.642160537419841e-05f, 0.00017084831779357046f, 9.052282257471234e-05f, 9.929905354510993e-05f, 0.00015818185056559741f, 0.0002813515311572701f, 0.00014601362636312842f, 0.0001148225856013596f, 0.000175798122654669f, 0.00011461366375442594f, 0.00016811674868222326f, 0.00020592290093190968f, 0.00014978805847931653f, 0.00015425524907186627f, 0.0002121274737874046f, 0.00012323007103987038f, 8.735286246519536e-05f, 0.0001128987132688053f, 0.00014476892829407007f, 0.00010052643483504653f, 0.00012543081538751721f, 9.623739606468007e-05f, 0.00012519225128926337f, 0.00015231464931275696f, 0.00012022548617096618f, 0.000214670886634849f, 0.00013671144552063197f, 8.600250293966383e-05f, 0.00015456121764145792f, 0.00021503101743292063f, 0.00022507028188556433f, 0.00016871244588401169f, 0.0002648178779054433f, 0.00015171988343354315f, 0.00016061759379226714f, 0.00018343288684263825f, 0.00010487345571164042f, 0.00030596216674894094f, 0.00018379747052676976f, 0.0002513529034331441f, 0.00013624803978018463f, 0.00011380072828615084f, 0.00015711752348579466f, 0.0001378617889713496f, 0.00011137889669043943f, 8.118565892800689e-05f, 0.000174874541698955f, 9.960430179489776e-05f, 0.00015370789333246648f, 0.0001849376130849123f, 0.00020798797777388245f, 0.000268750503892079f, 0.00022112933220341802f, 0.00016550847794860601f, 0.00014834984904155135f, 0.00011010766320396215f, 0.00016203016275539994f, 0.00013180164387449622f, 9.69292304944247e-05f, 0.00016029887774493545f, 0.0001726285699987784f, 0.00015310435264836997f, 0.0001158267623395659f, 8.955482189776376e-05f, 0.0001407070958521217f, 0.0001847196399467066f, 0.00017566698079463094f, 0.0002112860674969852f, 9.442982991458848e-05f, 0.00017648216453380883f, 0.00017781359201762825f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #70 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002631600946187973f, 0.0024131713435053825f, 0.0024035670794546604f, 0.0022327692713588476f, 0.0021812799386680126f, 0.002015415346249938f, 0.0019422413315623999f, 0.0017235161503776908f, 0.00236219703219831f, 0.002703661797568202f, 0.0035229374188929796f, 0.0028078765608370304f, 0.002337444806471467f, 0.0023799357004463673f, 0.0021739236544817686f, 0.0029508769512176514f, 0.0028930003754794598f, 0.0022439907770603895f, 0.0026455039624124765f, 0.0027542042080312967f, 0.0026496967766433954f, 0.0032824333757162094f, 0.0023925427813082933f, 0.0025848797522485256f, 0.002540448447689414f, 0.002486123237758875f, 0.0034489650279283524f, 0.0023458609357476234f, 0.0029387036338448524f, 0.002546915551647544f, 0.0021646865643560886f, 0.0019175675697624683f, 0.0024315291084349155f, 0.001949857221916318f, 0.0027201836928725243f, 0.002572133671492338f, 0.0033638819586485624f, 0.002553231082856655f, 0.0024369864258915186f, 0.002324433298781514f, 0.002671148395165801f, 0.0022964286617934704f, 0.0023840325884521008f, 0.0018848772160708904f, 0.0023665730841457844f, 0.0019994836766272783f, 0.0022843291517347097f, 0.0030354654882103205f, 0.0022648212034255266f, 0.0031960702035576105f, 0.002395155606791377f, 0.0033691751305013895f, 0.002597035141661763f, 0.0020616480614989996f, 0.0027533858083188534f, 0.0029282181058079004f, 0.0024705431424081326f, 0.002887400332838297f, 0.0023795808665454388f, 0.0020554340444505215f, 0.0019081805367022753f, 0.0018849348416551948f, 0.002614388708025217f, 0.002452897373586893f, 0.00300956261344254f, 0.0024069901555776596f, 0.0024498431012034416f, 0.0033000041730701923f, 0.0035435569006949663f, 0.004240944515913725f, 0.0019374156836420298f, 0.0019144763937219977f, 0.002405616920441389f, 0.001791086746379733f, 0.0026869738940149546f, 0.002404590370133519f, 0.0020751329138875008f, 0.0018135077552869916f, 0.001939778565429151f, 0.0023290226235985756f, 0.002474426291882992f, 0.0022229424212127924f, 0.0026101258117705584f, 0.002060661790892482f, 0.0030705295503139496f, 0.003040245734155178f, 0.002372813643887639f, 0.0018466893816366792f, 0.0023755182046443224f, 0.002320342231541872f, 0.0024018597323447466f, 0.003208545036613941f, 0.002849316457286477f, 0.0030054543167352676f, 0.003372115781530738f, 0.002670534187927842f, 0.0028111475985497236f, 0.002472494263201952f, 0.002084776060655713f, 0.001981399953365326f, 0.0017380357021465898f, 0.0027792660985141993f, 0.0019485366065055132f, 0.0020665423944592476f, 0.002309901872649789f, 0.0025170575827360153f, 0.003086019540205598f, 0.0023373046424239874f, 0.00237270281650126f, 0.0021081995218992233f, 0.0021463024895638227f, 0.002298584906384349f, 0.0026869296561926603f, 0.0031904345378279686f, 0.0028702954296022654f, 0.0026090359315276146f, 0.0021620693150907755f, 0.002445376943796873f, 0.002228568773716688f, 0.002252154052257538f, 0.0025064083747565746f, 0.0022890681866556406f, 0.0021426118910312653f, 0.0022686554584652185f, 0.0021265947725623846f, 0.003103573340922594f, 0.0023185124155133963f, 0.0023590552154928446f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #71 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(6.192002183524892e-05f, 5.678050365531817e-05f, 5.655451968777925e-05f, 5.253575000097044e-05f, 5.132423393661156e-05f, 4.742153760162182e-05f, 4.569979864754714e-05f, 4.055332101415843e-05f, 5.5581109336344525e-05f, 6.361557461787015e-05f, 8.289264951599762e-05f, 6.606768147321418e-05f, 5.4998701671138406e-05f, 5.599848736892454e-05f, 5.1151146180927753e-05f, 6.943239714019e-05f, 6.807059980928898e-05f, 5.279978358885273e-05f, 6.224715616554022e-05f, 6.480480806203559e-05f, 6.234581087483093e-05f, 7.723372982582077e-05f, 5.6295124522875994e-05f, 6.082070103730075e-05f, 5.977525870548561e-05f, 5.849701847182587e-05f, 8.11521167634055e-05f, 5.519672777154483e-05f, 6.914597179275006e-05f, 5.992742444504984e-05f, 5.093380241305567e-05f, 4.5119239075575024e-05f, 5.721245179302059e-05f, 4.587899456964806e-05f, 6.400432175723836e-05f, 6.0520793340401724e-05f, 7.915016612969339e-05f, 6.007602496538311e-05f, 5.73408578929957e-05f, 5.46925475646276e-05f, 6.285055133048445e-05f, 5.403361501521431e-05f, 5.609488653135486e-05f, 4.435005394043401e-05f, 5.568407505052164e-05f, 4.7046676627360284e-05f, 5.374892134568654e-05f, 7.142272079363465e-05f, 5.3289910283638164e-05f, 7.520165672758594e-05f, 5.635660272673704e-05f, 7.927470869617537e-05f, 6.110670801717788e-05f, 4.8509366024518386e-05f, 6.478554860223085e-05f, 6.889925134601071e-05f, 5.813042662339285e-05f, 6.793883221689612e-05f, 5.599013820756227e-05f, 4.836315565626137e-05f, 4.4898366468260065e-05f, 4.435140726855025e-05f, 6.151502748252824e-05f, 5.7715235016075894e-05f, 7.081324292812496e-05f, 5.663506453856826e-05f, 5.76433667447418e-05f, 7.764715701341629e-05f, 8.337781036971137e-05f, 9.978692833101377e-05f, 4.5586253690999e-05f, 4.504650496528484e-05f, 5.660275201080367e-05f, 4.2143219616264105e-05f, 6.322291301330552e-05f, 5.657859946950339e-05f, 4.8826655984157696e-05f, 4.267077019903809e-05f, 4.564184928312898e-05f, 5.4800533689558506e-05f, 5.822179446113296e-05f, 5.23045273439493e-05f, 6.141472840681672e-05f, 4.848615935770795e-05f, 7.224775617942214e-05f, 7.15351925464347e-05f, 5.583091115113348e-05f, 4.345151683082804e-05f, 5.5894546676427126e-05f, 5.459629028337076e-05f, 5.651434912579134e-05f, 7.549517613369972e-05f, 6.704273982904851e-05f, 7.071657455526292e-05f, 7.934390305308625e-05f, 6.283610127866268e-05f, 6.614465382881463e-05f, 5.817633791593835e-05f, 4.9053556722356007e-05f, 4.662117498810403e-05f, 4.08949599659536e-05f, 6.53944953228347e-05f, 4.584792259265669e-05f, 4.8624526243656874e-05f, 5.435063212644309e-05f, 5.922488708165474e-05f, 7.261222344823182e-05f, 5.499540566233918e-05f, 5.582830272032879e-05f, 4.960469595971517e-05f, 5.050123581895605e-05f, 5.408435026765801e-05f, 6.322187255136669e-05f, 7.506905240006745e-05f, 6.753636262146756e-05f, 6.138908065622672e-05f, 5.0872218707809225e-05f, 5.753828372689895e-05f, 5.243691339273937e-05f, 5.299186159390956e-05f, 5.8974317653337494e-05f, 5.386042903410271e-05f, 5.041439726483077e-05f, 5.338012852007523e-05f, 5.003752448828891e-05f, 7.302525773411617e-05f, 5.455323480418883e-05f, 5.5507181969005615e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #72 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006094500422477722f, 0.006760233081877232f, 0.008358302526175976f, 0.005758197978138924f, 0.004898133222013712f, 0.0050551448948681355f, 0.0065958076156675816f, 0.008470776490867138f, 0.006904016248881817f, 0.00926760584115982f, 0.00906010065227747f, 0.005921650677919388f, 0.008051522076129913f, 0.010244439356029034f, 0.006688588298857212f, 0.004489076789468527f, 0.007762197405099869f, 0.004923118744045496f, 0.005174355581402779f, 0.0028124500531703234f, 0.005605686455965042f, 0.006926193833351135f, 0.0033680007327347994f, 0.00608358858153224f, 0.006742751691490412f, 0.006608967203646898f, 0.01013985276222229f, 0.010411417111754417f, 0.009147215634584427f, 0.008707186207175255f, 0.0034629059955477715f, 0.007307711057364941f, 0.007545211352407932f, 0.00768983643501997f, 0.00517845107242465f, 0.007284106686711311f, 0.004469385836273432f, 0.006159919314086437f, 0.012566551566123962f, 0.005323091521859169f, 0.007467577699571848f, 0.00879056379199028f, 0.010142513550817966f, 0.005266780033707619f, 0.004381383769214153f, 0.004592859651893377f, 0.006657462567090988f, 0.006529704667627811f, 0.007391713093966246f, 0.005316413473337889f, 0.004881469998508692f, 0.007199566345661879f, 0.006098873447626829f, 0.007502988912165165f, 0.0062904744409024715f, 0.010826223529875278f, 0.005510464310646057f, 0.009102758020162582f, 0.007388414349406958f, 0.006147508043795824f, 0.005373950116336346f, 0.006035639438778162f, 0.009923801757395267f, 0.007587214931845665f, 0.009123274125158787f, 0.0052182720974087715f, 0.004893363919109106f, 0.004772631451487541f, 0.005045087542384863f, 0.006924295332282782f, 0.00661316467449069f, 0.005855905823409557f, 0.0071389442309737206f, 0.00492094224318862f, 0.00608157180249691f, 0.006031943950802088f, 0.0080364178866148f, 0.007342337165027857f, 0.008303017355501652f, 0.007686888799071312f, 0.0051042563281953335f, 0.004873362835496664f, 0.0063688065856695175f, 0.00367755931802094f, 0.005968497600406408f, 0.006683080457150936f, 0.0076597449369728565f, 0.011135014705359936f, 0.007202976383268833f, 0.004478099290281534f, 0.009150045923888683f, 0.006367772351950407f, 0.007574076298624277f, 0.010426693595945835f, 0.009717282839119434f, 0.010540518909692764f, 0.00942904595285654f, 0.006821433547884226f, 0.0046602291986346245f, 0.006364639848470688f, 0.00696773873642087f, 0.0044670868664979935f, 0.003059777896851301f, 0.007073266431689262f, 0.007192507851868868f, 0.00979518424719572f, 0.007609243504703045f, 0.010359782725572586f, 0.006193771027028561f, 0.009055900387465954f, 0.00422309385612607f, 0.004878904204815626f, 0.007785243447870016f, 0.00575244938954711f, 0.0061280266381800175f, 0.00683270487934351f, 0.006143690552562475f, 0.005892869085073471f, 0.009820327162742615f, 0.007537315599620342f, 0.007370408624410629f, 0.006265510339289904f, 0.005497672129422426f, 0.007099773734807968f, 0.008942789398133755f, 0.009808001108467579f, 0.01108603086322546f, 0.008662703447043896f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #73 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00014340001507662237f, 0.00015906430780887604f, 0.000196665947441943f, 0.00013548701826948673f, 0.00011525019363034517f, 0.00011894459021277726f, 0.0001551954774186015f, 0.00019931238784920424f, 0.00016244743892457336f, 0.00021806132281199098f, 0.0002131788496626541f, 0.00013933295849710703f, 0.00018944758630823344f, 0.00024104563635773957f, 0.0001573785557411611f, 0.0001056253386195749f, 0.00018263993842992932f, 0.00011583809100557119f, 0.00012174954463262111f, 6.617530016228557e-05f, 0.00013189850142225623f, 0.0001629692706046626f, 7.92470746091567e-05f, 0.00014314326108433306f, 0.00015865298337303102f, 0.0001555051130708307f, 0.00023858477652538568f, 0.0002449745370540768f, 0.0002152286033378914f, 0.0002048749738605693f, 8.148014603648335e-05f, 0.0001719461433822289f, 0.00017753438442014158f, 0.00018093733524437994f, 0.00012184590741526335f, 0.00017139075498562306f, 0.00010516202019061893f, 0.00014493928756564856f, 0.0002956835669465363f, 0.0001252492074854672f, 0.00017570771160535514f, 0.0002068368048639968f, 0.0002386473788646981f, 0.00012392424105200917f, 0.00010309138451702893f, 0.00010806728823808953f, 0.00015664618695154786f, 0.00015364011051133275f, 0.00017392265726812184f, 0.00012509209045674652f, 0.00011485812137834728f, 0.00016940156638156623f, 0.00014350291166920215f, 0.00017654092516750097f, 0.00014801116776652634f, 0.0002547346812207252f, 0.00012965798669029027f, 0.00021418253891170025f, 0.00017384505190420896f, 0.00014464724517893046f, 0.00012644588423427194f, 0.00014201505109667778f, 0.00023350122501142323f, 0.00017852270684670657f, 0.0002146652841474861f, 0.00012278287613298744f, 0.00011513797653606161f, 0.00011229720985284075f, 0.00011870794696733356f, 0.0001629245962249115f, 0.00015560387691948563f, 0.0001377860171487555f, 0.00016797515854705125f, 0.00011578687553992495f, 0.00014309580728877336f, 0.00014192808885127306f, 0.00018909218488261104f, 0.00017276087601203471f, 0.00019536512263584882f, 0.00018086798081640154f, 0.00012010015052510425f, 0.00011466736032161862f, 0.0001498542696936056f, 8.653081022202969e-05f, 0.00014043523697182536f, 0.00015724895638413727f, 0.00018022929725702852f, 0.0002620003651827574f, 0.00016948180564213544f, 0.00010536704212427139f, 0.00021529520745389163f, 0.00014982993889134377f, 0.00017821356595959514f, 0.00024533396936021745f, 0.00022864194761496037f, 0.0002480122202541679f, 0.00022185991110745817f, 0.00016050432168412954f, 0.00010965245746774599f, 0.0001497562334407121f, 0.00016394679551012814f, 0.00010510793072171509f, 7.19947784091346e-05f, 0.0001664298033574596f, 0.00016923548537306488f, 0.0002304749214090407f, 0.00017904103151522577f, 0.00024375959765166044f, 0.00014573578664567322f, 0.00021308001305442303f, 9.936691640177742e-05f, 0.00011479774548206478f, 0.00018318220099899918f, 0.00013535175821743906f, 0.0001441888598492369f, 0.00016076953033916652f, 0.00014455743075814098f, 0.0001386557414662093f, 0.00023106652952264994f, 0.00017734860011842102f, 0.00017342138744425029f, 0.0001474237797083333f, 0.00012935699487570673f, 0.0001670534984441474f, 0.00021041858417447656f, 0.00023077649530023336f, 0.0002608477952890098f, 0.000203828327357769f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #74 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0032278799917548895f, 0.002835942432284355f, 0.0031371801160275936f, 0.002240504138171673f, 0.0025219200178980827f, 0.001774617820046842f, 0.0025634656194597483f, 0.0020657044369727373f, 0.002176904585212469f, 0.0020492770709097385f, 0.0020842845551669598f, 0.002582837361842394f, 0.0028302399441599846f, 0.001981554087251425f, 0.0024706197436898947f, 0.0019867904484272003f, 0.0033118482679128647f, 0.0027681244537234306f, 0.0019257189705967903f, 0.0023715065326541662f, 0.002443985315039754f, 0.0019756967667490244f, 0.0021847833413630724f, 0.0025536655448377132f, 0.0031499206088483334f, 0.0021617631427943707f, 0.0024805180728435516f, 0.0026492075994610786f, 0.0017860466614365578f, 0.0024907919578254223f, 0.002524399431422353f, 0.002265569753944874f, 0.0022474026773124933f, 0.002932249568402767f, 0.0028565144166350365f, 0.0018945385236293077f, 0.0023241895250976086f, 0.0018779136007651687f, 0.0025094866286963224f, 0.002195321023464203f, 0.00215385970659554f, 0.0027999270241707563f, 0.0022063646465539932f, 0.002700341632589698f, 0.0034462239127606153f, 0.0030915432143956423f, 0.002179540926590562f, 0.002556276274845004f, 0.002939053578302264f, 0.0024554862175136805f, 0.002059634542092681f, 0.0021605854853987694f, 0.002003865083679557f, 0.00239965901710093f, 0.001981796696782112f, 0.0022614262998104095f, 0.0034483480267226696f, 0.0021782468538731337f, 0.002458516974002123f, 0.002010044874623418f, 0.0023148118052631617f, 0.0026484853588044643f, 0.0027883832808583975f, 0.0024424605071544647f, 0.003204368520528078f, 0.0023860069923102856f, 0.0024469257332384586f, 0.00236178538762033f, 0.0026389076374471188f, 0.0022495477460324764f, 0.0019109894055873156f, 0.002206662204116583f, 0.002179367234930396f, 0.0029117243830114603f, 0.0021256732288748026f, 0.0023835087195038795f, 0.0017807226395234466f, 0.001828895416110754f, 0.00269295834004879f, 0.002474156441166997f, 0.003947353921830654f, 0.003769231727346778f, 0.002483645686879754f, 0.0027163021732121706f, 0.002057158388197422f, 0.0022166785784065723f, 0.0018459382699802518f, 0.001996677601709962f, 0.00296975439414382f, 0.0030106408521533012f, 0.0021476158872246742f, 0.0030247303657233715f, 0.002909483155235648f, 0.002057046163827181f, 0.0017597335390746593f, 0.002211872721090913f, 0.0018610666738823056f, 0.002212669001892209f, 0.0019488277612254024f, 0.0036424421705305576f, 0.00252705835737288f, 0.0025192606262862682f, 0.0027566419448703527f, 0.002505339216440916f, 0.0017741291085258126f, 0.0028542648069560528f, 0.0021517162676900625f, 0.0028024797793477774f, 0.002425126265734434f, 0.0020845532417297363f, 0.002697205636650324f, 0.0022689581383019686f, 0.002590071875602007f, 0.0021673510782420635f, 0.0023884011898189783f, 0.002397859701886773f, 0.002746000187471509f, 0.0020197781268507242f, 0.002765696495771408f, 0.0022930894047021866f, 0.0024781213141977787f, 0.001974704908207059f, 0.002164579229429364f, 0.0030175114516168833f, 0.0020401410292834044f, 0.002501506358385086f, 0.003127746284008026f, 0.002405805280432105f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #75 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.595011993544176e-05f, 6.67280619381927e-05f, 7.381600153166801e-05f, 5.2717747166752815e-05f, 5.933929423918016e-05f, 4.175571302766912e-05f, 6.031684097251855e-05f, 4.8604812036501244e-05f, 5.122128641232848e-05f, 4.8218284064205363e-05f, 4.904199158772826e-05f, 6.077264333725907e-05f, 6.659387872787192e-05f, 4.66248020529747e-05f, 5.813223106088117e-05f, 4.674801311921328e-05f, 7.792584074195474e-05f, 6.513234256999567e-05f, 4.5311036956263706e-05f, 5.5800155678298324e-05f, 5.750553827965632e-05f, 4.6486984501825646e-05f, 5.1406666898401454e-05f, 6.008624768583104e-05f, 7.411577826132998e-05f, 5.086501550977118e-05f, 5.836513082613237e-05f, 6.23343003098853e-05f, 4.202462878311053e-05f, 5.860687087988481e-05f, 5.939763650530949e-05f, 5.33075253770221e-05f, 5.2880062867188826e-05f, 6.899410800542682e-05f, 6.721210229443386e-05f, 4.457737668417394e-05f, 5.4686814110027626e-05f, 4.4186203012941405e-05f, 5.904674617340788e-05f, 5.165461334399879e-05f, 5.0679052947089076e-05f, 6.588063843082637e-05f, 5.191446325625293e-05f, 6.353745266096666e-05f, 8.108762267511338e-05f, 7.274219387909397e-05f, 5.12833175889682e-05f, 6.014767859596759e-05f, 6.91542009008117e-05f, 5.777614569524303e-05f, 4.846198862651363e-05f, 5.0837305025197566e-05f, 4.714976603281684e-05f, 5.64625661354512e-05f, 4.663051004172303e-05f, 5.321003118297085e-05f, 8.11376012279652e-05f, 5.1252867706352845e-05f, 5.784746099379845e-05f, 4.72951760457363e-05f, 5.446615978144109e-05f, 6.231730367289856e-05f, 6.560901965713128e-05f, 5.746966053266078e-05f, 7.539690705016255e-05f, 5.614134352072142e-05f, 5.757472536060959e-05f, 5.557142139878124e-05f, 6.209194543771446e-05f, 5.293053618515842e-05f, 4.49644576292485e-05f, 5.192146636545658e-05f, 5.127922850078903e-05f, 6.85111663187854e-05f, 5.001584213459864e-05f, 5.6082557421177626e-05f, 4.189935862086713e-05f, 4.303283276385628e-05f, 6.336372462101281e-05f, 5.8215446188114583e-05f, 9.28789158933796e-05f, 8.868780423654243e-05f, 5.843872349942103e-05f, 6.391299393726513e-05f, 4.8403726395918056e-05f, 5.2157145546516404e-05f, 4.343384352978319e-05f, 4.698065094999038e-05f, 6.987657252466306e-05f, 7.083860691636801e-05f, 5.053214044892229e-05f, 7.117012864910066e-05f, 6.84584301779978e-05f, 4.8401088861282915e-05f, 4.140549572184682e-05f, 5.204406625125557e-05f, 4.3789805204141885e-05f, 5.2062801842112094e-05f, 4.585477290675044e-05f, 8.570452337153256e-05f, 5.946019882685505e-05f, 5.9276721003698185e-05f, 6.48621644359082e-05f, 5.894915739190765e-05f, 4.17442133766599e-05f, 6.715916970279068e-05f, 5.0628619646886364e-05f, 6.594070146093145e-05f, 5.706179581466131e-05f, 4.904831075691618e-05f, 6.346365989884362e-05f, 5.338725168257952e-05f, 6.09428680036217e-05f, 5.0996495701838285e-05f, 5.6197677622549236e-05f, 5.642023097607307e-05f, 6.461176963057369e-05f, 4.752419044962153e-05f, 6.50752117508091e-05f, 5.395504558691755e-05f, 5.830873851664364e-05f, 4.646364686777815e-05f, 5.093127765576355e-05f, 7.100027141859755e-05f, 4.800331953447312e-05f, 5.885897553525865e-05f, 7.359403389273211e-05f, 5.660718306899071e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #76 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00538790225982666f, 0.004563325550407171f, 0.00820198655128479f, 0.006608101539313793f, 0.009223394095897675f, 0.004379293881356716f, 0.005274007562547922f, 0.006699920631945133f, 0.004603034816682339f, 0.008500417694449425f, 0.005857605952769518f, 0.004837059881538153f, 0.006618203595280647f, 0.005425707437098026f, 0.0051219407469034195f, 0.00628454377874732f, 0.009316555224359035f, 0.007010030094534159f, 0.00566236162558198f, 0.005249065347015858f, 0.005471348762512207f, 0.004714382812380791f, 0.006715874187648296f, 0.005642822477966547f, 0.004185669124126434f, 0.00684413081035018f, 0.005763115826994181f, 0.004485337063670158f, 0.007262534461915493f, 0.006413856986910105f, 0.006408240180462599f, 0.007720721419900656f, 0.006671347189694643f, 0.007406461518257856f, 0.005413542035967112f, 0.007269443944096565f, 0.0070209866389632225f, 0.003866300918161869f, 0.0044329725205898285f, 0.009021823294460773f, 0.004009712487459183f, 0.009914305992424488f, 0.008046758361160755f, 0.005925177596509457f, 0.0051698507741093636f, 0.005918492097407579f, 0.004809816833585501f, 0.008586261421442032f, 0.005074069835245609f, 0.005112567450851202f, 0.004933512303978205f, 0.0044622658751904964f, 0.00708163995295763f, 0.007785541005432606f, 0.006872583646327257f, 0.00750506529584527f, 0.004501656629145145f, 0.006820362526923418f, 0.0039173634722828865f, 0.005411162972450256f, 0.007214180193841457f, 0.007359971757978201f, 0.005999401211738586f, 0.0041766357608139515f, 0.005359121598303318f, 0.007021632511168718f, 0.004563054535537958f, 0.006141030229628086f, 0.006081676576286554f, 0.00832254346460104f, 0.005810207221657038f, 0.0043259430676698685f, 0.005339570809155703f, 0.004481982439756393f, 0.00555398128926754f, 0.005287171807140112f, 0.0037138736806809902f, 0.005319913849234581f, 0.006433012895286083f, 0.004897475708276033f, 0.006482085213065147f, 0.007697364781051874f, 0.005296648014336824f, 0.006219110451638699f, 0.007442924659699202f, 0.006677478086203337f, 0.0069017065688967705f, 0.005583884660154581f, 0.009144322946667671f, 0.007041522767394781f, 0.0036331037990748882f, 0.007121003232896328f, 0.008945073001086712f, 0.00563421193510294f, 0.005770571529865265f, 0.008523194119334221f, 0.0049698445945978165f, 0.006012007128447294f, 0.006220526527613401f, 0.004935144912451506f, 0.008378169499337673f, 0.009288905188441277f, 0.009926395490765572f, 0.0050657750107347965f, 0.006497882306575775f, 0.005065320059657097f, 0.00833455752581358f, 0.0060389405116438866f, 0.005569519009441137f, 0.010787188075482845f, 0.007499852683395147f, 0.0049576847814023495f, 0.006206688471138477f, 0.005761381704360247f, 0.0059973616153001785f, 0.006086180452257395f, 0.009006723761558533f, 0.006324624642729759f, 0.004175628535449505f, 0.004733208566904068f, 0.006730521563440561f, 0.0039330339059233665f, 0.005499943625181913f, 0.009915551170706749f, 0.0031116437166929245f, 0.00516124814748764f, 0.00855991430580616f, 0.00817137397825718f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #77 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001267741754418239f, 0.00010737236880231649f, 0.0001929879217641428f, 0.000155484740389511f, 0.0002170210354961455f, 0.00010304221359547228f, 0.00012409429473336786f, 0.00015764519048389047f, 0.00010830670362338424f, 0.0002000098320422694f, 0.00013782602036371827f, 0.00011381317744962871f, 0.00015572244592476636f, 0.0001276637049159035f, 0.00012051625526510179f, 0.0001478716148994863f, 0.00021921306324657053f, 0.00016494188457727432f, 0.00013323203893378377f, 0.00012350741599220783f, 0.00012873762170784175f, 0.00011092665954492986f, 0.00015802057168912143f, 0.00013277230027597398f, 9.848633635556325e-05f, 0.0001610383769730106f, 0.0001356027350993827f, 0.00010553734318818897f, 0.0001708831696305424f, 0.00015091428940650076f, 0.00015078212891239673f, 0.00018166404333896935f, 0.0001569728774484247f, 0.00017426969134248793f, 0.00012737746874336153f, 0.0001710457436274737f, 0.00016519968630746007f, 9.097178553929552e-05f, 0.00010430523980176076f, 0.00021227820252534002f, 9.434617822989821e-05f, 0.00023327779490500689f, 0.00018933549290522933f, 0.0001394159480696544f, 0.00012164354848209769f, 0.00013925864186603576f, 0.00011317216558381915f, 0.0002020296815317124f, 0.00011938987881876528f, 0.00012029570643790066f, 0.0001160826432169415f, 0.00010499449126655236f, 0.00016662682173773646f, 0.00018318920047022402f, 0.00016170785238500684f, 0.0001765897759469226f, 0.0001059213318512775f, 0.000160479117766954f, 9.217325714416802e-05f, 0.000127321487525478f, 0.0001697454135864973f, 0.00017317580932285637f, 0.00014116238162387162f, 9.827378380578011e-05f, 0.00012609698751475662f, 0.0001652148930588737f, 0.00010736598778748885f, 0.00014449482841882855f, 0.00014309828111436218f, 0.00019582455570343882f, 0.00013671076158061624f, 0.00010178689990425482f, 0.00012563695781864226f, 0.00010545841359999031f, 0.00013068191765341908f, 0.00012440404680091888f, 8.738526230445132e-05f, 0.00012517443974502385f, 0.00015136500587686896f, 0.00011523472494445741f, 0.0001525196566944942f, 0.00018111447570845485f, 0.00012462701124604791f, 0.00014633200771640986f, 0.00017512764316052198f, 0.0001571171305840835f, 0.00016239310207311064f, 0.00013138551730662584f, 0.00021516054403036833f, 0.00016568289720453322f, 8.548479672754183e-05f, 0.00016755302203819156f, 0.0002104723098454997f, 0.00013256969396024942f, 0.00013577815843746066f, 0.0002005457499762997f, 0.00011693752458086237f, 0.00014145899331197143f, 0.00014636533160228282f, 0.0001161210602731444f, 0.00019713339861482382f, 0.0002185624762205407f, 0.000233562255743891f, 0.00011919470853172243f, 0.00015289135626517236f, 0.00011918400559807196f, 0.00019610724120866507f, 0.00014209271466825157f, 0.00013104750541970134f, 0.0002538161934353411f, 0.00017646713240537792f, 0.00011665141209959984f, 0.00014603973249904811f, 0.00013556193152908236f, 0.00014111438940744847f, 0.00014320424816105515f, 0.00021192291751503944f, 0.0001488146954216063f, 9.825008601183072e-05f, 0.00011136961256852373f, 0.00015836521924939007f, 9.254197357222438e-05f, 0.00012941044406034052f, 0.0002333070879103616f, 7.321514567593113e-05f, 0.00012144113861722872f, 0.00020140975539106876f, 0.0001922676310641691f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #78 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0021954653784632683f, 0.0014594820095226169f, 0.0017853681929409504f, 0.0017009912990033627f, 0.003153029829263687f, 0.0017116367816925049f, 0.0025919892359524965f, 0.0026321487966924906f, 0.0017887642607092857f, 0.002042949665337801f, 0.0020095016807317734f, 0.0019327242625877261f, 0.0015375788789242506f, 0.002141496166586876f, 0.0033426869194954634f, 0.0023186304606497288f, 0.0025347634218633175f, 0.0015039651188999414f, 0.002051240298897028f, 0.0020346143282949924f, 0.002654397627338767f, 0.001986313611268997f, 0.0018917780835181475f, 0.0016895299777388573f, 0.0021777527872473f, 0.002564007882028818f, 0.00218917615711689f, 0.0025236026849597692f, 0.0017732830019667745f, 0.0020108309108763933f, 0.0013711154460906982f, 0.0023597886320203543f, 0.0021413860376924276f, 0.002065988490357995f, 0.0014547916362062097f, 0.0019144625402987003f, 0.003410822246223688f, 0.0019106800900772214f, 0.0015084801707416773f, 0.002569225151091814f, 0.0025881438050419092f, 0.0020594901870936155f, 0.0020094001665711403f, 0.001686624251306057f, 0.0018478871788829565f, 0.0019170184386894107f, 0.0017489842139184475f, 0.001745191402733326f, 0.0027808870654553175f, 0.002230435609817505f, 0.0020977670792490244f, 0.0015112910186871886f, 0.002484099706634879f, 0.0018894014647230506f, 0.002159039257094264f, 0.0021399338729679585f, 0.002483534859493375f, 0.001919131027534604f, 0.001591358333826065f, 0.00205409643240273f, 0.0015884976601228118f, 0.002459030831232667f, 0.0014766165986657143f, 0.002155148657038808f, 0.002669460838660598f, 0.002188294194638729f, 0.0020998299587517977f, 0.00219057803042233f, 0.0015292733442038298f, 0.002047098707407713f, 0.0019607562571763992f, 0.0019461363554000854f, 0.003039654577150941f, 0.0020466120913624763f, 0.0019993181340396404f, 0.0016439770115539432f, 0.002256657462567091f, 0.0019873923156410456f, 0.0025151486042886972f, 0.004855267237871885f, 0.0030331676825881004f, 0.0015321880346164107f, 0.0024098940193653107f, 0.0011699735186994076f, 0.00169202103279531f, 0.0011205163318663836f, 0.0024132663384079933f, 0.0030765493866056204f, 0.0015636277385056019f, 0.0025218850933015347f, 0.0024978669825941324f, 0.0029174513183534145f, 0.0020717200823128223f, 0.0028080432675778866f, 0.002393857343122363f, 0.0023327262606471777f, 0.0019520947244018316f, 0.0019510145066305995f, 0.002261112676933408f, 0.0021353091578930616f, 0.0020830053836107254f, 0.0021263970993459225f, 0.0015276246704161167f, 0.0017787260003387928f, 0.0021900893189013004f, 0.002072417177259922f, 0.0016700587002560496f, 0.001754767494276166f, 0.0029628800693899393f, 0.0017115003429353237f, 0.002180638490244746f, 0.0017615255201235414f, 0.0023028848227113485f, 0.003142436733469367f, 0.001348134595900774f, 0.001835447154007852f, 0.00305644772015512f, 0.002633732743561268f, 0.0024480598513036966f, 0.002580648520961404f, 0.0021077662240713835f, 0.0024361836258322f, 0.0016609755111858249f, 0.0018220735946670175f, 0.0019445911748334765f, 0.0018824655562639236f, 0.001643653609789908f, 0.0018602648051455617f, 0.0016628532903268933f, 0.002144100144505501f, 0.001926319906488061f, 0.002322835149243474f, 0.0017920196987688541f, 0.0020256671123206615f, 0.003279612399637699f, 0.0017762365750968456f, 0.002032788237556815f, 0.0013981421943753958f, 0.0012949121883139014f, 0.001979167340323329f, 0.0017263441113755107f, 0.0024927861522883177f, 0.0017586748581379652f, 0.0021006905008107424f, 0.0024922415614128113f, 0.002894451143220067f, 0.0026809372939169407f, 0.0026519950479269028f, 0.0016704245936125517f, 0.0020016757771372795f, 0.0020490570459514856f, 0.0019085690146312118f, 0.002352369949221611f, 0.001452094642445445f, 0.002230389742180705f, 0.003169713309034705f, 0.0022323087323457003f, 0.002390532521530986f, 0.002360978629440069f, 0.002216305350884795f, 0.0021850760094821453f, 0.002092290436848998f, 0.0018056920962408185f, 0.0013815194834023714f, 0.0017423705430701375f, 0.0024747021961957216f, 0.0024731834419071674f, 0.0026362764183431864f, 0.0016351452795788646f, 0.0025684935972094536f, 0.003087372286245227f, 0.003030646126717329f, 0.0019132886081933975f, 0.0019363862229511142f, 0.00257297744974494f, 0.001726550399325788f, 0.0021726444829255342f, 0.0018762361723929644f, 0.0020858386997133493f, 0.0025321508292108774f, 0.002056684112176299f, 0.0020985801238566637f, 0.003217131132259965f, 0.0018892762018367648f, 0.0018330927705392241f, 0.0018952959217131138f, 0.001973263453692198f, 0.0018686989787966013f, 0.0021302804816514254f, 0.002833547070622444f, 0.001949421246536076f, 0.0019153753528371453f, 0.0022129742428660393f, 0.0014731584815308452f, 0.0020588666666299105f, 0.0020766076631844044f, 0.0019248483004048467f, 0.0026759416796267033f, 0.0025100335478782654f, 0.002635671989992261f, 0.0023752383422106504f, 0.0022910593543201685f, 0.0025842306204140186f, 0.002783589530736208f, 0.001465800916776061f, 0.0027273567393422127f, 0.0018834922229871154f, 0.0024002757854759693f, 0.0024093978572636843f, 0.0018099183216691017f, 0.002446145983412862f, 0.0016124333487823606f, 0.0020493727643042803f, 0.0025776750408113003f, 0.0016768703935667872f, 0.002093666233122349f, 0.0025746298488229513f, 0.001961308531463146f, 0.002190413884818554f, 0.002249989192932844f, 0.002669594017788768f, 0.0031109198462218046f, 0.0021022604778409004f, 0.0021200196351855993f, 0.002431168220937252f, 0.001426751958206296f, 0.001774679054506123f, 0.0021349654998630285f, 0.001850369037128985f, 0.001653782557696104f, 0.002271103672683239f, 0.0027523511089384556f, 0.0019607527647167444f, 0.002074729884043336f, 0.0025432214606553316f, 0.0016636850778013468f, 0.0016697747632861137f, 0.002032959135249257f, 0.002466288162395358f, 0.0021620492916554213f, 0.0017316325102001429f, 0.0014934989158064127f, 0.0022117362823337317f, 0.0030509387142956257f, 0.0018404483562335372f, 0.002447990234941244f, 0.0020653957035392523f, 0.0022189561277627945f, 0.0024697675835341215f, 0.0028081859927624464f, 0.002153565874323249f, 0.0019429094390943646f, 0.0017620058497413993f, 0.002048378111794591f, 0.0030962901655584574f, 0.002984520746394992f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #79 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.1658011216204613e-05f, 3.434075551922433e-05f, 4.200866533210501e-05f, 4.002332570962608e-05f, 7.418893801514059e-05f, 4.027380782645196e-05f, 6.098798257880844e-05f, 6.193291483214125e-05f, 4.208856989862397e-05f, 4.806940341950394e-05f, 4.728239218820818e-05f, 4.547586650005542e-05f, 3.617832771851681e-05f, 5.0388145609758794e-05f, 7.865145744290203e-05f, 5.4556010582018644e-05f, 5.964149386272766e-05f, 3.5387416573939845e-05f, 4.8264479119097814e-05f, 4.787327998201363e-05f, 6.245641270652413e-05f, 4.6736789954593405e-05f, 4.451242784853093e-05f, 3.975364597863518e-05f, 5.124124436406419e-05f, 6.032959936419502e-05f, 5.1510029152268544e-05f, 5.937888636253774e-05f, 4.1724306356627494e-05f, 4.7313667892012745e-05f, 3.2261541491607204e-05f, 5.552444054046646e-05f, 5.0385555368848145e-05f, 4.861149500356987e-05f, 3.4230393794132397e-05f, 4.50461775471922e-05f, 8.02546419436112e-05f, 4.495717803365551e-05f, 3.549365283106454e-05f, 6.045235932106152e-05f, 6.0897502407897264e-05f, 4.8458594392286614e-05f, 4.7280005674110726e-05f, 3.96852774429135e-05f, 4.347970025264658e-05f, 4.5106316974852234e-05f, 4.1152568883262575e-05f, 4.1063329263124615e-05f, 6.543263589264825e-05f, 5.2480838348856196e-05f, 4.9359226977685466e-05f, 3.555978764779866e-05f, 5.844940460519865e-05f, 4.445650483830832e-05f, 5.080092523712665e-05f, 5.035138747189194e-05f, 5.8436115068616346e-05f, 4.5156026317272335e-05f, 3.744372588698752e-05f, 4.833168350160122e-05f, 3.737641600309871e-05f, 5.7859549997374415e-05f, 3.474391996860504e-05f, 5.07093827764038e-05f, 6.281084642978385e-05f, 5.1489274483174086e-05f, 4.9407764890929684e-05f, 5.1543014706112444e-05f, 3.598290277295746e-05f, 4.816702858079225e-05f, 4.6135442971717566e-05f, 4.579144297167659e-05f, 7.1521288191434e-05f, 4.815557986148633e-05f, 4.704278035205789e-05f, 3.8681813748553395e-05f, 5.309782500262372e-05f, 4.6762172132730484e-05f, 5.917996895732358e-05f, 0.00011424158583395183f, 7.136865315260366e-05f, 3.6051482311449945e-05f, 5.670338941854425e-05f, 2.752878936007619e-05f, 3.981226109317504e-05f, 2.6365090889157727e-05f, 5.6782737374305725e-05f, 7.238939724629745e-05f, 3.6791239836020395e-05f, 5.933847569394857e-05f, 5.877334115211852e-05f, 6.864591705380008e-05f, 4.874635487794876e-05f, 6.607161049032584e-05f, 5.632605461869389e-05f, 5.488767783390358e-05f, 4.593163976096548e-05f, 4.590622484101914e-05f, 5.320265336195007e-05f, 5.024256824981421e-05f, 4.9011890951078385e-05f, 5.0032875151373446e-05f, 3.594411100493744e-05f, 4.185237776255235e-05f, 5.153151505510323e-05f, 4.876275852438994e-05f, 3.929550075554289e-05f, 4.128864748054184e-05f, 6.971482798689976e-05f, 4.0270595491165295e-05f, 5.1309143600519747e-05f, 4.144765989622101e-05f, 5.418552609626204e-05f, 7.393969281110913e-05f, 3.1720814149593934e-05f, 4.318699211580679e-05f, 7.191641634562984e-05f, 6.19701822870411e-05f, 5.760140993515961e-05f, 6.072114410926588e-05f, 4.9594498705118895e-05f, 5.732196950702928e-05f, 3.9081776776583865e-05f, 4.2872321500908583e-05f, 4.575508864945732e-05f, 4.429330874700099e-05f, 3.867420309688896e-05f, 4.377093864604831e-05f, 3.9125960029195994e-05f, 5.044941644882783e-05f, 4.5325174141908064e-05f, 5.46549454156775e-05f, 4.2165171180386096e-05f, 4.7662757424404845e-05f, 7.716735126450658e-05f, 4.179380266577937e-05f, 4.783031181432307e-05f, 3.289746382506564e-05f, 3.0468521799775772e-05f, 4.6568642574129626e-05f, 4.061986328451894e-05f, 5.865379353053868e-05f, 4.138058648095466e-05f, 4.9428013880969957e-05f, 5.86409805691801e-05f, 6.810473132645711e-05f, 6.308087904471904e-05f, 6.239988579181954e-05f, 3.930410821340047e-05f, 4.709825589088723e-05f, 4.821310722036287e-05f, 4.4907508709002286e-05f, 5.534988304134458e-05f, 3.416693289182149e-05f, 5.247975786915049e-05f, 7.458149048034102e-05f, 5.252491246210411e-05f, 5.624782352242619e-05f, 5.5552438425365835e-05f, 5.2148363465676084e-05f, 5.141355359228328e-05f, 4.9230362492380664e-05f, 4.248687400831841e-05f, 3.2506341085536405e-05f, 4.099695433978923e-05f, 5.822828825330362e-05f, 5.8192552387481555e-05f, 6.203003431437537e-05f, 3.847400876111351e-05f, 6.0435144405346364e-05f, 7.264405576279387e-05f, 7.13093249942176e-05f, 4.501855801208876e-05f, 4.556202839012258e-05f, 6.0540645790752023e-05f, 4.06247163482476e-05f, 5.1121049182256684e-05f, 4.414673458086327e-05f, 4.907855691271834e-05f, 5.958001929684542e-05f, 4.8392568714916706e-05f, 4.9378355470253155e-05f, 7.569720764877275e-05f, 4.4453558075474575e-05f, 4.31315966125112e-05f, 4.4595199142349884e-05f, 4.6429729991359636e-05f, 4.396939038997516e-05f, 5.012424662709236e-05f, 6.667169509455562e-05f, 4.586873546941206e-05f, 4.506765617406927e-05f, 5.206998321227729e-05f, 3.466255293460563e-05f, 4.844392242375761e-05f, 4.8861358663998544e-05f, 4.5290547859622166e-05f, 6.296333594946191e-05f, 5.9059613704448566e-05f, 6.201580981723964e-05f, 5.588796193478629e-05f, 5.3907278925180435e-05f, 6.080542880226858e-05f, 6.549622776219621e-05f, 3.4489432437112555e-05f, 6.417310214601457e-05f, 4.431746492628008e-05f, 5.6477078032912686e-05f, 5.669171514455229e-05f, 4.2586314521031454e-05f, 5.755637539550662e-05f, 3.793960786424577e-05f, 4.822053597308695e-05f, 6.065117850084789e-05f, 3.945577554986812e-05f, 4.926273686578497e-05f, 6.057952850824222e-05f, 4.61484378320165e-05f, 5.153915117261931e-05f, 5.2940922614652663e-05f, 6.281397509155795e-05f, 7.319811265915632e-05f, 4.9464953917777166e-05f, 4.988281580153853e-05f, 5.720396075048484e-05f, 3.357063542352989e-05f, 4.1757153667276725e-05f, 5.0234484660904855e-05f, 4.3538097088458017e-05f, 3.8912530726520345e-05f, 5.343773591448553e-05f, 6.476120324805379e-05f, 4.6135359298205e-05f, 4.8817175411386415e-05f, 5.98405058553908e-05f, 3.914553235517815e-05f, 3.928881778847426e-05f, 4.7834331780904904e-05f, 5.8030309446621686e-05f, 5.087174940854311e-05f, 4.074429671163671e-05f, 3.5141150874551386e-05f, 5.204085391596891e-05f, 7.178679516073316e-05f, 4.3304669816279784e-05f, 5.759977284469642e-05f, 4.859754699282348e-05f, 5.2210732974344864e-05f, 5.811217852169648e-05f, 6.607496470678598e-05f, 5.06721407873556e-05f, 4.5715518353972584e-05f, 4.1458963096374646e-05f, 4.819713285542093e-05f, 7.28538871044293e-05f, 7.022402132861316e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #80 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011745704337954521f, 0.007075656205415726f, 0.013105843216180801f, 0.007611552253365517f, 0.005830335896462202f, 0.00849059596657753f, 0.005418707616627216f, 0.010011877864599228f, 0.005813204683363438f, 0.010051131248474121f, 0.00670591788366437f, 0.005950891878455877f, 0.007285657338798046f, 0.007256906945258379f, 0.010528500191867352f, 0.009198972024023533f, 0.006497712340205908f, 0.005857142154127359f, 0.009302022866904736f, 0.008612548001110554f, 0.01009274274110794f, 0.008306291885674f, 0.008109181188046932f, 0.00848670769482851f, 0.00919286534190178f, 0.006687519606202841f, 0.007285095751285553f, 0.008858359418809414f, 0.009768852032721043f, 0.005439705681055784f, 0.006300253327935934f, 0.005558188073337078f, 0.006134343799203634f, 0.007191163953393698f, 0.00804873090237379f, 0.008292751386761665f, 0.010793766006827354f, 0.007807051297277212f, 0.012827751226723194f, 0.010957667604088783f, 0.008661256171762943f, 0.007876576855778694f, 0.006548373028635979f, 0.007018639240413904f, 0.007402427960187197f, 0.007801301311701536f, 0.008330103009939194f, 0.010592270642518997f, 0.007780013140290976f, 0.006989229936152697f, 0.006786967162042856f, 0.006615496706217527f, 0.005184264853596687f, 0.009004523977637291f, 0.010686643421649933f, 0.0067280614748597145f, 0.0068356953561306f, 0.006986489985138178f, 0.009989557787775993f, 0.00557473860681057f, 0.007695279084146023f, 0.011420580558478832f, 0.00795105192810297f, 0.012682519853115082f, 0.01029094960540533f, 0.009592756628990173f, 0.006626144051551819f, 0.00931617058813572f, 0.008507574908435345f, 0.008625171147286892f, 0.006220515351742506f, 0.009568448178470135f, 0.006753283552825451f, 0.0074514285661280155f, 0.008349762298166752f, 0.007600048091262579f, 0.006022597663104534f, 0.00807435903698206f, 0.010729449801146984f, 0.007489979267120361f, 0.010083657689392567f, 0.006706872023642063f, 0.010144243016839027f, 0.007174444384872913f, 0.005666353274136782f, 0.008469249121844769f, 0.010645388625562191f, 0.007302920799702406f, 0.008814926259219646f, 0.00710707064718008f, 0.006204470060765743f, 0.006739850156009197f, 0.008298740722239017f, 0.012298797257244587f, 0.008540824986994267f, 0.007979401387274265f, 0.008784132078289986f, 0.009178461506962776f, 0.00625073304399848f, 0.007095566019415855f, 0.009105414152145386f, 0.009717000648379326f, 0.007607677485793829f, 0.007874276489019394f, 0.007005627732723951f, 0.008372506126761436f, 0.006748542655259371f, 0.005179526284337044f, 0.009470506571233273f, 0.010875589214265347f, 0.006247468758374453f, 0.007546349428594112f, 0.006417482625693083f, 0.008017425425350666f, 0.004749039188027382f, 0.006149939727038145f, 0.007975030690431595f, 0.009332960471510887f, 0.012818635441362858f, 0.006935836281627417f, 0.008741497993469238f, 0.01075248047709465f, 0.00580302020534873f, 0.007363238837569952f, 0.008164898492395878f, 0.008281568065285683f, 0.011681451462209225f, 0.009591314010322094f, 0.013996439054608345f, 0.006324026267975569f, 0.0065366714261472225f, 0.008214731700718403f, 0.008531671948730946f, 0.008251823484897614f, 0.006141526158899069f, 0.005416622385382652f, 0.0063150846399366856f, 0.004415658302605152f, 0.006419491488486528f, 0.00957494042813778f, 0.008342701010406017f, 0.01049351692199707f, 0.014332384802401066f, 0.0067237927578389645f, 0.009367660619318485f, 0.010028142482042313f, 0.008543958887457848f, 0.008835822343826294f, 0.008936984464526176f, 0.009670699946582317f, 0.007975875400006771f, 0.005048410966992378f, 0.011319173499941826f, 0.009154981933534145f, 0.006726492196321487f, 0.008553710766136646f, 0.008077449165284634f, 0.0076279412023723125f, 0.007323750760406256f, 0.009568067267537117f, 0.0076376209035515785f, 0.007384902331978083f, 0.004777364898473024f, 0.006154518108814955f, 0.00905541330575943f, 0.007032620254904032f, 0.00949888862669468f, 0.007592712063342333f, 0.007623382844030857f, 0.01006613951176405f, 0.015702063217759132f, 0.005541414488106966f, 0.009237467311322689f, 0.008166284300386906f, 0.006988464388996363f, 0.010874725878238678f, 0.009924187324941158f, 0.006163378711789846f, 0.012019273824989796f, 0.009789442643523216f, 0.009245623834431171f, 0.010178145952522755f, 0.007405563723295927f, 0.006012731231749058f, 0.006259662564843893f, 0.01577930897474289f, 0.010387342423200607f, 0.012144923210144043f, 0.00700759794563055f, 0.008454669266939163f, 0.009162239730358124f, 0.006599285174161196f, 0.005419422872364521f, 0.0075998264364898205f, 0.005219162441790104f, 0.006679974030703306f, 0.006162104196846485f, 0.009064992889761925f, 0.01132258027791977f, 0.010240537114441395f, 0.010812515392899513f, 0.008606878109276295f, 0.00571900699287653f, 0.005454511847347021f, 0.010313020087778568f, 0.004928641486912966f, 0.007882853969931602f, 0.008064979687333107f, 0.012189619243144989f, 0.010453748516738415f, 0.00689117843285203f, 0.0070640407502651215f, 0.007647851016372442f, 0.007828122936189175f, 0.009235130622982979f, 0.010355372913181782f, 0.008930339477956295f, 0.006850676145404577f, 0.007982717826962471f, 0.00544158136472106f, 0.01014084741473198f, 0.009401317685842514f, 0.008153894916176796f, 0.010351905599236488f, 0.007580517791211605f, 0.008453529328107834f, 0.007245979737490416f, 0.0061295656487345695f, 0.00805469136685133f, 0.008791196160018444f, 0.012903525494039059f, 0.008836430497467518f, 0.007003183476626873f, 0.00966313760727644f, 0.011889643967151642f, 0.0061459667049348354f, 0.010340845212340355f, 0.006671388633549213f, 0.007900812663137913f, 0.006919187027961016f, 0.01008960697799921f, 0.00669043930247426f, 0.005477300379425287f, 0.007491784635931253f, 0.009078889153897762f, 0.010345815680921078f, 0.008544687181711197f, 0.009890914894640446f, 0.009266511537134647f, 0.009345242753624916f, 0.009655240923166275f, 0.007240625564008951f, 0.005209584254771471f, 0.008710987865924835f, 0.006045779678970575f, 0.00779590243473649f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #81 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00027636950835585594f, 0.00016648603195790201f, 0.0003083727788180113f, 0.00017909535381477326f, 0.0001371843827655539f, 0.00019977873307652771f, 0.00012749900633934885f, 0.00023557360691484064f, 0.00013678129471372813f, 0.00023649721697438508f, 0.00015778630040585995f, 0.00014002098760101944f, 0.00017142723663710058f, 0.0001707507617538795f, 0.00024772941833361983f, 0.00021644640946760774f, 0.00015288735448848456f, 0.000137815106427297f, 0.0002188711368944496f, 0.00020264819613657892f, 0.00023747629893478006f, 0.0001954421604750678f, 0.00019080426136497408f, 0.00019968724518548697f, 0.00021630272385664284f, 0.0001573534100316465f, 0.00017141402349807322f, 0.00020843198581133038f, 0.00022985534451436251f, 0.00012799307296518236f, 0.00014824126265011728f, 0.00013078089978080243f, 0.00014433750766329467f, 0.00016920386406127363f, 0.00018938191351480782f, 0.00019512356084305793f, 0.00025397096760571003f, 0.00018369533063378185f, 0.0003018294519279152f, 0.00025782748707570136f, 0.0002037942613242194f, 0.0001853312278399244f, 0.00015407937462441623f, 0.00016514446178916842f, 0.00017417478375136852f, 0.00018356004147790372f, 0.00019600242376327515f, 0.0002492298954166472f, 0.00018305913545191288f, 0.0001644524745643139f, 0.00015969334344845265f, 0.0001556587521918118f, 0.00012198270269436762f, 0.00021187115635257214f, 0.0002514504303690046f, 0.00015830733173061162f, 0.00016083988884929568f, 0.00016438800957985222f, 0.00023504842829424888f, 0.00013117032358422875f, 0.00018106539209838957f, 0.00026871953741647303f, 0.00018708358402363956f, 0.00029841222567483783f, 0.00024213999859057367f, 0.0002257119194837287f, 0.00015590927796438336f, 0.00021920401195529848f, 0.0002001782413572073f, 0.00020294520072638988f, 0.0001463650696678087f, 0.00022513995645567775f, 0.00015890078793745488f, 0.00017532773199491203f, 0.00019646500004455447f, 0.00017882465908769518f, 0.00014170818030834198f, 0.00018998491577804089f, 0.00025245765573345125f, 0.00017623481107875705f, 0.00023726253130007535f, 0.00015780875401105732f, 0.00023868808057159185f, 0.00016881045303307474f, 0.00013332595699466765f, 0.0001992764591705054f, 0.00025047973031178117f, 0.0001718334387987852f, 0.00020741003390867263f, 0.0001672251964919269f, 0.00014598753477912396f, 0.00015858470578677952f, 0.00019526449614204466f, 0.00028938346076756716f, 0.00020096059597562999f, 0.00018775062926579267f, 0.0002066854649456218f, 0.00021596380975097418f, 0.00014707607624586672f, 0.00016695450176484883f, 0.00021424503938760608f, 0.00022863531194161624f, 0.00017900418606586754f, 0.00018527709471527487f, 0.0001648383040446788f, 0.00019700014672707766f, 0.00015878924750722945f, 0.00012187120591988787f, 0.00022283545695245266f, 0.0002558962150942534f, 0.0001469992712372914f, 0.00017756115994416177f, 0.00015099959273356944f, 0.00018864531011786312f, 0.00011174209794262424f, 0.0001447044633096084f, 0.0001876477908808738f, 0.0002195990673499182f, 0.0003016149566974491f, 0.00016319614951498806f, 0.0002056823141174391f, 0.00025299953995272517f, 0.00013654165377374738f, 0.00017325268709100783f, 0.00019211525795981288f, 0.0001948604331118986f, 0.00027485768077895045f, 0.00022567798441741616f, 0.0003293279733043164f, 0.00014880062371958047f, 0.0001538040378363803f, 0.000193287807633169f, 0.00020074522763025016f, 0.0001941605587489903f, 0.0001445064990548417f, 0.0001274499372811988f, 0.00014859023212920874f, 0.0001038978443830274f, 0.00015104685735423118f, 0.00022529272246174514f, 0.00019629884627647698f, 0.00024690627469681203f, 0.00033723260276019573f, 0.00015820689441170543f, 0.0002204155462095514f, 0.00023595629318151623f, 0.00020103433053009212f, 0.00020790169946849346f, 0.00021028198534622788f, 0.00022754588280804455f, 0.00018766765424516052f, 0.00011878614168381318f, 0.0002663334889803082f, 0.00021541134628932923f, 0.00015827041352167726f, 0.000201263785129413f, 0.00019005763169843704f, 0.00017948097956832498f, 0.0001723235473036766f, 0.00022513099247589707f, 0.00017970873159356415f, 0.00017376241157762706f, 0.00011240859021199867f, 0.000144812191138044f, 0.00021306854614522308f, 0.00016547342238482088f, 0.00022350327344611287f, 0.00017865205882117152f, 0.0001793737174011767f, 0.00023685034830123186f, 0.0003694603219628334f, 0.00013038622273597866f, 0.0002173521788790822f, 0.00019214786880183965f, 0.00016443445929326117f, 0.0002558759006205946f, 0.0002335102908546105f, 0.0001450206764275208f, 0.00028280646074563265f, 0.00023033983597997576f, 0.0002175440895371139f, 0.00023948578746058047f, 0.00017424856196157634f, 0.00014147603360470384f, 0.00014728617679793388f, 0.0003712778561748564f, 0.0002444080600980669f, 0.00028576291515491903f, 0.00016488466644659638f, 0.00019893339776899666f, 0.00021558211301453412f, 0.00015527730283793062f, 0.00012751582835335284f, 0.00017881944950204343f, 0.0001228038308909163f, 0.00015717586211394519f, 0.00014499068493023515f, 0.00021329395531211048f, 0.0002664136700332165f, 0.00024095381377264857f, 0.0002544121234677732f, 0.00020251478417776525f, 0.00013456487795338035f, 0.0001283414603676647f, 0.00024265929823741317f, 0.0001159680396085605f, 0.0001854789152275771f, 0.0001897642359836027f, 0.0002868145820684731f, 0.0002459705574437976f, 0.00016214538482017815f, 0.00016621273243799806f, 0.00017994943482335657f, 0.00018419112893752754f, 0.00021729720174334943f, 0.0002436558424960822f, 0.0002101256395690143f, 0.0001611923798918724f, 0.00018782865663524717f, 0.00012803720892407f, 0.0002386081760050729f, 0.00022120747598819435f, 0.00019185635028406978f, 0.00024357424990739673f, 0.00017836512415669858f, 0.00019890657858923078f, 0.00017049364396370947f, 0.0001442250795662403f, 0.0001895221503218636f, 0.0002068516769213602f, 0.0003036123816855252f, 0.00020791601855307817f, 0.0001647807948756963f, 0.00022736794198863208f, 0.00027975632110610604f, 0.00014461098180618137f, 0.00024331400345545262f, 0.000156973852426745f, 0.0001859014737419784f, 0.0001628043974051252f, 0.00023740252072457224f, 0.0001574221096234396f, 0.00012887765478808433f, 0.00017627728811930865f, 0.00021362092229537666f, 0.000243430957198143f, 0.00020105147268623114f, 0.0002327274123672396f, 0.00021803556592203677f, 0.00021988806838635355f, 0.0002271821431349963f, 0.0001703676680335775f, 0.00012257845082785934f, 0.00020496442448347807f, 0.00014225364429876208f, 0.00018343300325796008f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #82 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_26_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000842112407553941f, 0.0013041464844718575f, 0.001138030900619924f, 0.0005243843188509345f, 0.0011736631859093904f, 0.0006688912399113178f, 0.0007405562209896743f, 0.0011397270718589425f, 0.0008493062341585755f, 0.0010336756240576506f, 0.0008432557224296033f, 0.0006769237807020545f, 0.0010763265891000628f, 0.0007054557208903134f, 0.0006885909824632108f, 0.0008182828896678984f, 0.0008828723221085966f, 0.000662960868794471f, 0.0005971782957203686f, 0.0009628058760426939f, 0.0005596854025498033f, 0.000758543552365154f, 0.000981582561507821f, 0.0007636952213943005f, 0.0011587018379941583f, 0.0007411372498609126f, 0.0013655625516548753f, 0.000999392825178802f, 0.0005828875582665205f, 0.0007036784081719816f, 0.0008316081948578358f, 0.000943110731896013f, 0.0011032032780349255f, 0.0007940179784782231f, 0.0007631441112607718f, 0.0007277738768607378f, 0.0008038418018259108f, 0.000632337003480643f, 0.0008758200565353036f, 0.0007531618466600776f, 0.001007812679745257f, 0.000826590578071773f, 0.001008533756248653f, 0.0009438037523068488f, 0.0005523135187104344f, 0.0006054726545698941f, 0.0007470147684216499f, 0.0006955695571377873f, 0.0010598113294690847f, 0.0010243264259770513f, 0.0008271806873381138f, 0.0006022508605383337f, 0.0006906753405928612f, 0.0015829525655135512f, 0.0007209385512396693f, 0.0009647177066653967f, 0.0010184722486883402f, 0.0007633030763827264f, 0.0006863584858365357f, 0.0008413311443291605f, 0.0008430352318100631f, 0.0007850596448406577f, 0.0009844565065577626f, 0.0007278051343746483f, 0.0005891689797863364f, 0.0008134896634146571f, 0.0006236019544303417f, 0.0007440648623742163f, 0.0007412770646624267f, 0.0008669809903949499f, 0.000884649227373302f, 0.0007251338684000075f, 0.000496092950925231f, 0.0008091138442978263f, 0.000644105311948806f, 0.0006310287863016129f, 0.0012650784337893128f, 0.0008288720273412764f, 0.0006871572695672512f, 0.0005261354381218553f, 0.0015504807233810425f, 0.0006562371272593737f, 0.0005268609384074807f, 0.0007458036998286843f, 0.0011014459887519479f, 0.0005827242857776582f, 0.0006888766074553132f, 0.0012005968019366264f, 0.0007454418810084462f, 0.0007752087549306452f, 0.000979259260930121f, 0.0006419328856281936f, 0.0007771867676638067f, 0.0008302158094011247f, 0.0005547779146581888f, 0.0011835594195872545f, 0.0010044076479971409f, 0.0008779125637374818f, 0.0011570651549845934f, 0.0006577086169272661f, 0.0006527200457639992f, 0.0006399030098691583f, 0.0006391252973116934f, 0.0008454086491838098f, 0.0010517530608922243f, 0.0006672487943433225f, 0.0006456288392655551f, 0.0006436454714275897f, 0.0009308555163443089f, 0.0008190095541067421f, 0.0010216543450951576f, 0.0006410015048459172f, 0.0004996603820472956f, 0.001175734680145979f, 0.0006827122415415943f, 0.0010031798155978322f, 0.0010892372811213136f, 0.0007069217972457409f, 0.0012415111996233463f, 0.0006370191695168614f, 0.0008428361616097391f, 0.0006046672933734953f, 0.0006294814520515501f, 0.0008145399624481797f, 0.0008457425283268094f, 0.0006344565190374851f, 0.0006150947301648557f, 0.0009362237760797143f, 0.0008972131181508303f, 0.0011851980816572905f, 0.001234657596796751f, 0.0009666772093623877f, 0.0008252346306107938f, 0.0006267466233111918f, 0.0008853403269313276f, 0.0005116050015203655f, 0.0009593313443474472f, 0.0009215599275194108f, 0.0006297771469689906f, 0.0007418377790600061f, 0.0009106549550779164f, 0.0007434487342834473f, 0.0007694751839153469f, 0.0008508137543685734f, 0.0008140158606693149f, 0.0007955650798976421f, 0.0008734113653190434f, 0.0008599479915574193f, 0.0009350210893899202f, 0.0006865346222184598f, 0.0008650785894133151f, 0.0007490694988518953f, 0.0006310596945695579f, 0.0005842932150699198f, 0.000928086694329977f, 0.0008294924045912921f, 0.0007378553273156285f, 0.001212508650496602f, 0.00075575738446787f, 0.0007671021157875657f, 0.000625294866040349f, 0.0007585802813991904f, 0.0014014969347044826f, 0.0007892639259807765f, 0.0007406198419630527f, 0.0007122094975784421f, 0.0006044890615157783f, 0.0007680143462494016f, 0.0005617470596916974f, 0.0012374124489724636f, 0.0007926637772470713f, 0.0006036176346242428f, 0.0010590930469334126f, 0.0006868412019684911f, 0.0007628112798556685f, 0.0007668570033274591f, 0.0020718704909086227f, 0.001547969994135201f, 0.0008660151506774127f, 0.0007954132743179798f, 0.0006229017744772136f, 0.0007172385230660439f, 0.0007527535781264305f, 0.0008190420921891928f, 0.0009545249631628394f, 0.0008837703499011695f, 0.0011638723080977798f, 0.0007271408685483038f, 0.0006991351256147027f, 0.0007710007485002279f, 0.0008015130297280848f, 0.0009592126007191837f, 0.000628605717793107f, 0.0008237964357249439f, 0.0009333458729088306f, 0.0006083741900511086f, 0.000689985288772732f, 0.000994718517176807f, 0.000617539684753865f, 0.0004269065975677222f, 0.0006946249632164836f, 0.0004570550809148699f, 0.0008964653825387359f, 0.0009207332623191178f, 0.0008045419817790389f, 0.0009828078327700496f, 0.0010912753641605377f, 0.0006704108673147857f, 0.0005654973792843521f, 0.0008809021674096584f, 0.0009101434843614697f, 0.0009733402985148132f, 0.0007969584548845887f, 0.0007308085332624614f, 0.0014325538650155067f, 0.0005746111855842173f, 0.0005800375947728753f, 0.000798729422967881f, 0.0009237589547410607f, 0.0007844962528906763f, 0.0008381009683944285f, 0.0006688577705062926f, 0.0010072655277326703f, 0.0011009741574525833f, 0.0007677347166463733f, 0.0007330563385039568f, 0.0006093409610912204f, 0.0005814599571749568f, 0.0006734705530107021f, 0.0006553721614181995f, 0.001052773674018681f, 0.0006971302209421992f, 0.0007704487070441246f, 0.0005021739634685218f, 0.0009746965952217579f, 0.001283152843825519f, 0.0010005116928368807f, 0.0006202355725690722f, 0.0006487952196039259f, 0.0009630653657950461f, 0.0014496160438284278f, 0.0010542657691985369f, 0.0006452240631915629f, 0.0014291132101789117f, 0.0005997153930366039f, 0.0012893712846562266f, 0.0011383709497749805f, 0.0008909961325116456f, 0.0006821136339567602f, 0.0014935748185962439f, 0.0007046492537483573f, 0.0008277383749373257f, 0.0012661200016736984f, 0.0010325935436412692f, 0.0008121226564981043f, 0.00103192578535527f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #83 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_26_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.9814409824903123e-05f, 3.068580190301873e-05f, 2.677719749044627e-05f, 1.2338455235294532e-05f, 2.7615604267339222e-05f, 1.5738618458271958e-05f, 1.7424852558178827e-05f, 2.681710793694947e-05f, 1.9983675883850083e-05f, 2.432178007438779e-05f, 1.9841310859192163e-05f, 1.5927618733257987e-05f, 2.532533289922867e-05f, 1.6598958609392866e-05f, 1.6202140614041127e-05f, 1.925371543620713e-05f, 2.0773466530954465e-05f, 1.5599080143147148e-05f, 1.4051253856450785e-05f, 2.2654256099485792e-05f, 1.3169068552087992e-05f, 1.7848084098659456e-05f, 2.3096061340766028e-05f, 1.7969299733522348e-05f, 2.726357342908159e-05f, 1.7438524082535878e-05f, 3.2130883482750505e-05f, 2.3515125576523133e-05f, 1.371500184177421e-05f, 1.6557140043005347e-05f, 1.9567252820706926e-05f, 2.2190841264091432e-05f, 2.5957724574254826e-05f, 1.8682776499190368e-05f, 1.795633215806447e-05f, 1.7124091755249538e-05f, 1.8913924577645957e-05f, 1.4878518413752317e-05f, 2.0607531041605398e-05f, 1.772145515133161e-05f, 2.371324080741033e-05f, 1.9449191313469782e-05f, 2.3730206521577202e-05f, 2.2207146685104817e-05f, 1.2995612451049965e-05f, 1.4246415958041325e-05f, 1.7576818208908662e-05f, 1.6366342606488615e-05f, 2.493673855497036e-05f, 2.4101798771880567e-05f, 1.9463075659587048e-05f, 1.417060866515385e-05f, 1.625118420633953e-05f, 3.7245943531161174e-05f, 1.696326035016682e-05f, 2.269923970743548e-05f, 2.3964053980307654e-05f, 1.796007200027816e-05f, 1.614961183804553e-05f, 1.979602711799089e-05f, 1.983612310141325e-05f, 1.8471992007107474e-05f, 2.3163682271842845e-05f, 1.712482662696857e-05f, 1.3862800187780522e-05f, 1.914093445520848e-05f, 1.4672987163066864e-05f, 1.750740921124816e-05f, 1.744181281537749e-05f, 2.0399553250172175e-05f, 2.0815276002394967e-05f, 1.7061973267118447e-05f, 1.1672775144688785e-05f, 1.903797237901017e-05f, 1.5155419532675296e-05f, 1.4847736565570813e-05f, 2.9766551961074583e-05f, 1.9502871509757824e-05f, 1.616840745555237e-05f, 1.237965716427425e-05f, 3.648189886007458e-05f, 1.5440873539773747e-05f, 1.2396728379826527e-05f, 1.7548321920912713e-05f, 2.5916377126122825e-05f, 1.3711160136153921e-05f, 1.620886177988723e-05f, 2.824933653755579e-05f, 1.7539809050504118e-05f, 1.824020546337124e-05f, 2.3041395252221264e-05f, 1.5104303201951552e-05f, 1.8286747945239767e-05f, 1.953448918357026e-05f, 1.30535981952562e-05f, 2.7848456738865934e-05f, 2.363312160014175e-05f, 2.0656767446780577e-05f, 2.722506360441912e-05f, 1.5475498003070243e-05f, 1.535811861685943e-05f, 1.5056541997182649e-05f, 1.5038242963782977e-05f, 1.989196789509151e-05f, 2.4747130737523548e-05f, 1.5699972209404223e-05f, 1.5191267266345676e-05f, 1.5144599274208304e-05f, 2.1902482330915518e-05f, 1.927081393660046e-05f, 2.4038925403147005e-05f, 1.5082388927112333e-05f, 1.1756715139199514e-05f, 2.7664345907396637e-05f, 1.6063817383837886e-05f, 2.360423059144523e-05f, 2.5629113224567845e-05f, 1.663345392444171e-05f, 2.9212029403424822e-05f, 1.4988686416472774e-05f, 1.983143920369912e-05f, 1.4227465726435184e-05f, 1.481132858316414e-05f, 1.9165647245245054e-05f, 1.9899824110325426e-05f, 1.4928388736734632e-05f, 1.4472817383648362e-05f, 2.2028794774087146e-05f, 2.111089816025924e-05f, 2.7887013857252896e-05f, 2.9050766897853464e-05f, 2.274534745083656e-05f, 1.9417286239331588e-05f, 1.4746980014024302e-05f, 2.0831537767662667e-05f, 1.203776537295198e-05f, 2.2572503439732827e-05f, 2.1683763407054357e-05f, 1.4818286217632703e-05f, 1.745500776451081e-05f, 2.1427174942800775e-05f, 1.74929118657019e-05f, 1.8105298295267858e-05f, 2.001914799620863e-05f, 1.9153314497089013e-05f, 1.8719178115134127e-05f, 2.055085678875912e-05f, 2.023407068918459e-05f, 2.2000496755936183e-05f, 1.6153755495906807e-05f, 2.035479155892972e-05f, 1.7625165128265508e-05f, 1.484846325183753e-05f, 1.3748075616604183e-05f, 2.1837335225427523e-05f, 1.951746889972128e-05f, 1.7361302525387146e-05f, 2.8529615519801155e-05f, 1.7782527720555663e-05f, 1.8049462596536614e-05f, 1.4712820302520413e-05f, 1.784894811862614e-05f, 3.297640068922192e-05f, 1.8570915926829912e-05f, 1.7426349586457945e-05f, 1.6757870980654843e-05f, 1.422327204636531e-05f, 1.8070926671498455e-05f, 1.3217578270996455e-05f, 2.9115588404238224e-05f, 1.8650913261808455e-05f, 1.420276839780854e-05f, 2.4919836505432613e-05f, 1.616096960788127e-05f, 1.7948501408682205e-05f, 1.804369458113797e-05f, 4.874989463132806e-05f, 3.6422825360205024e-05f, 2.0376826796564274e-05f, 1.8715607438934967e-05f, 1.465651257603895e-05f, 1.6876201698323712e-05f, 1.7711849068291485e-05f, 1.9271579731139354e-05f, 2.245941141154617e-05f, 2.0794597730855457e-05f, 2.7385231078369543e-05f, 1.7109197870013304e-05f, 1.6450238035758957e-05f, 1.814119423215743e-05f, 1.8859131159842946e-05f, 2.256970947200898e-05f, 1.4790723071200773e-05f, 1.938344576046802e-05f, 2.1961079255561344e-05f, 1.431468717782991e-05f, 1.623494790692348e-05f, 2.3405142201227136e-05f, 1.4530345652019605e-05f, 1.0044861483038403e-05f, 1.634411637496669e-05f, 1.0754237337096129e-05f, 2.109330307575874e-05f, 2.166431295336224e-05f, 1.8930399164673872e-05f, 2.3124890503822826e-05f, 2.5677067242213525e-05f, 1.577437433297746e-05f, 1.3305821084941272e-05f, 2.07271095860051e-05f, 2.1415140508906916e-05f, 2.2902124328538775e-05f, 1.8751963580143638e-05f, 1.7195494365296327e-05f, 3.370715057826601e-05f, 1.3520263564714696e-05f, 1.364794388791779e-05f, 1.8793632989400066e-05f, 2.173550456063822e-05f, 1.8458735212334432e-05f, 1.972002246475313e-05f, 1.5737830835860223e-05f, 2.3700366000412032e-05f, 2.590527401480358e-05f, 1.806434738682583e-05f, 1.724838512018323e-05f, 1.4337434549815953e-05f, 1.368141147395363e-05f, 1.5846366295590997e-05f, 1.5420520867337473e-05f, 2.477114503562916e-05f, 1.64030643645674e-05f, 1.812820482882671e-05f, 1.1815857760666404e-05f, 2.2934038497623987e-05f, 3.0191831683623604e-05f, 2.3541451810160652e-05f, 1.4593778359994758e-05f, 1.526577034383081e-05f, 2.2660362446913496e-05f, 3.4108612453565e-05f, 2.4806253350107e-05f, 1.518174303782871e-05f, 3.36261946358718e-05f, 1.4110950360191055e-05f, 3.033814937225543e-05f, 2.6785199224832468e-05f, 2.096461503242608e-05f, 1.604973294888623e-05f, 3.514293712214567e-05f, 1.6579982911935076e-05f, 1.9476197849144228e-05f, 2.9791059205308557e-05f, 2.4296319679706357e-05f, 1.910876926558558e-05f, 2.428060724923853e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #84 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 2,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0014636187115684152f, 0.001394936116412282f),
    AI_PACK_INTQ_ZP(0, 0)))

/* Int quant #85 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 2,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(2.7236963433097117e-05f, 2.5958826881833375e-05f),
    AI_PACK_INTQ_ZP(0, 0)))

/* Int quant #86 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_0_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #87 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #88 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #89 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #90 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #91 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #92 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #93 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #94 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #95 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #96 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #97 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #98 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #99 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #100 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #101 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #102 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #103 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #104 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #105 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #106 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #107 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #108 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #109 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #110 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #111 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #112 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_26_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01860933005809784f),
    AI_PACK_INTQ_ZP(-128)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  input_output, AI_STATIC,
  0, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 96, 96), AI_STRIDE_INIT(4, 1, 1, 1, 96),
  1, &input_output_array, &input_output_intq)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_output, AI_STATIC,
  1, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 48, 48), AI_STRIDE_INIT(4, 1, 1, 8, 384),
  1, &conv2d_0_output_array, &conv2d_0_output_intq)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_output, AI_STATIC,
  2, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 48, 48), AI_STRIDE_INIT(4, 1, 1, 8, 384),
  1, &conv2d_1_output_array, &conv2d_1_output_intq)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_output, AI_STATIC,
  3, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 48, 48), AI_STRIDE_INIT(4, 1, 1, 16, 768),
  1, &conv2d_2_output_array, &conv2d_2_output_intq)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_output, AI_STATIC,
  4, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 24, 24), AI_STRIDE_INIT(4, 1, 1, 16, 384),
  1, &conv2d_3_output_array, &conv2d_3_output_intq)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_output, AI_STATIC,
  5, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 24, 24), AI_STRIDE_INIT(4, 1, 1, 32, 768),
  1, &conv2d_4_output_array, &conv2d_4_output_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_output, AI_STATIC,
  6, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 24, 24), AI_STRIDE_INIT(4, 1, 1, 32, 768),
  1, &conv2d_5_output_array, &conv2d_5_output_intq)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_output, AI_STATIC,
  7, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 24, 24), AI_STRIDE_INIT(4, 1, 1, 32, 768),
  1, &conv2d_6_output_array, &conv2d_6_output_intq)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_output, AI_STATIC,
  8, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 12, 12), AI_STRIDE_INIT(4, 1, 1, 32, 384),
  1, &conv2d_7_output_array, &conv2d_7_output_intq)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_output, AI_STATIC,
  9, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 12, 12), AI_STRIDE_INIT(4, 1, 1, 64, 768),
  1, &conv2d_8_output_array, &conv2d_8_output_intq)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_output, AI_STATIC,
  10, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 12, 12), AI_STRIDE_INIT(4, 1, 1, 64, 768),
  1, &conv2d_9_output_array, &conv2d_9_output_intq)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_output, AI_STATIC,
  11, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 12, 12), AI_STRIDE_INIT(4, 1, 1, 64, 768),
  1, &conv2d_10_output_array, &conv2d_10_output_intq)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_output, AI_STATIC,
  12, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 6, 6), AI_STRIDE_INIT(4, 1, 1, 64, 384),
  1, &conv2d_11_output_array, &conv2d_11_output_intq)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_output, AI_STATIC,
  13, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_12_output_array, &conv2d_12_output_intq)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_output, AI_STATIC,
  14, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_13_output_array, &conv2d_13_output_intq)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_output, AI_STATIC,
  15, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_14_output_array, &conv2d_14_output_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_output, AI_STATIC,
  16, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_15_output_array, &conv2d_15_output_intq)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_output, AI_STATIC,
  17, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_16_output_array, &conv2d_16_output_intq)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_output, AI_STATIC,
  18, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_17_output_array, &conv2d_17_output_intq)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_output, AI_STATIC,
  19, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_18_output_array, &conv2d_18_output_intq)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_output, AI_STATIC,
  20, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_19_output_array, &conv2d_19_output_intq)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_output, AI_STATIC,
  21, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_20_output_array, &conv2d_20_output_intq)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_output, AI_STATIC,
  22, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_21_output_array, &conv2d_21_output_intq)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_output, AI_STATIC,
  23, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_22_output_array, &conv2d_22_output_intq)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_output, AI_STATIC,
  24, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_23_output_array, &conv2d_23_output_intq)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_output, AI_STATIC,
  25, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 3, 3), AI_STRIDE_INIT(4, 1, 1, 256, 768),
  1, &conv2d_24_output_array, &conv2d_24_output_intq)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_output, AI_STATIC,
  26, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 3, 3), AI_STRIDE_INIT(4, 1, 1, 256, 768),
  1, &conv2d_25_output_array, &conv2d_25_output_intq)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_output, AI_STATIC,
  27, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 1, 1, 256, 256),
  1, &conv2d_26_output_array, &conv2d_26_output_intq)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_output, AI_STATIC,
  28, 0x1,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2, 2),
  1, &conv2d_28_output_array, &conv2d_28_output_intq)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  reshape_29_fmt_output, AI_STATIC,
  29, 0x0,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 4, 4, 8, 8),
  1, &reshape_29_fmt_output_array, NULL)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  nl_30_output, AI_STATIC,
  30, 0x0,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 4, 4, 8, 8),
  1, &nl_30_output_array, NULL)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  nl_30_fmt_output, AI_STATIC,
  31, 0x1,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2, 2),
  1, &nl_30_fmt_output_array, &nl_30_fmt_output_intq)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_weights, AI_STATIC,
  32, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 3, 8), AI_STRIDE_INIT(4, 1, 1, 3, 9),
  1, &conv2d_0_weights_array, &conv2d_0_weights_intq)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_bias, AI_STATIC,
  33, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_0_bias_array, &conv2d_0_bias_intq)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_weights, AI_STATIC,
  34, 0x1,
  AI_SHAPE_INIT(4, 8, 3, 3, 1), AI_STRIDE_INIT(4, 1, 8, 24, 72),
  1, &conv2d_1_weights_array, &conv2d_1_weights_intq)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_bias, AI_STATIC,
  35, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_1_bias_array, &conv2d_1_bias_intq)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_weights, AI_STATIC,
  36, 0x1,
  AI_SHAPE_INIT(4, 8, 1, 1, 16), AI_STRIDE_INIT(4, 1, 8, 8, 8),
  1, &conv2d_2_weights_array, &conv2d_2_weights_intq)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_bias, AI_STATIC,
  37, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_2_bias_array, &conv2d_2_bias_intq)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_weights, AI_STATIC,
  38, 0x1,
  AI_SHAPE_INIT(4, 16, 3, 3, 1), AI_STRIDE_INIT(4, 1, 16, 48, 144),
  1, &conv2d_3_weights_array, &conv2d_3_weights_intq)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_bias, AI_STATIC,
  39, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_3_bias_array, &conv2d_3_bias_intq)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_weights, AI_STATIC,
  40, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 32), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &conv2d_4_weights_array, &conv2d_4_weights_intq)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_bias, AI_STATIC,
  41, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_4_bias_array, &conv2d_4_bias_intq)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_weights, AI_STATIC,
  42, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 1), AI_STRIDE_INIT(4, 1, 32, 96, 288),
  1, &conv2d_5_weights_array, &conv2d_5_weights_intq)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_bias, AI_STATIC,
  43, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_5_bias_array, &conv2d_5_bias_intq)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_weights, AI_STATIC,
  44, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 32), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_6_weights_array, &conv2d_6_weights_intq)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_bias, AI_STATIC,
  45, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_6_bias_array, &conv2d_6_bias_intq)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_weights, AI_STATIC,
  46, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 1), AI_STRIDE_INIT(4, 1, 32, 96, 288),
  1, &conv2d_7_weights_array, &conv2d_7_weights_intq)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_bias, AI_STATIC,
  47, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_7_bias_array, &conv2d_7_bias_intq)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_weights, AI_STATIC,
  48, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 64), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_8_weights_array, &conv2d_8_weights_intq)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_bias, AI_STATIC,
  49, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_8_bias_array, &conv2d_8_bias_intq)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_weights, AI_STATIC,
  50, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 1), AI_STRIDE_INIT(4, 1, 64, 192, 576),
  1, &conv2d_9_weights_array, &conv2d_9_weights_intq)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_bias, AI_STATIC,
  51, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_9_bias_array, &conv2d_9_bias_intq)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_weights, AI_STATIC,
  52, 0x1,
  AI_SHAPE_INIT(4, 64, 1, 1, 64), AI_STRIDE_INIT(4, 1, 64, 64, 64),
  1, &conv2d_10_weights_array, &conv2d_10_weights_intq)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_bias, AI_STATIC,
  53, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_10_bias_array, &conv2d_10_bias_intq)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_weights, AI_STATIC,
  54, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 1), AI_STRIDE_INIT(4, 1, 64, 192, 576),
  1, &conv2d_11_weights_array, &conv2d_11_weights_intq)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_bias, AI_STATIC,
  55, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_11_bias_array, &conv2d_11_bias_intq)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_weights, AI_STATIC,
  56, 0x1,
  AI_SHAPE_INIT(4, 64, 1, 1, 128), AI_STRIDE_INIT(4, 1, 64, 64, 64),
  1, &conv2d_12_weights_array, &conv2d_12_weights_intq)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_bias, AI_STATIC,
  57, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_12_bias_array, &conv2d_12_bias_intq)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_weights, AI_STATIC,
  58, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_13_weights_array, &conv2d_13_weights_intq)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_bias, AI_STATIC,
  59, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_13_bias_array, &conv2d_13_bias_intq)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_weights, AI_STATIC,
  60, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_14_weights_array, &conv2d_14_weights_intq)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_bias, AI_STATIC,
  61, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_14_bias_array, &conv2d_14_bias_intq)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_weights, AI_STATIC,
  62, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_15_weights_array, &conv2d_15_weights_intq)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_bias, AI_STATIC,
  63, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_15_bias_array, &conv2d_15_bias_intq)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_weights, AI_STATIC,
  64, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_16_weights_array, &conv2d_16_weights_intq)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_bias, AI_STATIC,
  65, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_16_bias_array, &conv2d_16_bias_intq)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_weights, AI_STATIC,
  66, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_17_weights_array, &conv2d_17_weights_intq)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_bias, AI_STATIC,
  67, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_17_bias_array, &conv2d_17_bias_intq)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_weights, AI_STATIC,
  68, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_18_weights_array, &conv2d_18_weights_intq)

/* Tensor #69 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_bias, AI_STATIC,
  69, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_18_bias_array, &conv2d_18_bias_intq)

/* Tensor #70 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_weights, AI_STATIC,
  70, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_19_weights_array, &conv2d_19_weights_intq)

/* Tensor #71 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_bias, AI_STATIC,
  71, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_19_bias_array, &conv2d_19_bias_intq)

/* Tensor #72 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_weights, AI_STATIC,
  72, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_20_weights_array, &conv2d_20_weights_intq)

/* Tensor #73 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_bias, AI_STATIC,
  73, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_20_bias_array, &conv2d_20_bias_intq)

/* Tensor #74 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_weights, AI_STATIC,
  74, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_21_weights_array, &conv2d_21_weights_intq)

/* Tensor #75 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_bias, AI_STATIC,
  75, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_21_bias_array, &conv2d_21_bias_intq)

/* Tensor #76 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_weights, AI_STATIC,
  76, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_22_weights_array, &conv2d_22_weights_intq)

/* Tensor #77 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_bias, AI_STATIC,
  77, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_22_bias_array, &conv2d_22_bias_intq)

/* Tensor #78 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_weights, AI_STATIC,
  78, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_23_weights_array, &conv2d_23_weights_intq)

/* Tensor #79 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_bias, AI_STATIC,
  79, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_23_bias_array, &conv2d_23_bias_intq)

/* Tensor #80 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_weights, AI_STATIC,
  80, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 256), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_24_weights_array, &conv2d_24_weights_intq)

/* Tensor #81 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_bias, AI_STATIC,
  81, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &conv2d_24_bias_array, &conv2d_24_bias_intq)

/* Tensor #82 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_weights, AI_STATIC,
  82, 0x1,
  AI_SHAPE_INIT(4, 256, 3, 3, 1), AI_STRIDE_INIT(4, 1, 256, 768, 2304),
  1, &conv2d_25_weights_array, &conv2d_25_weights_intq)

/* Tensor #83 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_bias, AI_STATIC,
  83, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &conv2d_25_bias_array, &conv2d_25_bias_intq)

/* Tensor #84 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_weights, AI_STATIC,
  84, 0x1,
  AI_SHAPE_INIT(4, 256, 1, 1, 256), AI_STRIDE_INIT(4, 1, 256, 256, 256),
  1, &conv2d_26_weights_array, &conv2d_26_weights_intq)

/* Tensor #85 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_bias, AI_STATIC,
  85, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &conv2d_26_bias_array, &conv2d_26_bias_intq)

/* Tensor #86 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_weights, AI_STATIC,
  86, 0x1,
  AI_SHAPE_INIT(4, 256, 1, 1, 2), AI_STRIDE_INIT(4, 1, 256, 256, 256),
  1, &conv2d_28_weights_array, &conv2d_28_weights_intq)

/* Tensor #87 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_bias, AI_STATIC,
  87, 0x1,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 4, 4, 8, 8),
  1, &conv2d_28_bias_array, &conv2d_28_bias_intq)

/* Tensor #88 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_scratch0, AI_STATIC,
  88, 0x0,
  AI_SHAPE_INIT(4, 1, 292, 1, 1), AI_STRIDE_INIT(4, 1, 1, 292, 292),
  1, &conv2d_0_scratch0_array, NULL)

/* Tensor #89 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_scratch1, AI_STATIC,
  89, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 48, 48), AI_STRIDE_INIT(4, 1, 1, 8, 384),
  1, &conv2d_0_scratch1_array, &conv2d_0_scratch1_intq)

/* Tensor #90 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_scratch0, AI_STATIC,
  90, 0x0,
  AI_SHAPE_INIT(4, 1, 297, 1, 1), AI_STRIDE_INIT(4, 1, 1, 297, 297),
  1, &conv2d_1_scratch0_array, NULL)

/* Tensor #91 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_scratch1, AI_STATIC,
  91, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 48, 48), AI_STRIDE_INIT(4, 1, 1, 8, 384),
  1, &conv2d_1_scratch1_array, &conv2d_1_scratch1_intq)

/* Tensor #92 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch0, AI_STATIC,
  92, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 1, 1, 192, 192),
  1, &conv2d_2_scratch0_array, NULL)

/* Tensor #93 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch1, AI_STATIC,
  93, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 48, 48), AI_STRIDE_INIT(4, 1, 1, 16, 768),
  1, &conv2d_2_scratch1_array, &conv2d_2_scratch1_intq)

/* Tensor #94 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch0, AI_STATIC,
  94, 0x0,
  AI_SHAPE_INIT(4, 1, 593, 1, 1), AI_STRIDE_INIT(4, 1, 1, 593, 593),
  1, &conv2d_3_scratch0_array, NULL)

/* Tensor #95 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch1, AI_STATIC,
  95, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 24, 24), AI_STRIDE_INIT(4, 1, 1, 16, 384),
  1, &conv2d_3_scratch1_array, &conv2d_3_scratch1_intq)

/* Tensor #96 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_scratch0, AI_STATIC,
  96, 0x0,
  AI_SHAPE_INIT(4, 1, 384, 1, 1), AI_STRIDE_INIT(4, 1, 1, 384, 384),
  1, &conv2d_4_scratch0_array, NULL)

/* Tensor #97 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_scratch1, AI_STATIC,
  97, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 24, 24), AI_STRIDE_INIT(4, 1, 1, 32, 768),
  1, &conv2d_4_scratch1_array, &conv2d_4_scratch1_intq)

/* Tensor #98 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_scratch0, AI_STATIC,
  98, 0x0,
  AI_SHAPE_INIT(4, 1, 1185, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1185, 1185),
  1, &conv2d_5_scratch0_array, NULL)

/* Tensor #99 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_scratch1, AI_STATIC,
  99, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 24, 24), AI_STRIDE_INIT(4, 1, 1, 32, 768),
  1, &conv2d_5_scratch1_array, &conv2d_5_scratch1_intq)

/* Tensor #100 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_scratch0, AI_STATIC,
  100, 0x0,
  AI_SHAPE_INIT(4, 1, 448, 1, 1), AI_STRIDE_INIT(4, 1, 1, 448, 448),
  1, &conv2d_6_scratch0_array, NULL)

/* Tensor #101 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_scratch1, AI_STATIC,
  101, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 24, 24), AI_STRIDE_INIT(4, 1, 1, 32, 768),
  1, &conv2d_6_scratch1_array, &conv2d_6_scratch1_intq)

/* Tensor #102 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_scratch0, AI_STATIC,
  102, 0x0,
  AI_SHAPE_INIT(4, 1, 1185, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1185, 1185),
  1, &conv2d_7_scratch0_array, NULL)

/* Tensor #103 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_scratch1, AI_STATIC,
  103, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 12, 12), AI_STRIDE_INIT(4, 1, 1, 32, 384),
  1, &conv2d_7_scratch1_array, &conv2d_7_scratch1_intq)

/* Tensor #104 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_scratch0, AI_STATIC,
  104, 0x0,
  AI_SHAPE_INIT(4, 1, 768, 1, 1), AI_STRIDE_INIT(4, 1, 1, 768, 768),
  1, &conv2d_8_scratch0_array, NULL)

/* Tensor #105 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_scratch1, AI_STATIC,
  105, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 12, 12), AI_STRIDE_INIT(4, 1, 1, 64, 768),
  1, &conv2d_8_scratch1_array, &conv2d_8_scratch1_intq)

/* Tensor #106 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch0, AI_STATIC,
  106, 0x0,
  AI_SHAPE_INIT(4, 1, 2369, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2369, 2369),
  1, &conv2d_9_scratch0_array, NULL)

/* Tensor #107 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch1, AI_STATIC,
  107, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 12, 12), AI_STRIDE_INIT(4, 1, 1, 64, 768),
  1, &conv2d_9_scratch1_array, &conv2d_9_scratch1_intq)

/* Tensor #108 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_scratch0, AI_STATIC,
  108, 0x0,
  AI_SHAPE_INIT(4, 1, 896, 1, 1), AI_STRIDE_INIT(4, 1, 1, 896, 896),
  1, &conv2d_10_scratch0_array, NULL)

/* Tensor #109 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_scratch1, AI_STATIC,
  109, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 12, 12), AI_STRIDE_INIT(4, 1, 1, 64, 768),
  1, &conv2d_10_scratch1_array, &conv2d_10_scratch1_intq)

/* Tensor #110 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_scratch0, AI_STATIC,
  110, 0x0,
  AI_SHAPE_INIT(4, 1, 2369, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2369, 2369),
  1, &conv2d_11_scratch0_array, NULL)

/* Tensor #111 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_scratch1, AI_STATIC,
  111, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 6, 6), AI_STRIDE_INIT(4, 1, 1, 64, 384),
  1, &conv2d_11_scratch1_array, &conv2d_11_scratch1_intq)

/* Tensor #112 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_scratch0, AI_STATIC,
  112, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_12_scratch0_array, NULL)

/* Tensor #113 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_scratch1, AI_STATIC,
  113, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_12_scratch1_array, &conv2d_12_scratch1_intq)

/* Tensor #114 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_scratch0, AI_STATIC,
  114, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_13_scratch0_array, NULL)

/* Tensor #115 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_scratch1, AI_STATIC,
  115, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_13_scratch1_array, &conv2d_13_scratch1_intq)

/* Tensor #116 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_scratch0, AI_STATIC,
  116, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_14_scratch0_array, NULL)

/* Tensor #117 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_scratch1, AI_STATIC,
  117, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_14_scratch1_array, &conv2d_14_scratch1_intq)

/* Tensor #118 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_scratch0, AI_STATIC,
  118, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_15_scratch0_array, NULL)

/* Tensor #119 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_scratch1, AI_STATIC,
  119, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_15_scratch1_array, &conv2d_15_scratch1_intq)

/* Tensor #120 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_scratch0, AI_STATIC,
  120, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_16_scratch0_array, NULL)

/* Tensor #121 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_scratch1, AI_STATIC,
  121, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_16_scratch1_array, &conv2d_16_scratch1_intq)

/* Tensor #122 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_scratch0, AI_STATIC,
  122, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_17_scratch0_array, NULL)

/* Tensor #123 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_scratch1, AI_STATIC,
  123, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_17_scratch1_array, &conv2d_17_scratch1_intq)

/* Tensor #124 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_scratch0, AI_STATIC,
  124, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_18_scratch0_array, NULL)

/* Tensor #125 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_scratch1, AI_STATIC,
  125, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_18_scratch1_array, &conv2d_18_scratch1_intq)

/* Tensor #126 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_scratch0, AI_STATIC,
  126, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_19_scratch0_array, NULL)

/* Tensor #127 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_scratch1, AI_STATIC,
  127, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_19_scratch1_array, &conv2d_19_scratch1_intq)

/* Tensor #128 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_scratch0, AI_STATIC,
  128, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_20_scratch0_array, NULL)

/* Tensor #129 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_scratch1, AI_STATIC,
  129, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_20_scratch1_array, &conv2d_20_scratch1_intq)

/* Tensor #130 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_scratch0, AI_STATIC,
  130, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_21_scratch0_array, NULL)

/* Tensor #131 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_scratch1, AI_STATIC,
  131, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_21_scratch1_array, &conv2d_21_scratch1_intq)

/* Tensor #132 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_scratch0, AI_STATIC,
  132, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_22_scratch0_array, NULL)

/* Tensor #133 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_scratch1, AI_STATIC,
  133, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_22_scratch1_array, &conv2d_22_scratch1_intq)

/* Tensor #134 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_scratch0, AI_STATIC,
  134, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_23_scratch0_array, NULL)

/* Tensor #135 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_scratch1, AI_STATIC,
  135, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_23_scratch1_array, &conv2d_23_scratch1_intq)

/* Tensor #136 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_scratch0, AI_STATIC,
  136, 0x0,
  AI_SHAPE_INIT(4, 1, 3072, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3072, 3072),
  1, &conv2d_24_scratch0_array, NULL)

/* Tensor #137 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_scratch1, AI_STATIC,
  137, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 3, 3), AI_STRIDE_INIT(4, 1, 1, 256, 768),
  1, &conv2d_24_scratch1_array, &conv2d_24_scratch1_intq)

/* Tensor #138 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_scratch0, AI_STATIC,
  138, 0x0,
  AI_SHAPE_INIT(4, 1, 9473, 1, 1), AI_STRIDE_INIT(4, 1, 1, 9473, 9473),
  1, &conv2d_25_scratch0_array, NULL)

/* Tensor #139 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_scratch1, AI_STATIC,
  139, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 3, 3), AI_STRIDE_INIT(4, 1, 1, 256, 768),
  1, &conv2d_25_scratch1_array, &conv2d_25_scratch1_intq)

/* Tensor #140 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_scratch0, AI_STATIC,
  140, 0x0,
  AI_SHAPE_INIT(4, 1, 3584, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3584, 3584),
  1, &conv2d_26_scratch0_array, NULL)

/* Tensor #141 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_scratch1, AI_STATIC,
  141, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 3, 3), AI_STRIDE_INIT(4, 1, 1, 256, 768),
  1, &conv2d_26_scratch1_array, &conv2d_26_scratch1_intq)

/* Tensor #142 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_scratch0, AI_STATIC,
  142, 0x0,
  AI_SHAPE_INIT(4, 1, 1044, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1044, 1044),
  1, &conv2d_28_scratch0_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_0_weights, &conv2d_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_0_scratch0, &conv2d_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_0_layer, 0,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_0_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_1_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_1_weights, &conv2d_1_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_1_scratch0, &conv2d_1_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_1_layer, 1,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_1_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_2_layer, AI_STATIC, 
  .groups = 8, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_2_weights, &conv2d_2_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_2_scratch0, &conv2d_2_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_2_layer, 2,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_2_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_3_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_3_weights, &conv2d_3_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_3_scratch0, &conv2d_3_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_3_layer, 3,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_3_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_4_layer, AI_STATIC, 
  .groups = 16, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_4_weights, &conv2d_4_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_4_scratch0, &conv2d_4_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_4_layer, 4,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_4_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_5_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_5_weights, &conv2d_5_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_5_scratch0, &conv2d_5_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_5_layer, 5,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_5_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_6_layer, AI_STATIC, 
  .groups = 32, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_6_weights, &conv2d_6_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_6_scratch0, &conv2d_6_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_6_layer, 6,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_6_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_7_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_7_weights, &conv2d_7_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_7_scratch0, &conv2d_7_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_7_layer, 7,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_7_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_8_layer, AI_STATIC, 
  .groups = 32, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_8_weights, &conv2d_8_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_8_scratch0, &conv2d_8_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_8_layer, 8,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_8_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_9_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_9_weights, &conv2d_9_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_9_scratch0, &conv2d_9_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_9_layer, 9,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_9_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_10_layer, AI_STATIC, 
  .groups = 64, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_10_weights, &conv2d_10_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_10_scratch0, &conv2d_10_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_10_layer, 10,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_10_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_11_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_11_weights, &conv2d_11_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_11_scratch0, &conv2d_11_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_11_layer, 11,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_11_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_12_layer, AI_STATIC, 
  .groups = 64, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_12_weights, &conv2d_12_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_12_scratch0, &conv2d_12_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_12_layer, 12,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_12_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_13_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_13_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_13_weights, &conv2d_13_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_13_scratch0, &conv2d_13_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_13_layer, 13,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_13_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_14_layer, AI_STATIC, 
  .groups = 128, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_14_weights, &conv2d_14_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_14_scratch0, &conv2d_14_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_14_layer, 14,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_14_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_15_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_15_weights, &conv2d_15_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_15_scratch0, &conv2d_15_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_15_layer, 15,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_15_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_16_layer, AI_STATIC, 
  .groups = 128, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_16_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_16_weights, &conv2d_16_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_16_scratch0, &conv2d_16_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_16_layer, 16,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_16_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_17_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_17_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_17_weights, &conv2d_17_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_17_scratch0, &conv2d_17_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_17_layer, 17,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_17_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_18_layer, AI_STATIC, 
  .groups = 128, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_18_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_18_weights, &conv2d_18_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_18_scratch0, &conv2d_18_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_18_layer, 18,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_18_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_19_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_19_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_19_weights, &conv2d_19_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_19_scratch0, &conv2d_19_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_19_layer, 19,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_19_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_20_layer, AI_STATIC, 
  .groups = 128, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_20_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_20_weights, &conv2d_20_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_20_scratch0, &conv2d_20_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_20_layer, 20,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_20_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_21_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_21_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_21_weights, &conv2d_21_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_21_scratch0, &conv2d_21_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_21_layer, 21,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_21_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_22_layer, AI_STATIC, 
  .groups = 128, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_22_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_22_weights, &conv2d_22_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_22_scratch0, &conv2d_22_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_22_layer, 22,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_22_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_23_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_23_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_23_weights, &conv2d_23_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_23_scratch0, &conv2d_23_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_23_layer, 23,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_23_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_24_layer, AI_STATIC, 
  .groups = 128, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_24_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_24_weights, &conv2d_24_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_24_scratch0, &conv2d_24_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_24_layer, 24,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_24_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_25_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_25_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_25_weights, &conv2d_25_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_25_scratch0, &conv2d_25_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_25_layer, 25,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_25_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_26_layer, AI_STATIC, 
  .groups = 256, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_26_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_26_weights, &conv2d_26_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_26_scratch0, &conv2d_26_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_26_layer, 27,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_nl_pool_integer_SSSA_ch,
  &conv2d_26_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_28_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(3, 3), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_ap_array_integer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_28_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_28_weights, &conv2d_28_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_28_layer, 28,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_28_chain,
  &AI_NET_OBJ_INSTANCE, &reshape_29_fmt_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reshape_29_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reshape_29_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reshape_29_fmt_layer, 29,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &reshape_29_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &nl_30_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_30_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reshape_29_fmt_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_30_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_30_layer, 30,
  NL_TYPE, 0x0, NULL,
  nl, forward_sm,
  &nl_30_chain,
  &AI_NET_OBJ_INSTANCE, &nl_30_fmt_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_30_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_30_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_30_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_30_fmt_layer, 30,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &nl_30_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &nl_30_fmt_layer, AI_STATIC, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 218920, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 38240, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &input_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &nl_30_fmt_output),
  &conv2d_0_layer, 0, NULL)



AI_DECLARE_STATIC
ai_bool network_configure_activations(
  ai_network* net_ctx, const ai_buffer* activation_buffer)
{
  AI_ASSERT(net_ctx &&  activation_buffer && activation_buffer->data)

  ai_ptr activations = AI_PTR(AI_PTR_ALIGN(activation_buffer->data, 4));
  AI_ASSERT(activations)
  AI_UNUSED(net_ctx)

  {
    /* Updating activations (byte) offsets */
    input_output_array.data = AI_PTR(NULL);
    input_output_array.data_start = AI_PTR(NULL);
    conv2d_0_output_array.data = AI_PTR(activations + 1184);
    conv2d_0_output_array.data_start = AI_PTR(activations + 1184);
    conv2d_1_output_array.data = AI_PTR(activations + 19616);
    conv2d_1_output_array.data_start = AI_PTR(activations + 19616);
    conv2d_2_output_array.data = AI_PTR(activations + 400);
    conv2d_2_output_array.data_start = AI_PTR(activations + 400);
    conv2d_3_output_array.data = AI_PTR(activations + 0);
    conv2d_3_output_array.data_start = AI_PTR(activations + 0);
    conv2d_4_output_array.data = AI_PTR(activations + 9600);
    conv2d_4_output_array.data_start = AI_PTR(activations + 9600);
    conv2d_5_output_array.data = AI_PTR(activations + 8000);
    conv2d_5_output_array.data_start = AI_PTR(activations + 8000);
    conv2d_6_output_array.data = AI_PTR(activations + 7200);
    conv2d_6_output_array.data_start = AI_PTR(activations + 7200);
    conv2d_7_output_array.data = AI_PTR(activations + 25632);
    conv2d_7_output_array.data_start = AI_PTR(activations + 25632);
    conv2d_8_output_array.data = AI_PTR(activations + 9984);
    conv2d_8_output_array.data_start = AI_PTR(activations + 9984);
    conv2d_9_output_array.data = AI_PTR(activations + 28416);
    conv2d_9_output_array.data_start = AI_PTR(activations + 28416);
    conv2d_10_output_array.data = AI_PTR(activations + 10112);
    conv2d_10_output_array.data_start = AI_PTR(activations + 10112);
    conv2d_11_output_array.data = AI_PTR(activations + 4676);
    conv2d_11_output_array.data_start = AI_PTR(activations + 4676);
    conv2d_12_output_array.data = AI_PTR(activations + 11588);
    conv2d_12_output_array.data_start = AI_PTR(activations + 11588);
    conv2d_13_output_array.data = AI_PTR(activations + 16196);
    conv2d_13_output_array.data_start = AI_PTR(activations + 16196);
    conv2d_14_output_array.data = AI_PTR(activations + 6400);
    conv2d_14_output_array.data_start = AI_PTR(activations + 6400);
    conv2d_15_output_array.data = AI_PTR(activations + 15616);
    conv2d_15_output_array.data_start = AI_PTR(activations + 15616);
    conv2d_16_output_array.data = AI_PTR(activations + 6400);
    conv2d_16_output_array.data_start = AI_PTR(activations + 6400);
    conv2d_17_output_array.data = AI_PTR(activations + 15616);
    conv2d_17_output_array.data_start = AI_PTR(activations + 15616);
    conv2d_18_output_array.data = AI_PTR(activations + 6400);
    conv2d_18_output_array.data_start = AI_PTR(activations + 6400);
    conv2d_19_output_array.data = AI_PTR(activations + 15616);
    conv2d_19_output_array.data_start = AI_PTR(activations + 15616);
    conv2d_20_output_array.data = AI_PTR(activations + 6400);
    conv2d_20_output_array.data_start = AI_PTR(activations + 6400);
    conv2d_21_output_array.data = AI_PTR(activations + 15616);
    conv2d_21_output_array.data_start = AI_PTR(activations + 15616);
    conv2d_22_output_array.data = AI_PTR(activations + 6400);
    conv2d_22_output_array.data_start = AI_PTR(activations + 6400);
    conv2d_23_output_array.data = AI_PTR(activations + 11008);
    conv2d_23_output_array.data_start = AI_PTR(activations + 11008);
    conv2d_24_output_array.data = AI_PTR(activations + 5376);
    conv2d_24_output_array.data_start = AI_PTR(activations + 5376);
    conv2d_25_output_array.data = AI_PTR(activations + 2304);
    conv2d_25_output_array.data_start = AI_PTR(activations + 2304);
    conv2d_26_output_array.data = AI_PTR(activations + 8192);
    conv2d_26_output_array.data_start = AI_PTR(activations + 8192);
    conv2d_28_output_array.data = AI_PTR(activations + 1044);
    conv2d_28_output_array.data_start = AI_PTR(activations + 1044);
    reshape_29_fmt_output_array.data = AI_PTR(activations + 0);
    reshape_29_fmt_output_array.data_start = AI_PTR(activations + 0);
    nl_30_output_array.data = AI_PTR(activations + 8);
    nl_30_output_array.data_start = AI_PTR(activations + 8);
    nl_30_fmt_output_array.data = AI_PTR(NULL);
    nl_30_fmt_output_array.data_start = AI_PTR(NULL);
    conv2d_0_scratch0_array.data = AI_PTR(activations + 19616);
    conv2d_0_scratch0_array.data_start = AI_PTR(activations + 19616);
    conv2d_0_scratch1_array.data = AI_PTR(activations + 1184);
    conv2d_0_scratch1_array.data_start = AI_PTR(activations + 1184);
    conv2d_1_scratch0_array.data = AI_PTR(activations + 884);
    conv2d_1_scratch0_array.data_start = AI_PTR(activations + 884);
    conv2d_1_scratch1_array.data = AI_PTR(activations + 19616);
    conv2d_1_scratch1_array.data_start = AI_PTR(activations + 19616);
    conv2d_2_scratch0_array.data = AI_PTR(activations + 38048);
    conv2d_2_scratch0_array.data_start = AI_PTR(activations + 38048);
    conv2d_2_scratch1_array.data = AI_PTR(activations + 400);
    conv2d_2_scratch1_array.data_start = AI_PTR(activations + 400);
    conv2d_3_scratch0_array.data = AI_PTR(activations + 37644);
    conv2d_3_scratch0_array.data_start = AI_PTR(activations + 37644);
    conv2d_3_scratch1_array.data = AI_PTR(activations + 0);
    conv2d_3_scratch1_array.data_start = AI_PTR(activations + 0);
    conv2d_4_scratch0_array.data = AI_PTR(activations + 9216);
    conv2d_4_scratch0_array.data_start = AI_PTR(activations + 9216);
    conv2d_4_scratch1_array.data = AI_PTR(activations + 9600);
    conv2d_4_scratch1_array.data_start = AI_PTR(activations + 9600);
    conv2d_5_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_5_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_5_scratch1_array.data = AI_PTR(activations + 8000);
    conv2d_5_scratch1_array.data_start = AI_PTR(activations + 8000);
    conv2d_6_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_6_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_6_scratch1_array.data = AI_PTR(activations + 7200);
    conv2d_6_scratch1_array.data_start = AI_PTR(activations + 7200);
    conv2d_7_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_7_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_7_scratch1_array.data = AI_PTR(activations + 1188);
    conv2d_7_scratch1_array.data_start = AI_PTR(activations + 1188);
    conv2d_8_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_8_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_8_scratch1_array.data = AI_PTR(activations + 768);
    conv2d_8_scratch1_array.data_start = AI_PTR(activations + 768);
    conv2d_9_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_9_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_9_scratch1_array.data = AI_PTR(activations + 19200);
    conv2d_9_scratch1_array.data_start = AI_PTR(activations + 19200);
    conv2d_10_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_10_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_10_scratch1_array.data = AI_PTR(activations + 896);
    conv2d_10_scratch1_array.data_start = AI_PTR(activations + 896);
    conv2d_11_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_11_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_11_scratch1_array.data = AI_PTR(activations + 2372);
    conv2d_11_scratch1_array.data_start = AI_PTR(activations + 2372);
    conv2d_12_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_12_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_12_scratch1_array.data = AI_PTR(activations + 6980);
    conv2d_12_scratch1_array.data_start = AI_PTR(activations + 6980);
    conv2d_13_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_13_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_13_scratch1_array.data = AI_PTR(activations + 4740);
    conv2d_13_scratch1_array.data_start = AI_PTR(activations + 4740);
    conv2d_14_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_14_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_14_scratch1_array.data = AI_PTR(activations + 1792);
    conv2d_14_scratch1_array.data_start = AI_PTR(activations + 1792);
    conv2d_15_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_15_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_15_scratch1_array.data = AI_PTR(activations + 11008);
    conv2d_15_scratch1_array.data_start = AI_PTR(activations + 11008);
    conv2d_16_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_16_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_16_scratch1_array.data = AI_PTR(activations + 1792);
    conv2d_16_scratch1_array.data_start = AI_PTR(activations + 1792);
    conv2d_17_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_17_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_17_scratch1_array.data = AI_PTR(activations + 11008);
    conv2d_17_scratch1_array.data_start = AI_PTR(activations + 11008);
    conv2d_18_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_18_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_18_scratch1_array.data = AI_PTR(activations + 1792);
    conv2d_18_scratch1_array.data_start = AI_PTR(activations + 1792);
    conv2d_19_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_19_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_19_scratch1_array.data = AI_PTR(activations + 11008);
    conv2d_19_scratch1_array.data_start = AI_PTR(activations + 11008);
    conv2d_20_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_20_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_20_scratch1_array.data = AI_PTR(activations + 1792);
    conv2d_20_scratch1_array.data_start = AI_PTR(activations + 1792);
    conv2d_21_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_21_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_21_scratch1_array.data = AI_PTR(activations + 11008);
    conv2d_21_scratch1_array.data_start = AI_PTR(activations + 11008);
    conv2d_22_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_22_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_22_scratch1_array.data = AI_PTR(activations + 1792);
    conv2d_22_scratch1_array.data_start = AI_PTR(activations + 1792);
    conv2d_23_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_23_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_23_scratch1_array.data = AI_PTR(activations + 4740);
    conv2d_23_scratch1_array.data_start = AI_PTR(activations + 4740);
    conv2d_24_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_24_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_24_scratch1_array.data = AI_PTR(activations + 3072);
    conv2d_24_scratch1_array.data_start = AI_PTR(activations + 3072);
    conv2d_25_scratch0_array.data = AI_PTR(activations + 7680);
    conv2d_25_scratch0_array.data_start = AI_PTR(activations + 7680);
    conv2d_25_scratch1_array.data = AI_PTR(activations + 0);
    conv2d_25_scratch1_array.data_start = AI_PTR(activations + 0);
    conv2d_26_scratch0_array.data = AI_PTR(activations + 4608);
    conv2d_26_scratch0_array.data_start = AI_PTR(activations + 4608);
    conv2d_26_scratch1_array.data = AI_PTR(activations + 0);
    conv2d_26_scratch1_array.data_start = AI_PTR(activations + 0);
    conv2d_28_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_28_scratch0_array.data_start = AI_PTR(activations + 0);
    
  }
  return true;
}



AI_DECLARE_STATIC
ai_bool network_configure_weights(
  ai_network* net_ctx, const ai_buffer* weights_buffer)
{
  AI_ASSERT(net_ctx &&  weights_buffer && weights_buffer->data)

  ai_ptr weights = AI_PTR(weights_buffer->data);
  AI_ASSERT(weights)
  AI_UNUSED(net_ctx)

  {
    /* Updating weights (byte) offsets */
    
    conv2d_0_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_0_weights_array.data = AI_PTR(weights + 0);
    conv2d_0_weights_array.data_start = AI_PTR(weights + 0);
    conv2d_0_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_0_bias_array.data = AI_PTR(weights + 72);
    conv2d_0_bias_array.data_start = AI_PTR(weights + 72);
    conv2d_1_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_weights_array.data = AI_PTR(weights + 104);
    conv2d_1_weights_array.data_start = AI_PTR(weights + 104);
    conv2d_1_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_bias_array.data = AI_PTR(weights + 176);
    conv2d_1_bias_array.data_start = AI_PTR(weights + 176);
    conv2d_2_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_weights_array.data = AI_PTR(weights + 208);
    conv2d_2_weights_array.data_start = AI_PTR(weights + 208);
    conv2d_2_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_bias_array.data = AI_PTR(weights + 336);
    conv2d_2_bias_array.data_start = AI_PTR(weights + 336);
    conv2d_3_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_weights_array.data = AI_PTR(weights + 400);
    conv2d_3_weights_array.data_start = AI_PTR(weights + 400);
    conv2d_3_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_bias_array.data = AI_PTR(weights + 544);
    conv2d_3_bias_array.data_start = AI_PTR(weights + 544);
    conv2d_4_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_weights_array.data = AI_PTR(weights + 608);
    conv2d_4_weights_array.data_start = AI_PTR(weights + 608);
    conv2d_4_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_bias_array.data = AI_PTR(weights + 1120);
    conv2d_4_bias_array.data_start = AI_PTR(weights + 1120);
    conv2d_5_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_weights_array.data = AI_PTR(weights + 1248);
    conv2d_5_weights_array.data_start = AI_PTR(weights + 1248);
    conv2d_5_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_bias_array.data = AI_PTR(weights + 1536);
    conv2d_5_bias_array.data_start = AI_PTR(weights + 1536);
    conv2d_6_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_weights_array.data = AI_PTR(weights + 1664);
    conv2d_6_weights_array.data_start = AI_PTR(weights + 1664);
    conv2d_6_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_bias_array.data = AI_PTR(weights + 2688);
    conv2d_6_bias_array.data_start = AI_PTR(weights + 2688);
    conv2d_7_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_weights_array.data = AI_PTR(weights + 2816);
    conv2d_7_weights_array.data_start = AI_PTR(weights + 2816);
    conv2d_7_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_bias_array.data = AI_PTR(weights + 3104);
    conv2d_7_bias_array.data_start = AI_PTR(weights + 3104);
    conv2d_8_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_8_weights_array.data = AI_PTR(weights + 3232);
    conv2d_8_weights_array.data_start = AI_PTR(weights + 3232);
    conv2d_8_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_8_bias_array.data = AI_PTR(weights + 5280);
    conv2d_8_bias_array.data_start = AI_PTR(weights + 5280);
    conv2d_9_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_weights_array.data = AI_PTR(weights + 5536);
    conv2d_9_weights_array.data_start = AI_PTR(weights + 5536);
    conv2d_9_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_bias_array.data = AI_PTR(weights + 6112);
    conv2d_9_bias_array.data_start = AI_PTR(weights + 6112);
    conv2d_10_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_weights_array.data = AI_PTR(weights + 6368);
    conv2d_10_weights_array.data_start = AI_PTR(weights + 6368);
    conv2d_10_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_bias_array.data = AI_PTR(weights + 10464);
    conv2d_10_bias_array.data_start = AI_PTR(weights + 10464);
    conv2d_11_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_11_weights_array.data = AI_PTR(weights + 10720);
    conv2d_11_weights_array.data_start = AI_PTR(weights + 10720);
    conv2d_11_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_11_bias_array.data = AI_PTR(weights + 11296);
    conv2d_11_bias_array.data_start = AI_PTR(weights + 11296);
    conv2d_12_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_12_weights_array.data = AI_PTR(weights + 11552);
    conv2d_12_weights_array.data_start = AI_PTR(weights + 11552);
    conv2d_12_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_12_bias_array.data = AI_PTR(weights + 19744);
    conv2d_12_bias_array.data_start = AI_PTR(weights + 19744);
    conv2d_13_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_13_weights_array.data = AI_PTR(weights + 20256);
    conv2d_13_weights_array.data_start = AI_PTR(weights + 20256);
    conv2d_13_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_13_bias_array.data = AI_PTR(weights + 21408);
    conv2d_13_bias_array.data_start = AI_PTR(weights + 21408);
    conv2d_14_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_14_weights_array.data = AI_PTR(weights + 21920);
    conv2d_14_weights_array.data_start = AI_PTR(weights + 21920);
    conv2d_14_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_14_bias_array.data = AI_PTR(weights + 38304);
    conv2d_14_bias_array.data_start = AI_PTR(weights + 38304);
    conv2d_15_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_weights_array.data = AI_PTR(weights + 38816);
    conv2d_15_weights_array.data_start = AI_PTR(weights + 38816);
    conv2d_15_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_bias_array.data = AI_PTR(weights + 39968);
    conv2d_15_bias_array.data_start = AI_PTR(weights + 39968);
    conv2d_16_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_weights_array.data = AI_PTR(weights + 40480);
    conv2d_16_weights_array.data_start = AI_PTR(weights + 40480);
    conv2d_16_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_bias_array.data = AI_PTR(weights + 56864);
    conv2d_16_bias_array.data_start = AI_PTR(weights + 56864);
    conv2d_17_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_weights_array.data = AI_PTR(weights + 57376);
    conv2d_17_weights_array.data_start = AI_PTR(weights + 57376);
    conv2d_17_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_bias_array.data = AI_PTR(weights + 58528);
    conv2d_17_bias_array.data_start = AI_PTR(weights + 58528);
    conv2d_18_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_weights_array.data = AI_PTR(weights + 59040);
    conv2d_18_weights_array.data_start = AI_PTR(weights + 59040);
    conv2d_18_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_bias_array.data = AI_PTR(weights + 75424);
    conv2d_18_bias_array.data_start = AI_PTR(weights + 75424);
    conv2d_19_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_19_weights_array.data = AI_PTR(weights + 75936);
    conv2d_19_weights_array.data_start = AI_PTR(weights + 75936);
    conv2d_19_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_19_bias_array.data = AI_PTR(weights + 77088);
    conv2d_19_bias_array.data_start = AI_PTR(weights + 77088);
    conv2d_20_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_20_weights_array.data = AI_PTR(weights + 77600);
    conv2d_20_weights_array.data_start = AI_PTR(weights + 77600);
    conv2d_20_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_20_bias_array.data = AI_PTR(weights + 93984);
    conv2d_20_bias_array.data_start = AI_PTR(weights + 93984);
    conv2d_21_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_weights_array.data = AI_PTR(weights + 94496);
    conv2d_21_weights_array.data_start = AI_PTR(weights + 94496);
    conv2d_21_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_bias_array.data = AI_PTR(weights + 95648);
    conv2d_21_bias_array.data_start = AI_PTR(weights + 95648);
    conv2d_22_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_weights_array.data = AI_PTR(weights + 96160);
    conv2d_22_weights_array.data_start = AI_PTR(weights + 96160);
    conv2d_22_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_bias_array.data = AI_PTR(weights + 112544);
    conv2d_22_bias_array.data_start = AI_PTR(weights + 112544);
    conv2d_23_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_weights_array.data = AI_PTR(weights + 113056);
    conv2d_23_weights_array.data_start = AI_PTR(weights + 113056);
    conv2d_23_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_bias_array.data = AI_PTR(weights + 114208);
    conv2d_23_bias_array.data_start = AI_PTR(weights + 114208);
    conv2d_24_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_24_weights_array.data = AI_PTR(weights + 114720);
    conv2d_24_weights_array.data_start = AI_PTR(weights + 114720);
    conv2d_24_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_24_bias_array.data = AI_PTR(weights + 147488);
    conv2d_24_bias_array.data_start = AI_PTR(weights + 147488);
    conv2d_25_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_25_weights_array.data = AI_PTR(weights + 148512);
    conv2d_25_weights_array.data_start = AI_PTR(weights + 148512);
    conv2d_25_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_25_bias_array.data = AI_PTR(weights + 150816);
    conv2d_25_bias_array.data_start = AI_PTR(weights + 150816);
    conv2d_26_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_26_weights_array.data = AI_PTR(weights + 151840);
    conv2d_26_weights_array.data_start = AI_PTR(weights + 151840);
    conv2d_26_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_26_bias_array.data = AI_PTR(weights + 217376);
    conv2d_26_bias_array.data_start = AI_PTR(weights + 217376);
    conv2d_28_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_28_weights_array.data = AI_PTR(weights + 218400);
    conv2d_28_weights_array.data_start = AI_PTR(weights + 218400);
    conv2d_28_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_28_bias_array.data = AI_PTR(weights + 218912);
    conv2d_28_bias_array.data_start = AI_PTR(weights + 218912);
  }

  return true;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_API_ENTRY
ai_bool ai_network_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if ( report && net_ctx )
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_MODEL_NAME,
      .model_signature   = AI_NETWORK_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 7162968,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .activations       = AI_STRUCT_INIT,
      .params            = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }

  return false;
}

AI_API_ENTRY
ai_error ai_network_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_network_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_network_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_network_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if ( !net_ctx ) return false;

  ai_bool ok = true;
  ok &= network_configure_weights(net_ctx, &params->params);
  ok &= network_configure_activations(net_ctx, &params->activations);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_network_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_NETWORK_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

