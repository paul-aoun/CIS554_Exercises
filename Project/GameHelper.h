#ifndef GAMEUTILITY_H
#define GAMEUTILITY_H

#include <string>

class GameHelper {

private:
	std::string name{ "" };

public:
	virtual const void setName(std::string);
	virtual const std::string getName() const;
};

#endif
