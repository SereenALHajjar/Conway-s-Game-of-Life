#include "Simulation.hpp"
#include <iostream>

void Simulation::Draw()
{
    grid.Draw();
}
void Simulation::SetCellValue(int row, int column, int value)
{
    grid.SetValue(row, column, value);
}
int Simulation::CountLiveNeighbors(int row, int column)
{
    int live_neighbors = 0;
    std::vector<std::pair<int, int>> neighbors_offset = {
        {-1, -1},
        {-1, 0},
        {-1, +1},
        {0, -1},
        {0, +1},
        {+1, -1},
        {+1, -1},
        {+1, 0},
        {+1, +1}};
    for (auto [x, y] : neighbors_offset)
    {
        int neighbor_row = (row + x + grid.GetRows()) % grid.GetRows();
        int neighbor_column = (column + y + grid.GetColumns()) % grid.GetColumns();
        live_neighbors += grid.GetValue(neighbor_row, neighbor_column);
    }
    // std::cout<<"***"<<live_neighbors<<std::endl ;
    return live_neighbors;
}
void Simulation::Update()
{
    if (running == false)
        return;
    for (int row = 0; row < grid.GetRows(); row++)
    {
        for (int column = 0; column < grid.GetColumns(); column++)
        {
            int live_neighbors = CountLiveNeighbors(row, column);
            int cell_value = grid.GetValue(row, column);

            if (cell_value == 1)
            {
                if (live_neighbors > 3 || live_neighbors < 2)
                {
                    temp_grid.SetValue(row, column, 0);
                }
                else
                {
                    temp_grid.SetValue(row, column, 1);
                }
            }
            else
            {
                if (live_neighbors == 3)
                {
                    temp_grid.SetValue(row, column, 1);
                }
                else
                {
                    temp_grid.SetValue(row, column, 0);
                }
            }
        }
    }
    grid = temp_grid;
}
bool Simulation::IsRunning()
{
    return running;
}
void Simulation::Start()
{
    running = true;
}
void Simulation::Stop()
{
    running = false;
}
void Simulation::ClearGrid()
{
    if (!IsRunning())
    {
        grid.Clear();
    }
}
void Simulation::CreateRandomState()
{
    if (!IsRunning())
    {
        grid.FillRandom();
    }
}
void Simulation::ToggleCell(int row, int column)
{
    if (!IsRunning())
    {
        grid.ToggleCell(row, column);
    }
}