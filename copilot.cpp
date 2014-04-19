#include <stdbool.h>
#include <stdint.h>


#include "copilot.h"


static uint64_t __global_clock = 0;



static const uint32_t __coverage_len = 1;
static uint32_t __coverage[1] = {0};
static uint32_t __coverage_index = 0;
struct {  /* state */
  struct {  /* copilot */
    uint32_t queue_buffer_str0[1];
    uint16_t queue_pointer_str0;
    uint32_t tmp0;
  } copilot;
} state =
{  /* state */
  {  /* copilot */
    /* queue_buffer_str0 */
    { 0UL
    },
    /* queue_pointer_str0 */  0,
    /* tmp0 */  0UL
  }
};

/* copilot.update_state_s0 */
static void __r1() {
  bool __0 = true;
  uint16_t __1 = state.copilot.queue_pointer_str0;
  uint16_t __2 = 0;
  uint16_t __3 = __1 + __2;
  uint16_t __4 = 1;
  uint16_t __5 = __3 % __4;
  uint32_t __6 = state.copilot.queue_buffer_str0[__5];
  uint32_t __7 = 1UL;
  uint32_t __8 = __6 + __7;
  if (__0) {
    __coverage[0] = __coverage[0] | (1 << 1);
  }
  state.copilot.tmp0 = __8;
}

/* copilot.fire_trigger_shiftOut */
static void __r0() {
  bool __0 = true;
  uint16_t __1 = state.copilot.queue_pointer_str0;
  uint16_t __2 = 0;
  uint16_t __3 = __1 + __2;
  uint16_t __4 = 1;
  uint16_t __5 = __3 % __4;
  uint32_t __6 = state.copilot.queue_buffer_str0[__5];
  uint32_t __7 = 20UL;
  uint32_t __8 = __6 % __7;
  uint32_t __9 = 40UL;
  uint32_t __10 = __6 / __9;
  uint32_t __11 = __10 % __9;
  uint32_t __12 = __11 / __7;
  uint32_t __13 = 0UL;
  bool __14 = __12 == __13;
  uint32_t __15 = __11 % __7;
  uint32_t __16 = __7 - __15;
  uint32_t __17 = __14 ? __11 : __16;
  bool __18 = __8 < __17;
  uint32_t __19 = 500UL;
  uint32_t __20 = __6 / __19;
  uint32_t __21 = __18 ? __20 : __13;
  uint32_t __22 = 3UL;
  uint32_t __23 = __21 << __22;
  uint32_t __24 = 7UL;
  uint32_t __25 = __21 & __24;
  uint32_t __26 = __23 | __25;
  uint32_t __27 = __26 << __22;
  uint32_t __28 = __27 | __25;
  uint32_t __29 = __28 << __22;
  uint32_t __30 = __29 | __25;
  uint32_t __31 = __30 << __22;
  uint32_t __32 = __31 | __25;
  uint32_t __33 = __32 << __22;
  uint32_t __34 = __33 | __25;
  uint32_t __35 = __34 << __22;
  uint32_t __36 = __35 | __25;
  uint32_t __37 = __36 << __22;
  uint32_t __38 = __37 | __25;
  uint32_t __39 = __38 << __22;
  uint32_t __40 = __39 | __25;
  uint32_t __41 = __40 << __22;
  uint32_t __42 = __41 | __25;
  uint32_t __43 = __42 << __22;
  uint32_t __44 = __43 | __25;
  uint32_t __45 = __44 << __22;
  uint32_t __46 = __45 | __25;
  uint32_t __47 = __46 << __22;
  uint32_t __48 = __47 | __25;
  uint32_t __49 = __48 << __22;
  uint32_t __50 = __49 | __25;
  uint32_t __51 = __50 << __22;
  uint32_t __52 = __51 | __25;
  uint32_t __53 = __52 << __22;
  uint32_t __54 = __53 | __25;
  uint32_t __55 = __54 << __22;
  uint32_t __56 = __55 | __25;
  uint32_t __57 = __56 << __22;
  uint32_t __58 = __57 | __25;
  uint32_t __59 = __58 << __22;
  uint32_t __60 = __59 | __25;
  uint32_t __61 = __60 << __22;
  uint32_t __62 = __61 | __25;
  uint32_t __63 = __62 << __22;
  uint32_t __64 = __63 | __25;
  uint32_t __65 = __64 << __22;
  uint32_t __66 = __65 | __25;
  uint32_t __67 = __66 << __22;
  uint32_t __68 = __67 | __25;
  uint32_t __69 = __68 << __22;
  uint32_t __70 = __69 | __25;
  uint32_t __71 = __70 << __22;
  uint32_t __72 = __71 | __25;
  if (__0) {
    shiftOut(__72);
    __coverage[0] = __coverage[0] | (1 << 0);
  }
}

/* copilot.update_buffer_s0 */
static void __r2() {
  bool __0 = true;
  uint32_t __1 = state.copilot.tmp0;
  uint16_t __2 = state.copilot.queue_pointer_str0;
  uint16_t __3 = 1;
  uint16_t __4 = __2 + __3;
  bool __5 = __4 < __3;
  uint16_t __6 = 0;
  uint16_t __7 = __5 ? __4 : __6;
  if (__0) {
    __coverage[0] = __coverage[0] | (1 << 2);
  }
  state.copilot.queue_buffer_str0[__2] = __1;
  state.copilot.queue_pointer_str0 = __7;
}


static void __assertion_checks() {
}


void copilot()
{

  {
    static uint8_t __scheduling_clock = 4;
    if (__scheduling_clock == 0) {
      __assertion_checks(); __r1();  /* copilot.update_state_s0 */
      __scheduling_clock = 7;
    }
    else {
      __scheduling_clock = __scheduling_clock - 1;
    }
  }
  {
    static uint8_t __scheduling_clock = 5;
    if (__scheduling_clock == 0) {
      __assertion_checks(); __r0();  /* copilot.fire_trigger_shiftOut */
      __scheduling_clock = 7;
    }
    else {
      __scheduling_clock = __scheduling_clock - 1;
    }
  }
  {
    static uint8_t __scheduling_clock = 7;
    if (__scheduling_clock == 0) {
      __assertion_checks(); __r2();  /* copilot.update_buffer_s0 */
      __scheduling_clock = 7;
    }
    else {
      __scheduling_clock = __scheduling_clock - 1;
    }
  }

  __global_clock = __global_clock + 1;

}

void step()
{
  copilot();copilot();copilot();copilot();copilot();copilot();copilot();copilot();
}

