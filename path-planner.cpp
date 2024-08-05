#include "path-planner.hpp"
#include <queue>
#include <unordered_map>
#include <cstdlib>
#include <algorithm>    // std::reverse
#include <iostream>

/**
 * A* searching algorithm with Manhatan distance as heuristic
*/
Trajectory plan_path(const OccGrid& grid,
                     const std::pair<int,int> start,
                     const std::pair<int,int> target) {

    int start_idx = grid.idx_2d_to_1d(start);
    int target_idx = grid.idx_2d_to_1d(target);
    // <cost+heuristic, cell idx>
    std::priority_queue<std::pair<int,int>,
                        std::vector<std::pair<int,int>>,
                        std::greater<std::pair<int,int>>> frontier;
    frontier.push(std::make_pair(abs(target.first-start.first)+
                                 abs(target.second-start.second), start_idx));

    std::unordered_map<int,int> costs; //<cell idx, cost>
    std::unordered_map<int,int> paths; //backtracking cell idx <from, to>
    costs[start_idx] = 0;

    //unit can move along 4 directions
    std::vector<std::pair<int,int>>movement{
        {1,0}, {0,1}, {-1,0}, {0,-1}
    };

    while(frontier.size()){
        auto curr = frontier.top();
        frontier.pop();
        //found target
        if(curr.second == target_idx){
            break;
        }
        auto idx_2d = grid.idx_1d_to_2d(curr.second);
        for(auto move : movement){
            int next_row = idx_2d.first + move.first;
            int next_col = idx_2d.second + move.second;
            //out of bound or obstacle
            if(!grid.is_free(next_row, next_col)){
                continue;
            }
            int next = grid.idx_2d_to_1d(next_row, next_col);
            //this next cell is already visited
            if(costs.count(next) && costs[next] <= costs[curr.second]+1){
                continue;
            }
            costs[next] = costs[curr.second]+1;
            paths[next] = curr.second;
            //priority of frontier cells are sorted by cost + distance to target
            frontier.push(std::make_pair(costs[next]+
                          std::abs(next_row-idx_2d.first)+
                          std::abs(next_col-idx_2d.second),next));
        }
    }

    Trajectory traj;
    int curr = target_idx;
    while(paths.count(curr)){
        traj.push_back(grid.idx_1d_to_2d(curr));
        curr = paths[curr];
    }
    if(traj.size()){
        traj.push_back(start);
    }
    std::reverse(traj.begin(), traj.end());
    return traj;
}

bool is_path_collision_free(const OccGrid& grid,
                            const Trajectory& trajectory) {
    for(auto& idx : trajectory){
        if(!grid.is_free(idx.first, idx.second)){
            return false;
        }
    }
    return true;
}