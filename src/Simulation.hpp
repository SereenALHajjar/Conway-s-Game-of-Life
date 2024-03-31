#include "Grid.hpp"

class Simulation
{
public:
    Simulation(int width, int height, int cell_size) : grid(width, height, cell_size), temp_grid(width, height, cell_size), running(false){};
    void Draw();
    void SetCellValue(int row, int column, int value);
    int CountLiveNeighbors(int row, int column);
    void Update();
    bool IsRunning();
    void Start();
    void Stop();
    void ClearGrid();
    void CreateRandomState();
    void ToggleCell(int row, int column);

private:
    Grid grid;
    Grid temp_grid;
    bool running;
};