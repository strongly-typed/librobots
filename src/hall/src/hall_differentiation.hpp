#ifndef LIBROBOTS_HALL_DIFFERENTIATION
#define LIBROBOTS_HALL_DIFFERENTIATION

/**
 * Find differences to previous hall state.
 * Valid hall states are 0 to 5.
 * Output is either +1, 0, or -1.
 * The output can then be integrated using HallIntegration.
 */
class HallDifferentiation
{
public:
	HallDifferentiation() : old_hall_state(0)
	{}

	int8_t
	get(const uint8_t hall_state) {
		if (hall_state > 5) {
			// invalid hall state
			return 0;
		}

		// Valid hall state
		int8_t diff = hall_state - old_hall_state;
		old_hall_state = hall_state;

		// Overflows
		if (diff == -5) { return +1; }
		if (diff == +5) { return -1; }

		if ((diff > 1) or (diff < -1)) {
			// invalid transition
			return 0;
		}

		return diff;
	}

protected:
	uint8_t
	old_hall_state;
};

#endif // LIBROBOTS_HALL_DIFFERENTIATION
