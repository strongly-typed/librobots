#ifndef LIBROBOTS_HALL_INTEGRATION
#define LIBROBOTS_HALL_INTEGRATION

/**
 * Integrate small differences to absoulte value
 */
template < typename Type = int32_t >
class HallIntegration
{
public:
	HallIntegration() : state(0)
	{}

	Type
	update(const int8_t diff) {
		state += diff;
		return state;
	}

	Type
	get() {
		return state;
	}

	void
	reset() {
		state = 0;
	}

protected:
	Type state;
};

#endif // LIBROBOTS_HALL_INTEGRATION
