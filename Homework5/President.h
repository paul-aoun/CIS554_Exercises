#include <string>

class President {

private:
	std::string name{ "" };
	int order{ 0 }, randomOrder{ 0 }, guessedOrder{ 0 };

public:
	void setName(std::string);
	void setOrder(int);
	void setRandomOrder(int);
	void setGuessedOrder(int);

	const std::string getName() const;
	const int getOrder() const;
	const int getRandomOrder() const;
	const int getGuessedOrder() const;
};
