/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Sun Nov 21 19:14:58 2021
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
#define AI_NETWORK_MODEL_SIGNATURE     "0161aec65ab4468f7c028b90a142f90f"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Sun Nov 21 19:14:58 2021"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array serving_default_conv2d_input0_int8_output_array;   /* Array #0 */
AI_STATIC ai_array conv2d_0_output_array;   /* Array #1 */
AI_STATIC ai_array eltwise_2_output_array;   /* Array #2 */
AI_STATIC ai_array conv2d_3_output_array;   /* Array #3 */
AI_STATIC ai_array eltwise_5_output_array;   /* Array #4 */
AI_STATIC ai_array conv2d_6_output_array;   /* Array #5 */
AI_STATIC ai_array eltwise_8_output_array;   /* Array #6 */
AI_STATIC ai_array conv2d_9_output_array;   /* Array #7 */
AI_STATIC ai_array eltwise_11_output_array;   /* Array #8 */
AI_STATIC ai_array conv2d_12_output_array;   /* Array #9 */
AI_STATIC ai_array eltwise_14_output_array;   /* Array #10 */
AI_STATIC ai_array conv2d_15_output_array;   /* Array #11 */
AI_STATIC ai_array eltwise_17_output_array;   /* Array #12 */
AI_STATIC ai_array conv2d_18_output_array;   /* Array #13 */
AI_STATIC ai_array eltwise_20_output_array;   /* Array #14 */
AI_STATIC ai_array conv2d_21_output_array;   /* Array #15 */
AI_STATIC ai_array eltwise_23_output_array;   /* Array #16 */
AI_STATIC ai_array conv2d_24_output_array;   /* Array #17 */
AI_STATIC ai_array eltwise_26_output_array;   /* Array #18 */
AI_STATIC ai_array conv2d_27_output_array;   /* Array #19 */
AI_STATIC ai_array eltwise_29_output_array;   /* Array #20 */
AI_STATIC ai_array conv2d_30_output_array;   /* Array #21 */
AI_STATIC ai_array eltwise_32_output_array;   /* Array #22 */
AI_STATIC ai_array conv2d_33_output_array;   /* Array #23 */
AI_STATIC ai_array eltwise_35_output_array;   /* Array #24 */
AI_STATIC ai_array conv2d_36_output_array;   /* Array #25 */
AI_STATIC ai_array eltwise_38_output_array;   /* Array #26 */
AI_STATIC ai_array conv2d_39_output_array;   /* Array #27 */
AI_STATIC ai_array eltwise_41_output_array;   /* Array #28 */
AI_STATIC ai_array conv2d_42_output_array;   /* Array #29 */
AI_STATIC ai_array eltwise_44_output_array;   /* Array #30 */
AI_STATIC ai_array conv2d_45_output_array;   /* Array #31 */
AI_STATIC ai_array eltwise_47_output_array;   /* Array #32 */
AI_STATIC ai_array conv2d_48_output_array;   /* Array #33 */
AI_STATIC ai_array eltwise_50_output_array;   /* Array #34 */
AI_STATIC ai_array conv2d_51_output_array;   /* Array #35 */
AI_STATIC ai_array eltwise_53_output_array;   /* Array #36 */
AI_STATIC ai_array dense_55_output_array;   /* Array #37 */
AI_STATIC ai_array dense_55_fmt_output_array;   /* Array #38 */
AI_STATIC ai_array nl_56_output_array;   /* Array #39 */
AI_STATIC ai_array nl_56_fmt_output_array;   /* Array #40 */
AI_STATIC ai_array conv2d_0_weights_array;   /* Array #41 */
AI_STATIC ai_array conv2d_0_bias_array;   /* Array #42 */
AI_STATIC ai_array eltwise_2_scale_array;   /* Array #43 */
AI_STATIC ai_array eltwise_2_bias_array;   /* Array #44 */
AI_STATIC ai_array conv2d_3_weights_array;   /* Array #45 */
AI_STATIC ai_array conv2d_3_bias_array;   /* Array #46 */
AI_STATIC ai_array eltwise_5_scale_array;   /* Array #47 */
AI_STATIC ai_array eltwise_5_bias_array;   /* Array #48 */
AI_STATIC ai_array conv2d_6_weights_array;   /* Array #49 */
AI_STATIC ai_array conv2d_6_bias_array;   /* Array #50 */
AI_STATIC ai_array eltwise_8_scale_array;   /* Array #51 */
AI_STATIC ai_array eltwise_8_bias_array;   /* Array #52 */
AI_STATIC ai_array conv2d_9_weights_array;   /* Array #53 */
AI_STATIC ai_array conv2d_9_bias_array;   /* Array #54 */
AI_STATIC ai_array eltwise_11_scale_array;   /* Array #55 */
AI_STATIC ai_array eltwise_11_bias_array;   /* Array #56 */
AI_STATIC ai_array conv2d_12_weights_array;   /* Array #57 */
AI_STATIC ai_array conv2d_12_bias_array;   /* Array #58 */
AI_STATIC ai_array eltwise_14_scale_array;   /* Array #59 */
AI_STATIC ai_array eltwise_14_bias_array;   /* Array #60 */
AI_STATIC ai_array conv2d_15_weights_array;   /* Array #61 */
AI_STATIC ai_array conv2d_15_bias_array;   /* Array #62 */
AI_STATIC ai_array eltwise_17_scale_array;   /* Array #63 */
AI_STATIC ai_array eltwise_17_bias_array;   /* Array #64 */
AI_STATIC ai_array conv2d_18_weights_array;   /* Array #65 */
AI_STATIC ai_array conv2d_18_bias_array;   /* Array #66 */
AI_STATIC ai_array eltwise_20_scale_array;   /* Array #67 */
AI_STATIC ai_array eltwise_20_bias_array;   /* Array #68 */
AI_STATIC ai_array conv2d_21_weights_array;   /* Array #69 */
AI_STATIC ai_array conv2d_21_bias_array;   /* Array #70 */
AI_STATIC ai_array eltwise_23_scale_array;   /* Array #71 */
AI_STATIC ai_array eltwise_23_bias_array;   /* Array #72 */
AI_STATIC ai_array conv2d_24_weights_array;   /* Array #73 */
AI_STATIC ai_array conv2d_24_bias_array;   /* Array #74 */
AI_STATIC ai_array eltwise_26_scale_array;   /* Array #75 */
AI_STATIC ai_array eltwise_26_bias_array;   /* Array #76 */
AI_STATIC ai_array conv2d_27_weights_array;   /* Array #77 */
AI_STATIC ai_array conv2d_27_bias_array;   /* Array #78 */
AI_STATIC ai_array eltwise_29_scale_array;   /* Array #79 */
AI_STATIC ai_array eltwise_29_bias_array;   /* Array #80 */
AI_STATIC ai_array conv2d_30_weights_array;   /* Array #81 */
AI_STATIC ai_array conv2d_30_bias_array;   /* Array #82 */
AI_STATIC ai_array eltwise_32_scale_array;   /* Array #83 */
AI_STATIC ai_array eltwise_32_bias_array;   /* Array #84 */
AI_STATIC ai_array conv2d_33_weights_array;   /* Array #85 */
AI_STATIC ai_array conv2d_33_bias_array;   /* Array #86 */
AI_STATIC ai_array eltwise_35_scale_array;   /* Array #87 */
AI_STATIC ai_array eltwise_35_bias_array;   /* Array #88 */
AI_STATIC ai_array conv2d_36_weights_array;   /* Array #89 */
AI_STATIC ai_array conv2d_36_bias_array;   /* Array #90 */
AI_STATIC ai_array eltwise_38_scale_array;   /* Array #91 */
AI_STATIC ai_array eltwise_38_bias_array;   /* Array #92 */
AI_STATIC ai_array conv2d_39_weights_array;   /* Array #93 */
AI_STATIC ai_array conv2d_39_bias_array;   /* Array #94 */
AI_STATIC ai_array eltwise_41_scale_array;   /* Array #95 */
AI_STATIC ai_array eltwise_41_bias_array;   /* Array #96 */
AI_STATIC ai_array conv2d_42_weights_array;   /* Array #97 */
AI_STATIC ai_array conv2d_42_bias_array;   /* Array #98 */
AI_STATIC ai_array eltwise_44_scale_array;   /* Array #99 */
AI_STATIC ai_array eltwise_44_bias_array;   /* Array #100 */
AI_STATIC ai_array conv2d_45_weights_array;   /* Array #101 */
AI_STATIC ai_array conv2d_45_bias_array;   /* Array #102 */
AI_STATIC ai_array eltwise_47_scale_array;   /* Array #103 */
AI_STATIC ai_array eltwise_47_bias_array;   /* Array #104 */
AI_STATIC ai_array conv2d_48_weights_array;   /* Array #105 */
AI_STATIC ai_array conv2d_48_bias_array;   /* Array #106 */
AI_STATIC ai_array eltwise_50_scale_array;   /* Array #107 */
AI_STATIC ai_array eltwise_50_bias_array;   /* Array #108 */
AI_STATIC ai_array conv2d_51_weights_array;   /* Array #109 */
AI_STATIC ai_array conv2d_51_bias_array;   /* Array #110 */
AI_STATIC ai_array eltwise_53_scale_array;   /* Array #111 */
AI_STATIC ai_array eltwise_53_bias_array;   /* Array #112 */
AI_STATIC ai_array dense_55_weights_array;   /* Array #113 */
AI_STATIC ai_array dense_55_bias_array;   /* Array #114 */
AI_STATIC ai_array conv2d_0_scratch0_array;   /* Array #115 */
AI_STATIC ai_array eltwise_2_scratch0_array;   /* Array #116 */
AI_STATIC ai_array conv2d_3_scratch0_array;   /* Array #117 */
AI_STATIC ai_array eltwise_5_scratch0_array;   /* Array #118 */
AI_STATIC ai_array conv2d_6_scratch0_array;   /* Array #119 */
AI_STATIC ai_array eltwise_8_scratch0_array;   /* Array #120 */
AI_STATIC ai_array conv2d_9_scratch0_array;   /* Array #121 */
AI_STATIC ai_array eltwise_11_scratch0_array;   /* Array #122 */
AI_STATIC ai_array conv2d_12_scratch0_array;   /* Array #123 */
AI_STATIC ai_array eltwise_14_scratch0_array;   /* Array #124 */
AI_STATIC ai_array conv2d_15_scratch0_array;   /* Array #125 */
AI_STATIC ai_array eltwise_17_scratch0_array;   /* Array #126 */
AI_STATIC ai_array conv2d_18_scratch0_array;   /* Array #127 */
AI_STATIC ai_array eltwise_20_scratch0_array;   /* Array #128 */
AI_STATIC ai_array conv2d_21_scratch0_array;   /* Array #129 */
AI_STATIC ai_array eltwise_23_scratch0_array;   /* Array #130 */
AI_STATIC ai_array conv2d_24_scratch0_array;   /* Array #131 */
AI_STATIC ai_array eltwise_26_scratch0_array;   /* Array #132 */
AI_STATIC ai_array conv2d_27_scratch0_array;   /* Array #133 */
AI_STATIC ai_array eltwise_29_scratch0_array;   /* Array #134 */
AI_STATIC ai_array conv2d_30_scratch0_array;   /* Array #135 */
AI_STATIC ai_array eltwise_32_scratch0_array;   /* Array #136 */
AI_STATIC ai_array conv2d_33_scratch0_array;   /* Array #137 */
AI_STATIC ai_array eltwise_35_scratch0_array;   /* Array #138 */
AI_STATIC ai_array conv2d_36_scratch0_array;   /* Array #139 */
AI_STATIC ai_array eltwise_38_scratch0_array;   /* Array #140 */
AI_STATIC ai_array conv2d_39_scratch0_array;   /* Array #141 */
AI_STATIC ai_array eltwise_41_scratch0_array;   /* Array #142 */
AI_STATIC ai_array conv2d_42_scratch0_array;   /* Array #143 */
AI_STATIC ai_array eltwise_44_scratch0_array;   /* Array #144 */
AI_STATIC ai_array conv2d_45_scratch0_array;   /* Array #145 */
AI_STATIC ai_array eltwise_47_scratch0_array;   /* Array #146 */
AI_STATIC ai_array conv2d_48_scratch0_array;   /* Array #147 */
AI_STATIC ai_array eltwise_50_scratch0_array;   /* Array #148 */
AI_STATIC ai_array conv2d_51_scratch0_array;   /* Array #149 */
AI_STATIC ai_array eltwise_53_scratch0_array;   /* Array #150 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor serving_default_conv2d_input0_int8_output;   /* Tensor #0 */
AI_STATIC ai_tensor conv2d_0_output;   /* Tensor #1 */
AI_STATIC ai_tensor eltwise_2_output;   /* Tensor #2 */
AI_STATIC ai_tensor conv2d_3_output;   /* Tensor #3 */
AI_STATIC ai_tensor eltwise_5_output;   /* Tensor #4 */
AI_STATIC ai_tensor conv2d_6_output;   /* Tensor #5 */
AI_STATIC ai_tensor eltwise_8_output;   /* Tensor #6 */
AI_STATIC ai_tensor conv2d_9_output;   /* Tensor #7 */
AI_STATIC ai_tensor eltwise_11_output;   /* Tensor #8 */
AI_STATIC ai_tensor conv2d_12_output;   /* Tensor #9 */
AI_STATIC ai_tensor eltwise_14_output;   /* Tensor #10 */
AI_STATIC ai_tensor conv2d_15_output;   /* Tensor #11 */
AI_STATIC ai_tensor eltwise_17_output;   /* Tensor #12 */
AI_STATIC ai_tensor conv2d_18_output;   /* Tensor #13 */
AI_STATIC ai_tensor eltwise_20_output;   /* Tensor #14 */
AI_STATIC ai_tensor conv2d_21_output;   /* Tensor #15 */
AI_STATIC ai_tensor eltwise_23_output;   /* Tensor #16 */
AI_STATIC ai_tensor conv2d_24_output;   /* Tensor #17 */
AI_STATIC ai_tensor eltwise_26_output;   /* Tensor #18 */
AI_STATIC ai_tensor conv2d_27_output;   /* Tensor #19 */
AI_STATIC ai_tensor eltwise_29_output;   /* Tensor #20 */
AI_STATIC ai_tensor conv2d_30_output;   /* Tensor #21 */
AI_STATIC ai_tensor eltwise_32_output;   /* Tensor #22 */
AI_STATIC ai_tensor conv2d_33_output;   /* Tensor #23 */
AI_STATIC ai_tensor eltwise_35_output;   /* Tensor #24 */
AI_STATIC ai_tensor conv2d_36_output;   /* Tensor #25 */
AI_STATIC ai_tensor eltwise_38_output;   /* Tensor #26 */
AI_STATIC ai_tensor conv2d_39_output;   /* Tensor #27 */
AI_STATIC ai_tensor eltwise_41_output;   /* Tensor #28 */
AI_STATIC ai_tensor conv2d_42_output;   /* Tensor #29 */
AI_STATIC ai_tensor eltwise_44_output;   /* Tensor #30 */
AI_STATIC ai_tensor conv2d_45_output;   /* Tensor #31 */
AI_STATIC ai_tensor eltwise_47_output;   /* Tensor #32 */
AI_STATIC ai_tensor conv2d_48_output;   /* Tensor #33 */
AI_STATIC ai_tensor eltwise_50_output;   /* Tensor #34 */
AI_STATIC ai_tensor conv2d_51_output;   /* Tensor #35 */
AI_STATIC ai_tensor eltwise_53_output;   /* Tensor #36 */
AI_STATIC ai_tensor eltwise_53_output0;   /* Tensor #37 */
AI_STATIC ai_tensor dense_55_output;   /* Tensor #38 */
AI_STATIC ai_tensor dense_55_fmt_output;   /* Tensor #39 */
AI_STATIC ai_tensor nl_56_output;   /* Tensor #40 */
AI_STATIC ai_tensor nl_56_fmt_output;   /* Tensor #41 */
AI_STATIC ai_tensor conv2d_0_weights;   /* Tensor #42 */
AI_STATIC ai_tensor conv2d_0_bias;   /* Tensor #43 */
AI_STATIC ai_tensor eltwise_2_scale;   /* Tensor #44 */
AI_STATIC ai_tensor eltwise_2_bias;   /* Tensor #45 */
AI_STATIC ai_tensor conv2d_3_weights;   /* Tensor #46 */
AI_STATIC ai_tensor conv2d_3_bias;   /* Tensor #47 */
AI_STATIC ai_tensor eltwise_5_scale;   /* Tensor #48 */
AI_STATIC ai_tensor eltwise_5_bias;   /* Tensor #49 */
AI_STATIC ai_tensor conv2d_6_weights;   /* Tensor #50 */
AI_STATIC ai_tensor conv2d_6_bias;   /* Tensor #51 */
AI_STATIC ai_tensor eltwise_8_scale;   /* Tensor #52 */
AI_STATIC ai_tensor eltwise_8_bias;   /* Tensor #53 */
AI_STATIC ai_tensor conv2d_9_weights;   /* Tensor #54 */
AI_STATIC ai_tensor conv2d_9_bias;   /* Tensor #55 */
AI_STATIC ai_tensor eltwise_11_scale;   /* Tensor #56 */
AI_STATIC ai_tensor eltwise_11_bias;   /* Tensor #57 */
AI_STATIC ai_tensor conv2d_12_weights;   /* Tensor #58 */
AI_STATIC ai_tensor conv2d_12_bias;   /* Tensor #59 */
AI_STATIC ai_tensor eltwise_14_scale;   /* Tensor #60 */
AI_STATIC ai_tensor eltwise_14_bias;   /* Tensor #61 */
AI_STATIC ai_tensor conv2d_15_weights;   /* Tensor #62 */
AI_STATIC ai_tensor conv2d_15_bias;   /* Tensor #63 */
AI_STATIC ai_tensor eltwise_17_scale;   /* Tensor #64 */
AI_STATIC ai_tensor eltwise_17_bias;   /* Tensor #65 */
AI_STATIC ai_tensor conv2d_18_weights;   /* Tensor #66 */
AI_STATIC ai_tensor conv2d_18_bias;   /* Tensor #67 */
AI_STATIC ai_tensor eltwise_20_scale;   /* Tensor #68 */
AI_STATIC ai_tensor eltwise_20_bias;   /* Tensor #69 */
AI_STATIC ai_tensor conv2d_21_weights;   /* Tensor #70 */
AI_STATIC ai_tensor conv2d_21_bias;   /* Tensor #71 */
AI_STATIC ai_tensor eltwise_23_scale;   /* Tensor #72 */
AI_STATIC ai_tensor eltwise_23_bias;   /* Tensor #73 */
AI_STATIC ai_tensor conv2d_24_weights;   /* Tensor #74 */
AI_STATIC ai_tensor conv2d_24_bias;   /* Tensor #75 */
AI_STATIC ai_tensor eltwise_26_scale;   /* Tensor #76 */
AI_STATIC ai_tensor eltwise_26_bias;   /* Tensor #77 */
AI_STATIC ai_tensor conv2d_27_weights;   /* Tensor #78 */
AI_STATIC ai_tensor conv2d_27_bias;   /* Tensor #79 */
AI_STATIC ai_tensor eltwise_29_scale;   /* Tensor #80 */
AI_STATIC ai_tensor eltwise_29_bias;   /* Tensor #81 */
AI_STATIC ai_tensor conv2d_30_weights;   /* Tensor #82 */
AI_STATIC ai_tensor conv2d_30_bias;   /* Tensor #83 */
AI_STATIC ai_tensor eltwise_32_scale;   /* Tensor #84 */
AI_STATIC ai_tensor eltwise_32_bias;   /* Tensor #85 */
AI_STATIC ai_tensor conv2d_33_weights;   /* Tensor #86 */
AI_STATIC ai_tensor conv2d_33_bias;   /* Tensor #87 */
AI_STATIC ai_tensor eltwise_35_scale;   /* Tensor #88 */
AI_STATIC ai_tensor eltwise_35_bias;   /* Tensor #89 */
AI_STATIC ai_tensor conv2d_36_weights;   /* Tensor #90 */
AI_STATIC ai_tensor conv2d_36_bias;   /* Tensor #91 */
AI_STATIC ai_tensor eltwise_38_scale;   /* Tensor #92 */
AI_STATIC ai_tensor eltwise_38_bias;   /* Tensor #93 */
AI_STATIC ai_tensor conv2d_39_weights;   /* Tensor #94 */
AI_STATIC ai_tensor conv2d_39_bias;   /* Tensor #95 */
AI_STATIC ai_tensor eltwise_41_scale;   /* Tensor #96 */
AI_STATIC ai_tensor eltwise_41_bias;   /* Tensor #97 */
AI_STATIC ai_tensor conv2d_42_weights;   /* Tensor #98 */
AI_STATIC ai_tensor conv2d_42_bias;   /* Tensor #99 */
AI_STATIC ai_tensor eltwise_44_scale;   /* Tensor #100 */
AI_STATIC ai_tensor eltwise_44_bias;   /* Tensor #101 */
AI_STATIC ai_tensor conv2d_45_weights;   /* Tensor #102 */
AI_STATIC ai_tensor conv2d_45_bias;   /* Tensor #103 */
AI_STATIC ai_tensor eltwise_47_scale;   /* Tensor #104 */
AI_STATIC ai_tensor eltwise_47_bias;   /* Tensor #105 */
AI_STATIC ai_tensor conv2d_48_weights;   /* Tensor #106 */
AI_STATIC ai_tensor conv2d_48_bias;   /* Tensor #107 */
AI_STATIC ai_tensor eltwise_50_scale;   /* Tensor #108 */
AI_STATIC ai_tensor eltwise_50_bias;   /* Tensor #109 */
AI_STATIC ai_tensor conv2d_51_weights;   /* Tensor #110 */
AI_STATIC ai_tensor conv2d_51_bias;   /* Tensor #111 */
AI_STATIC ai_tensor eltwise_53_scale;   /* Tensor #112 */
AI_STATIC ai_tensor eltwise_53_bias;   /* Tensor #113 */
AI_STATIC ai_tensor dense_55_weights;   /* Tensor #114 */
AI_STATIC ai_tensor dense_55_bias;   /* Tensor #115 */
AI_STATIC ai_tensor conv2d_0_scratch0;   /* Tensor #116 */
AI_STATIC ai_tensor eltwise_2_scratch0;   /* Tensor #117 */
AI_STATIC ai_tensor conv2d_3_scratch0;   /* Tensor #118 */
AI_STATIC ai_tensor eltwise_5_scratch0;   /* Tensor #119 */
AI_STATIC ai_tensor conv2d_6_scratch0;   /* Tensor #120 */
AI_STATIC ai_tensor eltwise_8_scratch0;   /* Tensor #121 */
AI_STATIC ai_tensor conv2d_9_scratch0;   /* Tensor #122 */
AI_STATIC ai_tensor eltwise_11_scratch0;   /* Tensor #123 */
AI_STATIC ai_tensor conv2d_12_scratch0;   /* Tensor #124 */
AI_STATIC ai_tensor eltwise_14_scratch0;   /* Tensor #125 */
AI_STATIC ai_tensor conv2d_15_scratch0;   /* Tensor #126 */
AI_STATIC ai_tensor eltwise_17_scratch0;   /* Tensor #127 */
AI_STATIC ai_tensor conv2d_18_scratch0;   /* Tensor #128 */
AI_STATIC ai_tensor eltwise_20_scratch0;   /* Tensor #129 */
AI_STATIC ai_tensor conv2d_21_scratch0;   /* Tensor #130 */
AI_STATIC ai_tensor eltwise_23_scratch0;   /* Tensor #131 */
AI_STATIC ai_tensor conv2d_24_scratch0;   /* Tensor #132 */
AI_STATIC ai_tensor eltwise_26_scratch0;   /* Tensor #133 */
AI_STATIC ai_tensor conv2d_27_scratch0;   /* Tensor #134 */
AI_STATIC ai_tensor eltwise_29_scratch0;   /* Tensor #135 */
AI_STATIC ai_tensor conv2d_30_scratch0;   /* Tensor #136 */
AI_STATIC ai_tensor eltwise_32_scratch0;   /* Tensor #137 */
AI_STATIC ai_tensor conv2d_33_scratch0;   /* Tensor #138 */
AI_STATIC ai_tensor eltwise_35_scratch0;   /* Tensor #139 */
AI_STATIC ai_tensor conv2d_36_scratch0;   /* Tensor #140 */
AI_STATIC ai_tensor eltwise_38_scratch0;   /* Tensor #141 */
AI_STATIC ai_tensor conv2d_39_scratch0;   /* Tensor #142 */
AI_STATIC ai_tensor eltwise_41_scratch0;   /* Tensor #143 */
AI_STATIC ai_tensor conv2d_42_scratch0;   /* Tensor #144 */
AI_STATIC ai_tensor eltwise_44_scratch0;   /* Tensor #145 */
AI_STATIC ai_tensor conv2d_45_scratch0;   /* Tensor #146 */
AI_STATIC ai_tensor eltwise_47_scratch0;   /* Tensor #147 */
AI_STATIC ai_tensor conv2d_48_scratch0;   /* Tensor #148 */
AI_STATIC ai_tensor eltwise_50_scratch0;   /* Tensor #149 */
AI_STATIC ai_tensor conv2d_51_scratch0;   /* Tensor #150 */
AI_STATIC ai_tensor eltwise_53_scratch0;   /* Tensor #151 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conv2d_0_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain eltwise_2_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain conv2d_3_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain eltwise_5_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain conv2d_6_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain eltwise_8_chain;   /* Chain #5 */
AI_STATIC_CONST ai_tensor_chain conv2d_9_chain;   /* Chain #6 */
AI_STATIC_CONST ai_tensor_chain eltwise_11_chain;   /* Chain #7 */
AI_STATIC_CONST ai_tensor_chain conv2d_12_chain;   /* Chain #8 */
AI_STATIC_CONST ai_tensor_chain eltwise_14_chain;   /* Chain #9 */
AI_STATIC_CONST ai_tensor_chain conv2d_15_chain;   /* Chain #10 */
AI_STATIC_CONST ai_tensor_chain eltwise_17_chain;   /* Chain #11 */
AI_STATIC_CONST ai_tensor_chain conv2d_18_chain;   /* Chain #12 */
AI_STATIC_CONST ai_tensor_chain eltwise_20_chain;   /* Chain #13 */
AI_STATIC_CONST ai_tensor_chain conv2d_21_chain;   /* Chain #14 */
AI_STATIC_CONST ai_tensor_chain eltwise_23_chain;   /* Chain #15 */
AI_STATIC_CONST ai_tensor_chain conv2d_24_chain;   /* Chain #16 */
AI_STATIC_CONST ai_tensor_chain eltwise_26_chain;   /* Chain #17 */
AI_STATIC_CONST ai_tensor_chain conv2d_27_chain;   /* Chain #18 */
AI_STATIC_CONST ai_tensor_chain eltwise_29_chain;   /* Chain #19 */
AI_STATIC_CONST ai_tensor_chain conv2d_30_chain;   /* Chain #20 */
AI_STATIC_CONST ai_tensor_chain eltwise_32_chain;   /* Chain #21 */
AI_STATIC_CONST ai_tensor_chain conv2d_33_chain;   /* Chain #22 */
AI_STATIC_CONST ai_tensor_chain eltwise_35_chain;   /* Chain #23 */
AI_STATIC_CONST ai_tensor_chain conv2d_36_chain;   /* Chain #24 */
AI_STATIC_CONST ai_tensor_chain eltwise_38_chain;   /* Chain #25 */
AI_STATIC_CONST ai_tensor_chain conv2d_39_chain;   /* Chain #26 */
AI_STATIC_CONST ai_tensor_chain eltwise_41_chain;   /* Chain #27 */
AI_STATIC_CONST ai_tensor_chain conv2d_42_chain;   /* Chain #28 */
AI_STATIC_CONST ai_tensor_chain eltwise_44_chain;   /* Chain #29 */
AI_STATIC_CONST ai_tensor_chain conv2d_45_chain;   /* Chain #30 */
AI_STATIC_CONST ai_tensor_chain eltwise_47_chain;   /* Chain #31 */
AI_STATIC_CONST ai_tensor_chain conv2d_48_chain;   /* Chain #32 */
AI_STATIC_CONST ai_tensor_chain eltwise_50_chain;   /* Chain #33 */
AI_STATIC_CONST ai_tensor_chain conv2d_51_chain;   /* Chain #34 */
AI_STATIC_CONST ai_tensor_chain eltwise_53_chain;   /* Chain #35 */
AI_STATIC_CONST ai_tensor_chain dense_55_chain;   /* Chain #36 */
AI_STATIC_CONST ai_tensor_chain dense_55_fmt_chain;   /* Chain #37 */
AI_STATIC_CONST ai_tensor_chain nl_56_chain;   /* Chain #38 */
AI_STATIC_CONST ai_tensor_chain nl_56_fmt_chain;   /* Chain #39 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_conv2d conv2d_0_layer; /* Layer #0 */
AI_STATIC ai_layer_bn eltwise_2_layer; /* Layer #1 */
AI_STATIC ai_layer_conv2d conv2d_3_layer; /* Layer #2 */
AI_STATIC ai_layer_bn eltwise_5_layer; /* Layer #3 */
AI_STATIC ai_layer_conv2d conv2d_6_layer; /* Layer #4 */
AI_STATIC ai_layer_bn eltwise_8_layer; /* Layer #5 */
AI_STATIC ai_layer_conv2d conv2d_9_layer; /* Layer #6 */
AI_STATIC ai_layer_bn eltwise_11_layer; /* Layer #7 */
AI_STATIC ai_layer_conv2d conv2d_12_layer; /* Layer #8 */
AI_STATIC ai_layer_bn eltwise_14_layer; /* Layer #9 */
AI_STATIC ai_layer_conv2d conv2d_15_layer; /* Layer #10 */
AI_STATIC ai_layer_bn eltwise_17_layer; /* Layer #11 */
AI_STATIC ai_layer_conv2d conv2d_18_layer; /* Layer #12 */
AI_STATIC ai_layer_bn eltwise_20_layer; /* Layer #13 */
AI_STATIC ai_layer_conv2d conv2d_21_layer; /* Layer #14 */
AI_STATIC ai_layer_bn eltwise_23_layer; /* Layer #15 */
AI_STATIC ai_layer_conv2d conv2d_24_layer; /* Layer #16 */
AI_STATIC ai_layer_bn eltwise_26_layer; /* Layer #17 */
AI_STATIC ai_layer_conv2d conv2d_27_layer; /* Layer #18 */
AI_STATIC ai_layer_bn eltwise_29_layer; /* Layer #19 */
AI_STATIC ai_layer_conv2d conv2d_30_layer; /* Layer #20 */
AI_STATIC ai_layer_bn eltwise_32_layer; /* Layer #21 */
AI_STATIC ai_layer_conv2d conv2d_33_layer; /* Layer #22 */
AI_STATIC ai_layer_bn eltwise_35_layer; /* Layer #23 */
AI_STATIC ai_layer_conv2d conv2d_36_layer; /* Layer #24 */
AI_STATIC ai_layer_bn eltwise_38_layer; /* Layer #25 */
AI_STATIC ai_layer_conv2d conv2d_39_layer; /* Layer #26 */
AI_STATIC ai_layer_bn eltwise_41_layer; /* Layer #27 */
AI_STATIC ai_layer_conv2d conv2d_42_layer; /* Layer #28 */
AI_STATIC ai_layer_bn eltwise_44_layer; /* Layer #29 */
AI_STATIC ai_layer_conv2d conv2d_45_layer; /* Layer #30 */
AI_STATIC ai_layer_bn eltwise_47_layer; /* Layer #31 */
AI_STATIC ai_layer_conv2d conv2d_48_layer; /* Layer #32 */
AI_STATIC ai_layer_bn eltwise_50_layer; /* Layer #33 */
AI_STATIC ai_layer_conv2d conv2d_51_layer; /* Layer #34 */
AI_STATIC ai_layer_bn eltwise_53_layer; /* Layer #35 */
AI_STATIC ai_layer_dense dense_55_layer; /* Layer #36 */
AI_STATIC ai_layer_nl dense_55_fmt_layer; /* Layer #37 */
AI_STATIC ai_layer_nl nl_56_layer; /* Layer #38 */
AI_STATIC ai_layer_nl nl_56_fmt_layer; /* Layer #39 */




/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  serving_default_conv2d_input0_int8_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 3072, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_2_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_5_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_8_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_11_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_14_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_17_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_20_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_23_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 23552, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_26_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 23552, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 23552, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_29_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 23552, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 23552, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_32_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 23552, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 23552, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_35_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 23552, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 23552, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_38_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 23552, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 23552, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_41_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 23552, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_44_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_47_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_50_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_51_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_53_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  dense_55_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 20, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  dense_55_fmt_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 20, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  nl_56_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 20, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  nl_56_fmt_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 20, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_2_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_2_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 288, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_5_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_5_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_8_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_8_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 288, AI_STATIC)

/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_11_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_11_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_14_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_14_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 288, AI_STATIC)

/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_17_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_17_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#67 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_20_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#68 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_20_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#69 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 288, AI_STATIC)

/* Array#70 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#71 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_23_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#72 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_23_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#73 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 26496, AI_STATIC)

/* Array#74 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 92, AI_STATIC)

/* Array#75 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_26_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 92, AI_STATIC)

/* Array#76 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_26_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 92, AI_STATIC)

/* Array#77 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 92, AI_STATIC)

/* Array#78 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 92, AI_STATIC)

/* Array#79 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_29_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 92, AI_STATIC)

/* Array#80 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_29_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 92, AI_STATIC)

/* Array#81 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8464, AI_STATIC)

/* Array#82 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 92, AI_STATIC)

/* Array#83 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_32_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 92, AI_STATIC)

/* Array#84 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_32_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 92, AI_STATIC)

/* Array#85 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 828, AI_STATIC)

/* Array#86 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 92, AI_STATIC)

/* Array#87 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_35_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 92, AI_STATIC)

/* Array#88 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_35_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 92, AI_STATIC)

/* Array#89 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8464, AI_STATIC)

/* Array#90 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 92, AI_STATIC)

/* Array#91 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_38_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 92, AI_STATIC)

/* Array#92 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_38_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 92, AI_STATIC)

/* Array#93 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 828, AI_STATIC)

/* Array#94 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 92, AI_STATIC)

/* Array#95 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_41_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 92, AI_STATIC)

/* Array#96 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_41_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 92, AI_STATIC)

/* Array#97 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 105984, AI_STATIC)

/* Array#98 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#99 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_44_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#100 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_44_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#101 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#102 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#103 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_47_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#104 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_47_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#105 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 147456, AI_STATIC)

/* Array#106 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#107 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_50_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#108 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_50_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#109 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_51_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 147456, AI_STATIC)

/* Array#110 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_51_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#111 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_53_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#112 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_53_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#113 */
AI_ARRAY_OBJ_DECLARE(
  dense_55_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10240, AI_STATIC)

/* Array#114 */
AI_ARRAY_OBJ_DECLARE(
  dense_55_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 20, AI_STATIC)

/* Array#115 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2284, AI_STATIC)

/* Array#116 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_2_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 320, AI_STATIC)

/* Array#117 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1185, AI_STATIC)

/* Array#118 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_5_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 320, AI_STATIC)

/* Array#119 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 448, AI_STATIC)

/* Array#120 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_8_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 320, AI_STATIC)

/* Array#121 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1185, AI_STATIC)

/* Array#122 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_11_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 320, AI_STATIC)

/* Array#123 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 448, AI_STATIC)

/* Array#124 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_14_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 320, AI_STATIC)

/* Array#125 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1185, AI_STATIC)

/* Array#126 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_17_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 320, AI_STATIC)

/* Array#127 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 448, AI_STATIC)

/* Array#128 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_20_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 320, AI_STATIC)

/* Array#129 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1185, AI_STATIC)

/* Array#130 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_23_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 320, AI_STATIC)

/* Array#131 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7560, AI_STATIC)

/* Array#132 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_26_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 920, AI_STATIC)

/* Array#133 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1197, AI_STATIC)

/* Array#134 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_29_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 920, AI_STATIC)

/* Array#135 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1288, AI_STATIC)

/* Array#136 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_32_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 920, AI_STATIC)

/* Array#137 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3405, AI_STATIC)

/* Array#138 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_35_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 920, AI_STATIC)

/* Array#139 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1288, AI_STATIC)

/* Array#140 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_38_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 920, AI_STATIC)

/* Array#141 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3405, AI_STATIC)

/* Array#142 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_41_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 920, AI_STATIC)

/* Array#143 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10224, AI_STATIC)

/* Array#144 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_44_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 1280, AI_STATIC)

/* Array#145 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1665, AI_STATIC)

/* Array#146 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_47_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 1280, AI_STATIC)

/* Array#147 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 11520, AI_STATIC)

/* Array#148 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_50_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 1280, AI_STATIC)

/* Array#149 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_51_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 11520, AI_STATIC)

/* Array#150 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_53_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 1280, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(serving_default_conv2d_input0_int8_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012728232890367508f),
    AI_PACK_INTQ_ZP(-95)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_0_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.5468504428863525f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_2_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06424694508314133f),
    AI_PACK_INTQ_ZP(-93)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.4181951880455017f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_5_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07163206487894058f),
    AI_PACK_INTQ_ZP(-83)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.13061587512493134f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_8_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06778375059366226f),
    AI_PACK_INTQ_ZP(-77)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16809263825416565f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_11_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1021173968911171f),
    AI_PACK_INTQ_ZP(-72)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1233009397983551f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_14_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05389464646577835f),
    AI_PACK_INTQ_ZP(-88)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09184373170137405f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_17_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12957090139389038f),
    AI_PACK_INTQ_ZP(-112)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11554400622844696f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_20_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0660245269536972f),
    AI_PACK_INTQ_ZP(-102)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05590274557471275f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_23_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07862305641174316f),
    AI_PACK_INTQ_ZP(-101)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12331835925579071f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_26_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06578299403190613f),
    AI_PACK_INTQ_ZP(-105)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.019455982372164726f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_29_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07933364808559418f),
    AI_PACK_INTQ_ZP(-44)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07896443456411362f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_32_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05105430260300636f),
    AI_PACK_INTQ_ZP(-97)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04716815426945686f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_35_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07972921431064606f),
    AI_PACK_INTQ_ZP(-111)))

/* Int quant #25 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1317289173603058f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #26 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_38_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.062229450792074203f),
    AI_PACK_INTQ_ZP(-111)))

/* Int quant #27 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05299985036253929f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #28 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_41_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10187515616416931f),
    AI_PACK_INTQ_ZP(-106)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_42_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16223104298114777f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #30 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_44_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04996199905872345f),
    AI_PACK_INTQ_ZP(-109)))

/* Int quant #31 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_45_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.018038930371403694f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #32 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_47_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10697348415851593f),
    AI_PACK_INTQ_ZP(-54)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_48_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09805776923894882f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #34 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_50_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05469798296689987f),
    AI_PACK_INTQ_ZP(-113)))

/* Int quant #35 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_51_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09201718121767044f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #36 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_53_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03419242799282074f),
    AI_PACK_INTQ_ZP(-110)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_55_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.18389765918254852f),
    AI_PACK_INTQ_ZP(-38)))

/* Int quant #38 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_56_fmt_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #39 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_0_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0033905089367181063f, 0.009390008635818958f, 0.0039944821037352085f, 0.020675627514719963f, 0.015036076307296753f, 0.005591782741248608f, 0.018712064251303673f, 0.007578135468065739f, 0.005959856323897839f, 0.01823204569518566f, 0.008276563137769699f, 0.009653453715145588f, 0.012174537405371666f, 0.009052525274455547f, 0.008839825168251991f, 0.010664275847375393f, 0.01606115885078907f, 0.009309514425694942f, 0.012172402814030647f, 0.01338390912860632f, 0.007547582965344191f, 0.014366639778017998f, 0.01686379685997963f, 0.020184209570288658f, 0.007733092177659273f, 0.014990202151238918f, 0.0060983579605817795f, 0.007064110599458218f, 0.01130148209631443f, 0.006571369711309671f, 0.009459172375500202f, 0.010342896915972233f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #40 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_0_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(4.315518890507519e-05f, 0.00011951821943512186f, 5.084270014776848e-05f, 0.0002631641982588917f, 0.00019138268544338644f, 7.117351196939126e-05f, 0.0002381715166848153f, 9.645627142162994e-05f, 7.585844286950305e-05f, 0.00023206172045320272f, 0.00010534602188272402f, 0.00012287140998523682f, 0.00015496034757234156f, 0.00011522264685481787f, 0.00011251535033807158f, 0.00013573738397099078f, 0.0002044301654677838f, 0.00011849367001559585f, 0.0001549331791466102f, 0.0001703535090200603f, 9.606739331502467e-05f, 0.00018286194244865328f, 0.00021464633755385876f, 0.0002569093194324523f, 9.842860163189471e-05f, 0.00019079878984484822f, 7.762132008792832e-05f, 8.991364302346483e-05f, 0.00014384789392352104f, 8.364192763110623e-05f, 0.00012039855209877715f, 0.00013164679694455117f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #41 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_2_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.22698110342025757f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #42 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_2_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01770935021340847f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #43 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006490656174719334f, 0.01267461571842432f, 0.004101697821170092f, 0.022268030792474747f, 0.01180237252265215f, 0.006908611860126257f, 0.017141465097665787f, 0.015070758759975433f, 0.009946691803634167f, 0.016375835984945297f, 0.011478404514491558f, 0.0037091083358973265f, 0.01016034185886383f, 0.015052087604999542f, 0.011524088680744171f, 0.012172378599643707f, 0.009772252291440964f, 0.004399011842906475f, 0.01559152640402317f, 0.009141571819782257f, 0.004620122257620096f, 0.01074480451643467f, 0.01179429329931736f, 0.012737534940242767f, 0.006100663915276527f, 0.0055466596968472f, 0.003773956559598446f, 0.00923022348433733f, 0.012623896822333336f, 0.005040590185672045f, 0.010166133753955364f, 0.010634557344019413f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #44 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00041700483416207135f, 0.0008143053273670375f, 0.00026352156419306993f, 0.0014306529192253947f, 0.0007582663674838841f, 0.00044385719229467213f, 0.0011012867325916886f, 0.0009682502131909132f, 0.0006390445632860065f, 0.0010520974174141884f, 0.0007374524138867855f, 0.00023829887504689395f, 0.0006527709192596376f, 0.0009670506697148085f, 0.0007403874769806862f, 0.0007820381433703005f, 0.0006278373766690493f, 0.00028262307750992477f, 0.0010017079766839743f, 0.0005873180343769491f, 0.00029682874446734786f, 0.0006903208559378982f, 0.0007577473297715187f, 0.000818347733002156f, 0.0003919490263797343f, 0.0003563559439498931f, 0.00024246517568826675f, 0.0005930136539973319f, 0.0008110468043014407f, 0.0003238425124436617f, 0.0006531430408358574f, 0.000683237798511982f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #45 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_5_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2368365377187729f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #46 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_5_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0253536868840456f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #47 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0052610780112445354f, 0.009981791488826275f, 0.005858345422893763f, 0.005260857287794352f, 0.0065251789055764675f, 0.007312305271625519f, 0.008315127342939377f, 0.006020207889378071f, 0.009685355238616467f, 0.00564116844907403f, 0.011593718081712723f, 0.00674758106470108f, 0.016174327582120895f, 0.006152145564556122f, 0.005393350962549448f, 0.009472696110606194f, 0.0064007192850112915f, 0.004415431991219521f, 0.014889821410179138f, 0.005266329739242792f, 0.0053366441279649734f, 0.005591060966253281f, 0.006403522100299597f, 0.007909187115728855f, 0.005888947751373053f, 0.01118114311248064f, 0.007587068248540163f, 0.005290903151035309f, 0.010952763259410858f, 0.0040030707605183125f, 0.008180450648069382f, 0.005027547013014555f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #48 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0003768618917092681f, 0.0007150163291953504f, 0.0004196453664917499f, 0.00037684605922549963f, 0.0004674120282288641f, 0.0005237955483607948f, 0.0005956297391094267f, 0.0004312399250920862f, 0.0006937819998711348f, 0.00040408855420537293f, 0.000830481993034482f, 0.00048334317398257554f, 0.001158600440248847f, 0.0004406908992677927f, 0.0003863368765451014f, 0.0006785487639717758f, 0.0004584967391565442f, 0.00031628651777282357f, 0.0010665886802598834f, 0.00037723808782175183f, 0.0003822748258244246f, 0.0004004992370028049f, 0.00045869749737903476f, 0.0005665514036081731f, 0.0004218374961055815f, 0.0008009283919818699f, 0.0005434773629531264f, 0.00037899831659160554f, 0.000784569070674479f, 0.00028674822533503175f, 0.0005859825760126114f, 0.00036013356293551624f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #49 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_8_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.024222232401371002f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #50 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_8_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02730637416243553f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #51 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007528179790824652f, 0.007568398490548134f, 0.005922405049204826f, 0.005034937057644129f, 0.008462835103273392f, 0.00657421350479126f, 0.009944702498614788f, 0.005985294468700886f, 0.007476236205548048f, 0.004694903735071421f, 0.010462443344295025f, 0.007021147757768631f, 0.015828201547265053f, 0.005809325724840164f, 0.004769282415509224f, 0.013459981419146061f, 0.00608781399205327f, 0.012185255065560341f, 0.010560399852693081f, 0.0048137535341084f, 0.0062757148407399654f, 0.007843626663088799f, 0.009262573905289173f, 0.006294294726103544f, 0.009035424329340458f, 0.016153084114193916f, 0.00783209502696991f, 0.00523059256374836f, 0.00561790494248271f, 0.00418777484446764f, 0.008714129216969013f, 0.01087598130106926f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #52 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005102882860228419f, 0.0005130144418217242f, 0.00040144281229004264f, 0.000341286911861971f, 0.000573642726521939f, 0.0004456248425412923f, 0.0006740892422385514f, 0.00040570570854470134f, 0.0005067673046141863f, 0.0003182381915394217f, 0.0007091836305335164f, 0.0004759197181556374f, 0.0010728948982432485f, 0.00039377788198180497f, 0.00032327984808944166f, 0.0009123680065385997f, 0.0004126548592466861f, 0.0008259622845798731f, 0.0007158234948292375f, 0.00032629427732899785f, 0.0004253914812579751f, 0.0005316704045981169f, 0.0006278519867919385f, 0.00042665089131332934f, 0.0006124549545347691f, 0.0010949166025966406f, 0.0005308887921273708f, 0.0003545491781551391f, 0.00038080266676843166f, 0.00028386307531036437f, 0.0005906763835810125f, 0.0007372148102149367f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #53 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_11_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.18424300849437714f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #54 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_11_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04490262269973755f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #55 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007573698181658983f, 0.006928417831659317f, 0.008471949957311153f, 0.004490585997700691f, 0.005271549336612225f, 0.008654695935547352f, 0.00832618772983551f, 0.0076703401282429695f, 0.006100369151681662f, 0.0059614949859678745f, 0.004586626775562763f, 0.005089147016406059f, 0.005502225365489721f, 0.005537636578083038f, 0.005729500204324722f, 0.00985738355666399f, 0.00563780078664422f, 0.005265163257718086f, 0.00547316949814558f, 0.0044884756207466125f, 0.005309779662638903f, 0.005212399642914534f, 0.004316875245422125f, 0.005900934804230928f, 0.009202766232192516f, 0.007889894768595695f, 0.004565111361443996f, 0.00606859615072608f, 0.012480340898036957f, 0.009627165272831917f, 0.005638398230075836f, 0.004290411248803139f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #56 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0007734063547104597f, 0.0007075119647197425f, 0.0008651334792375565f, 0.0004585669666994363f, 0.0005383169045671821f, 0.0008837950299493968f, 0.0008502486161887646f, 0.0007832751725800335f, 0.0006229538121260703f, 0.0006087723304517567f, 0.00046837437548674643f, 0.0005196904530748725f, 0.0005618729046545923f, 0.0005654890555888414f, 0.0005850816378369927f, 0.0010066103423014283f, 0.0005757175385951996f, 0.0005376647459343076f, 0.0005589058273471892f, 0.0004583514528349042f, 0.0005422208923846483f, 0.0005322766955941916f, 0.0004408280656207353f, 0.0006025881157256663f, 0.0009397625108249485f, 0.000805695541203022f, 0.00046617729822173715f, 0.0006197092588990927f, 0.0012744598789140582f, 0.0009831010829657316f, 0.0005757785402238369f, 0.0004381256294436753f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #57 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_14_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00914008915424347f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #58 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_14_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.016960443928837776f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #59 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.010732043534517288f, 0.00499946903437376f, 0.011245198547840118f, 0.0027548877988010645f, 0.005523158702999353f, 0.004852492827922106f, 0.006051967386156321f, 0.0054832035675644875f, 0.008471759967505932f, 0.006249085534363985f, 0.006066419649869204f, 0.005891891662031412f, 0.005902234930545092f, 0.004371695686131716f, 0.005722878035157919f, 0.010939644649624825f, 0.006162689998745918f, 0.006789794657379389f, 0.006020331755280495f, 0.005486166570335627f, 0.008305431343615055f, 0.005578898824751377f, 0.005120986141264439f, 0.004963679704815149f, 0.009621929377317429f, 0.009313555434346199f, 0.004218855407088995f, 0.003931599203497171f, 0.007186426315456629f, 0.01302429474890232f, 0.01066591963171959f, 0.00551570113748312f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #60 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005783996894024312f, 0.0002694446302484721f, 0.0006060560117475688f, 0.00014847370039205998f, 0.0002976686810143292f, 0.00026152338250540197f, 0.00032616863609291613f, 0.0002955153177026659f, 0.0004565825220197439f, 0.00033679226180538535f, 0.0003269475419074297f, 0.000317541416734457f, 0.0003180988715030253f, 0.0002356109907850623f, 0.0003084324998781085f, 0.000589588307775557f, 0.00033213599817827344f, 0.00036593357799574733f, 0.0003244636463932693f, 0.000295675010420382f, 0.00044761828030459583f, 0.00030067277839407325f, 0.00027599374880082905f, 0.00026751577388495207f, 0.0005185704794712365f, 0.0005019507952965796f, 0.00022737371909897774f, 0.00021189215476624668f, 0.0003873099049087614f, 0.0007019397453404963f, 0.0005748359835706651f, 0.0002972667571157217f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #61 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_17_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.016115669161081314f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #62 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_17_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.015887729823589325f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #63 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0069039869122207165f, 0.006313030607998371f, 0.004777568858116865f, 0.005699208937585354f, 0.00391842145472765f, 0.011267530731856823f, 0.0037259231321513653f, 0.007361053489148617f, 0.01369877252727747f, 0.005327049642801285f, 0.00541603984311223f, 0.006073589902371168f, 0.00789826363325119f, 0.005995525512844324f, 0.00409270916134119f, 0.0067540365271270275f, 0.005301536060869694f, 0.006061887368559837f, 0.008470071479678154f, 0.0061824731528759f, 0.0058228555135428905f, 0.0062598492950201035f, 0.008253048174083233f, 0.007251393049955368f, 0.006228294223546982f, 0.0054993899539113045f, 0.012449548579752445f, 0.0058232927694916725f, 0.014116575941443443f, 0.005704337731003761f, 0.008350237272679806f, 0.0067213429138064384f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #64 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0008945558220148087f, 0.0008179850410670042f, 0.0006190338754095137f, 0.000738451664801687f, 0.0005077134119346738f, 0.001459944061934948f, 0.0004827712255064398f, 0.0009537783334963024f, 0.001774962292984128f, 0.0006902306340634823f, 0.0007017611642368138f, 0.0007869605324231088f, 0.0010233850916847587f, 0.0007768456707708538f, 0.0005302960053086281f, 0.0008751266286708415f, 0.0006869247881695628f, 0.000785444222856313f, 0.0010974748292937875f, 0.0008010686142370105f, 0.0007544726249761879f, 0.0008110943017527461f, 0.001069354941137135f, 0.0009395695524290204f, 0.0008070056792348623f, 0.0007125608972273767f, 0.0016130992444232106f, 0.0007545293192379177f, 0.0018290975131094456f, 0.0007391161634586751f, 0.0010819478193297982f, 0.000870890449732542f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #65 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_20_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011066390201449394f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #66 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_20_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.013259674422442913f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #67 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005320155527442694f, 0.005591893568634987f, 0.006042610388249159f, 0.005401557311415672f, 0.0057169124484062195f, 0.0047307685017585754f, 0.005354822613298893f, 0.006660407409071922f, 0.005806471221148968f, 0.007471001241356134f, 0.003954845014959574f, 0.002831706777215004f, 0.005054133012890816f, 0.00512022664770484f, 0.0035154479555785656f, 0.008159053511917591f, 0.005529948975890875f, 0.0024113678373396397f, 0.007172112353146076f, 0.004518075380474329f, 0.0052697728388011456f, 0.006283723283559084f, 0.003897502552717924f, 0.005628231912851334f, 0.0050600008107721806f, 0.003075090702623129f, 0.00782355573028326f, 0.006777481641620398f, 0.0036036837846040726f, 0.003050322877243161f, 0.003831092966720462f, 0.004944679327309132f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #68 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0003512607654556632f, 0.0003692021418828517f, 0.0003989604883827269f, 0.0003566352534107864f, 0.0003774564538616687f, 0.000312346761347726f, 0.000353549636201933f, 0.0004397502343636006f, 0.00038336950819939375f, 0.0004932692972943187f, 0.00026111677289009094f, 0.00018696210463531315f, 0.0003336967492941767f, 0.0003380605485290289f, 0.00023210578365251422f, 0.0005386976408772171f, 0.0003651122679002583f, 0.0001592094195075333f, 0.00047353532863780856f, 0.00029830378480255604f, 0.00034793425584211946f, 0.0004148798470851034f, 0.0002573307720012963f, 0.000371601345250383f, 0.0003340841503813863f, 0.00020303140627220273f, 0.0005165465408936143f, 0.0004474800080060959f, 0.00023793151194695383f, 0.00020139612024649978f, 0.0002529461053200066f, 0.00032647012267261744f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #69 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_23_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.013221624307334423f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #70 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_23_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.016681436449289322f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #71 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 92,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002299993997439742f, 0.002860586391761899f, 0.0025105178356170654f, 0.0025579023640602827f, 0.0015255928738042712f, 0.002331537427380681f, 0.0028669112361967564f, 0.002888023154810071f, 0.0024094651453197002f, 0.000815212435554713f, 0.0026804099325090647f, 0.0029659534338861704f, 0.002983229933306575f, 0.0025127939879894257f, 0.003850232344120741f, 0.0017295440193265676f, 0.0018236689502373338f, 0.003096689935773611f, 0.0020695358980447054f, 0.0025582897942513227f, 0.0033551210071891546f, 0.0006212799926288426f, 0.0025036558508872986f, 0.0025462789926677942f, 0.002653643721714616f, 0.0028046658262610435f, 0.0020456428173929453f, 0.002172568580135703f, 0.0029310528188943863f, 0.0027184223290532827f, 0.0012787148589268327f, 0.004677596036344767f, 0.002812383696436882f, 0.002946471096947789f, 0.002150863641873002f, 0.0005817735800519586f, 0.003168475814163685f, 0.003550996072590351f, 0.0033363522961735725f, 0.002646672772243619f, 0.0024681813083589077f, 0.002569019328802824f, 0.0014101428678259254f, 0.0023794721346348524f, 0.0023957956582307816f, 0.0015089011285454035f, 0.002563689835369587f, 0.002492567291483283f, 0.002676507458090782f, 0.000957562355324626f, 0.003122856607660651f, 0.0016817109426483512f, 0.0007599302916787565f, 0.002805474679917097f, 0.002970250090584159f, 0.0029650432989001274f, 0.0014523827703669667f, 0.0026461284141987562f, 0.0018906512996181846f, 0.0029281636234372854f, 0.0027566542848944664f, 0.001317610964179039f, 0.00218870397657156f, 0.0015600883634760976f, 0.0014769439585506916f, 0.002787613309919834f, 0.002326240297406912f, 0.0021277284249663353f, 0.0021564923226833344f, 0.0021716654300689697f, 0.0019162226235494018f, 0.0027942482847720385f, 0.0027025409508496523f, 0.0024668953847140074f, 0.002713932655751705f, 0.002099178731441498f, 0.0032824042718857527f, 0.001955344108864665f, 0.0027238542679697275f, 0.002915513003244996f, 0.0028739438857883215f, 0.0014600128633901477f, 0.002608148381114006f, 0.0007175677455961704f, 0.0019009418319910765f, 0.0007466544630005956f, 0.002741303062066436f, 0.0029098272789269686f, 0.0016698635881766677f, 0.002511915983632207f, 0.0030334850307554007f, 0.0006792540661990643f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #72 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 92,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001808325614547357f, 0.00022490804258268327f, 0.00019738457922358066f, 0.00020111010235268623f, 0.00011994677333859727f, 0.00018331260071136057f, 0.00022540532518178225f, 0.00022706520394422114f, 0.0001894395099952817f, 6.409449269995093e-05f, 0.00021074201504234225f, 0.00023319231695495546f, 0.00023455065093003213f, 0.00019756353867705911f, 0.0003027170314453542f, 0.00013598203076981008f, 0.00014338242181111127f, 0.0002434712223475799f, 0.0001627132442081347f, 0.0002011405595112592f, 0.00026378987240605056f, 4.884693044004962e-05f, 0.00019684508151840419f, 0.0002001962420763448f, 0.00020863757526967674f, 0.00022051139967516065f, 0.00016083469381555915f, 0.0001708139752736315f, 0.00023044833505991846f, 0.000213730672840029f, 0.00010053646838059649f, 0.0003677668864838779f, 0.00022111819998826832f, 0.00023166056780610234f, 0.00016910747217480093f, 4.57408168585971e-05f, 0.0002491152554284781f, 0.0002791901642922312f, 0.0002623142208904028f, 0.00020808950648643076f, 0.0001940559595823288f, 0.00020198414858896285f, 0.0001108697397285141f, 0.00018708137213252485f, 0.00018836477829609066f, 0.00011863441613968462f, 0.00020156512618996203f, 0.0001959732617251575f, 0.00021043520246166736f, 7.528647984145209e-05f, 0.0002455285284668207f, 0.00013222124835010618f, 5.974804298602976e-05f, 0.0002205749915447086f, 0.000233530139666982f, 0.00023312076518777758f, 0.00011419077054597437f, 0.00020804670930374414f, 0.0001486487890360877f, 0.00023022117966320366f, 0.0002167365892091766f, 0.00010359460429754108f, 0.0001720825966913253f, 0.00012265890836715698f, 0.00011612184607656673f, 0.0002191706735175103f, 0.00018289612489752471f, 0.00016728851187508553f, 0.0001695500104688108f, 0.0001707429764792323f, 0.00015065928164403886f, 0.00021969234512653202f, 0.00021248203120194376f, 0.0001939548528753221f, 0.0002133776870323345f, 0.0001650438498472795f, 0.0002580726577434689f, 0.00015373513451777399f, 0.0002141577424481511f, 0.00022922654170542955f, 0.0002259582543047145f, 0.0001147906732512638f, 0.00020506059809122235f, 5.641736788675189e-05f, 0.00014945786097086966f, 5.870425593457185e-05f, 0.0002155296242563054f, 0.00022877952142152935f, 0.00013128978025633842f, 0.00019749451894313097f, 0.00023850185971241444f, 5.3405030485009775e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #73 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_26_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03281195089221001f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #74 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_26_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011708623729646206f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #75 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 92,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0008754755253903568f, 0.002011400880292058f, 0.0018470825161784887f, 0.0018148310482501984f, 0.0008966277237050235f, 0.00156082259491086f, 0.0015449965139850974f, 0.0016262574354186654f, 0.0022382517345249653f, 0.002165438374504447f, 0.00230591231957078f, 0.0016199295641854405f, 0.0016493101138621569f, 0.0024882694706320763f, 0.0013793621910735965f, 0.0017945044673979282f, 0.0018690642900764942f, 0.0013969638384878635f, 0.0023114304058253765f, 0.0011598445707932115f, 0.0015577179146930575f, 4.2080271668965e-05f, 0.0012364084832370281f, 0.002573674777522683f, 0.002825669478625059f, 0.0023333558347076178f, 0.0019023081986233592f, 0.0024502172600477934f, 0.0015522199682891369f, 0.0012200967175886035f, 6.243343523237854e-05f, 0.0022815121337771416f, 0.0013310201466083527f, 0.0012160371989011765f, 0.0018666248070076108f, 0.00027639075415208936f, 0.001866391976363957f, 0.001857204595580697f, 0.0013957051560282707f, 0.0015594124561175704f, 0.0021837700624018908f, 0.0023600771091878414f, 0.0004395119904074818f, 0.0012935282429680228f, 0.00196006428450346f, 0.0018047126941382885f, 0.0009062731405720115f, 0.0013071366120129824f, 0.0011992583749815822f, 0.0014832003507763147f, 0.0009514751727692783f, 0.00018013498629443347f, 0.0007046929677017033f, 0.0018732952885329723f, 0.003472771728411317f, 0.0018250492867082357f, 0.00024444321752525866f, 0.0014181208098307252f, 0.0018118979642167687f, 0.001336073619313538f, 0.002736194059252739f, 4.45257501269225e-05f, 0.002041656756773591f, 0.00025593736791051924f, 0.001312298933044076f, 0.001249529654160142f, 0.0016999777872115374f, 0.0019526174291968346f, 0.0008303399663418531f, 0.0008621651795692742f, 0.0032342583872377872f, 0.001962479669600725f, 0.0013939141063019633f, 0.002170911291614175f, 0.0014838315546512604f, 0.0028788417112082243f, 0.0015102881006896496f, 0.001046063844114542f, 0.0019769114442169666f, 0.0008614831604063511f, 0.002987735904753208f, 0.003241828177124262f, 0.001224773470312357f, 3.080272290389985e-05f, 0.0035735606215894222f, 0.0020747254602611065f, 0.0025237416848540306f, 0.0008432372706010938f, 0.0006889504729770124f, 0.0015827853931114078f, 0.0024765701964497566f, 0.00028145595570094883f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #76 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 92,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.75914018554613e-05f, 0.00013231596676632762f, 0.00012150661495979875f, 0.00011938501847907901f, 5.898285598959774e-05f, 0.00010267558536725119f, 0.00010163449769606814f, 0.00010698008554754779f, 0.0001472388976253569f, 0.00014244901831261814f, 0.00015168981917668134f, 0.00010656381346052513f, 0.00010849655518541113f, 0.0001636858214624226f, 9.073857654584572e-05f, 0.00011804787936853245f, 0.00012295263877604157f, 9.189646516460925e-05f, 0.00015205281670205295f, 7.62980489525944e-05f, 0.00010247134923702106f, 2.7681662686518393e-06f, 8.133464871207252e-05f, 0.0001693040394457057f, 0.0001858809991972521f, 0.00015349512977991253f, 0.000125139529700391f, 0.0001611826301086694f, 0.00010210967593593523f, 8.026161231100559e-05f, 4.107058430236066e-06f, 0.0001500846992712468f, 8.75584883033298e-05f, 7.999457011464983e-05f, 0.00012279217480681837f, 1.8181810446549207e-05f, 0.0001227768516400829f, 0.00012217248149681836f, 9.181366476695985e-05f, 0.00010258281690767035f, 0.0001436549355275929f, 0.00015525294293183833f, 2.8912414563819766e-05f, 8.509216422680765e-05f, 0.00012893890379928052f, 0.0001187194066005759f, 5.961735951132141e-05f, 8.598736167186871e-05f, 7.88908073445782e-05f, 9.756936196936294e-05f, 6.259088695514947e-05f, 1.1849818292830605e-05f, 4.63568139821291e-05f, 0.00012323097325861454f, 0.00022844932391308248f, 0.00012005720782326534f, 1.6080206478363834e-05f, 9.32882321649231e-05f, 0.00011919207463506609f, 8.789091953076422e-05f, 0.00017999504052568227f, 2.929037236754084e-06f, 0.00013430629041977227f, 1.683632581261918e-05f, 8.63269524415955e-05f, 8.219780283980072e-05f, 0.00011182962771272287f, 0.00012844901357311755f, 5.462224726215936e-05f, 5.671580584021285e-05f, 0.00021275920153129846f, 0.00012909778160974383f, 9.169584518531337e-05f, 0.00014280904724728316f, 9.761088585946709e-05f, 0.0001893788285087794f, 9.935127309290692e-05f, 6.8813213147223e-05f, 0.0001300471485592425f, 5.66709422855638e-05f, 0.0001965422125067562f, 0.00021325716807041317f, 8.056926890276372e-05f, 2.0262953057681443e-06f, 0.00023507951118517667f, 0.00013648165622726083f, 0.00016601927927695215f, 5.547067121369764e-05f, 4.532122329692356e-05f, 0.00010412036499474198f, 0.00016291619976982474f, 1.851501474448014e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #77 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_29_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.24893225729465485f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #78 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_29_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05245525762438774f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #79 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 92,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003549671033397317f, 0.003921188414096832f, 0.0034940866753458977f, 0.003198644844815135f, 0.004786483012139797f, 0.003323415294289589f, 0.002909865463152528f, 0.0037838693242520094f, 0.004840805660933256f, 0.0039113848470151424f, 0.0027224484365433455f, 0.003157694125548005f, 0.004095412790775299f, 0.0034561639185994864f, 0.0035297132562845945f, 0.0021756025962531567f, 0.0038759398739784956f, 0.0030672885477542877f, 0.004483128897845745f, 0.005012717097997665f, 0.004006002098321915f, 0.003190449206158519f, 0.004231355153024197f, 0.005953998304903507f, 0.0038004517555236816f, 0.0030000428669154644f, 0.004279293119907379f, 0.004848278593271971f, 0.0029906299896538258f, 0.0025064826477319f, 0.00431208498775959f, 0.0032697010319679976f, 0.003986089490354061f, 0.002960948273539543f, 0.005050317849963903f, 0.002825584262609482f, 0.0037730576004832983f, 0.004029600415378809f, 0.004158510360866785f, 0.003721496555954218f, 0.0028194792103022337f, 0.004721054341644049f, 0.004126088693737984f, 0.003591476008296013f, 0.0030069199856370687f, 0.004046822898089886f, 0.003189337905496359f, 0.003221033839508891f, 0.0046258345246315f, 0.004270341247320175f, 0.003494871314615011f, 0.003550005378201604f, 0.004170339088886976f, 0.005438366439193487f, 0.006607262883335352f, 0.0030938745476305485f, 0.003888737875968218f, 0.004447104874998331f, 0.004026792943477631f, 0.003778760088607669f, 0.0055033257231116295f, 0.0036846704315394163f, 0.003281750250607729f, 0.003382096765562892f, 0.003328644437715411f, 0.0030963432509452105f, 0.0029931971803307533f, 0.003161835251376033f, 0.004020644351840019f, 0.004224345553666353f, 0.004156298935413361f, 0.0028063468635082245f, 0.005096405278891325f, 0.0034672548063099384f, 0.004798551090061665f, 0.0033532571978867054f, 0.004298245068639517f, 0.003184401895850897f, 0.004210073966532946f, 0.0031678027007728815f, 0.0038042606320232153f, 0.0036917757242918015f, 0.002944006584584713f, 0.003535392228513956f, 0.0051951780915260315f, 0.0027223883662372828f, 0.00364161329343915f, 0.003720585722476244f, 0.0035533267073333263f, 0.0031188991852104664f, 0.004517982713878155f, 0.00334347621537745f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #80 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 92,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002816083433572203f, 0.00031108217081055045f, 0.00027719864738173783f, 0.0002537601685617119f, 0.00037972917198203504f, 0.0002636586723383516f, 0.00023085024440661073f, 0.0003001881705131382f, 0.0003840387798845768f, 0.00031030442914925516f, 0.00021598176681436598f, 0.0002505113952793181f, 0.0003249040455557406f, 0.0002741900971159339f, 0.00028002503677271307f, 0.00017259849119000137f, 0.000307492446154356f, 0.00024333919282071292f, 0.0003556629817467183f, 0.0003976771258749068f, 0.0003178107726853341f, 0.0002531099889893085f, 0.0003356888482812792f, 0.0004723524034488946f, 0.000301503692753613f, 0.0002380043442826718f, 0.00033949193311855197f, 0.00038463162491098046f, 0.0002372575836488977f, 0.000198848414584063f, 0.000342093437211588f, 0.0002593973185867071f, 0.0003162310167681426f, 0.00023490282183047384f, 0.00040066015208140016f, 0.00022416390129365027f, 0.0002993304224219173f, 0.00031968290568329394f, 0.00032990978797897696f, 0.00029523990815505385f, 0.00022367956989910454f, 0.00037453847471624613f, 0.0003273376787547022f, 0.00028492489946074784f, 0.00023854992468841374f, 0.00032104921410791576f, 0.0002530218043830246f, 0.00025553637533448637f, 0.00036698434269055724f, 0.00033878174144774675f, 0.0002772609004750848f, 0.00028163488605059683f, 0.0003308482118882239f, 0.00043144545634277165f, 0.0005241782637313008f, 0.0002454483474139124f, 0.0003085077623836696f, 0.00035280504380352795f, 0.00031946017406880856f, 0.0002997828123625368f, 0.00043659890070557594f, 0.0002923183492384851f, 0.00026035323389805853f, 0.0002683140628505498f, 0.0002640735183376819f, 0.00024564421619288623f, 0.00023746125225443393f, 0.0002508399193175137f, 0.0003189723938703537f, 0.00033513273228891194f, 0.0003297343500889838f, 0.00022263774008024484f, 0.00040431643719784915f, 0.00027506996411830187f, 0.00038068657158873975f, 0.0002660261234268546f, 0.0003409954661037773f, 0.0002526302123442292f, 0.0003340005350764841f, 0.0002513133513275534f, 0.00030180587782524526f, 0.0002928820322267711f, 0.00023355877783615142f, 0.0002804755640681833f, 0.0004121524398215115f, 0.00021597699378617108f, 0.0002889024617616087f, 0.0002951676433440298f, 0.00028189836302772164f, 0.00024743363610468805f, 0.0003584280493669212f, 0.0002652501570992172f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #81 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_32_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.013220437802374363f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #82 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_32_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012405830435454845f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #83 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 92,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0031876140274107456f, 0.00453598378226161f, 0.004599971231073141f, 0.0028241188265383244f, 0.003797943936660886f, 0.00552308838814497f, 0.005532141774892807f, 0.005323928315192461f, 0.004665098153054714f, 0.00414454797282815f, 0.003324418095871806f, 0.005944041069597006f, 0.0057437424547970295f, 0.00498228007927537f, 0.003732943907380104f, 0.0036432635970413685f, 0.0039657591842114925f, 0.003027071710675955f, 0.004166566301137209f, 0.004331578500568867f, 0.0063454993069171906f, 0.003804074367508292f, 0.006548992823809385f, 0.006528246216475964f, 0.004089781548827887f, 0.00242383754812181f, 0.004556380212306976f, 0.005904670804738998f, 0.006266151554882526f, 0.0036008269526064396f, 0.006843338720500469f, 0.0035174803342670202f, 0.003100793110206723f, 0.002678373595699668f, 0.004857412539422512f, 0.004973129369318485f, 0.0053443084470927715f, 0.0076348972506821156f, 0.005338224116712809f, 0.005025974940508604f, 0.005256142932921648f, 0.0033827831503003836f, 0.004082018509507179f, 0.002732008695602417f, 0.004939910490065813f, 0.003983511123806238f, 0.005071426276117563f, 0.004442137666046619f, 0.005024381447583437f, 0.00303683802485466f, 0.002872144803404808f, 0.0048154559917747974f, 0.006049557123333216f, 0.004915911238640547f, 0.006767802406102419f, 0.003686953568831086f, 0.0028993431478738785f, 0.006109264213591814f, 0.005425986368209124f, 0.006135411094874144f, 0.007338270545005798f, 0.004322274122387171f, 0.003739620093256235f, 0.0052785673178732395f, 0.003645192598924041f, 0.005526193417608738f, 0.0037979912012815475f, 0.004134579561650753f, 0.0035908306017518044f, 0.002815110143274069f, 0.005396873690187931f, 0.002946010557934642f, 0.005035828333348036f, 0.007920568808913231f, 0.006198695860803127f, 0.004481879528611898f, 0.006964203901588917f, 0.005805349443107843f, 0.006219740957021713f, 0.004010507836937904f, 0.00505102938041091f, 0.004704898688942194f, 0.004622829146683216f, 0.005710358265787363f, 0.004046690184623003f, 0.002561717526987195f, 0.004421029705554247f, 0.0029088822193443775f, 0.005969448946416378f, 0.005061274394392967f, 0.007291268091648817f, 0.005172196310013533f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #84 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 92,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00016274141671601683f, 0.0002315814926987514f, 0.0002348483249079436f, 0.0001441834174329415f, 0.00019390137458685786f, 0.0002819774381350726f, 0.000282439636066556f, 0.00027180943288840353f, 0.00023817333567421883f, 0.00021159701282158494f, 0.00016972584126051515f, 0.000303468870697543f, 0.00029324277420528233f, 0.0002543668379075825f, 0.00019058285397477448f, 0.00018600428302306682f, 0.00020246907661203295f, 0.00015454503591172397f, 0.00021272113372106105f, 0.00022114571765996516f, 0.00032396503956988454f, 0.00019421435717958957f, 0.0003343542630318552f, 0.00033329505822621286f, 0.00020880094962194562f, 0.0001237473334185779f, 0.0002326228132005781f, 0.00030145884375087917f, 0.0003199139900971204f, 0.0001838377065723762f, 0.0003493818803690374f, 0.0001795825082808733f, 0.00015830883057788014f, 0.0001367424993077293f, 0.00024799181846901774f, 0.00025389966322109103f, 0.0002728499530348927f, 0.00038979435339570045f, 0.0002725392987485975f, 0.00025659764651209116f, 0.0002683487255126238f, 0.00017270563694182783f, 0.00020840461365878582f, 0.000139480791403912f, 0.0002522036957088858f, 0.00020337538444437087f, 0.000258918124018237f, 0.00022679024550598115f, 0.0002565163013059646f, 0.00015504364273510873f, 0.0001466353569412604f, 0.0002458497474435717f, 0.0003088559315074235f, 0.0002509784244466573f, 0.000345525419106707f, 0.00018823484424501657f, 0.00014802394434809685f, 0.00031190423760563135f, 0.0002770199498627335f, 0.00031323914299719036f, 0.0003746502916328609f, 0.00022067068493925035f, 0.0001909236889332533f, 0.0002694935828913003f, 0.0001861027703853324f, 0.00028213593759573996f, 0.00019390379020478576f, 0.00021108807413838804f, 0.00018332735635340214f, 0.00014372348960023373f, 0.0002755336172413081f, 0.00015040651487652212f, 0.0002571007062215358f, 0.00040437912684865296f, 0.00031647010473534465f, 0.00022881923359818757f, 0.00035555256181396544f, 0.000296388054266572f, 0.0003175445308443159f, 0.00020475368364714086f, 0.00025787678896449506f, 0.0002402053214609623f, 0.00023601531574968249f, 0.00029153836658224463f, 0.00020660094742197543f, 0.00013078670599497855f, 0.0002257125888718292f, 0.0001485109532950446f, 0.0003047660575248301f, 0.0002583998430054635f, 0.00037225059350021183f, 0.0002640628663357347f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #85 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_35_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.025364886969327927f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #86 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_35_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.010395235382020473f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #87 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 92,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004308933392167091f, 0.003653282765299082f, 0.003977410960942507f, 0.0038116546347737312f, 0.005245877895504236f, 0.004063009284436703f, 0.0036015850491821766f, 0.005089186131954193f, 0.0038821406196802855f, 0.0032490291632711887f, 0.0045786090195178986f, 0.0037036724388599396f, 0.0030325474217534065f, 0.003088558092713356f, 0.002864337293431163f, 0.005741175264120102f, 0.0035472919698804617f, 0.012308478355407715f, 0.004410847090184689f, 0.00425577349960804f, 0.0036991869565099478f, 0.0035653437953442335f, 0.004534746985882521f, 0.003477558959275484f, 0.006002727430313826f, 0.003969401586800814f, 0.003954524639993906f, 0.0041827005334198475f, 0.0025839039590209723f, 0.00416655233129859f, 0.0036425625439733267f, 0.0030142352916300297f, 0.004278525710105896f, 0.004475603345781565f, 0.00889777485281229f, 0.0047546266578137875f, 0.003911410924047232f, 0.004493262153118849f, 0.004226301331073046f, 0.0033972556702792645f, 0.003950430080294609f, 0.004186013713479042f, 0.003079031826928258f, 0.0033221652265638113f, 0.006790012586861849f, 0.0023999095428735018f, 0.004336359910666943f, 0.0037487095687538385f, 0.005412342958152294f, 0.004718586336821318f, 0.0037935085128992796f, 0.004558220040053129f, 0.0033104668837040663f, 0.004388622473925352f, 0.0037622854579240084f, 0.0036322136875241995f, 0.004184219054877758f, 0.004010727163404226f, 0.0028112868312746286f, 0.003877197625115514f, 0.0046583483926951885f, 0.004218725021928549f, 0.00391943845897913f, 0.0043824175372719765f, 0.0047887167893350124f, 0.004415606614202261f, 0.0038692087400704622f, 0.0035741827450692654f, 0.004449639469385147f, 0.004125082399696112f, 0.003919283393770456f, 0.004127776250243187f, 0.0034936729352921247f, 0.0035322553012520075f, 0.00394882308319211f, 0.004687837325036526f, 0.0037009352818131447f, 0.003466509748250246f, 0.0037999958731234074f, 0.004784862976521254f, 0.004377012141048908f, 0.006293328013271093f, 0.0036083771847188473f, 0.00433212099596858f, 0.004313667304813862f, 0.0035701191518455744f, 0.003504855092614889f, 0.0036229677498340607f, 0.003958495799452066f, 0.0034880887251347303f, 0.0049367803148925304f, 0.0063252500258386135f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #88 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 92,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00034354787203483284f, 0.0002912733762059361f, 0.00031711586052551866f, 0.0003039002185687423f, 0.0004182497214060277f, 0.00032394053414463997f, 0.00028715154621750116f, 0.00040575681487098336f, 0.00030952002271078527f, 0.00025904254289343953f, 0.000365048908861354f, 0.00029529089806601405f, 0.0002417826181044802f, 0.00024624832440167665f, 0.0002283713547512889f, 0.0004577393992803991f, 0.0002828227879945189f, 0.0009813453070819378f, 0.0003516733704600483f, 0.0003393094812054187f, 0.0002949332701973617f, 0.00028426205972209573f, 0.00036155182169750333f, 0.0002772630541585386f, 0.00047859273036010563f, 0.000316477264277637f, 0.0003152911376673728f, 0.00033348341821692884f, 0.0002060126280412078f, 0.0003321959520690143f, 0.0002904186549130827f, 0.00024032260989770293f, 0.00034112349385395646f, 0.00035683633177541196f, 0.00070941261947155f, 0.00037908265949226916f, 0.00031185371335595846f, 0.0003582442586775869f, 0.00033695969614200294f, 0.0002708605316001922f, 0.00031496468000113964f, 0.0003337475936859846f, 0.0002454888017382473f, 0.00026487361174076796f, 0.0005413623875938356f, 0.00019134290050715208f, 0.00034573455923236907f, 0.00029888167046010494f, 0.0004315218538977206f, 0.0003762091801036149f, 0.00030245346715673804f, 0.00036342331441119313f, 0.000263940921286121f, 0.00034990141284652054f, 0.0002999640710186213f, 0.00028959353221580386f, 0.00033360449015162885f, 0.0003197721380274743f, 0.00022414169507101178f, 0.00030912592774257064f, 0.00037140646600164473f, 0.000336355617037043f, 0.0003124937356915325f, 0.000349406705936417f, 0.00038180063711479306f, 0.00035205285530537367f, 0.00030848896130919456f, 0.0002849667798727751f, 0.00035476626362651587f, 0.0003288895823061466f, 0.00031248139566741884f, 0.0003291043685749173f, 0.0002785477845463902f, 0.0002816239430103451f, 0.0003148365649394691f, 0.0003737575898412615f, 0.000295072648441419f, 0.0002763821103144437f, 0.00030297067132778466f, 0.00038149335887283087f, 0.00034897573641501367f, 0.0005017620860598981f, 0.0002876930811908096f, 0.0003453966055531055f, 0.00034392529050819576f, 0.0002846427960321307f, 0.00027943935128860176f, 0.00028885636129416525f, 0.00031560775823891163f, 0.0002781025832518935f, 0.00039360561640933156f, 0.0005043072160333395f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #89 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_38_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008214127272367477f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #90 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_38_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008397416211664677f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #91 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 92,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003601131495088339f, 0.0030884165316820145f, 0.002650130307301879f, 0.002660902449861169f, 0.003570199478417635f, 0.0024164621718227863f, 0.0036191383842378855f, 0.0027700872160494328f, 0.0030517918057739735f, 0.0024363817647099495f, 0.0027958371210843325f, 0.0020175708923488855f, 0.0033535149414092302f, 0.0019969420973211527f, 0.004349947441369295f, 0.0023148872423917055f, 0.003366698743775487f, 0.002782527357339859f, 0.0026082841213792562f, 0.0038915539626032114f, 0.0022565037943422794f, 0.0034185382537543774f, 0.002106975531205535f, 0.0026551305782049894f, 0.0034069810062646866f, 0.004115802235901356f, 0.0022196276113390923f, 0.0020299621392041445f, 0.0022093034349381924f, 0.004039713181555271f, 0.003163812682032585f, 0.0035397387109696865f, 0.002952664392068982f, 0.004391480702906847f, 0.0028250091709196568f, 0.0032608930487185717f, 0.0022575370967388153f, 0.0023810570128262043f, 0.0036748640704900026f, 0.003548137377947569f, 0.0036299400962889194f, 0.0036973494570702314f, 0.003076561028137803f, 0.003055122448131442f, 0.0020993927028030157f, 0.0037773067597299814f, 0.003856110852211714f, 0.0028115585446357727f, 0.002828048774972558f, 0.002944076433777809f, 0.003081808565184474f, 0.0020783257205039263f, 0.004186260048300028f, 0.0030154669657349586f, 0.004320083186030388f, 0.0034500150941312313f, 0.002648038323968649f, 0.0028583528473973274f, 0.002939205849543214f, 0.002651491202414036f, 0.0027412036433815956f, 0.0035403647925704718f, 0.002439676085487008f, 0.0029069283045828342f, 0.0023930820170789957f, 0.002523711882531643f, 0.0034201277885586023f, 0.0032692314125597477f, 0.002969165565446019f, 0.0031476998701691628f, 0.0032032921444624662f, 0.0026981139089912176f, 0.002901593456044793f, 0.003942268900573254f, 0.0028864291962236166f, 0.0037682654801756144f, 0.0019738380797207355f, 0.0038392606656998396f, 0.004438026808202267f, 0.002596937119960785f, 0.002076098695397377f, 0.003679775632917881f, 0.003585279220715165f, 0.003723881673067808f, 0.002730723936110735f, 0.002352084731683135f, 0.00350087764672935f, 0.003480213461443782f, 0.0032471283338963985f, 0.00394386425614357f, 0.003305228892713785f, 0.0026370573323220015f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #92 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 92,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00022409643861465156f, 0.00019219046225771308f, 0.00016491615679115057f, 0.00016558650531806052f, 0.00022217155492398888f, 0.0001503751118434593f, 0.00022521699429489672f, 0.00017238101281691343f, 0.00018991132674273103f, 0.0001516147021902725f, 0.00017398341151420027f, 0.00012555232387967408f, 0.00020868738647550344f, 0.00012426861212588847f, 0.000270694843493402f, 0.00014405416732188314f, 0.00020950780890416354f, 0.00017315514560323209f, 0.00016231209156103432f, 0.00024216926249209791f, 0.0001404209906468168f, 0.00021273376478347927f, 0.00013111592852510512f, 0.00016522732039447874f, 0.00021201455092523247f, 0.0002561241271905601f, 0.00013812621182296425f, 0.00012632342986762524f, 0.00013748374476563185f, 0.0002513891377020627f, 0.00019688231986947358f, 0.00022027599334251136f, 0.00018374268256593496f, 0.0002732794382609427f, 0.00017579876293893903f, 0.00020292357658036053f, 0.00014048529556021094f, 0.0001481718645663932f, 0.00022868477390147746f, 0.00022079863992985338f, 0.00022588917636312544f, 0.0002300840278621763f, 0.00019145270925946534f, 0.00019011858967132866f, 0.00013064405356999487f, 0.0002350597205804661f, 0.0002399636578047648f, 0.0001749617513269186f, 0.00017598792328499258f, 0.00018320826347917318f, 0.0001917792542371899f, 0.0001293330715270713f, 0.00026050867745652795f, 0.00018765084678307176f, 0.0002688364183995873f, 0.00021469253988470882f, 0.0001647859753575176f, 0.0001778737350832671f, 0.00018290516163688153f, 0.00016500083438586444f, 0.00017058360390365124f, 0.00022031496337149292f, 0.00015181970957200974f, 0.00018089654622599483f, 0.00014892018225509673f, 0.00015704920224379748f, 0.00021283267415128648f, 0.00020344246877357364f, 0.00018476953846402466f, 0.0001958796347025782f, 0.00019933910516556352f, 0.00016790215158835053f, 0.0001805645733838901f, 0.00024532523821108043f, 0.00017962091078516096f, 0.00023449708533007652f, 0.00012283085379749537f, 0.00023891507589723915f, 0.00027617596788331866f, 0.00016160597442649305f, 0.00012919447908643633f, 0.00022899042232893407f, 0.00022310994972940534f, 0.00023173511726781726f, 0.00016993144527077675f, 0.00014636894047725946f, 0.00021785769786220044f, 0.00021657177421730012f, 0.00020206700719427317f, 0.00024542451137676835f, 0.0002056825760519132f, 0.00016410263197030872f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #93 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_41_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.026920674368739128f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #94 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_41_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01736527681350708f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #95 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_42_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0023409868590533733f, 0.0004779654846061021f, 0.0019254479557275772f, 0.0007850543479435146f, 0.0020435177721083164f, 0.0024379598908126354f, 0.0017559283878654242f, 0.0018087278585880995f, 0.002224917756393552f, 0.0017927022418007255f, 0.0017466048011556268f, 0.0018209475092589855f, 0.002383965300396085f, 0.0018633409636095166f, 0.0006607783725485206f, 0.002077995566651225f, 0.001692567951977253f, 0.0019040772458538413f, 0.0016518725315108895f, 0.0017212227685377002f, 0.0012218367774039507f, 0.002009993651881814f, 0.0023007369600236416f, 0.0017153326189145446f, 0.002771934261545539f, 0.000561836757697165f, 0.0007577732321806252f, 0.001929430291056633f, 0.0018898878479376435f, 0.0016884059878066182f, 0.0017886040732264519f, 0.0016752886585891247f, 0.002023885725066066f, 0.002264159033074975f, 0.0026150427293032408f, 0.0007337967399507761f, 0.0008928978350013494f, 0.0008472822955809534f, 0.0009214459569193423f, 0.001918893656693399f, 0.0007043949444778264f, 0.002062771702185273f, 0.0022803836036473513f, 0.002322085900232196f, 0.002900213934481144f, 0.002114668255671859f, 0.0009068126091733575f, 0.0017886098939925432f, 0.002188054146245122f, 0.0022679264657199383f, 0.002423682948574424f, 0.0029979597311466932f, 0.001665047137066722f, 0.0017430123407393694f, 0.002529833698645234f, 0.0016359526198357344f, 0.002139854012057185f, 0.0008616793784312904f, 0.0024522303137928247f, 0.0020280100870877504f, 0.0005847862921655178f, 0.0017408955609425902f, 0.0007852741400711238f, 0.0017160669667646289f, 0.0018627326935529709f, 0.000781018054112792f, 0.001880335621535778f, 0.0004788399091921747f, 0.001742502092383802f, 0.0017695805290713906f, 0.0024980835150927305f, 0.0020694697741419077f, 0.002328387461602688f, 0.001686264993622899f, 0.0016626925207674503f, 0.002386739244684577f, 0.0004323817847762257f, 0.0007841046317480505f, 0.0015984632773324847f, 0.0017591991927474737f, 0.0020023994147777557f, 0.00223756255581975f, 0.0007269998895935714f, 0.0024663754738867283f, 0.0005630184314213693f, 0.0007653062348254025f, 0.0022127567790448666f, 0.0021249796263873577f, 0.0018963045440614223f, 0.002270284341648221f, 0.0016615946078673005f, 0.001846673316322267f, 0.0020371233113110065f, 0.002100016688928008f, 0.0008746908279135823f, 0.001654272899031639f, 0.0007418009918183088f, 0.001990759279578924f, 0.001933376770466566f, 0.0021327664144337177f, 0.0018474278040230274f, 0.001946673379279673f, 0.0023186986800283194f, 0.0021578387822955847f, 0.002889179391786456f, 0.0017164443852379918f, 0.0009215105674229562f, 0.0030374566558748484f, 0.0022178147919476032f, 0.0004996238858439028f, 0.0011585729662328959f, 0.002621890977025032f, 0.0023776418529450893f, 0.000623050844296813f, 0.0017904747510328889f, 0.001963434275239706f, 0.002135226270183921f, 0.0019078265177085996f, 0.0019058651523664594f, 0.0022288558539003134f, 0.00177223130594939f, 0.0020902680698782206f, 0.0007001537014730275f, 0.000602465879637748f, 0.0008570144418627024f, 0.0025200480595231056f, 0.0018642956856638193f, 0.0008794916211627424f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #96 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_42_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002384883991908282f, 4.869280746788718e-05f, 0.00019615530618466437f, 7.997753709787503e-05f, 0.00020818368648178875f, 0.0002483675489202142f, 0.00017888547154143453f, 0.00018426442693453282f, 0.00022666384757030755f, 0.0001826318184612319f, 0.00017793563893064857f, 0.00018550931417848915f, 0.00024286683765240014f, 0.0001898281479952857f, 6.731689791195095e-05f, 0.00021169612591620535f, 0.00017243062029592693f, 0.00019397816504351795f, 0.00016828476509544998f, 0.00017534983635414392f, 0.00012447481276467443f, 0.00020476841018535197f, 0.00023438793141394854f, 0.00017474977357778698f, 0.00028239123639650643f, 5.723720823880285e-05f, 7.719826680840924e-05f, 0.00019656101358123124f, 0.00019253262144047767f, 0.000172006621141918f, 0.00018221432401333004f, 0.00017067028966266662f, 0.00020618367125280201f, 0.0002306615497218445f, 0.0002664078783709556f, 7.475565507775173e-05f, 9.096410940401256e-05f, 8.631701348349452e-05f, 9.387244790559635e-05f, 0.00019548759155441076f, 7.17603470548056e-05f, 0.000210145182791166f, 0.00023231442901305854f, 0.00023656286066398025f, 0.000295459758490324f, 0.0002154321555281058f, 9.23816769500263e-05f, 0.00018221490608993918f, 0.00022290836204774678f, 0.00023104535648599267f, 0.0002469130849931389f, 0.000305417604977265f, 0.00016962693189270794f, 0.00017756965826265514f, 0.00025772719527594745f, 0.00016666292503941804f, 0.00021799796377308667f, 8.778372284723446e-05f, 0.00024982134345918894f, 0.00020660384325310588f, 5.957519533694722e-05f, 0.00017735401343088597f, 7.999992521945387e-05f, 0.00017482458497397602f, 0.0001897661859402433f, 7.956633635330945e-05f, 0.0001915594912134111f, 4.878189065493643e-05f, 0.0001775176788214594f, 0.00018027629994321615f, 0.000254492653766647f, 0.00021082755120005459f, 0.00023720483295619488f, 0.00017178850248456f, 0.00016938705812208354f, 0.00024314943584613502f, 4.404896026244387e-05f, 7.988078141352162e-05f, 0.00016284370212815702f, 0.0001792186958482489f, 0.00020399475761223584f, 0.0002279520413139835f, 7.406322401948273e-05f, 0.00025126239052042365f, 5.7357588957529515e-05f, 7.796569116180763e-05f, 0.00022542494116351008f, 0.00021648262918461114f, 0.00019318632257636636f, 0.00023128556495066732f, 0.00016927521210163832f, 0.00018813012866303325f, 0.00020753225544467568f, 0.00021393952192738652f, 8.910926408134401e-05f, 0.0001685293100308627f, 7.55710934754461e-05f, 0.000202808907488361f, 0.00019696305389516056f, 0.00021727591229137033f, 0.00018820699187926948f, 0.00019831764802802354f, 0.00023621779109816998f, 0.00021983016631565988f, 0.0002943355939351022f, 0.0001748630456859246f, 9.387903264723718e-05f, 0.0003094413841608912f, 0.00022594022448174655f, 5.089925980428234e-05f, 0.0001180297986138612f, 0.0002671055553946644f, 0.00024222263891715556f, 6.347340240608901e-05f, 0.00018240489589516073f, 0.0002000251697609201f, 0.00021752651082351804f, 0.00019436012371443212f, 0.00019416031136643142f, 0.00022706504387315363f, 0.00018054633983410895f, 0.00021294638281688094f, 7.132826431188732e-05f, 6.137630407465622e-05f, 8.730847912374884e-05f, 0.00025673030177131295f, 0.0001899254129966721f, 8.95983466762118e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #97 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_44_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.016794368624687195f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #98 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_44_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007482047192752361f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #99 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_45_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0009292764007113874f, 7.887364336056635e-05f, 0.001422058790922165f, 0.0007582167745567858f, 0.0012651609722524881f, 0.0010006171651184559f, 0.0010596108622848988f, 0.0029387092217803f, 0.0013364540645852685f, 0.0027599497698247433f, 0.0014298510504886508f, 0.001096581225283444f, 0.0017788191325962543f, 0.0012928852811455727f, 0.0002799697103910148f, 0.001758122001774609f, 0.001003648736514151f, 0.0010443973587825894f, 0.0011416712077334523f, 0.001711538527160883f, 0.001012896653264761f, 0.0020238813012838364f, 0.0007850227993912995f, 0.0012094367993995547f, 0.0027684231754392385f, 5.009043889003806e-05f, 0.0003967228112742305f, 0.002025029854848981f, 0.0014313642168417573f, 0.002843643305823207f, 0.002494655316695571f, 0.0014314636355265975f, 0.002815668471157551f, 0.0029433604795485735f, 0.001893531996756792f, 0.0004999979864805937f, 0.00025609356816858053f, 0.0008798266062512994f, 0.0007467786781489849f, 0.0015025120228528976f, 0.0007700247224420309f, 0.0015441670548170805f, 0.0018494913820177317f, 0.0033204159699380398f, 0.0024799697566777468f, 0.0013796919956803322f, 0.0011459181550890207f, 0.0017448551952838898f, 0.0009034557733684778f, 0.0029448787681758404f, 0.0032381422352045774f, 0.003836284624412656f, 0.001303471508435905f, 0.0018293282482773066f, 0.0032076044008135796f, 0.001347794895991683f, 0.0012468970380723476f, 0.0003954206476919353f, 0.0014344350202009082f, 0.0008215647540055215f, 0.0007722291047684848f, 0.0014336862368509173f, 4.525354961515404e-05f, 0.002178745809942484f, 0.001511579961515963f, 8.707453525858e-05f, 0.002737667178735137f, 3.615321475081146e-05f, 0.00141979253385216f, 0.00232169427908957f, 0.003175040241330862f, 0.001479527447372675f, 0.0032494585029780865f, 0.002180104609578848f, 0.0022256060037761927f, 0.002654873300343752f, 0.00018504488980397582f, 0.00022847551736049354f, 0.001664379728026688f, 0.000914274191018194f, 0.0028627668507397175f, 0.003050771076232195f, 0.00040108096436597407f, 0.002852316712960601f, 0.00011612541129579768f, 0.00042603170732036233f, 0.0029556748922914267f, 0.001437238184735179f, 0.00134184374473989f, 0.001410282333381474f, 0.001981189474463463f, 0.0014546512393280864f, 0.0013317266711965203f, 0.0013768462231382728f, 0.0009620364871807396f, 0.001963359536603093f, 0.0006091963150538504f, 0.0019263040740042925f, 0.00130838667973876f, 0.0013516040053218603f, 0.002701718360185623f, 0.003323337296023965f, 0.0010293626692146063f, 0.001374976010993123f, 0.0014396823244169354f, 0.001647324301302433f, 0.0006099695456214249f, 0.0032688577193766832f, 0.0013042535865679383f, 0.0010320879518985748f, 0.0009202209766954184f, 0.001758019090630114f, 0.0031009700614959f, 7.798222213750705e-05f, 0.0017414410831406713f, 0.001331749721430242f, 0.000918035046197474f, 0.0013293791562318802f, 0.002773975022137165f, 0.0013708008918911219f, 0.0030131239909678698f, 0.0028512338176369667f, 0.0003892410022672266f, 0.00012015064567094669f, 0.00043349573388695717f, 0.0032946013379842043f, 0.0008816093322820961f, 0.0008771393913775682f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #100 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_45_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(4.642850763048045e-05f, 3.940685019188095e-06f, 7.104889664333314e-05f, 3.7882025935687125e-05f, 6.320996908470988e-05f, 4.9992835556622595e-05f, 5.294027869240381e-05f, 0.00014682378969155252f, 6.677191413473338e-05f, 0.00013789260992780328f, 7.143821858335286e-05f, 5.4787389672128484e-05f, 8.887336298357695e-05f, 6.459513679146767e-05f, 1.3987846614327282e-05f, 8.783928933553398e-05f, 5.0144295528298244e-05f, 5.218018122832291e-05f, 5.704017530661076e-05f, 8.551188511773944e-05f, 5.0606340664671734e-05f, 0.00010111715528182685f, 3.922130781575106e-05f, 6.04258784733247e-05f, 0.00013831595424562693f, 2.502618372091092e-06f, 1.9821065507130697e-05f, 0.00010117454075952992f, 7.151381578296423e-05f, 0.0001420741027686745f, 0.00012463796883821487f, 7.151878526201472e-05f, 0.0001406764204148203f, 0.0001470561692258343f, 9.460464207222685e-05f, 2.4980898160720244e-05f, 1.2794946997018997e-05f, 4.395789437694475e-05f, 3.731055403477512e-05f, 7.506850670324638e-05f, 3.8471975130960345e-05f, 7.714967068750411e-05f, 9.240428335033357e-05f, 0.00016589461301919073f, 0.0001239042467204854f, 6.893216777825728e-05f, 5.725236042053439e-05f, 8.717645687283948e-05f, 4.513845487963408e-05f, 0.0001471320283599198f, 0.0001617840607650578f, 0.0001916684559546411f, 6.512404070235789e-05f, 9.139689791481942e-05f, 0.000160258321557194f, 6.733852933393791e-05f, 6.22974694124423e-05f, 1.9756005713134073e-05f, 7.166724390117452e-05f, 4.1047016566153616e-05f, 3.858211130136624e-05f, 7.162983092712238e-05f, 2.26095789912506e-06f, 0.00010885449592024088f, 7.552155875600874e-05f, 4.35041783930501e-06f, 0.0001367793302051723f, 1.8062868321067072e-06f, 7.093567546689883e-05f, 0.00011599648860283196f, 0.00015863135922700167f, 7.392014958895743e-05f, 0.00016234944632742554f, 0.00010892238788073882f, 0.00011119572445750237f, 0.00013264277367852628f, 9.245212822861504e-06f, 1.1415093467803672e-05f, 8.315574086736888e-05f, 4.5678967580897734e-05f, 0.0001430295524187386f, 0.00015242262452375144f, 2.0038807633682154e-05f, 0.00014250744425226003f, 5.8018576964968815e-06f, 2.1285395632730797e-05f, 0.00014767142420168966f, 7.180729153333232e-05f, 6.704119732603431e-05f, 7.04605263308622e-05f, 9.898418647935614e-05f, 7.267728506121784e-05f, 6.653572927461937e-05f, 6.878998829051852e-05f, 4.806526703760028e-05f, 9.809336916077882e-05f, 3.0436665838351473e-05f, 9.624200174584985e-05f, 6.536961154779419e-05f, 6.75288392812945e-05f, 0.0001349832455161959f, 0.00016604056872893125f, 5.142901500221342e-05f, 6.869655044283718e-05f, 7.192940392997116e-05f, 8.230361709138379e-05f, 3.047529753530398e-05f, 0.00016331866208929569f, 6.516311987070367e-05f, 5.156517727300525e-05f, 4.5976081310072914e-05f, 8.783414523350075e-05f, 0.0001549306616652757f, 3.8961475183896255e-06f, 8.700587932253256e-05f, 6.653687887592241e-05f, 4.5866865548305213e-05f, 6.641844083787873e-05f, 0.00013859334285371006f, 6.848795601399615e-05f, 0.00015054170216899365f, 0.00014245334023144096f, 1.9447257727733813e-05f, 6.002966529194964e-06f, 2.1658313926309347e-05f, 0.00016460486222058535f, 4.404696301207878e-05f, 4.382363840704784e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #101 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_47_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.24899429082870483f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #102 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_47_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.062207892537117004f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #103 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_48_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0022954409942030907f, 0.002263704314827919f, 0.002242790535092354f, 0.0016967091942206025f, 0.0026249829679727554f, 0.0019082857761532068f, 0.001880232710391283f, 0.0024371391627937555f, 0.0020755603909492493f, 0.00208161398768425f, 0.002031638054177165f, 0.001967524876818061f, 0.002114742761477828f, 0.002129129134118557f, 0.0019366429187357426f, 0.002365163527429104f, 0.002766432473435998f, 0.0017371524590998888f, 0.0018657289911061525f, 0.0021833088248968124f, 0.0019563911482691765f, 0.002085782354697585f, 0.0021621587220579386f, 0.0018572210101410747f, 0.0023724716156721115f, 0.002234559040516615f, 0.001928224810399115f, 0.0022723290603607893f, 0.002965178107842803f, 0.002237653825432062f, 0.003006273414939642f, 0.0020513052586466074f, 0.0020398458000272512f, 0.0021720214281231165f, 0.002309403382241726f, 0.002036074874922633f, 0.0017892108298838139f, 0.002178104827180505f, 0.0018024431774392724f, 0.0021768934093415737f, 0.001726667396724224f, 0.0019882700871676207f, 0.0019311662763357162f, 0.0019691376946866512f, 0.0022672945633530617f, 0.00221177632920444f, 0.0018278807401657104f, 0.0024064884055405855f, 0.002291919430717826f, 0.0017987597966566682f, 0.0019492305582389235f, 0.0025361143052577972f, 0.0023971174377948046f, 0.0023806847166270018f, 0.001783337676897645f, 0.0020292617846280336f, 0.0026626107282936573f, 0.002352165523916483f, 0.0018623104551807046f, 0.002310157287865877f, 0.0016800636658445f, 0.0025382963940501213f, 0.0017008335562422872f, 0.002250509802252054f, 0.0024791492614895105f, 0.002183031290769577f, 0.002262558788061142f, 0.002409869572147727f, 0.0020066266879439354f, 0.0020654855761677027f, 0.002580233383923769f, 0.0024913812521845102f, 0.002219968009740114f, 0.0022449465468525887f, 0.0020402276422828436f, 0.0019510011188685894f, 0.0019363292958587408f, 0.002840144792571664f, 0.002515470376238227f, 0.0023751624394208193f, 0.0020981719717383385f, 0.003088328056037426f, 0.0017724414356052876f, 0.0019802767783403397f, 0.0023808428086340427f, 0.0022381595335900784f, 0.0025653892662376165f, 0.0022459484171122313f, 0.001985276583582163f, 0.0018855187809094787f, 0.0021884306333959103f, 0.0021552254911512136f, 0.0019377981079742312f, 0.0018478274578228593f, 0.002056063385680318f, 0.0021474300883710384f, 0.0026543112471699715f, 0.0027909581549465656f, 0.0019693842623382807f, 0.0017556081293150783f, 0.002149997977539897f, 0.0018866549944505095f, 0.002298203995451331f, 0.002954768715426326f, 0.0022189936134964228f, 0.0017383010126650333f, 0.0022151642479002476f, 0.0022288342006504536f, 0.0026024028193205595f, 0.0024042862933129072f, 0.0018882311414927244f, 0.002509788842871785f, 0.002310720970854163f, 0.0017738518072292209f, 0.0023482567630708218f, 0.0020539644174277782f, 0.0020814617164433002f, 0.002195058623328805f, 0.002071910770609975f, 0.0032198466360569f, 0.0020586950704455376f, 0.0019144631223753095f, 0.0027974892873317003f, 0.0027166716754436493f, 0.002129756147041917f, 0.0019101412035524845f, 0.0016308529302477837f, 0.0018264965619891882f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #104 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_48_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00024555131676606834f, 0.00024215634039137512f, 0.00023991911439225078f, 0.00018150289542973042f, 0.0002808035642374307f, 0.00020413598394952714f, 0.00020113504433538765f, 0.00026070926105603576f, 0.00022202992113307118f, 0.00022267749591264874f, 0.0002173313987441361f, 0.00021047299378551543f, 0.00022622139658778906f, 0.00022776036348659545f, 0.00020716944709420204f, 0.00025300978450104594f, 0.00029593490762636065f, 0.00018582925258670002f, 0.0001995835336856544f, 0.00023355615849141032f, 0.00020928197773173451f, 0.00022312341025099158f, 0.0002312936558155343f, 0.00019867339869961143f, 0.00025379154249094427f, 0.00023903856344986707f, 0.00020626893092412502f, 0.00024307896092068404f, 0.00031719543039798737f, 0.00023936961952131242f, 0.00032159153488464653f, 0.0002194352709921077f, 0.00021820941765327007f, 0.00023234869877342135f, 0.0002470449253451079f, 0.0002178060240112245f, 0.0001913981104735285f, 0.0002329994604224339f, 0.00019281363347545266f, 0.0002328698756173253f, 0.0001847076346166432f, 0.0002126921754097566f, 0.000206583586987108f, 0.00021064552129246294f, 0.00024254039453808218f, 0.00023660142323933542f, 0.00019553476886358112f, 0.0002574304526206106f, 0.0002451745967846364f, 0.00019241959671489894f, 0.0002085159794660285f, 0.00027129697264172137f, 0.00025642800028435886f, 0.00025467012892477214f, 0.000190769846085459f, 0.00021707720588892698f, 0.0002848287404049188f, 0.0002516193490009755f, 0.00019921784405596554f, 0.0002471255720593035f, 0.00017972226487472653f, 0.00027153041446581483f, 0.00018194409494753927f, 0.00024074487737379968f, 0.0002652032417245209f, 0.00023352645803242922f, 0.00024203379871323705f, 0.0002577921550255269f, 0.0002146558545064181f, 0.0002209521917393431f, 0.00027601656620390713f, 0.0002665117208380252f, 0.0002374777104705572f, 0.00024014974769670516f, 0.0002182502648793161f, 0.00020870538719464093f, 0.00020713589037768543f, 0.00030382018303498626f, 0.00026908863219432533f, 0.0002540794084779918f, 0.00022444876958616078f, 0.00033036922104656696f, 0.0001896042376756668f, 0.00021183710487093776f, 0.0002546870382502675f, 0.00023942372354213148f, 0.0002744286321103573f, 0.00024025692255236208f, 0.00021237194596324116f, 0.00020170051720924675f, 0.00023410405265167356f, 0.0002305519738001749f, 0.00020729302195832133f, 0.000197668545297347f, 0.0002199442678829655f, 0.00022971807629801333f, 0.00028394092805683613f, 0.00029855853063054383f, 0.00021067188936285675f, 0.00018780352547764778f, 0.0002299927728017792f, 0.00020182205480523407f, 0.0002458468952681869f, 0.00031608191784471273f, 0.00023737347510177642f, 0.00018595211440697312f, 0.0002369638386880979f, 0.00023842616064939648f, 0.0002783880918286741f, 0.0002571948862168938f, 0.00020199066784698516f, 0.00026848085690289736f, 0.0002471858751960099f, 0.00018975511193275452f, 0.0002512012142688036f, 0.0002197197318309918f, 0.0002226612123195082f, 0.00023481306561734527f, 0.00022163950779940933f, 0.00034443821641616523f, 0.0002202257892349735f, 0.00020479678642004728f, 0.0002992571680806577f, 0.0002906118461396545f, 0.000227827433263883f, 0.00020433445752132684f, 0.00017445802222937346f, 0.0001953867031261325f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #105 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_50_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005137588828802109f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #106 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_50_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0063071888871490955f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #107 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_51_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002750716172158718f, 0.002226727781817317f, 0.002493593143299222f, 0.0020624978933483362f, 0.0021959661971777678f, 0.0038788928650319576f, 0.0025144550018012524f, 0.0022027636878192425f, 0.0025734580121934414f, 0.0028704379219561815f, 0.0022240011021494865f, 0.002080886624753475f, 0.0024530100636184216f, 0.002178349532186985f, 0.002248798729851842f, 0.0023464029654860497f, 0.002179920207709074f, 0.002252368489280343f, 0.0020415615290403366f, 0.0022144748363643885f, 0.0024609691463410854f, 0.002191750565543771f, 0.0021598839666694403f, 0.0022309969644993544f, 0.0019752902444452047f, 0.002448159037157893f, 0.0023626552429050207f, 0.002459157956764102f, 0.002361584221944213f, 0.0018951313104480505f, 0.0021632553543895483f, 0.0023057342041283846f, 0.002178515773266554f, 0.002581524197012186f, 0.0025889219250530005f, 0.002533217193558812f, 0.002098965225741267f, 0.0027779897209256887f, 0.0024707650300115347f, 0.0023796719033271074f, 0.0021958532743155956f, 0.002357254270464182f, 0.0023841806687414646f, 0.002261567395180464f, 0.0027194092981517315f, 0.0022256621159613132f, 0.0020223185420036316f, 0.0030039402190595865f, 0.0021144128404557705f, 0.0019714445807039738f, 0.0022562071681022644f, 0.002224691677838564f, 0.002767197322100401f, 0.002409747103229165f, 0.002274185186251998f, 0.002624353626742959f, 0.002331057097762823f, 0.002402000594884157f, 0.002408817643299699f, 0.0029654663521796465f, 0.0022804292384535074f, 0.00211780215613544f, 0.0022655234206467867f, 0.0022747262846678495f, 0.0025985108222812414f, 0.0019917436875402927f, 0.002009612275287509f, 0.0019260860281065106f, 0.0022980631329119205f, 0.002098667435348034f, 0.002477525267750025f, 0.002365418244153261f, 0.0020481818355619907f, 0.0020015346817672253f, 0.002336249453946948f, 0.0022929408587515354f, 0.0021624346263706684f, 0.002332966774702072f, 0.0029081411194056273f, 0.0023526952136307955f, 0.002188699319958687f, 0.002267927397042513f, 0.002067673485726118f, 0.002354277763515711f, 0.002243221504613757f, 0.0020283134654164314f, 0.0021367522422224283f, 0.0024430782068520784f, 0.001937441062182188f, 0.002282292814925313f, 0.00208409340120852f, 0.0022545475512742996f, 0.0022141067311167717f, 0.002675546333193779f, 0.0026653166860342026f, 0.002115021226927638f, 0.002464401302859187f, 0.0027545534539967775f, 0.0025283140130341053f, 0.0022640759125351906f, 0.002351412083953619f, 0.002229419769719243f, 0.0021162910852581263f, 0.0022471302654594183f, 0.002501046285033226f, 0.0023338941391557455f, 0.002402684884145856f, 0.0022308696061372757f, 0.002041973639279604f, 0.002740927506238222f, 0.0026351013220846653f, 0.0027071237564086914f, 0.0019562579691410065f, 0.002092638285830617f, 0.002419995842501521f, 0.00203332700766623f, 0.002148774452507496f, 0.0024743934627622366f, 0.0023028391879051924f, 0.002478539478033781f, 0.002010842552408576f, 0.0021901633590459824f, 0.0020890284795314074f, 0.0022327075712382793f, 0.0022137474734336138f, 0.0022565219551324844f, 0.002131106099113822f, 0.0023879988584667444f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #108 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_51_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001504586252849549f, 0.00012179751502117142f, 0.00013639451935887337f, 0.00011281447223154828f, 0.00012011492071906105f, 0.00021216762252151966f, 0.00013753562234342098f, 0.00012048672942910343f, 0.0001407629606546834f, 0.00015700716176070273f, 0.00012164837244199589f, 0.000113820300612133f, 0.00013417469745036215f, 0.00011915132199646905f, 0.00012300474918447435f, 0.0001283435121877119f, 0.00011923723650397733f, 0.00012320000678300858f, 0.00011166929471073672f, 0.00012112730473745614f, 0.0001346100470982492f, 0.00011988433834630996f, 0.00011814129538834095f, 0.00012203103688079864f, 0.0001080443907994777f, 0.0001339093578280881f, 0.0001292324741370976f, 0.00013451097765937448f, 0.0001291738881263882f, 0.00010365986236138269f, 0.00011832570453407243f, 0.00012611900456249714f, 0.00011916041694348678f, 0.00014120416017249227f, 0.00014160880527924746f, 0.0001385618670610711f, 0.00011480916145956144f, 0.00015195042942650616f, 0.0001351458631688729f, 0.00013016325829084963f, 0.0001201087434310466f, 0.00012893705570604652f, 0.00013040986959822476f, 0.00012370316835585982f, 0.00014874619955662638f, 0.0001217392273247242f, 0.00011061674740631133f, 0.00016430947289336473f, 0.00011565411841729656f, 0.00010783404286485165f, 0.00012340997636783868f, 0.00012168614921392873f, 0.00015136011643335223f, 0.00013180830865167081f, 0.0001243933365913108f, 0.0001435468439012766f, 0.00012750412861350924f, 0.00013138458598405123f, 0.0001317574642598629f, 0.00016220503312069923f, 0.0001247348845936358f, 0.00011583950981730595f, 0.00012391955533530563f, 0.0001244229351868853f, 0.0001421332999598235f, 0.00010894436127273366f, 0.00010992174065904692f, 0.00010535302135394886f, 0.0001256994146388024f, 0.0001147928778664209f, 0.00013551564188674092f, 0.00012938361032865942f, 0.00011203141184523702f, 0.00010947990813292563f, 0.00012778813834302127f, 0.00012541924661491066f, 0.00011828081187559292f, 0.00012760858226101846f, 0.00015906945918686688f, 0.000128687679534778f, 0.0001197174351545982f, 0.00012405106099322438f, 0.00011309757246635854f, 0.00012877424887847155f, 0.0001226996973855421f, 0.00011094465298810974f, 0.00011687603546306491f, 0.00013363144535105675f, 0.0001059741189237684f, 0.0001248368207598105f, 0.00011399570212233812f, 0.00012331920152064413f, 0.0001211071721627377f, 0.00014634698163717985f, 0.00014578744594473392f, 0.00011568739864742383f, 0.00013479778135661036f, 0.00015066852211020887f, 0.0001382936752634123f, 0.00012384039291646332f, 0.00012861749564763159f, 0.00012194476585136726f, 0.00011575685493880883f, 0.00012291349412407726f, 0.00013680219126399606f, 0.0001276592956855893f, 0.0001314220135100186f, 0.00012202406651340425f, 0.00011169184290338308f, 0.00014992320211604238f, 0.00014413472672458738f, 0.00014807420666329563f, 0.00010700336861191317f, 0.00011446309508755803f, 0.0001323688920820132f, 0.00011121888383058831f, 0.00011753362923627719f, 0.0001353443367406726f, 0.00012596066517289728f, 0.00013557111378759146f, 0.00010998902871506289f, 0.00011979752162005752f, 0.00011426564742578194f, 0.00012212460569571704f, 0.00012108751980122179f, 0.00012342720583546907f, 0.0001165672074421309f, 0.00013061871868558228f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #109 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_53_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003621158190071583f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #110 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_53_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004874981939792633f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #111 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_55_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009204262867569923f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #112 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_55_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0003147161041852087f),
    AI_PACK_INTQ_ZP(0)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_conv2d_input0_int8_output, AI_STATIC,
  0, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 32, 32), AI_STRIDE_INIT(4, 1, 1, 3, 96),
  1, &serving_default_conv2d_input0_int8_output_array, &serving_default_conv2d_input0_int8_output_intq)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_output, AI_STATIC,
  1, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 1, 1, 32, 1024),
  1, &conv2d_0_output_array, &conv2d_0_output_intq)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_2_output, AI_STATIC,
  2, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 1, 1, 32, 1024),
  1, &eltwise_2_output_array, &eltwise_2_output_intq)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_output, AI_STATIC,
  3, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 1, 1, 32, 1024),
  1, &conv2d_3_output_array, &conv2d_3_output_intq)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_5_output, AI_STATIC,
  4, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 1, 1, 32, 1024),
  1, &eltwise_5_output_array, &eltwise_5_output_intq)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_output, AI_STATIC,
  5, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 1, 1, 32, 1024),
  1, &conv2d_6_output_array, &conv2d_6_output_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_8_output, AI_STATIC,
  6, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 1, 1, 32, 1024),
  1, &eltwise_8_output_array, &eltwise_8_output_intq)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_output, AI_STATIC,
  7, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 1, 1, 32, 1024),
  1, &conv2d_9_output_array, &conv2d_9_output_intq)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_11_output, AI_STATIC,
  8, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 1, 1, 32, 1024),
  1, &eltwise_11_output_array, &eltwise_11_output_intq)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_output, AI_STATIC,
  9, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 1, 1, 32, 1024),
  1, &conv2d_12_output_array, &conv2d_12_output_intq)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_14_output, AI_STATIC,
  10, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 1, 1, 32, 1024),
  1, &eltwise_14_output_array, &eltwise_14_output_intq)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_output, AI_STATIC,
  11, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 1, 1, 32, 1024),
  1, &conv2d_15_output_array, &conv2d_15_output_intq)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_17_output, AI_STATIC,
  12, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 1, 1, 32, 1024),
  1, &eltwise_17_output_array, &eltwise_17_output_intq)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_output, AI_STATIC,
  13, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 1, 1, 32, 1024),
  1, &conv2d_18_output_array, &conv2d_18_output_intq)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_20_output, AI_STATIC,
  14, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 1, 1, 32, 1024),
  1, &eltwise_20_output_array, &eltwise_20_output_intq)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_output, AI_STATIC,
  15, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 1, 1, 32, 1024),
  1, &conv2d_21_output_array, &conv2d_21_output_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_23_output, AI_STATIC,
  16, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 1, 1, 32, 1024),
  1, &eltwise_23_output_array, &eltwise_23_output_intq)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_output, AI_STATIC,
  17, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 16, 16), AI_STRIDE_INIT(4, 1, 1, 92, 1472),
  1, &conv2d_24_output_array, &conv2d_24_output_intq)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_26_output, AI_STATIC,
  18, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 16, 16), AI_STRIDE_INIT(4, 1, 1, 92, 1472),
  1, &eltwise_26_output_array, &eltwise_26_output_intq)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_output, AI_STATIC,
  19, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 16, 16), AI_STRIDE_INIT(4, 1, 1, 92, 1472),
  1, &conv2d_27_output_array, &conv2d_27_output_intq)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_29_output, AI_STATIC,
  20, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 16, 16), AI_STRIDE_INIT(4, 1, 1, 92, 1472),
  1, &eltwise_29_output_array, &eltwise_29_output_intq)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_output, AI_STATIC,
  21, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 16, 16), AI_STRIDE_INIT(4, 1, 1, 92, 1472),
  1, &conv2d_30_output_array, &conv2d_30_output_intq)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_32_output, AI_STATIC,
  22, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 16, 16), AI_STRIDE_INIT(4, 1, 1, 92, 1472),
  1, &eltwise_32_output_array, &eltwise_32_output_intq)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_output, AI_STATIC,
  23, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 16, 16), AI_STRIDE_INIT(4, 1, 1, 92, 1472),
  1, &conv2d_33_output_array, &conv2d_33_output_intq)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_35_output, AI_STATIC,
  24, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 16, 16), AI_STRIDE_INIT(4, 1, 1, 92, 1472),
  1, &eltwise_35_output_array, &eltwise_35_output_intq)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_output, AI_STATIC,
  25, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 16, 16), AI_STRIDE_INIT(4, 1, 1, 92, 1472),
  1, &conv2d_36_output_array, &conv2d_36_output_intq)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_38_output, AI_STATIC,
  26, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 16, 16), AI_STRIDE_INIT(4, 1, 1, 92, 1472),
  1, &eltwise_38_output_array, &eltwise_38_output_intq)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_output, AI_STATIC,
  27, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 16, 16), AI_STRIDE_INIT(4, 1, 1, 92, 1472),
  1, &conv2d_39_output_array, &conv2d_39_output_intq)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_41_output, AI_STATIC,
  28, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 16, 16), AI_STRIDE_INIT(4, 1, 1, 92, 1472),
  1, &eltwise_41_output_array, &eltwise_41_output_intq)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_output, AI_STATIC,
  29, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 8, 8), AI_STRIDE_INIT(4, 1, 1, 128, 1024),
  1, &conv2d_42_output_array, &conv2d_42_output_intq)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_44_output, AI_STATIC,
  30, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 8, 8), AI_STRIDE_INIT(4, 1, 1, 128, 1024),
  1, &eltwise_44_output_array, &eltwise_44_output_intq)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_output, AI_STATIC,
  31, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 8, 8), AI_STRIDE_INIT(4, 1, 1, 128, 1024),
  1, &conv2d_45_output_array, &conv2d_45_output_intq)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_47_output, AI_STATIC,
  32, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 8, 8), AI_STRIDE_INIT(4, 1, 1, 128, 1024),
  1, &eltwise_47_output_array, &eltwise_47_output_intq)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_output, AI_STATIC,
  33, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 4, 4), AI_STRIDE_INIT(4, 1, 1, 128, 512),
  1, &conv2d_48_output_array, &conv2d_48_output_intq)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_50_output, AI_STATIC,
  34, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 4, 4), AI_STRIDE_INIT(4, 1, 1, 128, 512),
  1, &eltwise_50_output_array, &eltwise_50_output_intq)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_51_output, AI_STATIC,
  35, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 2, 2), AI_STRIDE_INIT(4, 1, 1, 128, 256),
  1, &conv2d_51_output_array, &conv2d_51_output_intq)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_53_output, AI_STATIC,
  36, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 2, 2), AI_STRIDE_INIT(4, 1, 1, 128, 256),
  1, &eltwise_53_output_array, &eltwise_53_output_intq)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_53_output0, AI_STATIC,
  37, 0x1,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &eltwise_53_output_array, &eltwise_53_output_intq)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  dense_55_output, AI_STATIC,
  38, 0x1,
  AI_SHAPE_INIT(4, 1, 20, 1, 1), AI_STRIDE_INIT(4, 1, 1, 20, 20),
  1, &dense_55_output_array, &dense_55_output_intq)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  dense_55_fmt_output, AI_STATIC,
  39, 0x0,
  AI_SHAPE_INIT(4, 1, 20, 1, 1), AI_STRIDE_INIT(4, 4, 4, 80, 80),
  1, &dense_55_fmt_output_array, NULL)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  nl_56_output, AI_STATIC,
  40, 0x0,
  AI_SHAPE_INIT(4, 1, 20, 1, 1), AI_STRIDE_INIT(4, 4, 4, 80, 80),
  1, &nl_56_output_array, NULL)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  nl_56_fmt_output, AI_STATIC,
  41, 0x1,
  AI_SHAPE_INIT(4, 1, 20, 1, 1), AI_STRIDE_INIT(4, 1, 1, 20, 20),
  1, &nl_56_fmt_output_array, &nl_56_fmt_output_intq)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_weights, AI_STATIC,
  42, 0x1,
  AI_SHAPE_INIT(4, 3, 3, 3, 32), AI_STRIDE_INIT(4, 1, 3, 9, 27),
  1, &conv2d_0_weights_array, &conv2d_0_weights_intq)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_bias, AI_STATIC,
  43, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_0_bias_array, &conv2d_0_bias_intq)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_2_scale, AI_STATIC,
  44, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_2_scale_array, &eltwise_2_scale_intq)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_2_bias, AI_STATIC,
  45, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_2_bias_array, &eltwise_2_bias_intq)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_weights, AI_STATIC,
  46, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 1), AI_STRIDE_INIT(4, 1, 32, 96, 288),
  1, &conv2d_3_weights_array, &conv2d_3_weights_intq)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_bias, AI_STATIC,
  47, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_3_bias_array, &conv2d_3_bias_intq)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_5_scale, AI_STATIC,
  48, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_5_scale_array, &eltwise_5_scale_intq)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_5_bias, AI_STATIC,
  49, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_5_bias_array, &eltwise_5_bias_intq)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_weights, AI_STATIC,
  50, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 32), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_6_weights_array, &conv2d_6_weights_intq)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_bias, AI_STATIC,
  51, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_6_bias_array, &conv2d_6_bias_intq)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_8_scale, AI_STATIC,
  52, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_8_scale_array, &eltwise_8_scale_intq)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_8_bias, AI_STATIC,
  53, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_8_bias_array, &eltwise_8_bias_intq)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_weights, AI_STATIC,
  54, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 1), AI_STRIDE_INIT(4, 1, 32, 96, 288),
  1, &conv2d_9_weights_array, &conv2d_9_weights_intq)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_bias, AI_STATIC,
  55, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_9_bias_array, &conv2d_9_bias_intq)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_11_scale, AI_STATIC,
  56, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_11_scale_array, &eltwise_11_scale_intq)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_11_bias, AI_STATIC,
  57, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_11_bias_array, &eltwise_11_bias_intq)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_weights, AI_STATIC,
  58, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 32), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_12_weights_array, &conv2d_12_weights_intq)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_bias, AI_STATIC,
  59, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_12_bias_array, &conv2d_12_bias_intq)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_14_scale, AI_STATIC,
  60, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_14_scale_array, &eltwise_14_scale_intq)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_14_bias, AI_STATIC,
  61, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_14_bias_array, &eltwise_14_bias_intq)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_weights, AI_STATIC,
  62, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 1), AI_STRIDE_INIT(4, 1, 32, 96, 288),
  1, &conv2d_15_weights_array, &conv2d_15_weights_intq)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_bias, AI_STATIC,
  63, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_15_bias_array, &conv2d_15_bias_intq)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_17_scale, AI_STATIC,
  64, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_17_scale_array, &eltwise_17_scale_intq)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_17_bias, AI_STATIC,
  65, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_17_bias_array, &eltwise_17_bias_intq)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_weights, AI_STATIC,
  66, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 32), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_18_weights_array, &conv2d_18_weights_intq)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_bias, AI_STATIC,
  67, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_18_bias_array, &conv2d_18_bias_intq)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_20_scale, AI_STATIC,
  68, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_20_scale_array, &eltwise_20_scale_intq)

/* Tensor #69 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_20_bias, AI_STATIC,
  69, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_20_bias_array, &eltwise_20_bias_intq)

/* Tensor #70 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_weights, AI_STATIC,
  70, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 1), AI_STRIDE_INIT(4, 1, 32, 96, 288),
  1, &conv2d_21_weights_array, &conv2d_21_weights_intq)

/* Tensor #71 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_bias, AI_STATIC,
  71, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_21_bias_array, &conv2d_21_bias_intq)

/* Tensor #72 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_23_scale, AI_STATIC,
  72, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_23_scale_array, &eltwise_23_scale_intq)

/* Tensor #73 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_23_bias, AI_STATIC,
  73, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_23_bias_array, &eltwise_23_bias_intq)

/* Tensor #74 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_weights, AI_STATIC,
  74, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 92), AI_STRIDE_INIT(4, 1, 32, 96, 288),
  1, &conv2d_24_weights_array, &conv2d_24_weights_intq)

/* Tensor #75 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_bias, AI_STATIC,
  75, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 1, 1), AI_STRIDE_INIT(4, 4, 4, 368, 368),
  1, &conv2d_24_bias_array, &conv2d_24_bias_intq)

/* Tensor #76 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_26_scale, AI_STATIC,
  76, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 1, 1), AI_STRIDE_INIT(4, 1, 1, 92, 92),
  1, &eltwise_26_scale_array, &eltwise_26_scale_intq)

/* Tensor #77 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_26_bias, AI_STATIC,
  77, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 1, 1), AI_STRIDE_INIT(4, 1, 1, 92, 92),
  1, &eltwise_26_bias_array, &eltwise_26_bias_intq)

/* Tensor #78 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_weights, AI_STATIC,
  78, 0x1,
  AI_SHAPE_INIT(4, 92, 1, 1, 1), AI_STRIDE_INIT(4, 1, 92, 92, 92),
  1, &conv2d_27_weights_array, &conv2d_27_weights_intq)

/* Tensor #79 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_bias, AI_STATIC,
  79, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 1, 1), AI_STRIDE_INIT(4, 4, 4, 368, 368),
  1, &conv2d_27_bias_array, &conv2d_27_bias_intq)

/* Tensor #80 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_29_scale, AI_STATIC,
  80, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 1, 1), AI_STRIDE_INIT(4, 1, 1, 92, 92),
  1, &eltwise_29_scale_array, &eltwise_29_scale_intq)

/* Tensor #81 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_29_bias, AI_STATIC,
  81, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 1, 1), AI_STRIDE_INIT(4, 1, 1, 92, 92),
  1, &eltwise_29_bias_array, &eltwise_29_bias_intq)

/* Tensor #82 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_weights, AI_STATIC,
  82, 0x1,
  AI_SHAPE_INIT(4, 92, 1, 1, 92), AI_STRIDE_INIT(4, 1, 92, 92, 92),
  1, &conv2d_30_weights_array, &conv2d_30_weights_intq)

/* Tensor #83 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_bias, AI_STATIC,
  83, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 1, 1), AI_STRIDE_INIT(4, 4, 4, 368, 368),
  1, &conv2d_30_bias_array, &conv2d_30_bias_intq)

/* Tensor #84 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_32_scale, AI_STATIC,
  84, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 1, 1), AI_STRIDE_INIT(4, 1, 1, 92, 92),
  1, &eltwise_32_scale_array, &eltwise_32_scale_intq)

/* Tensor #85 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_32_bias, AI_STATIC,
  85, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 1, 1), AI_STRIDE_INIT(4, 1, 1, 92, 92),
  1, &eltwise_32_bias_array, &eltwise_32_bias_intq)

/* Tensor #86 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_weights, AI_STATIC,
  86, 0x1,
  AI_SHAPE_INIT(4, 92, 3, 3, 1), AI_STRIDE_INIT(4, 1, 92, 276, 828),
  1, &conv2d_33_weights_array, &conv2d_33_weights_intq)

/* Tensor #87 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_bias, AI_STATIC,
  87, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 1, 1), AI_STRIDE_INIT(4, 4, 4, 368, 368),
  1, &conv2d_33_bias_array, &conv2d_33_bias_intq)

/* Tensor #88 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_35_scale, AI_STATIC,
  88, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 1, 1), AI_STRIDE_INIT(4, 1, 1, 92, 92),
  1, &eltwise_35_scale_array, &eltwise_35_scale_intq)

/* Tensor #89 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_35_bias, AI_STATIC,
  89, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 1, 1), AI_STRIDE_INIT(4, 1, 1, 92, 92),
  1, &eltwise_35_bias_array, &eltwise_35_bias_intq)

/* Tensor #90 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_weights, AI_STATIC,
  90, 0x1,
  AI_SHAPE_INIT(4, 92, 1, 1, 92), AI_STRIDE_INIT(4, 1, 92, 92, 92),
  1, &conv2d_36_weights_array, &conv2d_36_weights_intq)

/* Tensor #91 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_bias, AI_STATIC,
  91, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 1, 1), AI_STRIDE_INIT(4, 4, 4, 368, 368),
  1, &conv2d_36_bias_array, &conv2d_36_bias_intq)

/* Tensor #92 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_38_scale, AI_STATIC,
  92, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 1, 1), AI_STRIDE_INIT(4, 1, 1, 92, 92),
  1, &eltwise_38_scale_array, &eltwise_38_scale_intq)

/* Tensor #93 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_38_bias, AI_STATIC,
  93, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 1, 1), AI_STRIDE_INIT(4, 1, 1, 92, 92),
  1, &eltwise_38_bias_array, &eltwise_38_bias_intq)

/* Tensor #94 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_weights, AI_STATIC,
  94, 0x1,
  AI_SHAPE_INIT(4, 92, 3, 3, 1), AI_STRIDE_INIT(4, 1, 92, 276, 828),
  1, &conv2d_39_weights_array, &conv2d_39_weights_intq)

/* Tensor #95 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_bias, AI_STATIC,
  95, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 1, 1), AI_STRIDE_INIT(4, 4, 4, 368, 368),
  1, &conv2d_39_bias_array, &conv2d_39_bias_intq)

/* Tensor #96 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_41_scale, AI_STATIC,
  96, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 1, 1), AI_STRIDE_INIT(4, 1, 1, 92, 92),
  1, &eltwise_41_scale_array, &eltwise_41_scale_intq)

/* Tensor #97 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_41_bias, AI_STATIC,
  97, 0x1,
  AI_SHAPE_INIT(4, 1, 92, 1, 1), AI_STRIDE_INIT(4, 1, 1, 92, 92),
  1, &eltwise_41_bias_array, &eltwise_41_bias_intq)

/* Tensor #98 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_weights, AI_STATIC,
  98, 0x1,
  AI_SHAPE_INIT(4, 92, 3, 3, 128), AI_STRIDE_INIT(4, 1, 92, 276, 828),
  1, &conv2d_42_weights_array, &conv2d_42_weights_intq)

/* Tensor #99 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_bias, AI_STATIC,
  99, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_42_bias_array, &conv2d_42_bias_intq)

/* Tensor #100 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_44_scale, AI_STATIC,
  100, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &eltwise_44_scale_array, &eltwise_44_scale_intq)

/* Tensor #101 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_44_bias, AI_STATIC,
  101, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &eltwise_44_bias_array, &eltwise_44_bias_intq)

/* Tensor #102 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_weights, AI_STATIC,
  102, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 1), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_45_weights_array, &conv2d_45_weights_intq)

/* Tensor #103 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_bias, AI_STATIC,
  103, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_45_bias_array, &conv2d_45_bias_intq)

/* Tensor #104 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_47_scale, AI_STATIC,
  104, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &eltwise_47_scale_array, &eltwise_47_scale_intq)

/* Tensor #105 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_47_bias, AI_STATIC,
  105, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &eltwise_47_bias_array, &eltwise_47_bias_intq)

/* Tensor #106 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_weights, AI_STATIC,
  106, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 128), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_48_weights_array, &conv2d_48_weights_intq)

/* Tensor #107 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_bias, AI_STATIC,
  107, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_48_bias_array, &conv2d_48_bias_intq)

/* Tensor #108 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_50_scale, AI_STATIC,
  108, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &eltwise_50_scale_array, &eltwise_50_scale_intq)

/* Tensor #109 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_50_bias, AI_STATIC,
  109, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &eltwise_50_bias_array, &eltwise_50_bias_intq)

/* Tensor #110 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_51_weights, AI_STATIC,
  110, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 128), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_51_weights_array, &conv2d_51_weights_intq)

/* Tensor #111 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_51_bias, AI_STATIC,
  111, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_51_bias_array, &conv2d_51_bias_intq)

/* Tensor #112 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_53_scale, AI_STATIC,
  112, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &eltwise_53_scale_array, &eltwise_53_scale_intq)

/* Tensor #113 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_53_bias, AI_STATIC,
  113, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &eltwise_53_bias_array, &eltwise_53_bias_intq)

/* Tensor #114 */
AI_TENSOR_OBJ_DECLARE(
  dense_55_weights, AI_STATIC,
  114, 0x1,
  AI_SHAPE_INIT(4, 512, 20, 1, 1), AI_STRIDE_INIT(4, 1, 512, 10240, 10240),
  1, &dense_55_weights_array, &dense_55_weights_intq)

/* Tensor #115 */
AI_TENSOR_OBJ_DECLARE(
  dense_55_bias, AI_STATIC,
  115, 0x1,
  AI_SHAPE_INIT(4, 1, 20, 1, 1), AI_STRIDE_INIT(4, 4, 4, 80, 80),
  1, &dense_55_bias_array, &dense_55_bias_intq)

/* Tensor #116 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_scratch0, AI_STATIC,
  116, 0x0,
  AI_SHAPE_INIT(4, 1, 2284, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2284, 2284),
  1, &conv2d_0_scratch0_array, NULL)

/* Tensor #117 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_2_scratch0, AI_STATIC,
  117, 0x0,
  AI_SHAPE_INIT(4, 1, 320, 1, 1), AI_STRIDE_INIT(4, 1, 1, 320, 320),
  1, &eltwise_2_scratch0_array, NULL)

/* Tensor #118 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch0, AI_STATIC,
  118, 0x0,
  AI_SHAPE_INIT(4, 1, 1185, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1185, 1185),
  1, &conv2d_3_scratch0_array, NULL)

/* Tensor #119 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_5_scratch0, AI_STATIC,
  119, 0x0,
  AI_SHAPE_INIT(4, 1, 320, 1, 1), AI_STRIDE_INIT(4, 1, 1, 320, 320),
  1, &eltwise_5_scratch0_array, NULL)

/* Tensor #120 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_scratch0, AI_STATIC,
  120, 0x0,
  AI_SHAPE_INIT(4, 1, 448, 1, 1), AI_STRIDE_INIT(4, 1, 1, 448, 448),
  1, &conv2d_6_scratch0_array, NULL)

/* Tensor #121 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_8_scratch0, AI_STATIC,
  121, 0x0,
  AI_SHAPE_INIT(4, 1, 320, 1, 1), AI_STRIDE_INIT(4, 1, 1, 320, 320),
  1, &eltwise_8_scratch0_array, NULL)

/* Tensor #122 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch0, AI_STATIC,
  122, 0x0,
  AI_SHAPE_INIT(4, 1, 1185, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1185, 1185),
  1, &conv2d_9_scratch0_array, NULL)

/* Tensor #123 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_11_scratch0, AI_STATIC,
  123, 0x0,
  AI_SHAPE_INIT(4, 1, 320, 1, 1), AI_STRIDE_INIT(4, 1, 1, 320, 320),
  1, &eltwise_11_scratch0_array, NULL)

/* Tensor #124 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_scratch0, AI_STATIC,
  124, 0x0,
  AI_SHAPE_INIT(4, 1, 448, 1, 1), AI_STRIDE_INIT(4, 1, 1, 448, 448),
  1, &conv2d_12_scratch0_array, NULL)

/* Tensor #125 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_14_scratch0, AI_STATIC,
  125, 0x0,
  AI_SHAPE_INIT(4, 1, 320, 1, 1), AI_STRIDE_INIT(4, 1, 1, 320, 320),
  1, &eltwise_14_scratch0_array, NULL)

/* Tensor #126 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_scratch0, AI_STATIC,
  126, 0x0,
  AI_SHAPE_INIT(4, 1, 1185, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1185, 1185),
  1, &conv2d_15_scratch0_array, NULL)

/* Tensor #127 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_17_scratch0, AI_STATIC,
  127, 0x0,
  AI_SHAPE_INIT(4, 1, 320, 1, 1), AI_STRIDE_INIT(4, 1, 1, 320, 320),
  1, &eltwise_17_scratch0_array, NULL)

/* Tensor #128 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_scratch0, AI_STATIC,
  128, 0x0,
  AI_SHAPE_INIT(4, 1, 448, 1, 1), AI_STRIDE_INIT(4, 1, 1, 448, 448),
  1, &conv2d_18_scratch0_array, NULL)

/* Tensor #129 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_20_scratch0, AI_STATIC,
  129, 0x0,
  AI_SHAPE_INIT(4, 1, 320, 1, 1), AI_STRIDE_INIT(4, 1, 1, 320, 320),
  1, &eltwise_20_scratch0_array, NULL)

/* Tensor #130 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_scratch0, AI_STATIC,
  130, 0x0,
  AI_SHAPE_INIT(4, 1, 1185, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1185, 1185),
  1, &conv2d_21_scratch0_array, NULL)

/* Tensor #131 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_23_scratch0, AI_STATIC,
  131, 0x0,
  AI_SHAPE_INIT(4, 1, 320, 1, 1), AI_STRIDE_INIT(4, 1, 1, 320, 320),
  1, &eltwise_23_scratch0_array, NULL)

/* Tensor #132 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_scratch0, AI_STATIC,
  132, 0x0,
  AI_SHAPE_INIT(4, 1, 7560, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7560, 7560),
  1, &conv2d_24_scratch0_array, NULL)

/* Tensor #133 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_26_scratch0, AI_STATIC,
  133, 0x0,
  AI_SHAPE_INIT(4, 1, 920, 1, 1), AI_STRIDE_INIT(4, 1, 1, 920, 920),
  1, &eltwise_26_scratch0_array, NULL)

/* Tensor #134 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_scratch0, AI_STATIC,
  134, 0x0,
  AI_SHAPE_INIT(4, 1, 1197, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1197, 1197),
  1, &conv2d_27_scratch0_array, NULL)

/* Tensor #135 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_29_scratch0, AI_STATIC,
  135, 0x0,
  AI_SHAPE_INIT(4, 1, 920, 1, 1), AI_STRIDE_INIT(4, 1, 1, 920, 920),
  1, &eltwise_29_scratch0_array, NULL)

/* Tensor #136 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_scratch0, AI_STATIC,
  136, 0x0,
  AI_SHAPE_INIT(4, 1, 1288, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1288, 1288),
  1, &conv2d_30_scratch0_array, NULL)

/* Tensor #137 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_32_scratch0, AI_STATIC,
  137, 0x0,
  AI_SHAPE_INIT(4, 1, 920, 1, 1), AI_STRIDE_INIT(4, 1, 1, 920, 920),
  1, &eltwise_32_scratch0_array, NULL)

/* Tensor #138 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_scratch0, AI_STATIC,
  138, 0x0,
  AI_SHAPE_INIT(4, 1, 3405, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3405, 3405),
  1, &conv2d_33_scratch0_array, NULL)

/* Tensor #139 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_35_scratch0, AI_STATIC,
  139, 0x0,
  AI_SHAPE_INIT(4, 1, 920, 1, 1), AI_STRIDE_INIT(4, 1, 1, 920, 920),
  1, &eltwise_35_scratch0_array, NULL)

/* Tensor #140 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_scratch0, AI_STATIC,
  140, 0x0,
  AI_SHAPE_INIT(4, 1, 1288, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1288, 1288),
  1, &conv2d_36_scratch0_array, NULL)

/* Tensor #141 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_38_scratch0, AI_STATIC,
  141, 0x0,
  AI_SHAPE_INIT(4, 1, 920, 1, 1), AI_STRIDE_INIT(4, 1, 1, 920, 920),
  1, &eltwise_38_scratch0_array, NULL)

/* Tensor #142 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_scratch0, AI_STATIC,
  142, 0x0,
  AI_SHAPE_INIT(4, 1, 3405, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3405, 3405),
  1, &conv2d_39_scratch0_array, NULL)

/* Tensor #143 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_41_scratch0, AI_STATIC,
  143, 0x0,
  AI_SHAPE_INIT(4, 1, 920, 1, 1), AI_STRIDE_INIT(4, 1, 1, 920, 920),
  1, &eltwise_41_scratch0_array, NULL)

/* Tensor #144 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_scratch0, AI_STATIC,
  144, 0x0,
  AI_SHAPE_INIT(4, 1, 10224, 1, 1), AI_STRIDE_INIT(4, 1, 1, 10224, 10224),
  1, &conv2d_42_scratch0_array, NULL)

/* Tensor #145 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_44_scratch0, AI_STATIC,
  145, 0x0,
  AI_SHAPE_INIT(4, 1, 1280, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1280, 1280),
  1, &eltwise_44_scratch0_array, NULL)

/* Tensor #146 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_scratch0, AI_STATIC,
  146, 0x0,
  AI_SHAPE_INIT(4, 1, 1665, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1665, 1665),
  1, &conv2d_45_scratch0_array, NULL)

/* Tensor #147 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_47_scratch0, AI_STATIC,
  147, 0x0,
  AI_SHAPE_INIT(4, 1, 1280, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1280, 1280),
  1, &eltwise_47_scratch0_array, NULL)

/* Tensor #148 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_scratch0, AI_STATIC,
  148, 0x0,
  AI_SHAPE_INIT(4, 1, 11520, 1, 1), AI_STRIDE_INIT(4, 1, 1, 11520, 11520),
  1, &conv2d_48_scratch0_array, NULL)

/* Tensor #149 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_50_scratch0, AI_STATIC,
  149, 0x0,
  AI_SHAPE_INIT(4, 1, 1280, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1280, 1280),
  1, &eltwise_50_scratch0_array, NULL)

/* Tensor #150 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_51_scratch0, AI_STATIC,
  150, 0x0,
  AI_SHAPE_INIT(4, 1, 11520, 1, 1), AI_STRIDE_INIT(4, 1, 1, 11520, 11520),
  1, &conv2d_51_scratch0_array, NULL)

/* Tensor #151 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_53_scratch0, AI_STATIC,
  151, 0x0,
  AI_SHAPE_INIT(4, 1, 1280, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1280, 1280),
  1, &eltwise_53_scratch0_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_conv2d_input0_int8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_0_weights, &conv2d_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_0_layer, 0,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_0_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_2_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_2_scale, &eltwise_2_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_2_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  eltwise_2_layer, 2,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn_integer,
  &eltwise_2_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_3_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_3_weights, &conv2d_3_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_3_layer, 3,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_3_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_5_layer, AI_STATIC, 
  .groups = 32, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_5_scale, &eltwise_5_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_5_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  eltwise_5_layer, 5,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn_integer,
  &eltwise_5_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_6_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_6_weights, &conv2d_6_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_6_layer, 6,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_6_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_8_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_8_scale, &eltwise_8_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_8_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  eltwise_8_layer, 8,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn_integer,
  &eltwise_8_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_9_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_9_weights, &conv2d_9_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_9_layer, 9,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_9_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_11_layer, AI_STATIC, 
  .groups = 32, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_11_scale, &eltwise_11_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_11_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  eltwise_11_layer, 11,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn_integer,
  &eltwise_11_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_12_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_12_weights, &conv2d_12_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_12_layer, 12,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_12_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_14_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_14_scale, &eltwise_14_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_14_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  eltwise_14_layer, 14,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn_integer,
  &eltwise_14_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_15_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_15_weights, &conv2d_15_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_15_layer, 15,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_15_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_17_layer, AI_STATIC, 
  .groups = 32, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_17_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_17_scale, &eltwise_17_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_17_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  eltwise_17_layer, 17,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn_integer,
  &eltwise_17_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_18_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_18_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_18_weights, &conv2d_18_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_18_layer, 18,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_18_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_20_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_20_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_20_scale, &eltwise_20_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_20_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  eltwise_20_layer, 20,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn_integer,
  &eltwise_20_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_21_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_21_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_21_weights, &conv2d_21_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_21_layer, 21,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_21_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_23_layer, AI_STATIC, 
  .groups = 32, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_23_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_23_scale, &eltwise_23_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_23_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  eltwise_23_layer, 23,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn_integer,
  &eltwise_23_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_24_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_24_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_24_weights, &conv2d_24_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_24_layer, 24,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_24_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_26_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_26_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_26_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_26_scale, &eltwise_26_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_26_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  eltwise_26_layer, 26,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn_integer,
  &eltwise_26_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_27_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_27_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_26_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_27_weights, &conv2d_27_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_27_layer, 27,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_27_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_29_layer, AI_STATIC, 
  .groups = 92, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_29_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_29_scale, &eltwise_29_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_29_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  eltwise_29_layer, 29,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn_integer,
  &eltwise_29_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_30_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_30_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_30_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_30_weights, &conv2d_30_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_30_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_30_layer, 30,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_30_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_32_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_32_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_30_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_32_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_32_scale, &eltwise_32_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_32_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  eltwise_32_layer, 32,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn_integer,
  &eltwise_32_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_33_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_33_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_32_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_33_weights, &conv2d_33_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_33_layer, 33,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_33_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_35_layer, AI_STATIC, 
  .groups = 92, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_35_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_35_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_35_scale, &eltwise_35_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_35_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  eltwise_35_layer, 35,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn_integer,
  &eltwise_35_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_36_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_36_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_35_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_36_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_36_weights, &conv2d_36_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_36_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_36_layer, 36,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_36_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_38_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_38_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_36_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_38_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_38_scale, &eltwise_38_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_38_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  eltwise_38_layer, 38,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn_integer,
  &eltwise_38_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_39_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_39_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_38_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_39_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_39_weights, &conv2d_39_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_39_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_39_layer, 39,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_39_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_41_layer, AI_STATIC, 
  .groups = 92, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_41_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_39_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_41_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_41_scale, &eltwise_41_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_41_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  eltwise_41_layer, 41,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn_integer,
  &eltwise_41_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_42_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_42_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_41_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_42_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_42_weights, &conv2d_42_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_42_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_42_layer, 42,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_42_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_44_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_44_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_42_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_44_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_44_scale, &eltwise_44_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_44_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  eltwise_44_layer, 44,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn_integer,
  &eltwise_44_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_45_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_45_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_44_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_45_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_45_weights, &conv2d_45_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_45_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_45_layer, 45,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_45_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_47_layer, AI_STATIC, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_47_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_45_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_47_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_47_scale, &eltwise_47_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_47_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  eltwise_47_layer, 47,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn_integer,
  &eltwise_47_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_48_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_48_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_47_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_48_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_48_weights, &conv2d_48_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_48_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_48_layer, 48,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_48_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_50_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_50_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_48_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_50_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_50_scale, &eltwise_50_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_50_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  eltwise_50_layer, 50,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn_integer,
  &eltwise_50_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_51_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_51_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_50_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_51_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_51_weights, &conv2d_51_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_51_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_51_layer, 51,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_51_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_53_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_53_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_51_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_53_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_53_scale, &eltwise_53_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_53_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  eltwise_53_layer, 53,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn_integer,
  &eltwise_53_chain,
  &AI_NET_OBJ_INSTANCE, &dense_55_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_55_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_53_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_55_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_55_weights, &dense_55_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_55_layer, 55,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &dense_55_chain,
  &AI_NET_OBJ_INSTANCE, &dense_55_fmt_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_55_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_55_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_55_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_55_fmt_layer, 55,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &dense_55_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &nl_56_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_56_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_55_fmt_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_56_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_56_layer, 56,
  NL_TYPE, 0x0, NULL,
  nl, forward_sm,
  &nl_56_chain,
  &AI_NET_OBJ_INSTANCE, &nl_56_fmt_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_56_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_56_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_56_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_56_fmt_layer, 56,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &nl_56_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &nl_56_fmt_layer, AI_STATIC, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 469524, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 48024, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &serving_default_conv2d_input0_int8_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &nl_56_fmt_output),
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
    serving_default_conv2d_input0_int8_output_array.data = AI_PTR(NULL);
    serving_default_conv2d_input0_int8_output_array.data_start = AI_PTR(NULL);
    conv2d_0_output_array.data = AI_PTR(activations + 13180);
    conv2d_0_output_array.data_start = AI_PTR(activations + 13180);
    eltwise_2_output_array.data = AI_PTR(activations + 13180);
    eltwise_2_output_array.data_start = AI_PTR(activations + 13180);
    conv2d_3_output_array.data = AI_PTR(activations + 11068);
    conv2d_3_output_array.data_start = AI_PTR(activations + 11068);
    eltwise_5_output_array.data = AI_PTR(activations + 11068);
    eltwise_5_output_array.data_start = AI_PTR(activations + 11068);
    conv2d_6_output_array.data = AI_PTR(activations + 10012);
    conv2d_6_output_array.data_start = AI_PTR(activations + 10012);
    eltwise_8_output_array.data = AI_PTR(activations + 10012);
    eltwise_8_output_array.data_start = AI_PTR(activations + 10012);
    conv2d_9_output_array.data = AI_PTR(activations + 7900);
    conv2d_9_output_array.data_start = AI_PTR(activations + 7900);
    eltwise_11_output_array.data = AI_PTR(activations + 7900);
    eltwise_11_output_array.data_start = AI_PTR(activations + 7900);
    conv2d_12_output_array.data = AI_PTR(activations + 6844);
    conv2d_12_output_array.data_start = AI_PTR(activations + 6844);
    eltwise_14_output_array.data = AI_PTR(activations + 6844);
    eltwise_14_output_array.data_start = AI_PTR(activations + 6844);
    conv2d_15_output_array.data = AI_PTR(activations + 4732);
    conv2d_15_output_array.data_start = AI_PTR(activations + 4732);
    eltwise_17_output_array.data = AI_PTR(activations + 4732);
    eltwise_17_output_array.data_start = AI_PTR(activations + 4732);
    conv2d_18_output_array.data = AI_PTR(activations + 3676);
    conv2d_18_output_array.data_start = AI_PTR(activations + 3676);
    eltwise_20_output_array.data = AI_PTR(activations + 3676);
    eltwise_20_output_array.data_start = AI_PTR(activations + 3676);
    conv2d_21_output_array.data = AI_PTR(activations + 1564);
    conv2d_21_output_array.data_start = AI_PTR(activations + 1564);
    eltwise_23_output_array.data = AI_PTR(activations + 1564);
    eltwise_23_output_array.data_start = AI_PTR(activations + 1564);
    conv2d_24_output_array.data = AI_PTR(activations + 0);
    conv2d_24_output_array.data_start = AI_PTR(activations + 0);
    eltwise_26_output_array.data = AI_PTR(activations + 24472);
    eltwise_26_output_array.data_start = AI_PTR(activations + 24472);
    conv2d_27_output_array.data = AI_PTR(activations + 22908);
    conv2d_27_output_array.data_start = AI_PTR(activations + 22908);
    eltwise_29_output_array.data = AI_PTR(activations + 22908);
    eltwise_29_output_array.data_start = AI_PTR(activations + 22908);
    conv2d_30_output_array.data = AI_PTR(activations + 21344);
    conv2d_30_output_array.data_start = AI_PTR(activations + 21344);
    eltwise_32_output_array.data = AI_PTR(activations + 21344);
    eltwise_32_output_array.data_start = AI_PTR(activations + 21344);
    conv2d_33_output_array.data = AI_PTR(activations + 18216);
    conv2d_33_output_array.data_start = AI_PTR(activations + 18216);
    eltwise_35_output_array.data = AI_PTR(activations + 18216);
    eltwise_35_output_array.data_start = AI_PTR(activations + 18216);
    conv2d_36_output_array.data = AI_PTR(activations + 16652);
    conv2d_36_output_array.data_start = AI_PTR(activations + 16652);
    eltwise_38_output_array.data = AI_PTR(activations + 16652);
    eltwise_38_output_array.data_start = AI_PTR(activations + 16652);
    conv2d_39_output_array.data = AI_PTR(activations + 13524);
    conv2d_39_output_array.data_start = AI_PTR(activations + 13524);
    eltwise_41_output_array.data = AI_PTR(activations + 13524);
    eltwise_41_output_array.data_start = AI_PTR(activations + 13524);
    conv2d_42_output_array.data = AI_PTR(activations + 37076);
    conv2d_42_output_array.data_start = AI_PTR(activations + 37076);
    eltwise_44_output_array.data = AI_PTR(activations + 1280);
    eltwise_44_output_array.data_start = AI_PTR(activations + 1280);
    conv2d_45_output_array.data = AI_PTR(activations + 11140);
    conv2d_45_output_array.data_start = AI_PTR(activations + 11140);
    eltwise_47_output_array.data = AI_PTR(activations + 1280);
    eltwise_47_output_array.data_start = AI_PTR(activations + 1280);
    conv2d_48_output_array.data = AI_PTR(activations + 20992);
    conv2d_48_output_array.data_start = AI_PTR(activations + 20992);
    eltwise_50_output_array.data = AI_PTR(activations + 1280);
    eltwise_50_output_array.data_start = AI_PTR(activations + 1280);
    conv2d_51_output_array.data = AI_PTR(activations + 0);
    conv2d_51_output_array.data_start = AI_PTR(activations + 0);
    eltwise_53_output_array.data = AI_PTR(activations + 1792);
    eltwise_53_output_array.data_start = AI_PTR(activations + 1792);
    dense_55_output_array.data = AI_PTR(activations + 0);
    dense_55_output_array.data_start = AI_PTR(activations + 0);
    dense_55_fmt_output_array.data = AI_PTR(activations + 20);
    dense_55_fmt_output_array.data_start = AI_PTR(activations + 20);
    nl_56_output_array.data = AI_PTR(activations + 100);
    nl_56_output_array.data_start = AI_PTR(activations + 100);
    nl_56_fmt_output_array.data = AI_PTR(NULL);
    nl_56_fmt_output_array.data_start = AI_PTR(NULL);
    conv2d_0_scratch0_array.data = AI_PTR(activations + 10896);
    conv2d_0_scratch0_array.data_start = AI_PTR(activations + 10896);
    eltwise_2_scratch0_array.data = AI_PTR(activations + 45948);
    eltwise_2_scratch0_array.data_start = AI_PTR(activations + 45948);
    conv2d_3_scratch0_array.data = AI_PTR(activations + 45948);
    conv2d_3_scratch0_array.data_start = AI_PTR(activations + 45948);
    eltwise_5_scratch0_array.data = AI_PTR(activations + 10748);
    eltwise_5_scratch0_array.data_start = AI_PTR(activations + 10748);
    conv2d_6_scratch0_array.data = AI_PTR(activations + 46684);
    conv2d_6_scratch0_array.data_start = AI_PTR(activations + 46684);
    eltwise_8_scratch0_array.data = AI_PTR(activations + 9692);
    eltwise_8_scratch0_array.data_start = AI_PTR(activations + 9692);
    conv2d_9_scratch0_array.data = AI_PTR(activations + 45948);
    conv2d_9_scratch0_array.data_start = AI_PTR(activations + 45948);
    eltwise_11_scratch0_array.data = AI_PTR(activations + 7580);
    eltwise_11_scratch0_array.data_start = AI_PTR(activations + 7580);
    conv2d_12_scratch0_array.data = AI_PTR(activations + 46684);
    conv2d_12_scratch0_array.data_start = AI_PTR(activations + 46684);
    eltwise_14_scratch0_array.data = AI_PTR(activations + 6524);
    eltwise_14_scratch0_array.data_start = AI_PTR(activations + 6524);
    conv2d_15_scratch0_array.data = AI_PTR(activations + 45948);
    conv2d_15_scratch0_array.data_start = AI_PTR(activations + 45948);
    eltwise_17_scratch0_array.data = AI_PTR(activations + 4412);
    eltwise_17_scratch0_array.data_start = AI_PTR(activations + 4412);
    conv2d_18_scratch0_array.data = AI_PTR(activations + 46684);
    conv2d_18_scratch0_array.data_start = AI_PTR(activations + 46684);
    eltwise_20_scratch0_array.data = AI_PTR(activations + 3356);
    eltwise_20_scratch0_array.data_start = AI_PTR(activations + 3356);
    conv2d_21_scratch0_array.data = AI_PTR(activations + 45948);
    conv2d_21_scratch0_array.data_start = AI_PTR(activations + 45948);
    eltwise_23_scratch0_array.data = AI_PTR(activations + 34332);
    eltwise_23_scratch0_array.data_start = AI_PTR(activations + 34332);
    conv2d_24_scratch0_array.data = AI_PTR(activations + 34332);
    conv2d_24_scratch0_array.data_start = AI_PTR(activations + 34332);
    eltwise_26_scratch0_array.data = AI_PTR(activations + 23552);
    eltwise_26_scratch0_array.data_start = AI_PTR(activations + 23552);
    conv2d_27_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_27_scratch0_array.data_start = AI_PTR(activations + 0);
    eltwise_29_scratch0_array.data = AI_PTR(activations + 0);
    eltwise_29_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_30_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_30_scratch0_array.data_start = AI_PTR(activations + 0);
    eltwise_32_scratch0_array.data = AI_PTR(activations + 0);
    eltwise_32_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_33_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_33_scratch0_array.data_start = AI_PTR(activations + 0);
    eltwise_35_scratch0_array.data = AI_PTR(activations + 0);
    eltwise_35_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_36_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_36_scratch0_array.data_start = AI_PTR(activations + 0);
    eltwise_38_scratch0_array.data = AI_PTR(activations + 0);
    eltwise_38_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_39_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_39_scratch0_array.data_start = AI_PTR(activations + 0);
    eltwise_41_scratch0_array.data = AI_PTR(activations + 0);
    eltwise_41_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_42_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_42_scratch0_array.data_start = AI_PTR(activations + 0);
    eltwise_44_scratch0_array.data = AI_PTR(activations + 0);
    eltwise_44_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_45_scratch0_array.data = AI_PTR(activations + 9472);
    conv2d_45_scratch0_array.data_start = AI_PTR(activations + 9472);
    eltwise_47_scratch0_array.data = AI_PTR(activations + 0);
    eltwise_47_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_48_scratch0_array.data = AI_PTR(activations + 9472);
    conv2d_48_scratch0_array.data_start = AI_PTR(activations + 9472);
    eltwise_50_scratch0_array.data = AI_PTR(activations + 0);
    eltwise_50_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_51_scratch0_array.data = AI_PTR(activations + 3328);
    conv2d_51_scratch0_array.data_start = AI_PTR(activations + 3328);
    eltwise_53_scratch0_array.data = AI_PTR(activations + 512);
    eltwise_53_scratch0_array.data_start = AI_PTR(activations + 512);
    
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
    conv2d_0_bias_array.data = AI_PTR(weights + 864);
    conv2d_0_bias_array.data_start = AI_PTR(weights + 864);
    eltwise_2_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_2_scale_array.data = AI_PTR(weights + 992);
    eltwise_2_scale_array.data_start = AI_PTR(weights + 992);
    eltwise_2_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_2_bias_array.data = AI_PTR(weights + 1024);
    eltwise_2_bias_array.data_start = AI_PTR(weights + 1024);
    conv2d_3_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_weights_array.data = AI_PTR(weights + 1056);
    conv2d_3_weights_array.data_start = AI_PTR(weights + 1056);
    conv2d_3_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_bias_array.data = AI_PTR(weights + 1344);
    conv2d_3_bias_array.data_start = AI_PTR(weights + 1344);
    eltwise_5_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_5_scale_array.data = AI_PTR(weights + 1472);
    eltwise_5_scale_array.data_start = AI_PTR(weights + 1472);
    eltwise_5_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_5_bias_array.data = AI_PTR(weights + 1504);
    eltwise_5_bias_array.data_start = AI_PTR(weights + 1504);
    conv2d_6_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_weights_array.data = AI_PTR(weights + 1536);
    conv2d_6_weights_array.data_start = AI_PTR(weights + 1536);
    conv2d_6_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_bias_array.data = AI_PTR(weights + 2560);
    conv2d_6_bias_array.data_start = AI_PTR(weights + 2560);
    eltwise_8_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_8_scale_array.data = AI_PTR(weights + 2688);
    eltwise_8_scale_array.data_start = AI_PTR(weights + 2688);
    eltwise_8_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_8_bias_array.data = AI_PTR(weights + 2720);
    eltwise_8_bias_array.data_start = AI_PTR(weights + 2720);
    conv2d_9_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_weights_array.data = AI_PTR(weights + 2752);
    conv2d_9_weights_array.data_start = AI_PTR(weights + 2752);
    conv2d_9_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_bias_array.data = AI_PTR(weights + 3040);
    conv2d_9_bias_array.data_start = AI_PTR(weights + 3040);
    eltwise_11_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_11_scale_array.data = AI_PTR(weights + 3168);
    eltwise_11_scale_array.data_start = AI_PTR(weights + 3168);
    eltwise_11_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_11_bias_array.data = AI_PTR(weights + 3200);
    eltwise_11_bias_array.data_start = AI_PTR(weights + 3200);
    conv2d_12_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_12_weights_array.data = AI_PTR(weights + 3232);
    conv2d_12_weights_array.data_start = AI_PTR(weights + 3232);
    conv2d_12_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_12_bias_array.data = AI_PTR(weights + 4256);
    conv2d_12_bias_array.data_start = AI_PTR(weights + 4256);
    eltwise_14_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_14_scale_array.data = AI_PTR(weights + 4384);
    eltwise_14_scale_array.data_start = AI_PTR(weights + 4384);
    eltwise_14_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_14_bias_array.data = AI_PTR(weights + 4416);
    eltwise_14_bias_array.data_start = AI_PTR(weights + 4416);
    conv2d_15_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_weights_array.data = AI_PTR(weights + 4448);
    conv2d_15_weights_array.data_start = AI_PTR(weights + 4448);
    conv2d_15_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_bias_array.data = AI_PTR(weights + 4736);
    conv2d_15_bias_array.data_start = AI_PTR(weights + 4736);
    eltwise_17_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_17_scale_array.data = AI_PTR(weights + 4864);
    eltwise_17_scale_array.data_start = AI_PTR(weights + 4864);
    eltwise_17_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_17_bias_array.data = AI_PTR(weights + 4896);
    eltwise_17_bias_array.data_start = AI_PTR(weights + 4896);
    conv2d_18_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_weights_array.data = AI_PTR(weights + 4928);
    conv2d_18_weights_array.data_start = AI_PTR(weights + 4928);
    conv2d_18_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_bias_array.data = AI_PTR(weights + 5952);
    conv2d_18_bias_array.data_start = AI_PTR(weights + 5952);
    eltwise_20_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_20_scale_array.data = AI_PTR(weights + 6080);
    eltwise_20_scale_array.data_start = AI_PTR(weights + 6080);
    eltwise_20_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_20_bias_array.data = AI_PTR(weights + 6112);
    eltwise_20_bias_array.data_start = AI_PTR(weights + 6112);
    conv2d_21_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_weights_array.data = AI_PTR(weights + 6144);
    conv2d_21_weights_array.data_start = AI_PTR(weights + 6144);
    conv2d_21_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_bias_array.data = AI_PTR(weights + 6432);
    conv2d_21_bias_array.data_start = AI_PTR(weights + 6432);
    eltwise_23_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_23_scale_array.data = AI_PTR(weights + 6560);
    eltwise_23_scale_array.data_start = AI_PTR(weights + 6560);
    eltwise_23_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_23_bias_array.data = AI_PTR(weights + 6592);
    eltwise_23_bias_array.data_start = AI_PTR(weights + 6592);
    conv2d_24_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_24_weights_array.data = AI_PTR(weights + 6624);
    conv2d_24_weights_array.data_start = AI_PTR(weights + 6624);
    conv2d_24_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_24_bias_array.data = AI_PTR(weights + 33120);
    conv2d_24_bias_array.data_start = AI_PTR(weights + 33120);
    eltwise_26_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_26_scale_array.data = AI_PTR(weights + 33488);
    eltwise_26_scale_array.data_start = AI_PTR(weights + 33488);
    eltwise_26_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_26_bias_array.data = AI_PTR(weights + 33580);
    eltwise_26_bias_array.data_start = AI_PTR(weights + 33580);
    conv2d_27_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_weights_array.data = AI_PTR(weights + 33672);
    conv2d_27_weights_array.data_start = AI_PTR(weights + 33672);
    conv2d_27_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_bias_array.data = AI_PTR(weights + 33764);
    conv2d_27_bias_array.data_start = AI_PTR(weights + 33764);
    eltwise_29_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_29_scale_array.data = AI_PTR(weights + 34132);
    eltwise_29_scale_array.data_start = AI_PTR(weights + 34132);
    eltwise_29_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_29_bias_array.data = AI_PTR(weights + 34224);
    eltwise_29_bias_array.data_start = AI_PTR(weights + 34224);
    conv2d_30_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_30_weights_array.data = AI_PTR(weights + 34316);
    conv2d_30_weights_array.data_start = AI_PTR(weights + 34316);
    conv2d_30_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_30_bias_array.data = AI_PTR(weights + 42780);
    conv2d_30_bias_array.data_start = AI_PTR(weights + 42780);
    eltwise_32_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_32_scale_array.data = AI_PTR(weights + 43148);
    eltwise_32_scale_array.data_start = AI_PTR(weights + 43148);
    eltwise_32_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_32_bias_array.data = AI_PTR(weights + 43240);
    eltwise_32_bias_array.data_start = AI_PTR(weights + 43240);
    conv2d_33_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_33_weights_array.data = AI_PTR(weights + 43332);
    conv2d_33_weights_array.data_start = AI_PTR(weights + 43332);
    conv2d_33_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_33_bias_array.data = AI_PTR(weights + 44160);
    conv2d_33_bias_array.data_start = AI_PTR(weights + 44160);
    eltwise_35_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_35_scale_array.data = AI_PTR(weights + 44528);
    eltwise_35_scale_array.data_start = AI_PTR(weights + 44528);
    eltwise_35_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_35_bias_array.data = AI_PTR(weights + 44620);
    eltwise_35_bias_array.data_start = AI_PTR(weights + 44620);
    conv2d_36_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_36_weights_array.data = AI_PTR(weights + 44712);
    conv2d_36_weights_array.data_start = AI_PTR(weights + 44712);
    conv2d_36_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_36_bias_array.data = AI_PTR(weights + 53176);
    conv2d_36_bias_array.data_start = AI_PTR(weights + 53176);
    eltwise_38_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_38_scale_array.data = AI_PTR(weights + 53544);
    eltwise_38_scale_array.data_start = AI_PTR(weights + 53544);
    eltwise_38_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_38_bias_array.data = AI_PTR(weights + 53636);
    eltwise_38_bias_array.data_start = AI_PTR(weights + 53636);
    conv2d_39_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_39_weights_array.data = AI_PTR(weights + 53728);
    conv2d_39_weights_array.data_start = AI_PTR(weights + 53728);
    conv2d_39_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_39_bias_array.data = AI_PTR(weights + 54556);
    conv2d_39_bias_array.data_start = AI_PTR(weights + 54556);
    eltwise_41_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_41_scale_array.data = AI_PTR(weights + 54924);
    eltwise_41_scale_array.data_start = AI_PTR(weights + 54924);
    eltwise_41_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_41_bias_array.data = AI_PTR(weights + 55016);
    eltwise_41_bias_array.data_start = AI_PTR(weights + 55016);
    conv2d_42_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_42_weights_array.data = AI_PTR(weights + 55108);
    conv2d_42_weights_array.data_start = AI_PTR(weights + 55108);
    conv2d_42_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_42_bias_array.data = AI_PTR(weights + 161092);
    conv2d_42_bias_array.data_start = AI_PTR(weights + 161092);
    eltwise_44_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_44_scale_array.data = AI_PTR(weights + 161604);
    eltwise_44_scale_array.data_start = AI_PTR(weights + 161604);
    eltwise_44_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_44_bias_array.data = AI_PTR(weights + 161732);
    eltwise_44_bias_array.data_start = AI_PTR(weights + 161732);
    conv2d_45_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_45_weights_array.data = AI_PTR(weights + 161860);
    conv2d_45_weights_array.data_start = AI_PTR(weights + 161860);
    conv2d_45_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_45_bias_array.data = AI_PTR(weights + 161988);
    conv2d_45_bias_array.data_start = AI_PTR(weights + 161988);
    eltwise_47_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_47_scale_array.data = AI_PTR(weights + 162500);
    eltwise_47_scale_array.data_start = AI_PTR(weights + 162500);
    eltwise_47_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_47_bias_array.data = AI_PTR(weights + 162628);
    eltwise_47_bias_array.data_start = AI_PTR(weights + 162628);
    conv2d_48_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_48_weights_array.data = AI_PTR(weights + 162756);
    conv2d_48_weights_array.data_start = AI_PTR(weights + 162756);
    conv2d_48_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_48_bias_array.data = AI_PTR(weights + 310212);
    conv2d_48_bias_array.data_start = AI_PTR(weights + 310212);
    eltwise_50_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_50_scale_array.data = AI_PTR(weights + 310724);
    eltwise_50_scale_array.data_start = AI_PTR(weights + 310724);
    eltwise_50_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_50_bias_array.data = AI_PTR(weights + 310852);
    eltwise_50_bias_array.data_start = AI_PTR(weights + 310852);
    conv2d_51_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_51_weights_array.data = AI_PTR(weights + 310980);
    conv2d_51_weights_array.data_start = AI_PTR(weights + 310980);
    conv2d_51_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_51_bias_array.data = AI_PTR(weights + 458436);
    conv2d_51_bias_array.data_start = AI_PTR(weights + 458436);
    eltwise_53_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_53_scale_array.data = AI_PTR(weights + 458948);
    eltwise_53_scale_array.data_start = AI_PTR(weights + 458948);
    eltwise_53_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_53_bias_array.data = AI_PTR(weights + 459076);
    eltwise_53_bias_array.data_start = AI_PTR(weights + 459076);
    dense_55_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_55_weights_array.data = AI_PTR(weights + 459204);
    dense_55_weights_array.data_start = AI_PTR(weights + 459204);
    dense_55_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_55_bias_array.data = AI_PTR(weights + 469444);
    dense_55_bias_array.data_start = AI_PTR(weights + 469444);
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
      
      .n_macc            = 27371192,
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

