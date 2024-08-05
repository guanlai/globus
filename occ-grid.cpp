#include "occ-grid.hpp"

std::pair<int,int> OccGrid::idx_1d_to_2d(int idx) const {
    int row = idx / m_width;
    int col = idx % m_width;
    return std::make_pair(row, col);
}

int OccGrid::idx_2d_to_1d(int row, int col) const {
    return row*m_width+col;
}

int OccGrid::idx_2d_to_1d(std::pair<int,int> idx) const {
    return idx.first*m_width + idx.second;
}

bool OccGrid::is_valid(int row, int col) const {
    return row >= 0 && row < m_height &&
           col >= 0 && col < m_width;
}

bool OccGrid::is_free(int row, int col) const {
    return is_valid(row, col) && 
           m_grid[idx_2d_to_1d(row, col)] < 0;
}

void OccGrid::set_grid(std::vector<int>& grid) {
    m_grid = grid;
}

int OccGrid::get_width() const {
    return m_width;
}

void OccGrid::set_width(int width) {
    m_width = width;
}

int OccGrid::get_height() const {
    return m_height;
}

void OccGrid::set_height(int height) {
    m_height = height;
}

void OccGrid::set_cell_value(int row, int col, int val) {
    if(!is_valid(row, col)){
        return;
    }
    m_grid[idx_2d_to_1d(row, col)] = val;
}