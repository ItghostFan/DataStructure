//
//  main.m
//  DataStructure
//
//  Created by ItghostFan on 2021/10/28.
//

#import <Foundation/Foundation.h>

#import "Sort.hpp"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        
        size_t size = 10;
        unsigned int* array = new unsigned int[size];
        int index = 0;
        
        NSMutableString *arrayOutput = [NSMutableString new];
        [arrayOutput appendString:@"["];
        
        for (; index < size - 1; ++index) {
            array[index] = (unsigned)random() % 100;
            [arrayOutput appendFormat:@"%u,", array[index]];
        }
        array[index] = (unsigned int)random() % 100;
        [arrayOutput appendFormat:@"%u", array[index]];
        [arrayOutput appendString:@"]"];
        NSLog(@"Before %@", arrayOutput);
        
//        Sort::bubble(array, size);
//        Sort::selection(array, size);
//        Sort::insertion(array, size);
        Sort::shell(array, size, 8);
        
        arrayOutput = [NSMutableString new];
        [arrayOutput appendString:@"["];
        
        for (index = 0; index < size - 1; ++index) {
            [arrayOutput appendFormat:@"%u,", array[index]];
        }
        [arrayOutput appendFormat:@"%u", array[index]];
        [arrayOutput appendString:@"]"];
        NSLog(@"After %@", arrayOutput);
        
        delete[] array;
    }
    return 0;
}
