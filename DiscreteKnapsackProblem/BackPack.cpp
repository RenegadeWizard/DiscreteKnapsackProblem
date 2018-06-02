//
//  BackPack.cpp
//  DiscreteKnapsackProblem
//
//  Created by Krzysztof Sychla on 02.06.2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include "BackPack.hpp"

BackPack::BackPack(int wielkosc,int ile,int *wartosc,int *waga){
    C = wielkosc;
    n = ile;
    p = new int [n];
    w = new int [n];
    
    for (int i = 0;i < n;i++)
        p[i] = wartosc[i];
    
    for (int i = 0;i < n;i++)
        w[i] = waga[i];
    
}
