#ifndef LIBROBOTS_HALL_DECODER
#define LIBROBOTS_HALL_DECODER

#include <stdint.h>

/**
 * Lookup from Hall pins read to Hall states.
 */
class HallDecoderMaxon
{
public:
	/// Transformation from Hall pins to Hall state
	static uint8_t
	getState(const uint8_t pinstate) {
		return Lut[pinstate];
	}

private:
	static constexpr uint8_t
	Lut[8] = {
		6, /* 0b000 = 0 invalid */
		5, /* 0b001 = 1 */
		3, /* 0b010 = 2 */
		4, /* 0b011 = 3 */
		1, /* 0b100 = 4 */
		0, /* 0b101 = 5 */
		2, /* 0b110 = 6 */
		7, /* 0b111 = 7 invalid */
	};
};

#endif // LIBROBOTS_HALL_DECODER
