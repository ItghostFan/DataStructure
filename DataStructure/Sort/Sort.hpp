//
//  Sort.hpp
//  DataStructure
//
//  Created by ItghostFan on 2021/10/28.
//

#ifndef Sort_hpp
#define Sort_hpp

#include <stdio.h>
#include <machine/_types.h>

namespace Sort {

void bubble(unsigned int* array, size_t length);
void selection(unsigned int* array, size_t length);
void insertion(unsigned int* array, size_t length);
void shell(unsigned int* array, size_t length, unsigned int gap);

}

#endif /* Sort_hpp */
