/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Tue Nov  9 21:24:11 2021
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
#define AI_NETWORK_MODEL_SIGNATURE     "c9bc73e7988f0be1d242834dbcb101c6"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Tue Nov  9 21:24:11 2021"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array conv2d_15_input_output_array;   /* Array #0 */
AI_STATIC ai_array conv2d_0_output_array;   /* Array #1 */
AI_STATIC ai_array eltwise_2_output_array;   /* Array #2 */
AI_STATIC ai_array conv2d_3_output_array;   /* Array #3 */
AI_STATIC ai_array eltwise_5_output_array;   /* Array #4 */
AI_STATIC ai_array pool_6_output_array;   /* Array #5 */
AI_STATIC ai_array conv2d_7_output_array;   /* Array #6 */
AI_STATIC ai_array eltwise_9_output_array;   /* Array #7 */
AI_STATIC ai_array conv2d_10_output_array;   /* Array #8 */
AI_STATIC ai_array eltwise_12_output_array;   /* Array #9 */
AI_STATIC ai_array pool_13_output_array;   /* Array #10 */
AI_STATIC ai_array conv2d_14_output_array;   /* Array #11 */
AI_STATIC ai_array eltwise_16_output_array;   /* Array #12 */
AI_STATIC ai_array conv2d_17_output_array;   /* Array #13 */
AI_STATIC ai_array eltwise_19_output_array;   /* Array #14 */
AI_STATIC ai_array pool_20_output_array;   /* Array #15 */
AI_STATIC ai_array dense_22_output_array;   /* Array #16 */
AI_STATIC ai_array eltwise_24_output_array;   /* Array #17 */
AI_STATIC ai_array dense_25_output_array;   /* Array #18 */
AI_STATIC ai_array dense_25_fmt_output_array;   /* Array #19 */
AI_STATIC ai_array nl_26_output_array;   /* Array #20 */
AI_STATIC ai_array nl_26_fmt_output_array;   /* Array #21 */
AI_STATIC ai_array conv2d_0_weights_array;   /* Array #22 */
AI_STATIC ai_array conv2d_0_bias_array;   /* Array #23 */
AI_STATIC ai_array eltwise_2_scale_array;   /* Array #24 */
AI_STATIC ai_array eltwise_2_bias_array;   /* Array #25 */
AI_STATIC ai_array conv2d_3_weights_array;   /* Array #26 */
AI_STATIC ai_array conv2d_3_bias_array;   /* Array #27 */
AI_STATIC ai_array eltwise_5_scale_array;   /* Array #28 */
AI_STATIC ai_array eltwise_5_bias_array;   /* Array #29 */
AI_STATIC ai_array conv2d_7_weights_array;   /* Array #30 */
AI_STATIC ai_array conv2d_7_bias_array;   /* Array #31 */
AI_STATIC ai_array eltwise_9_scale_array;   /* Array #32 */
AI_STATIC ai_array eltwise_9_bias_array;   /* Array #33 */
AI_STATIC ai_array conv2d_10_weights_array;   /* Array #34 */
AI_STATIC ai_array conv2d_10_bias_array;   /* Array #35 */
AI_STATIC ai_array eltwise_12_scale_array;   /* Array #36 */
AI_STATIC ai_array eltwise_12_bias_array;   /* Array #37 */
AI_STATIC ai_array conv2d_14_weights_array;   /* Array #38 */
AI_STATIC ai_array conv2d_14_bias_array;   /* Array #39 */
AI_STATIC ai_array eltwise_16_scale_array;   /* Array #40 */
AI_STATIC ai_array eltwise_16_bias_array;   /* Array #41 */
AI_STATIC ai_array conv2d_17_weights_array;   /* Array #42 */
AI_STATIC ai_array conv2d_17_bias_array;   /* Array #43 */
AI_STATIC ai_array eltwise_19_scale_array;   /* Array #44 */
AI_STATIC ai_array eltwise_19_bias_array;   /* Array #45 */
AI_STATIC ai_array dense_22_weights_array;   /* Array #46 */
AI_STATIC ai_array dense_22_bias_array;   /* Array #47 */
AI_STATIC ai_array eltwise_24_scale_array;   /* Array #48 */
AI_STATIC ai_array eltwise_24_bias_array;   /* Array #49 */
AI_STATIC ai_array dense_25_weights_array;   /* Array #50 */
AI_STATIC ai_array dense_25_bias_array;   /* Array #51 */
AI_STATIC ai_array conv2d_0_scratch0_array;   /* Array #52 */
AI_STATIC ai_array eltwise_2_scratch0_array;   /* Array #53 */
AI_STATIC ai_array conv2d_3_scratch0_array;   /* Array #54 */
AI_STATIC ai_array eltwise_5_scratch0_array;   /* Array #55 */
AI_STATIC ai_array conv2d_7_scratch0_array;   /* Array #56 */
AI_STATIC ai_array eltwise_9_scratch0_array;   /* Array #57 */
AI_STATIC ai_array conv2d_10_scratch0_array;   /* Array #58 */
AI_STATIC ai_array eltwise_12_scratch0_array;   /* Array #59 */
AI_STATIC ai_array conv2d_14_scratch0_array;   /* Array #60 */
AI_STATIC ai_array eltwise_16_scratch0_array;   /* Array #61 */
AI_STATIC ai_array conv2d_17_scratch0_array;   /* Array #62 */
AI_STATIC ai_array eltwise_19_scratch0_array;   /* Array #63 */
AI_STATIC ai_array eltwise_24_scratch0_array;   /* Array #64 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor conv2d_15_input_output;   /* Tensor #0 */
AI_STATIC ai_tensor conv2d_0_output;   /* Tensor #1 */
AI_STATIC ai_tensor eltwise_2_output;   /* Tensor #2 */
AI_STATIC ai_tensor conv2d_3_output;   /* Tensor #3 */
AI_STATIC ai_tensor eltwise_5_output;   /* Tensor #4 */
AI_STATIC ai_tensor pool_6_output;   /* Tensor #5 */
AI_STATIC ai_tensor conv2d_7_output;   /* Tensor #6 */
AI_STATIC ai_tensor eltwise_9_output;   /* Tensor #7 */
AI_STATIC ai_tensor conv2d_10_output;   /* Tensor #8 */
AI_STATIC ai_tensor eltwise_12_output;   /* Tensor #9 */
AI_STATIC ai_tensor pool_13_output;   /* Tensor #10 */
AI_STATIC ai_tensor conv2d_14_output;   /* Tensor #11 */
AI_STATIC ai_tensor eltwise_16_output;   /* Tensor #12 */
AI_STATIC ai_tensor conv2d_17_output;   /* Tensor #13 */
AI_STATIC ai_tensor eltwise_19_output;   /* Tensor #14 */
AI_STATIC ai_tensor pool_20_output;   /* Tensor #15 */
AI_STATIC ai_tensor pool_20_output0;   /* Tensor #16 */
AI_STATIC ai_tensor dense_22_output;   /* Tensor #17 */
AI_STATIC ai_tensor eltwise_24_output;   /* Tensor #18 */
AI_STATIC ai_tensor dense_25_output;   /* Tensor #19 */
AI_STATIC ai_tensor dense_25_fmt_output;   /* Tensor #20 */
AI_STATIC ai_tensor nl_26_output;   /* Tensor #21 */
AI_STATIC ai_tensor nl_26_fmt_output;   /* Tensor #22 */
AI_STATIC ai_tensor conv2d_0_weights;   /* Tensor #23 */
AI_STATIC ai_tensor conv2d_0_bias;   /* Tensor #24 */
AI_STATIC ai_tensor eltwise_2_scale;   /* Tensor #25 */
AI_STATIC ai_tensor eltwise_2_bias;   /* Tensor #26 */
AI_STATIC ai_tensor conv2d_3_weights;   /* Tensor #27 */
AI_STATIC ai_tensor conv2d_3_bias;   /* Tensor #28 */
AI_STATIC ai_tensor eltwise_5_scale;   /* Tensor #29 */
AI_STATIC ai_tensor eltwise_5_bias;   /* Tensor #30 */
AI_STATIC ai_tensor conv2d_7_weights;   /* Tensor #31 */
AI_STATIC ai_tensor conv2d_7_bias;   /* Tensor #32 */
AI_STATIC ai_tensor eltwise_9_scale;   /* Tensor #33 */
AI_STATIC ai_tensor eltwise_9_bias;   /* Tensor #34 */
AI_STATIC ai_tensor conv2d_10_weights;   /* Tensor #35 */
AI_STATIC ai_tensor conv2d_10_bias;   /* Tensor #36 */
AI_STATIC ai_tensor eltwise_12_scale;   /* Tensor #37 */
AI_STATIC ai_tensor eltwise_12_bias;   /* Tensor #38 */
AI_STATIC ai_tensor conv2d_14_weights;   /* Tensor #39 */
AI_STATIC ai_tensor conv2d_14_bias;   /* Tensor #40 */
AI_STATIC ai_tensor eltwise_16_scale;   /* Tensor #41 */
AI_STATIC ai_tensor eltwise_16_bias;   /* Tensor #42 */
AI_STATIC ai_tensor conv2d_17_weights;   /* Tensor #43 */
AI_STATIC ai_tensor conv2d_17_bias;   /* Tensor #44 */
AI_STATIC ai_tensor eltwise_19_scale;   /* Tensor #45 */
AI_STATIC ai_tensor eltwise_19_bias;   /* Tensor #46 */
AI_STATIC ai_tensor dense_22_weights;   /* Tensor #47 */
AI_STATIC ai_tensor dense_22_bias;   /* Tensor #48 */
AI_STATIC ai_tensor eltwise_24_scale;   /* Tensor #49 */
AI_STATIC ai_tensor eltwise_24_bias;   /* Tensor #50 */
AI_STATIC ai_tensor dense_25_weights;   /* Tensor #51 */
AI_STATIC ai_tensor dense_25_bias;   /* Tensor #52 */
AI_STATIC ai_tensor conv2d_0_scratch0;   /* Tensor #53 */
AI_STATIC ai_tensor eltwise_2_scratch0;   /* Tensor #54 */
AI_STATIC ai_tensor conv2d_3_scratch0;   /* Tensor #55 */
AI_STATIC ai_tensor eltwise_5_scratch0;   /* Tensor #56 */
AI_STATIC ai_tensor conv2d_7_scratch0;   /* Tensor #57 */
AI_STATIC ai_tensor eltwise_9_scratch0;   /* Tensor #58 */
AI_STATIC ai_tensor conv2d_10_scratch0;   /* Tensor #59 */
AI_STATIC ai_tensor eltwise_12_scratch0;   /* Tensor #60 */
AI_STATIC ai_tensor conv2d_14_scratch0;   /* Tensor #61 */
AI_STATIC ai_tensor eltwise_16_scratch0;   /* Tensor #62 */
AI_STATIC ai_tensor conv2d_17_scratch0;   /* Tensor #63 */
AI_STATIC ai_tensor eltwise_19_scratch0;   /* Tensor #64 */
AI_STATIC ai_tensor eltwise_24_scratch0;   /* Tensor #65 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conv2d_0_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain eltwise_2_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain conv2d_3_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain eltwise_5_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain pool_6_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain conv2d_7_chain;   /* Chain #5 */
AI_STATIC_CONST ai_tensor_chain eltwise_9_chain;   /* Chain #6 */
AI_STATIC_CONST ai_tensor_chain conv2d_10_chain;   /* Chain #7 */
AI_STATIC_CONST ai_tensor_chain eltwise_12_chain;   /* Chain #8 */
AI_STATIC_CONST ai_tensor_chain pool_13_chain;   /* Chain #9 */
AI_STATIC_CONST ai_tensor_chain conv2d_14_chain;   /* Chain #10 */
AI_STATIC_CONST ai_tensor_chain eltwise_16_chain;   /* Chain #11 */
AI_STATIC_CONST ai_tensor_chain conv2d_17_chain;   /* Chain #12 */
AI_STATIC_CONST ai_tensor_chain eltwise_19_chain;   /* Chain #13 */
AI_STATIC_CONST ai_tensor_chain pool_20_chain;   /* Chain #14 */
AI_STATIC_CONST ai_tensor_chain dense_22_chain;   /* Chain #15 */
AI_STATIC_CONST ai_tensor_chain eltwise_24_chain;   /* Chain #16 */
AI_STATIC_CONST ai_tensor_chain dense_25_chain;   /* Chain #17 */
AI_STATIC_CONST ai_tensor_chain dense_25_fmt_chain;   /* Chain #18 */
AI_STATIC_CONST ai_tensor_chain nl_26_chain;   /* Chain #19 */
AI_STATIC_CONST ai_tensor_chain nl_26_fmt_chain;   /* Chain #20 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_conv2d conv2d_0_layer; /* Layer #0 */
AI_STATIC ai_layer_bn eltwise_2_layer; /* Layer #1 */
AI_STATIC ai_layer_conv2d conv2d_3_layer; /* Layer #2 */
AI_STATIC ai_layer_bn eltwise_5_layer; /* Layer #3 */
AI_STATIC ai_layer_pool pool_6_layer; /* Layer #4 */
AI_STATIC ai_layer_conv2d conv2d_7_layer; /* Layer #5 */
AI_STATIC ai_layer_bn eltwise_9_layer; /* Layer #6 */
AI_STATIC ai_layer_conv2d conv2d_10_layer; /* Layer #7 */
AI_STATIC ai_layer_bn eltwise_12_layer; /* Layer #8 */
AI_STATIC ai_layer_pool pool_13_layer; /* Layer #9 */
AI_STATIC ai_layer_conv2d conv2d_14_layer; /* Layer #10 */
AI_STATIC ai_layer_bn eltwise_16_layer; /* Layer #11 */
AI_STATIC ai_layer_conv2d conv2d_17_layer; /* Layer #12 */
AI_STATIC ai_layer_bn eltwise_19_layer; /* Layer #13 */
AI_STATIC ai_layer_pool pool_20_layer; /* Layer #14 */
AI_STATIC ai_layer_dense dense_22_layer; /* Layer #15 */
AI_STATIC ai_layer_bn eltwise_24_layer; /* Layer #16 */
AI_STATIC ai_layer_dense dense_25_layer; /* Layer #17 */
AI_STATIC ai_layer_nl dense_25_fmt_layer; /* Layer #18 */
AI_STATIC ai_layer_nl nl_26_layer; /* Layer #19 */
AI_STATIC ai_layer_nl nl_26_fmt_layer; /* Layer #20 */




/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_input_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
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
  pool_6_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_9_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_12_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  pool_13_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_16_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_19_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  pool_20_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  dense_22_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_24_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  dense_25_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  dense_25_fmt_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  nl_26_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  nl_26_fmt_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 10, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_2_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_2_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_5_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_5_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_9_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 64, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_9_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 64, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_12_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 64, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_12_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 64, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_16_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 64, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_16_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 64, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_19_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 64, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_19_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 64, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  dense_22_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 131072, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  dense_22_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_24_scale_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_24_bias_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  dense_25_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1280, AI_STATIC)

/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  dense_25_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 10, AI_STATIC)

/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2284, AI_STATIC)

/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_2_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 320, AI_STATIC)

/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6720, AI_STATIC)

/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_5_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 320, AI_STATIC)

/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7168, AI_STATIC)

/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_9_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 640, AI_STATIC)

/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8320, AI_STATIC)

/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_12_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 640, AI_STATIC)

/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8320, AI_STATIC)

/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_16_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 640, AI_STATIC)

/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8320, AI_STATIC)

/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_19_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 640, AI_STATIC)

/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_24_scratch0_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 1280, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_input_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012728232890367508f),
    AI_PACK_INTQ_ZP(-95)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_0_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01711316965520382f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_2_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10393621772527695f),
    AI_PACK_INTQ_ZP(-109)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09104610234498978f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_5_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10790013521909714f),
    AI_PACK_INTQ_ZP(-119)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(pool_6_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10790013521909714f),
    AI_PACK_INTQ_ZP(-119)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09401364624500275f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_9_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08383120596408844f),
    AI_PACK_INTQ_ZP(-119)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06519805639982224f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_12_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09555831551551819f),
    AI_PACK_INTQ_ZP(-119)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(pool_13_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09555831551551819f),
    AI_PACK_INTQ_ZP(-119)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08733012527227402f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_16_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.078162282705307f),
    AI_PACK_INTQ_ZP(-116)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04730865731835365f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_19_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06381434202194214f),
    AI_PACK_INTQ_ZP(-115)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(pool_20_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06381434202194214f),
    AI_PACK_INTQ_ZP(-115)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_22_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10943429172039032f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_24_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0263995248824358f),
    AI_PACK_INTQ_ZP(-83)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_25_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11216777563095093f),
    AI_PACK_INTQ_ZP(-53)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_26_fmt_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_0_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001302352175116539f, 0.002054025884717703f, 0.002622957807034254f, 0.004559637513011694f, 0.0037692764308303595f, 0.0019298364641144872f, 0.003030078485608101f, 0.0012034508399665356f, 0.0026912849862128496f, 0.0016295480309054255f, 0.001815826166421175f, 0.001676645944826305f, 0.002702560042962432f, 0.0025958004407584667f, 0.002227573189884424f, 0.002647628542035818f, 0.0017688695807009935f, 0.0022512704599648714f, 0.0033386650029569864f, 0.0016919943736866117f, 0.001171656884253025f, 0.0018301275558769703f, 0.0018347043078392744f, 0.0030147703364491463f, 0.0024155420251190662f, 0.0014702907064929605f, 0.0022196327336132526f, 0.0025983101222664118f, 0.0036514531821012497f, 0.0032374493312090635f, 0.0017378453630954027f, 0.0038991589099168777f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_0_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.6576641428400762e-05f, 2.6144120056414977e-05f, 3.338561873533763e-05f, 5.8036126574734226e-05f, 4.797622750629671e-05f, 2.4563407350797206e-05f, 3.8567544834222645e-05f, 1.5317802535719238e-05f, 3.4255303035024554e-05f, 2.0741266780532897e-05f, 2.31122576224152e-05f, 2.1340740204323083e-05f, 3.439881402300671e-05f, 3.3039952541003004e-05f, 2.8353069865261205e-05f, 3.369963087607175e-05f, 2.251458317914512e-05f, 2.865469468815718e-05f, 4.249530684319325e-05f, 2.1536097847274505e-05f, 1.4913121958670672e-05f, 2.3294289348996244e-05f, 2.3352544303634204e-05f, 3.837269832729362e-05f, 3.074558117077686e-05f, 1.871420317911543e-05f, 2.825200317602139e-05f, 3.3071897632908076e-05f, 4.64765471406281e-05f, 4.1207007598131895e-05f, 2.2119700588518754e-05f, 4.962940147379413e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_2_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2215064913034439f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_2_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.015316205099225044f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0011349163250997663f, 0.0020870198495686054f, 0.0014049921883270144f, 0.0015224831877276301f, 0.0012250852305442095f, 0.0015875777462497354f, 0.0017104344442486763f, 0.0022758739069104195f, 0.0017178141279146075f, 0.0013625023420900106f, 0.0013797612627968192f, 0.0014257573056966066f, 0.0013387355720624328f, 0.0013308667112141848f, 0.002064343309029937f, 0.0018474083626642823f, 0.0014760512858629227f, 0.0012079710140824318f, 0.0019419296877458692f, 0.0013322675367817283f, 0.001382331014610827f, 0.0022545019164681435f, 0.0017940885154530406f, 0.0018176122102886438f, 0.0013959439238533378f, 0.0018030169885605574f, 0.0015744511038064957f, 0.0019549590069800615f, 0.0018727132119238377f, 0.0010887021198868752f, 0.002061693463474512f, 0.003051188075914979f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #25 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00011795890895882621f, 0.00021691694564651698f, 0.00014602957526221871f, 0.000158241149620153f, 0.00012733072799164802f, 0.00016500682977493852f, 0.00017777609173208475f, 0.00023654573305975646f, 0.00017854310863185674f, 0.0001416133454767987f, 0.0001434071600669995f, 0.00014818782801739872f, 0.00013914311421103776f, 0.00013832525291945785f, 0.0002145600301446393f, 0.00019201263785362244f, 0.00015341518155764788f, 0.00012555194552987814f, 0.00020183682499919087f, 0.00013847084483131766f, 0.00014367426047101617f, 0.00023432439775206149f, 0.00018647077376954257f, 0.0001889157429104671f, 0.00014508912863675505f, 0.00018739876395557076f, 0.00016364248585887253f, 0.00020319104078225791f, 0.000194642721908167f, 0.00011315558367641643f, 0.00021428462059702724f, 0.0003171289572492242f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #26 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_5_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.021511858329176903f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #27 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_5_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007394382264465094f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #28 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001260350807569921f, 0.0011461806716397405f, 0.0011732029961422086f, 0.0015076634008437395f, 0.0010162235703319311f, 0.0011843745596706867f, 0.0014561944408342242f, 0.0011129295453429222f, 0.001278395066037774f, 0.0011586998589336872f, 0.0010014665313065052f, 0.0011728234821930528f, 0.0011811454314738512f, 0.001362059498205781f, 0.0014131347415968776f, 0.0011907023144885898f, 0.0011558461701497436f, 0.0010325416224077344f, 0.0017184383468702435f, 0.0012431005015969276f, 0.0010385893983766437f, 0.0014833471504971385f, 0.0014576426474377513f, 0.0012130294926464558f, 0.001282135141082108f, 0.001098735723644495f, 0.0019649923779070377f, 0.0011698195012286305f, 0.0015267609851434827f, 0.0012527643702924252f, 0.001218404620885849f, 0.0019159693038091063f, 0.0011519769905135036f, 0.0012169061228632927f, 0.0011341637000441551f, 0.0011368290288373828f, 0.0013278197729960084f, 0.0016738410340622067f, 0.0010878376197069883f, 0.0015630228444933891f, 0.0011016210773959756f, 0.001473241369239986f, 0.0010248854523524642f, 0.0012788408203050494f, 0.001170179690234363f, 0.0011586633045226336f, 0.00139666220638901f, 0.0013067522086203098f, 0.001374529441818595f, 0.0013410324463620782f, 0.0011960777919739485f, 0.0011850874871015549f, 0.001516424585133791f, 0.0012815732043236494f, 0.001179484068416059f, 0.0012264881515875459f, 0.0010633062338456511f, 0.0011416093911975622f, 0.0012193381553515792f, 0.0017423550598323345f, 0.0011736741289496422f, 0.0012037117267027497f, 0.0010617492953315377f, 0.0011152770603075624f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00013599202793557197f, 0.0001236730458913371f, 0.00012658875493798405f, 0.00016267708269879222f, 0.00010965066030621529f, 0.00012779417738784105f, 0.00015712357708252966f, 0.00012008524936391041f, 0.0001379390014335513f, 0.00012502387107815593f, 0.00010805837519001216f, 0.00012654780584853142f, 0.00012744574632961303f, 0.00014696639846079051f, 0.00015247742703650147f, 0.0001284769386984408f, 0.0001247159525519237f, 0.00011141138384118676f, 0.00018541973258834332f, 0.0001341307070106268f, 0.00011206393537577242f, 0.00016005335783120245f, 0.00015727983554825187f, 0.0001308860519202426f, 0.00013834255514666438f, 0.00011855373304570094f, 0.00021202294738031924f, 0.00012622367648873478f, 0.00016473772120662034f, 0.00013517343904823065f, 0.00013146601850166917f, 0.00020673334074672312f, 0.00012429847265593708f, 0.00013130433217156678f, 0.0001223764120368287f, 0.0001226640015374869f, 0.00014327192911878228f, 0.00018060767615679651f, 0.00011737782915588468f, 0.0001686503819655627f, 0.00011886506399605423f, 0.00015896293916739523f, 0.00011058527888962999f, 0.00013798709551338106f, 0.00012626254465430975f, 0.00012501992750912905f, 0.0001507000415585935f, 0.00014099874533712864f, 0.000148311912198551f, 0.00014469758025370538f, 0.00012905694893561304f, 0.0001278710988117382f, 0.00016362241876777261f, 0.00013828191731590778f, 0.00012726649583783f, 0.00013233823119662702f, 0.00011473088670754805f, 0.0001231798087246716f, 0.00013156674685887992f, 0.00018800034013111144f, 0.00012663959932979196f, 0.00012988066009711474f, 0.00011456289212219417f, 0.00012033854727633297f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #30 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_9_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01288293395191431f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #31 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_9_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006041331682354212f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #32 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0010344204492866993f, 0.0009261383675038815f, 0.0010168198496103287f, 0.0009329793974757195f, 0.0010910435812547803f, 0.0008864107076078653f, 0.0009387625032104552f, 0.0010131787275895476f, 0.0013308245688676834f, 0.0010533547028899193f, 0.0009759921231307089f, 0.0008634195546619594f, 0.0011993373045697808f, 0.0012784666614606977f, 0.0011611075606197119f, 0.000989592750556767f, 0.0009584269719198346f, 0.0010705763706937432f, 0.001089023076929152f, 0.000992580666206777f, 0.0009619853808544576f, 0.0009458696586079895f, 0.0008895055507309735f, 0.0009280255762860179f, 0.001119786174967885f, 0.0011164385359734297f, 0.001063637319020927f, 0.0010762599995359778f, 0.0010048509575426579f, 0.0010363776236772537f, 0.0010418997844681144f, 0.001147027825936675f, 0.0010117088677361608f, 0.0011706121731549501f, 0.0010103718377649784f, 0.0009153846185654402f, 0.0010735050309449434f, 0.0010001412592828274f, 0.0008852305472828448f, 0.0008739976328797638f, 0.001015587360598147f, 0.0009296293137595057f, 0.0008579985005781054f, 0.0009844008600339293f, 0.001276941504329443f, 0.001191569957882166f, 0.0009836440440267324f, 0.0009802256245166063f, 0.0010974445613101125f, 0.0011996326502412558f, 0.0009217074257321656f, 0.0011455405037850142f, 0.0009135459549725056f, 0.0009264986147172749f, 0.0011346336686983705f, 0.001084767049178481f, 0.0011581185972318053f, 0.0011064858408644795f, 0.0010751719819381833f, 0.0009773391066119075f, 0.0010564415715634823f, 0.0011114688822999597f, 0.001031238934956491f, 0.0009364576544612646f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.671671093907207e-05f, 7.763929897919297e-05f, 8.524123404640704e-05f, 7.821278995834291e-05f, 9.146350203081965e-05f, 7.430888217641041e-05f, 7.869759429013357e-05f, 8.493599307257682e-05f, 0.00011156463006045669f, 8.830399747239426e-05f, 8.18185944808647e-05f, 7.238150283228606e-05f, 0.00010054188896901906f, 0.00010717540135374293f, 9.733704791869968e-05f, 8.295875159092247e-05f, 8.034608617890626e-05f, 8.974770753411576e-05f, 9.129411773756146e-05f, 8.320923370774835e-05f, 8.064439316513017e-05f, 7.929339335532859e-05f, 7.456832099705935e-05f, 7.779750012559816e-05f, 9.387302270624787e-05f, 9.359238902106881e-05f, 8.916600199881941e-05f, 9.022417361848056e-05f, 8.423786493949592e-05f, 8.688078378327191e-05f, 8.734371658647433e-05f, 9.615672752261162e-05f, 8.481277473038062e-05f, 9.81338307610713e-05f, 8.470068860333413e-05f, 7.673779327888042e-05f, 8.999322017189115e-05f, 8.384304965147749e-05f, 7.420994370477274e-05f, 7.32682747184299e-05f, 8.513791544828564e-05f, 7.793194527039304e-05f, 7.192704651970416e-05f, 8.252351108239964e-05f, 0.0001070475482265465f, 9.989074897021055e-05f, 8.246006473200396e-05f, 8.217349386541173e-05f, 9.200010390486568e-05f, 0.00010056664905278012f, 7.726784679107368e-05f, 9.603203943697736e-05f, 7.658365939278156e-05f, 7.766949420329183e-05f, 9.5117706223391e-05f, 9.093732660403475e-05f, 9.708647849038243e-05f, 9.275804040953517e-05f, 9.013296221382916e-05f, 8.193151734303683e-05f, 8.85627741809003e-05f, 9.317577496403828e-05f, 8.645000343676656e-05f, 7.850437395973131e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #34 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_12_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.020101143047213554f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #35 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_12_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006522871553897858f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #36 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0011862029787153006f, 0.0010708871996030211f, 0.000901239225640893f, 0.0009657482150942087f, 0.0010963260428979993f, 0.0008973335498012602f, 0.0009608679101802409f, 0.0009728371514938772f, 0.001272133318707347f, 0.0010567707940936089f, 0.0010628423187881708f, 0.0010429496178403497f, 0.0010850239777937531f, 0.001004746532998979f, 0.00114933040458709f, 0.0009308967273682356f, 0.0009120835456997156f, 0.0012125330977141857f, 0.0009502009488642216f, 0.0010190298780798912f, 0.001099185086786747f, 0.0008961690473370254f, 0.0010280273854732513f, 0.0009663368691690266f, 0.0009399187983945012f, 0.001049750717356801f, 0.0009576332522556186f, 0.0009321781690232456f, 0.0008932088385336101f, 0.0010308638447895646f, 0.0011726763332262635f, 0.0010017919121310115f, 0.0011481234105303884f, 0.0010864944197237492f, 0.0009746303549036384f, 0.0010816656285896897f, 0.0009710342856124043f, 0.0009299017838202417f, 0.000945240375585854f, 0.0009553386480547488f, 0.0011453008046373725f, 0.001018332433886826f, 0.0009114437852986157f, 0.0009340778924524784f, 0.0010007427772507071f, 0.001023609540425241f, 0.0010258435504510999f, 0.001143032917752862f, 0.0011981513816863298f, 0.0009492341778241098f, 0.0011666230857372284f, 0.001031990977935493f, 0.001054192311130464f, 0.0010689079063013196f, 0.0011153764789924026f, 0.0011309210676699877f, 0.000964970386121422f, 0.0010600172681733966f, 0.0009946373756974936f, 0.000939075427595526f, 0.0010385779896751046f, 0.0011995438253507018f, 0.0012362340930849314f, 0.0009753955528140068f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00011335156159475446f, 0.00010233217471977696f, 8.612090459791943e-05f, 9.228527051163837e-05f, 0.00010476307215867564f, 8.57476843520999e-05f, 9.181891800835729e-05f, 9.296267671743408e-05f, 0.0001215629163198173f, 0.0001009832340059802f, 0.00010156341886613518f, 9.966250945581123e-05f, 0.00010368306539021432f, 9.601188503438607e-05f, 0.00010982807725667953f, 8.895492646843195e-05f, 8.715716830920428e-05f, 0.00011586761684156954f, 9.079960000235587e-05f, 9.737678192323074e-05f, 0.00010503627709113061f, 8.563640585634857e-05f, 9.823656728258356e-05f, 9.234152093995363e-05f, 8.981705468613654e-05f, 0.00010031241254182532f, 9.150982077699155e-05f, 8.907737355912104e-05f, 8.535353117622435e-05f, 9.850761125562713e-05f, 0.00011205897317267954f, 9.57295487751253e-05f, 0.0001097127387765795f, 0.00010382357868365943f, 9.313403279520571e-05f, 0.00010336214472772554f, 9.279040386900306e-05f, 8.885985153028741e-05f, 9.032557863974944e-05f, 9.129055251833051e-05f, 0.00010944301902782172f, 9.731013415148482e-05f, 8.709603571332991e-05f, 8.925890870159492e-05f, 9.562929335515946e-05f, 9.781440166989341e-05f, 9.802787826629356e-05f, 0.00010922629735432565f, 0.00011449332669144496f, 9.070721716852859e-05f, 0.00011148053454235196f, 9.861531725618988e-05f, 0.00010073684097733349f, 0.00010214303620159626f, 0.00010658349492587149f, 0.0001080689107766375f, 9.221094660460949e-05f, 0.00010129346628673375f, 9.504587069386616e-05f, 8.973646617960185e-05f, 9.924476034939289e-05f, 0.00011462638940429315f, 0.0001181324478238821f, 9.320715616922826e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #38 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_16_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00970724318176508f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #39 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_16_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007169113494455814f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #40 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0010542790405452251f, 0.0010300270514562726f, 0.0009771821787580848f, 0.0009690379956737161f, 0.0010180678218603134f, 0.0009571697446517646f, 0.0012317751534283161f, 0.0011637224815785885f, 0.0012566078221425414f, 0.0010045877425000072f, 0.0009224877576343715f, 0.0011178808053955436f, 0.0010899933986365795f, 0.0008975917007774115f, 0.0009726161370053887f, 0.000927671033423394f, 0.0009705372503958642f, 0.0009243462118320167f, 0.0007960643852129579f, 0.0010279429843649268f, 0.0008539101690985262f, 0.0009662939119152725f, 0.0012192287249490619f, 0.0008734852890484035f, 0.0009624239173717797f, 0.000892456853762269f, 0.0009277136414311826f, 0.0010189670138061047f, 0.0009484166512265801f, 0.0009800470434129238f, 0.0009047235362231731f, 0.0010625895811244845f, 0.0010080775246024132f, 0.0008426272543147206f, 0.001006613951176405f, 0.001045966986566782f, 0.001135788974352181f, 0.0008983535808511078f, 0.0010271507780998945f, 0.001108530443161726f, 0.0010532098822295666f, 0.000903954787645489f, 0.001105575473047793f, 0.0008765857783146203f, 0.0011785790557041764f, 0.0010761718731373549f, 0.0010824991622939706f, 0.0009265752742066979f, 0.001094831619411707f, 0.000918965321034193f, 0.0008639260195195675f, 0.0009097885922528803f, 0.0010238909162580967f, 0.0009874276584014297f, 0.001027258113026619f, 0.0009311847970820963f, 0.000991517910733819f, 0.0009457686683163047f, 0.0010582052636891603f, 0.0008910569013096392f, 0.0009475822444073856f, 0.0009355730144307017f, 0.0009895985713228583f, 0.0008938312530517578f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #41 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.240485476562753e-05f, 8.050926408031955e-05f, 7.637879025423899e-05f, 7.57422239985317e-05f, 7.957450725371018e-05f, 7.481457578251138e-05f, 9.627835970604792e-05f, 9.09592054085806e-05f, 9.821933781495318e-05f, 7.852086855564266e-05f, 7.210375042632222e-05f, 8.737611642573029e-05f, 8.519637049175799e-05f, 7.015781739028171e-05f, 7.602189725730568e-05f, 7.250888302223757e-05f, 7.585941057186574e-05f, 7.224900764413178e-05f, 6.222220690688118e-05f, 8.034636994125322e-05f, 6.674356700386852e-05f, 7.552773604402319e-05f, 9.529769886285067e-05f, 6.827360630268231e-05f, 7.522525265812874e-05f, 6.975646829232574e-05f, 7.251221541082487e-05f, 7.964478572830558e-05f, 7.41304102120921e-05f, 7.66027151257731e-05f, 7.071525760693476e-05f, 8.305443043354899e-05f, 7.879363693064079e-05f, 6.586167000932619e-05f, 7.86792443250306e-05f, 8.175516995834187e-05f, 8.877585787558928e-05f, 7.021736382739618e-05f, 8.028445154195651e-05f, 8.66452683112584e-05f, 8.232129039242864e-05f, 7.065517274895683e-05f, 8.641430031275377e-05f, 6.851594662293792e-05f, 9.212042641593143e-05f, 8.411605085711926e-05f, 8.461060497211292e-05f, 7.242323772516102e-05f, 8.557453838875517e-05f, 7.182842819020152e-05f, 6.75264309393242e-05f, 7.111114973668009e-05f, 8.002965478226542e-05f, 7.717959670117125e-05f, 8.029284072108567e-05f, 7.278352859430015e-05f, 7.749930227873847e-05f, 7.392343832179904e-05f, 8.271174010587856e-05f, 6.964703788980842e-05f, 7.406518852803856e-05f, 7.312652451219037e-05f, 7.734928658464924e-05f, 6.986389053054154e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #42 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_19_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012546959333121777f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #43 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_19_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006552858743816614f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #44 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_22_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0010676722740754485f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #45 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_22_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(6.813280197093263e-05f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #46 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_24_scale_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0036137087736278772f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #47 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_24_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009300339967012405f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #48 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_25_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0019086243119090796f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #49 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_25_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.038677409174852e-05f),
    AI_PACK_INTQ_ZP(0)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_input_output, AI_STATIC,
  0, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 32, 32), AI_STRIDE_INIT(4, 1, 1, 3, 96),
  1, &conv2d_15_input_output_array, &conv2d_15_input_output_intq)

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
  pool_6_output, AI_STATIC,
  5, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 16, 16), AI_STRIDE_INIT(4, 1, 1, 32, 512),
  1, &pool_6_output_array, &pool_6_output_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_output, AI_STATIC,
  6, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_7_output_array, &conv2d_7_output_intq)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_9_output, AI_STATIC,
  7, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &eltwise_9_output_array, &eltwise_9_output_intq)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_output, AI_STATIC,
  8, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_10_output_array, &conv2d_10_output_intq)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_12_output, AI_STATIC,
  9, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &eltwise_12_output_array, &eltwise_12_output_intq)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  pool_13_output, AI_STATIC,
  10, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 8, 8), AI_STRIDE_INIT(4, 1, 1, 64, 512),
  1, &pool_13_output_array, &pool_13_output_intq)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_output, AI_STATIC,
  11, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 8, 8), AI_STRIDE_INIT(4, 1, 1, 64, 512),
  1, &conv2d_14_output_array, &conv2d_14_output_intq)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_16_output, AI_STATIC,
  12, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 8, 8), AI_STRIDE_INIT(4, 1, 1, 64, 512),
  1, &eltwise_16_output_array, &eltwise_16_output_intq)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_output, AI_STATIC,
  13, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 8, 8), AI_STRIDE_INIT(4, 1, 1, 64, 512),
  1, &conv2d_17_output_array, &conv2d_17_output_intq)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_19_output, AI_STATIC,
  14, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 8, 8), AI_STRIDE_INIT(4, 1, 1, 64, 512),
  1, &eltwise_19_output_array, &eltwise_19_output_intq)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  pool_20_output, AI_STATIC,
  15, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 4, 4), AI_STRIDE_INIT(4, 1, 1, 64, 256),
  1, &pool_20_output_array, &pool_20_output_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  pool_20_output0, AI_STATIC,
  16, 0x1,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &pool_20_output_array, &pool_20_output_intq)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  dense_22_output, AI_STATIC,
  17, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &dense_22_output_array, &dense_22_output_intq)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_24_output, AI_STATIC,
  18, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &eltwise_24_output_array, &eltwise_24_output_intq)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  dense_25_output, AI_STATIC,
  19, 0x1,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 1, 1, 10, 10),
  1, &dense_25_output_array, &dense_25_output_intq)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  dense_25_fmt_output, AI_STATIC,
  20, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &dense_25_fmt_output_array, NULL)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  nl_26_output, AI_STATIC,
  21, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &nl_26_output_array, NULL)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  nl_26_fmt_output, AI_STATIC,
  22, 0x1,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 1, 1, 10, 10),
  1, &nl_26_fmt_output_array, &nl_26_fmt_output_intq)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_weights, AI_STATIC,
  23, 0x1,
  AI_SHAPE_INIT(4, 3, 3, 3, 32), AI_STRIDE_INIT(4, 1, 3, 9, 27),
  1, &conv2d_0_weights_array, &conv2d_0_weights_intq)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_bias, AI_STATIC,
  24, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_0_bias_array, &conv2d_0_bias_intq)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_2_scale, AI_STATIC,
  25, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_2_scale_array, &eltwise_2_scale_intq)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_2_bias, AI_STATIC,
  26, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_2_bias_array, &eltwise_2_bias_intq)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_weights, AI_STATIC,
  27, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 32), AI_STRIDE_INIT(4, 1, 32, 96, 288),
  1, &conv2d_3_weights_array, &conv2d_3_weights_intq)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_bias, AI_STATIC,
  28, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_3_bias_array, &conv2d_3_bias_intq)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_5_scale, AI_STATIC,
  29, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_5_scale_array, &eltwise_5_scale_intq)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_5_bias, AI_STATIC,
  30, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_5_bias_array, &eltwise_5_bias_intq)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_weights, AI_STATIC,
  31, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 64), AI_STRIDE_INIT(4, 1, 32, 96, 288),
  1, &conv2d_7_weights_array, &conv2d_7_weights_intq)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_bias, AI_STATIC,
  32, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_7_bias_array, &conv2d_7_bias_intq)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_9_scale, AI_STATIC,
  33, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 1, 1, 64, 64),
  1, &eltwise_9_scale_array, &eltwise_9_scale_intq)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_9_bias, AI_STATIC,
  34, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 1, 1, 64, 64),
  1, &eltwise_9_bias_array, &eltwise_9_bias_intq)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_weights, AI_STATIC,
  35, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 1, 64, 192, 576),
  1, &conv2d_10_weights_array, &conv2d_10_weights_intq)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_bias, AI_STATIC,
  36, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_10_bias_array, &conv2d_10_bias_intq)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_12_scale, AI_STATIC,
  37, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 1, 1, 64, 64),
  1, &eltwise_12_scale_array, &eltwise_12_scale_intq)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_12_bias, AI_STATIC,
  38, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 1, 1, 64, 64),
  1, &eltwise_12_bias_array, &eltwise_12_bias_intq)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_weights, AI_STATIC,
  39, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 1, 64, 192, 576),
  1, &conv2d_14_weights_array, &conv2d_14_weights_intq)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_bias, AI_STATIC,
  40, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_14_bias_array, &conv2d_14_bias_intq)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_16_scale, AI_STATIC,
  41, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 1, 1, 64, 64),
  1, &eltwise_16_scale_array, &eltwise_16_scale_intq)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_16_bias, AI_STATIC,
  42, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 1, 1, 64, 64),
  1, &eltwise_16_bias_array, &eltwise_16_bias_intq)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_weights, AI_STATIC,
  43, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 1, 64, 192, 576),
  1, &conv2d_17_weights_array, &conv2d_17_weights_intq)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_bias, AI_STATIC,
  44, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_17_bias_array, &conv2d_17_bias_intq)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_19_scale, AI_STATIC,
  45, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 1, 1, 64, 64),
  1, &eltwise_19_scale_array, &eltwise_19_scale_intq)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_19_bias, AI_STATIC,
  46, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 1, 1, 64, 64),
  1, &eltwise_19_bias_array, &eltwise_19_bias_intq)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  dense_22_weights, AI_STATIC,
  47, 0x1,
  AI_SHAPE_INIT(4, 1024, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1024, 131072, 131072),
  1, &dense_22_weights_array, &dense_22_weights_intq)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  dense_22_bias, AI_STATIC,
  48, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &dense_22_bias_array, &dense_22_bias_intq)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_24_scale, AI_STATIC,
  49, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &eltwise_24_scale_array, &eltwise_24_scale_intq)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_24_bias, AI_STATIC,
  50, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &eltwise_24_bias_array, &eltwise_24_bias_intq)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  dense_25_weights, AI_STATIC,
  51, 0x1,
  AI_SHAPE_INIT(4, 128, 10, 1, 1), AI_STRIDE_INIT(4, 1, 128, 1280, 1280),
  1, &dense_25_weights_array, &dense_25_weights_intq)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  dense_25_bias, AI_STATIC,
  52, 0x1,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &dense_25_bias_array, &dense_25_bias_intq)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_scratch0, AI_STATIC,
  53, 0x0,
  AI_SHAPE_INIT(4, 1, 2284, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2284, 2284),
  1, &conv2d_0_scratch0_array, NULL)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_2_scratch0, AI_STATIC,
  54, 0x0,
  AI_SHAPE_INIT(4, 1, 320, 1, 1), AI_STRIDE_INIT(4, 1, 1, 320, 320),
  1, &eltwise_2_scratch0_array, NULL)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch0, AI_STATIC,
  55, 0x0,
  AI_SHAPE_INIT(4, 1, 6720, 1, 1), AI_STRIDE_INIT(4, 1, 1, 6720, 6720),
  1, &conv2d_3_scratch0_array, NULL)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_5_scratch0, AI_STATIC,
  56, 0x0,
  AI_SHAPE_INIT(4, 1, 320, 1, 1), AI_STRIDE_INIT(4, 1, 1, 320, 320),
  1, &eltwise_5_scratch0_array, NULL)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_scratch0, AI_STATIC,
  57, 0x0,
  AI_SHAPE_INIT(4, 1, 7168, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7168, 7168),
  1, &conv2d_7_scratch0_array, NULL)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_9_scratch0, AI_STATIC,
  58, 0x0,
  AI_SHAPE_INIT(4, 1, 640, 1, 1), AI_STRIDE_INIT(4, 1, 1, 640, 640),
  1, &eltwise_9_scratch0_array, NULL)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_scratch0, AI_STATIC,
  59, 0x0,
  AI_SHAPE_INIT(4, 1, 8320, 1, 1), AI_STRIDE_INIT(4, 1, 1, 8320, 8320),
  1, &conv2d_10_scratch0_array, NULL)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_12_scratch0, AI_STATIC,
  60, 0x0,
  AI_SHAPE_INIT(4, 1, 640, 1, 1), AI_STRIDE_INIT(4, 1, 1, 640, 640),
  1, &eltwise_12_scratch0_array, NULL)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_scratch0, AI_STATIC,
  61, 0x0,
  AI_SHAPE_INIT(4, 1, 8320, 1, 1), AI_STRIDE_INIT(4, 1, 1, 8320, 8320),
  1, &conv2d_14_scratch0_array, NULL)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_16_scratch0, AI_STATIC,
  62, 0x0,
  AI_SHAPE_INIT(4, 1, 640, 1, 1), AI_STRIDE_INIT(4, 1, 1, 640, 640),
  1, &eltwise_16_scratch0_array, NULL)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_scratch0, AI_STATIC,
  63, 0x0,
  AI_SHAPE_INIT(4, 1, 8320, 1, 1), AI_STRIDE_INIT(4, 1, 1, 8320, 8320),
  1, &conv2d_17_scratch0_array, NULL)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_19_scratch0, AI_STATIC,
  64, 0x0,
  AI_SHAPE_INIT(4, 1, 640, 1, 1), AI_STRIDE_INIT(4, 1, 1, 640, 640),
  1, &eltwise_19_scratch0_array, NULL)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_24_scratch0, AI_STATIC,
  65, 0x0,
  AI_SHAPE_INIT(4, 1, 1280, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1280, 1280),
  1, &eltwise_24_scratch0_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_input_output),
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
  .groups = 1, 
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
  &AI_NET_OBJ_INSTANCE, &pool_6_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  pool_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pool_6_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pool_6_layer, 6,
  POOL_TYPE, 0x0, NULL,
  pool, forward_mp_integer_INT8,
  &pool_6_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_7_layer, AI_STATIC, 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pool_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_7_weights, &conv2d_7_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_7_layer, 7,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_7_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_9_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_9_scale, &eltwise_9_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_9_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  eltwise_9_layer, 9,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn_integer,
  &eltwise_9_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_10_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_10_weights, &conv2d_10_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_10_layer, 10,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_10_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_12_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_12_scale, &eltwise_12_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_12_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  eltwise_12_layer, 12,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn_integer,
  &eltwise_12_chain,
  &AI_NET_OBJ_INSTANCE, &pool_13_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  pool_13_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pool_13_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pool_13_layer, 13,
  POOL_TYPE, 0x0, NULL,
  pool, forward_mp_integer_INT8,
  &pool_13_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_14_layer, AI_STATIC, 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pool_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_14_weights, &conv2d_14_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_14_layer, 14,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_14_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_16_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_16_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_16_scale, &eltwise_16_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_16_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  eltwise_16_layer, 16,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn_integer,
  &eltwise_16_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_17_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_17_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_17_weights, &conv2d_17_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_17_layer, 17,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_17_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_19_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_19_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_19_scale, &eltwise_19_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_19_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  eltwise_19_layer, 19,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn_integer,
  &eltwise_19_chain,
  &AI_NET_OBJ_INSTANCE, &pool_20_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  pool_20_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pool_20_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pool_20_layer, 20,
  POOL_TYPE, 0x0, NULL,
  pool, forward_mp_integer_INT8,
  &pool_20_chain,
  &AI_NET_OBJ_INSTANCE, &dense_22_layer, AI_STATIC, 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_22_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pool_20_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_22_weights, &dense_22_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_22_layer, 22,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &dense_22_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_24_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_24_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_24_scale, &eltwise_24_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_24_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  eltwise_24_layer, 24,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn_integer,
  &eltwise_24_chain,
  &AI_NET_OBJ_INSTANCE, &dense_25_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_25_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_25_weights, &dense_25_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_25_layer, 25,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &dense_25_chain,
  &AI_NET_OBJ_INSTANCE, &dense_25_fmt_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_25_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_25_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_25_fmt_layer, 25,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &dense_25_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &nl_26_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_26_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_25_fmt_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_26_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_26_layer, 26,
  NL_TYPE, 0x0, NULL,
  nl, forward_sm,
  &nl_26_chain,
  &AI_NET_OBJ_INSTANCE, &nl_26_fmt_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_26_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_26_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_26_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_26_fmt_layer, 26,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &nl_26_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &nl_26_fmt_layer, AI_STATIC, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 274184, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 41600, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &conv2d_15_input_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &nl_26_fmt_output),
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
    conv2d_15_input_output_array.data = AI_PTR(NULL);
    conv2d_15_input_output_array.data_start = AI_PTR(NULL);
    conv2d_0_output_array.data = AI_PTR(activations + 2112);
    conv2d_0_output_array.data_start = AI_PTR(activations + 2112);
    eltwise_2_output_array.data = AI_PTR(activations + 2112);
    eltwise_2_output_array.data_start = AI_PTR(activations + 2112);
    conv2d_3_output_array.data = AI_PTR(activations + 0);
    conv2d_3_output_array.data_start = AI_PTR(activations + 0);
    eltwise_5_output_array.data = AI_PTR(activations + 0);
    eltwise_5_output_array.data_start = AI_PTR(activations + 0);
    pool_6_output_array.data = AI_PTR(activations + 32768);
    pool_6_output_array.data_start = AI_PTR(activations + 32768);
    conv2d_7_output_array.data = AI_PTR(activations + 7168);
    conv2d_7_output_array.data_start = AI_PTR(activations + 7168);
    eltwise_9_output_array.data = AI_PTR(activations + 23552);
    eltwise_9_output_array.data_start = AI_PTR(activations + 23552);
    conv2d_10_output_array.data = AI_PTR(activations + 21376);
    conv2d_10_output_array.data_start = AI_PTR(activations + 21376);
    eltwise_12_output_array.data = AI_PTR(activations + 640);
    eltwise_12_output_array.data_start = AI_PTR(activations + 640);
    pool_13_output_array.data = AI_PTR(activations + 17024);
    pool_13_output_array.data_start = AI_PTR(activations + 17024);
    conv2d_14_output_array.data = AI_PTR(activations + 8320);
    conv2d_14_output_array.data_start = AI_PTR(activations + 8320);
    eltwise_16_output_array.data = AI_PTR(activations + 640);
    eltwise_16_output_array.data_start = AI_PTR(activations + 640);
    conv2d_17_output_array.data = AI_PTR(activations + 13056);
    conv2d_17_output_array.data_start = AI_PTR(activations + 13056);
    eltwise_19_output_array.data = AI_PTR(activations + 640);
    eltwise_19_output_array.data_start = AI_PTR(activations + 640);
    pool_20_output_array.data = AI_PTR(activations + 4736);
    pool_20_output_array.data_start = AI_PTR(activations + 4736);
    dense_22_output_array.data = AI_PTR(activations + 0);
    dense_22_output_array.data_start = AI_PTR(activations + 0);
    eltwise_24_output_array.data = AI_PTR(activations + 1408);
    eltwise_24_output_array.data_start = AI_PTR(activations + 1408);
    dense_25_output_array.data = AI_PTR(activations + 0);
    dense_25_output_array.data_start = AI_PTR(activations + 0);
    dense_25_fmt_output_array.data = AI_PTR(activations + 12);
    dense_25_fmt_output_array.data_start = AI_PTR(activations + 12);
    nl_26_output_array.data = AI_PTR(activations + 52);
    nl_26_output_array.data_start = AI_PTR(activations + 52);
    nl_26_fmt_output_array.data = AI_PTR(NULL);
    nl_26_fmt_output_array.data_start = AI_PTR(NULL);
    conv2d_0_scratch0_array.data = AI_PTR(activations + 34880);
    conv2d_0_scratch0_array.data_start = AI_PTR(activations + 34880);
    eltwise_2_scratch0_array.data = AI_PTR(activations + 1792);
    eltwise_2_scratch0_array.data_start = AI_PTR(activations + 1792);
    conv2d_3_scratch0_array.data = AI_PTR(activations + 34880);
    conv2d_3_scratch0_array.data_start = AI_PTR(activations + 34880);
    eltwise_5_scratch0_array.data = AI_PTR(activations + 32768);
    eltwise_5_scratch0_array.data_start = AI_PTR(activations + 32768);
    conv2d_7_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_7_scratch0_array.data_start = AI_PTR(activations + 0);
    eltwise_9_scratch0_array.data = AI_PTR(activations + 0);
    eltwise_9_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_10_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_10_scratch0_array.data_start = AI_PTR(activations + 0);
    eltwise_12_scratch0_array.data = AI_PTR(activations + 0);
    eltwise_12_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_14_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_14_scratch0_array.data_start = AI_PTR(activations + 0);
    eltwise_16_scratch0_array.data = AI_PTR(activations + 0);
    eltwise_16_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_17_scratch0_array.data = AI_PTR(activations + 4736);
    conv2d_17_scratch0_array.data_start = AI_PTR(activations + 4736);
    eltwise_19_scratch0_array.data = AI_PTR(activations + 0);
    eltwise_19_scratch0_array.data_start = AI_PTR(activations + 0);
    eltwise_24_scratch0_array.data = AI_PTR(activations + 128);
    eltwise_24_scratch0_array.data_start = AI_PTR(activations + 128);
    
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
    conv2d_3_bias_array.data = AI_PTR(weights + 10272);
    conv2d_3_bias_array.data_start = AI_PTR(weights + 10272);
    eltwise_5_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_5_scale_array.data = AI_PTR(weights + 10400);
    eltwise_5_scale_array.data_start = AI_PTR(weights + 10400);
    eltwise_5_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_5_bias_array.data = AI_PTR(weights + 10432);
    eltwise_5_bias_array.data_start = AI_PTR(weights + 10432);
    conv2d_7_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_weights_array.data = AI_PTR(weights + 10464);
    conv2d_7_weights_array.data_start = AI_PTR(weights + 10464);
    conv2d_7_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_bias_array.data = AI_PTR(weights + 28896);
    conv2d_7_bias_array.data_start = AI_PTR(weights + 28896);
    eltwise_9_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_9_scale_array.data = AI_PTR(weights + 29152);
    eltwise_9_scale_array.data_start = AI_PTR(weights + 29152);
    eltwise_9_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_9_bias_array.data = AI_PTR(weights + 29216);
    eltwise_9_bias_array.data_start = AI_PTR(weights + 29216);
    conv2d_10_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_weights_array.data = AI_PTR(weights + 29280);
    conv2d_10_weights_array.data_start = AI_PTR(weights + 29280);
    conv2d_10_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_bias_array.data = AI_PTR(weights + 66144);
    conv2d_10_bias_array.data_start = AI_PTR(weights + 66144);
    eltwise_12_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_12_scale_array.data = AI_PTR(weights + 66400);
    eltwise_12_scale_array.data_start = AI_PTR(weights + 66400);
    eltwise_12_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_12_bias_array.data = AI_PTR(weights + 66464);
    eltwise_12_bias_array.data_start = AI_PTR(weights + 66464);
    conv2d_14_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_14_weights_array.data = AI_PTR(weights + 66528);
    conv2d_14_weights_array.data_start = AI_PTR(weights + 66528);
    conv2d_14_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_14_bias_array.data = AI_PTR(weights + 103392);
    conv2d_14_bias_array.data_start = AI_PTR(weights + 103392);
    eltwise_16_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_16_scale_array.data = AI_PTR(weights + 103648);
    eltwise_16_scale_array.data_start = AI_PTR(weights + 103648);
    eltwise_16_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_16_bias_array.data = AI_PTR(weights + 103712);
    eltwise_16_bias_array.data_start = AI_PTR(weights + 103712);
    conv2d_17_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_weights_array.data = AI_PTR(weights + 103776);
    conv2d_17_weights_array.data_start = AI_PTR(weights + 103776);
    conv2d_17_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_bias_array.data = AI_PTR(weights + 140640);
    conv2d_17_bias_array.data_start = AI_PTR(weights + 140640);
    eltwise_19_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_19_scale_array.data = AI_PTR(weights + 140896);
    eltwise_19_scale_array.data_start = AI_PTR(weights + 140896);
    eltwise_19_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_19_bias_array.data = AI_PTR(weights + 140960);
    eltwise_19_bias_array.data_start = AI_PTR(weights + 140960);
    dense_22_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_22_weights_array.data = AI_PTR(weights + 141024);
    dense_22_weights_array.data_start = AI_PTR(weights + 141024);
    dense_22_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_22_bias_array.data = AI_PTR(weights + 272096);
    dense_22_bias_array.data_start = AI_PTR(weights + 272096);
    eltwise_24_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_24_scale_array.data = AI_PTR(weights + 272608);
    eltwise_24_scale_array.data_start = AI_PTR(weights + 272608);
    eltwise_24_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_24_bias_array.data = AI_PTR(weights + 272736);
    eltwise_24_bias_array.data_start = AI_PTR(weights + 272736);
    dense_25_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_25_weights_array.data = AI_PTR(weights + 272864);
    dense_25_weights_array.data_start = AI_PTR(weights + 272864);
    dense_25_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_25_bias_array.data = AI_PTR(weights + 274144);
    dense_25_bias_array.data_start = AI_PTR(weights + 274144);
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
      
      .n_macc            = 29595784,
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

