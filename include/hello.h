// 避免重複引用此標頭檔
#ifndef _HELLO_H_
#define _HELLO_H_

// gcc 生成 .o 檔跟 g++ 生成 .o 檔物件命名規則會不一樣
// 會造成連結 .o 檔時，名子對不上，導致 no reference
// 需要告訴編譯器這裡為 c code，要用 gcc 的命名規則
#if defined (__cplusplus)
extern "C" {
#endif

#include <stdio.h>

void printGreeting();

#if defined (__cplusplus)
}
#endif
#endif