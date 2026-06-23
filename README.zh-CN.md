# Gamepad Input Arduino Lib （通用手柄输入库）

[English](README.md)

## 概述

一个**轻量**、**跨平台**、**零依赖**的 C++ 手柄输入数据结构库，专为 **Arduino / ESP32 / STM32 / PC** 设计，可作为多手柄协议的统一输入抽象层。

## 特性

- **跨平台**：AVR / ESP32 / STM32 / Linux / Windows / macOS
- **C++11 / 14 / 17 全兼容**
- **零动态分配**：无 STL 容器、无异常、无 RTTI
- **POD / memcpy 安全**：可直接用于 DMA、BLE、HID、日志回放
- **类型安全**：使用 enum class封装按钮与轴
- **语义清晰**：API 接近自然语言
- **体积小**：仅一个头文件

## 示例代码

```c++
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
  [[maybe_unused]] uint8_t x = state[Axis::kLeftStickX];

  // 清除按键
  state.Clear(Button::kCrossA);
}

void loop() {}
```
