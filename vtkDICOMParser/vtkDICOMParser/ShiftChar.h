#pragma once
#include <iostream>
#define ASCII_NUM_DEBUT static_cast<short>('0')
#define ASCII_NUM_FIN (static_cast<short>('9') + 1)
#define ASCII_LOWERCASE_DEBUT static_cast<short>('a')
#define ASCII_LOWERCASE_FIN (static_cast<short>('z') + 1)
#define ASCII_UPPERCASE_DEBUT static_cast<short>('A')
#define ASCII_UPPERCASE_FIN (static_cast<short>('Z') + 1)

class ShiftChar
{
public:
	explicit ShiftChar(char ori, int stplen);
	~ShiftChar();
	short CheckCharType() const;
	char Transform() ;
	ShiftChar* Update();
	ShiftChar* SetChar(char ori);
	ShiftChar* SetStepLength(int stplen);
	int GetStepLength() const;
	char GetChar() const;
	int CorrectNegativeStep(int stplen, int step);
	inline void MarkUpdate() {
		this->_updated = true;
	}
	inline void ClearUpdate() {
		this->_updated = false;
	}
	friend std::ostream& operator<< (std::ostream&, const ShiftChar*);
private:
	char _ori;
	char _pro;
	int	 _stplen;
	bool _updated;
};

