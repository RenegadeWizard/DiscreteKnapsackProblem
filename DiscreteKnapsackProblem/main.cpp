//
//  main.cpp
//  DiscreteKnapsackProblem
//
//  Created by Krzysztof Sychla on 17.05.2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include <iostream>
#include "BackPack.hpp"

int main(int argc, const char * argv[]) {
    int weight[] = {3,4,1,2};
    int price[] = {5,2,1,4};
    int C = 6;
    int n = 4;
    BackPack plecak(C,n,price,weight);
    plecak.BruteForce();
    return 0;
}
