#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "json.hpp"

#include "occ-grid.hpp"
#include "path-planner.hpp"

int main(){
    //std::cout << "hello world" << std::endl;
    std::ifstream fJson("occmap.json");
    std::stringstream buffer;
    buffer << fJson.rdbuf();
    auto json = nlohmann::json::parse(buffer.str());
    std::vector<int> data = json["layers"][0]["data"];
    //std::cout << data.size() << std::endl;

    OccGrid grid;
    grid.set_grid(data);

    while(true) {
        bool start_valid = false;
        bool target_valid = false;
        int start_row, start_col, target_row, target_col;
        while(!start_valid){
            std::cout << "enter start row col between [0,63]" << std::endl;
            std::cin >> start_row >> start_col;
            if(grid.is_free(start_row, start_col)){
                start_valid = true;
            } else {
                std::cout << "start pose [" << start_row << "," << start_col << "] is an obstacle" << std::endl; 
            }
        }
        while(!target_valid){
            std::cout << "enter target row col between [0,63]" << std::endl;
            std::cin >> target_row >> target_col;
            if(grid.is_free(target_row, target_col)){
                target_valid = true;
            } else {
                std::cout << "target pose [" << target_row << "," << target_col << "] is an obstacle" << std::endl; 
            }            
        }
        if(grid.is_free(start_row, start_col) && 
        grid.is_free(target_row, target_col)) {
            auto traj = plan_path(grid, std::make_pair(start_row, start_col), std::make_pair(target_row,target_col));
            if(!is_path_collision_free(grid, traj)){
                std::cout << "failed to plan path" << std::endl;
            } else {
                std::cout << "the shortest path from [" 
                          << start_row << "," << start_col << "] to [" 
                          << target_row << "," << target_col << "]:" << std::endl;
                for(auto node : traj){
                    std::cout << "[" << node.first << "," << node.second << "]" << std::endl; 
                }
            }
        }
    }

    return 0;
}