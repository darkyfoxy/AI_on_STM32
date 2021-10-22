/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Tue Oct 19 13:31:59 2021
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
#define AI_NETWORK_MODEL_SIGNATURE     "df31937334d89e3449d3ab09c1c6059b"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Tue Oct 19 13:31:59 2021"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array modelInput_output_array;   /* Array #0 */
AI_STATIC ai_array node_8_output_array;   /* Array #1 */
AI_STATIC ai_array node_10_output_array;   /* Array #2 */
AI_STATIC ai_array node_12_output_array;   /* Array #3 */
AI_STATIC ai_array node_14_output_array;   /* Array #4 */
AI_STATIC ai_array node_16_output_array;   /* Array #5 */
AI_STATIC ai_array modelOutput_output_array;   /* Array #6 */
AI_STATIC ai_array node_8_weights_array;   /* Array #7 */
AI_STATIC ai_array node_8_bias_array;   /* Array #8 */
AI_STATIC ai_array node_12_weights_array;   /* Array #9 */
AI_STATIC ai_array node_12_bias_array;   /* Array #10 */
AI_STATIC ai_array node_16_weights_array;   /* Array #11 */
AI_STATIC ai_array node_16_bias_array;   /* Array #12 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor modelInput_output;   /* Tensor #0 */
AI_STATIC ai_tensor node_8_output;   /* Tensor #1 */
AI_STATIC ai_tensor node_10_output;   /* Tensor #2 */
AI_STATIC ai_tensor node_12_output;   /* Tensor #3 */
AI_STATIC ai_tensor node_14_output;   /* Tensor #4 */
AI_STATIC ai_tensor node_16_output;   /* Tensor #5 */
AI_STATIC ai_tensor modelOutput_output;   /* Tensor #6 */
AI_STATIC ai_tensor node_8_weights;   /* Tensor #7 */
AI_STATIC ai_tensor node_8_bias;   /* Tensor #8 */
AI_STATIC ai_tensor node_12_weights;   /* Tensor #9 */
AI_STATIC ai_tensor node_12_bias;   /* Tensor #10 */
AI_STATIC ai_tensor node_16_weights;   /* Tensor #11 */
AI_STATIC ai_tensor node_16_bias;   /* Tensor #12 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain node_8_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain node_10_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain node_12_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain node_14_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain node_16_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain modelOutput_chain;   /* Chain #5 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_dense node_8_layer; /* Layer #0 */
AI_STATIC ai_layer_nl node_10_layer; /* Layer #1 */
AI_STATIC ai_layer_dense node_12_layer; /* Layer #2 */
AI_STATIC ai_layer_nl node_14_layer; /* Layer #3 */
AI_STATIC ai_layer_dense node_16_layer; /* Layer #4 */
AI_STATIC ai_layer_nl modelOutput_layer; /* Layer #5 */




/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  modelInput_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 784, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  node_8_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 200, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  node_10_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 200, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  node_12_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 200, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  node_14_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 200, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  node_16_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  modelOutput_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 10, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  node_8_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 156800, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  node_8_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 200, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  node_12_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 40000, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  node_12_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 200, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  node_16_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2000, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  node_16_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10, AI_STATIC)

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  modelInput_output, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 784, 1, 1), AI_STRIDE_INIT(4, 4, 4, 3136, 3136),
  1, &modelInput_output_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  node_8_output, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 1, 200, 1, 1), AI_STRIDE_INIT(4, 4, 4, 800, 800),
  1, &node_8_output_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  node_10_output, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 1, 200, 1, 1), AI_STRIDE_INIT(4, 4, 4, 800, 800),
  1, &node_10_output_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  node_12_output, AI_STATIC,
  3, 0x0,
  AI_SHAPE_INIT(4, 1, 200, 1, 1), AI_STRIDE_INIT(4, 4, 4, 800, 800),
  1, &node_12_output_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  node_14_output, AI_STATIC,
  4, 0x0,
  AI_SHAPE_INIT(4, 1, 200, 1, 1), AI_STRIDE_INIT(4, 4, 4, 800, 800),
  1, &node_14_output_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  node_16_output, AI_STATIC,
  5, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &node_16_output_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  modelOutput_output, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &modelOutput_output_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  node_8_weights, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 784, 200, 1, 1), AI_STRIDE_INIT(4, 4, 3136, 627200, 627200),
  1, &node_8_weights_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  node_8_bias, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 1, 200, 1, 1), AI_STRIDE_INIT(4, 4, 4, 800, 800),
  1, &node_8_bias_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  node_12_weights, AI_STATIC,
  9, 0x0,
  AI_SHAPE_INIT(4, 200, 200, 1, 1), AI_STRIDE_INIT(4, 4, 800, 160000, 160000),
  1, &node_12_weights_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  node_12_bias, AI_STATIC,
  10, 0x0,
  AI_SHAPE_INIT(4, 1, 200, 1, 1), AI_STRIDE_INIT(4, 4, 4, 800, 800),
  1, &node_12_bias_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  node_16_weights, AI_STATIC,
  11, 0x0,
  AI_SHAPE_INIT(4, 200, 10, 1, 1), AI_STRIDE_INIT(4, 4, 800, 8000, 8000),
  1, &node_16_weights_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  node_16_bias, AI_STATIC,
  12, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &node_16_bias_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &modelInput_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &node_8_weights, &node_8_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_8_layer, 1,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &node_8_chain,
  &AI_NET_OBJ_INSTANCE, &node_10_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_10_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_10_layer, 2,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &node_10_chain,
  &AI_NET_OBJ_INSTANCE, &node_12_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &node_12_weights, &node_12_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_12_layer, 4,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &node_12_chain,
  &AI_NET_OBJ_INSTANCE, &node_14_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_14_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_14_layer, 5,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &node_14_chain,
  &AI_NET_OBJ_INSTANCE, &node_16_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_16_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &node_16_weights, &node_16_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_16_layer, 7,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &node_16_chain,
  &AI_NET_OBJ_INSTANCE, &modelOutput_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  modelOutput_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &modelOutput_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  modelOutput_layer, 8,
  NL_TYPE, 0x0, NULL,
  nl, forward_sm,
  &modelOutput_chain,
  &AI_NET_OBJ_INSTANCE, &modelOutput_layer, AI_STATIC, 
  .nl_params = NULL, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 796840, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 1600, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &modelInput_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &modelOutput_output),
  &node_8_layer, 0, NULL)



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
    node_8_output_array.data = AI_PTR(activations + 0);
    node_8_output_array.data_start = AI_PTR(activations + 0);
    node_10_output_array.data = AI_PTR(activations + 0);
    node_10_output_array.data_start = AI_PTR(activations + 0);
    node_12_output_array.data = AI_PTR(activations + 800);
    node_12_output_array.data_start = AI_PTR(activations + 800);
    node_14_output_array.data = AI_PTR(activations + 0);
    node_14_output_array.data_start = AI_PTR(activations + 0);
    node_16_output_array.data = AI_PTR(activations + 800);
    node_16_output_array.data_start = AI_PTR(activations + 800);
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
    
    node_8_weights_array.format |= AI_FMT_FLAG_CONST;
    node_8_weights_array.data = AI_PTR(weights + 0);
    node_8_weights_array.data_start = AI_PTR(weights + 0);
    node_8_bias_array.format |= AI_FMT_FLAG_CONST;
    node_8_bias_array.data = AI_PTR(weights + 627200);
    node_8_bias_array.data_start = AI_PTR(weights + 627200);
    node_12_weights_array.format |= AI_FMT_FLAG_CONST;
    node_12_weights_array.data = AI_PTR(weights + 628000);
    node_12_weights_array.data_start = AI_PTR(weights + 628000);
    node_12_bias_array.format |= AI_FMT_FLAG_CONST;
    node_12_bias_array.data = AI_PTR(weights + 788000);
    node_12_bias_array.data_start = AI_PTR(weights + 788000);
    node_16_weights_array.format |= AI_FMT_FLAG_CONST;
    node_16_weights_array.data = AI_PTR(weights + 788800);
    node_16_weights_array.data_start = AI_PTR(weights + 788800);
    node_16_bias_array.format |= AI_FMT_FLAG_CONST;
    node_16_bias_array.data = AI_PTR(weights + 796800);
    node_16_bias_array.data_start = AI_PTR(weights + 796800);
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
      
      .n_macc            = 199760,
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

