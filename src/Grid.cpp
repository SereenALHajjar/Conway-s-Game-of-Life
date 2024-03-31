#include "Grid.hpp"
#include <raylib.h>
void Grid::Draw()
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            Color color = ((cells[row][column]) ? Color{0, 255, 0, 255} : Color{51, 51, 51, 255});
            DrawRectangle(column * cell_size, row * cell_size, cell_size - 1, cell_size - 1, color);
        }
    }
}
void Grid::SetValue(int row, int column, int value)
{
    if (IsWithinBounds(row, column))
    {
        cells[row][column] = value;
    }
}
int Grid::GetValue(int row, int column)
{
    if (IsWithinBounds(row, column))
        return cells[row][column];
    return 0;
}
bool Grid::IsWithinBounds(int row, int column)
{
    return row >= 0 && row < rows && column >= 0 && column < columns;
}
int Grid::GetColumns()
{
    return columns;
}
int Grid::GetRows()
{
    return rows;
}
void Grid::FillRandom()
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            cells[row][column] = GetRandomValue(0, 4) == 4 ? 1 : 0;
        }
    }
}
void Grid::Clear()
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            cells[row][column] = 0;
        }
    }
}
void Grid::ToggleCell(int row, int column)
{
    if (Grid::IsWithinBounds(row, column))
        cells[row][column] = 1 - cells[row][column];
}