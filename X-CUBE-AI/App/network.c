/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Sat Oct 30 17:56:22 2021
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
#define AI_NETWORK_MODEL_SIGNATURE     "0fa7755a7f67eb16549ac5508a7fb879"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Sat Oct 30 17:56:22 2021"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array modelInput_output_array;   /* Array #0 */
AI_STATIC ai_array node_52_output_array;   /* Array #1 */
AI_STATIC ai_array node_54_output_array;   /* Array #2 */
AI_STATIC ai_array node_55_output_array;   /* Array #3 */
AI_STATIC ai_array node_57_output_array;   /* Array #4 */
AI_STATIC ai_array node_58_output_array;   /* Array #5 */
AI_STATIC ai_array node_59_output_array;   /* Array #6 */
AI_STATIC ai_array node_61_output_array;   /* Array #7 */
AI_STATIC ai_array node_62_output_array;   /* Array #8 */
AI_STATIC ai_array node_64_output_array;   /* Array #9 */
AI_STATIC ai_array node_65_output_array;   /* Array #10 */
AI_STATIC ai_array node_66_output_array;   /* Array #11 */
AI_STATIC ai_array node_68_output_array;   /* Array #12 */
AI_STATIC ai_array node_69_output_array;   /* Array #13 */
AI_STATIC ai_array node_71_output_array;   /* Array #14 */
AI_STATIC ai_array node_72_output_array;   /* Array #15 */
AI_STATIC ai_array node_74_output_array;   /* Array #16 */
AI_STATIC ai_array node_75_output_array;   /* Array #17 */
AI_STATIC ai_array node_76_output_array;   /* Array #18 */
AI_STATIC ai_array node_77_output_array;   /* Array #19 */
AI_STATIC ai_array modelOutput_output_array;   /* Array #20 */
AI_STATIC ai_array fc2bias_array;   /* Array #21 */
AI_STATIC ai_array fc2weight_array;   /* Array #22 */
AI_STATIC ai_array fc1bias_array;   /* Array #23 */
AI_STATIC ai_array fc1weight_array;   /* Array #24 */
AI_STATIC ai_array node_52_weights_array;   /* Array #25 */
AI_STATIC ai_array node_52_bias_array;   /* Array #26 */
AI_STATIC ai_array node_54_scale_array;   /* Array #27 */
AI_STATIC ai_array node_54_bias_array;   /* Array #28 */
AI_STATIC ai_array node_55_weights_array;   /* Array #29 */
AI_STATIC ai_array node_55_bias_array;   /* Array #30 */
AI_STATIC ai_array node_57_scale_array;   /* Array #31 */
AI_STATIC ai_array node_57_bias_array;   /* Array #32 */
AI_STATIC ai_array node_59_weights_array;   /* Array #33 */
AI_STATIC ai_array node_59_bias_array;   /* Array #34 */
AI_STATIC ai_array node_61_scale_array;   /* Array #35 */
AI_STATIC ai_array node_61_bias_array;   /* Array #36 */
AI_STATIC ai_array node_62_weights_array;   /* Array #37 */
AI_STATIC ai_array node_62_bias_array;   /* Array #38 */
AI_STATIC ai_array node_64_scale_array;   /* Array #39 */
AI_STATIC ai_array node_64_bias_array;   /* Array #40 */
AI_STATIC ai_array node_66_weights_array;   /* Array #41 */
AI_STATIC ai_array node_66_bias_array;   /* Array #42 */
AI_STATIC ai_array node_68_scale_array;   /* Array #43 */
AI_STATIC ai_array node_68_bias_array;   /* Array #44 */
AI_STATIC ai_array node_69_weights_array;   /* Array #45 */
AI_STATIC ai_array node_69_bias_array;   /* Array #46 */
AI_STATIC ai_array node_71_scale_array;   /* Array #47 */
AI_STATIC ai_array node_71_bias_array;   /* Array #48 */
AI_STATIC ai_array node_76_scale_array;   /* Array #49 */
AI_STATIC ai_array node_76_bias_array;   /* Array #50 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor modelInput_output;   /* Tensor #0 */
AI_STATIC ai_tensor node_52_output;   /* Tensor #1 */
AI_STATIC ai_tensor node_54_output;   /* Tensor #2 */
AI_STATIC ai_tensor node_55_output;   /* Tensor #3 */
AI_STATIC ai_tensor node_57_output;   /* Tensor #4 */
AI_STATIC ai_tensor node_58_output;   /* Tensor #5 */
AI_STATIC ai_tensor node_59_output;   /* Tensor #6 */
AI_STATIC ai_tensor node_61_output;   /* Tensor #7 */
AI_STATIC ai_tensor node_62_output;   /* Tensor #8 */
AI_STATIC ai_tensor node_64_output;   /* Tensor #9 */
AI_STATIC ai_tensor node_65_output;   /* Tensor #10 */
AI_STATIC ai_tensor node_66_output;   /* Tensor #11 */
AI_STATIC ai_tensor node_68_output;   /* Tensor #12 */
AI_STATIC ai_tensor node_69_output;   /* Tensor #13 */
AI_STATIC ai_tensor node_71_output;   /* Tensor #14 */
AI_STATIC ai_tensor node_72_output;   /* Tensor #15 */
AI_STATIC ai_tensor node_72_output0;   /* Tensor #16 */
AI_STATIC ai_tensor node_74_output;   /* Tensor #17 */
AI_STATIC ai_tensor node_75_output;   /* Tensor #18 */
AI_STATIC ai_tensor node_76_output;   /* Tensor #19 */
AI_STATIC ai_tensor node_77_output;   /* Tensor #20 */
AI_STATIC ai_tensor modelOutput_output;   /* Tensor #21 */
AI_STATIC ai_tensor fc2bias;   /* Tensor #22 */
AI_STATIC ai_tensor fc2weight;   /* Tensor #23 */
AI_STATIC ai_tensor fc1bias;   /* Tensor #24 */
AI_STATIC ai_tensor fc1weight;   /* Tensor #25 */
AI_STATIC ai_tensor node_52_weights;   /* Tensor #26 */
AI_STATIC ai_tensor node_52_bias;   /* Tensor #27 */
AI_STATIC ai_tensor node_54_scale;   /* Tensor #28 */
AI_STATIC ai_tensor node_54_bias;   /* Tensor #29 */
AI_STATIC ai_tensor node_55_weights;   /* Tensor #30 */
AI_STATIC ai_tensor node_55_bias;   /* Tensor #31 */
AI_STATIC ai_tensor node_57_scale;   /* Tensor #32 */
AI_STATIC ai_tensor node_57_bias;   /* Tensor #33 */
AI_STATIC ai_tensor node_59_weights;   /* Tensor #34 */
AI_STATIC ai_tensor node_59_bias;   /* Tensor #35 */
AI_STATIC ai_tensor node_61_scale;   /* Tensor #36 */
AI_STATIC ai_tensor node_61_bias;   /* Tensor #37 */
AI_STATIC ai_tensor node_62_weights;   /* Tensor #38 */
AI_STATIC ai_tensor node_62_bias;   /* Tensor #39 */
AI_STATIC ai_tensor node_64_scale;   /* Tensor #40 */
AI_STATIC ai_tensor node_64_bias;   /* Tensor #41 */
AI_STATIC ai_tensor node_66_weights;   /* Tensor #42 */
AI_STATIC ai_tensor node_66_bias;   /* Tensor #43 */
AI_STATIC ai_tensor node_68_scale;   /* Tensor #44 */
AI_STATIC ai_tensor node_68_bias;   /* Tensor #45 */
AI_STATIC ai_tensor node_69_weights;   /* Tensor #46 */
AI_STATIC ai_tensor node_69_bias;   /* Tensor #47 */
AI_STATIC ai_tensor node_71_scale;   /* Tensor #48 */
AI_STATIC ai_tensor node_71_bias;   /* Tensor #49 */
AI_STATIC ai_tensor node_76_scale;   /* Tensor #50 */
AI_STATIC ai_tensor node_76_bias;   /* Tensor #51 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain node_52_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain node_54_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain node_55_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain node_57_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain node_58_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain node_59_chain;   /* Chain #5 */
AI_STATIC_CONST ai_tensor_chain node_61_chain;   /* Chain #6 */
AI_STATIC_CONST ai_tensor_chain node_62_chain;   /* Chain #7 */
AI_STATIC_CONST ai_tensor_chain node_64_chain;   /* Chain #8 */
AI_STATIC_CONST ai_tensor_chain node_65_chain;   /* Chain #9 */
AI_STATIC_CONST ai_tensor_chain node_66_chain;   /* Chain #10 */
AI_STATIC_CONST ai_tensor_chain node_68_chain;   /* Chain #11 */
AI_STATIC_CONST ai_tensor_chain node_69_chain;   /* Chain #12 */
AI_STATIC_CONST ai_tensor_chain node_71_chain;   /* Chain #13 */
AI_STATIC_CONST ai_tensor_chain node_72_chain;   /* Chain #14 */
AI_STATIC_CONST ai_tensor_chain node_74_chain;   /* Chain #15 */
AI_STATIC_CONST ai_tensor_chain node_75_chain;   /* Chain #16 */
AI_STATIC_CONST ai_tensor_chain node_76_chain;   /* Chain #17 */
AI_STATIC_CONST ai_tensor_chain node_77_chain;   /* Chain #18 */
AI_STATIC_CONST ai_tensor_chain modelOutput_chain;   /* Chain #19 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_conv2d node_52_layer; /* Layer #0 */
AI_STATIC ai_layer_bn node_54_layer; /* Layer #1 */
AI_STATIC ai_layer_conv2d node_55_layer; /* Layer #2 */
AI_STATIC ai_layer_bn node_57_layer; /* Layer #3 */
AI_STATIC ai_layer_pool node_58_layer; /* Layer #4 */
AI_STATIC ai_layer_conv2d node_59_layer; /* Layer #5 */
AI_STATIC ai_layer_bn node_61_layer; /* Layer #6 */
AI_STATIC ai_layer_conv2d node_62_layer; /* Layer #7 */
AI_STATIC ai_layer_bn node_64_layer; /* Layer #8 */
AI_STATIC ai_layer_pool node_65_layer; /* Layer #9 */
AI_STATIC ai_layer_conv2d node_66_layer; /* Layer #10 */
AI_STATIC ai_layer_bn node_68_layer; /* Layer #11 */
AI_STATIC ai_layer_conv2d node_69_layer; /* Layer #12 */
AI_STATIC ai_layer_bn node_71_layer; /* Layer #13 */
AI_STATIC ai_layer_pool node_72_layer; /* Layer #14 */
AI_STATIC ai_layer_gemm node_74_layer; /* Layer #15 */
AI_STATIC ai_layer_nl node_75_layer; /* Layer #16 */
AI_STATIC ai_layer_bn node_76_layer; /* Layer #17 */
AI_STATIC ai_layer_gemm node_77_layer; /* Layer #18 */
AI_STATIC ai_layer_nl modelOutput_layer; /* Layer #19 */




/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  modelInput_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 3072, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  node_52_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  node_54_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  node_55_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  node_57_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  node_58_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  node_59_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  node_61_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  node_62_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  node_64_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  node_65_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  node_66_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  node_68_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  node_69_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  node_71_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  node_72_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  node_74_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  node_75_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  node_76_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  node_77_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  modelOutput_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 10, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  fc2bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  fc2weight_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1280, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  fc1bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  fc1weight_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 131072, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  node_52_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 864, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  node_52_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  node_54_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  node_54_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  node_55_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 9216, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  node_55_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  node_57_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  node_57_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  node_59_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 18432, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  node_59_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  node_61_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  node_61_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  node_62_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 36864, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  node_62_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  node_64_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  node_64_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  node_66_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 36864, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  node_66_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  node_68_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  node_68_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  node_69_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 36864, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  node_69_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  node_71_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  node_71_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  node_76_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  node_76_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  modelInput_output, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 32, 32), AI_STRIDE_INIT(4, 4, 4, 12, 384),
  1, &modelInput_output_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  node_52_output, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 4, 4, 128, 4096),
  1, &node_52_output_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  node_54_output, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 4, 4, 128, 4096),
  1, &node_54_output_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  node_55_output, AI_STATIC,
  3, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 4, 4, 128, 4096),
  1, &node_55_output_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  node_57_output, AI_STATIC,
  4, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 4, 4, 128, 4096),
  1, &node_57_output_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  node_58_output, AI_STATIC,
  5, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 16, 16), AI_STRIDE_INIT(4, 4, 4, 128, 2048),
  1, &node_58_output_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  node_59_output, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 4, 4, 256, 4096),
  1, &node_59_output_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  node_61_output, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 4, 4, 256, 4096),
  1, &node_61_output_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  node_62_output, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 4, 4, 256, 4096),
  1, &node_62_output_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  node_64_output, AI_STATIC,
  9, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 4, 4, 256, 4096),
  1, &node_64_output_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  node_65_output, AI_STATIC,
  10, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 8, 8), AI_STRIDE_INIT(4, 4, 4, 256, 2048),
  1, &node_65_output_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  node_66_output, AI_STATIC,
  11, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 8, 8), AI_STRIDE_INIT(4, 4, 4, 256, 2048),
  1, &node_66_output_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  node_68_output, AI_STATIC,
  12, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 8, 8), AI_STRIDE_INIT(4, 4, 4, 256, 2048),
  1, &node_68_output_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  node_69_output, AI_STATIC,
  13, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 8, 8), AI_STRIDE_INIT(4, 4, 4, 256, 2048),
  1, &node_69_output_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  node_71_output, AI_STATIC,
  14, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 8, 8), AI_STRIDE_INIT(4, 4, 4, 256, 2048),
  1, &node_71_output_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  node_72_output, AI_STATIC,
  15, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 4, 4), AI_STRIDE_INIT(4, 4, 4, 256, 1024),
  1, &node_72_output_array, NULL)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  node_72_output0, AI_STATIC,
  16, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4096, 4096),
  1, &node_72_output_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  node_74_output, AI_STATIC,
  17, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &node_74_output_array, NULL)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  node_75_output, AI_STATIC,
  18, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &node_75_output_array, NULL)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  node_76_output, AI_STATIC,
  19, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &node_76_output_array, NULL)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  node_77_output, AI_STATIC,
  20, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &node_77_output_array, NULL)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  modelOutput_output, AI_STATIC,
  21, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &modelOutput_output_array, NULL)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  fc2bias, AI_STATIC,
  22, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &fc2bias_array, NULL)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  fc2weight, AI_STATIC,
  23, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 128), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &fc2weight_array, NULL)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  fc1bias, AI_STATIC,
  24, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &fc1bias_array, NULL)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  fc1weight, AI_STATIC,
  25, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1024), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &fc1weight_array, NULL)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  node_52_weights, AI_STATIC,
  26, 0x0,
  AI_SHAPE_INIT(4, 3, 3, 3, 32), AI_STRIDE_INIT(4, 4, 12, 36, 108),
  1, &node_52_weights_array, NULL)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  node_52_bias, AI_STATIC,
  27, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &node_52_bias_array, NULL)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  node_54_scale, AI_STATIC,
  28, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &node_54_scale_array, NULL)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  node_54_bias, AI_STATIC,
  29, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &node_54_bias_array, NULL)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  node_55_weights, AI_STATIC,
  30, 0x0,
  AI_SHAPE_INIT(4, 32, 3, 3, 32), AI_STRIDE_INIT(4, 4, 128, 384, 1152),
  1, &node_55_weights_array, NULL)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  node_55_bias, AI_STATIC,
  31, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &node_55_bias_array, NULL)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  node_57_scale, AI_STATIC,
  32, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &node_57_scale_array, NULL)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  node_57_bias, AI_STATIC,
  33, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &node_57_bias_array, NULL)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  node_59_weights, AI_STATIC,
  34, 0x0,
  AI_SHAPE_INIT(4, 32, 3, 3, 64), AI_STRIDE_INIT(4, 4, 128, 384, 1152),
  1, &node_59_weights_array, NULL)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  node_59_bias, AI_STATIC,
  35, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &node_59_bias_array, NULL)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  node_61_scale, AI_STATIC,
  36, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &node_61_scale_array, NULL)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  node_61_bias, AI_STATIC,
  37, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &node_61_bias_array, NULL)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  node_62_weights, AI_STATIC,
  38, 0x0,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 4, 256, 768, 2304),
  1, &node_62_weights_array, NULL)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  node_62_bias, AI_STATIC,
  39, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &node_62_bias_array, NULL)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  node_64_scale, AI_STATIC,
  40, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &node_64_scale_array, NULL)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  node_64_bias, AI_STATIC,
  41, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &node_64_bias_array, NULL)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  node_66_weights, AI_STATIC,
  42, 0x0,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 4, 256, 768, 2304),
  1, &node_66_weights_array, NULL)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  node_66_bias, AI_STATIC,
  43, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &node_66_bias_array, NULL)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  node_68_scale, AI_STATIC,
  44, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &node_68_scale_array, NULL)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  node_68_bias, AI_STATIC,
  45, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &node_68_bias_array, NULL)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  node_69_weights, AI_STATIC,
  46, 0x0,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 4, 256, 768, 2304),
  1, &node_69_weights_array, NULL)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  node_69_bias, AI_STATIC,
  47, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &node_69_bias_array, NULL)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  node_71_scale, AI_STATIC,
  48, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &node_71_scale_array, NULL)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  node_71_bias, AI_STATIC,
  49, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &node_71_bias_array, NULL)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  node_76_scale, AI_STATIC,
  50, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &node_76_scale_array, NULL)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  node_76_bias, AI_STATIC,
  51, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &node_76_bias_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_52_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &modelInput_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_52_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &node_52_weights, &node_52_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_52_layer, 1,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &node_52_chain,
  &AI_NET_OBJ_INSTANCE, &node_54_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_54_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_52_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_54_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &node_54_scale, &node_54_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_54_layer, 2,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &node_54_chain,
  &AI_NET_OBJ_INSTANCE, &node_55_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_55_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_54_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_55_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &node_55_weights, &node_55_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_55_layer, 4,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &node_55_chain,
  &AI_NET_OBJ_INSTANCE, &node_57_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_57_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_55_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_57_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &node_57_scale, &node_57_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_57_layer, 5,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &node_57_chain,
  &AI_NET_OBJ_INSTANCE, &node_58_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_58_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_57_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_58_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_58_layer, 6,
  POOL_TYPE, 0x0, NULL,
  pool, forward_mp,
  &node_58_chain,
  &AI_NET_OBJ_INSTANCE, &node_59_layer, AI_STATIC, 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .count_include_pad = 0, 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_59_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_58_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_59_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &node_59_weights, &node_59_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_59_layer, 8,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &node_59_chain,
  &AI_NET_OBJ_INSTANCE, &node_61_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_61_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_59_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_61_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &node_61_scale, &node_61_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_61_layer, 9,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &node_61_chain,
  &AI_NET_OBJ_INSTANCE, &node_62_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_62_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_61_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_62_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &node_62_weights, &node_62_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_62_layer, 11,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &node_62_chain,
  &AI_NET_OBJ_INSTANCE, &node_64_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_64_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_62_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_64_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &node_64_scale, &node_64_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_64_layer, 12,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &node_64_chain,
  &AI_NET_OBJ_INSTANCE, &node_65_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_65_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_64_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_65_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_65_layer, 13,
  POOL_TYPE, 0x0, NULL,
  pool, forward_mp,
  &node_65_chain,
  &AI_NET_OBJ_INSTANCE, &node_66_layer, AI_STATIC, 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .count_include_pad = 0, 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_66_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_65_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_66_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &node_66_weights, &node_66_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_66_layer, 15,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &node_66_chain,
  &AI_NET_OBJ_INSTANCE, &node_68_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_68_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_66_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_68_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &node_68_scale, &node_68_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_68_layer, 16,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &node_68_chain,
  &AI_NET_OBJ_INSTANCE, &node_69_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_69_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_68_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_69_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &node_69_weights, &node_69_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_69_layer, 18,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &node_69_chain,
  &AI_NET_OBJ_INSTANCE, &node_71_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_71_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_69_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_71_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &node_71_scale, &node_71_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_71_layer, 19,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &node_71_chain,
  &AI_NET_OBJ_INSTANCE, &node_72_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_72_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_71_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_72_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_72_layer, 20,
  POOL_TYPE, 0x0, NULL,
  pool, forward_mp,
  &node_72_chain,
  &AI_NET_OBJ_INSTANCE, &node_74_layer, AI_STATIC, 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .count_include_pad = 0, 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_74_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &node_72_output0, &fc1weight, &fc1bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_74_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_74_layer, 22,
  GEMM_TYPE, 0x0, NULL,
  gemm, forward_gemm,
  &node_74_chain,
  &AI_NET_OBJ_INSTANCE, &node_75_layer, AI_STATIC, 
  .alpha = 1.0, 
  .beta = 1.0, 
  .tA = 1, 
  .tB = 1, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_75_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_74_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_75_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_75_layer, 23,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &node_75_chain,
  &AI_NET_OBJ_INSTANCE, &node_76_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_76_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_75_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_76_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &node_76_scale, &node_76_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_76_layer, 24,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &node_76_chain,
  &AI_NET_OBJ_INSTANCE, &node_77_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_77_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &node_76_output, &fc2weight, &fc2bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_77_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_77_layer, 25,
  GEMM_TYPE, 0x0, NULL,
  gemm, forward_gemm,
  &node_77_chain,
  &AI_NET_OBJ_INSTANCE, &modelOutput_layer, AI_STATIC, 
  .alpha = 1.0, 
  .beta = 1.0, 
  .tA = 1, 
  .tB = 1, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  modelOutput_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_77_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &modelOutput_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  modelOutput_layer, 26,
  NL_TYPE, 0x0, NULL,
  nl, forward_sm,
  &modelOutput_chain,
  &AI_NET_OBJ_INSTANCE, &modelOutput_layer, AI_STATIC, 
  .nl_params = NULL, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 1091240, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 139648, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &modelInput_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &modelOutput_output),
  &node_52_layer, 0, NULL)



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
    modelInput_output_array.data = AI_PTR(NULL);
    modelInput_output_array.data_start = AI_PTR(NULL);
    node_52_output_array.data = AI_PTR(activations + 8576);
    node_52_output_array.data_start = AI_PTR(activations + 8576);
    node_54_output_array.data = AI_PTR(activations + 8576);
    node_54_output_array.data_start = AI_PTR(activations + 8576);
    node_55_output_array.data = AI_PTR(activations + 0);
    node_55_output_array.data_start = AI_PTR(activations + 0);
    node_57_output_array.data = AI_PTR(activations + 0);
    node_57_output_array.data_start = AI_PTR(activations + 0);
    node_58_output_array.data = AI_PTR(activations + 0);
    node_58_output_array.data_start = AI_PTR(activations + 0);
    node_59_output_array.data = AI_PTR(activations + 32768);
    node_59_output_array.data_start = AI_PTR(activations + 32768);
    node_61_output_array.data = AI_PTR(activations + 32768);
    node_61_output_array.data_start = AI_PTR(activations + 32768);
    node_62_output_array.data = AI_PTR(activations + 23808);
    node_62_output_array.data_start = AI_PTR(activations + 23808);
    node_64_output_array.data = AI_PTR(activations + 23808);
    node_64_output_array.data_start = AI_PTR(activations + 23808);
    node_65_output_array.data = AI_PTR(activations + 0);
    node_65_output_array.data_start = AI_PTR(activations + 0);
    node_66_output_array.data = AI_PTR(activations + 16384);
    node_66_output_array.data_start = AI_PTR(activations + 16384);
    node_68_output_array.data = AI_PTR(activations + 0);
    node_68_output_array.data_start = AI_PTR(activations + 0);
    node_69_output_array.data = AI_PTR(activations + 16384);
    node_69_output_array.data_start = AI_PTR(activations + 16384);
    node_71_output_array.data = AI_PTR(activations + 0);
    node_71_output_array.data_start = AI_PTR(activations + 0);
    node_72_output_array.data = AI_PTR(activations + 16384);
    node_72_output_array.data_start = AI_PTR(activations + 16384);
    node_74_output_array.data = AI_PTR(activations + 0);
    node_74_output_array.data_start = AI_PTR(activations + 0);
    node_75_output_array.data = AI_PTR(activations + 512);
    node_75_output_array.data_start = AI_PTR(activations + 512);
    node_76_output_array.data = AI_PTR(activations + 0);
    node_76_output_array.data_start = AI_PTR(activations + 0);
    node_77_output_array.data = AI_PTR(activations + 512);
    node_77_output_array.data_start = AI_PTR(activations + 512);
    modelOutput_output_array.data = AI_PTR(NULL);
    modelOutput_output_array.data_start = AI_PTR(NULL);
    
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
    
    fc2bias_array.format |= AI_FMT_FLAG_CONST;
    fc2bias_array.data = AI_PTR(weights + 0);
    fc2bias_array.data_start = AI_PTR(weights + 0);
    fc2weight_array.format |= AI_FMT_FLAG_CONST;
    fc2weight_array.data = AI_PTR(weights + 40);
    fc2weight_array.data_start = AI_PTR(weights + 40);
    fc1bias_array.format |= AI_FMT_FLAG_CONST;
    fc1bias_array.data = AI_PTR(weights + 5160);
    fc1bias_array.data_start = AI_PTR(weights + 5160);
    fc1weight_array.format |= AI_FMT_FLAG_CONST;
    fc1weight_array.data = AI_PTR(weights + 5672);
    fc1weight_array.data_start = AI_PTR(weights + 5672);
    node_52_weights_array.format |= AI_FMT_FLAG_CONST;
    node_52_weights_array.data = AI_PTR(weights + 529960);
    node_52_weights_array.data_start = AI_PTR(weights + 529960);
    node_52_bias_array.format |= AI_FMT_FLAG_CONST;
    node_52_bias_array.data = AI_PTR(weights + 533416);
    node_52_bias_array.data_start = AI_PTR(weights + 533416);
    node_54_scale_array.format |= AI_FMT_FLAG_CONST;
    node_54_scale_array.data = AI_PTR(weights + 533544);
    node_54_scale_array.data_start = AI_PTR(weights + 533544);
    node_54_bias_array.format |= AI_FMT_FLAG_CONST;
    node_54_bias_array.data = AI_PTR(weights + 533672);
    node_54_bias_array.data_start = AI_PTR(weights + 533672);
    node_55_weights_array.format |= AI_FMT_FLAG_CONST;
    node_55_weights_array.data = AI_PTR(weights + 533800);
    node_55_weights_array.data_start = AI_PTR(weights + 533800);
    node_55_bias_array.format |= AI_FMT_FLAG_CONST;
    node_55_bias_array.data = AI_PTR(weights + 570664);
    node_55_bias_array.data_start = AI_PTR(weights + 570664);
    node_57_scale_array.format |= AI_FMT_FLAG_CONST;
    node_57_scale_array.data = AI_PTR(weights + 570792);
    node_57_scale_array.data_start = AI_PTR(weights + 570792);
    node_57_bias_array.format |= AI_FMT_FLAG_CONST;
    node_57_bias_array.data = AI_PTR(weights + 570920);
    node_57_bias_array.data_start = AI_PTR(weights + 570920);
    node_59_weights_array.format |= AI_FMT_FLAG_CONST;
    node_59_weights_array.data = AI_PTR(weights + 571048);
    node_59_weights_array.data_start = AI_PTR(weights + 571048);
    node_59_bias_array.format |= AI_FMT_FLAG_CONST;
    node_59_bias_array.data = AI_PTR(weights + 644776);
    node_59_bias_array.data_start = AI_PTR(weights + 644776);
    node_61_scale_array.format |= AI_FMT_FLAG_CONST;
    node_61_scale_array.data = AI_PTR(weights + 645032);
    node_61_scale_array.data_start = AI_PTR(weights + 645032);
    node_61_bias_array.format |= AI_FMT_FLAG_CONST;
    node_61_bias_array.data = AI_PTR(weights + 645288);
    node_61_bias_array.data_start = AI_PTR(weights + 645288);
    node_62_weights_array.format |= AI_FMT_FLAG_CONST;
    node_62_weights_array.data = AI_PTR(weights + 645544);
    node_62_weights_array.data_start = AI_PTR(weights + 645544);
    node_62_bias_array.format |= AI_FMT_FLAG_CONST;
    node_62_bias_array.data = AI_PTR(weights + 793000);
    node_62_bias_array.data_start = AI_PTR(weights + 793000);
    node_64_scale_array.format |= AI_FMT_FLAG_CONST;
    node_64_scale_array.data = AI_PTR(weights + 793256);
    node_64_scale_array.data_start = AI_PTR(weights + 793256);
    node_64_bias_array.format |= AI_FMT_FLAG_CONST;
    node_64_bias_array.data = AI_PTR(weights + 793512);
    node_64_bias_array.data_start = AI_PTR(weights + 793512);
    node_66_weights_array.format |= AI_FMT_FLAG_CONST;
    node_66_weights_array.data = AI_PTR(weights + 793768);
    node_66_weights_array.data_start = AI_PTR(weights + 793768);
    node_66_bias_array.format |= AI_FMT_FLAG_CONST;
    node_66_bias_array.data = AI_PTR(weights + 941224);
    node_66_bias_array.data_start = AI_PTR(weights + 941224);
    node_68_scale_array.format |= AI_FMT_FLAG_CONST;
    node_68_scale_array.data = AI_PTR(weights + 941480);
    node_68_scale_array.data_start = AI_PTR(weights + 941480);
    node_68_bias_array.format |= AI_FMT_FLAG_CONST;
    node_68_bias_array.data = AI_PTR(weights + 941736);
    node_68_bias_array.data_start = AI_PTR(weights + 941736);
    node_69_weights_array.format |= AI_FMT_FLAG_CONST;
    node_69_weights_array.data = AI_PTR(weights + 941992);
    node_69_weights_array.data_start = AI_PTR(weights + 941992);
    node_69_bias_array.format |= AI_FMT_FLAG_CONST;
    node_69_bias_array.data = AI_PTR(weights + 1089448);
    node_69_bias_array.data_start = AI_PTR(weights + 1089448);
    node_71_scale_array.format |= AI_FMT_FLAG_CONST;
    node_71_scale_array.data = AI_PTR(weights + 1089704);
    node_71_scale_array.data_start = AI_PTR(weights + 1089704);
    node_71_bias_array.format |= AI_FMT_FLAG_CONST;
    node_71_bias_array.data = AI_PTR(weights + 1089960);
    node_71_bias_array.data_start = AI_PTR(weights + 1089960);
    node_76_scale_array.format |= AI_FMT_FLAG_CONST;
    node_76_scale_array.data = AI_PTR(weights + 1090216);
    node_76_scale_array.data_start = AI_PTR(weights + 1090216);
    node_76_bias_array.format |= AI_FMT_FLAG_CONST;
    node_76_bias_array.data = AI_PTR(weights + 1090728);
    node_76_bias_array.data_start = AI_PTR(weights + 1090728);
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
      
      .n_macc            = 29702230,
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

