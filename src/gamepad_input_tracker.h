
#pragma once

#ifndef GAMEPAD_INPUT_TRACKER_H
#define GAMEPAD_INPUT_TRACKER_H

#include <Arduino.h>

#include "gamepad_input_state.h"

namespace gamepad::input {
class Tracker {
 public:
  const State& raw() const noexcept { return current_; }
  void Reset() noexcept {
    current_.Reset();
    previous_.Reset();
  }

  void Tick() noexcept { previous_ = current_; }
  void Update(State state) noexcept { current_ = state; };
  bool pressed(Button button) const noexcept { return current_[button] && !previous_[button]; }
  bool released(Button button) const noexcept { return !current_[button] && previous_[button]; }
  bool holding(Button button) const noexcept { return current_[button] && previous_[button]; }
  bool AxisChanged(Axis axis, uint8_t threshold) const noexcept {
    return AxisChanged(previous_[axis], current_[axis], threshold);
  }
  bool operator[](Button button) const noexcept { return current_[button]; }
  uint8_t operator[](Axis axis) const noexcept { return current_[axis]; }

 private:
  static bool AxisChanged(int16_t previous, int16_t current, uint8_t threshold) noexcept {
    return previous != current &&
           (current == 0 || current == 255 || static_cast<uint8_t>(abs(current - previous)) >= threshold);
  }

  State current_{};
  State previous_{};
};
}  // namespace gamepad::input

#endif