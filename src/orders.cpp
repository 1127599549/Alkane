/**
 * Copyright 2018 VMware
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 *          Author: Heena Nagda
 *           Project: Themis
 */

#include <unordered_map>
#include "hotstuff/orders.h"
#include "hotstuff/entity.h"

#define LOG_INFO HOTSTUFF_LOG_INFO
#define LOG_DEBUG HOTSTUFF_LOG_DEBUG
#define LOG_WARN HOTSTUFF_LOG_WARN
#define LOG_PROTO HOTSTUFF_LOG_PROTO

namespace hotstuff {
    MergeOrder::MergeOrder(std::unordered_map<ReplicaID, std::vector<uint256_t>> const& orders){
        MergeOrder::orders = orders;
        reset_visited();
    }

    void MergeOrder::reset_visited(){
        for(auto const &entry:orders){
            visited[entry.first] = false;
        }
    }
    
    std::unordered_map<ReplicaID, std::vector<uint256_t>> MergeOrder::get_merge_order(){
        return orders;
    }
}
