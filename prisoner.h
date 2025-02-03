#ifndef PRISONER_H
#define PRISONER_H

class Prisoner
{
	bool lit;
public:
	/* getters */

	// Returns if the player's candle is lit.
	bool IsLit();

	/* setters */

	// Sets the state of the player's candle.
	void SetLit(bool newState);

	/* constructors */
};

#endif