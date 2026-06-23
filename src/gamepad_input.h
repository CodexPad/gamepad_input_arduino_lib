#include <stddef.h>
#include <stdint.h>

namespace gamepad_input {
#if __cplusplus >= 201703L
inline constexpr size_t kVersionMajor = 1;
inline constexpr size_t kVersionMinor = 0;
inline constexpr size_t kVersionPatch = 0;
inline constexpr size_t kAxisCount = 4;
inline constexpr uint8_t kAxisCenter = 0x80;
#else
static constexpr size_t kVersionMajor = 1;
static constexpr size_t kVersionMinor = 0;
static constexpr size_t kVersionPatch = 0;
static constexpr size_t kAxisCount = 4;
static constexpr uint8_t kAxisCenter = 0x80;
#endif

/**
 * @~English
 * @enum CodexPad::Button
 * @brief Button Type of CodexPad
 */
/**
 * @~Chinese
 * @enum CodexPad::Button
 * @brief CodexPad按键类型
 */
enum class Button : uint32_t {
  /**
   * @~English
   * @brief Up
   */
  /**
   * @~Chinese
   * @brief 上
   */
  kUp = uint32_t{1} << 0,

  /**
   * @~English
   * @brief Down
   */
  /**
   * @~Chinese
   * @brief 下
   */
  kDown = uint32_t{1} << 1,

  /**
   * @~English
   * @brief Left
   */
  /**
   * @~Chinese
   * @brief 左
   */
  kLeft = uint32_t{1} << 2,

  /**
   * @~English
   * @brief Right
   */
  /**
   * @~Chinese
   * @brief 右
   */
  kRight = uint32_t{1} << 3,

  /**
   * @~English
   * @brief Square or X
   */
  /**
   * @~Chinese
   * @brief 方形或者X
   */
  kSquareX = uint32_t{1} << 4,

  /**
   * @~English
   * @brief Triangle or Y
   */
  /**
   * @~Chinese
   * @brief 三角形或者Y
   */
  kTriangleY = uint32_t{1} << 5,

  /**
   * @~English
   * @brief Cross or A
   */
  /**
   * @~Chinese
   * @brief 叉或者A
   */
  kCrossA = uint32_t{1} << 6,

  /**
   * @~English
   * @brief Circle or B
   */
  /**
   * @~Chinese
   * @brief 圆形或者B
   */
  kCircleB = uint32_t{1} << 7,

  /**
   * @~English
   * @brief L1
   */
  /**
   * @~Chinese
   * @brief L1
   */
  kL1 = uint32_t{1} << 8,

  /**
   * @~English
   * @brief L2
   */
  /**
   * @~Chinese
   * @brief L2
   */
  kL2 = uint32_t{1} << 9,

  /**
   * @~English
   * @brief L3
   */
  /**
   * @~Chinese
   * @brief L3
   */
  kL3 = uint32_t{1} << 10,

  /**
   * @~English
   * @brief R1
   */
  /**
   * @~Chinese
   * @brief R1
   */
  kR1 = uint32_t{1} << 11,

  /**
   * @~English
   * @brief R2
   */
  /**
   * @~Chinese
   * @brief R2
   */
  kR2 = uint32_t{1} << 12,

  /**
   * @~English
   * @brief R3
   */
  /**
   * @~Chinese
   * @brief R3
   */
  kR3 = uint32_t{1} << 13,

  /**
   * @~English
   * @brief Select
   */
  /**
   * @~Chinese
   * @brief 选择
   */
  kSelect = uint32_t{1} << 14,

  /**
   * @~English
   * @brief Start
   */
  /**
   * @~Chinese
   * @brief 开始
   */
  kStart = uint32_t{1} << 15,

  /**
   * @~English
   * @brief Home
   */
  /**
   * @~Chinese
   * @brief 首页
   */
  kHome = uint32_t{1} << 16,
};

/**
 * @~English
 * @enum CodexPad::Axis
 * @brief Axis
 */
/**
 * @~Chinese
 * @enum CodexPad::Axis
 * @brief 轴
 */
enum class Axis : size_t {
  /**
   * @~English
   * @brief Left stick X axis
   */
  /**
   * @~Chinese
   * @brief 左摇杆X轴
   */
  kLeftStickX,

  /**
   * @~English
   * @brief Left stick Y axis
   */
  /**
   * @~Chinese
   * @brief 左摇杆Y轴
   */
  kLeftStickY,

  /**
   * @~English
   * @brief Right stick X axis
   */
  /**
   * @~Chinese
   * @brief 右摇杆X轴
   */
  kRightStickX,

  /**
   * @~English
   * @brief Right stick Y axis
   */
  /**
   * @~Chinese
   * @brief 右摇杆Y轴
   */
  kRightStickY,
};

inline constexpr Button operator|(Button a, Button b) noexcept {
  return static_cast<Button>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b));
}

inline constexpr bool operator&(uint32_t bits, Button b) noexcept { return (bits & static_cast<uint32_t>(b)) != 0; }

struct State {
  uint32_t buttons{0};
  uint8_t axes[kAxisCount]{kAxisCenter, kAxisCenter, kAxisCenter, kAxisCenter};

  void Reset() noexcept {
    buttons = 0;
    for (size_t i = 0; i < kAxisCount; ++i) {
      axes[i] = kAxisCenter;
    }
  }

  inline bool operator[](Button button) const noexcept { return (buttons & button) != 0; }

  /**
   * @~English
   * @brief Set Button
   * @param b Button
   */
  /**
   * @~Chinese
   * @brief 设置按键
   * @param b 按键
   */
  inline void Set(Button button) noexcept { buttons |= static_cast<uint32_t>(button); }

  /**
   * @~English
   * @brief Clear Button
   * @param b Button
   */
  /**
   * @~Chinese
   * @brief 清除按键
   * @param b 按键
   */
  inline void Clear(Button button) noexcept { buttons &= ~static_cast<uint32_t>(button); }

  /**
   * @~English
   * @brief Get Axis
   * @param a Axis
   */
  /**
   * @~Chinese
   * @brief 获取轴
   * @param a 轴
   */
  inline uint8_t& operator[](Axis axis) noexcept { return axes[static_cast<size_t>(axis)]; }

  /**
   * @~English
   * @brief Get Axis
   * @param a Axis
   */
  /**
   * @~Chinese
   * @brief 获取轴
   * @param a 轴
   */
  inline const uint8_t& operator[](Axis axis) const noexcept { return axes[static_cast<size_t>(axis)]; }
};

static_assert(sizeof(State) == 8, "State layout must be stable");
}  // namespace gamepad_input