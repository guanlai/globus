#pragma once

#include "occ-grid.hpp"

typedef std::vector<std::pair<int,int>> Trajectory;

/**
 * @brief plan the shortest collision free path between start and target on grid
 * @param grid the grid for planning
 * @param start the start pose
 * @param target the target pose
 * @return the path consists of an array of grid index
*/
Trajectory plan_path(const OccGrid& grid,
                     const std::pair<int,int> start,
                     const std::pair<int,int> target);

/**
 * @brief check if a planned path has collision with the grid
 * @param grid the grid for planning
 * @param trajectory the path that needs validation
 * @return true if collision free
*/
bool is_path_collision_free(const OccGrid& grid,
                            const Trajectory& trajectory);