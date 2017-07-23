#include "item.h"
#include <string>

using namespace std;

/**
 * Item implementation
 */


Item::Item(char symbol, string type) : Object(symbol, type){}

Item::~Item() {}
