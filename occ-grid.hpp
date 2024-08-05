#pragma once
#include <vector>

/**
 * @brief class for 2d grid
 * For simplicity, the grid size is hard coded to 64x64
 * I have API to change grid size
*/
class OccGrid {
private:
    int m_width = 64;
    int m_height = 64;
    std::vector<int> m_grid = std::vector<int>(64*64, -1);

public:
    /**
     * @brief covert grid cell index from 1d to 2d
     * @param idx 1d index of grid cell
     * @return a pair of int consists of row and col
    */
    std::pair<int,int> idx_1d_to_2d(int idx) const;

    /**
     * @brief convert grid cell idx from 2d to 1d
     * @param row the row of cell
     * @param col the col of cell
     * @return 1d index
    */
    int idx_2d_to_1d(int row, int col) const;
    /**
     * @brief convert grid cell idx from 2d to 1d
     * @param idx a pair of int consists of row and col
     * @return 1d index
    */
    int idx_2d_to_1d(std::pair<int,int> idx) const;

    /**
     * @brief check if input index is valid
     * @param row the row of idx
     * @param col the col of idx
     * @return true if index is valid, false otherwise
    */
    bool is_valid(int row, int col) const;

    /**
     * @brief check if the cell at input index is free to travel
     * @param row the row of index
     * @param col the col of index
     * @return true if the index is invalid and cell is free
    */
    bool is_free(int row, int col) const;

    /**
     * @brief init grid cells
     * @param grid the grid info
    */
    void set_grid(std::vector<int>& grid);

    int get_width() const;
    void set_width(int width);
    int get_height() const;
    void set_height(int height);
    void set_cell_value(int row, int col, int val);


}; //class OccGrid