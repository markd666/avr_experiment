#ifndef HAL_LIBS_READER_H_
#define HAL_LIBS_READER_H_

#pragma once

#include <cstdint>
#include "span.h"

namespace hal {
namespace libs {

/**
 * @defgroup utilities General Purpose Utilities
 * @{
 */

/**
 * @brief Reader object definition.
 *
 * This object is supposed to provide means of reading various entries in a way
 * that is independent of both current memory layout and the actual
 * buffer location in memory.
 */
class Reader final {
 public:
    /**
     * @brief Default ctor.
     */
    Reader();

    /**
     * @brief ctor.
     * @param[in] view Window into memory buffer from which the data is read.
     */
    Reader(hal::libs::span<const uint8_t> view);

    /**
     * @brief Initializes generic buffer reader.
     *
     * @param[in] view Window into memory buffer from which the data is read.
     */
    void Initialize(hal::libs::span<const uint8_t> view);

    /**
     * @brief Jumps over the requested amount of bytes.
     * @param[in] length Number of bytes to skip.
     * @return Operation status.
     * @retval true Buffer is valid and there is still some unread data left in
     * it.
     * @retval false An attempt to read beyond the buffer end has been made.
     */
    bool Skip(uint16_t length);

    /**
     * @brief Returns current reader status.
     * @retval true Buffer is valid and there is still some unread data left in
     * it.
     * @retval false An attempt to read beyond the buffer end has been made.
     */
    bool Status() const;

    /**
     * @brief Returns the number of not yet read bytes from the buffer.
     * @retval true Buffer is valid and there is still some unread data left in
     * it.
     * @retval false An attempt to read beyond the buffer end has been made.
     */
    int32_t RemainingSize();

    /**
     * @brief Read single byte from the buffer and move the current position to
     * the next byte.
     * @return Read byte.
     */
    uint8_t ReadByte();

    /**
     * @brief Read single binary coded decimal byte from the buffer and move the
     * current position to the next byte.
     * @param[in] upperNibbleMask mask used for byte's upper nibble.
     * @return Read byte.
     */
    uint8_t ReadByteBCD(uint8_t upperNibbleMask);

    /**
     * @brief Read single 16 bit word with little-endian memory orientation from
     * the buffer
     * and advance the current buffer position to the next unread byte.
     * @return Read word.
     */
    uint16_t ReadWordLE();

    /**
     * @brief Read single 16 bit word with little-endian memory orientation from
     * the buffer,
     * convert it into signed value and advance the current buffer position to
     * the next unread byte.
     * Value is read assuming 2's complement notation.
     * @return Read signed word value.
     */
    int16_t ReadSignedWordLE();

    /**
     * @brief Read single 16 bit word with big-endian memory orientation from
     * the buffer
     * and advance the current buffer position to the next unread byte.
     * @return Read word.
     */
    uint16_t ReadWordBE();

    /**
     * @brief Read single 16 bit word with big-endian memory orientation from
     * the buffer
     * and advance the current buffer position to the next unread byte.
     * @return Read word.
     */
    int16_t ReadSignedWordBE();

    /**
     * @brief Read single 32 bit word with little-endian memory orientation from
     * the buffer
     * and advance the current buffer position to the next unread byte.
     * @return Read double word.
     */
    uint32_t ReadDoubleWordLE();

    /**
     * @brief Read single 32 bit word with little-endian memory orientation from
     * the buffer,
     * convert it into signed value and advance the current buffer position to
     * the next unread byte.
     * Value is read assuming 2's complement notation.
     * @return Read signed double word value.
     */
    int32_t ReadSignedDoubleWordLE();

    /**
     * @brief Read single 32 bit word with big-endian memory orientation from
     * the buffer
     * and advance the current buffer position to the next unread byte.
     * @return Read double word.
     */
    uint32_t ReadDoubleWordBE();

    /**
     * @brief Read single 32 bit word with big-endian memory orientation from
     * the buffer
     * and advance the current buffer position to the next unread byte.
     * @return Read double word.
     */
    int32_t ReadSignedDoubleWordBE();

    /**
     * @brief Read single 64 bit word with little-endian memory orientation from
     * the buffer
     * and advance the current buffer position to the next unread byte.
     * @return Read double word.
     */
    uint64_t ReadQuadWordLE();

    /**
     * @brief Read the requested number of bytes from the buffer.
     *
     * This method does not perform any operation/transformation on the data it
     * only ensures that
     * there are requested number of bytes available in the buffer and advances
     * the current
     * buffer position to the first byte beyond the requested block.
     * @param[in] length Size in bytes of the requested data block.
     * @return Pointer to the first byte of the requested memory block.
     */
    hal::libs::span<const uint8_t> ReadArray(uint16_t length);

    /**
     * @brief Resets reader to the initial state.
     */
    void Reset();

    /**
     * @brief Returns span of remaining part of buffer.
     * @return Span for remaining part of buffer
     */
    hal::libs::span<const uint8_t> ReadToEnd();

 private:
    bool UpdateState(uint16_t requestedSize);

    /**
     * @brief Window into memory buffer from which the data is read.
     */
    hal::libs::span<const uint8_t> buffer;

    /**
     * @brief Current buffer location.
     *
     * This value points to the first not yet processed byte.
     */
    uint16_t position;

    /**
     * @brief Current buffer status.
     *
     *  - True -> Data is valid.
     *  - False -> Buffer overflow detected.
     */
    bool isValid;
};

inline bool Reader::Status() const {
    return this->isValid;
}

inline void Reader::Reset() {
    this->position = 0;
    this->isValid = !this->buffer.empty();
}

/** @}*/

}  // namespace libs
}  // namespace hal

#endif  // HAL_LIBS_READER_H_
