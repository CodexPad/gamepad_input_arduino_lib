#include "gamepad_input.h"

using namespace gamepad_input;

void setup() {
  Serial.begin(115200);
  State state;

  // 设置按键
  state.Set(Button::kCrossA);
  state.Set(Button::kStart);

  // 判断按键
  if (state[Button::kCrossA]) {
    // A 键按下
  }

  // 组合键判断
  if (state[Button::kCrossA | Button::kStart]) {
    // A + Start
  }

  // 访问摇杆轴
  state[Axis::kLeftStickX] = 200;
  uint8_t x = state[Axis::kLeftStickX];
  Serial.println(x);
  // 清除按键
  state.Clear(Button::kCrossA);
}

void loop() {}