//
//  BackPack.hpp
//  DiscreteKnapsackProblem
//
//  Created by Krzysztof Sychla on 02.06.2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#pragma once

class BackPack{
private:
    int C;       //Wielkość plecaka
    int n;       //Ilość elementów
    int *p;      //Tablica wartości
    int *w;      //Tablica wag
public:
    BackPack(int wielkosc,int ile,int *wartosc,int *waga);
    ~BackPack();
    void BruteForce();
    void DynamicProgramming();
    
    void PrintElem();
};
