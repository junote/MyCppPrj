#pragma once 
#include <stdint.h>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

using uint8 = uint8_t;
using uint16 = uint16_t;
using uint32 = uint32_t;


using sint8 =  int8_t;
using sint16 = int16_t;
using sint32 = int32_t;


#define devInfo(...) spdlog::info(__VA_ARGS__)