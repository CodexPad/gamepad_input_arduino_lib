#include "gamepad_input_tracker.h"

using namespace gamepad::input;

Tracker g_input_tracker;

void setup() { Serial.begin(115200); }

void loop() {
  State state;

  state.Set(Button::kCrossA);
  state.Set(Button::kStart);

  state[Axis::kLeftStickX] = 50;
  state[Axis::kLeftStickY] = 100;
  state[Axis::kRightStickX] = 150;
  state[Axis::kRightStickY] = 200;

  g_input_tracker.Tick();
  g_input_tracker.Update(state);

  Serial.println(g_input_tracker.pressed(Button::kCrossA));
  Serial.println(g_input_tracker.released(Button::kStart));
  Serial.println(g_input_tracker.holding(Button::kCrossA));

  delay(1000);
}