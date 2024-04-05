#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <utility>
#include <limits>

using namespace std;

class Cell;
class Grid;

class Organism
{
public:
	Organism(const int bp, int l, int bc) : breedingPoint(bp), life(l), breedingCompletion(bc){};
	virtual void persistThroughTime(Cell *currentCell, Cell **newCell) = 0;
	virtual string getType() const = 0;
	int getLife() const { return life; }
	void incrementLife() { life++; }
	int getBreedingCompletion() const { return breedingCompletion; }
	void incrementBreedingCompletion() { breedingCompletion++; }
	void setBreedingCompletion(int newBreedingCompletion) { breedingCompletion = newBreedingCompletion; }
	const int breedingPoint;

private:
	int life;
	int breedingCompletion;
	virtual void move(const vector<Cell *> &availableCells, Cell **newCell) = 0;
	virtual void createOffspring(Cell *location) const = 0;
	virtual void attemptToBreed(const vector<Cell *> &availableCells) = 0;
};

class Cell
{
public:
	Cell(int r, int c) : row(r), column(c), organism(nullptr) {}

	void display() const
	{
		if (containsPredator())
		{
			cout << "X";
		}
		else if (containsPrey())
		{
			cout << "o";
		}
		else
		{
			cout << "-";
		}
	}

	int getRow() { return row; };
	int getColumn() { return column; };
	bool isEmpty() const { return organism == nullptr; };

	void deOccupy()
	{
		organism = nullptr;
	}

	void occupy(Organism *newOrganism)
	{
		if (!isEmpty())
		{
			delete organism;
		}
		organism = newOrganism;
	}

	void experienceTime();

	bool containsPrey() const
	{
		if (organism != nullptr && organism->getType() == "Prey")
		{
			return true;
		}
		return false;
	}

	bool containsPredator() const
	{
		if (organism != nullptr && organism->getType() == "Predator")
		{
			return true;
		}
		return false;
	}

	pair<int, int> getPosition() const
	{
		return {row, column};
	}

	void setRow(int r)
	{
		row = r;
	}
	void setCol(int c)
	{
		column = c;
	}

private:
	Organism *organism;
	int row;
	int column;
};

class Prey : public Organism
{
public:
	Prey(int breedingPoint = 3, int life = 0, int breedingCompletion = 0) : Organism(breedingPoint, life, breedingCompletion) { srand(time(NULL)); }

	void persistThroughTime(Cell *currentCell, Cell **newCell) override;

	string getType() const override { return "Prey"; }

private:
	void move(const vector<Cell *> &availableCells, Cell **newCell) override
	{
		incrementLife();
		incrementBreedingCompletion();

		int selectedIndex = rand() % availableCells.size();
		Cell *selectedCell = availableCells[selectedIndex];

		if (selectedCell != nullptr && selectedCell->isEmpty())
		{
			*newCell = selectedCell;
			selectedCell->occupy(this);
		}
	}

	void createOffspring(Cell *location) const override
	{
		if (location && location->isEmpty())
		{
			Prey *child = new Prey();
			location->occupy(child);
		}
	}

	void attemptToBreed(const vector<Cell *> &availableCells) override
	{
		if (getBreedingCompletion() >= breedingPoint)
		{

			for (auto *cell : availableCells)
			{
				if (cell != nullptr && cell->isEmpty())
				{
					createOffspring(cell);
					setBreedingCompletion(0);
					return;
				}
			}

			incrementBreedingCompletion();
		}
	}
};

class Predator : public Organism
{
public:
	Predator(int breedingPoint = 8, int life = 0, int breedingCompletion = 0) : Organism(breedingPoint, life, breedingCompletion), lifeWithoutFood(0), theInevitabilityOfLife(false) { srand(time(NULL)); }
	string getType() const override { return "Predator"; }
	int lifeWithoutFood;
	void persistThroughTime(Cell *currentCell, Cell **newCell) override;
	bool isReadyForDeath()
	{
		return theInevitabilityOfLife;
	}

private:
	bool theInevitabilityOfLife;
	void move(const vector<Cell *> &availableCells, Cell **newCell) override
	{
		incrementLife();
		incrementBreedingCompletion();
		bool foundPrey = false;

		for (auto *cell : availableCells)
		{
			if (cell != nullptr && cell->containsPrey())
			{
				*newCell = cell;
				cell->occupy(this);
				lifeWithoutFood = 0;
				foundPrey = true;
				break;
			}
		}

		if (!foundPrey)
		{
			lifeWithoutFood++;
			int selectedIndex = rand() % availableCells.size();
			Cell *selectedCell = availableCells[selectedIndex];
			if (selectedCell != nullptr && selectedCell->isEmpty())
			{
				*newCell = selectedCell;
				selectedCell->occupy(this);
			}
		}
	}

	void createOffspring(Cell *location) const override
	{
		if (location && location->isEmpty())
		{
			Predator *child = new Predator();
			location->occupy(child);
		}
	}

	void attemptToBreed(const vector<Cell *> &availableCells) override
	{
		if (getBreedingCompletion() >= breedingPoint)
		{
			for (auto *cell : availableCells)
			{
				if (cell != nullptr && cell->isEmpty())
				{
					createOffspring(cell);
					setBreedingCompletion(0);
					return;
				}
			}
			incrementBreedingCompletion();
		}
	}
};

void Cell::experienceTime()
{
	Cell *newCell = nullptr;

	if (organism != nullptr)
	{
		organism->persistThroughTime(this, &newCell);
	}
	else
	{
		cout << "error when experiencing time";
		return;
	}

	if (organism->getType() == "Predator" && dynamic_cast<Predator *>(organism)->isReadyForDeath())
	{
		if (newCell != nullptr)
		{
			newCell->deOccupy();
		}
		delete organism;
		deOccupy();
		return;
	}

	if (newCell != nullptr && newCell->organism == this->organism)
	{
		deOccupy();
	}
}

class Grid
{
public:
	static Grid &getInstance()
	{
		static Grid instance(20, 20);
		return instance; 
	}

	void generateGrid(const vector<vector<int>> &layout);

	void display() const
	{
		for (const auto &row : grid)
		{
			for (const auto &cell : row)
			{
				cell.display();
				cout << " ";
			}
			cout << endl;
		}
	}

	void progressTime()
	{
		progressPredators();
		progressPrey();
		currentTime++;
		display();
	}

	void progressPredators()
	{
		vector<Cell *> predatorCells;

		for (auto &row : grid)
		{
			for (auto &cell : row)
			{
				if (cell.containsPredator())
				{
					predatorCells.push_back(&cell);
				}
			}
		}

		for (auto cell : predatorCells)
		{
			progressOrganism(*cell);
		}
	}

	void progressPrey()
	{
		vector<Cell *> preyCells;

		for (auto &row : grid)
		{
			for (auto &cell : row)
			{
				if (cell.containsPrey())
				{
					preyCells.push_back(&cell);
				}
			}
		}

		for (auto cell : preyCells)
		{
			progressOrganism(*cell);
		}
	}

	void progressOrganism(Cell &cell)
	{
		assert(cell.containsPredator() || cell.containsPrey());
		cell.experienceTime(); // Assuming this might utilize neighbors
	}

	vector<Cell *> getNeighbours(const Cell &cell)
	{
		pair<int, int> position = cell.getPosition();
		vector<Cell *> neighbours(4, nullptr); // NORTH, SOUTH, EAST, WEST

		assert(position.first >= 0 && position.first < height);
		assert(position.second >= 0 && position.second < width);

		// Get neighbours, checking bounds
		if (position.first > 0)
			neighbours[0] = &grid[position.first - 1][position.second]; // NORTH
		if (position.first < height - 1)
			neighbours[1] = &grid[position.first + 1][position.second]; // SOUTH
		if (position.second > 0)
			neighbours[2] = &grid[position.first][position.second - 1]; // WEST
		if (position.second < width - 1)
			neighbours[3] = &grid[position.first][position.second + 1]; // EAST

		return neighbours;
	}

private:
	Grid(int width, int height) : width(width), height(height), currentTime(0) { grid.resize(height, vector<Cell>(width, Cell(0, 0))); }
	const int width, height;
	vector<vector<Cell>> grid;
	int currentTime;
};

void Grid::generateGrid(const vector<vector<int>> &layout)
{
	for (int r = 0; r < height; ++r)
	{
		for (int c = 0; c < width; ++c)
		{
			grid[r][c].setRow(r);
			grid[r][c].setCol(c);
			grid[r][c].deOccupy();

			if (layout[r][c] == 1)
			{
				grid[r][c].occupy(new Prey());
			}
			else if (layout[r][c] == 2)
			{
				grid[r][c].occupy(new Predator());
			}
		}
	}
}

void Prey::persistThroughTime(Cell *currentCell, Cell **newCell)
{
	vector<Cell *> availableCells = Grid::getInstance().getNeighbours(*currentCell);
	move(availableCells, newCell);
	if (*newCell != nullptr && *newCell != currentCell)
	{
		availableCells = Grid::getInstance().getNeighbours(**newCell);
	}
	attemptToBreed(availableCells);
}

void Predator::persistThroughTime(Cell *currentCell, Cell **newCell)
{
	vector<Cell *> availableCells = Grid::getInstance().getNeighbours(*currentCell);
	move(availableCells, newCell);
	
	if (lifeWithoutFood >= 3)
	{
		theInevitabilityOfLife = true;
		return;
	}

	if (*newCell != nullptr && *newCell != currentCell)
	{
		availableCells = Grid::getInstance().getNeighbours(**newCell);
	}

	attemptToBreed(availableCells);
}

int main()
{
	// vector<vector<int>> layout = {
	//     {0, 1, 0, 2, 0},
	//     {0, 0, 0, 0, 1},
	//     {0, 1, 0, 0, 0},
	//     {0, 0, 0, 0, 1},
	//     {0, 1, 0, 1, 2}
	// };

	vector<vector<int>> layout = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{2, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0},
		{0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};

	auto &grid = Grid::getInstance();
	int time = 0;
	grid.generateGrid(layout);
	cout << "time: " << time << endl;
	grid.display();

	string input;

	while (true)
	{
		string input;
		getline(std::cin, input);

		if (input == "exit")
		{
			break;
		}
		cout << "time: " << ++time << endl;
		grid.progressTime();
		cout << endl;
	}

	return 0;
}
